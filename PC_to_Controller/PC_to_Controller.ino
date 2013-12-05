// This is the Arduino that handles the communication between the PC and the DMX controller.
// The way data is transmitted is:
// 1. First specify a channel
// 2. The data for that channel. (Data is HIGH by DMX speciification)
// This program uses AltSoftSerial library to establish a new serial line.
// By default, AltSoftSerial uses pin 9 to transmit and pin 8 to receive.
#include <AltSoftSerial.h>

AltSoftSerial altSerial;
#define testPin 5
const int HI = 255;

void setup(){
  Serial.begin(9600); // initialize the serial monitor
  Serial.setTimeout(100000); // parseInt has a default time out of 1 sec, this extends the time out.
  Serial.println("Initializing AltSoftSerial port");
  altSerial.begin(9600);
  Serial.println("Everything is set.");
}

void loop(){
  // First specify a channel
  // Then specify data for that channel
  
  // Setting up default values
  int channel = 0;
  int data = HI;
  
  if(Serial.available() > 0){
    channel = Serial.parseInt(); // Make sure to use newline in the serial monitor
    data = Serial.parseInt(); // Get data

    Serial.println(channel);
    Serial.println(data);
  }
  // Sending data and checking boundry
  if(channel > 0){
    altSerial.write(channel);
    if((data < HI) && (data >= 0)){
      altSerial.write(data);
    }
    else{
      altSerial.write(HI);
    }
  }
  else{
    Serial.println("Invalid Channel");
  }
  Serial.println("done");
}
