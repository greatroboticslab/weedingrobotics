//See BareMinimum example for a list of library functions
 
//Includes required to use Roboclaw library
#include <SoftwareSerial.h>
#include "RoboClaw.h"

//See limitations of Arduino SoftwareSerial
SoftwareSerial serial(10,11);	// rx, tx
RoboClaw roboclaw(&serial,10000);


#define Front_Left  0x80 // Address for the Front Left motor
#define Front_Right 0x81 // Address for the Front Right motor
#define Back_Left   0x82 // Address for the Back Left motor
#define Back_Right  0x83 // Address for the Back Right motor
#define Middle_Left 0x85 // Address for the Middle Left motor
#define Middle_Right 0x84 // Address for the Middle Right motor

int ch2 = 2; int ch3 = 3; int ch5 = 4;



// the speed of the motor can be adjusted from here. The speed goes form 0 to 127.
//int speed = 60; 



void setup() {
  //Open roboclaw serial ports

  roboclaw.begin(38400); // This is the baudrand that was set in the basicmicro motion studio. Make sure that all motor drivers have the same baudrand.
  Serial.begin(9600);
  
  //hardcoded path

  

}

void loop() {

  ch2 = pulseIn(2, HIGH);
  ch3 = pulseIn(3, HIGH);
  ch5 = pulseIn(4, HIGH);

  // This is for reading the values from the channels of the remote controller
  //Serial.print("ch2 = "); Serial.print(ch2);   Serial.print("|  "); 
  //Serial.print("ch3 = "); Serial.print(ch3); Serial.print("|"); 
  //Serial.print("ch5 = "); Serial.print(ch5); Serial.println("|"); 
  
if ( ch5 > 1200 )
{
  if ( (ch2 > 1600) ) // left forward
  {
    double speed1 = abs(ch2-1600);
    if (speed1 > 389)
    {
      speed1 = 400;
    }
    double speed2 = speed1 / 400;
    double speed = speed2 * 127;
    roboclaw.ForwardM1(Front_Left,  speed);
    roboclaw.ForwardM1(Back_Left,   speed);   
    roboclaw.ForwardM1(Middle_Left, speed);
    Serial.print("left f: "); Serial.print(speed);
  } 

  else if ( (ch2 < 1400) ) //left backward
  {
    double speed1 = 1400-ch2;
    if (speed1 > 400)
    {
      speed1 = 400;
    }
    double speed2 = speed1 / 400;
    double speed = speed2 * 127;
    roboclaw.BackwardM1(Front_Left,  speed);
    roboclaw.BackwardM1(Back_Left,   speed);  
    roboclaw.BackwardM1(Middle_Left, speed);
    Serial.print("left b: "); Serial.print(speed);
  }
  else // Stop if the remote controller in the resting position
  {
    roboclaw.ForwardBackwardM1(Front_Left,  64);
    roboclaw.ForwardBackwardM1(Back_Left,   64);
    roboclaw.ForwardBackwardM1(Middle_Left, 64);
    Serial.print("left stop");
  }

  if ( (ch3 > 1600) ) // right forward
  {
    double speed1 = abs(ch3-1600);
    if (speed1 > 389)
    {
      speed1 = 400;
    }
    double speed2 = speed1 / 400;
    double speed = speed2 * 127;
    Serial.print("  right f: "); Serial.println(speed);
    roboclaw.BackwardM1(Front_Right, speed);
    roboclaw.BackwardM1(Back_Right,  speed);
    roboclaw.BackwardM1(Middle_Right,speed);
  }

  else if ( (ch3 < 1400) ) //right backward
  {
    double speed1 = 1400-ch3;
    if (speed1 > 400)
    {
      speed1 = 400;
    }
    double speed2 = speed1 / 400;
    double speed = speed2 * 127;
    roboclaw.ForwardM1(Front_Right, speed);
    roboclaw.ForwardM1(Back_Right,  speed);
    roboclaw.ForwardM1(Middle_Right,speed);
    Serial.print("  right b: "); Serial.println(speed);
  } 

  else // Stop if the remote controller in the resting position
  {
    roboclaw.ForwardBackwardM1(Front_Right, 64);
    roboclaw.ForwardBackwardM1(Back_Right,  64);
    roboclaw.ForwardBackwardM1(Middle_Right,64);
    Serial.println("  right stop");
  }   

}
else // Stop if the remote controller in the resting position
{
  roboclaw.ForwardBackwardM1(Front_Left,  64);
  roboclaw.ForwardBackwardM1(Front_Right, 64);
  roboclaw.ForwardBackwardM1(Back_Left,   64);
  roboclaw.ForwardBackwardM1(Back_Right,  64);
  roboclaw.ForwardBackwardM1(Middle_Left, 64);
  roboclaw.ForwardBackwardM1(Middle_Right,64);

} 

}
