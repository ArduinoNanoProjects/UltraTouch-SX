/**
 *   _   _  _  _                 _____                      _       _____ __   __
 *  | | | || || |               |_   _|                    | |     /  ___|\ \ / /
 *  | | | || || |_  _ __   __ _   | |    ___   _   _   ___ | |__   \ `--.  \ V / 
 *  | | | || || __|| '__| / _` |  | |   / _ \ | | | | / __|| '_ \   `--. \ /   \ 
 *  | |_| || || |_ | |   | (_| |  | |  | (_) || |_| || (__ | | | | /\__/ // /^\ \
 *   \___/ |_| \__||_|    \__,_|  \_/   \___/  \__,_| \___||_| |_| \____/ \/   \/                                                                          
 *   
 * 
 * Die Version der UltraTouch SX (Version 6) ist ausgestattet mit einem Nextion Display 
 * und sie versendet MIDI zur Nutzung der Räuspertasten. Sie kann vielseitig genutzt 
 * und erweitert werden ;)
 * 
 * Diese Projekt entstand im Rahmen des Ultraschall Projektes zum Themea: "MIDI Controller"
 * Es gibt viele weitere Projekte von meinen Kollegen und der Community.
 * Schaue doch mal vorbei: https://ultraschall.fm
 * 
 * @developer   Michael McCouman Jr.
 * @version     V6
 * @date        4.Okt 2018
 * @website     https://wikibyte.org
 * 
 * Licence:     CC BY SA    
 * Github:      https://github.com/McCouman
 * 
*/

//Bibliothek:
#include "Nextion.h"

// LED Pins
#define LED 13      // OnBoard LED des Arduino Nanos

// Vars
int Switch = HIGH;  // Speichert den Wert des MIDI-Schalters



/**
 * Deklaration der Obejekte für das Nextion-Display:
 * 
 * Example: (page id = 0, component id = 1, component name = "b0")
*/
//pPodcast: (ID:1)
NexButton btn0pod = NexButton(1, 4, "btn0pod");             // Button top/left
NexButton btn1pod = NexButton(1, 5, "btn1pod");             // Button top/right
NexButton btn2pod = NexButton(1, 6, "btn2pod");             // Button down/left
NexButton btn3pod = NexButton(1, 7, "btn3pod");             // Button down/right
NexButton bMutePod = NexButton(1, 9, "bMutePod");           // Mute Button

//pRadio: (ID:2)
NexButton btn0radio = NexButton(2, 4, "btn0radio");         // Button top/left
NexButton btn1radio = NexButton(2, 5, "btn1radio");         // Button top/right
NexButton btn2radio = NexButton(2, 6, "btn2radio");         // Button down/left
NexButton btn3radio = NexButton(2, 7, "btn3radio");         // Button down/right
NexButton bMuteRadio = NexButton(2, 9, "bMuteRadio");       // Unmute Button

//pSchalter: (ID:3)
NexButton btn0switch = NexButton(2, 4, "btn0switch");       // Button top/left
NexButton btn1switch = NexButton(2, 5, "btn1switch");       // Button top/right
NexButton btn2switch = NexButton(2, 6, "btn2switch");       // Button down/left
NexButton btn3switch = NexButton(2, 7, "btn3switch");       // Button down/right
NexDSButton bMuteSwitch = NexDSButton(3, 9, "bMuteSwitch"); // Mute/Unmute Switch

//Seiten
NexPage pStart      = NexPage(0, 0, "Start");
NexPage pPodcast    = NexPage(1, 0, "pPodcast");
NexPage pRadio      = NexPage(2, 0, "pRadio");
NexPage pSchalter   = NexPage(3, 0, "pSchalter");
NexPage pTmenu            = NexPage(4, 0, "pTmenu");
NexPage pTmenuColor       = NexPage(0, 0, "pTmenuColor");
NexPage pTmenuSettings    = NexPage(0, 0, "pTmenuSettings");



/**
 * Registrieren aller Objekte für die TouchEvent Liste:
*/

char buffer[100] = {0};

NexTouch *nex_listen_list[] = {
  &bMutePod,
  &btn0pod,
  &btn1pod,
  &btn2pod,
  &btn3pod,
  &bMuteRadio,
  &btn0radio,
  &btn1radio,
  &btn2radio,
  &btn3radio,
  &bMuteSwitch,
  NULL
};



