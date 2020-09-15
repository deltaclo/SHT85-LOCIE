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
