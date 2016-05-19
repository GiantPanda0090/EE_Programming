// HEADER FILE
#pragma chip PIC16F1526, core 14 enh, code 8192, ram 32 : 0x4BF
#pragma ramdef  0x70 : 0x7F mapped_into_all_banks

#define INT_enh_style

#pragma config_def 0x2

#pragma wideConstData p 

/* Predefined:
  char *FSR0, *FSR1;
  char INDF0, INDF1;
  char FSR0L, FSR0H, FSR1L, FSR1H;
  char W, WREG;
  char PCL, PCLATH, STATUS, INTCON;
  bit Carry, DC, Zero_, PD, TO;
*/

char PORTA   @ 0x0C;
char PORTB   @ 0x0D;
char PORTC   @ 0x0E;
char PORTD   @ 0x0F;
char PORTE   @ 0x10;
char PIR1    @ 0x11;
char PIR2    @ 0x12;
char PIR3    @ 0x13;
char PIR4    @ 0x14;
char TMR0    @ 0x15;
char TMR1L   @ 0x16;
char TMR1H   @ 0x17;
char T1CON   @ 0x18;
char T1GCON  @ 0x19;
char TMR2    @ 0x1A;
char PR2     @ 0x1B;
char T2CON   @ 0x1C;

char TRISA   @ 0x8C;
char TRISB   @ 0x8D;
char TRISC   @ 0x8E;
char TRISD   @ 0x8F;
char TRISE   @ 0x90;
char PIE1    @ 0x91;
char PIE2    @ 0x92;
char PIE3    @ 0x93;
char PIE4    @ 0x94;
char OPTION_REG @ 0x95;
char PCON    @ 0x96;
char WDTCON  @ 0x97;

char OSCCON  @ 0x99;
char OSCSTAT @ 0x9A;
char ADRESL  @ 0x9B;
char ADRESH  @ 0x9C;
char ADCON0  @ 0x9D;
char ADCON1  @ 0x9E;

char LATA    @ 0x10C;
char LATB    @ 0x10D;
char LATC    @ 0x10E;
char LATD    @ 0x10F;
char LATE    @ 0x110;

char BORCON  @ 0x116;
char FVRCON  @ 0x117;

char APFCON  @ 0x11D;

char ANSELA  @ 0x18C;
char ANSELB  @ 0x18D;

char ANSELD  @ 0x18F;
char ANSELE  @ 0x190;
char PMADRL  @ 0x191;
char PMADRH  @ 0x192;
char PMDATL  @ 0x193;
char PMDATH  @ 0x194;
char PMCON1  @ 0x195;
char PMCON2  @ 0x196;
#ifdef _16F1526
char VREGCON @ 0x197;
#endif

char RC1REG  @ 0x199;
char TX1REG  @ 0x19A;
char SP1BRGL @ 0x19B;
char SP1BRGH @ 0x19C;
char RC1STA  @ 0x19D;
char TX1STA  @ 0x19E;
char BAUD1CON @ 0x19F;

char WPUB    @ 0x20D;

char WPUD    @ 0x20F;
char WPUE    @ 0x210;
char SSP1BUF @ 0x211;
char SSP1ADD @ 0x212;
char SSP1MSK @ 0x213;
char SSP1STAT @ 0x214;
char SSP1CON1 @ 0x215;
char SSP1CON2 @ 0x216;
char SSP1CON3 @ 0x217;

char SSP2BUF @ 0x219;
char SSP2ADD @ 0x21A;
char SSP2MSK @ 0x21B;
char SSP2STAT @ 0x21C;
char SSP2CON1 @ 0x21D;
char SSP2CON2 @ 0x21E;
char SSP2CON3 @ 0x21F;

char PORTF   @ 0x28C;
char PORTG   @ 0x28D;

char CCPR1L  @ 0x291;
char CCPR1H  @ 0x292;
char CCP1CON @ 0x293;

char CCPR2L  @ 0x298;
char CCPR2H  @ 0x299;
char CCP2CON @ 0x29A;

char CCPTMRS0 @ 0x29D;
char CCPTMRS1 @ 0x29E;
char CCPTMRS2 @ 0x29F;

char TRISF   @ 0x30C;
char TRISG   @ 0x30D;

