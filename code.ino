#include <Servo.h>

Servo servo1;  // create servo object to control a servo

int pos1;      // angle of servo 1 & servo2


String inString = ""; 
void setup()
{
  Serial.begin(9600);
  
  servo1.attach(9);  // attaches the servo on pin 9 to the servo object
  
  pos1 = 90;
  servo1.write(pos1);
  
  delay(15);
              
}

void loop()
{
     // Scene 1:
  int pos = readSerialValue();

    if( pos != -1){

       if( pos > 180) pos = 180;
       else if( pos < 0) pos = 0;

         servo1.attach(9);  // attaches the servo on pin 9 to the servo object
         servo1.write(pos);
         
         delay(1000);
         
         servo1.detach(); // Release servo
                         
    }
    
}
int readSerialValue()
{
     int v= -1;
  // Read serial input:
  while (Serial.available() > 0) {
    int inChar = Serial.read();
    if (isDigit(inChar)) {
      // convert the incoming byte to a char
      // and add it to the string:
      inString += (char)inChar;
    }
    // if you get a newline, print the string,
    // then the string's value:
    if (inChar == '\n') {
      Serial.print("String: ");
      Serial.println(inString);
      v = inString.toInt();
      Serial.print("Value:");
      Serial.println(v);
      
           
      // clear the string for new input:
      inString = "";
    }
  }
   return v;
}
