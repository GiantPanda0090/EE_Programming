// HEADER FILE
#pragma chip PIC16F1578, core 14 enh, code 4096, ram 32 : 0x32F // 512 bytes

#pragma ramdef  0x70 : 0x7F mapped_into_all_banks

#define INT_enh_style

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

char PIR1    @ 0x11;
char PIR2    @ 0x12;
char PIR3    @ 0x13;

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

char PIE1    @ 0x91;
char PIE2    @ 0x92;
char PIE3    @ 0x93;

char OPTION_REG @ 0x95;
char PCON    @ 0x96;
char WDTCON  @ 0x97;
char OSCTUNE @ 0x98;
char OSCCON  @ 0x99;
char OSCSTAT @ 0x9A;
char ADRESL  @ 0x9B;
char ADRESH  @ 0x9C;
char ADCON0  @ 0x9D;
char ADCON1  @ 0x9E;
char ADCON2  @ 0x9F;

char LATA    @ 0x10C;
char LATB    @ 0x10D;
char LATC    @ 0x10E;

char CM1CON0 @ 0x111;
char CM1CON1 @ 0x112;
char CM2CON0 @ 0x113;
char CM2CON1 @ 0x114;
char CMOUT   @ 0x115;
char BORCON  @ 0x116;
char FVRCON  @ 0x117;
char DACCON0 @ 0x118;
char DACCON1 @ 0x119;

char ANSELA  @ 0x18C;
char ANSELB  @ 0x18D;
char ANSELC  @ 0x18E;

char PMADRL  @ 0x191;
char PMADRH  @ 0x192;
char PMDATL  @ 0x193;
char PMDATH  @ 0x194;
char PMCON1  @ 0x195;
char PMCON2  @ 0x196;
#if _16F1578
char VREGCON @ 0x197;
#endif

char RCREG   @ 0x199;
char TXREG   @ 0x19A;
char SPBRGL  @ 0x19B;
char SPBRGH  @ 0x19C;
char RCSTA   @ 0x19D;
char TXSTA   @ 0x19E;
char BAUDCON @ 0x19F;

char WPUA    @ 0x20C;
char WPUB    @ 0x20D;
char WPUC    @ 0x20E;

char ODCONA  @ 0x28C;
char ODCONB  @ 0x28D;
char ODCONC  @ 0x28E;

char SLRCONA @ 0x30C;
char SLRCONB @ 0x30D;
char SLRCONC @ 0x30E;

char INLVLA  @ 0x38C;
char INLVLB  @ 0x38D;
char INLVLC  @ 0x38E;

char IOCAP   @ 0x391;
char IOCAN   @ 0x392;
char IOCAF   @ 0x393;
char IOCBP   @ 0x394;
char IOCBN   @ 0x395;
char IOCBF   @ 0x396;
char IOCCP   @ 0x397;
char IOCCN   @ 0x398;
char IOCCF   @ 0x399;

char CWG1DBR @ 0x691;
char CWG1DBF @ 0x692;
char CWG1CON0 @ 0x693;
char CWG1CON1 @ 0x694;
char CWG1CON2 @ 0x695;

