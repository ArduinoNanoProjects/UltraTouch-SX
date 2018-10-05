/**
 *   _   _  _  _                 _____                      _       _____ __   __
 *  | | | || || |               |_   _|                    | |     /  ___|\ \ / /
 *  | | | || || |_  _ __   __ _   | |    ___   _   _   ___ | |__   \ `--.  \ V / 
 *  | | | || || __|| '__| / _` |  | |   / _ \ | | | | / __|| '_ \   `--. \ /   \ 
 *  | |_| || || |_ | |   | (_| |  | |  | (_) || |_| || (__ | | | | /\__/ // /^\ \
 *   \___/ |_| \__||_|    \__,_|  \_/   \___/  \__,_| \___||_| |_| \____/ \/   \/                                                                          
 *   
 * 
 * Die Version der UltraTouch SX (Version 6) ist ausgestattet mit einem Nextion Display und sie versendet MIDI zur Nutzung 
 * der Räuspertasten. Sie kann vielseitig genutzt und erweitert werden ;)
 * 
 * Diese Projekt entstand im Rahmen des Ultraschall Projektes zum Themea: "MIDI Controller". Es gibt viele weitere Projekte 
 * von meinen Kollegen und der Community. Schaue doch mal vorbei: https://ultraschall.fm
 * 
 * @developer   Michael McCouman Jr.
 * @version     UT[SX] V6
 * @date        4.Okt 2018
 * @git:        https://github.com/McCouman
 * @website     https://wikibyte.org
 * 
 * Licence:     CC BY-NC-SA 4.0
 * Link:        https://creativecommons.org/licenses/by-nc-sa/4.0/deed.de
 *
**/

/*
 
   INFORMATIONEN ZUR LIZENZ:
   
   Diese Software steht unter CC BY-NC-SA 4.0 Lizenz: Namensnennung - Nicht-kommerziell - Weitergabe unter gleichen Bedingungen 
   4.0 International (CC BY-NC-SA 4.0). Dies ist eine allgemeinverständliche Zusammenfassung der Lizenz (die diese nicht ersetzt). 
   
   HAFTUNGSBESCHRÄNKUNG:
   
   Sie dürfen:
   - Teilen — das Material in jedwedem Format oder Medium vervielfältigen und weiterverbreiten
   - Bearbeiten — das Material remixen, verändern und darauf aufbauen
   - Der Lizenzgeber kann diese Freiheiten nicht widerrufen solange Sie sich an die Lizenzbedingungen halten.
   
   Unter folgenden Bedingungen:
   - Namensnennung — Sie müssen angemessene Urheber- und Rechteangaben machen, einen Link zur Lizenz beifügen und angeben, 
     ob Änderungen vorgenommen wurden. Diese Angaben dürfen in jeder angemessenen Art und Weise gemacht werden, allerdings 
     nicht so, dass der Eindruck entsteht, der Lizenzgeber unterstütze gerade Sie oder Ihre Nutzung besonders.
   
   - Nicht kommerziell — Sie dürfen das Material nicht für kommerzielle Zwecke nutzen.
   
   - Weitergabe unter gleichen Bedingungen — Wenn Sie das Material remixen, verändern oder anderweitig direkt darauf aufbauen, 
     dürfen Sie Ihre Beiträge nur unter derselben Lizenz wie das Original verbreiten.
   
   - Keine weiteren Einschränkungen — Sie dürfen keine zusätzlichen Klauseln oder technische Verfahren einsetzen, 
     die anderen rechtlich irgendetwas untersagen, was die Lizenz erlaubt.
   
   
   Hinweise:
   Sie müssen sich nicht an diese Lizenz halten hinsichtlich solcher Teile des Materials, die gemeinfrei sind, 
   oder soweit Ihre Nutzungshandlungen durch Ausnahmen und Schranken des Urheberrechts gedeckt sind. Es werden keine Garantien 
   gegeben und auch keine Gewähr geleistet. Die Lizenz verschafft Ihnen möglicherweise nicht alle Erlaubnisse, die Sie für die 
   jeweilige Nutzung brauchen. Es können beispielsweise andere Rechte wie Persönlichkeits- und Datenschutzrechte zu beachten sein, 
   die Ihre Nutzung des Materials entsprechend beschränken.
   
   Link:
   - https://creativecommons.org/licenses/by-nc-sa/4.0/deed.de

 * 
*/