char CCPR3L  @ 0x311;
char CCPR3H  @ 0x312;
char CCP3CON @ 0x313;

char CCPR4L  @ 0x318;
char CCPR4H  @ 0x319;
char CCP4CON @ 0x31A;

char CCPR5L  @ 0x31C;
char CCPR5H  @ 0x31D;
char CCP5CON @ 0x31E;

char LATF    @ 0x38C;
char LATG    @ 0x38D;

char IOCBP   @ 0x394;
char IOCBN   @ 0x395;
char IOCBF   @ 0x396;

char ANSELF  @ 0x40C;
char ANSELG  @ 0x40D;

char TMR3L   @ 0x411;
char TMR3H   @ 0x412;
char T3CON   @ 0x413;
char T3GCON  @ 0x414;
char TMR4    @ 0x415;
char PR4     @ 0x416;
char T4CON   @ 0x417;
char TMR5L   @ 0x418;
char TMR5H   @ 0x419;
char T5CON   @ 0x41A;
char T5GCON  @ 0x41B;
char TMR6    @ 0x41C;
char PR6     @ 0x41D;
char T6CON   @ 0x41E;

char WPUG    @ 0x48D;

char RC2REG  @ 0x491;
char TX2REG  @ 0x492;
char SP2BRG  @ 0x493;
char SP2BRGH @ 0x494;
char RC2STA  @ 0x495;
char TX2STA  @ 0x496;
char BAUD2CON @ 0x497;

char TMR8    @ 0x595;
char PR8     @ 0x596;
char T8CON   @ 0x597;

char TMR10   @ 0x59C;
char PR10    @ 0x59D;
char T10CON  @ 0x59E;

char CCPR6L  @ 0x611;
char CCPR6H  @ 0x612;
char CCP6CON @ 0x613;
char CCPR7L  @ 0x614;
char CCPR7H  @ 0x615;
char CCP7CON @ 0x616;
char CCPR8L  @ 0x617;
char CCPR8H  @ 0x618;
char CCP8CON @ 0x619;
char CCPR9L  @ 0x61A;
char CCPR9H  @ 0x61B;
char CCP9CON @ 0x61C;
char CCPR10L @ 0x61D;
char CCPR10H @ 0x61E;
char CCP10CON @ 0x61F;

char STATUS_SHAD @ 0xFE4;
char WREG_SHAD @ 0xFE5;
char BSR_SHAD @ 0xFE6;
char PCLATH_SHAD @ 0xFE7;
char FSR0L_SHAD @ 0xFE8;
char FSR0H_SHAD @ 0xFE9;
char FSR1L_SHAD @ 0xFEA;
char FSR1H_SHAD @ 0xFEB;

char STKPTR  @ 0xFED;
char TOSL    @ 0xFEE;
char TOSH    @ 0xFEF;


bit  IOCIF   @ INTCON.0;
bit  INTF    @ INTCON.1;
bit  TMR0IF  @ INTCON.2;
bit  IOCIE   @ INTCON.3;
bit  INTE    @ INTCON.4;
bit  TMR0IE  @ INTCON.5;
bit  PEIE    @ INTCON.6;
bit  GIE     @ INTCON.7;

bit  TMR1IF  @ PIR1.0;
bit  TMR2IF  @ PIR1.1;
bit  CCP1IF  @ PIR1.2;
bit  SSP1IF  @ PIR1.3;
bit  TX1IF   @ PIR1.4;
bit  RC1IF   @ PIR1.5;
bit  ADIF    @ PIR1.6;
bit  TMR1GIF @ PIR1.7;

bit  CCP2IF  @ PIR2.0;
bit  TMR8IF  @ PIR2.1;
bit  TMR10IF @ PIR2.2;
bit  BCL1IF  @ PIR2.3;
bit  TMR3GIF @ PIR2.5;
bit  TMR5GIF @ PIR2.6;
bit  OSFIF   @ PIR2.7;

bit  TMR3IF  @ PIR3.0;
bit  TMR4IF  @ PIR3.1;
bit  TMR5IF  @ PIR3.2;
bit  TMR6IF  @ PIR3.3;
bit  CCP3IF  @ PIR3.4;
bit  CCP4IF  @ PIR3.5;
bit  CCP5IF  @ PIR3.6;
bit  CCP6IF  @ PIR3.7;

