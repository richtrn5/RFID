#include "RfidUB.h"




// create instances of TFT class and MFRC522 class and button class
RfidUB cardReader_;

void setup() {
  Serial.begin(115200);
  pinMode(CW, OUTPUT);
  pinMode(CCW, OUTPUT);
  //pinMode(BUZZER_PIN, OUTPUT);

  cardReader_.tft_Setup();

  cardReader_.rfid_Setup();

  Serial.println(F("Scan PICC to see UID, SAK, type, and data blocks..."));

  cardReader_.add_people("John", "DABD6B80"); // add person to Dynamic Array
  cardReader_.add_people("Brandon", "7A69E880");

  cardReader_.wifi_Setup();

}

void loop() {

  //cardReader_.displayUID();
  cardReader_.checkUID();



}

// will use later in the MOTOR class

// program for running dc motor in all directions
  /*

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