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
const int HI = 255;

AltSoftSerial altSerial;
void softSerialArray(); 

void setup(){
  // initialize the DMX controller
  DMXSerial.init(DMXController);
  
  pinMode(testPin, OUTPUT);
  
  altSerial.begin(9600);
  altSerial.setTimeout(100000);  
}

void loop(){
  // The first data the controller sees will be the channel value
  // The second data the controller sees will be the value for that channel.
  // Set default values
  int channel = 0;
  int data = HI;
  // Get channel and data
  if(altSerial.available() > 0){
    channel = altSerial.parseInt();
    data = altSerial.parseInt();
  }
  // Since the channel and data are screened by the PC_to_Controller module, we don't have
  // to check them again here.
  DMXSerial.write(channel, data);  
  
}
void softSerialArray(int *array, int *channel){
  // Get channel, the trasmitter must know the channel limit.
  // NOTE: THIS FUNCTION IS OUTDATED, MIGHT BE REMOVED.
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
