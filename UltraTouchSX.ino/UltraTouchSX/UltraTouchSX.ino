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


//Angaben der Mute Seiten
#define Page1 ON
#define Page2 OFF
#define Page3 OFF
#define Page4 OFF

// LED Pins
#define LED 13      // OnBoard LED des Arduino Nanos

// Vars
int Switch1 = HIGH;  // Speichert den Wert des MIDI-Schalters für Seiten 1
/*
int Switch2 = HIGH;  // Speichert den Wert des MIDI-Schalters für Seiten 2
int Switch3 = HIGH;  // Speichert den Wert des MIDI-Schalters für Seiten 3
int Switch4 = HIGH;  // Speichert den Wert des MIDI-Schalters für Seiten 4
*/



/**
 * Deklaration der Obejekte für das Nextion-Display:
 * 
 * Example: (page id = 0, component id = 1, component name = "b0")
*/
// PAGE 1
//pPodcast: (ID:1)
NexButton btn0pod1 = NexButton(1, 4, "btn0pod1");             // Button top/left
NexButton btn1pod1 = NexButton(1, 5, "btn1pod1");             // Button top/right
NexButton btn2pod1 = NexButton(1, 6, "btn2pod1");             // Button down/left
NexButton btn3pod1 = NexButton(1, 7, "btn3pod1");             // Button down/right
NexButton bMutePod1 = NexButton(1, 9, "bMutePod1");           // Mute Button
//pRadio: (ID:2)
NexButton btn0radio1 = NexButton(2, 4, "btn0radio1");         // Button top/left
NexButton btn1radio1 = NexButton(2, 5, "btn1radio1");         // Button top/right
NexButton btn2radio1 = NexButton(2, 6, "btn2radio1");         // Button down/left
NexButton btn3radio1 = NexButton(2, 7, "btn3radio1");         // Button down/right
NexButton bMuteRadio1 = NexButton(2, 9, "bMuteRadio1");       // Unmute Button
//pSchalter: (ID:3)
NexButton btn0switch1 = NexButton(3, 4, "btn0switch");       // Button top/left
NexButton btn1switch1 = NexButton(3, 5, "btn1switch");       // Button top/right
NexButton btn2switch1 = NexButton(3, 6, "btn2switch");       // Button down/left
NexButton btn3switch1 = NexButton(3, 7, "btn3switch");       // Button down/right
NexDSButton bMuteSwitch1 = NexDSButton(3, 9, "bMuteSwitch1"); // Mute/Unmute Switch

