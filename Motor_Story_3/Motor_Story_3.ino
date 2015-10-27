#define ON 1
#define OFF 0

#include <ArduinoUnit.h>

boolean ENA = OFF;
boolean IN1 = OFF;
boolean IN2 = OFF;


boolean IN3 = OFF;
boolean IN4 = OFF;


int gr = 10;
int yr = 11;
int rr = 12;

int gl = 9;
int yl = 7;
int rl = 8;


void setMotors(boolean onoff)
{
  ENA = onoff;
  if (ENA == ON) 
  {
    digitalWrite(gr, HIGH);
    digitalWrite(gl, HIGH);
  } 
  else 
  {
    digitalWrite(gr, LOW);
    digitalWrite(gl, LOW);
  }
  
}
void setForward()
{
  IN1 = ON;
  IN2 = OFF;
  IN3 = ON;
  IN4 = OFF;
   if (ENA == ON) 
   {
     digitalWrite(yr, HIGH);
     digitalWrite(yl, HIGH);
   
     digitalWrite(rr, LOW);
     digitalWrite(rl, LOW);
   }
}
void setReverse()
{
  IN1 = OFF;
  IN2 = ON;
  IN3 = OFF;
  IN4 = ON;
   if (ENA == ON) 
   {
     digitalWrite(rr, HIGH);
     digitalWrite(rl, HIGH);
   
     digitalWrite(yr, LOW);
     digitalWrite(yl, LOW);
   }
}
void setStop()
{
  IN1 = ON;
  IN2 = ON;
  IN3 = ON;
  IN4 = ON;
   if (ENA == ON) 
   {
     digitalWrite(rr, HIGH);
     digitalWrite(rl, HIGH);
   
     digitalWrite(yr, HIGH);
     digitalWrite(yl, HIGH);
   }
}


void setup() {   Serial.begin (115200);             
  pinMode(gr, OUTPUT); 
 pinMode(yr, OUTPUT);
 pinMode(rr, OUTPUT);

 pinMode(gl, OUTPUT);
 pinMode(yl, OUTPUT);
 pinMode(rl, OUTPUT);
}


void loop() { Test::run();


 setMotors(ON);
 setForward();
 delay(10000);
 setStop (); 
 delay(1000);
 setReverse ();
 delay (1000); 
}  


test(boolean_on_off_system) {
 assertTrue (ON == 1);
  assertTrue (OFF == 0);
}
