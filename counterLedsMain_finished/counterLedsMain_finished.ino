/****************************************************
  File name: Shachar Kaduri
  Description: Buzzer Beep
  Website:
  E-mail:
  Author:
  Date:
*****************************************************/
const int buttonPin = 2;    // the pin that the pushbutton is attached to
const int ledPin0 = 7;       // the pin that the LED is attached to
const int ledPin1 = 12;
const int ledPin2 = 4;
const int ledPin3 = 13;
const int setPin = 8;        // the pin that the setledbutton is attached to

// Variables will change:
int buttonPushCounter = 0;   // counter for the number of button presses which printed at last
int buttonState = 0;         // current state of the button
int lastButtonState = 0;     // previous state of the button
int setButtonState = 0;
int lastSetButtonState = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(setPin, INPUT); //Set the digital 8 port mode, OUTPUT: Output mode.
  pinMode(buttonPin, INPUT); //Set the digital 2 port mode, OUTPUT: Output mode.
  pinMode(ledPin0, OUTPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  countPushButtonPresses();
  setButtonIsPressed();
}

void PrintAndRaiseCounter() {
  buttonPushCounter++;
  Serial.print("number of button pushes: ");
  Serial.println(buttonPushCounter);
}

void countPushButtonPresses() {
  buttonState = digitalRead(buttonPin);

  if (buttonState != lastButtonState) {
    if (buttonState == LOW) {
      PrintAndRaiseCounter();
    }
    else {
    }
    delay(50);//avoid bouncing
  }

  lastButtonState = buttonState;
}

void setButtonIsPressed() {
  setButtonState = digitalRead(setPin);

  if (setButtonState != lastSetButtonState) {
    if (setButtonState == LOW) {
      setLeds();
    }
    else {
    }
    delay(50);//avoid bouncing
  }

  lastSetButtonState = setButtonState;
}

void setLeds() {
      //printing for debugging 
    Serial.println(buttonPushCounter&B0001);
    Serial.println(buttonPushCounter&B0010);
    Serial.println(buttonPushCounter&B0100);
    Serial.println(buttonPushCounter&B1000);
    Serial.print("Led Pin 0: ");
    Serial.println((buttonPushCounter&1)>>0);
    Serial.print("Led Pin 1: ");
    Serial.println((buttonPushCounter&2)>>1);
    Serial.print("Led Pin 2: ");
    Serial.println((buttonPushCounter&4)>>3);
    Serial.print("Led Pin 3: ");
    Serial.println((buttonPushCounter&8)>>7);
    
    digitalWrite(ledPin0, (buttonPushCounter&1)==1);
    digitalWrite(ledPin1, (buttonPushCounter&2)==2);
    digitalWrite(ledPin2, (buttonPushCounter&4)==4);
    digitalWrite(ledPin3, (buttonPushCounter&8)==8);
    
}
