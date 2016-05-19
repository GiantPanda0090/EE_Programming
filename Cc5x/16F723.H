// HEADER FILE
#ifndef ICD2_DEBUG
 #pragma chip PIC16F723, core 14, code 4096, ram 32 : 0x12F

#else
 #pragma chip PIC16F723, core 14, code 0xF00, ram 32 : 0x12F
 // last 256 locations are reserved for debugging

 //RESERVED RAM LOCATIONS
 char ICD2R1 @ 0x70;
 char reservedICD2[11] @ 0x125;  // reserved RAM for ICD2

 #pragma stackLevels 7   // reserve one level for debugging
#endif

#pragma ramdef  0x70 : 0x7F mapped_into_all_banks

#define INT_gen_style
#define INT_rambank  0   /* interrupt variables in bank 0 */

#pragma config_def 0x0222

#pragma config_reg2 0x2008

#pragma wideConstData p

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

#pragma char PORTE   @ 0x09

#pragma char PIR1    @ 0x0C
#pragma char PIR2    @ 0x0D
#pragma char TMR1L   @ 0x0E
#pragma char TMR1H   @ 0x0F
#pragma char T1CON   @ 0x10
#pragma char TMR2    @ 0x11
#pragma char T2CON   @ 0x12
#pragma char SSPBUF  @ 0x13
#pragma char SSPCON  @ 0x14
#pragma char CCPR1L  @ 0x15
#pragma char CCPR1H  @ 0x16
#pragma char CCP1CON @ 0x17
#pragma char RCSTA   @ 0x18
#pragma char TXREG   @ 0x19
#pragma char RCREG   @ 0x1A
#pragma char CCPR2L  @ 0x1B
#pragma char CCPR2H  @ 0x1C
#pragma char CCP2CON @ 0x1D
#pragma char ADRES   @ 0x1E
#pragma char ADCON0  @ 0x1F

#pragma char TRISC   @ 0x87

#pragma char TRISE   @ 0x89

#pragma char PIE1    @ 0x8C
#pragma char PIE2    @ 0x8D
#pragma char PCON    @ 0x8E
#pragma char T1GCON  @ 0x8F
#pragma char OSCCON  @ 0x90
#pragma char OSCTUNE @ 0x91
#pragma char PR2     @ 0x92
#pragma char SSPADD  @ 0x93
#pragma char SSPMSK  @ 0x93
#pragma char SSPSTAT @ 0x94
#pragma char WPUB    @ 0x95
#pragma char IOCB    @ 0x96

#pragma char TXSTA   @ 0x98
#pragma char SPBRG   @ 0x99

#pragma char APFCON  @ 0x9C
#pragma char FVRCON  @ 0x9D

#pragma char ADCON1  @ 0x9F

#pragma char CPSCON0 @ 0x108
#pragma char CPSCON1 @ 0x109

#pragma char PMDATL  @ 0x10C
#pragma char PMADRL  @ 0x10D
#pragma char PMDATH  @ 0x10E
#pragma char PMADRH  @ 0x10F

#pragma char ANSELA  @ 0x185
#pragma char ANSELB  @ 0x186

#pragma char PMCON1  @ 0x18C

#pragma bit  PEIE    @ INTCON.6

#pragma bit  TMR1IF  @ PIR1.0
#pragma bit  TMR2IF  @ PIR1.1
#pragma bit  CCP1IF  @ PIR1.2
#pragma bit  SSPIF   @ PIR1.3
#pragma bit  TXIF    @ PIR1.4
#pragma bit  RCIF    @ PIR1.5
#pragma bit  ADIF    @ PIR1.6
#pragma bit  TMR1GIF @ PIR1.7

#pragma bit  CCP2IF  @ PIR2.0

#pragma bit  TMR1ON  @ T1CON.0
#pragma bit  T1SYNC_ @ T1CON.2
#pragma bit  T1OSCEN @ T1CON.3
#pragma bit  T1CKPS0 @ T1CON.4
#pragma bit  T1CKPS1 @ T1CON.5
#pragma bit  TMR1CS0 @ T1CON.6
#pragma bit  TMR1CS1 @ T1CON.7

#pragma bit  TMR2ON  @ T2CON.2

#pragma bit  SSPM0   @ SSPCON.0
#pragma bit  SSPM1   @ SSPCON.1
#pragma bit  SSPM2   @ SSPCON.2
#pragma bit  SSPM3   @ SSPCON.3
#pragma bit  CKP     @ SSPCON.4
#pragma bit  SSPEN   @ SSPCON.5
#pragma bit  SSPOV   @ SSPCON.6
#pragma bit  WCOL    @ SSPCON.7

