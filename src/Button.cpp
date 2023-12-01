#include "Button.h"

volatile bool sleepButtonPressed = false;

void Button::handleSleepButtonInterrupt() { 
    sleepButtonPressed = true;
    detachInterrupt(digitalPinToInterrupt(sleepPin));
}

void Button::begin() {
    pinMode(sleepPin, INPUT_PULLUP);
    pinMode(wakeUpPin, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(sleepPin), handleSleepButtonInterrupt, FALLING);
    // Configure the wake-up pin as a wake-up source
    esp_sleep_enable_ext0_wakeup((gpio_num_t)wakeUpPin, LOW);
}

void Button::loop() {
    if (sleepButtonPressed) {
      Serial.println("Turning off...");
      delay(1000);
      esp_deep_sleep_start();
    }
}