#include <MFRC522.h>
#include <MFRC522Extended.h>
#include <EEPROM.h>

#include <SPI.h>
#include "TFT_eSPI.h"
#include <WiFiManager.h>
#include "Button.h"
#include <vector>
#include "Person.h"

#define MAX_UID_LENGTH 10

#define TFT_GREY 0x5AEB

// for pinout diagram
//https://f6czv.fr/en/documentation-on-esp32-and-the-ttgo-t-display

// define SPI parameters


#define MY_MISO_PIN 27  // Define your custom MISO (Master In - Slave Out) pin
#define MY_MOSI_PIN 26  // Define your custom MOSI pin
#define SCK 25          // Default SCK pin for SPI
#define SS 33           // Default SS (Slave Select) pin for SPI .. IT IS ALSO THE SDA
#define RST 17

using std::vector;

//declaring RFID function prototypes


// This should return a value for whether a card is being read or not
// Returns a value if card is not new or is not reading the card.
class RfidUB
{
private:
    MFRC522 mfrc522;
    Button buttons_;
    TFT_eSPI tft = TFT_eSPI();
    // manager saves last successful wifi credentials in EEPROM
    WiFiManager wifiManager;
    //create a vector of person to store each person object with their name, uid, etc.
    vector<Person> people; 
public:
    RfidUB(): mfrc522(SS, RST) {} //inline just to initiate object
    void rfid_Setup();

    void displayUID();
    void tft_Setup();
    void wifi_Setup();

    //TODO implement these

    // checks to see if UID already exists 
    void checkUID();

    bool isUIDStored();
    void storeUID();

    ~RfidUB();
};



//TODO initiate WIFI





