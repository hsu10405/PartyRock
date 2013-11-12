// This is the Arduino that handles the communication between the PC and the DMX controller.
#include <SoftwareSerial.h>

#define rxPin 8
#define txPin 9
#define testPin 5

  // Initialize used variables
  int channel = 0;
  int index = 0;
  int data = 0;
  
// Initialize SoftwareSerial port
SoftwareSerial PCSerial = SoftwareSerial(rxPin, txPin);

void setup(){
  Serial.begin(9600); // initialize the serial monitor
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
  
  PCSerial.begin(9600);
  
  Serial.setTimeout(100000); // parseInt has a default time out of 1 sec, this extends the time out.
  
  Serial.println("Everything is set.");
  // Serial.print("Enter # of channels: ");
}

void loop(){
  // idea: takes comupter input and parse it to the DMX controller.
  // Send data only when I receive data from computer.
  if(Serial.available() > 0){
    // First send channel
    channel = index = Serial.parseInt(); // Get the channel
    Serial.print("Channel is: ");
    Serial.println(channel);
    PCSerial.write(channel); // Send the channel out
    while(index > 0){
      // loop until we have data for each channel
      if(Serial.available() > 0){
        Serial.print("Index is:");
        Serial.println(index);
        // get data
        data = Serial.parseInt();
        // send data
        Serial.print("I got: ");
        Serial.println(data);
        // send data
        PCSerial.write(data);
        // decrement counter
        index--;
        
      }
    }
    Serial.println("All data has been parsed. Enter a new set of channels.");
  }
  
  
}