char PWMEN   @ 0xD8E;
char PWMLD   @ 0xD8F;
char PWMOUT  @ 0xD90;
char PWM1PHL @ 0xD91;
char PWM1PHH @ 0xD92;
char PWM1DCL @ 0xD93;
char PWM1DCH @ 0xD94;
char PWM1PRL @ 0xD95;
char PWM1PRH @ 0xD96;
char PWM1OFL @ 0xD97;
char PWM1OFH @ 0xD98;
char PWM1TMRL @ 0xD99;
char PWM1TMRH @ 0xD9A;
char PWM1CON @ 0xD9B;
char PWM1INTE @ 0xD9C;
char PWM1INTF @ 0xD9D;
char PWM1CLKCON @ 0xD9E;
char PWM1LDCON @ 0xD9F;
char PWM1OFCON @ 0xDA0;
char PWM2PHL @ 0xDA1;
char PWM2PHH @ 0xDA2;
char PWM2DCL @ 0xDA3;
char PWM2DCH @ 0xDA4;
char PWM2PRL @ 0xDA5;
char PWM2PRH @ 0xDA6;
char PWM2OFL @ 0xDA7;
char PWM2OFH @ 0xDA8;
char PWM2TMRL @ 0xDA9;
char PWM2TMRH @ 0xDAA;
char PWM2CON @ 0xDAB;
char PWM2INTE @ 0xDAC;
char PWM2INTF @ 0xDAD;
char PWM2CLKCON @ 0xDAE;
char PWM2LDCON @ 0xDAF;
char PWM2OFCON @ 0xDB0;
char PWM3PHL @ 0xDB1;
char PWM3PHH @ 0xDB2;
char PWM3DCL @ 0xDB3;
char PWM3DCH @ 0xDB4;
char PWM3PRL @ 0xDB5;
char PWM3PRH @ 0xDB6;
char PWM3OFL @ 0xDB7;
char PWM3OFH @ 0xDB8;
char PWM3TMRL @ 0xDB9;
char PWM3TMRH @ 0xDBA;
char PWM3CON @ 0xDBB;
char PWM3INTE @ 0xDBC;
char PWM3INTF @ 0xDBD;
char PWM3CLKCON @ 0xDBE;
char PWM3LDCON @ 0xDBF;
char PWM3OFCON @ 0xDC0;
char PWM4PHL @ 0xDC1;
char PWM4PHH @ 0xDC2;
char PWM4DCL @ 0xDC3;
char PWM4DCH @ 0xDC4;
char PWM4PRL @ 0xDC5;
char PWM4PRH @ 0xDC6;
char PWM4OFL @ 0xDC7;
char PWM4OFH @ 0xDC8;
char PWM4TMRL @ 0xDC9;
char PWM4TMRH @ 0xDCA;
char PWM4CON @ 0xDCB;
char PWM4INTE @ 0xDCC;
char PWM4INTF @ 0xDCD;
char PWM4CLKCON @ 0xDCE;
char PWM4LDCON @ 0xDCF;
char PWM4OFCON @ 0xDD0;

char PPSLOCK @ 0xE0F;
char INTPPS  @ 0xE10;
char T0CKIPPS @ 0xE11;
char T1CKIPPS @ 0xE12;
char T1GPPS  @ 0xE13;
char CWG1PPS @ 0xE14;
char RXPPS   @ 0xE15;
char CKPPS   @ 0xE16;
char ADCACTPPS @ 0xE17;

char RA0PPS  @ 0xE90;
char RA1PPS  @ 0xE91;
char RA2PPS  @ 0xE92;

char RA4PPS  @ 0xE94;
char RA5PPS  @ 0xE95;

char RB4PPS  @ 0xE9C;
char RB5PPS  @ 0xE9D;
char RB6PPS  @ 0xE9E;
char RB7PPS  @ 0xE9F;
char RC0PPS  @ 0xEA0;
char RC1PPS  @ 0xEA1;
char RC2PPS  @ 0xEA2;
char RC3PPS  @ 0xEA3;
char RC4PPS  @ 0xEA4;
char RC5PPS  @ 0xEA5;
char RC6PPS  @ 0xEA6;
char RC7PPS  @ 0xEA7;

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
bit  TXIF    @ PIR1.4;
bit  RCIF    @ PIR1.5;
bit  ADIF    @ PIR1.6;
bit  TMR1GIF @ PIR1.7;

bit  C1IF    @ PIR2.5;
bit  C2IF    @ PIR2.6;

bit  PWM1IF  @ PIR3.4;
bit  PWM2IF  @ PIR3.5;
bit  PWM3IF  @ PIR3.6;
bit  PWM4IF  @ PIR3.7;

bit  TMR1ON  @ T1CON.0;
bit  T1SYNC_ @ T1CON.2;
bit  T1OSCEN @ T1CON.3;
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
bit  TXIE    @ PIE1.4;
bit  RCIE    @ PIE1.5;
bit  ADIE    @ PIE1.6;
bit  TMR1GIE @ PIE1.7;

bit  C1IE    @ PIE2.5;
bit  C2IE    @ PIE2.6;

bit  PWM1IE  @ PIE3.4;
bit  PWM2IE  @ PIE3.5;
bit  PWM3IE  @ PIE3.6;
bit  PWM4IE  @ PIE3.7;

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
bit  SPLLEN  @ OSCCON.7;

