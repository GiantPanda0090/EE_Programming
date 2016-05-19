// HEADER FILE
#pragma chip PIC16F1765, core 14 enh, code 8192, ram 32 : 0x64F // 1024 bytes

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

char PORTC   @ 0x0E;

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
char T2PR    @ 0x1B;
char T2CON   @ 0x1C;
char T2HLT   @ 0x1D;
char T2CLKCON @ 0x1E;
char T2RST   @ 0x1F;

char TRISA   @ 0x8C;

char TRISC   @ 0x8E;

char PIE1    @ 0x91;
char PIE2    @ 0x92;
char PIE3    @ 0x93;
char PIE4    @ 0x94;
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

char LATC    @ 0x10E;
char CMOUT   @ 0x10F;
char CM1CON0 @ 0x110;
char CM1CON1 @ 0x111;
char CM1NSEL @ 0x112;
char CM1PSEL @ 0x113;
char CM2CON0 @ 0x114;
char CM2CON1 @ 0x115;
char CM2NSEL @ 0x116;
char CM2PSEL @ 0x117;

char ANSELA  @ 0x18C;

char ANSELC  @ 0x18E;

char PMADRL  @ 0x191;
char PMADRH  @ 0x192;
char PMDATL  @ 0x193;
char PMDATH  @ 0x194;
char PMCON1  @ 0x195;
char PMCON2  @ 0x196;
#if _16F1765
char VREGCON @ 0x197;
#endif

char RC1REG  @ 0x199;
char TX1REG  @ 0x19A;
char SP1BRGL @ 0x19B;
char SP1BRGH @ 0x19C;
char RC1STA  @ 0x19D;
char TX1STA  @ 0x19E;
char BAUD1CON @ 0x19F;

char WPUA    @ 0x20C;

char WPUC    @ 0x20E;

char SSP1BUF @ 0x211;
char SSP1ADD @ 0x212;
char SSP1MSK @ 0x213;
char SSP1STAT @ 0x214;
char SSP1CON1 @ 0x215;
char SSP1CON2 @ 0x216;
char SSP1CON3 @ 0x217;

char BORCON  @ 0x21D;
char FVRCON  @ 0x21E;
char ZCD1CON @ 0x21F;

char ODCONA  @ 0x28C;

char ODCONC  @ 0x28E;

char CCPR1L  @ 0x291;
char CCPR1H  @ 0x292;
char CCP1CON @ 0x293;
char CCP1CAP @ 0x294;

char CCPTMRS @ 0x29E;

char SLRCONA @ 0x30C;

char SLRCONC @ 0x30E;

char INLVLA  @ 0x38C;

char INLVLC  @ 0x38E;

char IOCAP   @ 0x391;
char IOCAN   @ 0x392;
char IOCAF   @ 0x393;

char IOCCP   @ 0x397;
char IOCCN   @ 0x398;
char IOCCF   @ 0x399;

char MD1CON0 @ 0x39B;
char MD1CON1 @ 0x39C;
char MD1SRC  @ 0x39D;
char MD1CARL @ 0x39E;
char MD1CARH @ 0x39F;

char HIDRVC  @ 0x40E;

char T4TMR   @ 0x413;
char T4PR    @ 0x414;
char T4CON   @ 0x415;
char T4HLT   @ 0x416;
char T4CLKCON @ 0x417;
char T4RST   @ 0x418;

char T6TMR   @ 0x41A;
char T6PR    @ 0x41B;
char T6CON   @ 0x41C;
char T6HLT   @ 0x41D;
char T6CLKCON @ 0x41E;
char T6RST   @ 0x41F;

char TMR3L   @ 0x493;
char TMR3H   @ 0x494;
char T3CON   @ 0x495;
char T3GCON  @ 0x496;

char TMR5L   @ 0x49A;
char TMR5H   @ 0x49B;
char T5CON   @ 0x49C;
char T5GCON  @ 0x49D;

