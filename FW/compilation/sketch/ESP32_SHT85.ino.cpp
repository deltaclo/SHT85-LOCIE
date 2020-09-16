#include <Arduino.h>
#line 1 "D:\\Documents\\GitHub\\SHT85-LOCIE\\FW\\ESP32_SHT85\\ESP32_SHT85.ino"
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


#line 20 "D:\\Documents\\GitHub\\SHT85-LOCIE\\FW\\ESP32_SHT85\\ESP32_SHT85.ino"
void setup();
#line 1 "D:\\Documents\\GitHub\\SHT85-LOCIE\\FW\\ESP32_SHT85\\ServeurWeb.ino"
void setupNetwork();
#line 20 "D:\\Documents\\GitHub\\SHT85-LOCIE\\FW\\ESP32_SHT85\\ServeurWeb.ino"
void serveurWeb();
#line 36 "D:\\Documents\\GitHub\\SHT85-LOCIE\\FW\\ESP32_SHT85\\ServeurWeb.ino"
void setupEth();
#line 58 "D:\\Documents\\GitHub\\SHT85-LOCIE\\FW\\ESP32_SHT85\\ServeurWeb.ino"
void serveurWebEth();
#line 117 "D:\\Documents\\GitHub\\SHT85-LOCIE\\FW\\ESP32_SHT85\\ServeurWeb.ino"
void setupWifi();
#line 141 "D:\\Documents\\GitHub\\SHT85-LOCIE\\FW\\ESP32_SHT85\\ServeurWeb.ino"
void serveurWebWifi();
#line 1 "D:\\Documents\\GitHub\\SHT85-LOCIE\\FW\\ESP32_SHT85\\configOnSD.ino"
void loadConfigFile();
#line 22 "D:\\Documents\\GitHub\\SHT85-LOCIE\\FW\\ESP32_SHT85\\configOnSD.ino"
boolean readConfiguration();
#line 211 "D:\\Documents\\GitHub\\SHT85-LOCIE\\FW\\ESP32_SHT85\\configOnSD.ino"
void writeConfigFile();
#line 278 "D:\\Documents\\GitHub\\SHT85-LOCIE\\FW\\ESP32_SHT85\\configOnSD.ino"
void writeSensorFile();
#line 1 "D:\\Documents\\GitHub\\SHT85-LOCIE\\FW\\ESP32_SHT85\\core1.ino"
void loop();
#line 1 "D:\\Documents\\GitHub\\SHT85-LOCIE\\FW\\ESP32_SHT85\\core2.ino"
void codeForTask2( void * parameter );
#line 1 "D:\\Documents\\GitHub\\SHT85-LOCIE\\FW\\ESP32_SHT85\\datalogger.ino"
void datalogger();
#line 3 "D:\\Documents\\GitHub\\SHT85-LOCIE\\FW\\ESP32_SHT85\\fonctions.ino"
void setupCore();
#line 29 "D:\\Documents\\GitHub\\SHT85-LOCIE\\FW\\ESP32_SHT85\\fonctions.ino"
void pinSetup();
#line 47 "D:\\Documents\\GitHub\\SHT85-LOCIE\\FW\\ESP32_SHT85\\fonctions.ino"
void endSetup();
#line 62 "D:\\Documents\\GitHub\\SHT85-LOCIE\\FW\\ESP32_SHT85\\fonctions.ino"
void artificialLoad();
#line 72 "D:\\Documents\\GitHub\\SHT85-LOCIE\\FW\\ESP32_SHT85\\fonctions.ino"
float average(unsigned long * array, int len);
#line 2 "D:\\Documents\\GitHub\\SHT85-LOCIE\\FW\\ESP32_SHT85\\fonctionsSD.ino"
void listDir(fs::FS &fs, const char * dirname, uint8_t levels);
#line 33 "D:\\Documents\\GitHub\\SHT85-LOCIE\\FW\\ESP32_SHT85\\fonctionsSD.ino"
void delAllFile(fs::FS &fs, const char * dirname, uint8_t levels);
#line 66 "D:\\Documents\\GitHub\\SHT85-LOCIE\\FW\\ESP32_SHT85\\fonctionsSD.ino"
void createDir(fs::FS &fs, const char * path);
#line 75 "D:\\Documents\\GitHub\\SHT85-LOCIE\\FW\\ESP32_SHT85\\fonctionsSD.ino"
void removeDir(fs::FS &fs, const char * path);
#line 84 "D:\\Documents\\GitHub\\SHT85-LOCIE\\FW\\ESP32_SHT85\\fonctionsSD.ino"
void readFile(fs::FS &fs, const char * path);
#line 100 "D:\\Documents\\GitHub\\SHT85-LOCIE\\FW\\ESP32_SHT85\\fonctionsSD.ino"
void writeFile(fs::FS &fs, const char * path, const char * message);
#line 116 "D:\\Documents\\GitHub\\SHT85-LOCIE\\FW\\ESP32_SHT85\\fonctionsSD.ino"
void appendFile(fs::FS &fs, const char * path, const char * message);
#line 132 "D:\\Documents\\GitHub\\SHT85-LOCIE\\FW\\ESP32_SHT85\\fonctionsSD.ino"
void renameFile(fs::FS &fs, const char * path1, const char * path2);
#line 141 "D:\\Documents\\GitHub\\SHT85-LOCIE\\FW\\ESP32_SHT85\\fonctionsSD.ino"
void deleteFile(fs::FS &fs, const char * path);
#line 150 "D:\\Documents\\GitHub\\SHT85-LOCIE\\FW\\ESP32_SHT85\\fonctionsSD.ino"
void testFileIO(fs::FS &fs, const char * path);
#line 1 "D:\\Documents\\GitHub\\SHT85-LOCIE\\FW\\ESP32_SHT85\\sensors.ino"
String SHTtoJSON(String C, double T, double HR);
#line 15 "D:\\Documents\\GitHub\\SHT85-LOCIE\\FW\\ESP32_SHT85\\sensors.ino"
String ArrayStatusSHTtoJSON();
#line 38 "D:\\Documents\\GitHub\\SHT85-LOCIE\\FW\\ESP32_SHT85\\sensors.ino"
String ArraySHTtoJSON(String C[], double T[], double HR[], int n );
#line 63 "D:\\Documents\\GitHub\\SHT85-LOCIE\\FW\\ESP32_SHT85\\sensors.ino"
void readSHT();
#line 117 "D:\\Documents\\GitHub\\SHT85-LOCIE\\FW\\ESP32_SHT85\\sensors.ino"
void initSHT();
#line 151 "D:\\Documents\\GitHub\\SHT85-LOCIE\\FW\\ESP32_SHT85\\sensors.ino"
void tcaselect(uint8_t i, int d1);
#line 1 "D:\\Documents\\GitHub\\SHT85-LOCIE\\FW\\ESP32_SHT85\\serialCOM.ino"
void SerialCOM();
#line 201 "D:\\Documents\\GitHub\\SHT85-LOCIE\\FW\\ESP32_SHT85\\serialCOM.ino"
void serialEvent();
#line 20 "D:\\Documents\\GitHub\\SHT85-LOCIE\\FW\\ESP32_SHT85\\ESP32_SHT85.ino"
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
    versionFW = versionFW + " USB + WIFI";
    Serial.println("WIFI ENABLE");
  } else if (nSelected == "ETH"){
    NetworkSelect = 2;
    versionFW = versionFW + " USB + ETHERNET";
    Serial.println("ETH ENABLE");
  } else {
    NetworkSelect = 0;
    versionFW = versionFW + " USB ONLY";
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

#line 1 "D:\\Documents\\GitHub\\SHT85-LOCIE\\FW\\ESP32_SHT85\\ServeurWeb.ino"
void setupNetwork() {

  switch (NetworkSelect) {
    case 1:
      setupWifi();
      
      break;
    case 2:
      setupEth();
      break;
    default:
      // statements
      break;
  }



}

void serveurWeb() {
  switch (NetworkSelect) {
    case 1:
      serveurWebWifi();
      break;
    case 2:
      serveurWebEth();
      break;
    default:
      // statements
      break;
  }
}



void setupEth() {
  Ethernet.init(33);  // ESP32 with Adafruit Featherwing Ethernet

  Ethernet.begin(macAdresse, local_IP, gateway, gateway, subnet); //local_IP, gateway, subnet

  // Check for Ethernet hardware present
  if (Ethernet.hardwareStatus() == EthernetNoHardware) {
    Serial.println("Ethernet shield was not found.  Sorry, can't run without hardware. :(");
    while (true) {
      delay(1); // do nothing, no point running without Ethernet hardware
    }
  }
  if (Ethernet.linkStatus() == LinkOFF) {
    Serial.println("Ethernet cable is not connected.");
  }

  // start the server
  serverEth.begin();
  Serial.print("server is at ");
  Serial.println(Ethernet.localIP());
}

void serveurWebEth() {
  EthernetClient clientEth = serverEth.available();
  
  if (clientEth) {
    Serial.println("===      New Client ETH     ===");
    String currentLine = "";
    while (clientEth.connected()) {
      if (clientEth.available()) {
        char c = clientEth.read();             // read a byte, then
        if (c == '\n') {
          if (currentLine.length() == 0) {
            break;
          } else {    // if you got a newline, then clear currentLine:
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }

        // Check to see the client request
        if (currentLine.endsWith("GET /config")) {
          clientEth.println("HTTP/1.1 200 OK");
          clientEth.println("Content-type:text/html");
          clientEth.println();
          clientEth.println("{\"boxName\":\"" + boxName + "\",\"version\":\"" + versionFW + "\",\"SHT-Type\":\"" + capteurType + "\",\"nbSHT\":" + nbCapteur + "}");
          clientEth.println();
        } else if (currentLine.endsWith("GET /read")) {
          clientEth.println("HTTP/1.1 200 OK");
          clientEth.println("Content-type:text/html");
          clientEth.println();
          clientEth.println(ArraySHTtoJSON(Capteur, Temperature, Humidity, nbCapteur));
          clientEth.println();
        } else if (currentLine.endsWith("GET /status")) {
          clientEth.println("HTTP/1.1 200 OK");
          clientEth.println("Content-type:text/html");
          clientEth.println();
          clientEth.println(ArrayStatusSHTtoJSON());
          clientEth.println();
        } else if (currentLine.endsWith("GET /rst")) {
          clientEth.println("HTTP/1.1 200 OK");
          clientEth.println("Content-type:text/html");
          clientEth.println();
          clientEth.println("RESET");
          Serial.println("Rebooting");
          clientEth.println();
          digitalWrite(13, HIGH);
          delay(1000);
          ESP.restart();
        }
      }
    }
    // give the web browser time to receive the data
    delay(1);
    // close the connection:
    clientEth.stop();
    Serial.println("=== Client ETH Disconnected ===");
  }
}

void setupWifi() {
  Serial.print("Connecting to ");
  Serial.println(ssid);


  if (!WiFi.config(local_IP, gateway, subnet)) {
    Serial.println("STA Failed to configure");
  }
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());


  server.begin();
}

void serveurWebWifi() {
  WiFiClient client = server.available();   // listen for incoming clients

  if (client) {                             // if you get a client,
    Serial.println("===      New Client     ===");
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected()) {            // loop while the client's connected
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        if (c == '\n') {
          if (currentLine.length() == 0) {
            break;
          } else {    // if you got a newline, then clear currentLine:
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }

        // Check to see the client request
        if (currentLine.endsWith("GET /config")) {
          client.println("HTTP/1.1 200 OK");
          client.println("Content-type:text/html");
          client.println();
          client.println("{\"boxName\":\"" + boxName + "\",\"version\":\"" + versionFW + "\",\"SHT-Type\":\"" + capteurType + "\",\"nbSHT\":" + nbCapteur + "}");
          client.println();
        } else if (currentLine.endsWith("GET /read")) {
          client.println("HTTP/1.1 200 OK");
          client.println("Content-type:text/html");
          client.println();
          client.println(ArraySHTtoJSON(Capteur, Temperature, Humidity, nbCapteur));
          client.println();
        } else if (currentLine.endsWith("GET /status")) {
          client.println("HTTP/1.1 200 OK");
          client.println("Content-type:text/html");
          client.println();
          client.println(ArrayStatusSHTtoJSON());
          client.println();
        } else if (currentLine.endsWith("GET /rst")) {
          client.println("HTTP/1.1 200 OK");
          client.println("Content-type:text/html");
          client.println();
          client.println("RESET");
          Serial.println("Rebooting");
          client.println();
          digitalWrite(13, HIGH);
          delay(1000);
          ESP.restart();
        }
      }
    }
    // close the connection:
    client.stop();
    Serial.println("=== Client Disconnected ===");

  }
}

