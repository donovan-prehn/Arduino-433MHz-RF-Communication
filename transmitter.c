#include <VirtualWire.h>

/*
 * Arduino 433MHz Transmitter Demo
 *
 * Donovan Prehn
 * Peter Scherminski
 */

/* Physical Connections
 *
 *  NANO    ->    FS1000A
 *  5V  ----------- VCC
 *  GND ----------- GND     
 *  D13 ----------- ATAD
 *  A0  ----------- Light Dependent Resistor
 */

const int numberBase = 10;    //Decimal Base
const int transmitPin = 12;   //D12
const int analogInputPin = 0; //A0

char lightValueString[4];

void setup() {
 
  //USB Serial Monitor Debugging
  Serial.begin(9600);
  Serial.println("setup()");

  //VirtualWire
  vw_set_ptt_inverted(true);
  vw_setup(2000);
 
}
void loop() {

  //Read Light Value
  int analogLightValue = analogRead(analogInputPin);
  itoa(analogLightValue, lightValueString, numberBase);
 
  //Debug
  Serial.print("Light CharMsg: ");
  Serial.println(lightValueString);

  //Transmit Light Value
  vw_send((uint8_t *)lightValueString, strlen(lightValueString));
  vw_wait_tx(); // Wait until the whole message is gone
  delay(200);
 
}