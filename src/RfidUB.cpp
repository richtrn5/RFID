#include "RfidUB.h"

// for pinout diagram
//https://f6czv.fr/en/documentation-on-esp32-and-the-ttgo-t-display



//mfrc522 object instance
int getUID()
{

}

void rfid_Setup(MFRC522 & mfrc522)
{
    SPI.begin(SCK,MY_MISO_PIN,MY_MOSI_PIN); //RUN another SPI comm. line under those pins, assuming they're not being used

    pinMode(RST, OUTPUT);
    digitalWrite(RST, HIGH);

    mfrc522.PCD_Init();
    // for motor's relay
    delay(1000);



 // delay(4);				// Optional delay. Some board do need more time after init to be ready, see Readme
	mfrc522.PCD_DumpVersionToSerial();	// Show details of PCD - MFRC522 Card Reader details
}

void displayUID(MFRC522 & mfrc522, TFT_eSPI & tft)
{
    if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
    // Clear the line
    //tft.fillRect(0, 0, tft.width(), tft.fontHeight(), TFT_BLACK);

    // Show UID on TFT display
    tft.setCursor(0, 20); // (x,y, font)
    tft.setTextColor(TFT_WHITE, TFT_BLACK); // Set text color
    tft.print("UID Tag: ");

    for (byte i = 0; i < mfrc522.uid.size; i++) {
        tft.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
        tft.print(mfrc522.uid.uidByte[i], HEX);
    }

    delay(1000);  // Add a delay if needed
  }
}