#include <Arduino.h>
#include <M5Stack.h>
#include <Arduino_JSON.h>
#include <WiFiMulti.h>
#include <HTTPClient.h>

#include "WifiAccessPoint.h"

WiFiMulti wifiMulti;
HTTPClient http;
int httpCode;

WifiAccessPoint::WifiAccessPoint()
{
}

bool WifiAccessPoint::setupWifiConnection(const char *ssid, const char *password)
{
  wifiMulti.addAP(ssid, password);
  M5.Lcd.println("Connection Wifi en cour ...");
  if ((wifiMulti.run() == WL_CONNECTED))
  {
    M5.Lcd.println("\Connexion wifi effectuée avec succès");
    return true;
  }
  else
  {
    M5.Lcd.println("Une erreur est survenue lors de la connection wifi");
    return false;
  }

}

char WifiAccessPoint::requestDollicloud(String productRef)
{
    M5.Lcd.print("[HTTP Request] Requête en cours...\n");
    http.begin("https://t-iot-901.with4.dolicloud.com/api/index.php/products/ref/" + productRef);
    http.addHeader("DOLAPIKEY", "6JarUoS9O10yB0tI9nU7ve0ZRa1hR0Uw");

    httpCode = http.GET();

    if (httpCode <= 0 || httpCode != HTTP_CODE_OK)
    {
      M5.Lcd.printf("[HTTP Request] Erreur de requête sur la référence du produit, erreur: %s\n", http.errorToString(httpCode).c_str());
      http.end();
      return 'Z';
    }

    JSONVar product = JSON.parse(http.getString());
    http.end();

    http.begin("https://t-iot-901.with4.dolicloud.com/api/index.php/warehouses/" + product["fk_default_warehouse"]);
    http.addHeader("DOLAPIKEY", "6JarUoS9O10yB0tI9nU7ve0ZRa1hR0Uw");

    httpCode = http.GET();

    if (httpCode <= 0 || httpCode != HTTP_CODE_OK)
    {
      M5.Lcd.printf("[HTTP Request] Erreur de requête sur la warehouse, erreur: %s\n", http.errorToString(httpCode).c_str());
      http.end();
      return 'Z';
    }
    
    M5.Lcd.printf("[HTTP Request] Requete effectuee avec succes... code: %d\n", httpCode);

    JSONVar warehouse = JSON.parse(http.getString());

    M5.Lcd.print("Label de la warehouse : ");
    M5.Lcd.println((const char*) warehouse["label"]);

    http.end();

    return warehouse["label"];
}
