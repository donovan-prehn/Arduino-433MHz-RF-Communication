#include <VirtualWire.h>
#include <LiquidCrystal.h>
/*
 * Arduino 433MHz Receiver Demo
 *
 * Donovan Prehn
 * Peter Scherminski
 */

 /*   Physical Connections
  *   
  *   UNO     ->    XY-MK-5V
  *   5V   ----------- VCC
  *   11   ----------- DATA
  *        ----------- DATA
  *   GND  ----------- GND
  */

const int recvPin = 11;

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

void setup()
{

  //USB Serial Monitor Debugging
  Serial.begin(9600);
  Serial.println("setup()");
 
  // LCD Screen Shield
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0,0);

  //VirtualWire
  vw_set_rx_pin(recvPin);
  vw_set_ptt_inverted(true); // Required for DR3100
  vw_setup(2000);      // Bits per sec
  vw_rx_start();       // Start the receiver PLL running
}
void loop()
{
    uint8_t buf[VW_MAX_MESSAGE_LEN];
    uint8_t buflen = VW_MAX_MESSAGE_LEN;
    if (vw_get_message(buf, &buflen)) // Non-blocking
    {
      //Refresh LCD Screen
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Light Val: ");

      int i;
      for(i=0; i<buflen; i++){
        lcd.print(char(buf[i]));
      }
    }
}