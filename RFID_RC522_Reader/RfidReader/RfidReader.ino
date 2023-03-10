/*
*******************************************************************************
  Describe: RFID.
  Date: 2021/8/19
*******************************************************************************
  Please connect to Port A(22、21),Use the RFID Unit to read the Fudan card ID
  and display the ID on the screen.
*/


#include <M5Stack.h>
#include "RfidReader.h"


RfidReader rfidReader;

void setup() {

  M5.begin();        // Init M5Core.  初始化 M5Core
  M5.Power.begin();  // Init Power module.  初始化电源模块

  //initialise le moduleRfid
  rfidReader.setupRfid();




}

void loop() {

  M5.Lcd.println("RFID = " + rfidReader.readRfcTag());

}
