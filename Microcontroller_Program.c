#include <Servo.h> 

Servo myservo;  // create servo object to control a servo 

int val=0;    // variable to read the value from the analog pin 

int val1=0;

void setup() 

{ 
 
 myservo.attach(10);  // attaches the servo on pin 10 to the servo object 

Serial.begin(9600);

} 
 

void loop()
 
{ 

for(val=0; val<10; val=val++)

{ 
val1=val*18;
  
myservo.write(val1);                  // sets the servo position according to the scaled value 
  
Serial.print(val);
  
delay(3000);                           // waits for the servo to get there 


}

} 
