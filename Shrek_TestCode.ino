#include <Servo.h>


Servo shrek;  // Create a servo object for servo on digital pin 2
Servo fiona; // Create a servo object for servo on digital pin 4
Servo dragon;  // Create a servo object for servo on digital pin 7
bool dragonPlaced = false; // Create a boolena for when the user places the dragon behind the window
bool shrekEvent = false;
bool fionaEvent = false;




//initialize buttons to pins that will affect each Servo
const int buttonShrek = 2;
const int buttonFiona = 4;
const int buttonDragon = 7;
const int buttonDragonStart = 5;
const int buttonFarquaad = 11;


int buttonStateS = 0;
int previousButtonStateS = 0;


int buttonStateF = 0;
int previousButtonStateF = 0;


int buttonStateD = 0;
int previousButtonStateD = 0;


int buttonStateDS = 0;
int previousButtonStateDS = 0;


int buttonStateFa = 0;
int previousButtonStateFa = 0;


void setup() {
  Serial.begin(9600);
  shrek.attach(8);  // Attaches servo shrek to digital pin 8
  fiona.attach(12);  // Attaches servo fiona to digital pin 12
  dragon.attach(13);  // Attaches servo dragon to digital pin 13
 
  pinMode(buttonShrek, INPUT);
  pinMode(buttonFiona, INPUT);
  pinMode(buttonDragon, INPUT);
  pinMode(buttonFarquaad, INPUT);
  pinMode(buttonDragonStart, INPUT);
 
  shrek.write(0);
  fiona.write(0);
  dragon.write(0);
}


void loop() {
  buttonStateS = digitalRead(buttonShrek);
  //read Shrek Button
  //if (buttonStateS != previousButtonStateS) {
  if (buttonStateS != previousButtonStateS || buttonStateDS != previousButtonStateDS) {
    if (digitalRead(buttonShrek) == HIGH && digitalRead(buttonDragonStart)) { //if button shrek AND button dragonstart is pressed
      Serial.println("SHREK");
      shrek.write(180);
      shrekEvent = true; // Move shrek servo to position 180 degrees
    } else { //if button shrek is not pressed
   
    }
  }
  previousButtonStateS = buttonStateS;//reset buttonState for Shrek
  previousButtonStateDS = buttonStateDS;
 
  buttonStateF = digitalRead(buttonFiona);
  //read Fiona Button
  if (buttonStateF != previousButtonStateF) {
    if (digitalRead(buttonFiona) == HIGH && shrekEvent == true) { //if button fiona is pressed
      fiona.write(180);
      fionaEvent = true; // Move fiona servo to position 180 degrees
    } else { //if button fiona is not pressed
     
    }
  }
  previousButtonStateF = buttonStateF; //reset buttonState for Fiona
 
 buttonStateD = digitalRead(buttonDragon);
  //read Dragon Button
  if (buttonStateD != previousButtonStateD) {
    if (digitalRead(buttonDragon) == HIGH && fionaEvent == true) { //if button dragon is pressed
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
