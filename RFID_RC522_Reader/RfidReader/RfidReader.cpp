

#include <Arduino.h>
#include "RfidReader.h"

#include <M5Stack.h>

#include "MFRC522_I2C.h"

MFRC522 mfrc522(0x28); // Create MFRC522 instance.
String UID;

RfidReader::RfidReader()
{
  // SetupRfid();
  //  Se servirde ce bloc comme setup
}

void RfidReader::setupRfid()
{

  M5.Lcd.println("MFRC522 Test");
  Wire.begin(); // Wire init, adding the I2C bus.  Wire

  mfrc522.PCD_Init(); // Init MFRC522.
  M5.Lcd.println("Please put the card\n");
}

String RfidReader::readRfcTag()
{
  UID = "";
  M5.Lcd.setCursor(40, 47);
  if (!mfrc522.PICC_IsNewCardPresent() ||
      !mfrc522.PICC_ReadCardSerial())
  { //
    delay(1000);
   // return UID;
  }

  
    M5.Lcd.fillRect(42, 47, 320, 20, BLACK);
    for (byte i = 0; i < mfrc522.uid.size;
         i++)
    { // Output the stored UID data.
      // M5.Lcd.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
      // M5.Lcd.print(mfrc522.uid.uidByte[i], HEX);
      // M5.Lcd.print(mfrc522.uid.uidByte[i]);
      UID = UID + mfrc522.uid.uidByte[i];
    }
    M5.Lcd.println("");

    //M5.Lcd.println("UID : ");
   // M5.Lcd.println(UID);

    return UID;
 
}
