// HEADER FILE
#pragma chip PIC10F322, core 14, code 512, ram 0x40 : 0x7F

#if __CC5X__ < 3408
 #error CC5X version 3.4H (or later) is required to use this device
#endif

#pragma updateBank -

#define INT_lgen_style
#define INT_rambank  0

#pragma config_def 0x4

#pragma wideConstData p

/* Predefined:
  char W;
  char INDF, TMR0, PCL, STATUS, FSR;
  char OPTION;
  char PCLATH, INTCON;
  bit Carry, DC, Zero_, PD, TO, RP0, RP1, IRP;
  bit RBIF, INTF, T0IF, RBIE, INTE, T0IE, GIE;
  bit PA0, PA1;  // PCLATH
*/

#pragma char TRISA   @ 0x06
#pragma char LATA    @ 0x07
#pragma char ANSELA  @ 0x08
#pragma char WPUA    @ 0x09

#pragma char PIR1    @ 0x0C
#pragma char PIE1    @ 0x0D
#pragma char OPTION_REG @ 0x0E
#pragma char PCON    @ 0x0F
#pragma char OSCCON  @ 0x10
#pragma char TMR2    @ 0x11
#pragma char PR2     @ 0x12
#pragma char T2CON   @ 0x13
#pragma char PWM1DCL @ 0x14
#pragma char PWM1DCH @ 0x15
#pragma char PWM1CON @ 0x16
#pragma char PWM2DCL @ 0x17
#pragma char PWM2DCH @ 0x18
#pragma char PWM2CON @ 0x19
#pragma char IOCAP   @ 0x1A
#pragma char IOCAN   @ 0x1B
#pragma char IOCAF   @ 0x1C
#pragma char FVRCON  @ 0x1D
#pragma char ADRES   @ 0x1E
#pragma char ADCON   @ 0x1F
#pragma char PMADRL  @ 0x20
#pragma char PMADRH  @ 0x21
#pragma char PMDATL  @ 0x22
#pragma char PMDATH  @ 0x23
#pragma char PMCON1  @ 0x24
#pragma char PMCON2  @ 0x25
#pragma char CLKRCON @ 0x26
#pragma char NCO1ACCL @ 0x27
#pragma char NCO1ACCH @ 0x28
#pragma char NCO1ACCU @ 0x29
#pragma char NCO1INCL @ 0x2A
#pragma char NCO1INCH @ 0x2B

#pragma char NCO1CON @ 0x2D
#pragma char NCO1CLK @ 0x2E

#pragma char WDTCON  @ 0x30
#pragma char CLC1CON @ 0x31
#pragma char CLC1SEL0 @ 0x32
#pragma char CLC1SEL1 @ 0x33
#pragma char CLC1POL @ 0x34
#pragma char CLC1GLS0 @ 0x35
#pragma char CLC1GLS1 @ 0x36
#pragma char CLC1GLS2 @ 0x37
#pragma char CLC1GLS3 @ 0x38
#pragma char CWG1CON0 @ 0x39
#pragma char CWG1CON1 @ 0x3A
#pragma char CWG1CON2 @ 0x3B
#pragma char CWG1DBR @ 0x3C
#pragma char CWG1DBF @ 0x3D
#pragma char VREGCON @ 0x3E
#pragma char BORCON  @ 0x3F

#pragma bit  PEIE    @ INTCON.6

#pragma bit  TMR2IF  @ PIR1.1
#pragma bit  CLC1IF  @ PIR1.3
#pragma bit  NCO1IF  @ PIR1.4
#pragma bit  ADIF    @ PIR1.6

#pragma bit  TMR2IE  @ PIE1.1
#pragma bit  CLC1IE  @ PIE1.3
#pragma bit  NCO1IE  @ PIE1.4
#pragma bit  ADIE    @ PIE1.6

#pragma bit  PS0     @ /*OPTION_REG*/0x0E.0
#pragma bit  PS1     @ /*OPTION_REG*/0x0E.1
#pragma bit  PS2     @ /*OPTION_REG*/0x0E.2
#pragma bit  PSA     @ /*OPTION_REG*/0x0E.3
#pragma bit  T0SE    @ /*OPTION_REG*/0x0E.4
#pragma bit  RTE     @ /*OPTION_REG*/0x0E.4
#pragma bit  T0CS    @ /*OPTION_REG*/0x0E.5
#pragma bit  RTS     @ /*OPTION_REG*/0x0E.5
#pragma bit  INTEDG  @ /*OPTION_REG*/0x0E.6
#pragma bit  RBPU_   @ /*OPTION_REG*/0x0E.7
#pragma bit  WPUEN_  @ /*OPTION_REG*/0x0E.7

#pragma bit  BOR_    @ PCON.0
#pragma bit  POR_    @ PCON.1

#pragma bit  HFIOFS  @ OSCCON.0
#pragma bit  LFIOFR  @ OSCCON.1
#pragma bit  HFIOFR  @ OSCCON.3

#pragma bit  TMR2ON  @ T2CON.2

#pragma bit  PWM1DCL0 @ PWM1DCL.6
#pragma bit  PWM1DCL1 @ PWM1DCL.7

#pragma bit  PWM1POL @ PWM1CON.4
#pragma bit  PWM1OUT @ PWM1CON.5
#pragma bit  PWM1OE  @ PWM1CON.6
#pragma bit  PWM1EN  @ PWM1CON.7

#pragma bit  PWM2DCL0 @ PWM2DCL.6
#pragma bit  PWM2DCL1 @ PWM2DCL.7

#pragma bit  PWM2POL @ PWM2CON.4
#pragma bit  PWM2OUT @ PWM2CON.5
#pragma bit  PWM2OE  @ PWM2CON.6
#pragma bit  PWM2EN  @ PWM2CON.7

