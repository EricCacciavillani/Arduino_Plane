
#include <Servo.h> 
Servo myServoYaw;  // create servo object to control a servo 
Servo myServoPitch;
Servo myServoElevator;
Servo myServoRudder;// a maximum of eight servo objects can be created 
Servo myServoAileron;
Servo myServoRoll;
int count=-1;
int pos = 0;    // variable to store the servo position 
Servo up;
int temp;
const int centerForPitchInt=83;//centers the pitch in the begining
const int centerForYawInt=60;//centers the yaw in the begining
const int minElevatorValue=40;//brings it towards the front of the plane 
const int maxElevatorValue=64;//brings it away from thefront of the plane
const int centerRudderValue=65;
const int minRudderValue=50;//brings it towards the front of the plane 
const int maxRudderValue=78;//brings it away f the front of the plane 
const int centerElevatorValue=45;
const int minAileronValue=90;
const int centerAileronValue=110;
const int maxAileronValue=130;
int first=0;
//Take off(level out),Yaw Left Rudder comes towards during it going left,Yaw Left Rudder comes towards during it going right Elvator up, Pitch up,Elvator back to normal state, 
//Pitch to normal,Yaw Left Rudder comes towards during it going left,   
void playNextSound()
{
  digitalWrite(0,HIGH);
  delay(2000);
  digitalWrite(0,LOW);
}
void goRight()
{
  count=centerRudderValue;
  for(int i=60;i>=30;i--)
  {
    myServoYaw.write(i);
   if(count<maxRudderValue)
    {
      myServoRudder.write(count);
      count++;
    }
    delay(45);
  }
 count=maxRudderValue;
 for(int i=30;i<=60;i++)
 {
    myServoYaw.write(i);
    if(count>centerRudderValue)
    {
      myServoRudder.write(count);
      count--;
    }
    delay(45);
  }
}
void goLeft()
{
   count=centerRudderValue;
  for(int i=60;i<=90;i++)
  {
    myServoYaw.write(i);
    if(count>minRudderValue)
    {
      myServoRudder.write(count);
      count--;
    }
    delay(45);
  }
 count=minRudderValue;
 for(int i=90;i>=60;i--)
 {
    myServoYaw.write(i);
       if(count<centerRudderValue)
    {
      myServoRudder.write(count);
      count++;
    }
    delay(45);
  }
}
void goUp()
{
   for(int i=centerElevatorValue;i<maxElevatorValue;i++)
  {
    myServoElevator.write(i);
    delay(45);
  }
    for(int i=centerForPitchInt;i>=centerForPitchInt-25;i--)
  {
    myServoPitch.write(i);
    delay(45);
  }
   for(int i=maxElevatorValue;i>centerElevatorValue;i--)
  {
    myServoElevator.write(i);
    delay(45);
  }
    for(int i=centerForPitchInt-24;i<=centerForPitchInt;i++)
  {
    myServoPitch.write(i);
    if(centerForPitchInt==i)
    {
      delay(500);
    }
    else
    {
    delay(45);
    }
  }
}
void goDown()
{
  for(int i=centerElevatorValue;i>minElevatorValue;i--)
  {
    myServoElevator.write(i);
    delay(45);
  }
    for(int i=centerForPitchInt;i<=centerForPitchInt+25;i++)
  {
    myServoPitch.write(i);
    delay(45);
  }
     for(int i=minElevatorValue;i<centerElevatorValue;i++)
  {
    myServoElevator.write(i);
    delay(45);
  }
    for(int i=centerForPitchInt+24;i>=centerForPitchInt;i--)
  {
    myServoPitch.write(i);
    if(centerForPitchInt==i)
    {
      delay(500);
    }
    else
    {
    delay(45);
    }
  }
}
void rollRight()
{
  //92 center    75 left   112 right 
   count=centerAileronValue;
  for(int i=92;i<=112;i++)
  {
    myServoRoll.write(i);
    if(count>minAileronValue)
    {
      myServoAileron.write(count);
      count--;
    }
    delay(45);
  }
 count=minAileronValue;
 for(int i=111;i>=92;i--)
 {
    myServoRoll.write(i);
     if(count<centerAileronValue)
    {
      myServoAileron.write(count);
      count++;
    }
    delay(45);
  }
}
void rollLeft()
{
  //92 center    75 left   112 right 
   count=centerAileronValue;
  for(int i=92;i>=75;i--)
  {
    myServoRoll.write(i);
    if(count<maxAileronValue)
    {
      myServoAileron.write(count);
      count++;
    }
    delay(45);
  }
 count=maxAileronValue;
 for(int i=75;i<=92;i++)
 {
    myServoRoll.write(i);
     if(count>centerAileronValue)
    {
      myServoAileron.write(count);
      count--;
    }
    delay(45);
  }
}
int check=0;
void setup() 
{ 
  pinMode(12, OUTPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  pinMode(11,OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(0,OUTPUT);
  myServoPitch.attach(6);
  //delay(145);
  //myServoPitch.write(centerForPitchInt+25);
  //starting up and down axis 
  myServoYaw.attach(7);  // attaches the servo on pin 9 to the servo object
  myServoElevator.attach(2);
  myServoRudder.attach(3);
  myServoAileron.attach(4);
  myServoRoll.attach(5);
  myServoRoll.write(92);
  //myServoPitch.write(centerForPitchInt);
  myServoYaw.write(centerForYawInt);//starting left and right axis
  myServoElevator.write(centerElevatorValue);
  myServoAileron.write(centerAileronValue);
  myServoRudder.write(65);
} 
//Take off(level out),Yaw Right Rudder goes away during it going right,Yaw Left Rudder comes towards during it going right Elvator up, Pitch up,Elvator back to normal state, 
//Pitch to normal,Yaw Left Rudder comes towards during it going left, 
void motorDown()
{
   while(digitalRead(8)==LOW)
  {
    digitalWrite(13,LOW);
    digitalWrite(12,HIGH);
    analogWrite(11,255);
    //check=1;
  }
  analogWrite(11,0);
}
void motorUp()
{
   while(digitalRead(9)==LOW)
  {
    digitalWrite(13,HIGH);
    digitalWrite(12,LOW);
    analogWrite(11,255);
    //check=1;
  }
  analogWrite(11,0);
}

 //Yaw servo ranges are 20 to 99
 //bottom servo ranges are 34 to 99 
void loop() 
{
  /*
  if(count!=-1)
  {
    myServoPitch.write(centerForPitchInt);//starting up and down axis
    myServoYaw.write(centerForYawInt);//starting left and right axis
    myServoElevator.write(centerElevatorValue);
    myServoAileron.write(centerAileronValue);
    myServoRudder.write(65); 
  }
  */
  if(first==0)
  {
    
  playNextSound();
  //delay(6000);
  motorDown();
  playNextSound();
  motorUp();
  for(int i=centerForPitchInt+48;i>centerForPitchInt;i--)
  {
    myServoPitch.write(i);
    delay(85);
  }
  playNextSound();
  //play all WAVE
  goUp();
  goUp();
  goRight();
  rollLeft();
  goDown();
  rollRight();
  goLeft();
  delay(5000);
  playNextSound();
  goUp();
  goRight();
  goDown();
  goRight();
  goUp();
  goDown();
  delay(2000);
  playNextSound();
  goUp();
  goLeft();
  goRight();
  delay(2000);
  playNextSound();
  goUp();
  rollRight();
  goLeft();
  rollLeft();
  delay(2000);
  playNextSound();
  goLeft();
  goRight();
  rollRight();
  delay(4000);
  //playNextSound();
  rollLeft();
  rollRight();
  goUp();
  rollLeft();
  delay(4000);
  playNextSound();
  goDown();
  rollLeft();
  rollRight();
  goDown();
  delay(4000);
  playNextSound();
  //goUp();
  //play WAV5 
  //goLeft();
  //goRight();
  //goDown();
  //goUp();
  //rollRight();
  //rollLeft();
  for(int i=centerForPitchInt;i<centerForPitchInt+48;i++)
  {
    myServoPitch.write(i);
    delay(85);
  }
  motorDown();
 // myServoPitch.write(centerForPitchInt+48);
  first=1;
  
  }
}


