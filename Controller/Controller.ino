#include <DMXSerial.h>
#define max_channel 10; //defining max channel here
#define ON 255; //Since we are just turning lights on and off, we will define the values to make our lives easier.
#define OFF 0;
#define output 6; //setting up the output pin here.
// This is a DMX code for the MASTER controller.
// DMXserial use analogWrite to output signals.
// In our case each channel represents an separate Arduino to control.
// 

void setup() {
  pinMode(output, OUTPUT);
  Serial.begin(9600); //initialize serial monitor
  Serial.println("Monitor initialized);
  
}

void loop() {
  int channel = 0;
  int signal_stat = ON;
  
  // Only send data when you get data  
  // Getting inputs
  if(Serial.available() > 0){
    Serial.println("Select a channel.");
    channel = Serial.read();
    Serial.println("Channel received");
    Serial.println("");
    Serial.println("On or off?");
    signal_stat = Serial.read();
    Serial.println("Input received");
    
    while(channel > max_channel){
      Serial.println("Not a valid input");
      channel = Serial.read(); // if the program receives wrong inputs, keep on asking for the new one.
    }
    if(signal_stat > 0){;
      signal_stat = ON;
    }
    else{
      signal_stat = OFF;
    }
  }
  
  // Passing input to receiver, for now it only takes one input per cycle.
  DMXSerial.write(channel, signal_stat);
  delayMicroseconds(2000); // Wait a little bit.  
    
    
}
