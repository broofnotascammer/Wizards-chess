// Magic Chess – Arduino Controller
// Receives moves like: E2,E4

String input = "";

void setup() {
  Serial.begin(9600);
  Serial.println("Magic Chess Arduino Ready");
}

void loop() {
  while (Serial.available()) {
    char c = Serial.read();
    if (c == '\n') {
      processMove(input);
      input = "";
    } else {
      input += c;
    }
  }
}

void processMove(String cmd) {
  if (cmd.length() < 5) return;

  String from = cmd.substring(0, 2);
  String to   = cmd.substring(3, 5);

  // Here you would move steppers / magnet
  Serial.print("MOVE ");
  Serial.print(from);
  Serial.print(" -> ");
  Serial.println(to);

  // Placeholder delay to simulate motion
  delay(800);

  Serial.println("DONE");
}
