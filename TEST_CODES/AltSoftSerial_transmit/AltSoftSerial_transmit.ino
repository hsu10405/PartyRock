#include <AltSoftSerial.h>
// This is suppose to be a better implementation of the builtin softwareSerial library.
// By default, AltSoftSerial uses pin 9 to transmit and pin 8 to receive.

AltSoftSerial altSerial;
#define testPin 5
int counter = 0;
void setup(){
  pinMode(testPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("AltSoftSerial Test Begin");
  altSerial.begin(9600);
  Serial.setTimeout(100000);
}

void loop(){
  // The program affects a LED brightness. It starts at no light and gradually move to full brightness
  int data;
  
  if(Serial.available() > 0){
   data = Serial.parseInt(); 
  }
  
  /*
  counter = 0;
  while(counter < 256){
    Serial.print("Sent data is: "); // Show what's being transmitted
    Serial.println(counter);
    altSerial.write(counter);
    analogWrite(testPin, counter);
    counter++;
  }
  */
}
  


