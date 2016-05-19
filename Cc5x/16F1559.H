// HEADER FILE
#pragma chip PIC16LF1559, core 14 enh, code 8192, ram 32 : 0x32F // 512 bytes

#pragma ramdef  0x70 : 0x7F mapped_into_all_banks

#define INT_enh_style

#pragma config_def 0

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

char OPTION_REG @ 0x95;
char PCON    @ 0x96;
char WDTCON  @ 0x97;

char OSCCON  @ 0x99;
char OSCSTAT @ 0x9A;
char ADRESL  @ 0x9B;
char AD1RES0L @ 0x9B;
char ADRESH  @ 0x9C;
char AD1RES0H @ 0x9C;
char ADCON0  @ 0x9D;
char ADCON1  @ 0x9E;
char ADCON2  @ 0x9F;

char LATA    @ 0x10C;
char LATB    @ 0x10D;
char LATC    @ 0x10E;

char BORCON  @ 0x116;
char FVRCON  @ 0x117;

char APFCON  @ 0x11D;

char ANSELA  @ 0x18C;
char ANSELB  @ 0x18D;
char ANSELC  @ 0x18E;

char PMADRL  @ 0x191;
char PMADRH  @ 0x192;
char PMDATL  @ 0x193;
char PMDATH  @ 0x194;
char PMCON1  @ 0x195;
char PMCON2  @ 0x196;

char RCREG   @ 0x199;
char TXREG   @ 0x19A;
char SPBRGL  @ 0x19B;
char SPBRGH  @ 0x19C;
char RCSTA   @ 0x19D;
char TXSTA   @ 0x19E;
char BAUDCON @ 0x19F;

char WPUA    @ 0x20C;
char WPUB    @ 0x20D;

char SSPBUF @ 0x211;
char SSPADD @ 0x212;
char SSPMSK @ 0x213;
char SSPSTAT @ 0x214;
char SSPCON1 @ 0x215;
char SSPCON2 @ 0x216;
char SSPCON3 @ 0x217;

char IOCAP   @ 0x391;
char IOCAN   @ 0x392;
char IOCAF   @ 0x393;
char IOCBP   @ 0x394;
char IOCBN   @ 0x395;
char IOCBF   @ 0x396;

char PWM1DCL @ 0x611;
char PWM1DCH @ 0x612;
char PWM1CON @ 0x613;
char PWM2DCL @ 0x614;
char PWM2DCH @ 0x615;
char PWM2CON @ 0x616;

char AAD1CON0 @ 0x711;
char AAD1CON1 @ 0x712;
char AAD1CON2 @ 0x713;
char AAD1CON3 @ 0x714;
char AAD1STAT @ 0x715;
char AAD1PRE @ 0x716;
char AAD1ACQ @ 0x717;
char AAD1GRD @ 0x718;
char AAD1CAP @ 0x719;
char AAD1RES0L @ 0x71A;
char AAD1RES0H @ 0x71B;
char AAD1RES1L @ 0x71C;
char AAD1RES1H @ 0x71D;
char AAD1CH  @ 0x71E;

char AAD2CON0 @ 0x791;

char AAD2CON2 @ 0x793;
char AAD2CON3 @ 0x794;

char AAD2PRE @ 0x796;
char AAD2ACQ @ 0x797;
char AAD2GRD @ 0x798;
char AAD2CAP @ 0x799;
char AAD2RES0L @ 0x79A;
char AAD2RES0H @ 0x79B;
char AAD2RES1L @ 0x79C;
char AAD2RES1H @ 0x79D;
char AAD2CH  @ 0x79E;

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
bit  AD1IF   @ PIR1.6;
bit  TMR1GIF @ PIR1.7;

bit  BCLIF   @ PIR2.3;
bit  AD2IF   @ PIR2.6;

bit  TMR1ON  @ T1CON.0;
bit  T1SYNC_ @ T1CON.2;
bit  T1CKPS0 @ T1CON.4;
bit  T1CKPS1 @ T1CON.5;
bit  TMR1CS0 @ T1CON.6;
bit  TMR1CS1 @ T1CON.7;

bit  T1GSS   @ T1GCON.0;
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
bit  AD1IE   @ PIE1.6;
bit  TMR1GIE @ PIE1.7;

bit  BCLIE   @ PIE2.3;
bit  AD2IE   @ PIE2.6;

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
bit  HFIOFR  @ OSCSTAT.4;
bit  PLLSR   @ OSCSTAT.6;

bit  ADON    @ ADCON0.0;
bit  GO      @ ADCON0.1;
bit  CHS0    @ ADCON0.2;
bit  CHS1    @ ADCON0.3;
bit  CHS2    @ ADCON0.4;
bit  CHS3    @ ADCON0.5;
bit  CHS4    @ ADCON0.6;

