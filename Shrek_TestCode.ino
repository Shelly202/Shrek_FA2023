//Branch test code from Chelsea -- adding Booleans

#include <Servo.h>

Servo shrek;  // Create a servo object for servo on digital pin 2
Servo fiona; // Create a servo object for servo on digital pin 4
Servo dragon;  // Create a servo object for servo on digital pin 7
bool dragonPlaced = false; // Create a boolean for when the user places the dragon behind the window
bool shrekEvent = false; 
bool fionaEvent = false;

/*
pseudocode

Add new boolean for shrek trigger - initially false
	set to true after green and purple token placed on circuit 
	(one time trigger-doesn't need to be deactivated or activiated again)

Add new boolean for fiona trigger - initially false
If shrek trigger is true 
	Function Fiona plays 
    fiona trigger set to true after sun is placed on back wall circuit
    (one time trigger-doesn't need to be deactivated or activiated again)
    else Function Fiona doesn't play
    
If fiona trigger is true 
	Function Dragon plays
    else Function Dragon doesn't play

*/


//initialize buttons to pins that will affect each Servo
const int buttonShrek = 2;
const int buttonFiona = 4;
const int buttonDragon = 7;
const int buttonFarquaad = 11;

int buttonStateS = 0;
int previousButtonStateS = 0;

int buttonStateF = 0;
int previousButtonStateF = 0;

int buttonStateD = 0;
int previousButtonStateD = 0;

int buttonStateFa = 0;
int previousButtonStateFa = 0;

void setup() {
  shrek.attach(8);  // Attaches servo shrek to digital pin 8
  fiona.attach(12);  // Attaches servo fiona to digital pin 12
  dragon.attach(13);  // Attaches servo dragon to digital pin 13
  
  pinMode(buttonShrek, INPUT);
  pinMode(buttonFiona, INPUT);
  pinMode(buttonDragon, INPUT);
  pinMode(buttonFarquaad, INPUT);
  
  shrek.write(0);
  fiona.write(0);
  dragon.write(0);
  
  Serial.begin(9600);
}

void loop() { 
  
  buttonStateS = digitalRead(buttonShrek);
  //read Shrek Button
  if (buttonStateS != previousButtonStateS) {// button is pushed or unpushed
    if (digitalRead(buttonShrek) == HIGH) { //if button shrek is pressed
  		shrek.write(180); // Move shrek servo to position 180 degrees
      	shrekEvent = true; //allows Fionabutton to work
    	//Serial.println("ShrekEvent is true"); Debugging
    } else { //if button shrek is not pressed
      	shrek.write(0);
    }
  }
  previousButtonStateS = buttonStateS;//reset buttonState for Shrek
  
 if (shrekEvent == true) { // if shrek's event has happened
  buttonStateF = digitalRead(buttonFiona);
  //read Fiona Button
  if (buttonStateF != previousButtonStateF) {
    if (digitalRead(buttonFiona) == HIGH) {
  		fiona.write(180); // Move fiona servo to position 180 degrees
      	fionaEvent = true; // allows Dragonbutton to work
      	//Serial.println("FionaEvent is true"); Debugging
    } else { //if button fiona is not pressed
      	fiona.write(0);
    }
  
  }
  previousButtonStateF = buttonStateF; //reset buttonState for Fiona
 }
  
if (fionaEvent == true) { // if fiona's transformation has happened
 buttonStateD = digitalRead(buttonDragon);
  //read Dragon Button
  if (buttonStateD != previousButtonStateD) {
    if (digitalRead(buttonDragon) == HIGH) { //if button dragon is pressed
      if (dragonPlaced == false) {
        dragon.write(90); // move dragon to window
        dragonPlaced = true; // set dragon bool to true
    } else { //if button dragon is not pressed
      	// dragon.write(0); commented out for testing purposes
      }
    }
  }
  previousButtonStateD = buttonStateD; //reset buttonState for Dragon

  buttonStateFa = digitalRead(buttonFarquaad);
  if (buttonStateFa != previousButtonStateFa) {
    if (digitalRead(buttonFarquaad) == HIGH) {
      if (dragonPlaced == true) {
          dragon.write(180);
      }
    }
  }
  previousButtonStateFa = buttonStateFa;
  
 }
  
}