// BIBLIOTHEK:
#include "Nextion.h"

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

// LED PIN:
#define LED         13   // OnBoard LED des Arduino Nanos
#define PIN         12   // Signal Pin für NeoPixel
#define NUMPIXELS    5   // Anzahl der NeoPixel

// VARS:
int Switch1 = HIGH;  // Speichert den Wert des MIDI-Schalters für Seiten 1
/*
int Switch2 = HIGH;  // Speichert den Wert des MIDI-Schalters für Seiten 2
int Switch3 = HIGH;  // Speichert den Wert des MIDI-Schalters für Seiten 3
int Switch4 = HIGH;  // Speichert den Wert des MIDI-Schalters für Seiten 4
*/
int Modus = 1;

// NEOPIXEL:
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);



/**
 * Deklaration der Obejekte für das Nextion-Display:
 * Bsp.: (page id = 0, component id = 1, component name = "b0")
*/
// PAGE 1:
//pPodcast1 (ID:1)
NexButton btn0pod1 = NexButton(1, 4, "btn0pod1");              // Button top/left
NexButton btn1pod1 = NexButton(1, 5, "btn1pod1");              // Button top/right
NexButton btn2pod1 = NexButton(1, 6, "btn2pod1");              // Button down/left
NexButton btn3pod1 = NexButton(1, 7, "btn3pod1");              // Button down/right
NexButton bMutePod1 = NexButton(1, 9, "bMutePod1");            // Mute Button
//pRadio1 (ID:2)
NexButton btn0radio1 = NexButton(2, 4, "btn0radio1");          // Button top/left
NexButton btn1radio1 = NexButton(2, 5, "btn1radio1");          // Button top/right
NexButton btn2radio1 = NexButton(2, 6, "btn2radio1");          // Button down/left
NexButton btn3radio1 = NexButton(2, 7, "btn3radio1");          // Button down/right
NexButton bMuteRadio1 = NexButton(2, 9, "bMuteRadio1");        // Unmute Button
//pSchalter1 (ID:3)
NexButton btn0switch1 = NexButton(3, 4, "btn0switch1");         // Button top/left
NexButton btn1switch1 = NexButton(3, 5, "btn1switch1");         // Button top/right
NexButton btn2switch1 = NexButton(3, 6, "btn2switch1");         // Button down/left
NexButton btn3switch1 = NexButton(3, 7, "btn3switch1");         // Button down/right
NexDSButton bMuteSwitch1 = NexDSButton(3, 9, "bMuteSwitch1");  // Mute/Unmute Switch

