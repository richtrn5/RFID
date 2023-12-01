#include <esp32-hal-gpio.h>
#include <Print.h>
#include <HardwareSerial.h>

#define sleepPin 0
#define wakeUpPin 35


class Button
{
private:
  static void handleSleepButtonInterrupt();

public:
  Button(){}
  void begin();
  void loop();
};
