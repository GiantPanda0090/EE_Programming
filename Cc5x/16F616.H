// HEADER FILE
#ifndef ICD2_DEBUG
 #pragma chip PIC16F616, core 14, code 2048, ram 32 : 0xBF

#else
 #pragma chip PIC16F616, core 14, code 0x700, ram 32 : 0xBF
 // last 256 locations are reserved for debugging

 //RESERVED RAM LOCATIONS
 char reservedICD2[12] @ 0xB5;  // reserved RAM for ICD2

 #pragma stackLevels 7   // reserve one level for debugging
#endif

#pragma ramdef  0x70 : 0x7F mapped_into_all_banks

#define INT_com_style
#define INT_rambank  0   /* interrupt variables in bank 0 */

#pragma config_def 0x0222

/* Predefined:
  char W;
  char INDF, TMR0, PCL, STATUS, FSR, PORTA;
  char OPTION, TRISA;
  char PCLATH, INTCON;
  bit PS0, PS1, PS2, PSA, T0SE, T0CS, INTEDG, RBPU_;
  bit Carry, DC, Zero_, PD, TO, RP0, RP1, IRP;
  bit RBIF, INTF, T0IF, RBIE, INTE, T0IE, GIE;
  bit PA0, PA1;  // PCLATH
*/

#pragma char PORTC   @ 0x07

#pragma char PIR1    @ 0x0C

#pragma char TMR1L   @ 0x0E
#pragma char TMR1H   @ 0x0F
#pragma char T1CON   @ 0x10
#pragma char TMR2    @ 0x11
#pragma char T2CON   @ 0x12
#pragma char CCPR1L  @ 0x13
#pragma char CCPR1H  @ 0x14
#pragma char CCP1CON @ 0x15
#pragma char PWM1CON @ 0x16
#pragma char ECCPAS  @ 0x17

#pragma char VRCON   @ 0x19
#pragma char CM1CON0 @ 0x1A
#pragma char CM2CON0 @ 0x1B
#pragma char CM2CON1 @ 0x1C

#pragma char ADRESH  @ 0x1E
#pragma char ADCON0  @ 0x1F

#pragma char TRISC   @ 0x87

#pragma char PIE1    @ 0x8C

#pragma char PCON    @ 0x8E

#pragma char OSCTUNE @ 0x90
#pragma char ANSEL   @ 0x91
#pragma char PR2     @ 0x92

#pragma char WPUA    @ 0x95
#pragma char IOCA    @ 0x96

#pragma char SRCON0  @ 0x99
#pragma char SRCON1  @ 0x9A

#pragma char ADRESL  @ 0x9E
#pragma char ADCON1  @ 0x9F

#pragma bit  RAIF    @ INTCON.0
#pragma bit  RAIE    @ INTCON.3
#pragma bit  PEIE    @ INTCON.6

#pragma bit  TMR1IF  @ PIR1.0
#pragma bit  TMR2IF  @ PIR1.1
#pragma bit  C1IF    @ PIR1.3
#pragma bit  C2IF    @ PIR1.4
#pragma bit  CCP1IF  @ PIR1.5
#pragma bit  ADIF    @ PIR1.6

#pragma bit  TMR1ON  @ T1CON.0
#pragma bit  TMR1CS  @ T1CON.1
#pragma bit  T1SYNC_ @ T1CON.2
#pragma bit  T1OSCEN @ T1CON.3
#pragma bit  T1CKPS0 @ T1CON.4
#pragma bit  T1CKPS1 @ T1CON.5
#pragma bit  TMR1GE  @ T1CON.6
#pragma bit  T1GINV  @ T1CON.7

#pragma bit  TMR2ON  @ T2CON.2

#pragma bit  CCP1M0  @ CCP1CON.0
#pragma bit  CCP1M1  @ CCP1CON.1
#pragma bit  CCP1M2  @ CCP1CON.2
#pragma bit  CCP1M3  @ CCP1CON.3
#pragma bit  DC1B0   @ CCP1CON.4
#pragma bit  DC1B1   @ CCP1CON.5
#pragma bit  P1M0    @ CCP1CON.6
#pragma bit  P1M1    @ CCP1CON.7

#pragma bit  PRSEN   @ PWM1CON.7

#pragma bit  PSSBD0  @ ECCPAS.0
#pragma bit  PSSBD1  @ ECCPAS.1
#pragma bit  PSSAC0  @ ECCPAS.2
#pragma bit  PSSAC1  @ ECCPAS.3
#pragma bit  ECCPASE @ ECCPAS.7

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
#pragma bit  C2HYS   @ CM2CON1.2
#pragma bit  C1HYS   @ CM2CON1.3
#pragma bit  T1ACS   @ CM2CON1.4
#pragma bit  MC2OUT  @ CM2CON1.6
#pragma bit  MC1OUT  @ CM2CON1.7

#pragma bit  ADON    @ ADCON0.0
#pragma bit  GO      @ ADCON0.1
#pragma bit  CHS0    @ ADCON0.2
#pragma bit  CHS1    @ ADCON0.3
#pragma bit  CHS2    @ ADCON0.4
#pragma bit  CHS3    @ ADCON0.5
#pragma bit  VCFG    @ ADCON0.6
#pragma bit  ADFM    @ ADCON0.7

#pragma bit  TMR1IE  @ PIE1.0
#pragma bit  TMR2IE  @ PIE1.1
#pragma bit  C1IE    @ PIE1.3
#pragma bit  C2IE    @ PIE1.4
#pragma bit  CCP1IE  @ PIE1.5
#pragma bit  ADIE    @ PIE1.6

#pragma bit  BOR_    @ PCON.0
#pragma bit  POR_    @ PCON.1

#pragma bit  SRCLKEN @ SRCON0.0
#pragma bit  PULSR   @ SRCON0.2
#pragma bit  PULSS   @ SRCON0.3
#pragma bit  C2REN   @ SRCON0.4
#pragma bit  C1SEN   @ SRCON0.5
#pragma bit  SR0     @ SRCON0.6
#pragma bit  SR1     @ SRCON0.7

#pragma bit  SRCS2   @ SRCON1.6
#pragma bit  SRCS1   @ SRCON1.7