char OPA1NCHS @ 0x50F;
char OPA1PCHS @ 0x510;
char OPA1CON @ 0x511;
char OPA1ORS @ 0x512;

char DACLD   @ 0x590;
char DAC1CON0 @ 0x591;
char DAC1REFL @ 0x592;
char DAC1REFH @ 0x593;

char DAC3CON0 @ 0x597;
char DAC3REF  @ 0x598;

char PWM3DCL @ 0x617;
char PWM3DCH @ 0x618;
char PWM3CON @ 0x619;

char COG1PHR @ 0x68D;
char COG1PHF @ 0x68E;
char COG1BLKR @ 0x68F;
char COG1BLKF @ 0x690;
char COG1DBR @ 0x691;
char COG1DBF @ 0x692;
char COG1CON0 @ 0x693;
char COG1CON1 @ 0x694;
char COG1RIS0 @ 0x695;
char COG1RIS1 @ 0x696;
char COG1RSIM0 @ 0x697;
char COG1RSIM1 @ 0x698;
char COG1FIS0 @ 0x699;
char COG1FIS1 @ 0x69A;
char COG1FSIM0 @ 0x69B;
char COG1FSIM1 @ 0x69C;
char COG1ASD0 @ 0x69D;
char COG1ASD1 @ 0x69E;
char COG1STR @ 0x69F;

char PRG1RTSS @ 0x794;
char PRG1FTSS @ 0x795;
char PRG1INS @ 0x796;
char PRG1CON0 @ 0x797;
char PRG1CON1 @ 0x798;
char PRG1CON2 @ 0x799;

char PWMEN   @ 0xD8E;
char PWMLD   @ 0xD8F;
char PWMOUT  @ 0xD90;
char PWM5PHL @ 0xD91;
char PWM5PHH @ 0xD92;
char PWM5DCL @ 0xD93;
char PWM5DCH @ 0xD94;
char PWM5PRL @ 0xD95;
char PWM5PRH @ 0xD96;
char PWM5OFL @ 0xD97;
char PWM5OFH @ 0xD98;
char PWM5TMRL @ 0xD99;
char PWM5TMRH @ 0xD9A;
char PWM5CON @ 0xD9B;
char PWM5INTE @ 0xD9C;
char PWM5INTF @ 0xD9D;
char PWM5CLKCON @ 0xD9E;
char PWM5LDCON @ 0xD9F;
char PWM5OFCON @ 0xDA0;

char PPSLOCK @ 0xE0F;
char INTPPS  @ 0xE10;
char T0CKIPPS @ 0xE11;
char T1CKIPPS @ 0xE12;
char T1GPPS  @ 0xE13;
char CCP1PPS @ 0xE14;

char COG1INPPS @ 0xE16;

char T2CKIPPS @ 0xE19;
char T3CKIPPS @ 0xE1A;
char T3GPPS  @ 0xE1B;
char T4CKIPPS @ 0xE1C;
char T5CKIPPS @ 0xE1D;
char T5GPPS  @ 0xE1E;
char T6CKIPPS @ 0xE1F;
char SSPCLKPPS @ 0xE20;
char SSPDATPPS @ 0xE21;
char SSPSSPPS @ 0xE22;

char RXPPS   @ 0xE24;
char CKPPS   @ 0xE25;

char CLCIN0PPS @ 0xE28;
char CLCIN1PPS @ 0xE29;
char CLCIN2PPS @ 0xE2A;
char CLCIN3PPS @ 0xE2B;
char PRG1RPPS @ 0xE2C;
char PRG1FPPS @ 0xE2D;

char MD1CHPPS @ 0xE30;
char MD1CLPPS @ 0xE31;
char MD1MODPPS @ 0xE32;

char RA0PPS  @ 0xE90;
char RA1PPS  @ 0xE91;
char RA2PPS  @ 0xE92;

char RA4PPS  @ 0xE94;
char RA5PPS  @ 0xE95;

