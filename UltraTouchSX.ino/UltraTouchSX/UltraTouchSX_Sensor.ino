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
 * @date        04.Okt 2018 - 03. Jan 2019
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
#define NUMPIXELS    6   // Anzahl der NeoPixel

// VARS:
int Toggle      = HIGH;  // Speichert den Wert des Button Peak View
int Switch      = HIGH;  // Speichert den Wert des MIDI-Schalters 
int Bridhness   = 255;   // Speichert den Wert der Helligkeit für die Bodenbeleuchtung
int Modus       = 1;     // Speichert den Wert ob Mute oder Unmute für die Farben eines Callbacks
int Channel     = 1;     // Speichert die Werte für die Kanäle 1 bis 4 für die Mute/Unmute Taste
int Colors      = 1;     // Speichert die Werte für die Farben 1 bis 9 für die Bodenbeleuctung
int Light       = 1;     // Speichert die Werte für die Helligkeit 1 bis 8 für die Bodenbeleuctung

// VARS HCSR04
int triggerPin  = 2;
int echoPin     = 3;


// NEOPIXEL:
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);


/**
 * Deklaration der Obejekte für das Nextion-Display:
 * Bsp.: (page id = 0, component id = 1, component name = "b0")
*/
// PAGES:
//pPodcast1 (ID:1)
NexButton btn0pod = NexButton(1, 3, "btn0pod");                 // Button top/left
NexButton btn1pod = NexButton(1, 4, "btn1pod");                 // Button top/right
NexButton btn2pod = NexButton(1, 5, "btn2pod");                 // Button down/left
NexButton btn3pod = NexButton(1, 6, "btn3pod");                 // Button down/right
NexButton btnMutePod = NexButton(1, 8, "btnMutePod");           // Mute Button
//pRadio1 (ID:2)
NexButton btn0radio = NexButton(2, 3, "btn0radio");             // Button top/left
NexButton btn1radio = NexButton(2, 4, "btn1radio");             // Button top/right
NexButton btn2radio = NexButton(2, 5, "btn2radio");             // Button down/left
NexButton btn3radio = NexButton(2, 6, "btn3radio");             // Button down/right
NexButton btnMuteRadio = NexButton(2, 8, "btnMuteRadio");       // Unmute Button
//pSchalter1 (ID:3)
NexButton btn0switch = NexButton(3, 3, "btn0switch");           // Button top/left
NexButton btn1switch = NexButton(3, 4, "btn1switch");           // Button top/right
NexButton btn2switch = NexButton(3, 5, "btn2switch");           // Button down/left
NexButton btn3switch = NexButton(3, 6, "btn3switch");           // Button down/right
NexDSButton btnMuteSwitch = NexDSButton(3, 8, "btnMuteSwitch"); // Mute/Unmute Switch

// MENU:
//pTmenu (ID:4)
NexButton bGoPage = NexButton(4, 1, "bGoPage");                // Button Channel (1 bis 4)
NexButton bGoColor = NexButton(4, 6, "bGoColor");              // Button Color 
NexButton bGoLight = NexButton(4, 7, "bGoLight");              // Button Helligkeit

// PAGES OVERVIEW:
NexPage pStart      = NexPage(0, 0, "Start");
NexPage pPodcast    = NexPage(1, 0, "pPodcast");
NexPage pRadio      = NexPage(2, 0, "pRadio");
NexPage pSchalter   = NexPage(3, 0, "pSchalter");
NexPage pTmenu      = NexPage(4, 0, "pTmenu");




/**
 * Registrieren aller Objekte für die TouchEvent Liste:
*/
char buffer[100] = {0};

NexTouch *nex_listen_list[] = {
  // Pages:
  &btnMutePod,
  &btn0pod,
  &btn1pod,
  &btn2pod,
  &btn3pod,
  &btnMuteRadio,
  &btn0radio,
  &btn1radio,
  &btn2radio,
  &btn3radio,
  &btnMuteSwitch,
  &btn0switch,
  &btn1switch,
  &btn2switch,
  &btn3switch,
  // Menu
  &bGoPage,
  &bGoColor,
  &bGoLight,
  NULL
};


/**
 * MENU CALLBACKS:
 */
// MENU: CHANNEL
void bGoChannelPushCallback(void *ptr) {
  Channel = Channel +1 ;
  if (Channel == 5) {
    Channel = 1;
  }
}

