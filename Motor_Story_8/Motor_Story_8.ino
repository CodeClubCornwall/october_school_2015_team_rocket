// (/ 0-0 )/ \( *-* \)
#define ON 1
#define OFF 0

byte robot = 175;

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

void debug_clicks()
{
  Serial.print(pulsesLeft);
  Serial.print(", ");
  Serial.println(pulsesRight);
  delay(10);
}

void turnRight(int turnAmount, int reverseAmount)
{
  pulsesLeft = 0;
  pulsesRight = 0;
  
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
       
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH); 
   
  while (pulsesLeft < turnAmount && pulsesRight < reverseAmount)
   {
    delay(20);
   
    if (pulsesLeft >= turnAmount) 
    {
      
      digitalWrite(in1, HIGH);
      digitalWrite(in2, HIGH);
      
    }
    
    if (pulsesRight >= reverseAmount) 
    {
      digitalWrite(in3, HIGH);
      digitalWrite(in4, HIGH);
     
    }
    
  }
  
  setStop();
}

void turnLeft(int turnAmount, int reverseAmount)
{
  pulsesLeft = 0;
  pulsesRight = 0;
  
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
       
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
 

  while (pulsesLeft < reverseAmount && pulsesRight < turnAmount)
   {
   delay(20);
    if (pulsesLeft >= reverseAmount) 
    {
      
      digitalWrite(in1, HIGH);
      digitalWrite(in2, HIGH);
      
    }
    
    if (pulsesRight >= turnAmount) 
    {
      digitalWrite(in3, HIGH);
      digitalWrite(in4, HIGH);
     
    }
    
  }
  
  setStop();
}
void setMotors(byte powerLeft, byte powerRight)
{
  analogWrite(ena, powerLeft);
  analogWrite(enb, powerRight);
}

void setForwards(int pulses)
{
  pulsesRight = 0;
  pulsesLeft  = 0;
       
   while (pulsesLeft < pulses && pulsesRight < pulses)
   {     
     digitalWrite(in1, HIGH);
     digitalWrite(in3, HIGH);
     
     digitalWrite(in2, LOW);
     digitalWrite(in4, LOW);
    
   } 
   setStop();
}

void setReverse()
{ 
  digitalWrite(in2, HIGH);
  digitalWrite(in4, HIGH);
   
  digitalWrite(in1, LOW);
  digitalWrite(in3, LOW);
 
}

void setStop()
{ 
 digitalWrite(in2, HIGH);
 digitalWrite(in4, HIGH);
   
 digitalWrite(in1, HIGH);
 digitalWrite(in3, HIGH);
 
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
 
 Serial.begin(115200);
 
 attachInterrupt(0,countPulsesLeft,RISING);
 attachInterrupt(1,countPulsesRight,RISING);
 
 digitalWrite (b1, HIGH);
 digitalWrite (b2, HIGH);
 
 setMotors(robot, 200); 
}

// fP = Forwards Pulses
const int fP = 150;
boolean stopStart = ON;

const int turnPulsesLeft = 64;
const int reverseTurnPulsesRight = 64;

const int turnPulsesRight = 70;
const int reverseTurnPulsesLeft = 70;

void loop() 
{ 
  if (stopStart == ON) 
 {
     setForwards(fP);
     
     Serial.println("forwards...");
     delay(2000); 

     turnRight(turnPulsesLeft, reverseTurnPulsesRight);

     Serial.println("right...");
     delay(2000);
     
     setForwards(fP);
     setForwards(fP);
     
     Serial.println("forwards...");
     delay(2000);

     turnLeft(turnPulsesRight, reverseTurnPulsesLeft);

     Serial.println("left...");
     delay(2000);
     
     setForwards(fP);
     
     Serial.println("forwards...");
     delay(2000);
     
     turnLeft(turnPulsesRight, reverseTurnPulsesLeft);
     
     Serial.println("left...");
     delay(2000);
     
     setForwards(fP);
     
     Serial.println("forwards...");
     delay(2000);
     
     turnLeft(turnPulsesRight, reverseTurnPulsesLeft);
     
     Serial.println("left...");
     delay(2000);
     
     setForwards(fP);
     setForwards(fP);
     
     Serial.println("forwards...");
     delay(2000);
     
     turnRight(turnPulsesLeft, reverseTurnPulsesRight);
     
     Serial.println("right...");
     delay(2000);
     
     setForwards(fP);
     
     Serial.println("forwards...");
     delay(2000);

     stopStart = OFF;
     setMotors(0, 0); 
  }
} 

