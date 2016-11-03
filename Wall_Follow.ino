#include <Servo.h>


Servo motorPin;
int pos = 0; //variable to store servo position
Servo motorPin1;

  int distance = analogRead(25);    //left side
  int distance1 = analogRead(26);  //front side

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  motorPin.attach(19);
  motorPin1.attach(17);
  
}

void loop() 
{
  
  
  distance = analogRead(25);    //left side
  distance1 = analogRead(26);  //front side
  //Sserial.print("Distance 1: ");
 // Serial.println(distance);
 // delay(500);
  Serial.print("Distance 2: ");
  Serial.println(distance1);
  //delay(500);
  // put your main code here, to run repeatedly: 
  if ((distance > 2000 and distance < 3000) and distance1 <= 1000 ) //go forward
  {
    //going forward
    motorPin.write(199);
     motorPin1.write(-199);
  }
 else if(distance > 3000 and distance1 > 3000) //turn right
  {
    for (pos = 90; pos <= 90+35; pos++) 
    {
    motorPin.write(pos);
    motorPin1.write(pos);
    delay(15);
    }
  }
 /* else if (distance >= 3000) //turn slight right
  {
    for (pos = 90; pos <= 90+20; pos++) 
    {
    motorPin.write(pos);
    motorPin1.write(pos);
    delay(15);
    }
  }*/
  else  //turn left
  {
   for (pos = 90; pos >= 35; pos--) {
    motorPin.write(pos);
    motorPin1.write(pos);
    delay(15);
  } 
  motorPin.write(199);
  motorPin1.write(-199);
  delay(15);
  } 
 /*else if(distance <= 3000 and distance1 <= 3000) //turn slight left
  {
  for (pos = 90; pos >= 65; pos--) {
    motorPin.write(pos);
    motorPin1.write(pos);
    delay(15);
  }
  motorPin.write(199);
     motorPin1.write(-199);
     delay(15);
  }
  
  
  distance = analogRead(25);    //left side
  distance1 = analogRead(26);  //front side 
  //turn
  
  /* 
  //backward
  for (pos = 180; pos >= 1; pos-=1)
  {
    motorPin.write(pos);
    motorPin1.write(180-pos);
    delay(15);
  }

  //turn
  for (pos = 180; pos >=1; pos--) {
    motorPin.write(pos);
    motorPin1.write(pos);
    delay(15);
  }*/
}