bit  HFIOFS  @ OSCSTAT.0;
bit  LFIOFR  @ OSCSTAT.1;
bit  MFIOFR  @ OSCSTAT.2;
bit  HFIOFL  @ OSCSTAT.3;
bit  HFIOFR  @ OSCSTAT.4;
bit  OSTS    @ OSCSTAT.5;
bit  PLLR    @ OSCSTAT.6;

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

bit  TRIGSEL0 @ ADCON2.4;
bit  TRIGSEL1 @ ADCON2.5;
bit  TRIGSEL2 @ ADCON2.6;
bit  TRIGSEL3 @ ADCON2.7;

bit  MC1OUT  @ CMOUT.0;
bit  MC2OUT  @ CMOUT.1;

bit  BORRDY  @ BORCON.0;
bit  BORFS   @ BORCON.6;
bit  SBOREN  @ BORCON.7;

bit  ADFVR0  @ FVRCON.0;
bit  ADFVR1  @ FVRCON.1;
bit  CDAFVR0 @ FVRCON.2;
bit  CDAFVR1 @ FVRCON.3;
bit  TSRNG   @ FVRCON.4;
bit  TSEN    @ FVRCON.5;
bit  FVRRDY  @ FVRCON.6;
bit  FVREN   @ FVRCON.7;

bit  DACPSS0 @ DACCON0.2;
bit  DACPSS1 @ DACCON0.3;
bit  DACOE   @ DACCON0.5;
bit  DACEN   @ DACCON0.7;

bit  RD      @ PMCON1.0;
bit  WR      @ PMCON1.1;
bit  WREN    @ PMCON1.2;
bit  WRERR   @ PMCON1.3;
bit  FREE    @ PMCON1.4;
bit  LWLO    @ PMCON1.5;
bit  CFGS    @ PMCON1.6;

#if _16F1578
bit  VREGPM  @ VREGCON.1;
#endif

bit  RX9D    @ RCSTA.0;
bit  OERR    @ RCSTA.1;
bit  FERR    @ RCSTA.2;
bit  ADDEN   @ RCSTA.3;
bit  CREN    @ RCSTA.4;
bit  SREN    @ RCSTA.5;
bit  RX9     @ RCSTA.6;
bit  SPEN    @ RCSTA.7;

bit  TX9D    @ TXSTA.0;
bit  TRMT    @ TXSTA.1;
bit  BRGH    @ TXSTA.2;
bit  SENDB   @ TXSTA.3;
bit  SYNC    @ TXSTA.4;
bit  TXEN    @ TXSTA.5;
bit  TX9     @ TXSTA.6;
bit  CSRC    @ TXSTA.7;

bit  ABDEN   @ BAUDCON.0;
bit  WUE     @ BAUDCON.1;
bit  BRG16   @ BAUDCON.3;
bit  SCKP    @ BAUDCON.4;
bit  RCIDL   @ BAUDCON.6;
bit  ABDOVF  @ BAUDCON.7;

bit  G1ASDSPPS @ CWG1CON2.1;
bit  G1ASDSC1 @ CWG1CON2.2;
bit  G1ASDSC2 @ CWG1CON2.3;
bit  G1ARSEN @ CWG1CON2.6;
bit  G1ASE   @ CWG1CON2.7;

bit  PWM1EN_A @ PWMEN.0;
bit  PWM2EN_A @ PWMEN.1;
bit  PWM3EN_A @ PWMEN.2;
bit  PWM4EN_A @ PWMEN.3;

bit  PWM1LDA_A @ PWMLD.0;
bit  PWM2LDA_A @ PWMLD.1;
bit  PWM3LDA_A @ PWMLD.2;
bit  PWM4LDA_A @ PWMLD.3;

bit  PWM1OUT_A @ PWMOUT.0;
bit  PWM2OUT_A @ PWMOUT.1;
bit  PWM3OUT_A @ PWMOUT.2;
bit  PWM4OUT_A @ PWMOUT.3;

bit  C_SHAD  @ STATUS_SHAD.0;
bit  DC_SHAD @ STATUS_SHAD.1;
bit  Z_SHAD  @ STATUS_SHAD.2;
