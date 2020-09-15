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
