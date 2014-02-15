#include <Conceptinetics.h>
#include <Rdm_Defines.h>
#include <Rdm_Uid.h>

// Since DMX library conflicts with Arduino's built-in serial library
// and modifying hardwareSerial.cpp file is impossible.
// This file utilizes semaphores to make sure only one thing is on at any given time.

// Create a DMX Master Controller object and setting it up
#define DMX_MASTER_CHANNELS 100
#define TXEN_PIN 2 
DMX_Master dmx_master (DMX_MASTER_CHANNELS, TXEN_PIN);
void setup(){
  Serial.begin(9600);
  Serial.println("Serial Monitor initialized, ready to receive data");  
  
}

void loop(){
  
  
  
}
