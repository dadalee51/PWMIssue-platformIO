// #include <Arduino.h>
// void setup() {
//     pinMode(PIN_PA3, OUTPUT);
//     pinMode(PIN_PB4, OUTPUT);
//     pinMode(PIN_PB5, OUTPUT);
//     PORTMUX_CTRLC = PORTMUX_TCA00_bm | PORTMUX_TCA01_bm | PORTMUX_TCA02_bm;
//     PORTMUX_CTRLD = PORTMUX_TCB0_bm | PORTMUX_TCB1_bm;
//     PORTB.DIRSET = PIN3_bm | PIN4_bm | PIN5_bm; // Set PB3, PB4, PB5 as output
//     PORTA.DIRSET = PIN3_bm; // Set PA3 as output
//     TCA0.SPLIT.CTRLD = TCA_SPLIT_SPLITM_bm; // Enable split mode
//     TCA0.SPLIT.LPER = 0xFF; // Set period for lower byte
//     TCA0.SPLIT.HPER = 0xFF; // Set period for high byte
//     TCA0.SPLIT.CTRLA = TCA_SPLIT_CLKSEL_DIV1_gc | TCA_SPLIT_ENABLE_bm; // Clock select and enable
//     TCA0.SPLIT.CTRLB = TCA_SPLIT_HCMP0EN_bm |TCA_SPLIT_LCMP2EN_bm | TCA_SPLIT_LCMP1EN_bm; 
//     TCA0.SPLIT.LCMP1 = 0xFE; // Initial duty cycle for PB4 (Lower Comp 1)
//     TCA0.SPLIT.LCMP2 = 0xFE; // Initial duty cycle for PB5 (Lower Comp 2)
//     TCA0.SPLIT.HCMP0 = 0xFE; // Initial duty cycle for PB3 (Lower Comp 0)
//     /**
//      * 
//       * LCMP0 - PB0 / 3
//         LCMP1 - PB1 / 4
//         LCMP2 - PB2 / 5 - PB5 - 
//         HCMP0 - PA3 
//         HCMP1 - PA4
//         HCMP2 - PA5

//      * https://github.com/SpenceKonde/megaTinyCore/discussions/384
//      * 
//     */
// }
// char data=0;
// void loop() {
//     if(data>0xFD)data=0; 
//     data+=10;
//     for (int i=0;i<3;i++){
//         TCA0.SPLIT.LCMP1 = data; //Green
//         TCA0.SPLIT.LCMP2 = 0xFE; //blue
//         TCA0.SPLIT.HCMP0 = 0XFE; //RED!!!
//         delay(10);
//         TCA0.SPLIT.LCMP1 = 0xFE; //Green
//         TCA0.SPLIT.LCMP2 = data; //blue
//         TCA0.SPLIT.HCMP0 = 0XFE; //RED!!!
//         delay(10);
//         TCA0.SPLIT.LCMP1 = 0xFE; //Green
//         TCA0.SPLIT.LCMP2 = 0xFE; //blue
//         TCA0.SPLIT.HCMP0 = data; //RED!!!
//         delay(10);
//     }
// }


/***
 * backup ini
 * 
 *
 * 
 *  
[env:ATtiny1616]
platform = atmelmegaavr
board = ATtiny1616
framework = arduino
platform_packages = framework-arduino-megaavr-megatinycore @ https://github.com/SpenceKonde/megaTinyCore/
build_flags =  -DTCA0 -g3 -ggdb -Wl,-Map=output.map,--cref,--no-warn-mismatch -DTCA_PORTMUX=0x07 -DUSE_TIMERD0_PWM
extra_scripts = post:extra_script.py
 * 
 * 
*/