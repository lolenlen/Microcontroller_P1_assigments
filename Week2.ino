const int ledPin = LED_BUILTIN;  // the number of the LED pin
int ledState = LOW;  // ledState used to set the LED
unsigned long previousMillis = 0;  // will store last time LED was updated
long interval = 1000;  // interval at which to blink (milliseconds)
int direction = 1;  // Default direction is forward

void setup() {
  Serial.begin(9600);
  Serial.println("Laurent Henri Plassart");
  Serial.println("2153058");
  Serial.println("Week 2. Basics");

  pinMode(ledPin, OUTPUT);

  // Set Pins for LEDs
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);

  // Buttons pins
  pinMode(7, OUTPUT);
  pinMode(6, INPUT_PULLUP);  // K1 button
  pinMode(5, INPUT_PULLUP);  // K2 button
  pinMode(4, INPUT_PULLUP);  // K3 button
  pinMode(3, INPUT_PULLUP);  // K4 button
}

int led = 8;

void loop() {
  unsigned long currentMillis = millis();

  // Read button states
  int buttonK1 = digitalRead(6);  
  int buttonK2 = digitalRead(5);  
  int buttonK3 = digitalRead(4);  
  int buttonK4 = digitalRead(3);  

  // Button K1 logic - Increase interval
  if (buttonK1 == LOW) {
    delay(250);  
    Serial.println("K1");

    if (interval < 2500) {
      interval += 100;  // increment interval by 100 ms
    } else {
      interval = 2500;  // max interval 2500 ms
    }
  }

  // Button K2 logic - Decrease interval
  if (buttonK2 == LOW) {
    delay(250); 
    Serial.println("K2");

    if (interval > 100) {
      interval -= 100;  // decrement interval by 100 ms
    } else {
      interval = 100;  // min interval 100 ms
    }
  }

  // Button K3 logic - Move LEDs Left to Right, vice versa
  if (buttonK3 == LOW) {
    delay(250);
    Serial.println("K3");
    if (direction == 1) {
      direction = -1;
    }  else {
      direction = 1;
    }
  }

  // Button K4 logic - Stop and continue LED
  if (buttonK4 == LOW) {
    delay(250);
    Serial.println("K4");
     if (direction == 1) {
      direction = 0;
    }  else {
      direction = 1;
    }
  }

  // Handle LED blinking based on interval
  if (currentMillis - previousMillis >= interval)
  {
    // save the last time LED was updated
    previousMillis = currentMillis;

    // Turn off current LED
    digitalWrite(led, LOW);

    // Set the next LED based on direction
    led = led + direction;

    // Wrap LED index if necessary
    if (led > 13) {
      led = 8;  // Wrap to the first LED
    } else if (led < 8) {
      led = 13;  // Wrap to the last LED
    }

    // Turn the new LED on
    digitalWrite(led, HIGH);
  }
}
