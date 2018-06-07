#include <SPI.h>
#include <RFID.h>

#define SS_PIN 10
#define RST_PIN 9
RFID rfid(SS_PIN,RST_PIN);

//int led = 7;
//int relay= 8; 
int serNum[5];
int cards[][5] = {
  {127,126,160,89,248}
  
};

bool access = false;

void setup(){

    Serial.begin(9600);
    SPI.begin();
    rfid.init();
    pinMode(7, OUTPUT);
    digitalWrite(7, LOW);
    pinMode(8, OUTPUT);
    digitalWrite(8, LOW);
   
}

void loop(){
  if(rfid.isCard()){
    if(rfid.readCardSerial()){
      Serial.print(rfid.serNum[0]);
      Serial.print(" ");
      Serial.print(rfid.serNum[1]);
      Serial.print(" ");
      Serial.print(rfid.serNum[2]);
      Serial.print(" ");
      Serial.print(rfid.serNum[3]);
      Serial.print(" ");
      Serial.print(rfid.serNum[4]);
      Serial.println("");
        for(int x = 0; x < sizeof(cards); x++){
          for(int i = 0; i < sizeof(rfid.serNum); i++ ){
            if(rfid.serNum[i] != cards[x][i]) {
              access = false;
              break;
              }
            else {
              access = true;
              }
           }
              if(access) break;
        }
           
     }
     if(access){
        Serial.println("Welcome!");
        digitalWrite(8, HIGH); 
        delay(3000);
        digitalWrite(8, LOW);   
        } 
      else {
        Serial.println("Not allowed!"); 
        digitalWrite(7, HIGH);
        delay(1000);
        digitalWrite(7, LOW);    
       }        
  }
 rfid.halt();
}


