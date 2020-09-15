/*


*/

#include <WiFi.h>
#include <Ethernet.h>

#include <SPI.h>
#include <Wire.h>
#include "SHTSensor.h"
#include "FS.h"
#include <SD.h>
#include "RTClib.h"
#include <SDConfigFile.h>

#include "variables.h"


void setup()
{

  Wire.begin();
  Serial.begin(115200);
  delay(100);

  pinSetup();

  delay(1000);
  Serial.println("");
  Serial.println("******************************");
  Serial.println("        Program start         ");
  Serial.println("******************************");
  Serial.println(versionFW);
  Serial.println("******************************");
  loadConfigFile();
  delay(100);

  //Network config select
  String nSelected = network;
  if (nSelected == "WIFI"){
    NetworkSelect = 1;
    Serial.println("WIFI ENABLE");
  } else if (nSelected == "ETH"){
    NetworkSelect = 2;
    Serial.println("ETH ENABLE");
  } else {
    NetworkSelect = 0;
    Serial.println("USB ONLY");
  }
  
  //IP
  j = 0;
  for (int i = 0; i < strlen(IP); i++) {
    if (IP[i] == '.') {
      j++;
    } else {
      ParsedIP[j] = ParsedIP[j] + IP[i];
    }
  }
  local_IP = IPAddress((byte)ParsedIP[0].toInt(), (byte)ParsedIP[1].toInt(), (byte)ParsedIP[2].toInt(), (byte)ParsedIP[3].toInt());
  ParsedIP[0] = ""; ParsedIP[1] = ""; ParsedIP[2] = ""; ParsedIP[3] = "";
  //Serial.println(local_IP);

  //GW
  j = 0;
  for (int i = 0; i < strlen(Passerel); i++) {
    if (Passerel[i] == '.') {
      j++;
    } else {
      ParsedIP[j] = ParsedIP[j] + Passerel[i];
    }
  }
  gateway = IPAddress((byte)ParsedIP[0].toInt(), (byte)ParsedIP[1].toInt(), (byte)ParsedIP[2].toInt(), (byte)ParsedIP[3].toInt());
  ParsedIP[0] = ""; ParsedIP[1] = ""; ParsedIP[2] = ""; ParsedIP[3] = "";
  //Serial.println(gateway);

  //Mask
  j = 0;
  for (int i = 0; i < strlen(Masque); i++) {
    if (Masque[i] == '.') {
      j++;
    } else {
      ParsedIP[j] = ParsedIP[j] + Masque[i];
    }
  }
  subnet = IPAddress((byte)ParsedIP[0].toInt(), (byte)ParsedIP[1].toInt(), (byte)ParsedIP[2].toInt(), (byte)ParsedIP[3].toInt());
  ParsedIP[0] = ""; ParsedIP[1] = ""; ParsedIP[2] = ""; ParsedIP[3] = "";
  //Serial.println(subnet);

  //MAC
  j = 0;
  for (int i = 0; i < strlen(MAC); i++) {
    if (MAC[i] == ':') {
      j++;
    } else {
      ParsedMAC[j] = ParsedMAC[j] + MAC[i];
    }
  }

  for (int i = 0; i < 6; i++) {

    char copy[50];
    ParsedMAC[i].toCharArray(copy, 50);
    macAdresse[i] = strtoul(copy, NULL, 16);
    //Serial.print(macAdresse[i], HEX);
    //Serial.print(":");
  }

  //
  Serial.println();
  Serial.println();

  setupNetwork();

  //init SHT
  initSHT ();
  readSHT ();

  //init Serial
  // reserve 200 bytes for the inputString:
  inputString.reserve(200);

  endSetup();
  Serial.println("");
  Serial.println("******************************");
  Serial.println("           END SETUP          ");
  Serial.println("******************************");
  //writeConfiguration();
  //createSensorFile();
  setupCore();


}
