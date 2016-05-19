// HEADER FILE
#pragma chip PIC16F1454, core 14 enh, code 8192, ram 32 : 0x64F // 1024 bytes
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

char TMR0    @ 0x15;
char TMR1L   @ 0x16;
char TMR1H   @ 0x17;
char T1CON   @ 0x18;
char T1GCON  @ 0x19;
char TMR2    @ 0x1A;
char PR2     @ 0x1B;
char T2CON   @ 0x1C;

char TRISA   @ 0x8C;

char TRISC   @ 0x8E;

char PIE1    @ 0x91;
char PIE2    @ 0x92;

char OPTION_REG @ 0x95;
char PCON    @ 0x96;
char WDTCON  @ 0x97;
char OSCTUNE @ 0x98;
char OSCCON  @ 0x99;
char OSCSTAT @ 0x9A;

char LATA    @ 0x10C;

char LATC    @ 0x10E;

char BORCON  @ 0x116;

char APFCON  @ 0x11D;

char PMADRL  @ 0x191;
char PMADRH  @ 0x192;
char PMDATL  @ 0x193;
char PMDATH  @ 0x194;
char PMCON1  @ 0x195;
char PMCON2  @ 0x196;
#if _16F1454
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

char SSP1BUF @ 0x211;
char SSP1ADD @ 0x212;
char SSP1MSK @ 0x213;
char SSP1STAT @ 0x214;
char SSP1CON1 @ 0x215;
char SSP1CON2 @ 0x216;
char SSP1CON3 @ 0x217;

char IOCAP   @ 0x391;
char IOCAN   @ 0x392;
char IOCAF   @ 0x393;

char CLKRCON @ 0x39A;
char ACTCON  @ 0x39B;

char PWM1DCL @ 0x611;
char PWM1DCH @ 0x612;
char PWM1CON @ 0x613;
char PWM2DCL @ 0x614;
char PWM2DCH @ 0x615;
char PWM2CON @ 0x616;

char UCON    @ 0xE8E;
char USTAT   @ 0xE8F;
char UIR     @ 0xE90;
char UCFG    @ 0xE91;
char UIE     @ 0xE92;
char UEIR    @ 0xE93;
char UFRMH   @ 0xE94;
char UFRML   @ 0xE95;
char UADDR   @ 0xE96;
char UEIE    @ 0xE97;
char UEP0    @ 0xE98;
char UEP1    @ 0xE99;
char UEP2    @ 0xE9A;
char UEP3    @ 0xE9B;
char UEP4    @ 0xE9C;
char UEP5    @ 0xE9D;
char UEP6    @ 0xE9E;
char UEP7    @ 0xE9F;

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
bit  SSP1IF  @ PIR1.3;
bit  TXIF    @ PIR1.4;
bit  RCIF    @ PIR1.5;
bit  ADIF    @ PIR1.6;
bit  TMR1GIF @ PIR1.7;

bit  ACTIF   @ PIR2.1;
bit  USBIF   @ PIR2.2;
bit  BCL1IF  @ PIR2.3;
bit  C1IF    @ PIR2.5;
bit  C2IF    @ PIR2.6;
bit  OSFIF   @ PIR2.7;

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
bit  SSP1IE  @ PIE1.3;
bit  TXIE    @ PIE1.4;
bit  RCIE    @ PIE1.5;
bit  ADIE    @ PIE1.6;
bit  TMR1GIE @ PIE1.7;

bit  ACTIE   @ PIE2.1;
bit  USBIE   @ PIE2.2;
bit  BCL1IE  @ PIE2.3;
bit  C1IE    @ PIE2.5;
bit  C2IE    @ PIE2.6;
bit  OSFIE   @ PIE2.7;

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
bit  SPLLMULT @ OSCCON.6;
bit  SPLLEN  @ OSCCON.7;

bit  HFIOFS  @ OSCSTAT.0;
bit  LFIOFR  @ OSCSTAT.1;
bit  HFIOFR  @ OSCSTAT.4;
bit  OSTS    @ OSCSTAT.5;
bit  PLLRDY  @ OSCSTAT.6;
bit  SOSCR   @ OSCSTAT.7;

bit  BORRDY  @ BORCON.0;
bit  BORFS   @ BORCON.6;
bit  SBOREN  @ BORCON.7;

bit  T1GSEL  @ APFCON.3;
bit  SSSEL   @ APFCON.5;

