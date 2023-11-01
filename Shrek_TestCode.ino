// C++ code
// milan branch change

#include <Servo.h>
//taken from Prof code on Canvas slides

Servo servo; //create servo variable
const int buttonPin = 2; //create buttonpin

void setup()
{
  servo.attach(12); // attach servo to pin 12
  pinMode(buttonPin, INPUT);
}

void loop()
{
  //read if buttonPin
  if (digitalRead(buttonPin) == LOW) { 
    servo.write(180); //move servo 180
  } else {
    servo.write(0); //do not move servo/move servo 0 
  }
}