#line 1 "D:\\Documents\\GitHub\\SHT85-LOCIE\\FW\\ESP32_SHT85\\configOnSD.ino"
void loadConfigFile() {
  didReadConfig = false;

  // Setup the SD card
  Serial.println("Calling SD.begin()...");
  if (!SD.begin(pinSelectSD)) {
    Serial.println("SD.begin() failed.");
    Serial.println("Rebooting");
    ESP.restart();
    return;
  }
  Serial.println("... succeeded.");

  // Read our configuration from the SD card file.
  didReadConfig = readConfiguration();
  if (didReadConfig) {
    Serial.println("===== Config file OK =====");
  }

}

boolean readConfiguration() {
  /*
     Length of the longest line expected in the config file.
     The larger this number, the more memory is used
     to read the file.
     You probably won't need to change this number.
  */
  const uint8_t CONFIG_LINE_LENGTH = 127;

  // The open configuration file.
  SDConfigFile cfg;
  SDConfigFile cfgSensors;

  // Open the configuration file.
  if (!cfg.begin(CONFIG_FILE, CONFIG_LINE_LENGTH)) {
    Serial.print("Failed to open configuration file: ");
    Serial.println(CONFIG_FILE);
    return false;
  }

  // Read each setting from the file.
  while (cfg.readNextSetting()) {

    // Put a nameIs() block here for each setting you have.

    if (cfg.nameIs("ssid")) {
      ssid = cfg.copyValue();//cfg.getBooleanValue();
      Serial.print("Read ssid: ");
      Serial.println(ssid);

    } else if (cfg.nameIs("network")) {
      network = cfg.copyValue();//cfg.getBooleanValue();
      Serial.print("Read network: ");
      Serial.println(network);

    } else if (cfg.nameIs("password")) {
      password = cfg.copyValue();//cfg.getBooleanValue();
      Serial.print("Read password: ");
      Serial.println(password);

    } else if (cfg.nameIs("boxName")) {
      boxName = cfg.copyValue();//cfg.getBooleanValue();
      Serial.print("Read boxName: ");
      Serial.println(boxName);

    } else if (cfg.nameIs("capteurType")) {
      capteurType = cfg.copyValue();//cfg.getBooleanValue();
      Serial.print("Read capteurType: ");
      Serial.println(capteurType);

    } else if (cfg.nameIs("versionFW")) {
      versionFW = cfg.copyValue();//cfg.getBooleanValue();
      Serial.print("Read versionFW: ");
      Serial.println(versionFW);

    } else if (cfg.nameIs("IP")) {
      IP = cfg.copyValue();//cfg.getBooleanValue();
      Serial.print("Read IP: ");
      Serial.println(IP);

    } else if (cfg.nameIs("Passerel")) {
      Passerel = cfg.copyValue();//cfg.getBooleanValue();
      Serial.print("Read Passerel: ");
      Serial.println(Passerel);

    } else if (cfg.nameIs("Masque")) {
      Masque = cfg.copyValue();//cfg.getBooleanValue();
      Serial.print("Read Masque: ");
      Serial.println(Masque);

    } else if (cfg.nameIs("MAC")) {
      MAC = cfg.copyValue();//cfg.getBooleanValue();
      Serial.print("Read MAC: ");
      Serial.println(MAC);

    } else {
      // report unrecognized names.
      Serial.print("Unknown name in config: ");
      Serial.println(cfg.getName());
    }
  }



  // clean up
  cfg.end();

  // Open the sensors file.
  if (!cfgSensors.begin(SENSORS_FILE, CONFIG_LINE_LENGTH)) {
    Serial.print("Failed to open configuration file: ");
    Serial.println(SENSORS_FILE);
    return false;
  }

  while (cfgSensors.readNextSetting()) {

    // Put a nameIs() block here for each setting you have.

    if (cfgSensors.nameIs("SHT1")) {
      Capteur[0] = cfgSensors.copyValue();//cfg.getBooleanValue();
      Serial.print("Read SHT1: ");
      Serial.println(Capteur[0]);

    } else if (cfgSensors.nameIs("SHT2")) {
      Capteur[1] = cfgSensors.copyValue();//cfg.getBooleanValue();
      Serial.print("Read SHT2: ");
      Serial.println(Capteur[1]);

    } else if (cfgSensors.nameIs("SHT3")) {
      Capteur[2] = cfgSensors.copyValue();//cfg.getBooleanValue();
      Serial.print("Read SHT3: ");
      Serial.println(Capteur[2]);

    } else if (cfgSensors.nameIs("SHT4")) {
      Capteur[3] = cfgSensors.copyValue();//cfg.getBooleanValue();
      Serial.print("Read SHT4: ");
      Serial.println(Capteur[3]);

    } else if (cfgSensors.nameIs("SHT5")) {
      Capteur[4] = cfgSensors.copyValue();//cfg.getBooleanValue();
      Serial.print("Read SHT5: ");
      Serial.println(Capteur[4]);

    } else if (cfgSensors.nameIs("SHT6")) {
      Capteur[5] = cfgSensors.copyValue();//cfg.getBooleanValue();
      Serial.print("Read SHT6: ");
      Serial.println(Capteur[5]);

    } else if (cfgSensors.nameIs("SHT7")) {
      Capteur[6] = cfgSensors.copyValue();//cfg.getBooleanValue();
      Serial.print("Read SHT7: ");
      Serial.println(Capteur[6]);

    } else if (cfgSensors.nameIs("SHT8")) {
      Capteur[7] = cfgSensors.copyValue();//cfg.getBooleanValue();
      Serial.print("Read SHT8: ");
      Serial.println(Capteur[7]);

    } else if (cfgSensors.nameIs("SHT9")) {
      Capteur[8] = cfgSensors.copyValue();//cfg.getBooleanValue();
      Serial.print("Read SHT9: ");
      Serial.println(Capteur[8]);

    } else if (cfgSensors.nameIs("SHT10")) {
      Capteur[9] = cfgSensors.copyValue();//cfg.getBooleanValue();
      Serial.print("Read SHT10: ");
      Serial.println(Capteur[9]);

    } else if (cfgSensors.nameIs("SHT11")) {
      Capteur[10] = cfgSensors.copyValue();//cfg.getBooleanValue();
      Serial.print("Read SHT11: ");
      Serial.println(Capteur[10]);

    } else if (cfgSensors.nameIs("SHT12")) {
      Capteur[11] = cfgSensors.copyValue();//cfg.getBooleanValue();
      Serial.print("Read SHT12: ");
      Serial.println(Capteur[11]);

    } else if (cfgSensors.nameIs("SHT13")) {
      Capteur[12] = cfgSensors.copyValue();//cfg.getBooleanValue();
      Serial.print("Read SHT13: ");
      Serial.println(Capteur[12]);

    } else if (cfgSensors.nameIs("SHT14")) {
      Capteur[13] = cfgSensors.copyValue();//cfg.getBooleanValue();
      Serial.print("Read SHT14: ");
      Serial.println(Capteur[13]);

    } else if (cfgSensors.nameIs("SHT15")) {
      Capteur[14] = cfgSensors.copyValue();//cfg.getBooleanValue();
      Serial.print("Read SHT15: ");
      Serial.println(Capteur[14]);

    } else if (cfgSensors.nameIs("SHT16")) {
      Capteur[15] = cfgSensors.copyValue();//cfg.getBooleanValue();
      Serial.print("Read SHT16: ");
      Serial.println(Capteur[15]);

    } else {
      // report unrecognized names.
      Serial.print("Unknown name in config: ");
      Serial.println(cfgSensors.getName());
    }
  }
  // clean up
  cfgSensors.end();
  return true;
}

