import RPi.GPIO as GPIO
import time
GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)

#GREEN_LED = 26
#YELLOW_LED = 22
#RED_LED = 27
#BUTTON_PIN = 19
#BUZZER_PIN = 17

GPIO.setup(26, GPIO.OUT)
GPIO.setup(22, GPIO.OUT)
GPIO.setup(27, GPIO.OUT)
GPIO.setup(19, GPIO.IN, pull_up_down=GPIO.PUD_UP)  # Button with pull-up resistor HIGH when not pressed
GPIO.setup(17, GPIO.OUT)

green_time=15

def buzzer_beep():
    for _ in range(5):
        GPIO.output(17,1)
        time.sleep(1)
        GPIO.output(17,0)

def reset_lights():
    GPIO.output(26,0)
    GPIO.output(22,0)
    GPIO.output(27,0)
    GPIO.output(17,0)

try:
    while True:
        button_pressed= GPIO.input(19)==0
        if button_pressed:
            green_time=10

        reset_lights()
        GPIO.output(26,1)
        print("GREEN ON")
        time.sleep(green_time)

        reset_lights()
        GPIO.output(22,1)
        print("YELLOW ON")
        time.sleep(2)

        reset_lights()
        GPIO.output(27,1)
        print("RED ON")
        buzzer_beep()
        time.sleep(10)