bit  SSP2IF  @ PIR4.0;
bit  BCL2IF  @ PIR4.1;
bit  CCP7IF  @ PIR4.2;
bit  CCP8IF  @ PIR4.3;
bit  TX2IF   @ PIR4.4;
bit  RC2IF   @ PIR4.5;
bit  CCP9IF  @ PIR4.6;
bit  CCP10IF @ PIR4.7;

bit  TMR1ON  @ T1CON.0;
bit  T1SYNC_ @ T1CON.2;
bit  T1CKPS0 @ T1CON.4;
bit  T1CKPS1 @ T1CON.5;
bit  TMR1CS0 @ T1CON.6;
bit  TMR1CS1 @ T1CON.7;

bit  T1GSS0  @ T1GCON.0;
bit  T1GSS1  @ T1GCON.1;
bit  T1GVAL  @ T1GCON.2;
bit  T1GGO   @ T1GCON.3;
bit  T1GSPM  @ T1GCON.4;
bit  T1GTM   @ T1GCON.5;
bit  T1GPOL  @ T1GCON.6;
bit  TMR1GE  @ T1GCON.7;

bit  TMR2ON  @ T2CON.2;

bit  TMR1IE  @ PIE1.0;
bit  TMR2IE  @ PIE1.1;
bit  CCP1IE  @ PIE1.2;
bit  SSP1IE  @ PIE1.3;
bit  TX1IE   @ PIE1.4;
bit  RC1IE   @ PIE1.5;
bit  ADIE    @ PIE1.6;
bit  TMR1GIE @ PIE1.7;

bit  CCP2IE  @ PIE2.0;
bit  TMR8IE  @ PIE2.1;
bit  TMR10IE @ PIE2.2;
bit  BCL1IE  @ PIE2.3;
bit  TMR3GIE @ PIE2.5;
bit  TMR5GIE @ PIE2.6;
bit  OSFIE   @ PIE2.7;

bit  TMR3IE  @ PIE3.0;
bit  TMR4IE  @ PIE3.1;
bit  TMR5IE  @ PIE3.2;
bit  TMR6IE  @ PIE3.3;
bit  CCP3IE  @ PIE3.4;
bit  CCP4IE  @ PIE3.5;
bit  CCP5IE  @ PIE3.6;
bit  CCP6IE  @ PIE3.7;

bit  SSP2IE  @ PIE4.0;
bit  BCL2IE  @ PIE4.1;
bit  CCP7IE  @ PIE4.2;
bit  CCP8IE  @ PIE4.3;
bit  TX2IE   @ PIE4.4;
bit  RC2IE   @ PIE4.5;
bit  CCP9IE  @ PIE4.6;
bit  CCP10IE @ PIE4.7;

bit  PS0     @ OPTION_REG.0;
bit  PS1     @ OPTION_REG.1;
bit  PS2     @ OPTION_REG.2;
bit  PSA     @ OPTION_REG.3;
bit  TMR0SE  @ OPTION_REG.4;
bit  TMR0CS  @ OPTION_REG.5;
bit  INTEDG  @ OPTION_REG.6;
bit  WPUEN_  @ OPTION_REG.7;

bit  BOR_    @ PCON.0;
bit  POR_    @ PCON.1;
bit  RI_     @ PCON.2;
bit  RMCLR_  @ PCON.3;
bit  RWDT_   @ PCON.4;
bit  STKUNF  @ PCON.6;
bit  STKOVF  @ PCON.7;

bit  SWDTEN  @ WDTCON.0;

bit  SCS0    @ OSCCON.0;
bit  SCS1    @ OSCCON.1;

bit  HFIOFS  @ OSCSTAT.0;
bit  LFIOFR  @ OSCSTAT.1;
bit  HFIOFR  @ OSCSTAT.4;
bit  OSTS    @ OSCSTAT.5;
bit  SOSCR   @ OSCSTAT.7;

bit  ADON    @ ADCON0.0;
bit  GO      @ ADCON0.1;
bit  CHS0    @ ADCON0.2;
bit  CHS1    @ ADCON0.3;
bit  CHS2    @ ADCON0.4;
bit  CHS3    @ ADCON0.5;
bit  CHS4    @ ADCON0.6;