//-------------------------- Callbacks -----------------------------

/**
 * PODCAST: MUTE/UNMUTE
*/
void bMutePodcastPushCallback(void *ptr) {
  dbSerialPrintln("bMutePodcastPushCallback");
  digitalWrite(LED, HIGH);  // Turn ON internal LED
  Speak("OFF");
}
void bMutePodcastPopCallback(void *ptr) {
  dbSerialPrintln("bMutePodcastPopCallback");
  digitalWrite(LED, LOW);  // Turn OFF internal LED
  Speak("ON");
}

/**
 * RADIO: UNMUTE/MUTE
*/
void bMuteRadioPushCallback(void *ptr) {
  dbSerialPrintln("bMuteRadioPushCallback");
  digitalWrite(LED, LOW);  // Turn OFF internal LED
  Speak("ON");
}
void bMuteRadioPopCallback(void *ptr) {
  dbSerialPrintln("bMuteRadioPopCallback");
  digitalWrite(LED, HIGH);  // Turn ON internal LED
  Speak("OFF");
}

/**
 * SCHALTER: SWITCH MUTE/UNMUTE
*/
void bMuteSwitchPopCallback(void *ptr) {
  Switch = !Switch;
  if (Switch == HIGH) {
    digitalWrite(LED, HIGH);
    Speak("OFF");
  }
  if (Switch == LOW) {
    digitalWrite(LED, LOW);
    Speak("ON");
  }
}

/*
 * BUTTONS: 4er Buttons
*/
void btn0PushCallback(void *ptr) {
  digitalWrite(LED, HIGH);
  delay(500);
  digitalWrite(LED, LOW);
  delay(500);
}
void btn1PushCallback(void *ptr) {
  digitalWrite(LED, LOW);
}
void btn2PushCallback(void *ptr) {
  digitalWrite(LED, HIGH);
}
void btn3PushCallback(void *ptr) {
  digitalWrite(LED, HIGH);
  delay(150);
  digitalWrite(LED, LOW);
  delay(300);
}



//-------------------------- Program -----------------------------

/**
 * SETUP PROGRAM
 */
void setup(void) {

  Serial.begin(9600);
  
  // Initialisieren der Lib: ITEADLIB_Arduino_Nextion
  nexInit();

  // Angaben aller Pop- und Push-Events als Callback 
  /* Page: Podcast */
  bMutePod.attachPush(bMutePodcastPushCallback, &bMutePod);     // Mute Button 
  bMutePod.attachPop(bMutePodcastPopCallback, &bMutePod);       // Unmute Button 
  //4er Buttons
  btn0pod.attachPush(btn0PushCallback, &btn0pod);
  btn1pod.attachPush(btn1PushCallback, &btn1pod);
  btn2pod.attachPush(btn2PushCallback, &btn2pod);
  btn3pod.attachPush(btn3PushCallback, &btn3pod);

  /* Page: Radio */
  bMuteRadio.attachPush(bMuteRadioPushCallback, &bMuteRadio);   // Unmute Button 
  bMuteRadio.attachPop(bMuteRadioPopCallback, &bMuteRadio);     // Mute Button 
  //4er Buttons
  btn0radio.attachPush(btn0PushCallback, &btn0radio);
  btn1radio.attachPush(btn1PushCallback, &btn1radio);
  btn2radio.attachPush(btn2PushCallback, &btn2radio);
  btn3radio.attachPush(btn3PushCallback, &btn3radio);

  /* Page: Schalter */
  bMuteSwitch.attachPop(bMuteSwitchPopCallback, &bMuteSwitch);  // Mute/Unmute Switch
  //4er Buttons
  btn0switch.attachPush(btn0PushCallback, &btn0switch);
  btn1switch.attachPush(btn1PushCallback, &btn1switch);
  btn2switch.attachPush(btn2PushCallback, &btn2switch);
  btn3switch.attachPush(btn3PushCallback, &btn3switch);

  // Setze LED auf Ausgabe:
  pinMode(LED, OUTPUT);
}

/**
 * PROGRAM LOOP
 */
void loop(void) {
  //Nutzen der Events 
  nexLoop(nex_listen_list);
}
