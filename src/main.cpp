#include "RfidUB.h"
#include <string>
#include "Button.h"

using std::string;

#define CW 15
#define CCW 13

 
// create instances of TFT class and MFRC522 class
TFT_eSPI tft = TFT_eSPI();
MFRC522 mfrc522(SS, RST);
RfidUB cardReader_(mfrc522, tft);
Button buttons_;
//volatile bool buttonPressed = false;
//derived from Print class or Print.h

//initialize rc522 class pointer as a VSPI
//SPIClass rc522(VSPI);



void setup() {
  Serial.begin(115200);

  buttons_.begin();
  cardReader_.wifi_Setup();

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

  buttons_.loop();



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

 // TODO: Make active buzzer beep when distance sensor detects the box is opened

/*
#include <NewPing.h>

#define TRIGGER_PIN 12
#define ECHO_PIN 13
#define BUZZER_PIN 14

NewPing sonar(TRIGGER_PIN, ECHO_PIN);
int buzzerState = LOW;

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  int distance = sonar.ping_cm();

  if (distance <= 10) {
    // Box is opened, activate buzzer
    buzzerState = HIGH;
  } else {
    // Box is closed, deactivate buzzer
    buzzerState = LOW;
  }

  digitalWrite(BUZZER_PIN, buzzerState);
  delay(100);
}
*/

// create code where person scans card, and the card is sent to the database...
// maybe just store the names here with the UID... class People.h