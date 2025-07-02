// Motor Driver Pins
int motor1Pin1 = 2;
int motor1Pin2 = 3;
int motor2Pin1 = 4;
int motor2Pin2 = 5;
int motor3Pin1 = 6;
int motor3Pin2 = 7;
int motor4Pin1 = 8;
int motor4Pin2 = 9;

// Ultrasonic Sensor Pins
const int trigPin = 10;
const int echoPin = 11;

// IR Sensors
const int irLeft = A0;
const int irCenter = A1;
const int irRight = A2;

// Distance threshold in cm
const int obstacleDistance = 20;

void setup() {
  // Set motor pins as output
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
  pinMode(motor3Pin1, OUTPUT);
  pinMode(motor3Pin2, OUTPUT);
  pinMode(motor4Pin1, OUTPUT);
  pinMode(motor4Pin2, OUTPUT);

  // Set ultrasonic sensor pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // IR sensor pins (analog input by default)

  Serial.begin(9600); // Debugging
}

void loop() {
  long distance = getDistance();
  int leftIR = analogRead(irLeft);
  int centerIR = analogRead(irCenter);
  int rightIR = analogRead(irRight);

  Serial.print("Distance: "); Serial.print(distance); Serial.println(" cm");
  Serial.print("IR L: "); Serial.print(leftIR);
  Serial.print(" C: "); Serial.print(centerIR);
  Serial.print(" R: "); Serial.println(rightIR);

  // Check for obstacle
  if (distance > 0 && distance < obstacleDistance) {
    stopMotors();
    delay(300);
    turnRight();  // Avoid obstacle
    delay(500);
    stopMotors();
  } 
  else {
    // IR navigation logic
    if (centerIR < 500) {
      moveForward(); // Line detected in center
    } else if (leftIR < 500) {
      turnLeft();  // Adjust left
    } else if (rightIR < 500) {
      turnRight(); // Adjust right
    } else {
      stopMotors(); // Lost line or off-track
    }
  }

  delay(100);
}

void moveForward() {
  digitalWrite(motor1Pin1, HIGH); digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, HIGH); digitalWrite(motor2Pin2, LOW);
  digitalWrite(motor3Pin1, HIGH); digitalWrite(motor3Pin2, LOW);
  digitalWrite(motor4Pin1, HIGH); digitalWrite(motor4Pin2, LOW);
}

void moveBackward() {
  digitalWrite(motor1Pin1, LOW); digitalWrite(motor1Pin2, HIGH);
  digitalWrite(motor2Pin1, LOW); digitalWrite(motor2Pin2, HIGH);
  digitalWrite(motor3Pin1, LOW); digitalWrite(motor3Pin2, HIGH);
  digitalWrite(motor4Pin1, LOW); digitalWrite(motor4Pin2, HIGH);
}

void turnLeft() {
  digitalWrite(motor1Pin1, LOW); digitalWrite(motor1Pin2, HIGH);
  digitalWrite(motor2Pin1, HIGH); digitalWrite(motor2Pin2, LOW);
  digitalWrite(motor3Pin1, HIGH); digitalWrite(motor3Pin2, LOW);
  digitalWrite(motor4Pin1, LOW); digitalWrite(motor4Pin2, HIGH);
}

void turnRight() {
  digitalWrite(motor1Pin1, HIGH); digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW); digitalWrite(motor2Pin2, HIGH);
  digitalWrite(motor3Pin1, LOW); digitalWrite(motor3Pin2, HIGH);
  digitalWrite(motor4Pin1, HIGH); digitalWrite(motor4Pin2, LOW);
}

void stopMotors() {
  digitalWrite(motor1Pin1, LOW); digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW); digitalWrite(motor2Pin2, LOW);
  digitalWrite(motor3Pin1, LOW); digitalWrite(motor3Pin2, LOW);
  digitalWrite(motor4Pin1, LOW); digitalWrite(motor4Pin2, LOW);
}

long getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH, 20000); // Timeout at 20ms
  long distance = duration * 0.034 / 2;

  if (distance == 0 || distance > 300) return -1; // Invalid
  return distance;
}
