
/*
 Stepper Motor Control - one revolution

 This program drives a unipolar or bipolar stepper motor.
 The motor is attached to digital pins 8 - 11 of the Arduino.

 The motor should revolve one revolution in one direction, then
 one revolution in the other direction.


 Created 11 Mar. 2007
 Modified 19 May. 2018
 by Benak Patel

 */

#include <Stepper.h>

const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution
// for your motor

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);         //8&9 for PUL+ and PUL-;10&11 for DIR+ and DIR-
boolean state, lastState;                                   
int flag=0;
void setup() {
  pinMode(2,INPUT_PULLUP);                //at all times signal read is logic 1 and only when the switch is pressed logic 0 is read
  state = digitalRead(2);                 //digital read returns 1(TRUE) or 0(FALSE) depending on the switch position
  lastState = state;
                                      // set the speed at 20 rpm:
  myStepper.setSpeed(20);             //initialise stepper motor with rotation speed of 20 rpm
  Serial.begin(9600);                 // initialize the serial port:
  
}

void loop() {
  lastState = state;
  state = digitalRead(2);   //keepon reading the digital pin no.2 of Arduino 

if ( state != lastState ) {

  if(flag==0)
  {
  clkwise();     //call clkwise function to rotate stepper motor exactly 90'
  delay(1000);
  flag=1;         //change flag to 1, to avoid repeatation
    }
  else
  {
    Anticlkwise();    //call Anticlkwise function to rotate stepper motor exactly 90' in opposite direction
    delay(1000);
    flag=0;       //change flag to 0, to avoid repeatation
  }
}
}
void clkwise()
{
  Serial.println("clockwise");
  myStepper.step(stepsPerRevolution);
  delay(800);
  }
void Anticlkwise()
{
Serial.println("counterclockwise");
  myStepper.step(-stepsPerRevolution);
  delay(800);
} 