char RC0PPS  @ 0xEA0;
char RC1PPS  @ 0xEA1;
char RC2PPS  @ 0xEA2;
char RC3PPS  @ 0xEA3;
char RC4PPS  @ 0xEA4;
char RC5PPS  @ 0xEA5;

char CLCDATA @ 0xF0F;
char CLC1CON @ 0xF10;
char CLC1POL @ 0xF11;
char CLC1SEL0 @ 0xF12;
char CLC1SEL1 @ 0xF13;
char CLC1SEL2 @ 0xF14;
char CLC1SEL3 @ 0xF15;
char CLC1GLS0 @ 0xF16;
char CLC1GLS1 @ 0xF17;
char CLC1GLS2 @ 0xF18;
char CLC1GLS3 @ 0xF19;
char CLC2CON @ 0xF1A;
char CLC2POL @ 0xF1B;
char CLC2SEL0 @ 0xF1C;
char CLC2SEL1 @ 0xF1D;
char CLC2SEL2 @ 0xF1E;
char CLC2SEL3 @ 0xF1F;
char CLC2GLS0 @ 0xF20;
char CLC2GLS1 @ 0xF21;
char CLC2GLS2 @ 0xF22;
char CLC2GLS3 @ 0xF23;
char CLC3CON @ 0xF24;
char CLC3POL @ 0xF25;
char CLC3SEL0 @ 0xF26;
char CLC3SEL1 @ 0xF27;
char CLC3SEL2 @ 0xF28;
char CLC3SEL3 @ 0xF29;
char CLC3GLS0 @ 0xF2A;
char CLC3GLS1 @ 0xF2B;
char CLC3GLS2 @ 0xF2C;
char CLC3GLS3 @ 0xF2D;

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
bit  TXIF    @ PIR1.4;
bit  RCIF    @ PIR1.5;
bit  ADIF    @ PIR1.6;
bit  TMR1GIF @ PIR1.7;

bit  BCL1IF  @ PIR2.3;
bit  C1IF    @ PIR2.5;
bit  C2IF    @ PIR2.6;
bit  OSFIF   @ PIR2.7;

bit  CLC1IF  @ PIR3.0;
bit  CLC2IF  @ PIR3.1;
bit  CLC3IF  @ PIR3.2;

bit  ZCDIF   @ PIR3.4;
bit  COG1IF  @ PIR3.5;
bit  PWM5IF  @ PIR3.6;


bit  TMR4IF  @ PIR4.0;
bit  TMR6IF  @ PIR4.1;
bit  TMR3IF  @ PIR4.2;
bit  TMR3GIF @ PIR4.3;
bit  TMR5IF  @ PIR4.4;
bit  TMR5GIF @ PIR4.5;

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

bit  TMR2ON  @ T2CON.7;

bit  TMR1IE  @ PIE1.0;
bit  TMR2IE  @ PIE1.1;
bit  CCP1IE  @ PIE1.2;
bit  SSP1IE  @ PIE1.3;
bit  TXIE    @ PIE1.4;
bit  RCIE    @ PIE1.5;
bit  ADIE    @ PIE1.6;
bit  TMR1GIE @ PIE1.7;

bit  BCL1IE  @ PIE2.3;
bit  C1IE    @ PIE2.5;
bit  C2IE    @ PIE2.6;
bit  OSFIE   @ PIE2.7;

bit  CLC1IE  @ PIE3.0;
bit  CLC2IE  @ PIE3.1;
bit  CLC3IE  @ PIE3.2;

bit  ZCDIE   @ PIE3.4;
bit  COGIE   @ PIE3.5;
bit  PWM5IE  @ PIE3.6;

bit  TMR4IE  @ PIE4.0;
bit  TMR6IE  @ PIE4.1;
bit  TMR3IE  @ PIE4.2;
bit  TMR3GIE @ PIE4.3;
bit  TMR5IE  @ PIE4.4;
bit  TMR5GIE @ PIE4.5;

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
bit  ADNREF  @ ADCON1.2;
bit  ADFM    @ ADCON1.7;

