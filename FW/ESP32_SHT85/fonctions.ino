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
