#include <Wire.h>
// This a I2C master
void setup() {
  Wire.begin();
  Serial.begin(9600);
  Serial.setTimeout(100000);
  pinMode(4, OUTPUT);
}
// transmitted byte value consists of 7 bit data so numberical value ranges from 0 to 127
// the most siginificant bit is reserved for read and write action
void loop() {
  byte value = 0;
  while(true){
    Wire.beginTransmission(1); // Transmit to device 1
    Wire.write(value);
    Wire.endTransmission();
    analogWrite(4, (int)value);
    Serial.println(int(value));
    delay(10);
    value++;
    if(int(value) == 128){
     value = 0; 
    }
  }

}
