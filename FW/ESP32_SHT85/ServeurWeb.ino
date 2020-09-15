void serveurWeb() {
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
