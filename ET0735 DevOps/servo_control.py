import RPi.GPIO as GPIO
import time

SERVO_PIN = 18  # Use a PWM-capable GPIO pin

GPIO.setmode(GPIO.BCM)
GPIO.setup(SERVO_PIN, GPIO.OUT)

# Set PWM frequency to 50Hz (typical for servos)
pwm = GPIO.PWM(SERVO_PIN, 50)
pwm.start(0)

def set_angle(angle):
    """Set servo to specific angle between 0 and 180 degrees"""
    duty = 2 + (angle / 18)  # Convert angle to duty cycle
    GPIO.output(SERVO_PIN, True)
    pwm.ChangeDutyCycle(duty)
    time.sleep(0.5)
    GPIO.output(SERVO_PIN, False)
    pwm.ChangeDutyCycle(0)

def dispense():
    """Rotate servo to simulate drink release"""
    print("Dispensing drink...")
    set_angle(90)   # Move to unlock position
    time.sleep(1)
    set_angle(0)    # Return to lock
    print("Dispensing complete.")

def cleanup():
    pwm.stop()
    GPIO.cleanup()

# Example usage
if __name__ == "__main__":
    try:
        dispense()
    except KeyboardInterrupt:
        pass
    finally:
        cleanup()
