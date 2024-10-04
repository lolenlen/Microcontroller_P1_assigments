// Made by Laurent Henri Plassart, 2153058
// of ESE-1D-e for Microcontrollers 1
// as an Assignment for Week 4 S1,P1

int secretNumber = 2153058;
int guessedNumber;
int guessAmount = 3;
int guessAmountLeft;
int tries;

void setup() {
  Serial.begin(9600);
  Serial.println("Laurent Henri Plassart");
  Serial.println("2153058");
  Serial.println("Week 4. Communication");

  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(1, OUTPUT);

  guessAmountLeft = guessAmount;
  tries = 0;
}

void LED_lit_up(int tries) {
  if (tries == 0) {
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);    
  } else if (tries == 1) {
    digitalWrite(8, HIGH);
    digitalWrite(1, HIGH);
    delay(200);
    digitalWrite(1, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW); 
  } else if (tries == 2) {
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(1, HIGH);
    delay(200);
    digitalWrite(1, LOW);
    digitalWrite(10, LOW); 
  } else if (tries == 3) {
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH); 
    digitalWrite(1, HIGH);
    delay(200);
    digitalWrite(1, LOW);
  }
}

void compareGuess() {
  if (guessedNumber == secretNumber) {
    Serial.println("Congrats! You've guessed the correct number.");
    tries = 0;
    LED_lit_up(0);
  } else {
    tries++;
    guessAmountLeft = guessAmount - tries;
    if (guessAmountLeft > 0) {
      Serial.print("Wrong guess! You have ");
      Serial.print(guessAmountLeft);
      Serial.println(" guess(es) left. Try again!");
      LED_lit_up(tries);
    } else {
      Serial.println("INVALID CODE: APPLICATION IS INDEFINITELY LOCKED");
      Serial.println("PHOTO OF THE PERPETRATOR TAKEN");
      Serial.println("CALLING THE POLICE...");
      delay(2000);
      Serial.println("AUTHORITIES ON THEIR WAY!");
      LED_lit_up(tries);
    }
  }
}

void loop() {
  if (Serial.available() > 0) {
    guessedNumber = Serial.parseInt();
    if (guessedNumber != 0) {
      compareGuess();
    } else {
      Serial.println("Invalid input! Please enter a valid number.");
    }
  }
}
