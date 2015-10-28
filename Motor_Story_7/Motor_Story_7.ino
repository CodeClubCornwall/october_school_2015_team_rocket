// (/ 0-0 )/ \( *-* \)
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

void turn(int turnAmount)
{
  pulsesLeft = 0;
  setMotors(255, 0);
  if (ENAon == ON) 
  {
    digitalWrite(in1, HIGH);
       
    digitalWrite(in3, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in4, HIGH);
   }
    
  while (true)
  {
    Serial.println("In the loop");
    delay(20);
    if (pulsesLeft >= turnAmount) 
    {
      setStop();
      Serial.println("We should stop"); 
      delay(20);
      setMotors(175, 200);
      return;
    }
    
  }
}

void setMotors(byte powerLeft, byte powerRight)
{
  ENAon = (powerLeft > 0);
  ENBon = (powerRight > 0);
  analogWrite(ena, powerLeft);
  analogWrite(enb, powerRight);
 
}

void setForwards(int pulses)
{
  pulsesRight = 0;
  pulsesLeft  = 0;
       
   while (pulsesLeft < pulses && pulsesRight < pulses)
   {
     if (ENAon == ON) 
     {
       digitalWrite(in1, HIGH);
       digitalWrite(in3, HIGH);
     
       digitalWrite(in2, LOW);
       digitalWrite(in4, LOW);
     }
    
   } 
   setStop();
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
 Serial.println("I have pulses");
 delay(20);
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
 
 Serial.begin(115200);
 
 attachInterrupt(0,countPulsesLeft,RISING);
 attachInterrupt(1,countPulsesRight,RISING);
 
 digitalWrite (b1, HIGH);
 digitalWrite (b2, HIGH);
 
 setMotors(175, 200); 
}

boolean stopStart = ON;
int pulses = 138;

void loop() 
{ 
  if (stopStart == ON) 
 {
     setForwards(267);
     for (int counter = 0; counter < 3; counter ++)
     {
        delay(2000);
        turn(pulses);
        delay(2000);
        setForwards(267);

     }
     stopStart = OFF;
     setMotors(0, 0);
  }
} 

