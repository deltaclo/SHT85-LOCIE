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
