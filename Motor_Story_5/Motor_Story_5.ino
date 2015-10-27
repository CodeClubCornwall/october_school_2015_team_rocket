#define ON 1
#define OFF 0

boolean ENAon = OFF;
boolean ENBon = OFF;

boolean IN1 = OFF;
boolean IN2 = OFF;


boolean IN3 = OFF;
boolean IN4 = OFF;


int enb = 10;
int in4 = 11;
int in3 = 12;

int ena = 9;
int in2 = 7;
int in1 = 8;


void setMotors(boolean onoff)
{
  ENAon = onoff;
  if (ENAon == ON) 
  {
    digitalWrite(ena, HIGH);
    digitalWrite(enb, HIGH);
  } 
  else 
  {
    digitalWrite(ena, LOW);
    digitalWrite(enb, LOW);
  }
  
}

void setForward()
{
  IN1 = ON;
  IN2 = OFF;
  IN3 = ON;
  IN4 = OFF;
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
  IN1 = OFF;
  IN2 = ON;
  IN3 = OFF;
  IN4 = ON;
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
  IN1 = ON;
  IN2 = ON;
  IN3 = ON;
  IN4 = ON;
   if (ENAon == ON) 
   {
     digitalWrite(in2, HIGH);
     digitalWrite(in4, HIGH);
   
     digitalWrite(in1, HIGH);
     digitalWrite(in3, HIGH);
   }
}

void setup() {   Serial.begin (115200);             
  pinMode(enb, OUTPUT); 
 pinMode(in3, OUTPUT);
 pinMode(in4, OUTPUT);

 pinMode(ena, OUTPUT);
 pinMode(in1, OUTPUT);
 pinMode(in2, OUTPUT);
}


void loop() { Test::run();


 setMotors(ON);
 setForward();
 delay(1000);
 setStop (); 
 delay(1000);
 setReverse ();
 delay (1000); 
}  


test(boolean_on_off_system) {
 assertTrue (ON == 1);
  assertTrue (OFF == 0);
}