bit  ADPREF0 @ ADCON1.0;
bit  ADPREF1 @ ADCON1.1;
bit  ADCS0   @ ADCON1.4;
bit  ADCS1   @ ADCON1.5;
bit  ADCS2   @ ADCON1.6;
bit  ADFM    @ ADCON1.7;

bit  BORRDY  @ BORCON.0;
bit  BORFS   @ BORCON.6;
bit  SBOREN  @ BORCON.7;

bit  ADFVR0  @ FVRCON.0;
bit  ADFVR1  @ FVRCON.1;
bit  TSRNG   @ FVRCON.4;
bit  TSEN    @ FVRCON.5;
bit  FVRRDY  @ FVRCON.6;
bit  FVREN   @ FVRCON.7;

bit  CCP2SEL @ APFCON.0;
bit  T3CKISEL @ APFCON.1;

bit  RD      @ PMCON1.0;
bit  WR      @ PMCON1.1;
bit  WREN    @ PMCON1.2;
bit  WRERR   @ PMCON1.3;
bit  FREE    @ PMCON1.4;
bit  LWLO    @ PMCON1.5;
bit  CFGS    @ PMCON1.6;

#ifdef _16F1526
bit  VREGPM  @ VREGCON.1;
#endif

bit  RX9D1   @ RC1STA.0;
bit  OERR1   @ RC1STA.1;
bit  FERR1   @ RC1STA.2;
bit  ADDEN1  @ RC1STA.3;
bit  CREN1   @ RC1STA.4;
bit  SREN1   @ RC1STA.5;
bit  RX9_1   @ RC1STA.6;
bit  SPEN1   @ RC1STA.7;

bit  TX9D1   @ TX1STA.0;
bit  TRMT1   @ TX1STA.1;
bit  BRGH1   @ TX1STA.2;
bit  SENDB1  @ TX1STA.3;
bit  SYNC1   @ TX1STA.4;
bit  TXEN1   @ TX1STA.5;
bit  TX9_1   @ TX1STA.6;
bit  CSRC1   @ TX1STA.7;

bit  ABDEN1  @ BAUD1CON.0;
bit  WUE1    @ BAUD1CON.1;
bit  BRG16_1 @ BAUD1CON.3;
bit  SCKP1   @ BAUD1CON.4;
bit  RCIDL1  @ BAUD1CON.6;
bit  ABDOVF1 @ BAUD1CON.7;

bit  BF1     @ SSP1STAT.0;
bit  UA1     @ SSP1STAT.1;
bit  RW_1    @ SSP1STAT.2;
bit  S1      @ SSP1STAT.3;
bit  P1      @ SSP1STAT.4;
bit  DA_1    @ SSP1STAT.5;
bit  CKE1    @ SSP1STAT.6;
bit  SMP1    @ SSP1STAT.7;

bit  CKP1    @ SSP1CON1.4;
bit  SSPEN1  @ SSP1CON1.5;
bit  SSPOV1  @ SSP1CON1.6;
bit  WCOL1   @ SSP1CON1.7;

bit  SEN1    @ SSP1CON2.0;
bit  RSEN1   @ SSP1CON2.1;
bit  PEN1    @ SSP1CON2.2;
bit  RCEN1   @ SSP1CON2.3;
bit  ACKEN1  @ SSP1CON2.4;
bit  ACKDT1  @ SSP1CON2.5;
bit  ACKSTAT1 @ SSP1CON2.6;
bit  GCEN1   @ SSP1CON2.7;

bit  DHEN1   @ SSP1CON3.0;
bit  AHEN1   @ SSP1CON3.1;
bit  SBCDE1  @ SSP1CON3.2;
bit  SDAHT1  @ SSP1CON3.3;
bit  BOEN1   @ SSP1CON3.4;
bit  SCIE1   @ SSP1CON3.5;
bit  PCIE1   @ SSP1CON3.6;
bit  ACKTIM1 @ SSP1CON3.7;

bit  BF2     @ SSP2STAT.0;
bit  UA2     @ SSP2STAT.1;
bit  RW_2    @ SSP2STAT.2;
bit  S2      @ SSP2STAT.3;
bit  P2      @ SSP2STAT.4;
bit  DA_2    @ SSP2STAT.5;
bit  CKE2    @ SSP2STAT.6;
bit  SMP2    @ SSP2STAT.7;

