#include <SoftwareSerial.h>

SoftwareSerial BT(10,11);   // HC-05 Bluetooth

// Motor pins (L298N)
int in1 = 2;
int in2 = 3;
int in3 = 4;
int in4 = 5;

int ena = 6;   // Motor A speed
int enb = 9;   // Motor B speed

char cmd;

void setup()
{
  Serial.begin(9600);
  BT.begin(9600);

  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);

  pinMode(ena,OUTPUT);
  pinMode(enb,OUTPUT);

  // Motor speed
  analogWrite(ena,200);
  analogWrite(enb,200);
}

// -------- Movement Functions --------

void forward()
{
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);

  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
}

void back()
{
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);

  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
}

void left()
{
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);

  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
}

void right()
{
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);

  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
}

void stopbot()
{
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);

  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
}

// -------- Main Loop --------

void loop()
{
  if(BT.available())
  {
    cmd = BT.read();

    Serial.println(cmd);   // Debug (optional)

    if(cmd == 'F')
    {
      forward();
    }

    else if(cmd == 'B')
    {
      back();
    }

    else if(cmd == 'L')
    {
      left();
    }

    else if(cmd == 'R')
    {
      right();
    }

    else if(cmd == 'S')
    {
      stopbot();
    }
  }
}
