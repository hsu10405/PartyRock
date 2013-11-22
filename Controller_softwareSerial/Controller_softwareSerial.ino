// This is DMXcontroller that utilizes the DMX library and software serial protocol
// The idea is to have this as a intermediate hub between the computer and the DMX slaves
// The software serial handles computer inputs and the DMX controller serial handles DMX signals

// The protocol should be something like this
// 1. First batch of signal specifies how many channels we are sending data to
// 2. Second batch of data specifies the data to that channel
// 3. Since we are specifying the number of channels, if we are not sending anything to a particlar channel
//    we change it to idle.
//
// The software serial function and the DMX controller function are encapsulated so that it's easier to debug

#include <DMXSerial.h>

#include <AltSoftSerial.h>

#define testPin 5
#define arrSize 10

AltSoftSerial altSerial;
void softSerial(); 

void setup(){
  // initialize the DMX controller
  DMXSerial.init(DMXController);
  
  pinMode(testPin, OUTPUT);
  
  // Setting the transmission rate of SoftwareSerial
  altSerial.begin(9600);
  
  
}

void loop(){
  int channel = 0;
  int index = 1;
  int data[arrSize]; //declare each channel
  // Get data from altSerial
  softSerial(data, &channel);
  // Send it to DMX slaves
  while(index < channel){
    DMXSerial.write(index + 1, data[index]); // Push data to DMX slaves
    analogWrite(testPin, data[index]); // Make sure we are sending out data
    index++;
  }
  
}
void softSerial(int *array, int *channel){
  // Get channel, the trasmitter must know the channel limit.
  int index = 0;
  if(altSerial.available() > 0){
    *channel = altSerial.read();
    // index = *channel; // duplicate indexk
  }
  while(index < *channel){
    if(altSerial.available() > 0){
      array[index] = altSerial.read(); // caching data into an temp array;
      analogWrite(testPin, array[index]); // Make sure we got some data
      index++;
    }
  }
  
}
