int ch1 =  10; // Reseiver Channel-3 (left knob)
int ch2 =  11; // Reseiver Channel-4 (left knob)
int ch5 =  12; // The safety switch located in the top left corner
int ch6 =  13; // For the relay to switch teh UVC ON and OFF
int Relay = 42; // The digital pin for the relay that controls the output of the UVC.

// Left Front Motor
#define LF_RPWM 50 
#define LF_LPWM 51 
#define LF_REN  48
#define LF_LEN  49

// Right Front Motor
#define RF_RPWM 6  
#define RF_LPWM 7 
#define RF_REN 53
#define RF_LEN 52

// Left Back Motor
#define LB_RPWM 32 
#define LB_LPWM 33 
#define LB_REN  28
#define LB_LEN  29

//Right Back Motor
#define RB_RPWM 2 
#define RB_LPWM 3 
#define RB_REN  4
#define RB_LEN  5

int speed = 200; // 0-255


void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

  pinMode(10, INPUT);
  pinMode(11, INPUT);
  pinMode(12, INPUT);
  pinMode(13, INPUT); 

  pinMode(42,OUTPUT);

  pinMode(LF_REN, OUTPUT);
  pinMode(LF_LEN, OUTPUT);
  pinMode(LF_RPWM, OUTPUT);
  pinMode(LF_LPWM, OUTPUT);
  digitalWrite(LF_REN,HIGH);
  digitalWrite(LF_LEN,HIGH);

  pinMode(RF_REN, OUTPUT);
  pinMode(RF_LEN, OUTPUT);
  pinMode(RF_RPWM, OUTPUT);
  pinMode(RF_LPWM, OUTPUT);
  digitalWrite(RF_REN,HIGH);
  digitalWrite(RF_LEN,HIGH);

  pinMode(LB_REN, OUTPUT);
  pinMode(LB_LEN, OUTPUT);
  pinMode(LB_RPWM, OUTPUT);
  pinMode(LB_LPWM, OUTPUT);
  digitalWrite(LB_REN,HIGH);
  digitalWrite(LB_LEN,HIGH);

  pinMode(RB_REN, OUTPUT);
  pinMode(RB_LEN, OUTPUT);
  pinMode(RB_RPWM, OUTPUT);
  pinMode(RB_LPWM, OUTPUT);
  digitalWrite(RB_REN,HIGH);
  digitalWrite(RB_LEN,HIGH);

  

}

void loop() {
  // put your main code here, to run repeatedly:

  ch1 = pulseIn(10, HIGH);
  ch2 = pulseIn(11, HIGH);
  ch5 = pulseIn(12, HIGH);
  ch6 = pulseIn(13, HIGH);  

  Serial.println(ch6);
  // Serial.println(ch4);

if ( ch5 > 1200)
{

  if ( ch6 > 1200)
  {
    digitalWrite(Relay,HIGH);
  }

  else if ( (ch1==0) && (ch2==0) ) // Transmitter not connected yet (motor should not move)
  {
    analogWrite(LF_RPWM, 0);
    analogWrite(LF_LPWM, 0);

    analogWrite(RF_RPWM, 0);
    analogWrite(RF_LPWM, 0);

    analogWrite(LB_RPWM, 0);
    analogWrite(LB_LPWM, 0);

    analogWrite(RB_RPWM, 0);
    analogWrite(RB_LPWM, 0);
    
  }
  

  else if ( (ch2 > 1550) ) // Forward
  {
    analogWrite(LF_RPWM, speed);
    analogWrite(LF_LPWM, 0);

    analogWrite(RF_RPWM, 0);
    analogWrite(RF_LPWM, speed);

    analogWrite(LB_RPWM, speed);
    analogWrite(LB_LPWM, 0);

    analogWrite(RB_RPWM, 0);
    analogWrite(RB_LPWM, speed);
    
  }

  else if (ch2 < 1350) // Backward
  {
    analogWrite(LF_RPWM, 0);
    analogWrite(LF_LPWM, speed);

    analogWrite(RF_RPWM, speed);
    analogWrite(RF_LPWM, 0);

    analogWrite(LB_RPWM, 0);
    analogWrite(LB_LPWM, speed);

    analogWrite(RB_RPWM, speed);
    analogWrite(RB_LPWM, 0);
  }

  else if (ch1 > 1550) // Right
  {
    analogWrite(LF_RPWM, speed);
    analogWrite(LF_LPWM, 0);

    analogWrite(LB_RPWM, speed);
    analogWrite(LB_LPWM, 0);

    analogWrite(RF_RPWM, speed);
    analogWrite(RF_LPWM, 0);

    analogWrite(RB_RPWM, speed);
    analogWrite(RB_LPWM, 0);

  }

  else if (ch1 < 1350) // left
  {
    analogWrite(RF_RPWM, 0);
    analogWrite(RF_LPWM, speed);

    analogWrite(RB_RPWM, 0);
    analogWrite(RB_LPWM, speed);

    analogWrite(LF_RPWM, 0);
    analogWrite(LF_LPWM, speed);

    analogWrite(LB_RPWM, 0);
    analogWrite(LB_LPWM, speed);  

  }

  else // Stop
  {
    analogWrite(LF_RPWM, 0);
    analogWrite(LF_LPWM, 0);

    analogWrite(RF_RPWM, 0);
    analogWrite(RF_LPWM, 0);

    analogWrite(LB_RPWM, 0);
    analogWrite(LB_LPWM, 0);

    analogWrite(RB_RPWM, 0);
    analogWrite(RB_LPWM, 0);

    digitalWrite(Relay,LOW);
    
  }
}

else // Stop
{
  analogWrite(LF_RPWM, 0);
  analogWrite(LF_LPWM, 0);

  analogWrite(RF_RPWM, 0);
  analogWrite(RF_LPWM, 0);

  analogWrite(LB_RPWM, 0);
  analogWrite(LB_LPWM, 0);

  analogWrite(RB_RPWM, 0);
  analogWrite(RB_LPWM, 0);

  digitalWrite(Relay,LOW);
    
}

}
