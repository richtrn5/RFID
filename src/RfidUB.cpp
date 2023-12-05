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

void RfidUB::add_people(String name, String uid)
{
  people[index] = new Person(name, uid);
  index++;
  
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
        //tag += mfrc522.uid.uidByte[i];
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
  buttons_.loop();

  String tag = "";
  tft.setCursor(0, 20); // (x,y, font)
  tft.setTextColor(TFT_WHITE, TFT_BLACK); // Set text color
  tft.print("UID Tag: ");

  if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
    // Print UID
    Serial.print("UID Tag :");
    String content= "";
    for (byte i = 0; i < mfrc522.uid.size; i++) {
      //content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
      content.concat(String(mfrc522.uid.uidByte[i], HEX));
      tft.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
      tft.print(mfrc522.uid.uidByte[i], HEX);
    }
    content.toUpperCase();
    Serial.println(content);

    // Check for access for loop of each person
    // MOVE THE MOTOR HERE
    tft.setCursor(0, 40); // (x,y, font)

    if (check_People(content))
    {
      // add motor control here for unlock
    }
    else
    {
      Serial.println("Access Denied");
      tft.print("Access Denied");
      clearLineAtY(60);
      //tft.print("  ");
      // add motor control here for lock
    }
    
    
    delay(1000);  // Delay to avoid reading the same card multiple times
  }
}

  
  //if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {

bool RfidUB::check_People(String content)
{
  for (size_t i = 0; i < index; i++)
  {
    if (content.equals(people[i]->getUID())) {  // Replace "YOUR_ACCESS_UID" with the actual UID of the authorized card
      Serial.println("Access Granted");
      tft.print("Access Granted");
      tft.setCursor(0, 60); // (x,y, font)
      clearLineAtY(60);
      tft.print(people[i] -> getName());
      return true; // breaks for loop when detected
    } else {
      //Serial.println("Access Denied");
      //return false;
    }
  }
  return false; //default return
}


void RfidUB::clearLineAtY(int y) {
  // Draw a filled rectangle to clear the entire line at y position
  int16_t screenWidth = tft.width();
  int16_t lineHeight = tft.fontHeight();  // Adjust if using different font size

  tft.fillRect(0, y, screenWidth, lineHeight, TFT_GREY);
}


