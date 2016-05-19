// HEADER FILE
#pragma chip PIC16F526, core 12, code 1023, ram 0xD : 0x7F
// NOTE: last code location is omitted   ^--

#pragma resetVector 0

#pragma config_def 0x0010

#pragma data_area  0x400 : 0x43F

#pragma user_ID_addr 0x440

#if __CC5X__ < 3305
 #error 16F526 requires CC5X version 3.3E or later
#endif

/* Predefined:
  char W;
  char INDF, TMR0, PCL, STATUS, FSR, PORTB;
  char OPTION;
  bit Carry, DC, Zero_, PD, TO, PA0, PA1, PA2;
  bit FSR_5, FSR_6;
*/

#pragma char OSCCAL  @ 5
#pragma char CM1CON0 @ 8 mapped_into_all_banks
#pragma char ADCON0  @ 9 mapped_into_all_banks
#pragma char ADRES   @ 10 mapped_into_all_banks
#pragma char CM2CON0 @ 11 mapped_into_all_banks
#pragma char VRCON   @ 12 mapped_into_all_banks

#pragma char EECON  @ 0x21
#pragma char EEDATA @ 0x25
#pragma char EEADR  @ 0x26

#pragma bit  CWUF   @ STATUS.6
#pragma bit  RBWUF  @ STATUS.7

#pragma bit  C1WU_    @ CM1CON0.0
#pragma bit  C1PREF   @ CM1CON0.1
#pragma bit  C1NREF   @ CM1CON0.2
#pragma bit  C1ON     @ CM1CON0.3
#pragma bit  C1T0CS_  @ CM1CON0.4
#pragma bit  C1POL    @ CM1CON0.5
#pragma bit  C1OUTEN_ @ CM1CON0.6
#pragma bit  C1OUT    @ CM1CON0.7

#pragma bit  ADON     @ ADCON0.0
#pragma bit  GO       @ ADCON0.1
#pragma bit  CHS0     @ ADCON0.2
#pragma bit  CHS1     @ ADCON0.3
#pragma bit  ADCS0    @ ADCON0.4
#pragma bit  ADCS1    @ ADCON0.5
#pragma bit  ANS0     @ ADCON0.6
#pragma bit  ANS1     @ ADCON0.7

#pragma bit  C2WU_    @ CM1CON0.0
#pragma bit  C2PREF1  @ CM1CON0.1
#pragma bit  C2NREF   @ CM1CON0.2
#pragma bit  C2ON     @ CM1CON0.3
#pragma bit  C2PREF2  @ CM1CON0.4
#pragma bit  C2POL    @ CM1CON0.5
#pragma bit  C2OUTEN_ @ CM1CON0.6
#pragma bit  C2OUT    @ CM1CON0.7

#pragma bit  VR0     @ VRCON.0
#pragma bit  VR1     @ VRCON.1
#pragma bit  VR2     @ VRCON.2
#pragma bit  VR3     @ VRCON.3
#pragma bit  VRR     @ VRCON.5
#pragma bit  VROE    @ VRCON.6
#pragma bit  VREN    @ VRCON.7

#pragma bit  RD      @ EECON.0
#pragma bit  WR      @ EECON.1
#pragma bit  WREN    @ EECON.2
#pragma bit  WRERR   @ EECON.3
#pragma bit  FREE    @ EECON.4