#pragma bit  ADFVR0  @ FVRCON.0
#pragma bit  ADFVR1  @ FVRCON.1
#pragma bit  TSRNG   @ FVRCON.4
#pragma bit  TSEN    @ FVRCON.5
#pragma bit  FVRRDY  @ FVRCON.6
#pragma bit  FVREN   @ FVRCON.7

#pragma bit  ADON    @ ADCON.0
#pragma bit  GO      @ ADCON.1
#pragma bit  CHS0    @ ADCON.2
#pragma bit  CHS1    @ ADCON.3
#pragma bit  CHS2    @ ADCON.4
#pragma bit  ADCS0   @ ADCON.5
#pragma bit  ADCS1   @ ADCON.6
#pragma bit  ADCS2   @ ADCON.7

#pragma bit  PMADR8  @ PMADRH.0

#pragma bit  RD      @ PMCON1.0
#pragma bit  WR      @ PMCON1.1
#pragma bit  WREN    @ PMCON1.2
#pragma bit  WRERR   @ PMCON1.3
#pragma bit  FREE    @ PMCON1.4
#pragma bit  LWLO    @ PMCON1.5
#pragma bit  CFGS    @ PMCON1.6

#pragma bit  CLKROE  @ CLKRCON.6

#pragma bit  N1PFM   @ NCO1CON.0
#pragma bit  N1POL   @ NCO1CON.4
#pragma bit  N1OUT   @ NCO1CON.5
#pragma bit  N1OE    @ NCO1CON.6
#pragma bit  N1EN    @ NCO1CON.7

#pragma bit  SWDTEN  @ WDTCON.0

#pragma bit  LC1INTN @ CLC1CON.3
#pragma bit  LC1INTP @ CLC1CON.4
#pragma bit  LC1OUT  @ CLC1CON.5
#pragma bit  LC1OE   @ CLC1CON.6
#pragma bit  LC1EN   @ CLC1CON.7

#pragma bit  LC1G1POL @ CLC1POL.0
#pragma bit  LC1G2POL @ CLC1POL.1
#pragma bit  LC1G3POL @ CLC1POL.2
#pragma bit  LC1G4POL @ CLC1POL.3
#pragma bit  LC1POL  @ CLC1POL.7

#pragma bit  LC1G1D1N @ CLC1GLS0.0
#pragma bit  LC1G1D1T @ CLC1GLS0.1
#pragma bit  LC1G1D2N @ CLC1GLS0.2
#pragma bit  LC1G1D2T @ CLC1GLS0.3
#pragma bit  LC1G1D3N @ CLC1GLS0.4
#pragma bit  LC1G1D3T @ CLC1GLS0.5
#pragma bit  LC1G1D4N @ CLC1GLS0.6
#pragma bit  LC1G1D4T @ CLC1GLS0.7

#pragma bit  LC1G2D1N @ CLC1GLS1.0
#pragma bit  LC1G2D1T @ CLC1GLS1.1
#pragma bit  LC1G2D2N @ CLC1GLS1.2
#pragma bit  LC1G2D2T @ CLC1GLS1.3
#pragma bit  LC1G2D3N @ CLC1GLS1.4
#pragma bit  LC1G2D3T @ CLC1GLS1.5
#pragma bit  LC1G2D4N @ CLC1GLS1.6
#pragma bit  LC1G2D4T @ CLC1GLS1.7

#pragma bit  LC1G3D1N @ CLC1GLS2.0
#pragma bit  LC1G3D1T @ CLC1GLS2.1
#pragma bit  LC1G3D2N @ CLC1GLS2.2
#pragma bit  LC1G3D2T @ CLC1GLS2.3
#pragma bit  LC1G3D3N @ CLC1GLS2.4
#pragma bit  LC1G3D3T @ CLC1GLS2.5
#pragma bit  LC1G3D4N @ CLC1GLS2.6
#pragma bit  LC1G3D4T @ CLC1GLS2.7

#pragma bit  LC1G4D1N @ CLC1GLS3.0
#pragma bit  LC1G4D1T @ CLC1GLS3.1
#pragma bit  LC1G4D2N @ CLC1GLS3.2
#pragma bit  LC1G4D2T @ CLC1GLS3.3
#pragma bit  LC1G4D3N @ CLC1GLS3.4
#pragma bit  LC1G4D3T @ CLC1GLS3.5
#pragma bit  LC1G4D4N @ CLC1GLS3.6
#pragma bit  LC1G4D4T @ CLC1GLS3.7

#pragma bit  G1CS0   @ CWG1CON0.0
#pragma bit  G1POLA  @ CWG1CON0.3
#pragma bit  G1POLB  @ CWG1CON0.4
#pragma bit  G1OEA   @ CWG1CON0.5
#pragma bit  G1OEB   @ CWG1CON0.6
#pragma bit  G1EN    @ CWG1CON0.7

#pragma bit  G1IS0   @ CWG1CON1.0
#pragma bit  G1IS1   @ CWG1CON1.1
#pragma bit  G1ASDLA0 @ CWG1CON1.4
#pragma bit  G1ASDLA1 @ CWG1CON1.5
#pragma bit  G1ASDLB0 @ CWG1CON1.6
#pragma bit  G1ASDLB1 @ CWG1CON1.7

#pragma bit  G1ASDFLT @ CWG1CON2.0
#pragma bit  G1ASDCLC1 @ CWG1CON2.1
#pragma bit  G1ARSEN @ CWG1CON2.6
#pragma bit  G1ASE   @ CWG1CON2.7

#pragma bit  VREGPM1 @ VREGCON.1

#pragma bit  BORRDY  @ BORCON.0
#pragma bit  BORFS   @ BORCON.6
#pragma bit  SBOREN  @ BORCON.7
