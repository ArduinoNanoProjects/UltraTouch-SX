/**
 * Schaltet die LED rgb nach sein Farben an oder aus
 * und ermöglicht die Helligkeit festzulegen
 * 
 * Boden- und Deckenbeleuchtung
 * 
 * neo(255, 255, 255, 1);
 */
void NeoTop(int r, int g, int b){
  pixels.setPixelColor(0, pixels.Color(r,g,b));
  pixels.setPixelColor(1, pixels.Color(r,g,b));
  pixels.show();
  delay(1); 
}
void NeoBottom(int r, int g, int b){
  pixels.setPixelColor(4, pixels.Color(r,g,b));
  pixels.setPixelColor(3, pixels.Color(r,g,b));
  pixels.setPixelColor(2, pixels.Color(r,g,b));
  pixels.show();
  delay(1); 
}

void NeoBottomSwitch(int ColorSwitch){
  if (ColorSwitch == 1) {
    NeoBottom(0, Bridhness, 0); //grün 
  }
  if (ColorSwitch == 2) {
    NeoBottom(Bridhness/2+10, Bridhness, 0); //A grün
  }
  if (ColorSwitch == 3) {
    NeoBottom(Bridhness, (Bridhness/2+50), 0); //gelb
  }
  if (ColorSwitch == 4) {
    NeoBottom(Bridhness, (Bridhness / 2) - 60, 0); //orange
  }
  if (ColorSwitch == 5) {
    NeoBottom(Bridhness, 0, 0); //rot 
  }
  if (ColorSwitch == 6) {
    NeoBottom(Bridhness, 0, Bridhness); //pink 
  }
  if (ColorSwitch == 7) {
    NeoBottom((Bridhness/2)-10, 0, Bridhness); //lila
  }
  if (ColorSwitch == 8) {
    NeoBottom(0, 0, Bridhness); //blau 
  }
  if (ColorSwitch == 9) {
    NeoBottom(0, Bridhness, Bridhness); //h. blau 
  }
  if (ColorSwitch == 10) { //grün
    Colors = 1;
    NeoBottom(0, Bridhness, 0); 
  }
}

/**
 * Regenbogen der NeoPixel beim Starten des Arduinos
 */
void rainbowCycle(uint8_t wait) {
  uint16_t i, j;
  unsigned long ledMillis = 1;      // Blinkzeit
  int cycle = 5;                    // Wiederholungen

  for(j=0; j<256*cycle; j++) {
    for(i=0; i< pixels.numPixels(); i++) {
      pixels.setPixelColor(i, Wheel(((i * 256 / pixels.numPixels()) + j) & 255));
    }
    pixels.show();
    delay(5);
    if (millis() - ledMillis > wait)
    {
      ledMillis = millis();
    }
  }
}
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return pixels.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return pixels.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return pixels.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}
