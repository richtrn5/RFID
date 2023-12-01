#include "RfidUB.h"


RfidUB::~RfidUB()
{
}


//mfrc522 object instance
void RfidUB::rfid_Setup()
{
  buttons_.begin();
  SPI.begin(SCK,MY_MISO_PIN,MY_MOSI_PIN); //RUN another SPI comm. line under those pins, assuming they're not being used

  pinMode(RST, OUTPUT);
  digitalWrite(RST, HIGH);

  mfrc522.PCD_Init();
  delay(1000);

	mfrc522.PCD_DumpVersionToSerial();	// Show details of PCD - MFRC522 Card Reader details
}


void RfidUB::displayUID()
{
  // using buttons for sleep mode...
  buttons_.loop();

  if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
    // Clear the line
    //tft.fillRect(0, 0, tft.width(), tft.fontHeight(), TFT_BLACK);

    // Show UID on TFT display
    tft.setCursor(0, 20); // (x,y, font)
    tft.setTextColor(TFT_WHITE, TFT_BLACK); // Set text color
    tft.print("UID Tag: ");

    // checks and displays UID in HEX format
    for (byte i = 0; i < mfrc522.uid.size; i++) {
        tft.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
        tft.print(mfrc522.uid.uidByte[i], HEX);
    }

    delay(1000);  // Add a delay if needed
  }
}

void RfidUB::tft_Setup()
{
    const char stuff[15] = "UB RFID SYSTEM";

    //initialize display default parameters
    tft.init();
    //set screen to landscape
    tft.setRotation(1);
    tft.fillScreen(TFT_GREY);
    tft.setCursor(0,0,2); // sets cursor for tft.print, 3rd parameter is font type
    tft.setTextColor(TFT_WHITE,TFT_BLACK);  
    tft.setTextSize(1);
    tft.println(stuff);
}

void RfidUB::wifi_Setup()
{
  if(!wifiManager.autoConnect("esp32", "password"))
  {
    tft.setCursor(0,30,2); // sets cursor for tft.print, 3rd parameter is font type
    tft.println("WiFi Failed to Connect to ");
    //tft.println(wifiManager.getWiFiSSID());
  }
}

void RfidUB::checkUID()
{
  if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
    if (!isUIDStored()) {
      Serial.println("New UID detected. Storing in EEPROM.");
      storeUID();
    } else {
      Serial.println("UID already stored.");
    }
    delay(1000);
  }
}

bool RfidUB::isUIDStored()
{
  for (int i = 0; i < MAX_UID_LENGTH; i++) {
    if (EEPROM.read(i) != mfrc522.uid.uidByte[i]) {
      return false; // UID doesn't match at this address
    }
  }
  return true; // UID matches at all addresses
}


void RfidUB::storeUID()
{
  for (int i = 0; i < MAX_UID_LENGTH; i++) {
    EEPROM.write(i, mfrc522.uid.uidByte[i]);
  }
  EEPROM.commit();
}


