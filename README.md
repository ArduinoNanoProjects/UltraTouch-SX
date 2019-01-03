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

## Overview

UltraTouch SX ist ein Midi-Controller für Podcaster. Sie kann als Räuspertaste aufgebaut und genutzt werden. Dies ist eine kleine Idee, wie ein Controller erarbeitet und gebaut werden kann:   

<img src="https://raw.githubusercontent.com/ArduinoNanoProjects/UltraTouch-SX/master/UltraTouchV6_Overview.gif" alt="UltraTouch V6 - Overview">

## Arduino Code

Hier findet sich der <a href="https://github.com/ArduinoNanoProjects/UltraTouch-SX/blob/master/UltraTouchSX.ino/UltraTouchSX/UltraTouchSX.ino">Beispiel Code</a> meiner UltraTouch SX in der Version 6.0 Variante. Für dieses Projekt habe ich den <a href="https://store.arduino.cc/arduino-nano">Arduino Nano [0]</a> verwendet. Beachte, wenn Du größere Projekte aufbauen möchtest oder mehr Buttons benötigst, braucht dein Arduino mehr Speicher. Du benötigst daher, auf jedem Falle einen größeren Arduino für dein Projekt!

## Nextion Display

Das <a href="https://nextion.itead.cc">NextionDisplay [1]</a> ist eine einfache Möglichkeit sein eigenes Design und zusätzliche Software zu entwickeln. Die Software wird dabei direkt auf das Display gefläscht und kann über den Arduino angesprochen werden. Das in dieser Version genutzte Display ist das HMI TFT LCD Touch Display Module: 
<a href="https://www.itead.cc/nextion-nx4832t035.html">Nextion NX4832T035 - 3.5" [2]</a> (480 * 320). 

### Design Screen

Zur Entwicklung des Designs wurde <a href="https://www.adobe.com/de/products/photoshop.html">Photoshop <i>(R)(C)</i> [3]</a> benutzt. Das Design kann <a href="https://github.com/ArduinoNanoProjects/UltraTouch-SX/tree/master/NextionDisplay/PSD">hier</a> geladen und verändert werden. 

Des weiteren wird die Nextion Editor IDE benötigt um den Kernel des Systems zu entwickeln. Sie ist leider nur für Windows nutzbar und kann <a href="https://nextion.itead.cc/resources/download/">hier [4]</a> heruntergeladen werden. 

<img src="https://raw.githubusercontent.com/ArduinoNanoProjects/UltraTouch-SX/master/NextionDisplay/Screenshot4.png"/>


Zum laden des Projektes muss die <a href="https://github.com/ArduinoNanoProjects/UltraTouch-SX/blob/master/NextionDisplay/UltraTouchSX-LCARS.HMI">UltraTouchSX-LCARS.HMI</a> mit dem <i>Nextion Exitor</i> geladen werden.




#### Loading Screen
<img src="https://raw.githubusercontent.com/ArduinoNanoProjects/UltraTouch-SX/master/NextionDisplay/Screenshot.png"/>

#### Mute/Unmute Screen
<img src="https://raw.githubusercontent.com/ArduinoNanoProjects/UltraTouch-SX/master/NextionDisplay/Screenshot1.png"/> <img src="https://raw.githubusercontent.com/ArduinoNanoProjects/UltraTouch-SX/master/NextionDisplay/Screenshot2.png"/>

#### Settings Screen

<img src="https://raw.githubusercontent.com/ArduinoNanoProjects/UltraTouch-SX/master/NextionDisplay/Screenshot3.png"/>


### 3D Model

<img src="https://raw.githubusercontent.com/ArduinoNanoProjects/UltraTouch-SX/master/3D-Model/Model.png" alt="UltraTouch Model für 3D Printer">



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
