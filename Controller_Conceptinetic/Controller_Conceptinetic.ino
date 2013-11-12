// This is a DMX controller using the Conceptinetics library.
// Judging from the website I can turn the controller on or off
// which means that I can avoid redefinition of serial port.

#include <Conceptinetis.h>

#define DMX_master_channels 10 // set max number of channels
#define RXEXN_pin 3 // setting read/write mode pin

DMX_Master dmx_master(DMX_master_channels, RXEX_pin); // Setting up the DMX controller

void setup(){
  // Enable DMX master interface
  dmx_master.enable();
  
  // Set channel range @ 50%
  dmx_master.setChannelRange(1, 25, 127);
  
  // Initialize serial monitor
  Serial.begin(255000);
}

void loop(){
  
}
