// Made by Laurent Henri Plassart, 2153058
// of ESE-1D-e for Microcontrollers 1
// as a Requirement for Week 6 S1,P1

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

int trigPin = 9; 
int echoPin = 10; 
long duration, cm;
unsigned long previousMillis = 0;
long interval = 100;  

// switchState detection
int lastSwitchState = HIGH;  // previous switchState
int currentSwitchState;      // current switchState
bool LEDState = false;       // Tracks the LEDState

void setup()
{
  // make sure to initialize lcd and have the backlight on to be visible
  lcd.init();                    
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Laurent Plassart");

  pinMode(trigPin, OUTPUT);  
  pinMode(echoPin, INPUT);  

  pinMode(13, OUTPUT);      
  pinMode(20, INPUT_PULLUP); 
}

// led toggle checks if led is already on or not then does the other
void LEDToggle() {
  LEDState = !LEDState; 
  digitalWrite(13, LEDState ? HIGH : LOW);
}

void loop()
{
  unsigned long currentMillis = millis();
  
  currentSwitchState = digitalRead(20);

  if (currentSwitchState == LOW && lastSwitchState == HIGH) {
    LEDToggle();
    delay(50);
  }
  
  // Update last switchState
  lastSwitchState = currentSwitchState;

  if (currentMillis - previousMillis >= interval) 
  {
    previousMillis = currentMillis;

    // Trigger ultrasonic pulse
    digitalWrite(trigPin, LOW);
    delayMicroseconds(5);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    // Read echo
    duration = pulseIn(echoPin, HIGH);
    
    // Convert time to distance in cm
    cm = (duration / 2) / 29.1;

    // Display distance on LCD
    if (cm < 10) {
      lcd.setCursor(0,1);
      lcd.print("Dist: <10 cm ");
      digitalWrite(13, LOW);
    } else if (cm > 180) {
      lcd.setCursor(0,1);
      lcd.print("Dist: >180 cm ");
    digitalWrite(13, HIGH); // Turn on LED for distances greater than 180 cm
      distanceOverrideLED = true;

    } else {
      lcd.setCursor(0,1);
      lcd.print("Dist: ");
      lcd.print(cm);
      lcd.print(" cm   "); 
    }
  }
}
