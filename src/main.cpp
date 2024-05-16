#include <Arduino.h>
/*** AT1 - slave 0x12
 AT1 of DryBot v2.3a, may 10 2024.
 */
#include <Wire.h>
#define FOR(I,N) for(int I=0;I<N;I++)
#define PA0 17 //UPDI
#define PA1 14 //MOSI
#define PA2 15 //MISO
#define PA3 16 //CLK
#define PA4 0  //SS
#define PA5 1  
#define PA6 2  //DAC
#define PA7 3
#define PB0 9 //SCL
#define PB1 8 //SDA
#define PB2 7 //TXD
#define PB3 6 //RXD
#define PB4 5 
#define PB5 4 
#define PC0 10
#define PC1 11
#define PC2 12
#define PC3 13
int RGB_G = PB4;
int RGB_B = PB5;
int RGB_R = PA3;
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
    analogWrite(RGB_R,(val>>16) & 0xFF);
    analogWrite(RGB_G,(val>>8)  & 0xFF);
    analogWrite(RGB_B,val       & 0xFF);
}