bit  ADPREF0 @ ADCON1.0;
bit  ADPREF1 @ ADCON1.1;
bit  GO_ALL  @ ADCON1.2;
bit  ADFM    @ ADCON1.7;

bit  TRIGSEL0 @ ADCON2.4;
bit  TRIGSEL1 @ ADCON2.5;
bit  TRIGSEL2 @ ADCON2.6;

bit  BORRDY  @ BORCON.0;
bit  BORFS   @ BORCON.6;
bit  SBOREN  @ BORCON.7;

bit  ADFVR0  @ FVRCON.0;
bit  ADFVR1  @ FVRCON.1;
bit  TSRNG   @ FVRCON.4;
bit  TSEN    @ FVRCON.5;
bit  FVRRDY  @ FVRCON.6;
bit  FVREN   @ FVRCON.7;

bit  GRDASEL @ APFCON.0;
bit  GRDBSEL @ APFCON.1;
bit  TXCKSEL @ APFCON.2;
bit  SDSEL   @ APFCON.4;
bit  SSSEL   @ APFCON.5;
bit  SDOSEL  @ APFCON.6;
bit  RXDTSEL @ APFCON.7;

bit  RD      @ PMCON1.0;
bit  WR      @ PMCON1.1;
bit  WREN    @ PMCON1.2;
bit  WRERR   @ PMCON1.3;
bit  FREE    @ PMCON1.4;
bit  LWLO    @ PMCON1.5;
bit  CFGS    @ PMCON1.6;

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

bit  BF      @ SSPSTAT.0;
bit  UA      @ SSPSTAT.1;
bit  RW_     @ SSPSTAT.2;
bit  S       @ SSPSTAT.3;
bit  P       @ SSPSTAT.4;
bit  DA_     @ SSPSTAT.5;
bit  CKE     @ SSPSTAT.6;
bit  SMP     @ SSPSTAT.7;

bit  CKP     @ SSPCON1.4;
bit  SSPEN   @ SSPCON1.5;
bit  SSPOV   @ SSPCON1.6;
bit  WCOL    @ SSPCON1.7;

bit  SEN     @ SSPCON2.0;
bit  RSEN    @ SSPCON2.1;
bit  PEN     @ SSPCON2.2;
bit  RCEN    @ SSPCON2.3;
bit  ACKEN   @ SSPCON2.4;
bit  ACKDT   @ SSPCON2.5;
bit  ACKSTAT @ SSPCON2.6;
bit  GCEN    @ SSPCON2.7;

bit  DHEN    @ SSPCON3.0;
bit  AHEN    @ SSPCON3.1;
bit  SBCDE   @ SSPCON3.2;
bit  SDAHT   @ SSPCON3.3;
bit  BOEN    @ SSPCON3.4;
bit  SCIE    @ SSPCON3.5;
bit  PCIE    @ SSPCON3.6;
bit  ACKTIM  @ SSPCON3.7;

bit  PWM1POL @ PWM1CON.4;
bit  PWM1OUT @ PWM1CON.5;
bit  PWM1OE  @ PWM1CON.6;
bit  PWM1EN  @ PWM1CON.7;

bit  PWM2POL @ PWM2CON.4;
bit  PWM2OUT @ PWM2CON.5;
bit  PWM2OE  @ PWM2CON.6;
bit  PWM2EN  @ PWM2CON.7;

bit  AD1ON   @ AAD1CON0.0;
bit  GO1     @ AAD1CON0.1;

bit  AD1DSEN @ AAD1CON3.0;
bit  AD1IPEN @ AAD1CON3.1;
bit  AD1IPPOL @ AAD1CON3.6;
bit  AD1EPPOL @ AAD1CON3.7;

bit  AD1STG0 @ AAD1STAT.0;
bit  AD1STG1 @ AAD1STAT.1;
bit  AD1CONV @ AAD1STAT.2;
bit  AD2STG0 @ AAD1STAT.4;
bit  AD2STG1 @ AAD1STAT.5;
bit  AD2CONV @ AAD1STAT.6;

bit  GRD1POL @ AAD1GRD.5;
bit  GRD1AOE @ AAD1GRD.6;
bit  GRD1BOE @ AAD1GRD.7;

bit  AD2ON   @ AAD2CON0.0;
bit  GO2    @ AAD2CON0.1;

bit  GRD2POL @ AAD2GRD.5;
bit  GRD2AOE @ AAD2GRD.6;
bit  GRD2BOE @ AAD2GRD.7;

bit  C_SHAD  @ STATUS_SHAD.0;
bit  DC_SHAD @ STATUS_SHAD.1;
bit  Z_SHAD  @ STATUS_SHAD.2;
