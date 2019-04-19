
int sensorPin = A1;    // select the input pin for the potentiometer
int ledPin = 13;      // select the pin for the LED
int sensorValue = 0;  // variable to store the value coming from the sensor

void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);
  // turn the ledPin on
 
  // stop the program for <sensorValue> milliseconds:
  delay(1000);
  // turn the ledPin off:
  Serial.println(sensorValue);
  
  // stop the program for for <sensorValue> milliseconds:

}
