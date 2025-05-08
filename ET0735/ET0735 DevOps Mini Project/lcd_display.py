
from RPLCD.i2c import CharLCD
from time import sleep

# Adjust these based on your LCD's I2C address and dimensions
lcd = CharLCD('PCF8574', 0x27, cols=16, rows=2)

def display_message(line1, line2=''):
    lcd.clear()
    lcd.write_string(line1)
    if line2:
        lcd.cursor_pos = (1, 0)
        lcd.write_string(line2)

def clear_lcd():
    lcd.clear()

# Example usage
if __name__ == "__main__":
    display_message("Welcome!", "Select Drink")
    sleep(3)
    clear_lcd()
