#define led1 13
#define in1 12   // Motor A direction pin 1
#define in2 11   // Motor A direction pin 2
#define in3 10   // Motor B direction pin 1
#define in4 9    // Motor B direction pin 2
#define ena 6    // Motor A speed (PWM)
#define enb 5    // Motor B speed (PWM)

int motorSpeed = 175;           // Target speed (0–255)
int currentSpeed = motorSpeed;         // Used for gradual stop
bool stopRequested = false;     // Flag to indicate stop in progress
unsigned long lastSlowdownTime = 0;

void setup() {
  Serial.begin(9600);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(ena, OUTPUT);
  pinMode(enb, OUTPUT);
  pinMode(led1, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    char inputvalue = char(Serial.read());

    // Cancel stop if a new movement command comes in
    if (inputvalue == 'F' || inputvalue == 'B' || inputvalue == 'L' ||
        inputvalue == 'R' || inputvalue == 'C' || inputvalue == 'A') {
      stopRequested = false;
      currentSpeed = motorSpeed;
    }

    if (inputvalue == 'F') {
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
    }
    else if (inputvalue == 'B') {
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
    }
    else if (inputvalue == 'R') {
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
    }
    else if (inputvalue == 'L') {
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      digitalWrite(in3, LOW);
      digitalWrite(in4, LOW);
    }
    else if (inputvalue == 'C') {
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
    }
    else if (inputvalue == 'A') {
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
    }
    else if (inputvalue == 's') {
      digitalWrite(led1, HIGH);
    }
    else if (inputvalue == 'O') {
      digitalWrite(led1, LOW);
    }
    else if (inputvalue == 'S') {
      // Request a smooth stop
      stopRequested = true;
    }
  }

  // Smooth stop logic (non-blocking)
  if (stopRequested) {
    unsigned long now = millis();
    if (now - lastSlowdownTime >= 25) {
      lastSlowdownTime = now;
      if (currentSpeed > 0) {
        currentSpeed -= 5;
        if (currentSpeed < 0) currentSpeed = 0;
        analogWrite(ena, currentSpeed);
        analogWrite(enb, currentSpeed);
      } else {
        // Fully stopped, cut power to motors
        digitalWrite(in1, LOW);
        digitalWrite(in2, LOW);
        digitalWrite(in3, LOW);
        digitalWrite(in4, LOW);
        stopRequested = false;
        currentSpeed = motorSpeed; // Reset for next move
      }
    }
  } else {
    // Normal running: apply full motor speed
    analogWrite(ena, motorSpeed);
    analogWrite(enb, motorSpeed);
  }
}
