// HEADER FILE
#pragma chip PIC12HV752, core 14, code 1024, ram 0x40 : 0x7F /1 /3
#pragma ramdef  0x70 : 0x7F mapped_into_all_banks

#define INT_lgen_style
#define INT_rambank  0   /* interrupt variables in bank 0 */

#pragma config_def 0x224

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

#pragma char IOCAF   @ 0x08

#pragma char PIR1    @ 0x0C
#pragma char PIR2    @ 0x0D

#pragma char TMR1L   @ 0x0F
#pragma char TMR1H   @ 0x10
#pragma char T1CON   @ 0x11
#pragma char T1GCON  @ 0x12
#pragma char CCPR1L  @ 0x13
#pragma char CCPR1H  @ 0x14
#pragma char CCP1CON @ 0x15

#pragma char ADRESL  @ 0x1C
#pragma char ADRESH  @ 0x1D
#pragma char ADCON0  @ 0x1E
#pragma char ADCON1  @ 0x1F

#pragma char IOCAP   @ 0x88

#pragma char PIE1    @ 0x8C
#pragma char PIE2    @ 0x8D

#pragma char OSCCON  @ 0x8F
#pragma char FVRCON  @ 0x90
#pragma char DACCON0 @ 0x91
#pragma char DACCON1 @ 0x92

#pragma char CM2CON0 @ 0x9B
#pragma char CM2CON1 @ 0x9C
#pragma char CM1CON0 @ 0x9D
#pragma char CM1CON1 @ 0x9E
#pragma char CMOUT   @ 0x9F

#pragma char LATA    @ 0x105

#pragma char IOCAN   @ 0x108

#pragma char WPUA    @ 0x10C

#pragma char PCON    @ 0x10F
#pragma char TMR2    @ 0x110
#pragma char PR2     @ 0x111
#pragma char T2CON   @ 0x112
#pragma char HLTMR1  @ 0x113
#pragma char HLTPR1  @ 0x114
#pragma char HLT1CON0 @ 0x115
#pragma char HLT1CON1 @ 0x116

#pragma char ANSELA  @ 0x185

#pragma char APFCON  @ 0x188
#pragma char OSCTUNE @ 0x189

#pragma char PMCON1  @ 0x18C
#pragma char PMCON2  @ 0x18D
#pragma char PMADRL  @ 0x18E
#pragma char PMADRH  @ 0x18F
#pragma char PMDATL  @ 0x190
#pragma char PMDATH  @ 0x191
#pragma char COG1PH  @ 0x192
#pragma char COG1BLK @ 0x193
#pragma char COG1DB  @ 0x194
#pragma char COG1CON0 @ 0x195
#pragma char COG1CON1 @ 0x196
#pragma char COG1ASD @ 0x197

#pragma bit  IOCIF   @ INTCON.0
#pragma bit  PEIE    @ INTCON.6

#pragma bit  TMR1IF  @ PIR1.0
#pragma bit  TMR2IF  @ PIR1.1
#pragma bit  HLTMR1IF @ PIR1.2
#pragma bit  ADIF    @ PIR1.6
#pragma bit  TMR1GIF @ PIR1.7

#pragma bit  CCP1IF  @ PIR2.0
#pragma bit  COG1IF  @ PIR1.2
#pragma bit  C1IF    @ PIR2.4
#pragma bit  C2IF    @ PIR2.5

#pragma bit  TMR1ON  @ T1CON.0
#pragma bit  T1SYNC_ @ T1CON.2
#pragma bit  T1OSCEN @ T1CON.3
#pragma bit  T1CKPS0 @ T1CON.4
#pragma bit  T1CKPS1 @ T1CON.5
#pragma bit  TMR1CS0 @ T1CON.6
#pragma bit  TMR1CS1 @ T1CON.7

#pragma bit  T1GSS0  @ T1GCON.0
#pragma bit  T1GSS1  @ T1GCON.1
#pragma bit  T1GVAL  @ T1GCON.2
#pragma bit  T1GGO   @ T1GCON.3
#pragma bit  T1GSPM  @ T1GCON.4
#pragma bit  T1GTM   @ T1GCON.5
#pragma bit  T1GPOL  @ T1GCON.6
#pragma bit  TMR1GE  @ T1GCON.7

