 <pre>
 _   _  _  _                 _____                      _       _____ __   __
| | | || || |               |_   _|                    | |     /  ___|\ \ / /
| | | || || |_  _ __   __ _   | |    ___   _   _   ___ | |__   \ `--.  \ V /
| | | || || __|| '__| / _` |  | |   / _ \ | | | | / __|| '_ \   `--. \ /   \
| |_| || || |_ | |   | (_| |  | |  | (_) || |_| || (__ | | | | /\__/ // /^\ \
 \___/ |_| \__||_|    \__,_|  \_/   \___/  \__,_| \___||_| |_| \____/ \/   \/
 
Die Version der UltraTouch SX (Version 6) ist ausgestattet mit einem Nextion Display 
und sie versendet MIDI zur Nutzung der Räuspertasten. Sie kann vielseitig genutzt 
und erweitert werden ;)

Diese Idee entstand im Rahmen des Ultraschall-Projektes zum Themea: “MIDI Controller". 
Es gibt viele weitere Projekte von meinen Kollegen und der Podcast Community. 
Schau doch mal hier vorbei: https://ultraschall.fm

@developer   Michael McCouman Jr.
@version     UT[SX] V6
@date        04.Okt 2018 - 03. Jan 2019
@git:        https://github.com/McCouman
@website     https://wikibyte.org

Licence:     CC BY-NC-SA 4.0
Link:        https://creativecommons.org/licenses/by-nc-sa/4.0/deed.de
</pre>

# Overview

UltraTouch SX ist ein Midi-Controller für Podcaster. Sie kann als Räuspertaste aufgebaut und genutzt werden. Dies ist eine kleine Idee, wie ein Controller erarbeitet und gebaut werden kann:   

<img src="https://raw.githubusercontent.com/ArduinoNanoProjects/UltraTouch-SX/master/UltraTouchV6_Overview.gif" alt="UltraTouch V6 - Overview">

## Hard- und Software

### Arduino

Für dieses Projekt habe ich den <a href="https://store.arduino.cc/arduino-nano">Arduino Nano [0]</a> verwendet. Beachte, wenn Du größere Projekte aufbauen möchtest oder mehr Buttons benötigst, braucht dein Arduino mehr Speicher. Du benötigst daher, auf jedem Falle einen größeren Arduino für dein Projekt!

<img src="https://raw.githubusercontent.com/ArduinoNanoProjects/UltraTouch-SX/master/UltraTouchSX.ino/Arduino%20Nano.png"/>


### HC-SR04 Sensor

Das Ultraschall Modul HC-SR04 eignet sich zur Entfernungsmessung im Bereich zwischen 2cm und 2,5m mit einer Auflösung von 3mm. Es benötigt eine Versorgungsspannung von 5V bei einer Stromaufnahme von <2mA. Nach Triggerung misst das Modul
selbstständig die Entfernung und wandelt diese in ein PWM Signal welches am Ausgang zur Verfügung steht. Ein Messintervall hat dabei eine Dauer von 20ms. Es können daher 50 Messungen pro Sekunde durchgeführt werden. Es dient hier der schnellen und einfachen Lautstärkenanpassung über <i>Reaper Ultraschall</i>.

<img src="https://raw.githubusercontent.com/ArduinoNanoProjects/UltraTouch-SX/master/UltraTouchSX.ino/HC-SR04.png"/>


### WS-2812-B NeoPixel

<img src="https://raw.githubusercontent.com/ArduinoNanoProjects/UltraTouch-SX/master/UltraTouchSX.ino/NeoPixel.png"/>

Ein WS2812B wird auch kurz Neopixel genannt und es handelt sich hier um feste oder als Streifen vorhältige RGB LED. Ich habe für den beleuchteten Boden, 6 NeoPixel genutzt. Es können natürlich mehr oder weniger genutzt werden ;)

<img src="https://raw.githubusercontent.com/ArduinoNanoProjects/UltraTouch-SX/master/UltraTouchSX.ino/WS2812B.png"/> 


### Nextion Display

Das <a href="https://nextion.itead.cc">NextionDisplay [1]</a> ist eine einfache Möglichkeit sein eigenes Design und zusätzliche Software zu entwickeln. 

<img src="https://raw.githubusercontent.com/ArduinoNanoProjects/UltraTouch-SX/master/UltraTouchSX.ino/Nextion Display.png"/> 

Die Software wird dabei direkt auf das Display gefläscht und kann über den Arduino angesprochen werden. Das in dieser Version genutzte Display ist das HMI TFT LCD Touch Display Module: <a href="https://www.itead.cc/nextion-nx4832t035.html">Nextion NX4832T035 - 3.5" [2]</a> (480 * 320). 