bit  MC1OUT  @ CMOUT.0;
bit  MC2OUT  @ CMOUT.1;

bit  RD      @ PMCON1.0;
bit  WR      @ PMCON1.1;
bit  WREN    @ PMCON1.2;
bit  WRERR   @ PMCON1.3;
bit  FREE    @ PMCON1.4;
bit  LWLO    @ PMCON1.5;
bit  CFGS    @ PMCON1.6;

#if _16F1765
bit  VREGPM  @ VREGCON.1;
#endif

bit  RX9D    @ RC1STA.0;
bit  OERR    @ RC1STA.1;
bit  FERR    @ RC1STA.2;
bit  ADDEN   @ RC1STA.3;
bit  CREN    @ RC1STA.4;
bit  SREN    @ RC1STA.5;
bit  RX9     @ RC1STA.6;
bit  SPEN    @ RC1STA.7;

bit  TX9D    @ TX1STA.0;
bit  TRMT    @ TX1STA.1;
bit  BRGH    @ TX1STA.2;
bit  SENDB   @ TX1STA.3;
bit  SYNC    @ TX1STA.4;
bit  TXEN    @ TX1STA.5;
bit  TX9     @ TX1STA.6;
bit  CSRC    @ TX1STA.7;

bit  ABDEN   @ BAUD1CON.0;
bit  WUE     @ BAUD1CON.1;
bit  BRG16   @ BAUD1CON.3;
bit  SCKP    @ BAUD1CON.4;
bit  RCIDL   @ BAUD1CON.6;
bit  ABDOVF  @ BAUD1CON.7;

bit  BF      @ SSP1STAT.0;
bit  UA      @ SSP1STAT.1;
bit  RW_     @ SSP1STAT.2;
bit  S       @ SSP1STAT.3;
bit  P       @ SSP1STAT.4;
bit  DA_     @ SSP1STAT.5;
bit  CKE     @ SSP1STAT.6;
bit  SMP     @ SSP1STAT.7;

bit  CKP     @ SSP1CON1.4;
bit  SSPEN   @ SSP1CON1.5;
bit  SSPOV   @ SSP1CON1.6;
bit  WCOL    @ SSP1CON1.7;

bit  SEN     @ SSP1CON2.0;
bit  RSEN    @ SSP1CON2.1;
bit  PEN     @ SSP1CON2.2;
bit  RCEN    @ SSP1CON2.3;
bit  ACKEN   @ SSP1CON2.4;
bit  ACKDT   @ SSP1CON2.5;
bit  ACKSTAT @ SSP1CON2.6;
bit  GCEN    @ SSP1CON2.7;

bit  DHEN    @ SSP1CON3.0;
bit  AHEN    @ SSP1CON3.1;
bit  SBCDE   @ SSP1CON3.2;
bit  SDAHT   @ SSP1CON3.3;
bit  BOEN    @ SSP1CON3.4;
bit  SCIE    @ SSP1CON3.5;
bit  PCIE    @ SSP1CON3.6;
bit  ACKTIM  @ SSP1CON3.7;

bit  BORRDY  @ BORCON.0;
bit  BORFS   @ BORCON.6;
bit  SBOREN  @ BORCON.7;

bit  TSRNG   @ FVRCON.4;
bit  TSEN    @ FVRCON.5;
bit  FVRRDY  @ FVRCON.6;
bit  FVREN   @ FVRCON.7;

bit  TMR4ON  @ T4CON.7;

bit  TMR6ON  @ T6CON.7;

bit  TMR3ON  @ T3CON.0;

bit  TMR5ON  @ T5CON.0;

bit  DAC1LD  @ DACLD.0;

bit  MPWM5EN @ PWMEN.4;

bit  MPWM5LD @ PWMLD.4;