bit  CLKRSEL @ APFCON.7;

bit  RD      @ PMCON1.0;
bit  WR      @ PMCON1.1;
bit  WREN    @ PMCON1.2;
bit  WRERR   @ PMCON1.3;
bit  FREE    @ PMCON1.4;
bit  LWLO    @ PMCON1.5;
bit  CFGS    @ PMCON1.6;

#if _16F1454
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

bit  BF      @ SSP1STAT.0;
bit  UA      @ SSP1STAT.1;
bit  RW_     @ SSP1STAT.2;
bit  S       @ SSP1STAT.3;
bit  P       @ SSP1STAT.4;
bit  DA_     @ SSP1STAT.5;
bit  CKE     @ SSP1STAT.6;
bit  SMP     @ SSP1STAT.7;

bit  SSPM0   @ SSP1CON1.0;
bit  SSPM1   @ SSP1CON1.1;
bit  SSPM2   @ SSP1CON1.2;
bit  SSPM3   @ SSP1CON1.3;
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

bit  CLKRDIV0 @ CLKRCON.0;
bit  CLKRDIV1 @ CLKRCON.1;
bit  CLKRDIV2 @ CLKRCON.2;
bit  CLKRDC0 @ CLKRCON.3;
bit  CLKRDC1 @ CLKRCON.4;
bit  CLKRSLR @ CLKRCON.5;
bit  CLKROE  @ CLKRCON.6;
bit  CLKREN  @ CLKRCON.7;

bit  ACTORS  @ ACTCON.1;
bit  ACTLOCK @ ACTCON.3;
bit  ACTSRC  @ ACTCON.4;
bit  ACTUD   @ ACTCON.6;
bit  ACTEN   @ ACTCON.7;

bit  PWM1POL @ PWM1CON.4;
bit  PWM1OUT @ PWM1CON.5;
bit  PWM1OE  @ PWM1CON.6;
bit  PWM1EN  @ PWM1CON.7;

bit  PWM2POL @ PWM2CON.4;
bit  PWM2OUT @ PWM2CON.5;
bit  PWM2OE  @ PWM2CON.6;
bit  PWM2EN  @ PWM2CON.7;

bit  SUSPND  @ UCON.1;
bit  RESUME  @ UCON.2;
bit  USBEN   @ UCON.3;
bit  PKTDIS  @ UCON.4;
bit  SE0     @ UCON.5;
bit  PPBRST  @ UCON.6;

bit  PPBI    @ USTAT.1;
bit  DIR     @ USTAT.2;
bit  ENDP0   @ USTAT.3;
bit  ENDP1   @ USTAT.4;
bit  ENDP2   @ USTAT.5;
bit  ENDP3   @ USTAT.6;

bit  URSTIF  @ UIR.0;
bit  UERRIF  @ UIR.1;
bit  ACTVIF  @ UIR.2;
bit  TRNIF   @ UIR.3;
bit  IDLEIF  @ UIR.4;
bit  STALLIF @ UIR.5;
bit  SOFIF   @ UIR.6;

bit  PPB0    @ UCFG.0;
bit  PPB1    @ UCFG.1;
bit  FSEN    @ UCFG.2;
bit  UPUEN   @ UCFG.4;
bit  UTEYE   @ UCFG.7;

bit  URSTIE  @ UIE.0;
bit  UERRIE  @ UIE.1;
bit  ACTVIE  @ UIE.2;
bit  TRNIE   @ UIE.3;
bit  IDLEIE  @ UIE.4;
bit  STALLIE @ UIE.5;
bit  SOFIE   @ UIE.6;

bit  PIDEF   @ UEIR.0;
bit  CRC5EF  @ UEIR.1;
bit  CRC16EF @ UEIR.2;
bit  DFN8EF  @ UEIR.3;
bit  BTOEF   @ UEIR.4;
bit  BTSEF   @ UEIR.7;

bit  PIDEE   @ UEIE.0;
bit  CRC5EE  @ UEIE.1;
bit  CRC16EE @ UEIE.2;
bit  DFN8EE  @ UEIE.3;
bit  BTOEE   @ UEIE.4;
bit  BTSEE   @ UEIE.7;

bit  C_SHAD  @ STATUS_SHAD.0;
bit  DC_SHAD @ STATUS_SHAD.1;
bit  Z_SHAD  @ STATUS_SHAD.2;
