// This is DMXcontroller that utilizes the DMX library and software serial protocol
// The idea is to have this as a intermediate hub between the computer and the DMX slaves
// The software serial handles computer inputs and the DMX controller serial handles DMX signals

// The protocol should be something like this
// 1. First batch of signal specifies how many channels we are sending data to
// 2. Second batch of data specifies the data to that channel
// 3. Since we are specifying the number of channels, if we are not sending anything to a particlar channel
//    we change it to idle.
//
// How to use this.
// We send in signal using SoftwareSerial's serial monitor

// Update: the AltSoftSerial turns out to be a better software serial library.

#include <DMXSerial.h>
//#include <SoftwareSerial.h>
#include <AltSoftSerial.h>

//#define rxPin 8
//#define txPin 9
#define testPin 5
#define arrSize 10

AltSoftSerial altSerial;

  // initialize used variables
  int channel = 0;
  int index = 0;
  int data[arrSize] = { 0 }; //declare each channel

// Initialize software serial port
// SoftwareSerial dmxSerial = SoftwareSerial(rxPin, txPin);

void setup(){
  // initialize the DMX controller
  DMXSerial.init(DMXController);
  
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
  pinMode(testPin, OUTPUT);
  
  // Setting the transmission rate of SoftwareSerial
  altSerial.begin(9600);
  // dmxSerial.setTimeout(100000);
  // dmxSerial.flush();

  
}

void loop(){
  // Send data only when I receive data
  //digitalWrite(testPin, HIGH);
  if(altSerial.available() > 0){
    
    // Get channel
    channel = index = altSerial.parseInt();
    
    // Show that I got input from PC_to Controller Arduino
    //digitalWrite(testPin, LOW); // Turn it off
    
    // Get data from PC
    while(index > 0){
      // The idea is that we only decrease the counter only when receive data
      // or else the program will keep on looping at get data phase
      if(altSerial.available() > 0){
        data[arrSize-index] = altSerial.parseInt(); // putting data to each channel
        analogWrite(data[arrSize-index], testPin);
        index--;
      }
    }
    index = channel; // Reset index
  }
  // Send it to DMX slaves
    while(index > 0){
      DMXSerial.write((arrSize-index), data[arrSize-index]); // Push data to DMX slaves
      analogWrite(testPin, data[arrSize-index]); // Make sure we are sending out data
      index--;
    }
  
}