void writeConfigFile() {
  /*Serial.println(ssid);
    Serial.println(password);
    Serial.println(boxName);
    Serial.println(capteurType);
    Serial.println(versionFW);
    Serial.println(IP);
    Serial.println(Passerel);
    Serial.println(Masque);
    Serial.println(MAC);*/

  deleteFile(SD, CONFIG_FILE);
  writeFile(SD, CONFIG_FILE, "");
  //Box Name
  appendFile(SD, CONFIG_FILE, "boxName=");
  char boxNamecopy[50];
  boxName.toCharArray(boxNamecopy, 50);
  appendFile(SD, CONFIG_FILE, boxNamecopy);
  appendFile(SD, CONFIG_FILE, "\n");
  //Capteur type
  appendFile(SD, CONFIG_FILE, "capteurType=");
  char capteurTypecopy[50];
  capteurType.toCharArray(capteurTypecopy, 50);
  appendFile(SD, CONFIG_FILE, capteurTypecopy);
  appendFile(SD, CONFIG_FILE, "\n");
  //network
  appendFile(SD, CONFIG_FILE, "network=");
  char networkcopy[50];
  //network.toCharArray(networkcopy, 50);
  appendFile(SD, CONFIG_FILE, network);
  appendFile(SD, CONFIG_FILE, "\n");
  //IP
  appendFile(SD, CONFIG_FILE, "IP=");
  appendFile(SD, CONFIG_FILE, IP);
  appendFile(SD, CONFIG_FILE, "\n");
  //GW
  appendFile(SD, CONFIG_FILE, "Passerel=");
  appendFile(SD, CONFIG_FILE, Passerel);
  appendFile(SD, CONFIG_FILE, "\n");
  //Mask
  appendFile(SD, CONFIG_FILE, "Masque=");
  appendFile(SD, CONFIG_FILE, Masque);
  appendFile(SD, CONFIG_FILE, "\n");
  //MAC
  appendFile(SD, CONFIG_FILE, "MAC=");
  appendFile(SD, CONFIG_FILE, MAC);
  appendFile(SD, CONFIG_FILE, "\n");
  //SSID
  appendFile(SD, CONFIG_FILE, "ssid=");
  appendFile(SD, CONFIG_FILE, ssid);
  appendFile(SD, CONFIG_FILE, "\n");
  //Wifi Password
  appendFile(SD, CONFIG_FILE, "password=");
  appendFile(SD, CONFIG_FILE, password);
  appendFile(SD, CONFIG_FILE, "\n");
  //FW Version
  /*appendFile(SD, CONFIG_FILE, "versionFW=");
    char versionFWcopy[50];
    versionFW.toCharArray(versionFWcopy, 50);
    appendFile(SD, CONFIG_FILE, versionFWcopy);
    appendFile(SD, CONFIG_FILE, "\n");*/



  readFile(SD, CONFIG_FILE);
}

