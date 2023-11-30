#include "RfidUB.h"
#include <string>

using std::string;

#define CW 15
#define CCW 13


// create instances of TFT class and MFRC522 class
TFT_eSPI tft = TFT_eSPI();
MFRC522 mfrc522(SS, RST);
RfidUB cardReader_(mfrc522, tft);

//derived from Print class or Print.h

//initialize rc522 class pointer as a VSPI
//SPIClass rc522(VSPI);



void setup() {
  Serial.begin(115200);

  cardReader_.tft_Setup();

  delay(1000);

  cardReader_.rfid_Setup();

	Serial.println(F("Scan PICC to see UID, SAK, type, and data blocks..."));


}

void loop() {

  // PSEUDO CODE for simple display function
  // IF card detected
    // IF person is in database
        // tft.println( print person's name )
    // ELSE
        // tft.println( "access denied" )


  cardReader_.displayUID();



    //while(1) yield(); // We must yield() to stop a watchdog timeout.
  

}


// program for running dc motor in all directions
  /*
  digitalWrite(CW,HIGH); //Motor runs clockwise//

  delay(2500); //for 1 second//

  digitalWrite(CW, LOW); //Motor stops//

  digitalWrite(CCW, HIGH);//Motor runs counter-clockwise//

  delay(2500); //For 1 second//

  digitalWrite(CCW, LOW); //Motor stops//
  */