#pragma bit  CCP1M0  @ CCP1CON.0
#pragma bit  CCP1M1  @ CCP1CON.1
#pragma bit  CCP1M2  @ CCP1CON.2
#pragma bit  CCP1M3  @ CCP1CON.3
#pragma bit  DC1B0   @ CCP1CON.4
#pragma bit  DC1B1   @ CCP1CON.5

#pragma bit  RX9D    @ RCSTA.0
#pragma bit  OERR    @ RCSTA.1
#pragma bit  FERR    @ RCSTA.2
#pragma bit  ADDEN   @ RCSTA.3
#pragma bit  CREN    @ RCSTA.4
#pragma bit  SREN    @ RCSTA.5
#pragma bit  RX9     @ RCSTA.6
#pragma bit  SPEN    @ RCSTA.7

#pragma bit  CCP2M0  @ CCP2CON.0
#pragma bit  CCP2M1  @ CCP2CON.1
#pragma bit  CCP2M2  @ CCP2CON.2
#pragma bit  CCP2M3  @ CCP2CON.3
#pragma bit  DC2B0   @ CCP2CON.4
#pragma bit  DC2B1   @ CCP2CON.5

#pragma bit  ADON    @ ADCON0.0
#pragma bit  GO      @ ADCON0.1
#pragma bit  CHS0    @ ADCON0.2
#pragma bit  CHS1    @ ADCON0.3
#pragma bit  CHS2    @ ADCON0.4
#pragma bit  CHS3    @ ADCON0.5

#pragma bit  TMR1IE  @ PIE1.0
#pragma bit  TMR2IE  @ PIE1.1
#pragma bit  CCP1IE  @ PIE1.2
#pragma bit  SSPIE   @ PIE1.3
#pragma bit  TXIE    @ PIE1.4
#pragma bit  RCIE    @ PIE1.5
#pragma bit  ADIE    @ PIE1.6
#pragma bit  TMR1GIE @ PIE1.7

#pragma bit  CCP2IE  @ PIE2.0

#pragma bit  BOR_    @ PCON.0
#pragma bit  POR_    @ PCON.1

#pragma bit  T1GSS0  @ T1GCON.0
#pragma bit  T1GSS1  @ T1GCON.1
#pragma bit  T1GVAL  @ T1GCON.2
#pragma bit  T1GGO   @ T1GCON.3
#pragma bit  T1GSPM  @ T1GCON.4
#pragma bit  T1GTM   @ T1GCON.5
#pragma bit  T1GPOL  @ T1GCON.6
#pragma bit  TMR1GE  @ T1GCON.7

#pragma bit  ICSS    @ OSCCON.2
#pragma bit  ICSL    @ OSCCON.3
#pragma bit  IRCF0   @ OSCCON.4
#pragma bit  IRCF1   @ OSCCON.5

#pragma bit  BF      @ SSPSTAT.0
#pragma bit  UA      @ SSPSTAT.1
#pragma bit  RW_     @ SSPSTAT.2
#pragma bit  S       @ SSPSTAT.3
#pragma bit  P       @ SSPSTAT.4
#pragma bit  DA_     @ SSPSTAT.5
#pragma bit  CKE     @ SSPSTAT.6
#pragma bit  SMP     @ SSPSTAT.7

#pragma bit  TX9D    @ TXSTA.0
#pragma bit  TRMT    @ TXSTA.1
#pragma bit  BRGH    @ TXSTA.2
#pragma bit  SYNC    @ TXSTA.4
#pragma bit  TXEN    @ TXSTA.5
#pragma bit  TX9     @ TXSTA.6
#pragma bit  CSRC    @ TXSTA.7

#pragma bit  CCP2SEL @ APFCON.0
#pragma bit  SSSEL   @ APFCON.1

#pragma bit  ADFVR0  @ FVRCON.0
#pragma bit  ADFVR1  @ FVRCON.1
#pragma bit  FVREN   @ FVRCON.6
#pragma bit  FVRRDY  @ FVRCON.7

#pragma bit  ADREF0  @ ADCON1.0
#pragma bit  ADREF1  @ ADCON1.1
#pragma bit  ADCS0   @ ADCON1.4
#pragma bit  ADCS1   @ ADCON1.5
#pragma bit  ADCS2   @ ADCON1.6

#pragma bit  T0XCS   @ CPSCON0.0
#pragma bit  CPSOUT  @ CPSCON0.1
#pragma bit  CPSRNG0 @ CPSCON0.2
#pragma bit  CPSRNG1 @ CPSCON0.3
#pragma bit  CPSON   @ CPSCON0.7

#pragma bit  RD      @ PMCON1.0
