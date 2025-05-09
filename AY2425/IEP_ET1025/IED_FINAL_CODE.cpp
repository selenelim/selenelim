// BLYNK SETUP
#define BLYNK_PRINT Serial
#include <SoftwareSerial.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define BLYNK_TEMPLATE_ID "TMPL6NROWqGP-"
#define BLYNK_TEMPLATE_NAME "trashbinwifi"
#define BLYNK_AUTH_TOKEN "7uH0l28WwEqjkGzbJb1B3iTZMj2FQgdC"
#include <ESP8266_Lib.h>
#include <BlynkSimpleShieldEsp8266.h>

char ssid[] = "lss";
char pass[] = "ayuumahtet";

// LCD DISPLAY
LiquidCrystal_I2C lcd(0x27, 16, 2);

// ESP8266 Setup
SoftwareSerial EspSerial(12, 13); // RX, TX
#define ESP8266_BAUD 9600
ESP8266 wifi(&EspSerial);

#define IR_SENSOR_RIGHT A0  // IR sensor
#define IR_SENSOR_LEFT A1
#define MOTOR_SPEED 90

// Ultrasonic Sensors
#define TrigPinLeft  8
#define EchoPinLeft  7
#define TrigPinRight 11
#define EchoPinRight 10

// Target Board Hit Pins
#define Hit_aPin 4
#define Hit_bPin 2

// Right Motor
int enableRightMotor = 6;
int rightMotorPin1 = 5;
int rightMotorPin2 = 3;

// Left Motor
int enableLeftMotor = 5;  
int leftMotorPin1 = 9;
int leftMotorPin2 = 6;

int totalHits = 0;
bool hitAState = false;
bool hitBState = false;
String lastMessage = "";

unsigned long previousMillis = 0;
const long interval = 2000;
bool motorStopped = false;

void setup() {
  TCCR0B = TCCR0B & B11111000 | B00000010; // Change PWM frequency 
  Serial.begin(115200);
  lcd.init();
  lcd.backlight();
  updateLCD("Starting...");

  EspSerial.begin(ESP8266_BAUD);
  Blynk.begin(BLYNK_AUTH_TOKEN, wifi, ssid, pass);

  pinMode(enableRightMotor, OUTPUT);
  pinMode(rightMotorPin1, OUTPUT);
  pinMode(rightMotorPin2, OUTPUT);
  pinMode(enableLeftMotor, OUTPUT);
  pinMode(leftMotorPin1, OUTPUT);
  pinMode(leftMotorPin2, OUTPUT);
  rotateMotor(0, 0);

  pinMode(IR_SENSOR_RIGHT, INPUT);
  pinMode(IR_SENSOR_LEFT, INPUT);
  pinMode(TrigPinLeft, OUTPUT);
  pinMode(EchoPinLeft, INPUT);
  pinMode(TrigPinRight, OUTPUT);
  pinMode(EchoPinRight, INPUT);
  pinMode(Hit_aPin, INPUT_PULLUP);
  pinMode(Hit_bPin, INPUT_PULLUP);

  updateLCD("WiFi Connected!\nBlynk Ready!"); // Makes sure its connected first 
}

