#include <Arduino.h>
#include <Arduino.h>
#include <HardwareSerial.h>
#include <MIDI.h>


#define ROW_0 13
#define ROW_1 12
#define ROW_2 14
#define ROW_3 27

#define COL_0 26
#define COL_1 25
#define COL_2 33
#define COL_3 32
#define COL_4 35
#define COL_5 34
#define COL_6 39
#define COL_7 36

#define DEBOUNCE 10

#define NUM_KEYS 28
int32_t previousKeyState = 0;
int32_t keyState = 0;

MIDI_CREATE_INSTANCE(HardwareSerial, Serial2, DIN_MIDI);

void setup() {
  pinMode(ROW_0, OUTPUT);
  pinMode(ROW_1, OUTPUT);
  pinMode(ROW_2, OUTPUT);
  pinMode(ROW_3, OUTPUT);

  pinMode(COL_0, INPUT_PULLDOWN);
  pinMode(COL_1, INPUT_PULLDOWN);
  pinMode(COL_2, INPUT_PULLDOWN);
  pinMode(COL_3, INPUT_PULLDOWN);
  pinMode(COL_4, INPUT_PULLDOWN);
  pinMode(COL_5, INPUT_PULLDOWN);
  pinMode(COL_6, INPUT_PULLDOWN);
  pinMode(COL_7, INPUT_PULLDOWN);

  Serial.begin(9600);
  DIN_MIDI.begin(MIDI_CHANNEL_OMNI);
  delay(300);
}

void loop() {
  int key = 0;

  previousKeyState = keyState;
  keyState = 0;

  digitalWrite(ROW_0, HIGH);
  // Read incoming messages
  DIN_MIDI.read();
  delay(DEBOUNCE); // debounce for a few milliseconds
  keyState |= (digitalRead(COL_0) ? 1 : 0) << key++;
  keyState |= (digitalRead(COL_1) ? 1 : 0) << key++;
  keyState |= (digitalRead(COL_2) ? 1 : 0) << key++;
  keyState |= (digitalRead(COL_3) ? 1 : 0) << key++;
  keyState |= (digitalRead(COL_4) ? 1 : 0) << key++;
  keyState |= (digitalRead(COL_5) ? 1 : 0) << key++;
  keyState |= (digitalRead(COL_6) ? 1 : 0) << key++;
  keyState |= (digitalRead(COL_7) ? 1 : 0) << key++;
  digitalWrite(ROW_0, LOW);

  digitalWrite(ROW_1, HIGH);
  // Read incoming messages
  DIN_MIDI.read();
  delay(DEBOUNCE); // debounce for a few milliseconds
  keyState |= (digitalRead(COL_0) ? 1 : 0) << key++;
  keyState |= (digitalRead(COL_1) ? 1 : 0) << key++;
  keyState |= (digitalRead(COL_2) ? 1 : 0) << key++;
  keyState |= (digitalRead(COL_3) ? 1 : 0) << key++;
  keyState |= (digitalRead(COL_4) ? 1 : 0) << key++;
  keyState |= (digitalRead(COL_5) ? 1 : 0) << key++;
  keyState |= (digitalRead(COL_6) ? 1 : 0) << key++;
  keyState |= (digitalRead(COL_7) ? 1 : 0) << key++;
  digitalWrite(ROW_1, LOW);

  digitalWrite(ROW_2, HIGH);
  // Read incoming messages
  DIN_MIDI.read();
  delay(DEBOUNCE); // debounce for a few milliseconds
  keyState |= (digitalRead(COL_0) ? 1 : 0) << key++;
  keyState |= (digitalRead(COL_1) ? 1 : 0) << key++;
  keyState |= (digitalRead(COL_2) ? 1 : 0) << key++;
  keyState |= (digitalRead(COL_3) ? 1 : 0) << key++;
  keyState |= (digitalRead(COL_4) ? 1 : 0) << key++;
  keyState |= (digitalRead(COL_5) ? 1 : 0) << key++;
  keyState |= (digitalRead(COL_6) ? 1 : 0) << key++;
  keyState |= (digitalRead(COL_7) ? 1 : 0) << key++;
  digitalWrite(ROW_2, LOW);

  digitalWrite(ROW_3, HIGH);
  // Read incoming messages
  DIN_MIDI.read();
  delay(DEBOUNCE); // debounce for a few milliseconds
  keyState |= (digitalRead(COL_0) ? 1 : 0) << key++;
  keyState |= (digitalRead(COL_1) ? 1 : 0) << key++;
  keyState |= (digitalRead(COL_2) ? 1 : 0) << key++;
  keyState |= (digitalRead(COL_3) ? 1 : 0) << key++;
  digitalWrite(ROW_3, LOW);


  if (previousKeyState != keyState) {
    std::string activeNotes = "[";
    for(int32_t i = 0; i < NUM_KEYS; i++) {
      int note = 0x21 + i; // start at A1
      bool keyOn = keyState & (1 << i);
      bool prevKeyOn = previousKeyState & (1 << i);
      if (keyOn) {
        activeNotes += "X";
        if (!prevKeyOn) {
          DIN_MIDI.sendNoteOn(note, 63, 1);
        }
      } else {
        activeNotes += " ";
        if (prevKeyOn) {
          DIN_MIDI.sendNoteOn(note, 0, 1);
        }
      }

      if (i < NUM_KEYS-1) {
        activeNotes += "|";
      }
    }
    activeNotes += "]";
    Serial.println(" A ^ B C ^ D ^ E F ^ G ^ A ^ B C ^ D ^ E F ^ G ^ A ^ B C \n 0 1 2 3 4 5 6 7|0 1 2 3 4 5 6 7|0 1 2 3 4 5 6 7|0 1 2 3 ");
    Serial.println(activeNotes.c_str());
  }

  // Read incoming messages
  DIN_MIDI.read();
}
