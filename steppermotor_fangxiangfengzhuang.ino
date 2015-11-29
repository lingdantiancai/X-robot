/*
Adafruit Arduino - Lesson 16. Stepper
*/

#include <Stepper.h>
int  distance = 900;
int  turn = 300;
int in1Pin = 12;
int in2Pin = 11;
int in3Pin = 10;
int in4Pin = 9;

int in5Pin = 8;
int in6Pin = 7;
int in7Pin = 6;
int in8Pin = 5;
Stepper motor2(1000,in5Pin, in6Pin, in7Pin, in8Pin);
Stepper motor(1000, in1Pin, in2Pin, in3Pin, in4Pin); 
char val;
void forward();
void back();
void left();
void right();
int thisStep;
void setup()
{ 
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  pinMode(in3Pin, OUTPUT);
  pinMode(in4Pin, OUTPUT);

  pinMode(in5Pin,OUTPUT);
  pinMode(in6Pin,OUTPUT);
  pinMode(in7Pin,OUTPUT);
  pinMode(in8Pin,OUTPUT);// this line is for Leonardo's, it delays the serial interface
  // until the terminal window is opened
  while (!Serial);
  
  Serial.begin(9600);
  motor.setSpeed(20);
  motor2.setSpeed(20);
}

void loop()
{
  if(Serial.available()>0)
  thisStep = Serial.read();
  /*switch(thisStep)
 {
  case 'f': 
  {
  forward();
  break;
  }
  case 'b':
  {
  back(); 
  break;
  }
  case 'l':
  {
  left();
  break;
  }
  case 'r':
  {
  right();
  break;
  }
  */
  if(thisStep == 'f')
  forward();
  if(thisStep == 'b')
  back();
  if(thisStep == 'l')
  left();
  if(thisStep == 'r')
  right();
 

  while(Serial.read() >= 0){}
  
}

void forward()
{
  motor.step(distance); 
  motor2.step(distance);
  delay(30);
  }
void back()
{
  motor.step(-distance); 
  motor2.step(-distance);
   delay(30);
  }
void left()
{
  motor.step(-turn); 
  motor2.step(turn);
   delay(30);
  }
void right()
{
  motor.step(turn); 
  motor2.step(-turn);
   delay(30);
  }
 
  
