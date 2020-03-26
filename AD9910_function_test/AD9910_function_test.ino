#include <SPI.h>
#include "AD9910.h"


//Define pin mappings:
#define CSPIN 14                 // DDS chip select pin. Digital input (active low). Bringing this pin low enables detection of serial clock edges.
#define OSKPIN 15 //not actually connected               // DDS Output Shift Keying. Digital input.
#define PS0PIN 5               // DDS PROFILE[0] pin. Profile Select Pins. Digital input. Use these pins to select one of eight profiles for the DDS.
#define PS1PIN 6               // DDS PROFILE[1] pin. Profile Select Pins. Digital input. Use these pins to select one of eight profiles for the DDS.
#define PS2PIN 7               // DDS PROFILE[2] pin. Profile Select Pins. Digital input. Use these pins to select one of eight profiles for the DDS.
#define IO_UPDATEPIN  9        // DDS I/O_UPDATE pin. Digital input. A high on this pin transfers the contents of the buffers to the internal registers.
#define RESETPIN 10      // DDS MASTER_RESET pin. Digital input. Clears all memory elements and sets registers to default values.



//Declare the DDS object:
AD9910 DDS(CSPIN, RESETPIN, IO_UPDATEPIN, PS0PIN, PS1PIN, PS2PIN, OSKPIN);


void setup() {
  delay(100);
  SPI.begin();
  SPI.setClockDivider(4);
  SPI.setDataMode(SPI_MODE0,CSPIN);
  SPI.setBitOrder(MSBFIRST);
  
  Serial.begin(115200);
  
  delay(10);
  
  DDS.begin(40000000,25);
  DDS.setFreq(10000000,0);
}

void loop() {
  // put your main code here, to run repeatedly:
  DDS.setFreq(20000000,0);
  
  delay(500);
  DDS.setFreq(10000000,0);
  
  delay(500);

}