/*
// PAGE 2:
//pPodcast2 (ID:5)
NexButton btn0pod2 = NexButton(5, 4, "btn0pod2");              // Button top/left
NexButton btn1pod2 = NexButton(5, 5, "btn1pod2");              // Button top/right
NexButton btn2pod2 = NexButton(5, 6, "btn2pod2");              // Button down/left
NexButton btn3pod2 = NexButton(5, 7, "btn3pod2");              // Button down/right
NexButton bMutePod2 = NexButton(5, 9, "bMutePod2");            // Mute Button
//pRadio2 (ID:6)
NexButton btn0radio2 = NexButton(6, 4, "btn0radio2");          // Button top/left
NexButton btn1radio2 = NexButton(6, 5, "btn1radio2");          // Button top/right
NexButton btn2radio2 = NexButton(6, 6, "btn2radio2");          // Button down/left
NexButton btn3radio2 = NexButton(6, 7, "btn3radio2");          // Button down/right
NexButton bMuteRadio2 = NexButton(6, 9, "bMuteRadio2");        // Unmute Button
//pSchalter2 (ID:7)
NexButton btn0switch2 = NexButton(7, 4, "btn0switch2");        // Button top/left
NexButton btn1switch2 = NexButton(7, 5, "btn1switch2");        // Button top/right
NexButton btn2switch2 = NexButton(7, 6, "btn2switch2");        // Button down/left
NexButton btn3switch2 = NexButton(7, 7, "btn3switch2");        // Button down/right
NexDSButton bMuteSwitch2 = NexDSButton(7, 9, "bMuteSwitch2");  // Mute/Unmute Switch



// PAGE 3:
//pPodcast3 (ID:9)
NexButton btn0pod3 = NexButton(9, 4, "btn0pod3");              // Button top/left
NexButton btn1pod3 = NexButton(9, 5, "btn1pod3");              // Button top/right
NexButton btn2pod3 = NexButton(9, 6, "btn2pod3");              // Button down/left
NexButton btn3pod3 = NexButton(9, 7, "btn3pod3");              // Button down/right
NexButton bMutePod3 = NexButton(9, 9, "bMutePod3");            // Mute Button
//pRadio3 (ID:10)
NexButton btn0radio3 = NexButton(10, 4, "btn0radio3");         // Button top/left
NexButton btn1radio3 = NexButton(10, 5, "btn1radio3");         // Button top/right
NexButton btn2radio3 = NexButton(10, 6, "btn2radio3");         // Button down/left
NexButton btn3radio3 = NexButton(10, 7, "btn3radio3");         // Button down/right
NexButton bMuteRadio3 = NexButton(10, 9, "bMuteRadio3");       // Unmute Button
//pSchalter3 (ID:11)
NexButton btn0switch3 = NexButton(11, 4, "btn0switch3");       // Button top/left
NexButton btn1switch3 = NexButton(11, 5, "btn1switch3");       // Button top/right
NexButton btn2switch3 = NexButton(11, 6, "btn2switch3");       // Button down/left
NexButton btn3switch3 = NexButton(11, 7, "btn3switch3");       // Button down/right
NexDSButton bMuteSwitch3 = NexDSButton(11, 9, "bMuteSwitch3"); // Mute/Unmute Switch



// PAGE 4:
//pPodcast4 (ID:12)
NexButton btn0pod4 = NexButton(12, 4, "btn0pod4");             // Button top/left
NexButton btn1pod4 = NexButton(12, 5, "btn1pod4");             // Button top/right
NexButton btn2pod4 = NexButton(12, 6, "btn2pod4");             // Button down/left
NexButton btn3pod4 = NexButton(12, 7, "btn3pod4");             // Button down/right
NexButton bMutePod4 = NexButton(12, 9, "bMutePod");            // Mute Button
//pRadio4 (ID:13)
NexButton btn0radio4 = NexButton(13, 4, "btn0radio44");        // Button top/left
NexButton btn1radio4 = NexButton(13, 5, "btn1radio4");         // Button top/right
NexButton btn2radio4 = NexButton(13, 6, "btn2radio4");         // Button down/left
NexButton btn3radio4 = NexButton(13, 7, "btn3radio4");         // Button down/right
NexButton bMuteRadio4 = NexButton(13, 9, "bMuteRadio4");       // Unmute Button
//pSchalter4 (ID:14)
NexButton btn0switch4 = NexButton(14, 4, "btn0switch4");       // Button top/left
NexButton btn1switch4 = NexButton(14, 5, "btn1switch4");       // Button top/right
NexButton btn2switch4 = NexButton(14, 6, "btn2switch4");       // Button down/left
NexButton btn3switch4 = NexButton(14, 7, "btn3switch4");       // Button down/right
NexDSButton bMuteSwitch4 = NexDSButton(14, 9, "bMuteSwitch4"); // Mute/Unmute Switch
*/


/*
// PAGES OVERVIEW:
NexPage pStart      = NexPage(0, 0, "Start");
NexPage pPodcast1    = NexPage(1, 0, "pPodcast1");
NexPage pRadio1      = NexPage(2, 0, "pRadio1");
NexPage pSchalter1   = NexPage(3, 0, "pSchalter1");
NexPage pTmenu      = NexPage(4, 0, "pTmenu");
NexPage pPodcast2    = NexPage(5, 0, "pPodcast2");
NexPage pRadio2      = NexPage(6, 0, "pRadio2");
NexPage pSchalter2   = NexPage(7, 0, "pSchalter2");
NexPage pPodcast3    = NexPage(9, 0, "pPodcast3");
NexPage pRadio3      = NexPage(10, 0, "pRadio3");
NexPage pSchalter3   = NexPage(11, 0, "pSchalter3");
NexPage pPodcast4    = NexPage(11, 0, "pPodcast4");
NexPage pRadio4      = NexPage(12, 0, "pRadio4");
NexPage pSchalter4   = NexPage(13, 0, "pSchalter4");
*/



