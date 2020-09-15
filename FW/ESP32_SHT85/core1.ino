void loop() {
  digitalWrite(13, LOW);
  xSemaphoreTake( baton, portMAX_DELAY );
  serveurWeb();
  SerialCOM();
  xSemaphoreGive( baton );
}