void writeSensorFile() {
  deleteFile(SD, SENSORS_FILE);
  writeFile(SD, SENSORS_FILE, "");
  for (int i = 0; i < 16; i++) {
    String sensorID = String(i + 1);
    char sensorIDcopy[50];
    sensorID.toCharArray(sensorIDcopy, 50);

    char Capteurcopy[50];
    Capteur[i].toCharArray(Capteurcopy, 50);

    appendFile(SD, SENSORS_FILE, "SHT");
    appendFile(SD, SENSORS_FILE, sensorIDcopy);
    appendFile(SD, SENSORS_FILE, "=");
    appendFile(SD, SENSORS_FILE, Capteurcopy);
    appendFile(SD, SENSORS_FILE, "\n");
  }
  readFile(SD, SENSORS_FILE);
}

#line 1 "D:\\Documents\\GitHub\\SHT85-LOCIE\\FW\\ESP32_SHT85\\core1.ino"
void loop() {
  digitalWrite(13, LOW);
  xSemaphoreTake( baton, portMAX_DELAY );
  serveurWeb();
  SerialCOM();
  xSemaphoreGive( baton );
}

#line 1 "D:\\Documents\\GitHub\\SHT85-LOCIE\\FW\\ESP32_SHT85\\core2.ino"
void codeForTask2( void * parameter )
{
  for (;;) {
    xSemaphoreTake( baton, portMAX_DELAY );
    //Serial.println("readSHT");
    //unsigned long currentMillis = millis();
    //if ((unsigned long)(currentMillis - previousMillisSHT) >= ReadDelayLoop) {
      
      readSHT ();
      //previousMillisSHT = currentMillis;
    
    
    /*if ((unsigned long)(currentMillis - previousMillisSD) >= DatalogDelayLoop) {
      //Write DATA to SD
      previousMillisSHT = currentMillis;
    }*/
    xSemaphoreGive( baton );
    delay(ReadDelayLoop);
  }
}

