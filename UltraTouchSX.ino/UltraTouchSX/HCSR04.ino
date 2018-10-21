/**
 * Abfragewerte in 10er Schritten (einfach) für HCSR04 Sensor
 * 
 * Es werden hier statische Werte von 0-127 als CC versendet.
 * Hier kann z.B.: der Masterregler angesprochen werden.
 */
void sensorAbfragen(byte triggerPin, byte echoPin, byte ctrlNummer) {
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(3);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);

  long sensorWert = pulseIn(echoPin, HIGH);

  if ( (sensorWert <= 2001) && (sensorWert >= 239)) {
    byte sensorMIDI = map(sensorWert, 240, 2000, 0, 127);

    if ( (sensorMIDI <= 6) && (sensorMIDI >= 0)) {
      sendeMIDI(191, 5, 0);
      /*Serial.print(sensorWert);
      Serial.print("  |0-4|  0");
      Serial.println();*/
    }
    if ( (sensorMIDI <= 11) && (sensorMIDI >= 6)) {
      sendeMIDI(191, 5, 10);
      /*Serial.print(sensorWert);
      Serial.print("  |5-11|  10");
      Serial.println();*/
    }
    if ( (sensorMIDI <= 21) && (sensorMIDI >= 11)) {
      sendeMIDI(191, 5, 20);
      /*Serial.print(sensorWert);
      Serial.print("  |11-21|  20");
      Serial.println();*/
    }
    if ( (sensorMIDI <= 31) && (sensorMIDI >= 21)) {
      sendeMIDI(191, 5, 30);
      /*Serial.print(sensorWert);
      Serial.print("  |21-30|  30");
      Serial.println();*/
    }
    if ( (sensorMIDI <= 41) && (sensorMIDI >= 31)) {
      sendeMIDI(191, 5, 40);
      /*Serial.print(sensorWert);
      Serial.print("  |31-41|  40");
      Serial.println();*/
    }
    if ( (sensorMIDI <= 51) && (sensorMIDI >= 41)) {
      sendeMIDI(191, 5, 50);
      /*Serial.print(sensorWert);
      Serial.print("  |41-51|  50");
      Serial.println();*/
    }
    if ( (sensorMIDI <= 61) && (sensorMIDI >= 51)) {
      sendeMIDI(191, 5, 60);
      /*Serial.print(sensorWert);
      Serial.print("  |51-61|  60");
      Serial.println();*/
    }
    if ( (sensorMIDI <= 71) && (sensorMIDI >= 61)) {
      sendeMIDI(191, 5, 70);
      /*Serial.print(sensorWert);
      Serial.print("  |61-71|  70");
      Serial.println();*/
    }
    if ( (sensorMIDI <= 81) && (sensorMIDI >= 71)) {
      sendeMIDI(191, 5, 80);
      /*Serial.print(sensorWert);
      Serial.print("  |71-81|  80");
      Serial.println();*/
    }
    if ( (sensorMIDI <= 91) && (sensorMIDI >= 81)) {
      sendeMIDI(191, 5, 90);
      /*Serial.print(sensorWert);
      Serial.print("  |81-91|  90");
      Serial.println();*/
    }
    if ( (sensorMIDI <= 101) && (sensorMIDI >= 91)) {
      sendeMIDI(191, 5, 100);
      /*Serial.print(sensorWert);
      Serial.print("  |91-101|  100");
      Serial.println();*/
    }
    if ( (sensorMIDI <= 115) && (sensorMIDI >= 101)) {
      sendeMIDI(191, 5, 110);
      /*Serial.print(sensorWert);
      Serial.print("  |101-115|  110");
      Serial.println();*/
    }
    if ( (sensorMIDI <= 128) && (sensorMIDI >= 115)) {
      sendeMIDI(191, 5, 127);
      /*Serial.print(sensorWert);
      Serial.print("  |115-128|  127");
      Serial.println();*/
    }
    //sendeMIDI(191, 5, sensorMIDI);
  }
}
