from flask import Flask, render_template, request, redirect, url_for, send_file
import qrcode
import os
import io
from datetime import datetime

app = Flask(__name__)

# Temporary order store (in memory)
orders = {}

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/order', methods=['POST'])
def order():
    drink = request.form['drink']
    customer_id = request.form['customer_id']
    order_id = f"{customer_id}_{datetime.now().strftime('%Y%m%d%H%M%S')}"
    
    # Save the order
    orders[order_id] = {
        'drink': drink,
        'status': 'unpaid'  # Extend later for payment
    }

    # Generate QR
    qr_data = f"ORDER:{order_id}"
    qr_img = qrcode.make(qr_data)
    qr_io = io.BytesIO()
    qr_img.save(qr_io, 'PNG')
    qr_io.seek(0)

    return send_file(qr_io, mimetype='image/png', as_attachment=True, download_name=f'{order_id}.png')

@app.route('/verify/<order_id>')
def verify_order(order_id):
    if order_id in orders:
        return {'order_id': order_id, 'status': orders[order_id]['status'], 'drink': orders[order_id]['drink']}
    else:
        return {'error': 'Order not found'}, 404

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5000)
