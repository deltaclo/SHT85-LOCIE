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
