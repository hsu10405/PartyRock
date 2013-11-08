#include <DMXSerial.h>

// This code use registers instead of serial interfaces to transmit data to receivers.

void setup() {
  // Declaring arduino type 
  DMXSerial.init(DMXController);
  
}

void loop() {
  // Enable transmitter and interrupt, we are using register set 0 to house our data.
  UCSR0B = (1<<TXENn) | (1<<UDRIEn);
  
  
    
    
}
// initialize the Hardware serial port with the given baud rate
// using 8 data data bits an 2 stop bits.
void _DMXSerialBaud(long baud)
{
  uint16_t baud_setting;

  // calculate baud settings
  baud_setting = (F_CPU / 8 / baud - 1) / 2;

  // assign the baud_setting to the USART Baud Rate Register
  UBRRnH = baud_setting >> 8;
  UBRRnL = baud_setting;

  // 2 stop bits and 8 bit character size, no parity
  UCSRnC = (1<<USBSn) | (3<<USCZn0);
} // _DMXSerialBaud

void _DMXSerialWrite(uint8_t data)
{
  // Wait for empty transmit buffer
  while ( ! (UCSRnA & (1 << UDREn)) )
    ;
  // Put data into buffer, sends the data
  UDRn = data;
} // _DMXSerialWrite
