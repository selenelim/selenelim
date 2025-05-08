import RPi.GPIO as GPIO
import time
import spidev  # For SPI communication with MCP3008

# Set up GPIO pins
RED_LED_PIN = 27
GPIO.setmode(GPIO.BCM)
GPIO.setup(RED_LED_PIN, GPIO.OUT)

# Set up PWM on the red LED pin (1kHz frequency)
pwm = GPIO.PWM(RED_LED_PIN, 1000)  # 1000Hz frequency
pwm.start(0)  # Start with 0% duty cycle (LED off)

# Set up SPI to communicate with MCP3008 (ADC)
spi = spidev.SpiDev()
spi.open(0, 0)  # Open SPI bus 0, device 0
spi.max_speed_hz = 1350000  # Set maximum SPI speed

# Function to read the analog value from the potentiometer (connected to MCP3008)
def read_potentiometer(channel=0):
    # SPI communication with MCP3008 (channel 0 to channel 7)
    adc = spi.xfer2([1, (8 + channel) << 4, 0])
    value = ((adc[1] & 3) << 8) + adc[2]  # Extract the 10-bit ADC value
    return value

try:
    while True:
        # Read the potentiometer value (10-bit, 0-1023)
        pot_value = read_potentiometer(channel=0)

        # Map potentiometer value (0-1023) to a PWM duty cycle (0-100)
        pwm_duty_cycle = (pot_value / 1023.0) * 100

        # Set PWM duty cycle to control LED brightness
        pwm.ChangeDutyCycle(pwm_duty_cycle)

        # Print potentiometer value and LED brightness for debugging
        print(f"Potentiometer: {pot_value} | LED Brightness: {pwm_duty_cycle:.2f}%")

        time.sleep(0.1)  # Add a small delay for stability

except KeyboardInterrupt:
    print("Program interrupted")

finally:
    pwm.stop()  # Stop PWM
    GPIO.cleanup()  # Clean up GPIO settings
