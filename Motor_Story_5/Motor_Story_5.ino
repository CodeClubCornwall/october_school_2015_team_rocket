
#define ON 1
#define OFF 0

boolean ENAon = OFF;
boolean ENBon = OFF;

int pulses = 0;

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

void countPulses()
{
 pulses = pulses + 1;
}


void setup() 
{              
 pinMode(enb, OUTPUT); 
 pinMode(in3, OUTPUT);
 pinMode(in4, OUTPUT);

 pinMode(ena, OUTPUT);
 pinMode(in1, OUTPUT);
 pinMode(in2, OUTPUT);
 
 attachInterrupt(1,countPulses,RISING);
 attachInterrupt(0,countPulses,RISING);
 digitalWrite (b1, HIGH);
 digitalWrite (b2, HIGH);
}

boolean stopStart = ON; 

void loop() 
{ 
 if (stopStart == ON) 
 {
   setMotors(ON);
   setForward(255, 164);
   delay(10000);
   setStop();
   delay(1000);
   setMotors(OFF);
   stopStart = OFF;
 } 
}  

