import cv2
from pyzbar.pyzbar import decode
from picamera.array import PiRGBArray
from picamera import PiCamera
import time

def scan_qr(timeout=15):
    camera = PiCamera()
    camera.resolution = (640, 480)
    raw_capture = PiRGBArray(camera, size=(640, 480))
    print("Starting QR scan. Hold your QR code in front of the camera...")

    start_time = time.time()
    for frame in camera.capture_continuous(raw_capture, format="bgr", use_video_port=True):
        image = frame.array
        decoded_objs = decode(image)

        for obj in decoded_objs:
            data = obj.data.decode('utf-8')
            print(f"QR Code Detected: {data}")
            camera.close()
            return data

        raw_capture.truncate(0)

        if time.time() - start_time > timeout:
            print("QR scan timed out.")
            break

    camera.close()
    return None

# Example usage
if __name__ == "__main__":
    qr_data = scan_qr()
    if qr_data:
        print("Scanned QR Content:", qr_data)
    else:
        print("No QR code detected.")
    