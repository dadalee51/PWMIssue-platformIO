#include <Arduino.h>
void setup() {
  pinMode(PIN_PB5, OUTPUT);
  analogWrite(PIN_PB5, 0xF0);
}
void loop(){
    analogWrite(PIN_PB5, 0x80);
    delay(100);
    analogWrite(PIN_PB5, 0xAF);
    delay(100);
    
    delay(10);
    
};