//#include <DMXSerial.h>
#include <Wire.h>


void setup() {
  // put your setup code here, to run once:
  Wire.begin(1); // joining the bus with address #1
  //DMXSerial.init(DMXController);
  pinMode(2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Receive data from I2C and transfer it to DMX line.
  
  // First read I2C
  byte I2C = 0;
  while(Wire.available() > 1){
    I2C = Wire.read();
  }
  Serial.println(I2C);
  analogWrite(3, 127-(int)I2C);
  
}
