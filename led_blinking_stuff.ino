/*
  Arduino Starter Kit example
  Project 2 - Spaceship Interface

  This sketch is written to accompany Project 2 in the Arduino Starter Kit

  Parts required:
  - one green LED
  - two red LEDs
  - pushbutton
  - 10 kilohm resistor
  - three 220 ohm resistors

  created 13 Sep 2012
  by Scott Fitzgerald

  http://www.arduino.cc/starterKit

  This example code is part of the public domain.
*/

// Create a global variable to hold the state of the switch. This variable is
// persistent throughout the program. Whenever you refer to switchState, you’re
// talking about the number it holds
int switchstate = 0;
const int greenled= 3;
const int redled1 = 4;
const int redled2 = 5;
const int pinin = 2;
int delaytime = 250;                                                                                                                                                                                                                                                                                                                         

void setup() {
  // declare the LED pins as outputs
  pinMode(greenled, OUTPUT);
  pinMode(redled1, OUTPUT);
  pinMode(redled2, OUTPUT);

  // declare the switch pin as an input
  pinMode(pinin, INPUT);
}

void loop() {

  // read the value of the switch
  // digitalRead() checks to see if there is voltage on the pin or not
  switchstate = digitalRead(pinin);

  // if the button is not pressed turn on the green LED and off the red LEDs
  if (switchstate == LOW) {
    digitalWrite(greenled, HIGH); // turn the green LED on pin 3 on
    digitalWrite(redled1, LOW);  // turn the red LED on pin 4 off
    digitalWrite(redled2, LOW);  // turn the red LED on pin 5 off
  }
  // this else is part of the above if() statement.
  // if the switch is not LOW (the button is pressed) turn off the green LED and
  // blink alternatively the red LEDs
  else {
    digitalWrite(greenled, LOW);  // turn the green LED on pin 3 off
    digitalWrite(redled1, LOW);  // turn the red LED on pin 4 off
    digitalWrite(redled2, HIGH); // turn the red LED on pin 5 on
    // wait for a quarter second before changing the light
    delay(delaytime);
    digitalWrite(redled1, HIGH); // turn the red LED on pin 4 on
    digitalWrite(redled2, LOW);  // turn the red LED on pin 5 off
    // wait for a quarter second before changing the light
    delay(delaytime);
  }
}
