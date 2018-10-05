/**
 * Mute or Unmute
 * 
 * Speak("ON/OFF");
 */
void Speak(String State, int Page){
  //Unmute
  if(State == "ON"){
    sendMidiCC(191, Page, 0);      // Unmute: CH 16; C (1,2,3,4);  Vel 0
  }
  //Mute
  if(State == "OFF"){
    sendMidiCC(191, Page, 127);    // Mute:  CH 16; C (1,2,3,4);  Vel 127
  }
}

//------------------------- Functions --------------------

/**
 * sendMIDICC() 
 * 
 * Infos: CC = Continuous Controller (vordefinierter oder festgelegter Controller)
 * 
 * Status Bit:         1     |     0   1   1    |  1   1   1   1
 * --------------------------------------------------------------
 * Dez                128    |    64  32  16    |  8   4   2   1
 * --------------------------------------------------------------
 *                  Neue Msg |  Control Change  |    Channel
 * 
 * Data Byte 1: Controler Number
 * Data Byte 2: Velue 0/127 (an/aus)
 * 
 */
void sendMidiCC(int channel, int controler, int value) {
  Serial.write(channel);    // Channel: 176 bis 191 (0xB0)
  Serial.write(controler);  // Controler Number: 0-99
  Serial.write(value);      // On/Off: 0/127
}

/**
 * sendMidiNote()
 * 
 * Wird die Taste gedrückt wird der Wert über TasterSave gespeichert
 * und eine Note gesendet.
 * 
 * Ist der Taster nicht gedrückt wird die Note mit der Länge beendet.
 * 
 * MIDI Beispiel:
 * -----------------------------------------------------
 * 
 * (1.) Packet = Status Byte (1 Byte / 8 Bit)
 * 
 * 8 Bit       0        |     0  0   0     | 0    0   0   0
 * ----------------------------------------------------------
 * Potenz     2/7 (-1)  |    2/6 2/5 2/4   | 2/3 2/2 2/1 2/0
 * ----------------------------------------------------------
 * Dez        128       |    64  32  16    | 8    4   2   1
 * ----------------------------------------------------------
 * 
 * Status      1        |     0  0   1     | 0    0   0   0 
 * ----------------------------------------------------------
 *       Neue Nachricht |     Note on      |      Kanal 1
 *
 * Rechnung:  128 + 16
 *            10010000 = 144
 *                    
 * Kanal 01 = 144
 * Kanal 02 = 145
 * Kanal 03 = 146
 * Kanal 04 = 147
 * Kanal 05 = 148
 * Kanal 06 = 149
 * Kanal 07 = 150
 * Kanal 08 = 151
 * Kanal 09 = 152
 * Kanal 10 = 153
 * Kanal 11 = 154
 * Kanal 12 = 155
 * Kanal 13 = 156
 * Kanal 14 = 157
 * Kanal 15 = 158
 * Kanal 16 = 159
 *
 * 
 * (2.) Packet = Data Bit
 * 
 * Beispiel: 0 001 0000
 * 
 * Data   0        |     0  0   1     |     0    0    0    0 
 * --------------------------------------------------------------------
 *       Nachricht |  Notenwert (kk)  | Velocity (vv = Anschlagsstärke)
 * 
 * Notenwerte:
 *   Note(24, 0);   //C1
 *   Note(36, 0);   //C2
 *   Note(48, 0);   //C3 (standard)
 *   Note(60, 0);   //C4 
 *   Note(72, 0);   //C5
 *   Note(84, 0);   //C6
 *   Note(96, 0);   //C7
 *   Note(108, 0);  //C8
 * 
 * (3.) Packet = Data Bit
 * 
 *  Velocity = 0 bis 127
 */
void sendMidiNote(int Channel, int Note, int Velocity) {
  Serial.write(Channel);    // Note on/off, Channel: 1-16
  Serial.write(Note);       // Note: (kk) 1-128
  Serial.write(Velocity);   // Velocity:  (vv) 0-127
}
