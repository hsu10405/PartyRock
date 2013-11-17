#include <SoftwareSerial.h>

#define rxPin 8
#define txPin 9
#define testPin 5

int recvData = 0;

SoftwareSerial recvSerial = SoftwareSerial(rxPin, txPin);

void setup(){
 Serial.begin(9600);
 pinMode(rxPin, INPUT);
 pinMode(txPin, OUTPUT);
 
 recvSerial.begin(9600);
  
}

void loop(){
 if(recvSerial.available()){
   recvData = recvSerial.parseInt(); // Store transmitted data
 }
 analogWrite(testPin, recvData);
 if(recvData){
  recvData = 0; // If we receive data, we reset data
 }
 else{
   digitalWrite(testPin, HIGH); // if no data received, flash the the LED
   delay(100);
   digitalWrite(testPin, LOW);
 }
 Serial.println(recvData);
}
