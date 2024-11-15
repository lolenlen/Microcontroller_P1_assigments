// Made by Laurent Henri Plassart, 2153058
// of ESE-1D-e for Microcontrollers 1
// as an Assignment for Week 4 S1,P1

// set secret number, amout of guess, and the tries
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

  // check if the play has guessed 3 times then set the amount of tries to 0
  guessAmountLeft = guessAmount;
  tries = 0;
}

void LED_lit_up(int tries) {
  if (tries == 0) {
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);    // user haven't guessed yet
  } else if (tries == 1) {
    digitalWrite(8, HIGH);
    digitalWrite(1, HIGH);
    delay(200);
    digitalWrite(1, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW); // first guess wrong 1 LED lit up
  } else if (tries == 2) {
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(1, HIGH);
    delay(200);
    digitalWrite(1, LOW); // 2nd guess wrong 2 LEDs lit up
    digitalWrite(10, LOW); 
  } else if (tries == 3) {
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH); 
    digitalWrite(1, HIGH);
    delay(200);
    digitalWrite(1, LOW); // final guess wrong hence 3 LEDs lit up
  }
}

// comparing the guess to the secret number logic
void compareGuess() {
  if (guessedNumber == secretNumber) { 
    Serial.println("Congrats! You've guessed the correct number.");
    tries = 0; // reset tries after correct guess
    LED_lit_up(0); // turn off all LEDs
  } else {
    tries++; // increment tries for wrong guess
    guessAmountLeft = guessAmount - tries; // update remaining guesses
    if (guessAmountLeft > 0) {
      Serial.print("Wrong guess! You have ");
      Serial.print(guessAmountLeft);
      Serial.println(" guess(es) left. Try again!");
      LED_lit_up(tries); // update LEDs for current try count
    } else {
      Serial.println("INVALID CODE: APPLICATION IS INDEFINITELY LOCKED");
      Serial.println("PHOTO OF THE PERPETRATOR TAKEN");
      Serial.println("CALLING THE POLICE...");
      delay(2000);
      Serial.println("AUTHORITIES ON THEIR WAY!");
      LED_lit_up(tries); // all LEDs lit after lockout
    }
  }
}

void loop() {
  if (Serial.available() > 0) { // check for input from serial monitor
    guessedNumber = Serial.parseInt(); // read user input as an integer
    if (guessedNumber != 0) {
      compareGuess(); // process valid guess
    } else {
      Serial.println("invalid input! please enter a valid number."); 
      // handle invalid or non-numeric input
    }
  }
}
