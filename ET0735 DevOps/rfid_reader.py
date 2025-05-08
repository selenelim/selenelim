from mfrc522 import SimpleMFRC522
import time

reader = SimpleMFRC522()

def read_rfid():
    print("Hold RFID tag near reader...")
    try:
        id, text = reader.read()
        print(f"RFID ID: {id}")
        print(f"RFID Text: {text}")
        return id, text.strip()
    except Exception as e:
        print(f"Error: {e}")
    finally:
        time.sleep(1)

# Example usage
if __name__ == "__main__":
    while True:
        read_rfid()
