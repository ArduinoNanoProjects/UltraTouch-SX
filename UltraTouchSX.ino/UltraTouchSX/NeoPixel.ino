/**
 * Schaltet die LED rgb nach sein Farben an oder aus
 * und ermöglicht die Helligkeit festzulegen
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

void AllPixel(int r, int g, int b){
  pixels.setPixelColor(0, pixels.Color(r,g,b));
  pixels.setPixelColor(1, pixels.Color(r,g,b));
  pixels.setPixelColor(4, pixels.Color(r,g,b));
  pixels.setPixelColor(3, pixels.Color(r,g,b));
  pixels.setPixelColor(2, pixels.Color(r,g,b));
  pixels.show();
  delay(1); 
}

/**
 * Test Rainbow
 */
void rainbowCycle(uint8_t wait) {
  uint16_t i, j;
  unsigned long ledMillis = 1;      // Zeit für den Blinkrythmus der LED
  int cycle = 5;

  for(j=0; j<256*cycle; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< pixels.numPixels(); i++) {
      pixels.setPixelColor(i, Wheel(((i * 256 / pixels.numPixels()) + j) & 255));
    }
    pixels.show();
    delay(5);
    if (millis() - ledMillis > wait)
    {
      ledMillis = millis();               // beginne die Zeitzählung von vorne
    }
  }
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
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