// MENU: COLOR
void bGoColorPushCallback(void *ptr) {
  Colors = Colors +1 ;
  NeoBottomSwitch(Colors);
}

// MENU: BRIDHNESS
void bGoLightPushCallback(void *ptr) {
  Light = Light +1 ;
  if (Light == 1) {
    Bridhness = 255;
    NeoBottomSwitch(Colors);
  }
  if (Light == 2) {
    Bridhness = 0;
    NeoBottomSwitch(Colors);
  }
  if (Light == 3) {
    Bridhness = 25;
    NeoBottomSwitch(Colors);
  }
  if (Light == 4) {
    Bridhness = 60;
    NeoBottomSwitch(Colors);
  }
  if (Light == 5) {
    Bridhness = 110;
    NeoBottomSwitch(Colors);
  }
  if (Light == 6) {
    Bridhness = 160;
    NeoBottomSwitch(Colors);
  }
  if (Light == 7) {
    Bridhness = 200;
    NeoBottomSwitch(Colors);
  }
  if (Light == 8) {
    Bridhness = 230;
    NeoBottomSwitch(Colors);
  }
  if (Light == 9) {
    Bridhness = 255;
    NeoBottomSwitch(Colors);
    Light = 1;
  }
}


/**
 * PODCAST: MUTE/UNMUTE
*/
// PAGE 1: CALLBACKS PODCAST
void bMutePodcastPushCallback(void *ptr) {
  Speak("OFF", Channel);
  
  //== rot? 
  if (Colors == 5) {
    NeoTop(0, Bridhness, 0);
  } else {
    NeoBottom(Bridhness, 0, 0); //rot 
  }

  Modus = 1;
}
void bMutePodcastPopCallback(void *ptr) {
  Speak("ON", Channel);
  NeoBottomSwitch(Colors);
  Modus = 1;
}


/**
 * RADIO: UNMUTE/MUTE
*/
// PAGE 1: CALLBACKS RADIO
void bMuteRadioPushCallback(void *ptr) {
  Speak("ON", Channel);
  NeoBottomSwitch(Colors);
  
  Modus = 0;
}
void bMuteRadioPopCallback(void *ptr) {
  Speak("OFF", Channel);

  //== rot? 
  if (Colors == 5) {
    NeoTop(0, Bridhness, 0);
  } else {
    NeoBottom(Bridhness, 0, 0); //rot 
  }
  Modus = 0;
}


/**
 * SCHALTER: SWITCH MUTE/UNMUTE
*/
// PAGE 1: CALLBACKS SWITCH
void bMuteSwitchPopCallback(void *ptr) {
  Switch = !Switch;
  if (Switch == HIGH) {
    NeoBottomSwitch(Colors);
    Speak("ON", Channel);
    Modus = 1;
  }
  if (Switch == LOW) {
    //== rot? 
    if (Colors == 5) {
      NeoTop(0, Bridhness, 0);
    } else {
      NeoBottom(Bridhness, 0, 0); //rot 
    }
    
    Speak("OFF", Channel);
    Modus = 0;
  }
}


/*
 * BUTTONS: 4er Buttons
*/
// PAGE 1 - 4: BUTTON TOP LEFT
void btn0PushCallback(void *ptr) {
  if(Modus == 1){
    NeoTop(Bridhness, 0, 0);  
  }
  if(Modus == 0){
    NeoBottomSwitch(Colors);
  }
  digitalWrite(LED, HIGH);
  delay(500);
  Note(1);
  digitalWrite(LED, LOW);
  delay(500);
  if(Modus == 1){
    NeoBottomSwitch(Colors);
  }
  if(Modus == 0){
    NeoTop(Bridhness, 0, 0);
  }
}

// PAGE 1 - 4: BUTTON TOP RIGHT
void btn1PushCallback(void *ptr) {
  Toggle = !Toggle;
  if(Modus == 1){
    NeoTop(Bridhness, 0, 0);  
  }
  if(Modus == 0){
    NeoBottomSwitch(Colors);
  }
  //-MIDI AUSGABE
  digitalWrite(LED, HIGH);
  delay(500);
  if(Toggle == LOW){
    Note(4);
  } else {
    Note(5);
  }
  digitalWrite(LED, LOW);
  delay(500);
  if(Modus == 1){
    NeoBottomSwitch(Colors);
  }
  if(Modus == 0){
    NeoTop(Bridhness, 0, 0);
  }
}

