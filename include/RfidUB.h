#include <MFRC522.h>
#include <MFRC522Extended.h>
#include <EEPROM.h>

#include <SPI.h>
#include "TFT_eSPI.h"
#include <WiFiManager.h>
#include "Button.h"
#include <vector>
#include "Person.h"
#include "Motor.h"

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

// for relay input pins
#define CW 15
#define CCW 13

// Active Buzzer
#define BUZZER_PIN 14

//declaring RFID function prototypes

// This should return a value for whether a card is being read or not
// Returns a value if card is not new or is not reading the card.
class RfidUB
{
private:
    // multiple containments defined
    Motor motor;
    MFRC522 mfrc522;
    Button buttons_;
    TFT_eSPI tft = TFT_eSPI();
    // manager saves last successful wifi credentials in EEPROM
    WiFiManager wifiManager;
    // create dynamic array of Person
    Person ** people;
    const int num_people = 10;
    int index = 0;

public:
    RfidUB(): motor(CW,CCW), mfrc522(SS, RST) { people = new Person*[num_people]; } //inline just to initiate object
    void rfid_Setup();
    void add_people(String name, String uid);
    bool check_People(String content);
    void tft_Setup();
    void wifi_Setup();

    //TODO implement these
    void clearLineAtY(int y);

    // checks to see if UID already exists 
    void checkUID();


    ~RfidUB();
};



//TODO initiate WIFI





