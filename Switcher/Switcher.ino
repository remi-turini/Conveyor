#include <M5Stack.h>

#include "Switcher.h"

Switcher switcher;

void header(const char *string, uint16_t color) {
    M5.Lcd.fillScreen(color);
    M5.Lcd.setTextSize(1);
    M5.Lcd.setTextColor(TFT_WHITE, TFT_BLACK);
    M5.Lcd.fillRect(0, 0, 320, 30, TFT_BLACK);
    M5.Lcd.setTextDatum(TC_DATUM);
    M5.Lcd.drawString(string, 160, 3, 4);
}

void setup(){
    M5.Lcd.println("démarrage du programme switcher...");
}

void loop(){
  switcher.SetPosition('A');
  switcher.SetPosition('B');
  switcher.SetPosition('C');
  switcher.SetPosition('B');
}
