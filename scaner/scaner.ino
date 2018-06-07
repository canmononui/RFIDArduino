#include <SPI.h>
#include <RFID.h>

#define SS_PIN 10
#define RST_PIN 9

RFID rfid(SS_PIN, RST_PIN); 

// Setup variables:
  int serNum0;
  int serNum1;
  int serNum2;
  int serNum3;
  int serNum4;
  int cards[][5] = {
    {127,126,160,89,248}
  }

void setup()
{ 
  Serial.begin(9600);
  SPI.begin(); 
  rfid.init();
  pinMode(7, OUTPUT);
  digitalWrite(7, LOW);
  pinMode(8, OUTPUT);
  digitalWrite(8, LOW);  
}

void loop()
{
  if(rfid.isCard()) {
     if(rfid.readCardSerial()) {
       /*if (rfid.serNum[0] != serNum0
       && rfid.serNum[1] != serNum1
       && rfid.serNum[2] != serNum2
       && rfid.serNum[3] != serNum3
       && rfid.serNum[4] != serNum4) 
       */
       //Serial.println(" ");
       Serial.println("Card found");
       serNum0 = rfid.serNum[0];
       serNum1 = rfid.serNum[1];
       serNum2 = rfid.serNum[2];
       serNum3 = rfid.serNum[3];
       serNum4 = rfid.serNum[4];      
       Serial.print("Hex: ");
       Serial.print(rfid.serNum[0],HEX);
       Serial.print(", ");
       Serial.print(rfid.serNum[1],HEX);
       Serial.print(", ");
       Serial.print(rfid.serNum[2],HEX);
       Serial.print(", ");
       Serial.print(rfid.serNum[3],HEX);
       Serial.print(", ");
       Serial.print(rfid.serNum[4],HEX);
       Serial.println(" ");
        if(rfid.serNum[0],HEX = cardNum0
        && rfid.serNum[1],HEX = cardNum0
        && rfid.serNum[2],HEX = cardNum0
        && rfid.serNum[3],HEX = cardNum0
        && rfid.serNum[4],HEX = cardNum0){ 
          digitalWrite(8, HIGH);
          delay(1000);
          digitalWrite(8, LOW);
          delay(1000);
          }
        else{
          digitalWrite(7, HIGH);
          delay(1000);
          digitalWrite(7, LOW);
          delay(1000);
          }
       }
    }
    
    //rfid.halt();
}
