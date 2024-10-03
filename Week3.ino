const int analogInPinPM = A0; // Potentiometer
const int analogInPinLDR = A1; // LDR
const int analogOutPin = 13;   // Built-in LED
const int buttonPin = 7;       // Button pin (changed to 7)

int PotentiometerVal = 0;
int LDRVal = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("Laurent Henri Plassart");
  Serial.println("2153058");
  Serial.println("Week 3. Analog");

  // Set LED pin
  pinMode(analogOutPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);  // Use pin 7 and internal pull-up resistor
}

void loop() {
  PotentiometerVal = analogRead(analogInPinPM);
  LDRVal = analogRead(analogInPinLDR);
  int ButtonVal = digitalRead(buttonPin);

  // LED control based on potentiometer and LDR values
  if (PotentiometerVal > 75 && LDRVal > 75) {
    digitalWrite(analogOutPin, HIGH);  // Turn on LED if conditions are met

    // Check if button is pressed (input will be LOW when pressed)
    if (ButtonVal == LOW) {
      digitalWrite(analogOutPin, LOW);  // Turn off LED if button is pressed
    }
  } else {
    digitalWrite(analogOutPin, LOW);  // Turn off LED if conditions aren't met
  }

  // Print sensor values to Serial Monitor
  Serial.print("sensor PM = ");
  Serial.print(PotentiometerVal);
  Serial.print("\t sensor LDR = ");
  Serial.println(LDRVal);

  delay(500);  // Longer delay for easier reading
}
