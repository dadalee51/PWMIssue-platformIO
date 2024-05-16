#include <Arduino.h>
#include <Wire.h>
#define FOR(I,N) for(int I=0;I<N;I++)
void show_RGB(long val);
void setup() {
  pinMode(PIN_PA3, OUTPUT);
  pinMode(PIN_PB3, OUTPUT);
  pinMode(PIN_PB4, OUTPUT);
  pinMode(PIN_PB5, OUTPUT);

  CLKCTRL_MCLKCTRLA = 0x00; //no effect. defaulted. 
  // PORTMUX_CTRLC |= PORTMUX_TCA00_bm | PORTMUX_TCA01_bm | PORTMUX_TCA02_bm;
  // PORTB.DIRSET = PIN3_bm | PIN4_bm | PIN5_bm; // Set PB3, PB4, PB5 as output
  //   TCA0.SINGLE.CTRLG = TCA_SINGLE_CMP0_bm | TCA_SINGLE_CMP1_bm | TCA_SINGLE_CMP2_bm; // Enable compare channels 0, 1, 2
  //   TCA0.SINGLE.CTRLB = TCA_SINGLE_WGMODE_SINGLESLOPE_gc | TCA_SINGLE_CMP0EN_bm | TCA_SINGLE_CMP1EN_bm | TCA_SINGLE_CMP2EN_bm; // Single slope PWM
  //   TCA0.SINGLE.PER = 0xFE; // Set period (8-bit)
  //   TCA0.SINGLE.CMP0 = 0x80; // Initial duty cycle for PB3
  //   TCA0.SINGLE.CMP1 = 0x80; // Initial duty cycle for PB4
  //   TCA0.SINGLE.CMP2 = 0x80; // Initial duty cycle for PB5
  //   TCA0.SINGLE.CTRLA = TCA_SINGLE_CLKSEL_DIV64_gc | TCA_SINGLE_ENABLE_bm; // Clock select and enable

  PORTMUX_CTRLC = PORTMUX_TCA00_bm | PORTMUX_TCA01_bm | PORTMUX_TCA02_bm;
  PORTMUX_CTRLD = PORTMUX_TCB0_bm | PORTMUX_TCB1_bm;
  PORTB.DIRSET = PIN3_bm | PIN4_bm | PIN5_bm; // Set PB3, PB4, PB5 as output
  PORTA.DIRSET = PIN3_bm; // Set PA3 as output
//   PORTB.PIN5CTRL = PORT_INVEN_bm ;
  //   TCA0.SINGLE.CTRLA = TCA_SINGLE_CLKSEL_DIV256_gc | TCA_SINGLE_ENABLE_bm; // Clock select and enable
  //   TCA0.SINGLE.CTRLB = TCA_SINGLE_WGMODE_SINGLESLOPE_gc | TCA_SINGLE_CMP0EN_bm | TCA_SINGLE_CMP1EN_bm | TCA_SINGLE_CMP2EN_bm; // Single slope PWM, enable compare channels 0, 1, 2
  //   TCA0.SINGLE.PER = 254; // Set period (8-bit)
  //   TCA0.SINGLE.CMP0 = 20; // Initial duty cycle for PB3
  //   TCA0.SINGLE.CMP1 = 20; // Initial duty cycle for PB4
  //   TCA0.SINGLE.CMP2 = 20; // Initial duty cycle for PB5

    TCA0.SPLIT.CTRLD = TCA_SPLIT_SPLITM_bm; // Enable split mode
    TCA0.SPLIT.LPER = 0xFF; // Set period for lower byte
    TCA0.SPLIT.HPER = 0xFF; // Set period for high byte
    TCA0.SPLIT.CTRLA = TCA_SPLIT_CLKSEL_DIV1_gc | TCA_SPLIT_ENABLE_bm; // Clock select and enable
    TCA0.SPLIT.CTRLB = TCA_SPLIT_HCMP0EN_bm |TCA_SPLIT_LCMP2EN_bm | TCA_SPLIT_LCMP1EN_bm; 
//Setting the HCMPnEN bit in the FRQ or PWM Waveform Generation mode of operation will override the port output
//register for the corresponding WO[n+3] pin. 
    //TCA0.SPLIT.LCMP0 = 0xFE; // Initial duty cycle for PB3 (Lower Comp 0)
    TCA0.SPLIT.LCMP1 = 0xFE; // Initial duty cycle for PB4 (Lower Comp 1)
    TCA0.SPLIT.LCMP2 = 0xFE; // Initial duty cycle for PB5 (Lower Comp 2)
    TCA0.SPLIT.HCMP0 = 0xFE; // Initial duty cycle for PB3 (Lower Comp 0)
    // TCA0.SPLIT.HCMP1 = 0xFE; // Initial duty cycle for PB4 (Lower Comp 1)
    // TCA0.SPLIT.HCMP2 = 0xFE; // Initial duty cycle for PB5 (Lower Comp 2)
    //TCA0.SINGLE.CMP1 = 0xFE;

    /**
     * 
      * LCMP0 - PB0 / 3
        LCMP1 - PB1 / 4
        LCMP2 - PB2 / 5 - PB5 - blue
        HCMP0 - PA3 Red
        HCMP1 - PA4
        HCMP2 - PA5

     * https://github.com/SpenceKonde/megaTinyCore/discussions/384
     * 
    */

   delay(1000);

  
}
char data=0;

void loop() {
    if(data>0xFD)data=0; 
    data+=10;
    for (int i=0;i<3;i++){
        //mask each color
        TCA0.SPLIT.LCMP1 = data; //Green
        TCA0.SPLIT.LCMP2 = 0xFE; //blue
        TCA0.SPLIT.HCMP0 = 0XFE; //RED!!!
        delay(10);
        TCA0.SPLIT.LCMP1 = 0xFE; //Green
        TCA0.SPLIT.LCMP2 = data; //blue
        TCA0.SPLIT.HCMP0 = 0XFE; //RED!!!
        delay(10);
        TCA0.SPLIT.LCMP1 = 0xFE; //Green
        TCA0.SPLIT.LCMP2 = 0xFE; //blue
        TCA0.SPLIT.HCMP0 = data; //RED!!!
        delay(10);
    }
    //TCA0.SINGLE.CMP0 = data;
    //TCA0.SINGLE.CMP1 = data; //GREEN in normal mode.
    //TCA0.SINGLE.CMP2 = data;
    //TCA0.SPLIT.LCMP1 = data;  //Green as well?
    //TCA0.SPLIT.LCMP2 = data; //blue
    //TCA0.SPLIT.HCMP0 = data; //RED!!!
    
    //delay(1);
    // TCA0.SPLIT.LCMP1 = 0xFE; //green
    // TCA0.SPLIT.HCMP0 = 0xFE; //red
    // TCA0.SPLIT.LCMP0 = 0xFE; //Blue?
    // delay(1000);
    // TCA0.SPLIT.HCMP0 = 0xFE; //RED!!!
    // TCA0.SPLIT.LCMP0 = 0x80; //BLUE?
    // TCA0.SPLIT.LCMP1 = 0xFE; //green
    // delay(2000);
}
void show_RGB(long val){
    analogWrite(PIN_PA3,(val>>16) & 0xFF);
    analogWrite(PIN_PB4,(val>>8)  & 0xFF);
    analogWrite(PIN_PB5,val       & 0xFF);
}