const int buttonPin = 4; // GPIO 3 (D3)

void setup() {
  Serial.begin(115200);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  int buttonState = digitalRead(buttonPin);

  if (buttonState == LOW) { // Car bouton à GND = actif bas
    Serial.println("Bouton pressé");
  } else {
    Serial.println("Bouton relâché");
  }

  delay(100);
}
