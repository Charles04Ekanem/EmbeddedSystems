#include <Servo.h> // Library for servo functionality
// Pin Definitions
const int trigPin = 9;
const int echoPin = 10;
const int servoPin = 6;
const int ledPin = 7; 
const int openDistance = 15; // Defines distance trigger
const unsigned long openDuration = 3000; // Time Lid Stays Open (ms)

Servo lidServo;
bool isLidOpen = false;
unsigned long lidOpenTime = 0;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);

  lidServo.attach(servoPin);
  lidServo.write(0); // Start closed
  digitalWrite(ledPin, LOW); // LED off

  Serial.begin(9600); 
}

void loop() {
  long distance = measureDistance();

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // If object detected and lid is closed
  if (distance > 0 && distance < openDistance && !isLidOpen) {
    openLid();
    lidOpenTime = millis();
  }

  // Close after delay
  if (isLidOpen && millis() - lidOpenTime >= openDuration) {
    closeLid();
  }

  delay(100);
}

long measureDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  long distance = duration * 0.034 / 2;

  if (distance == 0 || distance > 300) return -1;  // Out of range
  return distance;
}

void openLid() {
  lidServo.write(90);   // Open angle
  digitalWrite(ledPin, HIGH); // Turn on LED
  isLidOpen = true;
  Serial.println("Lid Opened");
}

void closeLid() {
  lidServo.write(0);    // Close angle
  digitalWrite(ledPin, LOW);  // Turn off LED
  isLidOpen = false;
  Serial.println("Lid Closed");
}