#pragma bit  CC1PM0  @ CCP1CON.0
#pragma bit  CC1PM1  @ CCP1CON.1
#pragma bit  CC1PM2  @ CCP1CON.2
#pragma bit  CC1PM3  @ CCP1CON.3
#pragma bit  DC1B0   @ CCP1CON.4
#pragma bit  DC1B1   @ CCP1CON.5

#pragma bit  ADON    @ ADCON0.0
#pragma bit  GO      @ ADCON0.1
#pragma bit  CHS0    @ ADCON0.2
#pragma bit  CHS1    @ ADCON0.3
#pragma bit  CHS2    @ ADCON0.4
#pragma bit  CHS3    @ ADCON0.5
#pragma bit  VCFG    @ ADCON0.6
#pragma bit  ADFM    @ ADCON0.7

#pragma bit  ADCS0   @ ADCON1.4
#pragma bit  ADCS1   @ ADCON1.5
#pragma bit  ADCS2   @ ADCON1.6

#pragma bit  TMR1IE  @ PIE1.0
#pragma bit  TMR2IE  @ PIE1.1
#pragma bit  HLTMR1IE @ PIE1.2
#pragma bit  ADIE    @ PIE1.6
#pragma bit  TMR1GIE @ PIE1.7

#pragma bit  CCP1IE  @ PIE2.0
#pragma bit  COG1IE  @ PIE2.2
#pragma bit  C1IE    @ PIE2.4
#pragma bit  C2IE    @ PIE2.5

#pragma bit  LTS     @ OSCCON.1
#pragma bit  HTS     @ OSCCON.2

#pragma bit  FVRBUFSS @ FVRCON.4
#pragma bit  FVRBUFEN @ FVRCON.5
#pragma bit  FVRRDY  @ FVRCON.6
#pragma bit  FVREN   @ FVRCON.7

#pragma bit  DACPSS0 @ DACCON0.2
#pragma bit  DACOE   @ DACCON0.5
#pragma bit  DACRNG  @ DACCON0.6
#pragma bit  DACEN   @ DACCON0.7

#pragma bit  C2SYNC  @ CM2CON0.0
#pragma bit  C2HYS   @ CM2CON0.1
#pragma bit  C2SP    @ CM2CON0.2
#pragma bit  C2POL   @ CM2CON0.4
#pragma bit  C2OE    @ CM2CON0.5
#pragma bit  C2OUT   @ CM2CON0.6
#pragma bit  C2ON    @ CM2CON0.7

#pragma bit  C2NCH0  @ CM2CON1.0
#pragma bit  C2PCH0  @ CM2CON1.4
#pragma bit  C2PCH1  @ CM2CON1.5
#pragma bit  C2INTN  @ CM2CON1.6
#pragma bit  C2INTP  @ CM2CON1.7

#pragma bit  C1SYNC  @ CM1CON0.0
#pragma bit  C1HYS   @ CM1CON0.1
#pragma bit  C1SP    @ CM1CON0.2
#pragma bit  C1POL   @ CM1CON0.4
#pragma bit  C1OE    @ CM1CON0.5
#pragma bit  C1OUT   @ CM1CON0.6
#pragma bit  C1ON    @ CM1CON0.7

#pragma bit  C1NCH0  @ CM1CON1.0
#pragma bit  C1PCH0  @ CM1CON1.4
#pragma bit  C1PCH1  @ CM1CON1.5
#pragma bit  C1INTN  @ CM1CON1.6
#pragma bit  C1INTP  @ CM1CON1.7

#pragma bit  MCOUT1  @ CMOUT.0
#pragma bit  MCOUT2  @ CMOUT.1

#pragma bit  BOR_    @ PCON.0
#pragma bit  POR_    @ PCON.1

#pragma bit  TMR2ON  @ T2CON.2

#pragma bit  H1ON    @ HLT1CON0.2

#pragma bit  COG1O0SEL @ APFCON.0
#pragma bit  COG1O1SEL @ APFCON.1
#pragma bit  COG1FSEL @ APFCON.2
#pragma bit  T1GSEL  @ APFCON.4

#pragma bit  RD      @ PMCON1.0
#pragma bit  WR      @ PMCON1.1
#pragma bit  WREN    @ PMCON1.2
