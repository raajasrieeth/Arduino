#include <LiquidCrystal.h>
const int rs =4 , en =5 , d4 =6, d5 =7, d6 =8, d7 =9;
const int trigPin = 2;
const int echoPin = 3;
LiquidCrystal  lcd(rs , en, d4, d5, d6, d7);
 long duration;
 int distance;

void setup() {
  lcd.begin(16 ,2);
  lcd.print("hello, Raaj");
  delay(3300);
     
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);

}

void loop() {
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration=pulseIn(echoPin, HIGH);
  distance=duration*0.034/2;
  Serial.print("Distance:");
  Serial.print(distance);
   lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print(distance);
  
  for (int positionCounter = 0; positionCounter < 13; positionCounter++) {
    // scroll one position left:
    lcd.scrollDisplayLeft();
    // wait a bit:
    delay(150);
  }

  // scroll 29 positions (string length + display length) to the right
  // to move it offscreen right:
  for (int positionCounter = 0; positionCounter < 29; positionCounter++) {
    // scroll one position right:
    lcd.scrollDisplayRight();
    // wait a bit:
    delay(150);
  }

  // scroll 16 positions (display length + string length) to the left
  // to move it back to center:
  for (int positionCounter = 0; positionCounter < 16; positionCounter++) {
    // scroll one position left:
    lcd.scrollDisplayLeft();
    // wait a bit:
    delay(150);
  }
  
  

}
