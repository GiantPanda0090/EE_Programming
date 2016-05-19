// HEADER FILE
#ifndef ICD2_DEBUG
 #pragma chip PIC16F631, core 14, code 1024, ram 64 : 0x7F /1 /3

#else
 #pragma chip PIC16F631, core 14, code 0x300, ram 64 : 0x7F /1 /3
 // last 256 locations are reserved for debugging

 //RESERVED RAM LOCATIONS
 char reservedICD2[12] @ 0x65;  // reserved RAM for ICD2

 #pragma stackLevels 7   // reserve one level for debugging
#endif

#pragma ramdef  0x70 : 0x7F mapped_into_all_banks

#define INT_lgen_style
#define INT_rambank  0   /* interrupt variables in bank 0 */

#pragma config_def 0x0222

/* Predefined:
  char W;
  char INDF, TMR0, PCL, STATUS, FSR, PORTA, PORTB;
  char OPTION, TRISA, TRISB;
  char PCLATH, INTCON;
  bit PS0, PS1, PS2, PSA, T0SE, T0CS, INTEDG, RBPU_;
  bit Carry, DC, Zero_, PD, TO, RP0, RP1, IRP;
  bit RBIF, INTF, T0IF, RBIE, INTE, T0IE, GIE;
  bit PA0, PA1;  // PCLATH
*/

#pragma char PORTC   @ 0x07

#pragma char PIR1    @ 0x0C
#pragma char PIR2    @ 0x0D
#pragma char TMR1L   @ 0x0E
#pragma char TMR1H   @ 0x0F
#pragma char T1CON   @ 0x10

#pragma char TRISC   @ 0x87

#pragma char PIE1    @ 0x8C
#pragma char PIE2    @ 0x8D
#pragma char PCON    @ 0x8E
#pragma char OSCCON  @ 0x8F
#pragma char OSCTUNE @ 0x90

#pragma char WPUA    @ 0x95
#pragma char IOCA    @ 0x96
#pragma char WDTCON  @ 0x97

#pragma char EEDATA  @ 0x10C
#pragma char EEDAT   @ 0x10C
#pragma char EEADR   @ 0x10D

#pragma char WPUB    @ 0x115
#pragma char IOCB    @ 0x116

#pragma char VRCON   @ 0x118
#pragma char CM1CON0 @ 0x119
#pragma char CM2CON0 @ 0x11A
#pragma char CM2CON1 @ 0x11B

#pragma char ANSEL   @ 0x11E

#pragma char EECON1  @ 0x18C
#pragma char EECON2  @ 0x18D

#pragma char SRCON   @ 0x19E

#pragma bit  RABIF   @ INTCON.0
#pragma bit  RABIE   @ INTCON.3
#pragma bit  PEIE    @ INTCON.6

#pragma bit  TMR1IF  @ PIR1.0
#pragma bit  T1IF    @ PIR1.0

#pragma bit  EEIF    @ PIR2.4
#pragma bit  C1IF    @ PIR2.5
#pragma bit  C2IF    @ PIR2.6
#pragma bit  OSFIF   @ PIR2.7

#pragma bit  TMR1ON  @ T1CON.0
#pragma bit  TMR1CS  @ T1CON.1
#pragma bit  T1SYNC_ @ T1CON.2
#pragma bit  T1OSCEN @ T1CON.3
#pragma bit  T1CKPS0 @ T1CON.4
#pragma bit  T1CKPS1 @ T1CON.5
#pragma bit  TMR1GE  @ T1CON.6
#pragma bit  T1GINV  @ T1CON.7

#pragma bit  TMR1IE  @ PIE1.0
#pragma bit  T1IE    @ PIE1.0

#pragma bit  EEIE    @ PIE2.4
#pragma bit  C1IE    @ PIE2.5
#pragma bit  C2IE    @ PIE2.6
#pragma bit  OSFIE   @ PIE2.7

#pragma bit  BOR     @ PCON.0
#pragma bit  POR     @ PCON.1
#pragma bit  SBOREN  @ PCON.4
#pragma bit  ULPWUE  @ PCON.5

#pragma bit  SCS     @ OSCCON.0
#pragma bit  LTS     @ OSCCON.1
#pragma bit  HTS     @ OSCCON.2
#pragma bit  OSTS    @ OSCCON.3

#pragma bit  SWDTEN  @ WDTCON.0

#pragma bit  VR0     @ VRCON.0
#pragma bit  VR1     @ VRCON.1
#pragma bit  VR2     @ VRCON.2
#pragma bit  VR3     @ VRCON.3
#pragma bit  VP6EN   @ VRCON.4
#pragma bit  VRR     @ VRCON.5
#pragma bit  C2VREN  @ VRCON.6
#pragma bit  C1VREN  @ VRCON.7

#pragma bit  C1CH0   @ CM1CON0.0
#pragma bit  C1CH1   @ CM1CON0.1
#pragma bit  C1R     @ CM1CON0.2
#pragma bit  C1POL   @ CM1CON0.4
#pragma bit  C1OE    @ CM1CON0.5
#pragma bit  C1OUT   @ CM1CON0.6
#pragma bit  C1ON    @ CM1CON0.7

#pragma bit  C2CH0   @ CM2CON0.0
#pragma bit  C2CH1   @ CM2CON0.1
#pragma bit  C2R     @ CM2CON0.2
#pragma bit  C2POL   @ CM2CON0.4
#pragma bit  C2OE    @ CM2CON0.5
#pragma bit  C2OUT   @ CM2CON0.6
#pragma bit  C2ON    @ CM2CON0.7

#pragma bit  C2SYNC  @ CM2CON1.0
#pragma bit  T1GSS   @ CM2CON1.1
#pragma bit  MC2OUT  @ CM2CON1.6
#pragma bit  MC1OUT  @ CM2CON1.7

#pragma bit  RD      @ EECON1.0
#pragma bit  WR      @ EECON1.1
#pragma bit  WREN    @ EECON1.2
#pragma bit  WRERR   @ EECON1.3

#pragma bit  PULSR   @ SRCON.2
#pragma bit  PULSS   @ SRCON.3
#pragma bit  C2REN   @ SRCON.4
#pragma bit  C1SEN   @ SRCON.5
#pragma bit  SR0     @ SRCON.6
#pragma bit  SR1     @ SRCON.7
