/* This is a DMX receiver using interrupts. 
   The current DMX library library out on the internet are as of now too complicated to optimized.
   So this is a simple DMX receiver that handles incoming DMX signals.
   To use this code, you need to modify hardwareSerial.cpp in the arduino core file to avoid redefinition errors.
*/

#define RX_STATUS_PIN 2

volatile uint8_t DmxRxField[8]; // Array of DNX vals (raw)
volatile uint16_t DmxAddress; // Start address

enum {IDLE, BREAK, STARTB, STARTADR}; // DMX states

volatile uint8_t gDmxState;

void setup(){
  Serial.begin(250000);
  pinMode(RX_STATUS_PIN, OUTPUT); // RX STATUS LED PIN, blinks on incoming DMX data
  gDmxState = IDLE; // initial state
  DmxAddress = 3; // the desired Dmx Start Address
}

ISR(USART0_RX_vect) {
	digitalWrite(RX_STATUS_PIN, HIGH);
	static  uint16_t DmxCount;
	uint8_t  USARTstate = UCSR0A;    //get state before data!
	uint8_t  DmxByte   = UDR0;	    //get data
	uint8_t  DmxState  = gDmxState;	//just load once from SRAM to increase speed

	if (USARTstate &(1<<FE0))		//check for break
	{
		DmxCount =  DmxAddress;		//reset channel counter (count channels before start address)
		gDmxState = BREAK;
	}

	else if (DmxState == BREAK)
	{
		if (DmxByte == 0) gDmxState= STARTB;  //normal start code detected
		else			  gDmxState= IDLE;
	}

	else if (DmxState == STARTB)
	{
		if (--DmxCount == 0)	//start address reached?
		{
			DmxCount= 1;		//set up counter for required channels
			DmxRxField[0]= DmxByte;	//get 1st DMX channel of device
			gDmxState= STARTADR;
		}
	}

	else if (DmxState == STARTADR)
	{
		DmxRxField[DmxCount++]= DmxByte;	//get channel
		if (DmxCount >= sizeof(DmxRxField)) //all ch received?
		{
			gDmxState= IDLE;	//wait for next break
		}
	}
	digitalWrite(RX_STATUS_PIN, LOW);							
}
void loop(){
  analogWrite(4, DmxRxField[0]);
}