#line 1 "D:\\Documents\\GitHub\\SHT85-LOCIE\\FW\\ESP32_SHT85\\datalogger.ino"
void datalogger(){
  delay(10);
}

#line 1 "D:\\Documents\\GitHub\\SHT85-LOCIE\\FW\\ESP32_SHT85\\fonctions.ino"
//Fonctions

void setupCore() {
  baton = xSemaphoreCreateMutex();
  /*xTaskCreatePinnedToCore(
    codeForTask1,
    "network",
    2000,
    NULL,
    1,
    &Task1,
    0
    );*/

  //delay(500);  // needed to start-up task1

  xTaskCreatePinnedToCore(
    codeForTask2,
    "sensor",
    3000,
    NULL,
    1,
    &Task2,
    1
  );
}


void pinSetup() {
  pinMode(13, OUTPUT);
  //MUX
  pinMode(14, OUTPUT);
  pinMode(32, OUTPUT);

  pinMode(pinSelectSD, OUTPUT);
  pinMode(pinSelectETH, OUTPUT);

  digitalWrite(13, HIGH);

  //MUX
  digitalWrite(14, HIGH);
  digitalWrite(32, LOW);
  MUX = false;

}

void endSetup() {
  digitalWrite(13, HIGH);
  delay(200);
  digitalWrite(13, LOW);
  delay(250);
  digitalWrite(13, HIGH);
  delay(200);
  digitalWrite(13, LOW);
  delay(250);
  digitalWrite(13, HIGH);
  delay(200);
  digitalWrite(13, LOW);
  delay(250);
}

void artificialLoad () {
  randomSeed(0);
  randomMes = double(random(0, 1000)) / 1000;
  for (int i = 0; i < nbCapteur ; i++) {
    Capteur[i] = "SHT " + String(i + 1);
    Temperature[i] = randomMes * 24.5 + i;
    Humidity[i] = randomMes * 53.2 - i;
  }
}

float average (unsigned long * array, int len)  // assuming array is int.
{
  long sum = 0L ;  // sum will be larger than an item, long for safety.
  for (int i = 0 ; i < len ; i++)
    sum += array [i] ;
  return  ((float) sum) / len ;  // average will be fractional, so float may be appropriate.
}

#line 1 "D:\\Documents\\GitHub\\SHT85-LOCIE\\FW\\ESP32_SHT85\\fonctionsSD.ino"

void listDir(fs::FS &fs, const char * dirname, uint8_t levels) {
  Serial.printf("Listing directory: %s\n", dirname);

  File root = fs.open(dirname);
  if (!root) {
    Serial.println("Failed to open directory");
    return;
  }
  if (!root.isDirectory()) {
    Serial.println("Not a directory");
    return;
  }

  File file = root.openNextFile();
  while (file) {
    if (file.isDirectory()) {
      Serial.print("  DIR : ");
      Serial.println(file.name());
      if (levels) {
        listDir(fs, file.name(), levels - 1);
      }
    } else {
      Serial.print("  FILE: ");
      Serial.print(file.name());
      Serial.print("  SIZE: ");
      Serial.println(file.size());
    }
    file = root.openNextFile();
  }
}

void delAllFile(fs::FS &fs, const char * dirname, uint8_t levels) {
  Serial.printf("Listing directory: %s\n", dirname);

  File root = fs.open(dirname);
  if (!root) {
    Serial.println("Failed to open directory");
    return;
  }
  if (!root.isDirectory()) {
    Serial.println("Not a directory");
    return;
  }

  File file = root.openNextFile();
  while (file) {
    if (file.isDirectory()) {
      Serial.print("  DIR : ");
      Serial.println(file.name());
      if (levels) {
        listDir(fs, file.name(), levels - 1);
      }
    } else {

      Serial.print("DEL  FILE: ");
      Serial.print(file.name());
      Serial.print("  SIZE: ");
      Serial.println(file.size());
      deleteFile(fs, file.name());
    }
    file = root.openNextFile();
  }
}

