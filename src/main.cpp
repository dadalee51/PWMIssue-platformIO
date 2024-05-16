#include <Arduino.h>
#include <Wire.h>
#define FOR(I,N) for(int I=0;I<N;I++)
void show_RGB(long val);
void setup() {
  pinMode(PIN_PB3, OUTPUT);
  pinMode(PIN_PB4, OUTPUT);
  pinMode(PIN_PB5, OUTPUT);
  PORTMUX_CTRLC |= PORTMUX_TCA00_bm | PORTMUX_TCA01_bm | PORTMUX_TCA02_bm;
  show_RGB(0xFFFF00); 
}
void loop() {  
    show_RGB(0xFFFF00); 
    delay(500);
    show_RGB(0xFFFFAA);
    delay(500);
}
void show_RGB(long val){
    analogWrite(PIN_PB3,(val>>16) & 0xFF);
    analogWrite(PIN_PB4,(val>>8)  & 0xFF);
    analogWrite(PIN_PB5,val       & 0xFF);
}