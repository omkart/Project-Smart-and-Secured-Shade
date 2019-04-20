#include <Servo.h>
#include<SoftwareSerial.h>


SoftwareSerial bluetooth(6,7);    //tx,rx
unsigned int value2;
unsigned int value1;
unsigned int value;


unsigned int mode;
unsigned int stats;


Servo myservo; 

int sensorPin1 = A1;    // select the input pin for the potentiometer
int sensorPin2 = A2;
int ledPin = 13;      // select the pin for the LED
int sensorValue1 = 0;  // variable to store the value coming from the sensor
int sensorValue2 = 0; 


boolean ldr1;
boolean ldr2;

boolean lightPresent;

void setup() {

    pinMode(ledPin, OUTPUT);

    myservo.attach(9); 
    Serial.begin(9600);
    bluetooth.begin(9600);

}

void loop() {

  mystepper.setDirection(1);        //change this to 1 to make rotation in other direction    
  mystepper.setSpeed(120);        //speed in RPM : Keep the limits between 50 RPM and 150 RPM to avoid heating at low speed and slipping at high speed

  sensorValue1 = analogRead(sensorPin1);  
  sensorValue2 = analogRead(sensorPin2);
  // turn the ledPin on
 
  // stop the program for <sensorValue> milliseconds:
  delay(1000);
  // turn the ledPin off:
  Serial.println(sensorValue);

  if(sensorValue1<500)
  {
    ldr1 =true;
    //light present
  }
  else
  {
    ldr1 =false;
    //dark present
  }

   if(sensorValue2<500)
  {
    ldr2 =true;
    //light present
  }
  else
  {
    ldr2 =false;
    //dark present
  }

  if(ldr1 ==true && ldr2 ==true)
  {
    //close the panels
    run_stepper_in_one_direction();

    
  }

  else if(ldr1 ==true && ldr2 ==false)
  {
    //close the panels
    run_stepper_in_one_direction();

    
  }
   else if(ldr1 ==false && ldr2 ==true)
  {
    //open the panels
    run_stepper_in_other_direction();

    
  }
  else if(ldr1 ==false && ldr2 ==false)
  {
    //close the panels
    run_stepper_in_one_direction();

    
  }

}


void run_stepper_in_one_direction()
{
  myservo.write(90);    
}



void run_stepper_in_other_direction()
{
    myservo.write(0);    
}