/**
 * Registrieren aller Objekte für die TouchEvent Liste:
*/
char buffer[100] = {0};

NexTouch *nex_listen_list[] = {
  // Page 1:
  &bMutePod1,
  &btn0pod1,
  &btn1pod1,
  &btn2pod1,
  &btn3pod1,
  &bMuteRadio1,
  &btn0radio1,
  &btn1radio1,
  &btn2radio1,
  &btn3radio1,
  &bMuteSwitch1,
  &btn0switch1,
  &btn1switch1,
  &btn2switch1,
  &btn3switch1,

/*
  // Page 2:
  &bMutePod2,
  &btn0pod2,
  &btn1pod2,
  &btn2pod2,
  &btn3pod2,
  &bMuteRadio2,
  &btn0radio2,
  &btn1radio2,
  &btn2radio2,
  &btn3radio2,
  &bMuteSwitch2,
  &btn0switch2,
  &btn1switch2,
  &btn2switch2,
  &btn3switch2,

  // Page 3:
  &bMutePod3,
  &btn0pod3,
  &btn1pod3,
  &btn2pod3,
  &btn3pod3,
  &bMuteRadio3,
  &btn0radio3,
  &btn1radio3,
  &btn2radio3,
  &btn3radio3,
  &bMuteSwitch3,
  &btn0switch3,
  &btn1switch3,
  &btn2switch3,
  &btn3switch3,

  // Page 4:
  &bMutePod4,
  &btn0pod4,
  &btn1pod4,
  &btn2pod4,
  &btn3pod4,
  &bMuteRadio4,
  &btn0radio4,
  &btn1radio4,
  &btn2radio4,
  &btn3radio4,
  &bMuteSwitch4,
  &btn0switch4,
  &btn1switch4,
  &btn2switch4,
  &btn3switch4,
*/
  NULL
};

/**
 * EVENT CALLBACKS:
 */

/**
 * PODCAST: MUTE/UNMUTE
*/
// PAGE 1: CALLBACKS PODCAST
void bMutePodcast1PushCallback(void *ptr) {
  Speak("OFF", 1);
  NeoTop(255, 0, 0);
  Modus = 1;
}
void bMutePodcast1PopCallback(void *ptr) {
  Speak("ON", 1);
  NeoTop(90, 255, 0);
  Modus = 1;
}
/*
// PAGE 2: CALLBACKS PODCAST
void bMutePodcast2PushCallback(void *ptr) {
  dbSerialPrintln("bMutePodcastPushCallback");
  digitalWrite(LED, HIGH);  // Turn ON internal LED
  Speak("OFF", 2);
}
void bMutePodcast2PopCallback(void *ptr) {
  dbSerialPrintln("bMutePodcastPopCallback");
  digitalWrite(LED, LOW);  // Turn OFF internal LED
  Speak("ON", 2);
}
// PAGE 3: CALLBACKS PODCAST
void bMutePodcast3PushCallback(void *ptr) {
  dbSerialPrintln("bMutePodcastPushCallback");
  digitalWrite(LED, HIGH);  // Turn ON internal LED
  Speak("OFF", 3);
}
void bMutePodcast3PopCallback(void *ptr) {
  dbSerialPrintln("bMutePodcastPopCallback");
  digitalWrite(LED, LOW);  // Turn OFF internal LED
  Speak("ON", 3);
}
// PAGE 4: CALLBACKS PODCAST
void bMutePodcast4PushCallback(void *ptr) {
  dbSerialPrintln("bMutePodcastPushCallback");
  digitalWrite(LED, HIGH);  // Turn ON internal LED
  Speak("OFF", 4);
}
void bMutePodcast4PopCallback(void *ptr) {
  dbSerialPrintln("bMutePodcastPopCallback");
  digitalWrite(LED, LOW);  // Turn OFF internal LED
  Speak("ON", 4);
}
*/

