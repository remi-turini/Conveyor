#include <M5Stack.h>

#include "StepMotor.h"

StepMotor tapis;

void setup() {
  // put your setup code here, to run once:
M5.begin();
    M5.Power.begin();
    Wire.begin();
    m5.Lcd.setTextColor(WHITE, BLACK);
    m5.Lcd.setTextSize(2);
    m5.Lcd.setBrightness(100);
    M5.Lcd.setCursor(4, 10);
    M5.Lcd.println("StepMotor Test: 0x70");
}

void loop() {
  // put your main code here, to run repeatedly:
tapis.Forward(1);
//delay(1000);
//tapis.Forward(3);
//delay(1000);
M5.Lcd.println("la la");
}
