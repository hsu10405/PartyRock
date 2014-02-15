#include "mbed.h"
#include "DMX.h"
//#include "USBSerial.h"

//DMX protocol
DMX myDMX(p9,p10);
 
//Virtual serial port over USB
Serial pc(USBTX, USBRX);

//Indicator LED
DigitalOut L1(LED1);
DigitalOut L2(LED2);
DigitalOut L3(LED3);
DigitalOut L4(LED4);




int main() {

    myDMX.start();
    
    while(1) {
        switch(pc.getc()){
            case('a'):
                L1=0;
                myDMX.put(0,0);
                break;
            case('l'):
                L2=0;
                myDMX.put(1,0);
                break;
            case('c'):
                L3=0;
                myDMX.put(2,0);
                break;
            case('d'):
                L4=0;
                break;
            case('s'):
                L1=1;
                myDMX.put(0,255);
                break;
            case('k'):
                L2=1;
                myDMX.put(1,255);
                break;
            case('C'):
                L3=1;
                myDMX.put(2,255);
                break;
            case('D'):
                L4=1;
        }
    }
}