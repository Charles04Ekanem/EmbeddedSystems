// Define the pins for motor control
int motor1Pin1 = 2;
int motor1Pin2 = 3;
int motor2Pin1 = 4;
int motor2Pin2 = 5;
int motor3Pin1 = 6;
int motor3Pin2 = 7;
int motor4Pin1 = 8;
int motor4Pin2 = 9;

void setup() {
  // Set the motor control pins as outputs
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
  pinMode(motor3Pin1, OUTPUT);
  pinMode(motor3Pin2, OUTPUT);
  pinMode(motor4Pin1, OUTPUT);
  pinMode(motor4Pin2, OUTPUT);
}

void loop() {
  // Move forward
  moveForward();
  delay(2000); // Wait for 2 seconds

  // Move backward
  moveBackward();
  delay(2000); // Wait for 2 seconds

  // Turn left
  turnLeft();
  delay(2000); // Wait for 2 seconds

  // Turn right
  turnRight();
  delay(2000); // Wait for 2 seconds
}

// Function to move the robot car forward
void moveForward() {
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
  digitalWrite(motor3Pin1, HIGH);
  digitalWrite(motor3Pin2, LOW);
  digitalWrite(motor4Pin1, HIGH);
  digitalWrite(motor4Pin2, LOW);
}

// Function to move the robot car backward
void moveBackward() {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, HIGH);
  digitalWrite(motor3Pin1, LOW);
  digitalWrite(motor3Pin2, HIGH);
  digitalWrite(motor4Pin1, LOW);
  digitalWrite(motor4Pin2, HIGH);
}

// Function to turn the robot car left
void turnLeft() {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
  digitalWrite(motor3Pin1, HIGH);
  digitalWrite(motor3Pin2, LOW);
  digitalWrite(motor4Pin1, LOW);
  digitalWrite(motor4Pin2, HIGH);
}

// Function to turn the robot car right
void turnRight() {
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, HIGH);
  digitalWrite(motor3Pin1, LOW);
  digitalWrite(motor3Pin2, HIGH);
  digitalWrite(motor4Pin1, HIGH);
  digitalWrite(motor4Pin2, LOW);
}
