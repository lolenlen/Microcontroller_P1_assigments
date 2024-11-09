// Made by Laurent Henri Plassart, 2153058
// of ESE-1D-e for Microcontrollers 1
// as an Assignment for Week 1 S1,P1

void setup() {
  // Welccome message
  Serial.begin(9600);
  Serial.println("Laurent Henri Plassart");
  Serial.println("2153058");
  Serial.println("Week 1. Basics");

  // Set Pins 13, 12, 11, 10, 9, and 8 as outputs LEDs
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
}


void loop() {
  // Turn the LEDs on from PB0/D6 to PB5/D1
  // Wait for 100ms each time
  digitalWrite(8, HIGH);
  delay(100)); 
  digitalWrite(9, HIGH);
  delay(100)); 
  digitalWrite(10, HIGH);
  delay(100)); 
  digitalWrite(11, HIGH);
  delay(100)); 
  digitalWrite(12, HIGH);
  delay(100)); 
  digitalWrite(13, HIGH);
  delay(100)); 


  // Turn the LEDs off from D1 to D6
  // Wait for 100ms each time
  digitalWrite(13, LOW);
  delay(100));
  digitalWrite(12, LOW);
  delay(100));
  digitalWrite(11, LOW);
  delay(100));
  digitalWrite(10, LOW);
  delay(100));
  digitalWrite(9, LOW);
  delay(100));
  digitalWrite(8, LOW);
  delay(100));

  // Opposite way of
  // Turning the LEDs on from D1 to D6
  // Wait for 100ms each time
  digitalWrite(13, HIGH);
  delay(100));
  digitalWrite(12, HIGH);
  delay(100));
  digitalWrite(11, HIGH);
  delay(100));
  digitalWrite(10, HIGH);
  delay(100));
  digitalWrite(9, HIGH);
  delay(100));
  digitalWrite(8, HIGH);
  delay(100));

  // Turn the LEDs off from D6 to D1
  // Wait for 100ms each time
  digitalWrite(8, LOW);
  delay(100));
  digitalWrite(9, LOW);
  delay(100));
  digitalWrite(10, LOW);
  delay(100));
  digitalWrite(11, LOW);
  delay(100));
  digitalWrite(12, LOW);
  delay(100));
  digitalWrite(13, LOW);
  delay(100));
}

