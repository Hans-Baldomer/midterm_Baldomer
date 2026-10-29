// GPIOS
const byte ir_up = 36;
const byte ir_dn = 39;
const byte rst = 3;

#include "decoder.h"

// Variables
int counter = 0;
int inputAdd = 0;
int inputSub = 0;
int rst_in = 0;

void setup() {
  pinMode(ir_up, INPUT);
  pinMode(ir_dn, INPUT);
  pinMode(rst, INPUT_PULLUP);
  // Initialize 7-segment display pins
  initDisplay();

  Serial.begin(9600);
}

void loop() {
rst_in = digitalRead(rst);
if (rst_in == HIGH){

  inputAdd = digitalRead(ir_up);
  if (inputAdd == 0) {
    if (counter < 99) {
      counter++;
    }
    delay(300);
  }

  inputSub = digitalRead(ir_dn);
  if (inputSub == 0) {
    if (counter > 0) {
      counter--;
    }
    delay(300);
  }

  displayCounter(counter);
} else {
  counter = 8;
  }
  delay(50);
}