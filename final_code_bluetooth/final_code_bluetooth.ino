#include<SoftwareSerial.h>
#include <Servo.h>
SoftwareSerial bluetooth(7,8);    //tx,rx
unsigned int value2;
unsigned int value1;
unsigned int value;


Servo myservo; 
unsigned int mode;
unsigned int stats;

void setup() {
   Serial.begin(9600);
 bluetooth.begin(9600);
        //bender
 

}

void loop() {
  // put your main code here, to run repeatedly:
  protocol();

}


void protocol()
{
  while(1)
  {
    if(bluetooth.available()>=2)
    {
      while(bluetooth.available()>=2)
      {
       

       value1=bluetooth.read();
       value2=bluetooth.read();
      stats = ((value2 * 256) + value1 );
       
        Serial.println(stats);
          if(stats==6000)
          {

            Serial.println("ON mode");
             myservo.write(90); 
            
          }

          else if(stats==6100)
          {
            Serial.println("OFF Mode");
             myservo.write(0); 
            
          }

           }
      }
    }
}
