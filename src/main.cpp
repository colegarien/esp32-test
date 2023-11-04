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

#define DEBOUNCE 5

#define NUM_KEYS 28
int keys[NUM_KEYS];

void setup() {
  pinMode(ROW_0, OUTPUT);
  pinMode(ROW_1, OUTPUT);
  pinMode(ROW_2, OUTPUT);
  pinMode(ROW_3, OUTPUT);

  pinMode(COL_0, INPUT);
  pinMode(COL_1, INPUT);
  pinMode(COL_2, INPUT);
  pinMode(COL_3, INPUT);
  pinMode(COL_4, INPUT);
  pinMode(COL_5, INPUT);
  pinMode(COL_6, INPUT);
  pinMode(COL_7, INPUT);

  Serial.begin(9600);
}

void loop() {
  Serial.println("Testing Rows!");

  int key = 0;

  digitalWrite(ROW_0, HIGH);
  delay(DEBOUNCE); // debounce for a few milliseconds
  keys[key++] = digitalRead(COL_0);
  keys[key++] = digitalRead(COL_1);
  keys[key++] = digitalRead(COL_2);
  keys[key++] = digitalRead(COL_3);
  keys[key++] = digitalRead(COL_4);
  keys[key++] = digitalRead(COL_5);
  keys[key++] = digitalRead(COL_6);
  keys[key++] = digitalRead(COL_7);
  digitalWrite(ROW_0, LOW);

  digitalWrite(ROW_1, HIGH);
  delay(DEBOUNCE); // debounce for a few milliseconds
  keys[key++] = digitalRead(COL_0);
  keys[key++] = digitalRead(COL_1);
  keys[key++] = digitalRead(COL_2);
  keys[key++] = digitalRead(COL_3);
  keys[key++] = digitalRead(COL_4);
  keys[key++] = digitalRead(COL_5);
  keys[key++] = digitalRead(COL_6);
  keys[key++] = digitalRead(COL_7);
  digitalWrite(ROW_1, LOW);

  digitalWrite(ROW_2, HIGH);
  delay(DEBOUNCE); // debounce for a few milliseconds
  keys[key++] = digitalRead(COL_0);
  keys[key++] = digitalRead(COL_1);
  keys[key++] = digitalRead(COL_2);
  keys[key++] = digitalRead(COL_3);
  keys[key++] = digitalRead(COL_4);
  keys[key++] = digitalRead(COL_5);
  keys[key++] = digitalRead(COL_6);
  keys[key++] = digitalRead(COL_7);
  digitalWrite(ROW_2, LOW);

  digitalWrite(ROW_3, HIGH);
  delay(DEBOUNCE); // debounce for a few milliseconds
  keys[key++] = digitalRead(COL_0);
  keys[key++] = digitalRead(COL_1);
  keys[key++] = digitalRead(COL_2);
  keys[key++] = digitalRead(COL_3);
  digitalWrite(ROW_3, LOW);

  Serial.println("Key States: ");
  for(int i = 0; i < NUM_KEYS; i++) {
    if(keys[i]) {
      Serial.print("X");
    } else {
      Serial.print(" ");
    }
    Serial.print("|");
  }
  Serial.println("");

  delay(2000);
}
