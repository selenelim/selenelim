import time
import threading
import RPi.GPIO as GPIO
from lcd_display import display_message, clear_lcd  # From previous LCD code
from keypad_input import keypad  # From previous Keypad code
from rfid_reader import read_rfid  # From previous RFID code
from qr_scanner import scan_qr  # From previous QR code scanner
from servo_control import dispense  # From previous Servo control code
from burglar_detection import monitor_breach  # From previous Burglar detection code
from environment_monitor import monitor_environment  # From previous Environment monitor code
from flask import Flask, render_template, request, send_file, jsonify
import qrcode
import io
import smtplib
from email.message import EmailMessage

# Flask app for web interface
app = Flask(__name__)

# Keypad setup (user authentication)
valid_rfid_ids = [1234567890, 9876543210]  # Replace with actual valid IDs

# Define door sensor, buzzer, etc.
DOOR_SENSOR_PIN = 23  # Replace with actual door sensor pin
BUZZER_PIN = 24  # Replace with actual buzzer pin
GPIO.setmode(GPIO.BCM)
GPIO.setup(DOOR_SENSOR_PIN, GPIO.IN, pull_up_down=GPIO.PUD_UP)
GPIO.setup(BUZZER_PIN, GPIO.OUT)

# Setup threading for concurrent operations
def run_burglar_detection():
    thread = threading.Thread(target=monitor_breach)
    thread.daemon = True
    thread.start()

def run_environment_monitor():
    thread = threading.Thread(target=monitor_environment)
    thread.daemon = True
    thread.start()

def run_flask_app():
    app.run(host='0.0.0.0', port=5000)

# Flask routes for web interface
@app.route('/')
def index():
    return render_template('index.html')

@app.route('/order', methods=['POST'])
def order():
    drink = request.form['drink']
    customer_id = request.form['customer_id']
    order_id = f"{customer_id}_{time.strftime('%Y%m%d%H%M%S')}"
    
    # Generate QR code for order
    qr_data = f"ORDER:{order_id}"
    qr_img = qrcode.make(qr_data)
    qr_io = io.BytesIO()
    qr_img.save(qr_io, 'PNG')
    qr_io.seek(0)
    return send_file(qr_io, mimetype='image/png', as_attachment=True, download_name=f'{order_id}.png')

@app.route('/verify/<order_id>')
def verify_order(order_id):
    # For now, verify if order exists (later you can integrate with a database)
    return jsonify({'order_id': order_id, 'status': 'unpaid', 'drink': 'Coke'})

# Main Controller
def main():
    # Start the burglar detection system and environmental monitoring
    run_burglar_detection()
    run_environment_monitor()

    display_message("Welcome!", "Select Drink")
    
    while True:
        # Step 1: RFID scan for user authentication
        id, _ = read_rfid()
        if id not in valid_rfid_ids:
            display_message("Access Denied", "Invalid RFID")
            continue
        
        display_message("RFID Verified!", "Select Drink")

        # Step 2: Keypad input for drink selection
        selected_drink = keypad_input()
        if selected_drink:
            display_message(f"Selected: {selected_drink}", "Processing Payment...")
            
            # Step 3: Handle payment (this can be extended to a real payment system)
            payment_verified = True  # Assume payment is verified for now
            if payment_verified:
                display_message("Payment Successful!", "Dispensing Drink")
                dispense()  # Trigger the servo to release the drink
                time.sleep(5)  # Delay for drink dispensing
                clear_lcd()
            else:
                display_message("Payment Failed!", "Try Again")
                time.sleep(2)
                clear_lcd()

        # Step 4: QR code scan for remote orders (after local drink selection)
        order_data = scan_qr()
        if order_data:
            order_id = order_data.split(":")[1]
            display_message(f"Order ID: {order_id}", "Dispensing Drink")
            dispense()
            time.sleep(5)  # Delay for drink dispensing
            clear_lcd()

        time.sleep(1)

# Run Flask app in a separate thread
flask_thread = threading.Thread(target=run_flask_app)
flask_thread.daemon = True
flask_thread.start()

if __name__ == "__main__":
    main()
