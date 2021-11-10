#include <Servo.h>

Servo myservo1;  // create servo object to control a servo
Servo myservo2;
int pos1 = 0;    // variable to store the servo position
int pos2 = 0;
uint16_t LOOP_INTERVAL = 300;
int analogInPin = A0;    // select the input pin for the distance sensor
int sensorValue = 0;  // variable to store the value coming from the sensor

void setup() {
  Serial.begin(9600);
  myservo1.attach(9);
  myservo2.attach(8);
}
void loop() {
     uint16_t x, y, z, a, b, res, dist;
  // put your main code here, to run repeatedly:
  for ( int i = 50; i <= 90; i=i+2) {
         myservo2.write(i);
         delay(LOOP_INTERVAL);
   // statement block
  for ( int j = 90; j <= 130; j=j+1) {
     myservo1.write(j);
      x = map(analogRead(analogInPin), 0, 1023, 0, 255);;
      y = map(analogRead(analogInPin), 0, 1023, 0, 255);;
      z = map(analogRead(analogInPin), 0, 1023, 0, 255);;
      a = map(analogRead(analogInPin), 0, 1023, 0, 255);;
      b = map(analogRead(analogInPin), 0, 1023, 0, 255);;
      res = min(min(min(min(x, y), z), a), b);
      Serial.print(res);    Serial.print(",");
      Serial.print((i-70)*-1);    Serial.print(",");
      Serial.println(-1*(j-110));   
      delay(LOOP_INTERVAL);
   }
}
exit(0);
}
