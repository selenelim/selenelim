from pad4pi import rpi_gpio
import time

KEYPAD = [
    ["1", "2", "3", "A"],
    ["4", "5", "6", "B"],
    ["7", "8", "9", "C"],
    ["*", "0", "#", "D"]
]

ROW_PINS = [5, 6, 13, 19]     # Adjust according to your wiring
COL_PINS = [12, 16, 20, 21]

factory = rpi_gpio.KeypadFactory()
keypad = factory.create_keypad(keypad=KEYPAD, row_pins=ROW_PINS, col_pins=COL_PINS)

user_input = []

def key_pressed(key):
    print(f"Key pressed: {key}")
    user_input.append(key)

keypad.registerKeyPressHandler(key_pressed)

# Example usage
if __name__ == "__main__":
    print("Press keys (Ctrl+C to stop):")
    try:
        while True:
            time.sleep(0.2)
    except KeyboardInterrupt:
        print("\nYou entered:", "".join(user_input))
        keypad.cleanup()
