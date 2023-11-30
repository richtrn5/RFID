#include <MFRC522.h>
#include <MFRC522Extended.h>
#include <deprecated.h>
#include <require_cpp11.h>

#include <Print.h>
#include <Arduino.h>
#include <SPI.h>
#include "TFT_Start.h"

// define SPI parameters
#define MY_MISO_PIN 27  // Define your custom MISO (Master In - Slave Out) pin
#define MY_MOSI_PIN 26  // Define your custom MOSI pin
#define SCK 25          // Default SCK pin for SPI
#define SS 33           // Default SS (Slave Select) pin for SPI .. IT IS ALSO THE SDA
#define RST 17
//declaring RFID function prototypes


// This should return a value for whether a card is being read or not
// Returns a value if card is not new or is not reading the card.
int getUID();

void rfid_Setup(MFRC522 & mfrc522);

void displayUID(MFRC522 & mfrc522, TFT_eSPI & tft);