/**
 * RADIO: UNMUTE/MUTE
*/
// PAGE 1: CALLBACKS RADIO
void bMuteRadio1PushCallback(void *ptr) {
  NeoTop(90, 255, 0);
  Speak("ON", 1);
  Modus = 0;
}
void bMuteRadio1PopCallback(void *ptr) {
  NeoTop(255, 0, 0);
  Speak("OFF", 1);
  Modus = 0;
}
/*
// PAGE 2: CALLBACKS RADIO
void bMuteRadio2PushCallback(void *ptr) {
  dbSerialPrintln("bMuteRadioPushCallback");
  digitalWrite(LED, LOW);  // Turn OFF internal LED
  Speak("ON", 2);
}
void bMuteRadio2PopCallback(void *ptr) {
  dbSerialPrintln("bMuteRadioPopCallback");
  digitalWrite(LED, HIGH);  // Turn ON internal LED
  Speak("OFF", 2);
}
// PAGE 3: CALLBACKS RADIO
void bMuteRadio3PushCallback(void *ptr) {
  dbSerialPrintln("bMuteRadioPushCallback");
  digitalWrite(LED, LOW);  // Turn OFF internal LED
  Speak("ON", 3);
}
void bMuteRadio3PopCallback(void *ptr) {
  dbSerialPrintln("bMuteRadioPopCallback");
  digitalWrite(LED, HIGH);  // Turn ON internal LED
  Speak("OFF", 3);
}
// PAGE 4: CALLBACKS RADIO
void bMuteRadio4PushCallback(void *ptr) {
  dbSerialPrintln("bMuteRadioPushCallback");
  digitalWrite(LED, LOW);  // Turn OFF internal LED
  Speak("ON", 4);
}
void bMuteRadio4PopCallback(void *ptr) {
  dbSerialPrintln("bMuteRadioPopCallback");
  digitalWrite(LED, HIGH);  // Turn ON internal LED
  Speak("OFF", 4);
}
*/

/**
 * SCHALTER: SWITCH MUTE/UNMUTE
*/
// PAGE 1: CALLBACKS SWITCH
void bMuteSwitch1PopCallback(void *ptr) {
  Switch1 = !Switch1;
  if (Switch1 == HIGH) {
    NeoTop(90, 255, 0);
    Speak("ON", 1);
    Modus = 1;
  }
  if (Switch1 == LOW) {
    NeoTop(255, 0, 0);
    Speak("OFF", 1);
    Modus = 0;
  }
}
/*
// PAGE 2: CALLBACKS SWITCH
void bMuteSwitch2PopCallback(void *ptr) {
  Switch2 = !Switch2;
  if (Switch2 == HIGH) {
    digitalWrite(LED, HIGH);
    Speak("ON", 2);
  }
  if (Switch2 == LOW) {
    digitalWrite(LED, LOW);
    Speak("OFF", 2);
  }
}
// PAGE 3: CALLBACKS SWITCH
void bMuteSwitch3PopCallback(void *ptr) {
  Switch3 = !Switch3;
  if (Switch3 == HIGH) {
    digitalWrite(LED, HIGH);
    Speak("ON", 3);
  }
  if (Switch3 == LOW) {
    digitalWrite(LED, LOW);
    Speak("OFF", 3);
  }
}
// PAGE 4: CALLBACKS SWITCH
void bMuteSwitch4PopCallback(void *ptr) {
  Switch4 = !Switch4;
  if (Switch4 == HIGH) {
    digitalWrite(LED, HIGH);
    Speak("ON", 4);
  }
  if (Switch4 == LOW) {
    digitalWrite(LED, LOW);
    Speak("OFF", 4);
  }
}
*/