/*
// PAGE 2
//pPodcast: (ID:5)
NexButton btn0pod2 = NexButton(5, 4, "btn0pod2");             // Button top/left
NexButton btn1pod2 = NexButton(5, 5, "btn1pod2");             // Button top/right
NexButton btn2pod2 = NexButton(5, 6, "btn2pod2");             // Button down/left
NexButton btn3pod2 = NexButton(5, 7, "btn3pod2");             // Button down/right
NexButton bMutePod2 = NexButton(5, 9, "bMutePod2");           // Mute Button
//pRadio: (ID:6)
NexButton btn0radio2 = NexButton(6, 4, "btn0radio2");         // Button top/left
NexButton btn1radio2 = NexButton(6, 5, "btn1radio2");         // Button top/right
NexButton btn2radio2 = NexButton(6, 6, "btn2radio2");         // Button down/left
NexButton btn3radio2 = NexButton(6, 7, "btn3radio2");         // Button down/right
NexButton bMuteRadio2 = NexButton(6, 9, "bMuteRadio2");       // Unmute Button
//pSchalter: (ID:7)
NexButton btn0switch2 = NexButton(7, 4, "btn0switch2");       // Button top/left
NexButton btn1switch2 = NexButton(7, 5, "btn1switch2");       // Button top/right
NexButton btn2switch2 = NexButton(7, 6, "btn2switch2");       // Button down/left
NexButton btn3switch2 = NexButton(7, 7, "btn3switch2");       // Button down/right
NexDSButton bMuteSwitch2 = NexDSButton(7, 9, "bMuteSwitch2"); // Mute/Unmute Switch



// PAGE 3
//pPodcast: (ID:9)
NexButton btn0pod3 = NexButton(9, 4, "btn0pod3");             // Button top/left
NexButton btn1pod3 = NexButton(9, 5, "btn1pod3");             // Button top/right
NexButton btn2pod3 = NexButton(9, 6, "btn2pod3");             // Button down/left
NexButton btn3pod3 = NexButton(9, 7, "btn3pod3");             // Button down/right
NexButton bMutePod3 = NexButton(9, 9, "bMutePod3");           // Mute Button
//pRadio: (ID:10)
NexButton btn0radio3 = NexButton(10, 4, "btn0radio3");         // Button top/left
NexButton btn1radio3 = NexButton(10, 5, "btn1radio3");         // Button top/right
NexButton btn2radio3 = NexButton(10, 6, "btn2radio3");         // Button down/left
NexButton btn3radio3 = NexButton(10, 7, "btn3radio3");         // Button down/right
NexButton bMuteRadio3 = NexButton(10, 9, "bMuteRadio3");       // Unmute Button
//pSchalter: (ID:11)
NexButton btn0switch3 = NexButton(11, 4, "btn0switch3");       // Button top/left
NexButton btn1switch3 = NexButton(11, 5, "btn1switch3");       // Button top/right
NexButton btn2switch3 = NexButton(11, 6, "btn2switch3");       // Button down/left
NexButton btn3switch3 = NexButton(11, 7, "btn3switch3");       // Button down/right
NexDSButton bMuteSwitch3 = NexDSButton(11, 9, "bMuteSwitch3"); // Mute/Unmute Switch



// PAGE 4
//pPodcast: (ID:12)
NexButton btn0pod = NexButton(12, 4, "btn0pod");             // Button top/left
NexButton btn1pod = NexButton(12, 5, "btn1pod");             // Button top/right
NexButton btn2pod = NexButton(12, 6, "btn2pod");             // Button down/left
NexButton btn3pod = NexButton(12, 7, "btn3pod");             // Button down/right
NexButton bMutePod = NexButton(12, 9, "bMutePod");           // Mute Button

//pRadio: (ID:13)
NexButton btn0radio = NexButton(13, 4, "btn0radio");         // Button top/left
NexButton btn1radio = NexButton(13, 5, "btn1radio");         // Button top/right
NexButton btn2radio = NexButton(13, 6, "btn2radio");         // Button down/left
NexButton btn3radio = NexButton(13, 7, "btn3radio");         // Button down/right
NexButton bMuteRadio = NexButton(13, 9, "bMuteRadio");       // Unmute Button

//pSchalter: (ID:14)
NexButton btn0switch = NexButton(14, 4, "btn0switch");       // Button top/left
NexButton btn1switch = NexButton(14, 5, "btn1switch");       // Button top/right
NexButton btn2switch = NexButton(14, 6, "btn2switch");       // Button down/left
NexButton btn3switch = NexButton(14, 7, "btn3switch");       // Button down/right
NexDSButton bMuteSwitch = NexDSButton(14, 9, "bMuteSwitch"); // Mute/Unmute Switch
*/

//Seiten
NexPage pStart      = NexPage(0, 0, "Start");
NexPage pPodcast1    = NexPage(1, 0, "pPodcast1");
NexPage pRadio1      = NexPage(2, 0, "pRadio1");
NexPage pSchalter1   = NexPage(3, 0, "pSchalter1");
/*
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
  //Page 1
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

/*
  //Page 2
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

  //Page 3
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

  //Page 4
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
*/
  NULL
};



//-------------------------- Callbacks -----------------------------