void createDir(fs::FS &fs, const char * path) {
  Serial.printf("Creating Dir: %s\n", path);
  if (fs.mkdir(path)) {
    Serial.println("Dir created");
  } else {
    Serial.println("mkdir failed");
  }
}

void removeDir(fs::FS &fs, const char * path) {
  Serial.printf("Removing Dir: %s\n", path);
  if (fs.rmdir(path)) {
    Serial.println("Dir removed");
  } else {
    Serial.println("rmdir failed");
  }
}

void readFile(fs::FS &fs, const char * path) {
  Serial.printf("Reading file: %s\n", path);

  File file = fs.open(path);
  if (!file) {
    Serial.println("Failed to open file for reading");
    return;
  }

  Serial.print("Read from file: ");
  while (file.available()) {
    Serial.write(file.read());
  }
  file.close();
}

void writeFile(fs::FS &fs, const char * path, const char * message) {
  Serial.printf("Writing file: %s\n", path);

  File file = fs.open(path, FILE_WRITE);
  if (!file) {
    Serial.println("Failed to open file for writing");
    return;
  }
  if (file.print(message)) {
    Serial.println("File written");
  } else {
    Serial.println("Write failed");
  }
  file.close();
}

void appendFile(fs::FS &fs, const char * path, const char * message) {
  Serial.printf("Appending to file: %s\n", path);

  File file = fs.open(path, FILE_APPEND);
  if (!file) {
    Serial.println("Failed to open file for appending");
    return;
  }
  if (file.print(message)) {
    Serial.println("Message appended");
  } else {
    Serial.println("Append failed");
  }
  file.close();
}

void renameFile(fs::FS &fs, const char * path1, const char * path2) {
  Serial.printf("Renaming file %s to %s\n", path1, path2);
  if (fs.rename(path1, path2)) {
    Serial.println("File renamed");
  } else {
    Serial.println("Rename failed");
  }
}

void deleteFile(fs::FS &fs, const char * path) {
  Serial.printf("Deleting file: %s\n", path);
  if (fs.remove(path)) {
    Serial.println("File deleted");
  } else {
    Serial.println("Delete failed");
  }
}

void testFileIO(fs::FS &fs, const char * path) {
  File file = fs.open(path);
  static uint8_t buf[512];
  size_t len = 0;
  uint32_t start = millis();
  uint32_t end = start;
  if (file) {
    len = file.size();
    size_t flen = len;
    start = millis();
    while (len) {
      size_t toRead = len;
      if (toRead > 512) {
        toRead = 512;
      }
      file.read(buf, toRead);
      len -= toRead;
    }
    end = millis() - start;
    Serial.printf("%u bytes read for %u ms\n", flen, end);
    file.close();
  } else {
    Serial.println("Failed to open file for reading");
  }


  file = fs.open(path, FILE_WRITE);
  if (!file) {
    Serial.println("Failed to open file for writing");
    return;
  }

  size_t i;
  start = millis();
  for (i = 0; i < 2048; i++) {
    file.write(buf, 512);
  }
  end = millis() - start;
  Serial.printf("%u bytes written for %u ms\n", 2048 * 512, end);
  file.close();
}

#line 1 "D:\\Documents\\GitHub\\SHT85-LOCIE\\FW\\ESP32_SHT85\\sensors.ino"
String SHTtoJSON(String C, double T, double HR) {
  String jsonChain;
  jsonChain += "{";
  jsonChain += "\"Capteur\":\"";
  jsonChain += C;
  jsonChain += "\",\"Temp\":";
  jsonChain += T;
  jsonChain += ", \"RH\":";
  jsonChain += HR;
  jsonChain += "}";

  return jsonChain;
}

String ArrayStatusSHTtoJSON () {
  String jsonChain;
  jsonChain = "[";
  for (int i = 0; i < 15; i++) {
    if (initStatus[i]) {
      jsonChain += "{\"Capteur\":\"" + Capteur[i] + "\",\"Status\":true}";
    } else {
      jsonChain += "{\"Capteur\":\"" + Capteur[i] + "\",\"Status\":false}";
    }
    jsonChain += ",";
  }
  if (initStatus[15]) {
    jsonChain += "{\"Capteur\":\"" + Capteur[15] + "\",\"Status\":true}";
  } else {
    jsonChain += "{\"Capteur\":\"" + Capteur[15] + "\",\"Status\":false}";
  }
  //jsonChain += "{\"Capteur\":\"" + Capteur[15] + "\",\"Status\":" + initStatus[15] + "}";

  jsonChain += "]";

  return jsonChain;
}

String ArraySHTtoJSON(String C[], double T[], double HR[], int n ) {
  if (sizeof(T) / sizeof(T[0]) == sizeof(HR) / sizeof(HR[0])) {
    int nbc = n;
    String jsonChain;

    jsonChain = "[";
    if ( nbc > 1) {
      for (int i = 0; i < nbc - 1; i++) {
        jsonChain += SHTtoJSON(C[i], T[i], HR[i]);
        jsonChain += ",";
      }
    }
    jsonChain += SHTtoJSON(C[nbc - 1], T[nbc - 1], HR[nbc - 1]);

    jsonChain += "]";
    //Serial.println(randomMes);
    //SHTtoJSON = jsonChain;
    //Serial.println(jsonChain);
    return jsonChain;
  }
  else {
    return "[ERROR]";
  }
}

