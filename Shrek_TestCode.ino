#include <Servo.h>

Servo servo; //create servo variable
const int buttonPin = 2; //create buttonpin

int buttonState = 0;
int previousButtonState = 0;

void setup()
{
  servo.attach(12); // attach servo to pin 12
  pinMode(buttonPin, INPUT);
}

void loop()
{
 buttonState = digitalRead(buttonPin);
  //read if buttonPin
  if (buttonState != previousButtonState) {
  	if (digitalRead(buttonPin) == HIGH) { //if button pressed
    	servo.write(180); //move servo to position 180
  	} else { //if button not pressed
    	servo.write(0); //move servo to position 0
  	}
  }
  previousButtonState = buttonState;
  
}