/**
 * PODCAST: MUTE/UNMUTE
*/
void bMutePodcast1PushCallback(void *ptr) {
  dbSerialPrintln("bMutePodcastPushCallback");
  digitalWrite(LED, HIGH);  // Turn ON internal LED
  Speak("OFF", 1);
}
void bMutePodcast1PopCallback(void *ptr) {
  dbSerialPrintln("bMutePodcastPopCallback");
  digitalWrite(LED, LOW);  // Turn OFF internal LED
  Speak("ON", 1);
}
/*
//Page 2 bis Page 4
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
void bMuteRadio1PushCallback(void *ptr) {
  dbSerialPrintln("bMuteRadioPushCallback");
  digitalWrite(LED, LOW);  // Turn OFF internal LED
  Speak("ON", 1);
}
void bMuteRadio1PopCallback(void *ptr) {
  dbSerialPrintln("bMuteRadioPopCallback");
  digitalWrite(LED, HIGH);  // Turn ON internal LED
  Speak("OFF", 1);
}
/*
//Page 2 bis Page 4
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
void bMuteSwitch1PopCallback(void *ptr) {
  Switch1 = !Switch1;
  if (Switch1 == HIGH) {
    digitalWrite(LED, HIGH);
    Speak("ON", 1);
  }
  if (Switch1 == LOW) {
    digitalWrite(LED, LOW);
    Speak("OFF", 1);
  }
}
/*
//Page 2 bis Page 4
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
  // PAGE 1
  /* Page 1: Podcast */
  bMutePod1.attachPush(bMutePodcast1PushCallback, &bMutePod1);     // Mute Button 
  bMutePod1.attachPop(bMutePodcast1PopCallback, &bMutePod1);       // Unmute Button 
  //4er Buttons
  btn0pod1.attachPush(btn0PushCallback, &btn0pod1);
  btn1pod1.attachPush(btn1PushCallback, &btn1pod1);
  btn2pod1.attachPush(btn2PushCallback, &btn2pod1);
  btn3pod1.attachPush(btn3PushCallback, &btn3pod1);

  /* Page 1: Radio */
  bMuteRadio1.attachPush(bMuteRadio1PushCallback, &bMuteRadio1);   // Unmute Button 
  bMuteRadio1.attachPop(bMuteRadio1PopCallback, &bMuteRadio1);     // Mute Button 
  //4er Buttons
  btn0radio1.attachPush(btn0PushCallback, &btn0radio1);
  btn1radio1.attachPush(btn1PushCallback, &btn1radio1);
  btn2radio1.attachPush(btn2PushCallback, &btn2radio1);
  btn3radio1.attachPush(btn3PushCallback, &btn3radio1);

  /* Page 1: Schalter */
  bMuteSwitch1.attachPop(bMuteSwitch1PopCallback, &bMuteSwitch1);  // Mute/Unmute Switch
  //4er Buttons
  btn0switch1.attachPush(btn0PushCallback, &btn0switch1);
  btn1switch1.attachPush(btn1PushCallback, &btn1switch1);
  btn2switch1.attachPush(btn2PushCallback, &btn2switch1);
  btn3switch1.attachPush(btn3PushCallback, &btn3switch1);



