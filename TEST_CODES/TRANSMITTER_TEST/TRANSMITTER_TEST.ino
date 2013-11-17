#include <SoftwareSerial.h>

#define rxPin 8
#define txPin 9

int transData = 0;

SoftwareSerial transSerial = SoftwareSerial(rxPin, txPin);

void setup(){
 Serial.begin(9600);
 pinMode(rxPin, INPUT);
 pinMode(txPin, OUTPUT);
 
 transSerial.begin(9600);
 
}

void loop(){
  // Get data from serial
  if(Serial.available()){
   transData = Serial.parseInt(); // read the INT value of the serial input
   Serial.print("Data Get: ");
   Serial.println(transData);
  }
  // Send Data via SoftwareSerial
  if(transData){
    transSerial.write(transData);
    transData = 0; // reset data
  }
}