/*
 * BUTTONS: 4er Buttons
*/
// PAGE 1 - 4: BUTTON TOP LEFT
void btn0PushCallback(void *ptr) {
  if(Modus == 1){
    NeoTop(255, 20, 0);  
  }
  if(Modus == 0){
    NeoTop(90, 255, 0);
  }
  digitalWrite(LED, HIGH);
  delay(500);
  digitalWrite(LED, LOW);
  delay(500);
  if(Modus == 1){
    NeoTop(90, 255, 0);
  }
  if(Modus == 0){
    NeoTop(255, 20, 0);
  }
}
// PAGE 1 - 4: BUTTON TOP RIGHT
void btn1PushCallback(void *ptr) {
  if(Modus == 1){
    NeoTop(255, 20, 0);  
  }
  if(Modus == 0){
    NeoTop(90, 255, 0);
  }
  digitalWrite(LED, LOW);
  delay(500);
  if(Modus == 1){
    NeoTop(90, 255, 0);
  }
  if(Modus == 0){
    NeoTop(255, 20, 0);
  }
}
// PAGE 1 - 4: BUTTON DOWN LEFT
void btn2PushCallback(void *ptr) {
  if(Modus == 1){
    NeoTop(255, 20, 0);  
  }
  if(Modus == 0){
    NeoTop(90, 255, 0);
  }
  digitalWrite(LED, HIGH);
  delay(500);
  if(Modus == 1){
    NeoTop(90, 255, 0);
  }
  if(Modus == 0){
    NeoTop(255, 20, 0);
  }
}
// PAGE 1 - 4: BUTTON DOWN RIGHT
void btn3PushCallback(void *ptr) {
  if(Modus == 1){
    NeoTop(255, 20, 0);  
  }
  if(Modus == 0){
    NeoTop(90, 255, 0);
  }
  digitalWrite(LED, HIGH);
  delay(150);
  digitalWrite(LED, LOW);
  delay(300);
  if(Modus == 1){
    NeoTop(90, 255, 0);
  }
  if(Modus == 0){
    NeoTop(255, 20, 0);
  }
}


/**
 * SETUP PROGRAM
 */
