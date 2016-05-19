// HEADER FILE
#pragma chip PIC16F527, core 12 enh, code 1024, ram 12 : 0x7F  // 68 bytes

#if __CC5X__ < 3409
 #error CC5X version 3.4I (or later) is required to use this device
#endif

#pragma config_def  0x0022

#pragma data_area  0x400 : 0x43F
#pragma userIDlocations  0x440
#pragma config_reg       0x7FF

#define INT_enh12_style

/* Predefined:
  char W;
  char INDF, TMR0, PCL, STATUS, FSR, PORTA, PORTB;
  char OPTION, TRISA, TRISB, BSR;
  char PORTC, TRISC;
  bit Carry, DC, Zero_, PD, TO, PA0, PA1;
*/

#pragma char ADCON0  @ 0x09
#pragma char ADRES   @ 0x0A
#pragma char INTCON0 @ 0x0B mapped_into_all_banks

#pragma char EECON   @ 0x21

#pragma char EEDATA  @ 0x25
#pragma char EEADR   @ 0x26
#pragma char CM1CON0 @ 0x27
#pragma char CM2CON0 @ 0x28
#pragma char VRCON   @ 0x29
#pragma char ANSEL   @ 0x2A

#pragma char IW      @ 0x61

#pragma char INTCON1 @ 0x65
#pragma char ISTATUS @ 0x66
#pragma char IFSR    @ 0x67
#pragma char IBSR    @ 0x68
#pragma char OPACON  @ 0x69

#pragma bit  ADON    @ ADCON0.0
#pragma bit  GO      @ ADCON0.1
#pragma bit  CHS0    @ ADCON0.2
#pragma bit  CHS1    @ ADCON0.3
#pragma bit  CHS2    @ ADCON0.4
#pragma bit  CHS3    @ ADCON0.5
#pragma bit  ADCS0   @ ADCON0.6
#pragma bit  ADCS1   @ ADCON0.7

#pragma bit  GIE     @ INTCON0.0
#pragma bit  RAIF    @ INTCON0.4
#pragma bit  T0IF    @ INTCON0.5
#pragma bit  CWIF    @ INTCON0.6
#pragma bit  ADIF    @ INTCON0.7

#pragma bit  RD      @ EECON.0
#pragma bit  WR      @ EECON.1
#pragma bit  WREN    @ EECON.2
#pragma bit  WRERR   @ EECON.3
#pragma bit  FREE    @ EECON.4

#pragma bit  C1WU_   @ CM1CON0.0
#pragma bit  C1PREF  @ CM1CON0.1
#pragma bit  C1NREF  @ CM1CON0.2
#pragma bit  C1ON    @ CM1CON0.3
#pragma bit  C1T0CS_ @ CM1CON0.4
#pragma bit  C1POL   @ CM1CON0.5
#pragma bit  C1OUTEN_ @ CM1CON0.6
#pragma bit  C1OUT   @ CM1CON0.7

#pragma bit  C2WU_   @ CM2CON0.0
#pragma bit  C2PREF1 @ CM2CON0.1
#pragma bit  C2NREF  @ CM2CON0.2
#pragma bit  C2ON    @ CM2CON0.3
#pragma bit  C2PREF2 @ CM2CON0.4
#pragma bit  C2POL   @ CM2CON0.5
#pragma bit  C2OUTEN_ @ CM2CON0.6
#pragma bit  C2OUT   @ CM2CON0.7

#pragma bit  VR0     @ VRCON.0
#pragma bit  VR1     @ VRCON.1
#pragma bit  VR2     @ VRCON.2
#pragma bit  VR3     @ VRCON.3
#pragma bit  VRR     @ VRCON.5
#pragma bit  VROE    @ VRCON.6
#pragma bit  VREN    @ VRCON.7

#pragma bit  WUR     @ INTCON1.0
#pragma bit  RAIE    @ INTCON1.4
#pragma bit  T0IE    @ INTCON1.5
#pragma bit  CWIE    @ INTCON1.6
#pragma bit  ADIE    @ INTCON1.7

#pragma bit  OPA1ON  @ OPACON.0
#pragma bit  OPA2ON  @ OPACON.1