void readSHT () {
  digitalWrite(13, HIGH);
  prevTime = millis();
  //Serial.println();
  Serial.println("\nSHT Read");
  for (int i = 0; i < nbCapteur ; i++) {

    //Capteur[i] = "SHT " + String(i + 1);
    tcaselect(i, MUXDelay);
    //if (initStatus[i]) {
    boolean readStatus = true;
    prevTimeSHT = millis();
    while (!sht[i].readSample()) {
      //Humidity[i] = -1;
      //Temperature[i] = -1;
      if ((millis() - prevTimeSHT) > ReadDelay) {
        //Serial.println("SHT" + String(i + 1) + " Fail");
        //readStatus = false;
        break;
        initStatus[i] = false;
      } else {
        initStatus[i] = true;
      }
    }
    //if (readStatus) {
    Humidity[i] = sht[i].getHumidity();
    Temperature[i] = sht[i].getTemperature();
    //Serial.println("SHT" + String(i + 1) + " OK");
    //}
    /*    if (!sht[i].readSample()) {
          Humidity[i] = -1;
          Temperature[i] = -1;
          //if ((millis() - prevTimeSHT) > ReadDelay) {
          Serial.println("SHT" + String(i) + " Fail");
          //break;
          //}
        } else  {
          Humidity[i] = sht[i].getHumidity();
          Temperature[i] = sht[i].getTemperature();
          Serial.println("SHT" + String(i) + " OK");
        }
    */
    //Serial.println("SHT" + String(i + 1) + " RH=" + Humidity[i] + " Temp=" + Temperature[i]);
    SensorReadTime[i][k] = (millis() - prevTimeSHT);
    //Serial.print(String(SensorReadTime[i][k]) + " ");
  }
  //currTime = millis();
  SHTreadTime[k] = millis() - prevTime;
  //Serial.println(SHTreadTime[k]);

  digitalWrite(13, LOW);

}

void initSHT () {
  for (int i = 0; i < nbCapteur ; i++) {
    tcaselect(i, initMUXDelay);

    //boolean initStat = sht[i].init();
    //delay(100);
    if (sht[i].init()) {
      initStatus[i] = true;
      //Serial.print("SHT" + String(i + 1) + " init(): success\n");
    } else {
      initStatus[i] = false;
      Serial.print("SHT" + String(i + 1) + " init(): failed\n");
    }
    sht[i].setAccuracy(SHTSensor::SHT_ACCURACY_HIGH);

    prevTimeSHT = millis();
    boolean readStatus = true;
    while (!sht[i].readSample()) {
      //Humidity[i] = -1;
      //Temperature[i] = -1;
      if ((millis() - prevTimeSHT) > initReadDelay) {
        //Serial.println("SHT" + String(i + 1) + " Fail");
        //readStatus = false;
        break;
      }
    }
    //if (readStatus) {
    Humidity[i] = sht[i].getHumidity();
    Temperature[i] = sht[i].getTemperature();
    //Serial.println("SHT" + String(i + 1) + " Init OK");
    //}
  }
}

void tcaselect(uint8_t i, int d1) {
  if (i > 15) {
    return;
  } else if (i > 7) {
    i = i - 8;
    if (!MUX) {
      digitalWrite(14, LOW);
      digitalWrite(32, HIGH);
      delay(d1);
      MUX = true;
      Serial.println();
    }
    Wire.beginTransmission(TCAADDR2);
  } else {
    if (MUX) {
      digitalWrite(14, HIGH);
      digitalWrite(32, LOW);
      delay(d1);
      MUX = false;
    }
    Wire.beginTransmission(TCAADDR1);
  }

  Wire.write(1 << i);
  Wire.endTransmission();

  delay(20);
}

