
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
const int centerForPitchInt=53;//centers the pitch in the begining
const int centerForYawInt=60;//centers the yaw in the begining
const int minElevatorValue=40;//brings it towards the front of the plane 
const int maxElevatorValue=64;//brings it away from thefront of the plane
const int centerRudderValue=65;
const int minRudderValue=50;//brings it towards the front of the plane 
const int maxRudderValue=78;//brings it away f the front of the plane 
const int centerElevatorValue=45;
const int centerAileronValue=110;
//Take off(level out),Yaw Left Rudder comes towards during it going left,Yaw Left Rudder comes towards during it going right Elvator up, Pitch up,Elvator back to normal state, 
//Pitch to normal,Yaw Left Rudder comes towards during it going left,   
const int backToCenter=1;
const int leaveItThere=0;
const int backToLast=-1;
void goRight(int j)
{
    if(j!=backToLast)
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
    }
    else
    {
      j=backToCenter;
    }
   if(j==backToCenter)
   {
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
}
void goLeft(int j)
{
      if(j!=backToLast)
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
      }
      else
      {
        j=backToCenter;
      }
       if(j==backToCenter)
       {
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
  }
void goUp(int j)
{
   if(j!=backToLast)
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
   }
   else
   {
     j=backToCenter;
   }
     if(j==backToCenter)
     {
        for(int i=maxElevatorValue;i>centerElevatorValue;i--)
        {
          myServoElevator.write(i);
          delay(45);
        }
        for(int i=centerForPitchInt-24;i<=centerForPitchInt;i++)
        {
          myServoPitch.write(i);
          delay(45);
        }
     }
}
void goDown(int j)
{
  if(j!=backToLast)
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
  }
  else
  {
    j=backToCenter;
  }
  if(j==backToCenter)
    {
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
}
  
void setup() 
{ 
  myServoYaw.attach(7);  // attaches the servo on pin 9 to the servo object
  myServoPitch.attach(6);
  myServoElevator.attach(2);
  myServoRudder.attach(3);
  myServoAileron.attach(4);
  myServoRoll.attach(5);
  myServoRoll.write(50);
  myServoPitch.write(centerForPitchInt);//starting up and down axis
  myServoYaw.write(centerForYawInt);//starting left and right axis
  myServoElevator.write(centerElevatorValue);
  myServoAileron.write(centerAileronValue);
  myServoRudder.write(65);
} 
//Take off(level out),Yaw Right Rudder goes away during it going right,Yaw Left Rudder comes towards during it going right Elvator up, Pitch up,Elvator back to normal state, 
//Pitch to normal,Yaw Left Rudder comes towards during it going left, 

 //Yaw servo ranges are 20 to 99
 //bottom servo ranges are 34 to 99 
void loop() 
{
  //backToCenter
  //leaveItThere
  goRight(backToCenter);
  goLeft(backToCenter);
  goUp(leaveItThere);
  goRight(backToCenter);
  //roll
  //roll back 
  goUp(backToLast);
  goLeft(leaveItThere);
  
  for(int i=80;i<100;i++)
  {
    myServoRoll.write(i);
    delay(500);
  }
  
  
  
  
  
}