## Development

### LCARS Style (Design 2019)

Zur Entwicklung des Designs wurde <a href="https://www.adobe.com/de/products/photoshop.html">Photoshop <i>(R)(C)</i> [3]</a> benutzt. Das Design kann <a href="https://github.com/ArduinoNanoProjects/UltraTouch-SX/raw/master/NextionDisplay/UltraTouchSX-LCARS_2019/Data/PSD/UltraTouchSX-LCARS.psd">hier</a> geladen und verändert werden.

#### Load Screen
<img src="https://raw.githubusercontent.com/ArduinoNanoProjects/UltraTouch-SX/master/NextionDisplay/UltraTouchSX-LCARS_2019/Data/Screenshot.png"/>

##### Mute/Unmute Screen
<img src="https://raw.githubusercontent.com/ArduinoNanoProjects/UltraTouch-SX/master/NextionDisplay/UltraTouchSX-LCARS_2019/Data/Screenshot1.png"/> <img src="https://raw.githubusercontent.com/ArduinoNanoProjects/UltraTouch-SX/master/NextionDisplay/UltraTouchSX-LCARS_2019/Data/Screenshot2.png"/>

##### Settings Screen
<img src="https://raw.githubusercontent.com/ArduinoNanoProjects/UltraTouch-SX/master/NextionDisplay/UltraTouchSX-LCARS_2019/Data/Screenshot3.png"/>


### U4 Style (Design 2020)

Zur Entwicklung des Designs wurde <a href="https://www.adobe.com/de/products/photoshop.html">Photoshop <i>(R)(C)</i> [3]</a> benutzt. Das Design 2020 kann <a href="https://github.com/ArduinoNanoProjects/UltraTouch-SX/raw/master/NextionDisplay/UltraTouchSX-U4_2020/Design-UltraTouch%20SX6%20US4/PSD/UltraTouchSX-U4.psd">hier</a> geladen und verändert werden.

Lade das "Betriebssystem" (<a href="https://github.com/ArduinoNanoProjects/UltraTouch-SX/raw/master/NextionDisplay/UltraTouchSX-U4_2020/UltraTouchSX6-US4.HMI">HMI</a>) auf das Nextion Display. Bearbeiten kannst Du es über das <a href="https://github.com/ArduinoNanoProjects/UltraTouch-SX/raw/master/NextionDisplay/UltraTouchSX-U4_2020/Design-UltraTouch%20SX6%20US4/UltraTouchSX6-US4.tft>UltraTouchSX6-US4.tft</a>.

#### Load Screen
<img src="https://github.com/ArduinoNanoProjects/UltraTouch-SX/raw/master/NextionDisplay/UltraTouchSX-U4_2020/Design-UltraTouch%20SX6%20US4/Screens/Welcome/UltraTouchSX-U4_Welcome002.png"/>

##### Mute/Unmute Screen
<img src="https://github.com/ArduinoNanoProjects/UltraTouch-SX/raw/master/NextionDisplay/UltraTouchSX-U4_2020/Design-UltraTouch%20SX6%20US4/Screens/Page_Podcast/UltraTouchSX-US4_Podcast-Start_001.png"/> <img src="https://github.com/ArduinoNanoProjects/UltraTouch-SX/raw/master/NextionDisplay/UltraTouchSX-U4_2020/Design-UltraTouch%20SX6%20US4/Screens/Page_Podcast/UltraTouchSX-US4_Podcast-Mute.png"/>

##### Settings Screen
<img src="https://github.com/ArduinoNanoProjects/UltraTouch-SX/raw/master/NextionDisplay/UltraTouchSX-U4_2020/Design-UltraTouch%20SX6%20US4/Screens/Page_Settings/UltraTouchSX-US4_Settings-ON.png"/> <img src="https://github.com/ArduinoNanoProjects/UltraTouch-SX/raw/master/NextionDisplay/UltraTouchSX-U4_2020/Design-UltraTouch%20SX6%20US4/Screens/Page_Settings/Coloring/UltraTouchSX-Color-Gruen.png"/>




#### 3D-Modell

<a href="https://github.com/ArduinoNanoProjects/UltraTouch-SX/tree/master/3D-Model">Hier</a> findest Du die 3d Modelle für das Gehäuse der UltraTouch SX für deinen 3D Printer. Ich habe hier den Desktop 3D-Drucker (Ender 2) genutzt, um das Gehäuse zu drucken. Der Druck besteht aus fünf einzelnen Modellen, die ich jedoch mit unterschiedlichen Materialien gedruckt habe:

<img src="https://raw.githubusercontent.com/ArduinoNanoProjects/UltraTouch-SX/master/3D-Model/Model.png" alt="UltraTouch Model für 3D Printer">

