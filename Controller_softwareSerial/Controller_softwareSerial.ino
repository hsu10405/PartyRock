// This is DMXcontroller that utilizes the DMX library and software serial protocol
// The idea is to have this as a intermediate hub between the computer and the DMX slaves
// The software serial handles computer inputs and the DMX controller serial handles DMX signals

// The protocol should be something like this
// 1. First batch of signal specifies how many channels we are sending data to
// 2. Second batch of data specifies the data to that channel
// 3. Since we are specifying the number of channels, if we are not sending anything to a particlar channel
//    we change it to idle.
//


#include <DMXSerial.h>
#include <SoftwareSerial.h>
#define rxPin 3
#define txPin 4
#define testPin 5
#define arrSize 10

//Initialize software serial port
SoftwareSerial computerSerial = SoftwareSerial(rxPin, txPin);

void setup(){
  // initialize the DMX controller
  DMXSerial.init(DMXController);
  
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
  pinMode(testPin, OUTPUT);
  
  // Setting the transmission frequency
  computerSerial.begin(250000);

  
}

void loop(){
  // initialize used variables
  int channel;
  int index;
  int data[arrSize] = { 0 }; //declare each channel

  if(computerSerial.available() > 0){
    
    // Get channel
    channel = index = computerSerial.read();
    
    // Get data from PC
    for(index; index >= 0; index--){
      
      data[arrSize-index] = computerSerial.read(); // putting data to each channel
      
    }
  }
  // Send it to DMX slaves
    while(index >= 0){
    DMXSerial.write((arrSize-index), data[arrSize-index]); // Push data to DMX slaves
    analogWrite(testPin, data[arrSize-index]); // Make sure we are sending out data
    index--;
    }
  
}