#line 1 "D:\\Documents\\GitHub\\SHT85-LOCIE\\FW\\ESP32_SHT85\\serialCOM.ino"
void SerialCOM() {
  serialEvent();
  if (stringComplete) {
    //Serial.println(inputString);
    if (inputString == "READ?\n") {
      Serial.println(ArraySHTtoJSON(Capteur, Temperature, Humidity, nbCapteur));
    } else if (inputString == "CONFIG?\n") {
      Serial.println("{\"boxName\":\"" + boxName + "\",\"version\":\"" + versionFW + "\",\"SHT-Type\":\"" + capteurType + "\",\"nbSHT\":" + nbCapteur + "}");
    } else if ((inputString == "STATUS?\n")) {
      Serial.println(ArrayStatusSHTtoJSON());
    } else if ((inputString == "*RST\n")) {
      Serial.println("Rebooting");
      digitalWrite(13, HIGH);
      delay(1000);
      ESP.restart();
    } else if (inputString.startsWith("SET SHT")) {
      boolean ok = true;
      if (inputString.startsWith("SET SHT1=")) {
        Capteur[0] = inputString.substring(9);
        Capteur[0].trim();
        Serial.println("OK");
      } else if (inputString.startsWith("SET SHT2=")) {
        Capteur[1] = inputString.substring(9);
        Capteur[1].trim();
        Serial.println("OK");
      } else if (inputString.startsWith("SET SHT3=")) {
        Capteur[2] = inputString.substring(9);
        Capteur[2].trim();
        Serial.println("OK");
      } else if (inputString.startsWith("SET SHT4=")) {
        Capteur[3] = inputString.substring(9);
        Capteur[3].trim();
        Serial.println("OK");
      } else if (inputString.startsWith("SET SHT5=")) {
        Capteur[4] = inputString.substring(9);
        Capteur[4].trim();
        Serial.println("OK");
      } else if (inputString.startsWith("SET SHT6=")) {
        Capteur[5] = inputString.substring(9);
        Capteur[5].trim();
        Serial.println("OK");
      } else if (inputString.startsWith("SET SHT7=")) {
        Capteur[6] = inputString.substring(9);
        Capteur[6].trim();
        Serial.println("OK");
      } else if (inputString.startsWith("SET SHT8=")) {
        Capteur[7] = inputString.substring(9);
        Capteur[7].trim();
        Serial.println("OK");
      } else if (inputString.startsWith("SET SHT9=")) {
        Capteur[8] = inputString.substring(9);
        Capteur[8].trim();
        Serial.println("OK");
      } else if (inputString.startsWith("SET SHT10=")) {
        Capteur[9] = inputString.substring(10);
        Capteur[9].trim();
        Serial.println("OK");
      } else if (inputString.startsWith("SET SHT11=")) {
        Capteur[10] = inputString.substring(10);
        Capteur[10].trim();
        Serial.println("OK");
      } else if (inputString.startsWith("SET SHT12=")) {
        Capteur[11] = inputString.substring(10);
        Capteur[11].trim();
        Serial.println("OK");
      } else if (inputString.startsWith("SET SHT13=")) {
        Capteur[12] = inputString.substring(10);
        Capteur[12].trim();
        Serial.println("OK");
      } else if (inputString.startsWith("SET SHT14=")) {
        Capteur[13] = inputString.substring(10);
        Capteur[13].trim();
        Serial.println("OK");
      } else if (inputString.startsWith("SET SHT15=")) {
        Capteur[14] = inputString.substring(10);
        Capteur[14].trim();
        Serial.println("OK");
      } else if (inputString.startsWith("SET SHT16=")) {
        Capteur[15] = inputString.substring(10);
        Capteur[15].trim();
        Serial.println("OK");
      } else {
        Serial.println("NOK");
        ok = false;
      }
      if (ok) {
        writeSensorFile();
      }
    } else if (inputString.startsWith("SET READ=")) {
      inputString = inputString.substring(9);
      inputString.trim();
      ReadDelay = inputString.toInt();
    } else if (inputString.startsWith("SET MUX=")) {
      inputString = inputString.substring(8);
      inputString.trim();
      MUXDelay = inputString.toInt();
    } else if (inputString.startsWith("SET BOX")) {
      boolean ok = true;
      if (inputString.startsWith("SET BOXNAME=")) {
        boxName = inputString.substring(12);
        boxName.trim();
        Serial.println("OK");
      } else if (inputString.startsWith("SET BOXIP=")) {
        inputString = inputString.substring(10);
        inputString.trim();
        inputString.toCharArray(IP, 50);
        Serial.println("OK");
      } else if (inputString.startsWith("SET BOXGW=")) {
        inputString = inputString.substring(10);
        inputString.trim();
        inputString.toCharArray(Passerel, 50);
        Serial.println("OK");
      } else if (inputString.startsWith("SET BOXMASK=")) {
        inputString = inputString.substring(12);
        inputString.trim();
        inputString.toCharArray(Masque, 50);
        Serial.println("OK");
      } else if (inputString.startsWith("SET BOXMAC=")) {
        inputString = inputString.substring(11);
        inputString.trim();
        inputString.toCharArray(MAC, 50);
        Serial.println("OK");
      } else if (inputString.startsWith("SET BOXNETWORK=")) {
        inputString = inputString.substring(15);
        inputString.trim();
        inputString.toCharArray(network, 50);
        Serial.println("OK");
      } else {
        Serial.println("NOK");
        ok = false;
      }
      if (ok) {
        writeConfigFile();
      }
    } else if (inputString.startsWith("GET SHT")) {
      if (inputString.startsWith("GET SHT1")) {
        Serial.println(Capteur[0]);
      } else if (inputString.startsWith("GET SHT2")) {
        Serial.println(Capteur[1]);
      } else if (inputString.startsWith("GET SHT3")) {
        Serial.println(Capteur[2]);
      } else if (inputString.startsWith("GET SHT4")) {
        Serial.println(Capteur[3]);
      } else if (inputString.startsWith("GET SHT5")) {
        Serial.println(Capteur[4]);
      } else if (inputString.startsWith("GET SHT6")) {
        Serial.println(Capteur[5]);
      } else if (inputString.startsWith("GET SHT7")) {
        Serial.println(Capteur[6]);
      } else if (inputString.startsWith("GET SHT8")) {
        Serial.println(Capteur[7]);
      } else if (inputString.startsWith("GET SHT9")) {
        Serial.println(Capteur[8]);
      } else if (inputString.startsWith("GET SHT10")) {
        Serial.println(Capteur[9]);
      } else if (inputString.startsWith("GET SHT11")) {
        Serial.println(Capteur[10]);
      } else if (inputString.startsWith("GET SHT12")) {
        Serial.println(Capteur[11]);
      } else if (inputString.startsWith("GET SHT13")) {
        Serial.println(Capteur[12]);
      } else if (inputString.startsWith("GET SHT14")) {
        Serial.println(Capteur[13]);
      } else if (inputString.startsWith("GET SHT15")) {
        Serial.println(Capteur[14]);
      } else if (inputString.startsWith("GET SHT16")) {
        Serial.println(Capteur[15]);
      } else {
        Serial.println("NOK");
      }
    } else if (inputString.startsWith("GET READ")) {
      Serial.println(ReadDelay);
    } else if (inputString.startsWith("GET MUX")) {
      Serial.println(MUXDelay);
    } else if (inputString.startsWith("GET BOX")) {
      if (inputString.startsWith("GET BOXNAME")) {
        Serial.println(boxName);
      } else if (inputString.startsWith("GET BOXIP")) {
        Serial.println(IP);
      } else if (inputString.startsWith("GET BOXGW")) {
        Serial.println(Passerel);
      } else if (inputString.startsWith("GET BOXMASK")) {
        Serial.println(Masque);
      } else if (inputString.startsWith("GET BOXMAC")) {
        Serial.println(MAC);
      } else if (inputString.startsWith("GET BOXNETWORK")) {
        Serial.println(network);
      } else {
        Serial.println("NOK");
      }
    } else {
      Serial.println("NOK");
    }
    // clear the string:
    inputString = "";
    stringComplete = false;
  }

}

void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag so the main loop can
    // do something about it:
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
}

