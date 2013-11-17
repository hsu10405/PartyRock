#include <AltSoftSerial.h>
// This is suppose to be a better implementation of the builtin softwareSerial library.
// By default, AltSoftSerial uses pin 9 to transmit and pin 8 to receive.

AltSoftSerial altSerial;
#define testPin 5
int data = 0;

void setup(){
  pinMode(testPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("AltSoftSerial Test Begin");
  altSerial.begin(9600);
}

void loop(){
  if(altSerial.available()){
    data = altSerial.read();
    Serial.print("Received data is");
    Serial.println(data);
    analogWrite(testPin,data); // If everything is correct, the output should be what the input is.
  }
}