bit  MPWM5OUT @ PWMOUT.4;

bit  PPSLOCKED @ PPSLOCK.0;

bit  MCLC1OUT @ CLCDATA.0;
bit  MCLC2OUT @ CLCDATA.1;
bit  MCLC3OUT @ CLCDATA.2;

bit  LC1MODE0 @ CLC1CON.0;
bit  LC1MODE1 @ CLC1CON.1;
bit  LC1MODE2 @ CLC1CON.2;
bit  LC1INTN @ CLC1CON.3;
bit  LC1INTP @ CLC1CON.4;
bit  LC1OUT  @ CLC1CON.5;
bit  LC1EN   @ CLC1CON.7;

bit  LC1POL  @ CLC1POL.7;

bit  LC1G1D1N @ CLC1GLS0.0;
bit  LC1G1D1T @ CLC1GLS0.1;
bit  LC1G1D2N @ CLC1GLS0.2;
bit  LC1G1D2T @ CLC1GLS0.3;
bit  LC1G1D3N @ CLC1GLS0.4;
bit  LC1G1D3T @ CLC1GLS0.5;
bit  LC1G1D4N @ CLC1GLS0.6;
bit  LC1G1D4T @ CLC1GLS0.7;

bit  LC1G2D1N @ CLC1GLS1.0;
bit  LC1G2D1T @ CLC1GLS1.1;
bit  LC1G2D2N @ CLC1GLS1.2;
bit  LC1G2D2T @ CLC1GLS1.3;
bit  LC1G2D3N @ CLC1GLS1.4;
bit  LC1G2D3T @ CLC1GLS1.5;
bit  LC1G2D4N @ CLC1GLS1.6;
bit  LC1G2D4T @ CLC1GLS1.7;

bit  LC1G3D1N @ CLC1GLS2.0;
bit  LC1G3D1T @ CLC1GLS2.1;
bit  LC1G3D2N @ CLC1GLS2.2;
bit  LC1G3D2T @ CLC1GLS2.3;
bit  LC1G3D3N @ CLC1GLS2.4;
bit  LC1G3D3T @ CLC1GLS2.5;
bit  LC1G3D4N @ CLC1GLS2.6;
bit  LC1G3D4T @ CLC1GLS2.7;

bit  LC1G4D1N @ CLC1GLS3.0;
bit  LC1G4D1T @ CLC1GLS3.1;
bit  LC1G4D2N @ CLC1GLS3.2;
bit  LC1G4D2T @ CLC1GLS3.3;
bit  LC1G4D3N @ CLC1GLS3.4;
bit  LC1G4D3T @ CLC1GLS3.5;
bit  LC1G4D4N @ CLC1GLS3.6;
bit  LC1G4D4T @ CLC1GLS3.7;

bit  LC2MODE0 @ CLC2CON.0;
bit  LC2MODE1 @ CLC2CON.1;
bit  LC2MODE2 @ CLC2CON.2;
bit  LC2INTN @ CLC2CON.3;
bit  LC2INTP @ CLC2CON.4;
bit  LC2OUT  @ CLC2CON.5;
bit  LC2EN   @ CLC2CON.7;

bit  LC2POL  @ CLC2POL.7;

bit  LC2G1D1N @ CLC2GLS0.0;
bit  LC2G1D1T @ CLC2GLS0.1;
bit  LC2G1D2N @ CLC2GLS0.2;
bit  LC2G1D2T @ CLC2GLS0.3;
bit  LC2G1D3N @ CLC2GLS0.4;
bit  LC2G1D3T @ CLC2GLS0.5;
bit  LC2G1D4N @ CLC2GLS0.6;
bit  LC2G1D4T @ CLC2GLS0.7;