void loop() {
  Blynk.run();
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    // Detect Hit A
    if (digitalRead(Hit_aPin) == LOW && !hitAState) {
      rotateMotor(0,0);
      motorStopped = true;
      hitAState = true;
      totalHits++;
      int distanceRight = getDistanceRight();    // Get distance from U/S
      updateLCD("Hit A: " + String(distanceRight) + "cm");
      Blynk.virtualWrite(V5, distanceRight);     // Send Distance from LEFT U/S to Virtual Pin 5 in Blynk 
      String binStatus = (distanceRight < 5) ? "Bins full" : "Bin okay";
      Blynk.virtualWrite(V9, binStatus);         // Send Status of Bin to Virtual Pin 9 in Blynk
      motorStopped = false;
    }

    // Detect Hit B
    if (digitalRead(Hit_bPin) == LOW && !hitBState) {
      rotateMotor(0,0);
      motorStopped = true;
      hitBState = true;
      totalHits++;
      int distanceLeft = getDistanceLeft();     //Get distance from U/S
      updateLCD("Hit B: " + String(distanceLeft) + "cm");
      Blynk.virtualWrite(V6, distanceLeft);     // Send Distance from LEFT U/S to Virtual Pin 6 in Blynk 
      String binStatus = (distanceLeft < 5) ? "Bins full" : "Bin okay";
      Blynk.virtualWrite(V9, binStatus);        // Send Status of Bin to Virtual Pin 9 in Blynk
      motorStopped = false;
    }

    // Reset hit states
    if (digitalRead(Hit_aPin) == HIGH) hitAState = false;
    if (digitalRead(Hit_bPin) == HIGH) hitBState = false;

    // Display total hits
    Serial.print("Total Hits: ");
    Serial.println(totalHits);
    updateLCD("Total Hits: " + String(totalHits));
    Blynk.virtualWrite(V4, totalHits);
  }

  // MOTOR CONTROL: Follow the line
  int rightIRSensorValue = digitalRead(IR_SENSOR_RIGHT);
  int leftIRSensorValue = digitalRead(IR_SENSOR_LEFT);

  
  if (rightIRSensorValue == LOW && leftIRSensorValue == LOW && !motorStopped) {
    rotateMotor(0, 0);
  }
  else if (rightIRSensorValue == HIGH && leftIRSensorValue == LOW && !motorStopped) {
    rotateMotor(MOTOR_SPEED, -MOTOR_SPEED);
  }
  else if (rightIRSensorValue == LOW && leftIRSensorValue == HIGH && !motorStopped) {
    rotateMotor(-MOTOR_SPEED, MOTOR_SPEED);
  } 
  else if(rightIRSensorValue == HIGH && leftIRSensorValue == HIGH && !motorStopped){
    rotateMotor(MOTOR_SPEED, MOTOR_SPEED);
  }
}


int getDistanceLeft() {
  digitalWrite(TrigPinLeft, LOW);
  delayMicroseconds(2);
  digitalWrite(TrigPinLeft, HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigPinLeft, LOW);
  long pulseDuration = pulseIn(EchoPinLeft, HIGH, 30000);
  return (pulseDuration == 0) ? -1 : pulseDuration / 58;
}

int getDistanceRight() {
  digitalWrite(TrigPinRight, LOW);
  delayMicroseconds(2);
  digitalWrite(TrigPinRight, HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigPinRight, LOW);
  long pulseDuration = pulseIn(EchoPinRight, HIGH, 30000);
  return (pulseDuration == 0) ? -1 : pulseDuration / 58;
}

void updateLCD(String message) {
  if (message != lastMessage) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(message);
    lastMessage = message;
  }
}

void rotateMotor(int rightMotorSpeed, int leftMotorSpeed) {
  if (rightMotorSpeed < 0) {
    digitalWrite(rightMotorPin1, LOW);
    digitalWrite(rightMotorPin2, HIGH);    
  }
  else if (rightMotorSpeed > 0) {
    digitalWrite(rightMotorPin1, HIGH);
    digitalWrite(rightMotorPin2, LOW);      
  }
  else {
    digitalWrite(rightMotorPin1, LOW);
    digitalWrite(rightMotorPin2, LOW);      
  }

  if (leftMotorSpeed < 0) {
    digitalWrite(leftMotorPin1, LOW);
    digitalWrite(leftMotorPin2, HIGH);    
  }
  else if (leftMotorSpeed > 0) {
    digitalWrite(leftMotorPin1, HIGH);
    digitalWrite(leftMotorPin2, LOW);      
  }
  else {
    digitalWrite(leftMotorPin1, LOW);
    digitalWrite(leftMotorPin2, LOW);      
  }

  analogWrite(enableRightMotor, abs(rightMotorSpeed));
  analogWrite(enableLeftMotor, abs(leftMotorSpeed));    
}