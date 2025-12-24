#include <Servo.h>

Servo servoX;
Servo servoY;

// Adjust after calibration
int posX = 90;
int posY = 90;

void setup() {
  Serial.begin(9600);

  servoX.attach(9);
  servoY.attach(10);

  servoX.write(posX);
  servoY.write(posY);

  Serial.println("Wizard Chess Ready");
}

void loop() {
  if (Serial.available()) {
    String cmd = Serial.readStringUntil('\n');
    cmd.trim();

    if (cmd.startsWith("MOVE")) {
      char fromFile = cmd.charAt(5);
      int fromRank = cmd.charAt(6) - '0';

      char toFile = cmd.charAt(8);
      int toRank = cmd.charAt(9) - '0';

      movePiece(fromFile, fromRank, toFile, toRank);
    }
  }
}

void movePiece(char fFile, int fRank, char tFile, int tRank) {
  moveToSquare(fFile, fRank);
  delay(800);
  moveToSquare(tFile, tRank);
  delay(800);
}

void moveToSquare(char file, int rank) {
  int x = map(file, 'A', 'H', 30, 150);
  int y = map(rank, 1, 8, 30, 150);

  servoX.write(x);
  servoY.write(y);

  delay(500);
}