bit  LC2G2D1N @ CLC2GLS1.0;
bit  LC2G2D1T @ CLC2GLS1.1;
bit  LC2G2D2N @ CLC2GLS1.2;
bit  LC2G2D2T @ CLC2GLS1.3;
bit  LC2G2D3N @ CLC2GLS1.4;
bit  LC2G2D3T @ CLC2GLS1.5;
bit  LC2G2D4N @ CLC2GLS1.6;
bit  LC2G2D4T @ CLC2GLS1.7;

bit  LC2G3D1N @ CLC2GLS2.0;
bit  LC2G3D1T @ CLC2GLS2.1;
bit  LC2G3D2N @ CLC2GLS2.2;
bit  LC2G3D2T @ CLC2GLS2.3;
bit  LC2G3D3N @ CLC2GLS2.4;
bit  LC2G3D3T @ CLC2GLS2.5;
bit  LC2G3D4N @ CLC2GLS2.6;
bit  LC2G3D4T @ CLC2GLS2.7;

bit  LC2G4D1N @ CLC2GLS3.0;
bit  LC2G4D1T @ CLC2GLS3.1;
bit  LC2G4D2N @ CLC2GLS3.2;
bit  LC2G4D2T @ CLC2GLS3.3;
bit  LC2G4D3N @ CLC2GLS3.4;
bit  LC2G4D3T @ CLC2GLS3.5;
bit  LC2G4D4N @ CLC2GLS3.6;
bit  LC2G4D4T @ CLC2GLS3.7;

bit  LC3MODE0 @ CLC3CON.0;
bit  LC3MODE1 @ CLC3CON.1;
bit  LC3MODE2 @ CLC3CON.2;
bit  LC3INTN @ CLC3CON.3;
bit  LC3INTP @ CLC3CON.4;
bit  LC3OUT  @ CLC3CON.5;
bit  LC3EN   @ CLC3CON.7;

bit  LC3POL  @ CLC3POL.7;

bit  LC3G1D1N @ CLC3GLS0.0;
bit  LC3G1D1T @ CLC3GLS0.1;
bit  LC3G1D2N @ CLC3GLS0.2;
bit  LC3G1D2T @ CLC3GLS0.3;
bit  LC3G1D3N @ CLC3GLS0.4;
bit  LC3G1D3T @ CLC3GLS0.5;
bit  LC3G1D4N @ CLC3GLS0.6;
bit  LC3G1D4T @ CLC3GLS0.7;

bit  LC3G2D1N @ CLC3GLS1.0;
bit  LC3G2D1T @ CLC3GLS1.1;
bit  LC3G2D2N @ CLC3GLS1.2;
bit  LC3G2D2T @ CLC3GLS1.3;
bit  LC3G2D3N @ CLC3GLS1.4;
bit  LC3G2D3T @ CLC3GLS1.5;
bit  LC3G2D4N @ CLC3GLS1.6;
bit  LC3G2D4T @ CLC3GLS1.7;

bit  LC3G3D1N @ CLC3GLS2.0;
bit  LC3G3D1T @ CLC3GLS2.1;
bit  LC3G3D2N @ CLC3GLS2.2;
bit  LC3G3D2T @ CLC3GLS2.3;
bit  LC3G3D3N @ CLC3GLS2.4;
bit  LC3G3D3T @ CLC3GLS2.5;
bit  LC3G3D4N @ CLC3GLS2.6;
bit  LC3G3D4T @ CLC3GLS2.7;

bit  LC3G4D1N @ CLC3GLS3.0;
bit  LC3G4D1T @ CLC3GLS3.1;
bit  LC3G4D2N @ CLC3GLS3.2;
bit  LC3G4D2T @ CLC3GLS3.3;
bit  LC3G4D3N @ CLC3GLS3.4;
bit  LC3G4D3T @ CLC3GLS3.5;
bit  LC3G4D4N @ CLC3GLS3.6;
bit  LC3G4D4T @ CLC3GLS3.7;

bit  C_SHAD  @ STATUS_SHAD.0;
bit  DC_SHAD @ STATUS_SHAD.1;
bit  Z_SHAD  @ STATUS_SHAD.2;
