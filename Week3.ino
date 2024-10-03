const int analogInPinPM_1 = A0; // Potentiometer 1 PC0
const int analogInPinPM_2 = A1; // PM 2 PC1
                                // Connect both of PMs VCC to the + of breadboard (same with GND)
                                // connected to the 3.3V/GND (NOT 5V it will smoke again) of atpmega
const int analogOutPin = 13;    // Built-in LED
const int buttonPin = 7;        // Button connect to PD7

int PM_Val_1 = 0;
int PM_Val_2 = 0;
int ButtonVal = HIGH;     

/// LED fast blinking
bool fastBlinking = false;      // Track fast blinking state
unsigned long previousMillis = 0; // Store last time LED was updated
int blinkInterval = 500;        // Default to 1Hz (500ms on/off)

// Button debouncing
const unsigned long debounceDelay = 50; // milliseconds
unsigned long lastDebounceTime = 0; // last time the button state changed
int lastButtonState = HIGH; // previous button state

void setup() {
  Serial.begin(9600);
  Serial.println("Laurent Henri Plassart");
  Serial.println("2153058");
  Serial.println("Week 3. Analog");

  pinMode(analogOutPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);  
}

void loop() {
  // Read PMs values
  PM_Val_1 = analogRead(analogInPinPM_1);
  PM_Val_2 = analogRead(analogInPinPM_2);
  
  // Read button
  int reading = digitalRead(buttonPin);

  // Check button state
  if (reading != lastButtonState) {
    lastDebounceTime = millis(); // reset debounce timer
  }

  // Only change button state if button state has been stable
  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != ButtonVal) {
      ButtonVal = reading; // save button state
    }
  }
  lastButtonState = reading; // save last state

  // Check if button is pressed 
  if (ButtonVal == LOW) {
    // if pressed, revert to 1Hz blinking
    fastBlinking = false;
    blinkInterval = 500;  // 1Hz (500ms on, 500ms off)
  } else {
    // If PM values greater than 75, set 10Hz blinking
    if (PM_Val_1 > 75 && PM_Val_2 > 75) {
      fastBlinking = true;
      blinkInterval = 50; // 10Hz (50ms on, 50ms off)
    } else {
      // else maintain 1Hz blinking
      fastBlinking = false;
      blinkInterval = 500;  // 1Hz (500ms on, 500ms off)
    }
  }

  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= blinkInterval) {
    previousMillis = currentMillis; 
    digitalWrite(analogOutPin, !digitalRead(analogOutPin));
  }

  Serial.print(" sensor left = ");
  Serial.print(PM_Val_1);
  Serial.print(" sensor right = ");
  Serial.print(PM_Val_2);
  Serial.print(" Button = ");
  Serial.println(ButtonVal);
  
}