- Body: ist das Gehäuse (schwarz: PLA)
- top_box: ist der Verbund für das Display (silber: PLA)
- Top: ist der obere Bereich der LED Box (silber: PETG)
- Bottom: ist der untere Bereich der LED Box (silber: PETG)
- Transparent: ist der Transparente Bereich der LED Box (transparent, dark glow: PLA)

*Achtung: Je nach Material gibt es unterschiedliche fließverhalten der Kunststoffe. Sie haben daher unterschiedlichen Schwund beim Drucken. Möchte man ein z.B. rein PLA-Material nutzen, so muss das Design angepasst werden oder nachträglich bearbeitet werden.*

### GUI Development

Des weiteren wird die IDE: Nextion Editor benötigt, um den Kernel der GUI als laufendes Systems zu entwickeln. Die Software  ist leider nur für Windows erhältlich und kann direkt auf der Website von <a href="https://nextion.itead.cc/resources/download/">Nextion [4]</a> heruntergeladen werden. 

<img src="https://raw.githubusercontent.com/ArduinoNanoProjects/UltraTouch-SX/master/NextionDisplay/Screenshot4.png"/>

Zum laden des Projektes muss die <a href="https://github.com/ArduinoNanoProjects/UltraTouch-SX/blob/master/NextionDisplay/UltraTouchSX-LCARS.HMI">UltraTouchSX-LCARS.HMI</a> mit dem <i>Nextion Exitor</i> geladen werden.

### API Development

Hier findet sich der <a href="https://github.com/ArduinoNanoProjects/UltraTouch-SX/blob/master/UltraTouchSX.ino/UltraTouchSX/UltraTouchSX.ino">Beispiel Code</a> meiner UltraTouch SX in der Version 6.0 Variante. 



## Externe Links
- [0] Arduino Nano: https://store.arduino.cc/arduino-nano
- [1] Nextion Website: https://nextion.itead.cc
- [2] Nextion Display 3,5": https://www.itead.cc/nextion-nx4832t035.html
- [3] Photoshop: https://www.adobe.com/de/products/photoshop.html
- [4] Nextion Editor: https://nextion.itead.cc/resources/download/


## Lizenz
Diese Software steht unter CC BY-NC-SA 4.0 - Lizenz: Namensnennung - Nicht-kommerziell - Weitergabe unter gleichen Bedingungen 4.0 International (CC BY-NC-SA 4.0)

Dies ist eine allgemeinverständliche Zusammenfassung der Lizenz (die diese nicht ersetzt). Haftungsbeschränkung.

**Sie dürfen:**

* Teilen — das Material in jedwedem Format oder Medium vervielfältigen und weiterverbreiten
* Bearbeiten — das Material remixen, verändern und darauf aufbauen

Der Lizenzgeber kann diese Freiheiten nicht widerrufen solange Sie sich an die Lizenzbedingungen halten.

**Unter folgenden Bedingungen:**

* Namensnennung — Sie müssen angemessene Urheber- und Rechteangaben machen, einen Link zur Lizenz beifügen und angeben, ob Änderungen vorgenommen wurden. Diese Angaben dürfen in jeder angemessenen Art und Weise gemacht werden, allerdings nicht so, dass der Eindruck entsteht, der Lizenzgeber unterstütze gerade Sie oder Ihre Nutzung besonders.

* Nicht kommerziell — Sie dürfen das Material nicht für kommerzielle Zwecke nutzen.

* Weitergabe unter gleichen Bedingungen — Wenn Sie das Material remixen, verändern oder anderweitig direkt darauf aufbauen, dürfen Sie Ihre Beiträge nur unter derselben Lizenz wie das Original verbreiten.

* Keine weiteren Einschränkungen — Sie dürfen keine zusätzlichen Klauseln oder technische Verfahren einsetzen, die anderen rechtlich irgendetwas untersagen, was die Lizenz erlaubt.

**Hinweise:**

Sie müssen sich nicht an diese Lizenz halten hinsichtlich solcher Teile des Materials, die gemeinfrei sind, oder soweit Ihre Nutzungshandlungen durch Ausnahmen und Schranken des Urheberrechts gedeckt sind.

Es werden keine Garantien gegeben und auch keine Gewähr geleistet. Die Lizenz verschafft Ihnen möglicherweise nicht alle Erlaubnisse, die Sie für die jeweilige Nutzung brauchen. Es können beispielsweise andere Rechte wie Persönlichkeits- und Datenschutzrechte zu beachten sein, die Ihre Nutzung des Materials entsprechend beschränken.

Link: https://creativecommons.org/licenses/by-nc-sa/4.0/deed.de
