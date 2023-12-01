#include <MFRC522.h>
#include <MFRC522Extended.h>
#include <deprecated.h>
#include <require_cpp11.h>

#include <Print.h>
#include <Arduino.h>
#include <SPI.h>
#include "TFT_eSPI.h"
#include <WiFiManager.h>


#define TFT_GREY 0x5AEB

// for pinout diagram
//https://f6czv.fr/en/documentation-on-esp32-and-the-ttgo-t-display

// define SPI parameters
#define MY_MISO_PIN 27  // Define your custom MISO (Master In - Slave Out) pin
#define MY_MOSI_PIN 26  // Define your custom MOSI pin
#define SCK 25          // Default SCK pin for SPI
#define SS 33           // Default SS (Slave Select) pin for SPI .. IT IS ALSO THE SDA
#define RST 17
#define buttonPin 0
#define wakeUpPin 35
//declaring RFID function prototypes


// This should return a value for whether a card is being read or not
// Returns a value if card is not new or is not reading the card.
class RfidUB
{
private:
    MFRC522 mfrc522;
    TFT_eSPI tft;
    WiFiManager wifiManager;
public:
    RfidUB(MFRC522& tempMFRC, TFT_eSPI & tft);
    void rfid_Setup();
    void displayUID();
    void tft_Setup();
    void wifi_Setup() { wifiManager.autoConnect("esp32", "password"); }
    ~RfidUB();
};



//TODO initiate WIFI





