#include <Arduino.h>

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
}

void loop() {
  int key = 0;

  previousKeyState = keyState;
  keyState = 0;

  digitalWrite(ROW_0, HIGH);
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
  delay(DEBOUNCE); // debounce for a few milliseconds
  keyState |= (digitalRead(COL_0) ? 1 : 0) << key++;
  keyState |= (digitalRead(COL_1) ? 1 : 0) << key++;
  keyState |= (digitalRead(COL_2) ? 1 : 0) << key++;
  keyState |= (digitalRead(COL_3) ? 1 : 0) << key++;
  digitalWrite(ROW_3, LOW);


  if (previousKeyState != keyState) {
    Serial.println(" A ^ B C ^ D ^ E F ^ G ^ A ^ B C ^ D ^ E F ^ G ^ A ^ B C ");
    Serial.println(" 0 1 2 3 4 5 6 7|0 1 2 3 4 5 6 7|0 1 2 3 4 5 6 7|0 1 2 3 ");
    Serial.print("[");
    for(int32_t i = 0; i < NUM_KEYS; i++) {
      if(keyState & (1 << i)) {
        Serial.print("X");
      } else {
        Serial.print(" ");
      }

      if (i < NUM_KEYS-1) {
        Serial.print("|");
      }
    }
    Serial.println("]");
  }
}
