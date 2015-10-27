
#define ON 1
#define OFF 0

boolean ENAon = OFF;
boolean ENBon = OFF;

int pulsesLeft = 0;
int pulsesRight = 0;

int b1 = 2;
int b2 = 3;

int enb = 10;
int in4 = 11;
int in3 = 12;

int ena = 9;
int in2 = 7;
int in1 = 8;


void setMotors(byte powerLeft, byte powerRight)
{
  ENAon = (powerLeft > 0);
  ENBon = (powerRight > 0);
  analogWrite(ena, powerLeft);
  analogWrite(enb, powerRight);
 
}

void setForward()
{
  if (ENAon == ON) 
   {
     digitalWrite(in1, HIGH);
     digitalWrite(in3, HIGH);
   
     digitalWrite(in2, LOW);
     digitalWrite(in4, LOW);
   }
}

void setReverse()
{
   if (ENAon == ON) 
   {
     digitalWrite(in2, HIGH);
     digitalWrite(in4, HIGH);
   
     digitalWrite(in1, LOW);
     digitalWrite(in3, LOW);
   }
}

void setStop()
{
   if (ENAon == ON) 
   {
     digitalWrite(in2, HIGH);
     digitalWrite(in4, HIGH);
   
     digitalWrite(in1, HIGH);
     digitalWrite(in3, HIGH);
   }
}

void countPulsesLeft()
{
 pulsesLeft = pulsesLeft + 1;
}

void countPulsesRight()
{
 pulsesRight = pulsesRight + 1;
}

void setup()
{              
 pinMode(enb, OUTPUT); 
 pinMode(in3, OUTPUT);
 pinMode(in4, OUTPUT);

 pinMode(ena, OUTPUT);
 pinMode(in1, OUTPUT);
 pinMode(in2, OUTPUT);
 
 attachInterrupt(1,countPulsesLeft,RISING);
 attachInterrupt(0,countPulsesRight,RISING);
 digitalWrite (b1, HIGH);
 digitalWrite (b2, HIGH);
 setMotors(175, 200);
 
}

boolean stopStart = ON; 

void loop() 
{ 

 if (stopStart == ON) 
 {
   setForward();
   
   if (pulsesLeft > 1074 && pulsesRight > 1074)
     {
     setStop();
     setMotors(OFF, OFF);
     stopStart = OFF;
     } 
     
    else
      {
      setForward();
      }
  }
} 

