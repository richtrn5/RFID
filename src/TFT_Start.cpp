#include "TFT_Start.h"

void tft_Setup(TFT_eSPI & tft)
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