void setup(void) {
  /* Starte Serielle Kommunikation mit 9600 Baut */
  Serial.begin(9600);

   // NeoPixel library.
  #if defined (__AVR_ATtiny85__)
    if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
  #endif
  pixels.begin();   // init NeoPixel
  
  /* Initialisieren der Lib: ITEADLIB_Arduino_Nextion *
  nexInit();

  /* Angaben aller Pop- und Push-Events als Callback */
  // PAGE 1:
  //Events Podcast1
  bMutePod1.attachPush(bMutePodcast1PushCallback, &bMutePod1);     // Mute Button 
  bMutePod1.attachPop(bMutePodcast1PopCallback, &bMutePod1);       // Unmute Button 
  btn0pod1.attachPush(btn0PushCallback, &btn0pod1);
  btn1pod1.attachPush(btn1PushCallback, &btn1pod1);
  btn2pod1.attachPush(btn2PushCallback, &btn2pod1);
  btn3pod1.attachPush(btn3PushCallback, &btn3pod1);
  //Events Radio1 
  bMuteRadio1.attachPush(bMuteRadio1PushCallback, &bMuteRadio1);   // Unmute Button 
  bMuteRadio1.attachPop(bMuteRadio1PopCallback, &bMuteRadio1);     // Mute Button 
  btn0radio1.attachPush(btn0PushCallback, &btn0radio1);
  btn1radio1.attachPush(btn1PushCallback, &btn1radio1);
  btn2radio1.attachPush(btn2PushCallback, &btn2radio1);
  btn3radio1.attachPush(btn3PushCallback, &btn3radio1);
  //Events Schalter1
  bMuteSwitch1.attachPop(bMuteSwitch1PopCallback, &bMuteSwitch1);  // Mute/Unmute Switch
  btn0switch1.attachPush(btn0PushCallback, &btn0switch1);
  btn1switch1.attachPush(btn1PushCallback, &btn1switch1);
  btn2switch1.attachPush(btn2PushCallback, &btn2switch1);
  btn3switch1.attachPush(btn3PushCallback, &btn3switch1);

/*
  // PAGE 2:
  //Events Podcast2
  bMutePod2.attachPush(bMutePodcast2PushCallback, &bMutePod2);     // Mute Button 
  bMutePod2.attachPop(bMutePodcast2PopCallback, &bMutePod2);       // Unmute Button
  btn0pod2.attachPush(btn0PushCallback, &btn0pod2);
  btn1pod2.attachPush(btn1PushCallback, &btn1pod2);
  btn2pod2.attachPush(btn2PushCallback, &btn2pod2);
  btn3pod2.attachPush(btn3PushCallback, &btn3pod2);
  //Events Radio2
  bMuteRadio2.attachPush(bMuteRadio2PushCallback, &bMuteRadio2);   // Unmute Button 
  bMuteRadio2.attachPop(bMuteRadio2PopCallback, &bMuteRadio2);     // Mute Button
  btn0radio2.attachPush(btn0PushCallback, &btn0radio2);
  btn1radio2.attachPush(btn1PushCallback, &btn1radio2);
  btn2radio2.attachPush(btn2PushCallback, &btn2radio2);
  btn3radio2.attachPush(btn3PushCallback, &btn3radio2);
  //Events Schalter2
  bMuteSwitch2.attachPop(bMuteSwitch2PopCallback, &bMuteSwitch2);  // Mute/Unmute Switch
  btn0switch2.attachPush(btn0PushCallback, &btn0switch2);
  btn1switch2.attachPush(btn1PushCallback, &btn1switch2);
  btn2switch2.attachPush(btn2PushCallback, &btn2switch2);
  btn3switch2.attachPush(btn3PushCallback, &btn3switch2);


  // PAGE 3
  //Events Podcast3
  bMutePod3.attachPush(bMutePodcast3PushCallback, &bMutePod3);     // Mute Button 
  bMutePod3.attachPop(bMutePodcast3PopCallback, &bMutePod3);       // Unmute Button
  btn0pod3.attachPush(btn0PushCallback, &btn0pod3);
  btn1pod3.attachPush(btn1PushCallback, &btn1pod3);
  btn2pod3.attachPush(btn2PushCallback, &btn2pod3);
  btn3pod3.attachPush(btn3PushCallback, &btn3pod3);
  //Events Radio3
  bMuteRadio3.attachPush(bMuteRadio3PushCallback, &bMuteRadio3);   // Unmute Button 
  bMuteRadio3.attachPop(bMuteRadio3PopCallback, &bMuteRadio3);     // Mute Button
  btn0radio3.attachPush(btn0PushCallback, &btn0radio3);
  btn1radio3.attachPush(btn1PushCallback, &btn1radio3);
  btn2radio3.attachPush(btn2PushCallback, &btn2radio3);
  btn3radio3.attachPush(btn3PushCallback, &btn3radio3);
  //Events Schalter3
  bMuteSwitch3.attachPop(bMuteSwitch3PopCallback, &bMuteSwitch3);  // Mute/Unmute Switch
  btn0switch3.attachPush(btn0PushCallback, &btn0switch3);
  btn1switch3.attachPush(btn1PushCallback, &btn1switch3);
  btn2switch3.attachPush(btn2PushCallback, &btn2switch3);
  btn3switch3.attachPush(btn3PushCallback, &btn3switch3);


  // PAGE 4:
  //Events Podcast
  bMutePod4.attachPush(bMutePodcast4PushCallback, &bMutePod4);     // Mute Button 
  bMutePod4.attachPop(bMutePodcast4PopCallback, &bMutePod4);       // Unmute Button
  btn0pod4.attachPush(btn0PushCallback, &btn0pod4);
  btn1pod4.attachPush(btn1PushCallback, &btn1pod4);
  btn2pod4.attachPush(btn2PushCallback, &btn2pod4);
  btn3pod4.attachPush(btn3PushCallback, &btn3pod4);
  //Events Radio
  bMuteRadio4.attachPush(bMuteRadio4PushCallback, &bMuteRadio4);   // Unmute Button 
  bMuteRadio4.attachPop(bMuteRadio4PopCallback, &bMuteRadio4);     // Mute Button
  btn0radio4.attachPush(btn0PushCallback, &btn0radio4);
  btn1radio4.attachPush(btn1PushCallback, &btn1radio4);
  btn2radio4.attachPush(btn2PushCallback, &btn2radio4);
  btn3radio4.attachPush(btn3PushCallback, &btn3radio4);
  //Events Schalter
  bMuteSwitch4.attachPop(bMuteSwitch4PopCallback, &bMuteSwitch4);  // Mute/Unmute Switch
  btn0switch4.attachPush(btn0PushCallback, &btn0switch4);
  btn1switch4.attachPush(btn1PushCallback, &btn1switch4);
  btn2switch4.attachPush(btn2PushCallback, &btn2switch4);
  btn3switch4.attachPush(btn3PushCallback, &btn3switch4);
*/ 
  /* Setze LED auf Ausgabe */
  pinMode(LED, OUTPUT);

  /* Starte Regenbogen für NeoPixel Test */
  rainbowCycle(1000);
  delay(1000);

  /* Setze NeoPixel auf Grün */
  NeoTop(90, 255, 0);
  NeoBottom(0, 255, 0);
}


/**
 * PROGRAM LOOP
 */
void loop(void) {
  /* Nutzen der Events */
  nexLoop(nex_listen_list);
}
