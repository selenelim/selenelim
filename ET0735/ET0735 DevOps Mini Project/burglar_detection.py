import RPi.GPIO as GPIO
import time
import os
from picamera import PiCamera
import smtplib
from email.message import EmailMessage

# GPIO setup
DOOR_SENSOR_PIN = 23  # Connected to reed switch or vibration sensor
BUZZER_PIN = 24

GPIO.setmode(GPIO.BCM)
GPIO.setup(DOOR_SENSOR_PIN, GPIO.IN, pull_up_down=GPIO.PUD_UP)
GPIO.setup(BUZZER_PIN, GPIO.OUT)

camera = PiCamera()

def sound_buzzer(duration=5):
    print("🔔 Buzzer activated!")
    GPIO.output(BUZZER_PIN, GPIO.HIGH)
    time.sleep(duration)
    GPIO.output(BUZZER_PIN, GPIO.LOW)

def capture_image(path="intruder.jpg"):
    print("📸 Capturing image...")
    camera.capture(path)
    return path

def send_email(image_path):
    msg = EmailMessage()
    msg['Subject'] = '🚨 Vending Machine Breach Alert'
    msg['From'] = 'your.email@example.com'
    msg['To'] = 'technician@example.com'
    msg.set_content('A possible break-in has been detected. Image attached.')

    with open(image_path, 'rb') as img:
        msg.add_attachment(img.read(), maintype='image', subtype='jpeg', filename='intruder.jpg')

    try:
        with smtplib.SMTP_SSL('smtp.gmail.com', 465) as smtp:
            smtp.login('your.email@example.com', 'your-app-password')
            smtp.send_message(msg)
        print("📤 Alert email sent!")
    except Exception as e:
        print("❌ Failed to send email:", e)

def monitor_breach():
    print("Monitoring door sensor...")
    while True:
        if GPIO.input(DOOR_SENSOR_PIN) == GPIO.LOW:  # LOW = door forced open
            print("🚨 Intrusion detected!")
            sound_buzzer()
            img = capture_image()
            send_email(img)
            time.sleep(10)  # Prevent spamming
        time.sleep(0.5)

if __name__ == "__main__":
    try:
        monitor_breach()
    except KeyboardInterrupt:
        print("Stopping...")
    finally:
        camera.close()
        GPIO.cleanup()
