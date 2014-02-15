#include <DmxSimple.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Setting up Serial port");
  Serial.setTimeout(1000000);
  pinMode(4, OUTPUT);
  
}
int value = 0;
int channel = 0;
void loop() {
  // put your main code here, to run repeatedly: 
  // Make sure the serial monitor is set to new line.
  while(Serial.available() > 0){
    // get channel first
    channel = Serial.parseInt();
    Serial.println(channel); 
    // get value
    value = Serial.parseInt();
    Serial.println(value);
    // Write value
    analogWrite(4, value); // Output received value
    DmxSimple.write(channel, value); // By default DmxSimple uses pin 3 for output
  }
}
