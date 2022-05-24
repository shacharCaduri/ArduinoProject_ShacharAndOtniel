#include <LiquidCrystal.h>

/****************************************************
  File name: Shachar Kaduri & Otniel Yazdi
  Description: Push Buttons Counter and Set  LEDs
  Website:
  E-mail:
  Author:
  Date:
  
 LiquidCrystal Library - Counter and Set Button displaying the counter presses number.

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch prints "number of presses the user pressed the counter button" to the LCD
 and shows the time.

  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe
 modified 7 Nov 2016
 by Arturo Guadalupi

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystalHelloWorld
*****************************************************/
const int buttonPin = 7;    // the pin that the pushbutton is attached to
const int setPin = 8;       // the pin that the setledbutton is attached to
const int RSPin=12;         //A register select (RS) pin that controls where in the LCD's memory you're writing data to. 
                            //You can select either the data register, which holds what goes on the screen, or an 
                            //instruction register, which is where the LCD's controller looks for instructions on what to do next.
                            
const int EnablePin=11;     //An Enable pin that enables writing to the registers
const int RWPin=0;          // control if it'll be write/read to the register. Currently connected to GND and not to any pin but for any case someone will want to use I wrote this const

//8 data pins (D0 -D7). The states of these pins (high or low) 
//are the bits that you're writing to a register when you write,
//or the values you're reading when you read.
const int D7Pin=2;          
const int D6Pin=3;          
const int D5Pin=4;          
const int D4Pin=5;          
//End of const connected D0-7 pins

                            
// Variables will change:
int buttonPushCounter = 0;   // counter for the number of button presses which printed at last
int buttonState = 0;         // current state of the button
int lastButtonState = 0;     // previous state of the button
int setButtonState = 0;
int lastSetButtonState = 0;
LiquidCrystal lcd(RSPin, EnablePin, D4Pin, D5Pin, D6Pin, D7Pin);

void setup() {
  // put your setup code here, to run once:
  pinMode(setPin, INPUT); //Set the digital 8 port mode, OUTPUT: Output mode.
  pinMode(buttonPin, INPUT); //Set the digital 2 port mode, OUTPUT: Output mode.
  lcd.begin(16, 2);
  lcd.print("hi Otniel, look ");
  lcd.setCursor(0,1);
  lcd.print("what I have made!");
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
      setLCD();
    }
    else {
    }
    delay(50);//avoid bouncing
  }

  lastSetButtonState = setButtonState;
}

void setLCD() {
  Serial.println("set button has been pressed");
  lcd.setCursor(0,0);
  lcd.print("                 ");
  lcd.setCursor(0,0);
  lcd.print("Num of presses:");
  lcd.setCursor(0,1);
  lcd.print("                 ");
  lcd.setCursor(0,1);
  lcd.print(buttonPushCounter);
}
