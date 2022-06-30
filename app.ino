#include <Servo.h>
#include <SoftwareSerial.h>
SoftwareSerial BT(10,11);
Servo myservo1;  // create servo object to control a servo
Servo myservo2;
Servo myservo3;
Servo myservo4;

int pos1=90, pos2=0, pos3=0, pos4=90;
void setup() 
{
myservo1.write(pos1);  
delay(1000);
myservo2.write(pos2);
myservo3.write(pos3);
myservo4.write(pos4);
delay(1500);
BT.begin(9600);
Serial.begin(9600); //  set the baud rate to 9600
myservo1.attach(3); // set the control pin of servo 1 to D3  dizuo-servo1-3
myservo2.attach(5); // set the control pin of servo 2 to D5  arm-servo2-5
myservo3.attach(6); //set the control pin of servo 3 to D6   lower arm-servo-6
myservo4.attach(9);

}

void loop() 
{
if(BT.available()) //read while data is present
{
unsigned int servopos = BT.read();
unsigned int servopos1 = BT.read();
unsigned int realservo = (servopos1*256)+servopos;
Serial.println(realservo); 

if (realservo >= 1000 && realservo <1180){
int servo1 = realservo;
servo1 = map(servo1, 1000,1180,0,180);
myservo1.write(servo1);
Serial.println("servo 1 ON");
delay(10);
}

if (realservo >= 2000 && realservo <2180){
int servo2 = realservo;
servo2 = map(servo2, 2000,2180,0,180);
myservo2.write(servo2);
Serial.println("servo 2 ON");
delay(10);
}

if (realservo >= 3000 && realservo<3180){
int servo3 = realservo;
servo3 = map(servo3, 3000,3180,0,180);
myservo3.write(servo3);
Serial.println("servo 3 ON");
delay(10);
}

if (realservo >= 4000 && realservo<4180){
int servo4 = realservo;
servo4 = map(servo4, 4000,4180,0,180);
myservo4.write(servo4);
Serial.println("servo 4 ON");
delay(10);
}
else{
Serial.println(realservo+2);
}


//pos1 = value;
//myservo1.write(pos1);
//value2 = Serial.read();
//pos2 = value2;
//myservo2.write(pos2);
//value3 = Serial.read();
//pos3 = value3;
//myservo3.write(pos3);
//value4 = Serial.read();
//pos4 = value4;
//myservo4.write(pos4);
//delay(15); }
//Serial.println(value);
//Serial.println(value2);
//Serial.println(value3);
//Serial.println(value4);
}
}
