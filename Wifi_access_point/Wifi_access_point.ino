#include <Arduino_JSON.h>

#include <M5Stack.h>
#include <WiFiMulti.h>
#include <HTTPClient.h>
#include "WifiAccessPoint.h"

//WiFiMulti wifiMulti;
//HTTPClient http;
WifiAccessPoint wifiAccessPoint;

//const char *ssid = "Remiwifi";
//const char *password = "remistiti";
//int httpCode;

void setup()
{
  M5.begin();
  M5.Power.begin();

  //faire la connexion wifi

  //faire tourner le moteur pas à pas

  // lire le rfid

  //arrêter le moteur pas à pas

  // faire l'appel au dollibar

  // faire tourner le moteur pas à pas,

  // pivoter le servomoteur dans la bonne direction grâce au retour de l'appel dollibar

  // recommencer à la ligne 26 ...

  bool success = wifiAccessPoint.setupWifiConnection("Remiwifi", "remistiti");
  
  if (success != 1)
  {
    // condition à modifier ici, par exemple reboucler sur la connexion wifi
    M5.Lcd.println("Impossible de connecter la wifi");
    return;
  }

  char result = wifiAccessPoint.requestDollicloud("4663866229107128");
  if(result == 'Z')
  {
    // condition à modifier ici, par exemple reboucler sur la requete dollibar
    M5.Lcd.println("Impossible de recuperer la warehouse");
    return;
  }
    
  M5.Lcd.printf("Voici la warehouse id : %d\n", (const char*) result);
}

void loop()
{
}
