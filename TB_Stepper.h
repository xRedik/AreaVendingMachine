//change pins
#define DIR_PIN_Vertical 3
#define STEP_PIN_Vertical 6
#define DIR_PIN_Horizontal 2
#define STEP_PIN_Horizontal 5
///

void moveUp (int steps) {
  digitalWrite(DIR_PIN_Vertical, LOW);
  for (int i = 0; i < steps; i++) {
    digitalWrite(STEP_PIN_Vertical, HIGH);
    delayMicroseconds(300);
    digitalWrite(STEP_PIN_Vertical, LOW);
    delayMicroseconds(300);
  }
}

void moveDown (int steps) {
  digitalWrite(DIR_PIN_Vertical, HIGH);
  for (int i = 0; i < steps; i++) {
    digitalWrite(STEP_PIN_Vertical, HIGH);
    delayMicroseconds(300);
    digitalWrite(STEP_PIN_Vertical, LOW);
    delayMicroseconds(300);
  }
}

void moveLeft (int steps) {
  digitalWrite(DIR_PIN_Horizontal, HIGH);
  for (int i = 0; i < steps; i++) {
    digitalWrite(STEP_PIN_Horizontal, HIGH);
    delayMicroseconds(300);
    digitalWrite(STEP_PIN_Horizontal, LOW);
    delayMicroseconds(300);
  }
}

void moveRight (int steps) {
  digitalWrite(DIR_PIN_Horizontal, LOW);
  for (int i = 0; i < steps; i++) {
    digitalWrite(STEP_PIN_Horizontal, HIGH);
    delayMicroseconds(300);
    digitalWrite(STEP_PIN_Horizontal, LOW);
    delayMicroseconds(300);
  }
}
