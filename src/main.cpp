#include <Arduino.h>

void setup() {
  pinMode(PIN_PB5, OUTPUT);
  analogWrite(PIN_PB5, 0xF0);
}

void loop(){
    #ifdef ARDUINO_MAIN
    analogWrite(PIN_PB5, 0x80);
    delay(100);
    analogWrite(PIN_PB5, 0x70);
    delay(100);
    #endif
    delay(10);
    
};