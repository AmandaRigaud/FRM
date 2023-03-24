// C++ code
#include <Servo.h>

//Define variables to use
int pos = 0;
int prePos = 0;
int servoPos;

//Define the flex sensor's pin
int flexpin = A0;
//Define the servo's pin
int servopin = 7;
//Define the servo
Servo servo;

void setup()
{
  Serial.begin(9600);
  
  //Enable flex sensor port like input
  pinMode(flexpin, INPUT);
  
  //Setting servo motor
  servo.attach(servopin);
  servo.write(0);
}

void loop()
{
  //Read flex sensor value
  pos = analogRead(flexpin);
  
  //Convert flex sensor value to servo motor equivalent
  servoPos = map(pos, 990, 1017, 0, 180);
  
  //Change servo motor position to calculed position
  servo.write(servoPos);
  
  //If the position change, show to user the new position
  if(prePos != servoPos){
    prePos = servoPos;
    Serial.print("Flex sensor position: ");
    Serial.println(pos);
    Serial.print("Servo motor position: ");
    Serial.println(servoPos);
    Serial.println(" ");
  }
  
  //delay(10);
}