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

  appendFile(SD, CONFIG_FILE, "ssid=");
  appendFile(SD, CONFIG_FILE, ssid);
  appendFile(SD, CONFIG_FILE, "\n");

  appendFile(SD, CONFIG_FILE, "password=");
  appendFile(SD, CONFIG_FILE, password);
  appendFile(SD, CONFIG_FILE, "\n");

  appendFile(SD, CONFIG_FILE, "boxName=");
  char boxNamecopy[50];
  boxName.toCharArray(boxNamecopy, 50);
  appendFile(SD, CONFIG_FILE, boxNamecopy);
  appendFile(SD, CONFIG_FILE, "\n");

  /*appendFile(SD, CONFIG_FILE, "capteurType=");
  char capteurTypecopy[50];
  capteurType.toCharArray(capteurTypecopy, 50);
  appendFile(SD, CONFIG_FILE, capteurTypecopy);
  appendFile(SD, CONFIG_FILE, "\n");*/

  /*appendFile(SD, CONFIG_FILE, "versionFW=");
  char versionFWcopy[50];
  versionFW.toCharArray(versionFWcopy, 50);
  appendFile(SD, CONFIG_FILE, versionFWcopy);
  appendFile(SD, CONFIG_FILE, "\n");*/

  appendFile(SD, CONFIG_FILE, "IP=");
  appendFile(SD, CONFIG_FILE, IP);
  appendFile(SD, CONFIG_FILE, "\n");

  appendFile(SD, CONFIG_FILE, "Passerel=");
  appendFile(SD, CONFIG_FILE, Passerel);
  appendFile(SD, CONFIG_FILE, "\n");

  appendFile(SD, CONFIG_FILE, "Masque=");
  appendFile(SD, CONFIG_FILE, Masque);
  appendFile(SD, CONFIG_FILE, "\n");

  appendFile(SD, CONFIG_FILE, "MAC=");
  appendFile(SD, CONFIG_FILE, MAC);
  appendFile(SD, CONFIG_FILE, "\n");

  readFile(SD, CONFIG_FILE);
}

void writeSensorFile() {
  deleteFile(SD, SENSORS_FILE);
  writeFile(SD, SENSORS_FILE, "");
  for (int i = 0; i < 16; i++) {
    String sensorID = String(i+1);
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