bit  CKP2    @ SSP2CON1.4;
bit  SSPEN2  @ SSP2CON1.5;
bit  SSPOV2  @ SSP2CON1.6;
bit  WCOL2   @ SSP2CON1.7;

bit  SEN2    @ SSP2CON2.0;
bit  RSEN2   @ SSP2CON2.1;
bit  PEN2    @ SSP2CON2.2;
bit  RCEN2   @ SSP2CON2.3;
bit  ACKEN2  @ SSP2CON2.4;
bit  ACKDT2  @ SSP2CON2.5;
bit  ACKSTAT2 @ SSP2CON2.6;
bit  GCEN2   @ SSP2CON2.7;

bit  DHEN2   @ SSP2CON3.0;
bit  AHEN2   @ SSP2CON3.1;
bit  SBCDE2  @ SSP2CON3.2;
bit  SDAHT2  @ SSP2CON3.3;
bit  BOEN2   @ SSP2CON3.4;
bit  SCIE2   @ SSP2CON3.5;
bit  PCIE2   @ SSP2CON3.6;
bit  ACKTIM2 @ SSP2CON3.7;

bit  TMR3ON  @ T3CON.0;
bit  T3SYNC_ @ T3CON.2;
bit  T3CKPS0 @ T3CON.4;
bit  T3CKPS1 @ T3CON.5;
bit  TMR3CS0 @ T3CON.6;
bit  TMR3CS1 @ T3CON.7;

bit  T3GSS0  @ T3GCON.0;
bit  T3GSS1  @ T3GCON.1;
bit  T3GVAL  @ T3GCON.2;
bit  T3GGO   @ T3GCON.3;
bit  T3GSPM  @ T3GCON.4;
bit  T3GTM   @ T3GCON.5;
bit  T3GPOL  @ T3GCON.6;
bit  TMR3GE  @ T3GCON.7;

bit  TMR4ON  @ T4CON.2;

bit  TMR5ON  @ T5CON.0;
bit  T5SYNC_ @ T5CON.2;
bit  T5CKPS0 @ T5CON.4;
bit  T5CKPS1 @ T5CON.5;
bit  TMR5CS0 @ T5CON.6;
bit  TMR5CS1 @ T5CON.7;

bit  T5GSS0  @ T5GCON.0;
bit  T5GSS1  @ T5GCON.1;
bit  T5GVAL  @ T5GCON.2;
bit  T5GGO   @ T5GCON.3;
bit  T5GSPM  @ T5GCON.4;
bit  T5GTM   @ T5GCON.5;
bit  T5GPOL  @ T5GCON.6;
bit  TMR5GE  @ T5GCON.7;

bit  TMR6ON  @ T6CON.2;

bit  RX9D2   @ RC2STA.0;
bit  OERR2   @ RC2STA.1;
bit  FERR2   @ RC2STA.2;
bit  ADDEN2  @ RC2STA.3;
bit  CREN2   @ RC2STA.4;
bit  SREN2   @ RC2STA.5;
bit  RX9_2   @ RC2STA.6;
bit  SPEN2   @ RC2STA.7;

bit  TX9D2   @ TX2STA.0;
bit  TRMT2   @ TX2STA.1;
bit  BRGH2   @ TX2STA.2;
bit  SENDB2  @ TX2STA.3;
bit  SYNC2   @ TX2STA.4;
bit  TXEN2   @ TX2STA.5;
bit  TX9_2   @ TX2STA.6;
bit  CSRC2   @ TX2STA.7;

bit  ABDEN2  @ BAUD2CON.0;
bit  WUE2    @ BAUD2CON.1;
bit  BRG16_2 @ BAUD2CON.3;
bit  SCKP2   @ BAUD2CON.4;
bit  RCIDL2  @ BAUD2CON.6;
bit  ABDOVF2 @ BAUD2CON.7;

bit  TMR8ON  @ T8CON.2;

bit  TMR10ON @ T10CON.2;

bit  C_SHAD  @ STATUS_SHAD.0;
bit  DC_SHAD @ STATUS_SHAD.1;
bit  Z_SHAD  @ STATUS_SHAD.2;