/*
  // PAGE 2
  //Page 2: Podcast
  bMutePod2.attachPush(bMutePodcast2PushCallback, &bMutePod2);     // Mute Button 
  bMutePod2.attachPop(bMutePodcast2PopCallback, &bMutePod2);       // Unmute Button 
  //4er Buttons
  btn0pod2.attachPush(btn0PushCallback, &btn0pod2);
  btn1pod2.attachPush(btn1PushCallback, &btn1pod2);
  btn2pod2.attachPush(btn2PushCallback, &btn2pod2);
  btn3pod2.attachPush(btn3PushCallback, &btn3pod2);

  //Page 2: Radio
  bMuteRadio2.attachPush(bMuteRadio2PushCallback, &bMuteRadio2);   // Unmute Button 
  bMuteRadio2.attachPop(bMuteRadio2PopCallback, &bMuteRadio2);     // Mute Button 
  //4er Buttons
  btn0radio2.attachPush(btn0PushCallback, &btn0radio2);
  btn1radio2.attachPush(btn1PushCallback, &btn1radio2);
  btn2radio2.attachPush(btn2PushCallback, &btn2radio2);
  btn3radio2.attachPush(btn3PushCallback, &btn3radio2);

  //Page 2: Schalter
  bMuteSwitch2.attachPop(bMuteSwitch2PopCallback, &bMuteSwitch2);  // Mute/Unmute Switch
  //4er Buttons
  btn0switch2.attachPush(btn0PushCallback, &btn0switch2);
  btn1switch2.attachPush(btn1PushCallback, &btn1switch2);
  btn2switch2.attachPush(btn2PushCallback, &btn2switch2);
  btn3switch2.attachPush(btn3PushCallback, &btn3switch2);



  // PAGE 3
  //Page 3: Podcast
  bMutePod3.attachPush(bMutePodcast3PushCallback, &bMutePod3);     // Mute Button 
  bMutePod3.attachPop(bMutePodcast3PopCallback, &bMutePod3);       // Unmute Button 
  //4er Buttons
  btn0pod3.attachPush(btn0PushCallback, &btn0pod3);
  btn1pod3.attachPush(btn1PushCallback, &btn1pod3);
  btn2pod3.attachPush(btn2PushCallback, &btn2pod3);
  btn3pod3.attachPush(btn3PushCallback, &btn3pod3);

  //Page 3: Radio
  bMuteRadio3.attachPush(bMuteRadio3PushCallback, &bMuteRadio3);   // Unmute Button 
  bMuteRadio3.attachPop(bMuteRadio3PopCallback, &bMuteRadio3);     // Mute Button 
  //4er Buttons
  btn0radio3.attachPush(btn0PushCallback, &btn0radio3);
  btn1radio3.attachPush(btn1PushCallback, &btn1radio3);
  btn2radio3.attachPush(btn2PushCallback, &btn2radio3);
  btn3radio3.attachPush(btn3PushCallback, &btn3radio3);

  //Page 3: Schalter
  bMuteSwitch3.attachPop(bMuteSwitch3PopCallback, &bMuteSwitch3);  // Mute/Unmute Switch
  //4er Buttons
  btn0switch3.attachPush(btn0PushCallback, &btn0switch3);
  btn1switch3.attachPush(btn1PushCallback, &btn1switch3);
  btn2switch3.attachPush(btn2PushCallback, &btn2switch3);
  btn3switch3.attachPush(btn3PushCallback, &btn3switch3);



  // PAGE 4
  //Page 4: Podcast
  bMutePod4.attachPush(bMutePodcast4PushCallback, &bMutePod4);     // Mute Button 
  bMutePod4.attachPop(bMutePodcast4PopCallback, &bMutePod4);       // Unmute Button 
  //4er Buttons
  btn0pod4.attachPush(btn0PushCallback, &btn0pod4);
  btn1pod4.attachPush(btn1PushCallback, &btn1pod4);
  btn2pod4.attachPush(btn2PushCallback, &btn2pod4);
  btn3pod4.attachPush(btn3PushCallback, &btn3pod4);

  //Page 4: Radio
  bMuteRadio4.attachPush(bMuteRadio4PushCallback, &bMuteRadio4);   // Unmute Button 
  bMuteRadio4.attachPop(bMuteRadio4PopCallback, &bMuteRadio4);     // Mute Button 
  //4er Buttons
  btn0radio4.attachPush(btn0PushCallback, &btn0radio4);
  btn1radio4.attachPush(btn1PushCallback, &btn1radio4);
  btn2radio4.attachPush(btn2PushCallback, &btn2radio4);
  btn3radio4.attachPush(btn3PushCallback, &btn3radio4);

  //Page 4: Schalter
  bMuteSwitch4.attachPop(bMuteSwitch4PopCallback, &bMuteSwitch4);  // Mute/Unmute Switch
  //4er Buttons
  btn0switch4.attachPush(btn0PushCallback, &btn0switch4);
  btn1switch4.attachPush(btn1PushCallback, &btn1switch4);
  btn2switch4.attachPush(btn2PushCallback, &btn2switch4);
  btn3switch4.attachPush(btn3PushCallback, &btn3switch4);
*/
  

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