// PAGE 1 - 4: BUTTON DOWN LEFT
void btn2PushCallback(void *ptr) {
  if(Modus == 1){
    NeoTop(Bridhness, 0, 0);  
  }
  if(Modus == 0){
    NeoBottomSwitch(Colors);
  }
  //-MIDI AUSGABE
  digitalWrite(LED, HIGH);
  delay(500);
  Note(2);
  digitalWrite(LED, LOW);
  delay(500);
  if(Modus == 1){
    NeoBottomSwitch(Colors);
  }
  if(Modus == 0){
    NeoTop(Bridhness, 0, 0);
  }
}

// PAGE 1 - 4: BUTTON DOWN RIGHT
void btn3PushCallback(void *ptr) {
  if(Modus == 1){
    NeoTop(Bridhness, 0, 0);  
  }
  if(Modus == 0){
    NeoBottomSwitch(Colors);
  }
  //-MIDI AUSGABE
  digitalWrite(LED, HIGH);
  delay(500);
  Note(3);
  digitalWrite(LED, LOW);
  delay(500);
  if(Modus == 1){
    NeoBottomSwitch(Colors);
  }
  if(Modus == 0){
    NeoTop(Bridhness, 0, 0);
  }
}


/**
 * SETUP PROGRAM
 */
void setup(void) {
  /* Starte Serielle Kommunikation mit 9600 Baut */
  Serial.begin(9600);

  /* Initialisieren der NeoPixel Lib */
  #if defined (__AVR_ATtiny85__)
    if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
  #endif
  pixels.begin();
  
  /* Initialisieren der Lib: ITEADLIB_Arduino_Nextion */
  nexInit();

  /* Angaben aller Pop- und Push-Events als Callback */
  //Events Podcast
  btnMutePod.attachPush(bMutePodcastPushCallback, &btnMutePod);     // Mute Button 
  btnMutePod.attachPop(bMutePodcastPopCallback, &btnMutePod);       // Unmute Button 
  btn0pod.attachPush(btn0PushCallback, &btn0pod);
  btn1pod.attachPush(btn1PushCallback, &btn1pod);
  btn2pod.attachPush(btn2PushCallback, &btn2pod);
  btn3pod.attachPush(btn3PushCallback, &btn3pod);
  //Events Radio
  btnMuteRadio.attachPush(bMuteRadioPushCallback, &btnMuteRadio);   // Unmute Button 
  btnMuteRadio.attachPop(bMuteRadioPopCallback, &btnMuteRadio);     // Mute Button 
  btn0radio.attachPush(btn0PushCallback, &btn0radio);
  btn1radio.attachPush(btn1PushCallback, &btn1radio);
  btn2radio.attachPush(btn2PushCallback, &btn2radio);
  btn3radio.attachPush(btn3PushCallback, &btn3radio);
  //Events Schalter
  btnMuteSwitch.attachPop(bMuteSwitchPopCallback, &btnMuteSwitch);  // Mute/Unmute Switch
  btn0switch.attachPush(btn0PushCallback, &btn0switch);
  btn1switch.attachPush(btn1PushCallback, &btn1switch);
  btn2switch.attachPush(btn2PushCallback, &btn2switch);
  btn3switch.attachPush(btn3PushCallback, &btn3switch);
  //Event Channel
  bGoPage.attachPush(bGoChannelPushCallback, &bGoPage);
  //Event Color
  bGoColor.attachPush(bGoColorPushCallback, &bGoColor);
  //Event Brightness
  bGoLight.attachPush(bGoLightPushCallback, &bGoLight);

  /* Setze LED auf Ausgabe */
  pinMode(LED, OUTPUT);

  /* Setze Ultrachall Sensor (HC-SR04) */
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);

  /* Starte Regenbogen für NeoPixel Test */
  rainbowCycle(1000);
  delay(1000);

  /* Setze NeoPixel auf Grün */
  NeoTop(0, 255, 0);
  NeoBottom(0, 255, 0);
}


/**
 * PROGRAM LOOP
 */
void loop(void) {
  /* Nutzen der Events */
  nexLoop(nex_listen_list);

  /* Lese den Ultraschall-Sensor aus */
  //HCSR04_Read();
  sensorAbfragen(triggerPin, echoPin, 1);
}
