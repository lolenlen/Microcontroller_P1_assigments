const int analogPin = A0;

unsigned long previousMillis = 0;  // will store last time LED was updated
int direction = 1; // Initialize direction 
int led = 8;    
int analogIntervalValue = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("Laurent Henri Plassart");
  Serial.println("2153058");
  Serial.println("Week 5. Controls Structures");

  // Set LEDs
  for (int i = 8; i <= 13; i++) {
    pinMode(i, OUTPUT);
  }

  // Set PM
  pinMode(0, INPUT);

  // Set SW
  pinMode(20, INPUT_PULLUP);
}

int LED_direction() {
  if (Serial.available() > 0) {
    int inByte = Serial.read();
    switch (inByte) {
      case 'u':   // Forward
        return 1;
      case 'd':   // Backward
        return -1;
      default:
        Serial.println("Please input 'u' for forward or 'd' for backward direction");
        return direction; // its the intialized direction
    }
  }
  return direction;
}

void LED_chaser(int interval = 1) {
  unsigned long currentMillis = millis();
  int buttonState = digitalRead(20);

  // Only update the LEDs when the interval has passed
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    // Only change the LED position if the button is not pressed
    if (buttonState == HIGH) {
      digitalWrite(led, LOW); 

      direction = LED_direction();
      
      led += direction; 

      if (led > 13) {
        led = 8; 
      } else if (led < 8) {
        led = 13; 
      }

      digitalWrite(led, HIGH); 
    } else {
      // If button pressed, keep current LED lit
      digitalWrite(led, HIGH);
    }
  }
}


void loop() {
  analogIntervalValue = analogRead(analogPin);

  LED_chaser(analogIntervalValue);

  // debugging
  Serial.println(analogIntervalValue);
  delay(100);  
}
