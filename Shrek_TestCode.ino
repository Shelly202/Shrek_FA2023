#include <Servo.h>

Servo shrek;  // Create a servo object for servo on digital pin 2
Servo fiona; // Create a servo object for servo on digital pin 4
Servo dragon;  // Create a servo object for servo on digital pin 7

//initialize buttons to pins that will affect each Servo
const int buttonShrek = 2;
const int buttonFiona = 4;
const int buttonDragon = 7;

int buttonStateS = 0;
int previousButtonStateS = 0;

int buttonStateF = 0;
int previousButtonStateF = 0;

int buttonStateD = 0;
int previousButtonStateD = 0;

void setup() {
  shrek.attach(8);  // Attaches servo shrek to digital pin 8
  fiona.attach(12);  // Attaches servo fiona to digital pin 12
  dragon.attach(13);  // Attaches servo dragon to digital pin 13
  
  pinMode(buttonShrek, INPUT);
  pinMode(buttonFiona, INPUT);
  pinMode(buttonDragon, INPUT);
}

void loop() { 
  
  buttonStateS = digitalRead(buttonShrek);
  //read Shrek Button
  if (buttonStateS != previousButtonStateS) {
    if (digitalRead(buttonShrek) == HIGH) { //if button shrek is pressed
  		shrek.write(180); // Move shrek servo to position 180 degrees
    } else { //if button shrek is not pressed
      	shrek.write(0);
    }
  }
  previousButtonStateS = buttonStateS; //reset buttonState for Shrek
  
  buttonStateF = digitalRead(buttonFiona);
  //read Fiona Button
  if (buttonStateF != previousButtonStateF) {
    if (digitalRead(buttonFiona) == HIGH) { //if button fiona is pressed
  		fiona.write(180); // Move fiona servo to position 180 degrees
    } else { //if button fiona is not pressed
      	fiona.write(0);
    }
  }
  previousButtonStateF = buttonStateF; //reset buttonState for Fiona
  
 buttonStateD = digitalRead(buttonDragon);
  //read Dragon Button
  if (buttonStateD != previousButtonStateD) {
    if (digitalRead(buttonDragon) == HIGH) { //if button dragon is pressed
  		dragon.write(180); // Move dragon servo to position 180 degrees
    } else { //if button dragon is not pressed
      	dragon.write(0);
    }
  }
  previousButtonStateD = buttonStateD; //reset buttonState for Dragon
  
}
