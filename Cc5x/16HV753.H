// HEADER FILE
#pragma chip PIC16HV753, core 14, code 2048, ram 32 : 0x1BF
#pragma ramdef  0x70 : 0x7F mapped_into_all_banks

#define INT_lgen_style
#define INT_rambank  0   /* interrupt variables in bank 0 */

#pragma config_def 0x0224

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
#pragma char IOCAF   @ 0x08
#pragma char IOCCF   @ 0x09

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

#pragma char TRISC   @ 0x87
#pragma char IOCAP   @ 0x88
#pragma char IOCCP   @ 0x89

#pragma char PIE1    @ 0x8C
#pragma char PIE2    @ 0x8D

#pragma char OSCCON  @ 0x8F
#pragma char FVR1CON0 @ 0x90
#pragma char DAC1CON0 @ 0x91
#pragma char DAC1REFL @ 0x92
#pragma char DAC1REFH @ 0x93

#pragma char OPA1CON0 @ 0x96

#pragma char CM2CON0 @ 0x9B
#pragma char CM2CON1 @ 0x9C
#pragma char CM1CON0 @ 0x9D
#pragma char CM1CON1 @ 0x9E
#pragma char CMOUT   @ 0x9F

#pragma char LATA    @ 0x105

#pragma char LATC    @ 0x107
#pragma char IOCAN   @ 0x108
#pragma char IOCCN   @ 0x109

#pragma char WPUA    @ 0x10C
#pragma char WPUC    @ 0x10D
#pragma char SLRCONC @ 0x10E
#pragma char PCON    @ 0x10F
#pragma char TMR2    @ 0x110
#pragma char PR2     @ 0x111
#pragma char T2CON   @ 0x112
#pragma char HLTMR1  @ 0x113
#pragma char HLTPR1  @ 0x114
#pragma char HLT1CON0 @ 0x115
#pragma char HLT1CON1 @ 0x116
#pragma char HLTMR2  @ 0x117
#pragma char HLTPR2  @ 0x118
#pragma char HLT2CON0 @ 0x119
#pragma char HLT2CON1 @ 0x11A

#pragma char SLPCCON0 @ 0x11E
#pragma char SLPCCON1 @ 0x11F

#pragma char ANSELA  @ 0x185

#pragma char ANSELC  @ 0x187
#pragma char APFCON  @ 0x188
#pragma char OSCTUNE @ 0x189

#pragma char PMCON1  @ 0x18C
#pragma char PMCON2  @ 0x18D
#pragma char PMADRL  @ 0x18E
#pragma char PMADRH  @ 0x18F
#pragma char PMDATL  @ 0x190
#pragma char PMDATH  @ 0x191
#pragma char COG1PHR @ 0x192
#pragma char COG1PHF @ 0x193
#pragma char COG1BKR @ 0x194
#pragma char COG1BKF @ 0x195
#pragma char COG1DBR @ 0x196
#pragma char COG1DBF @ 0x197
#pragma char COG1CON0 @ 0x198
#pragma char COG1CON1 @ 0x199
#pragma char COG1RIS @ 0x19A
#pragma char COG1RSIM @ 0x19B
#pragma char COG1FIS @ 0x19C
#pragma char COG1FSIM @ 0x19D
#pragma char COG1ASD0 @ 0x19E
#pragma char COG1ASD1 @ 0x19F

#pragma bit  PEIE    @ INTCON.6

#pragma bit  TMR1IF  @ PIR1.0
#pragma bit  TMR2IF  @ PIR1.1
#pragma bit  HLTMR1IF @ PIR1.2
#pragma bit  HLTMR2IF @ PIR1.3
#pragma bit  ADIF    @ PIR1.6
#pragma bit  TMR1GIF @ PIR1.7

#pragma bit  CCP1IF  @ PIR2.0
#pragma bit  COG1IF  @ PIR2.2
#pragma bit  C1IF    @ PIR2.4
#pragma bit  C2IF    @ PIR2.5

#pragma bit  TMR1ON  @ T1CON.0
#pragma bit  T1SYNC_ @ T1CON.2
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

#pragma bit  ADON    @ ADCON0.0
#pragma bit  GO      @ ADCON0.1
#pragma bit  CHS0    @ ADCON0.2
#pragma bit  CHS1    @ ADCON0.3
#pragma bit  CHS2    @ ADCON0.4
#pragma bit  CHS3    @ ADCON0.5
#pragma bit  ADFM    @ ADCON0.7

#pragma bit  ADPREF1 @ ADCON1.0
#pragma bit  ADCS0   @ ADCON1.4
#pragma bit  ADCS1   @ ADCON1.5
#pragma bit  ADCS2   @ ADCON1.6

#pragma bit  TMR1IE  @ PIE1.0
#pragma bit  TMR2IE  @ PIE1.1
#pragma bit  HLTMR1IE @ PIE1.2
#pragma bit  HLTMR2IE @ PIE1.3
#pragma bit  ADIE    @ PIE1.6
#pragma bit  TMR1GIE @ PIE1.7

#pragma bit  CCP1IE  @ PIE2.0
#pragma bit  COG1IE  @ PIE2.2
#pragma bit  C1IE    @ PIE2.4
#pragma bit  C2IE    @ PIE2.5

#pragma bit  LTS     @ OSCCON.1
#pragma bit  HTS     @ OSCCON.2

#pragma bit  FVRBUFEN @ FVR1CON0.0
#pragma bit  FVRBUFSS0 @ FVR1CON0.3
#pragma bit  FVRBUFSS1 @ FVR1CON0.4
#pragma bit  FVROE   @ FVR1CON0.5
#pragma bit  FVRRDY  @ FVR1CON0.6
#pragma bit  FVREN   @ FVR1CON0.7

#pragma bit  DACPSS0 @ DAC1CON0.2
#pragma bit  DACPSS1 @ DAC1CON0.3
#pragma bit  DACOE   @ DAC1CON0.5
#pragma bit  DACFM   @ DAC1CON0.6
#pragma bit  DACEN   @ DAC1CON0.7

#pragma bit  OPA1PCH0 @ OPA1CON0.0
#pragma bit  OPA1PCH1 @ OPA1CON0.1
#pragma bit  OPA1NCH0 @ OPA1CON0.2
#pragma bit  OPA1NCH1 @ OPA1CON0.3
#pragma bit  OPA1UGM  @ OPA1CON0.4
#pragma bit  OPA1EN  @ OPA1CON0.7

#pragma bit  C2SYNC  @ CM2CON0.0
#pragma bit  C2HYS   @ CM2CON0.1
#pragma bit  C2SP    @ CM2CON0.2
#pragma bit  C2ZLF   @ CM2CON0.3
#pragma bit  C2POL   @ CM2CON0.4
#pragma bit  C2OE    @ CM2CON0.5
#pragma bit  C2OUT   @ CM2CON0.6
#pragma bit  C2ON    @ CM2CON0.7

#pragma bit  C2NCH0  @ CM2CON1.0
#pragma bit  C2NCH1  @ CM2CON1.1
#pragma bit  C2NCH2  @ CM2CON1.2
#pragma bit  C2PCH0  @ CM2CON1.3
#pragma bit  C2PCH1  @ CM2CON1.4
#pragma bit  C2PCH2  @ CM2CON1.5
#pragma bit  C2INTN  @ CM2CON1.6
#pragma bit  C2INTP  @ CM2CON1.7

#pragma bit  C1SYNC  @ CM1CON0.0
#pragma bit  C1HYS   @ CM1CON0.1
#pragma bit  C1SP    @ CM1CON0.2
#pragma bit  C1ZLF   @ CM1CON0.3
#pragma bit  C1POL   @ CM1CON0.4
#pragma bit  C1OE    @ CM1CON0.5
#pragma bit  C1OUT   @ CM1CON0.6
#pragma bit  C1ON    @ CM1CON0.7

#pragma bit  C1NCH0  @ CM1CON1.0
#pragma bit  C1NCH1  @ CM1CON1.1
#pragma bit  C1NCH2  @ CM1CON1.2
#pragma bit  C1PCH0  @ CM1CON1.3
#pragma bit  C1PCH1  @ CM1CON1.4
#pragma bit  C1PCH2  @ CM1CON1.5
#pragma bit  C1INTN  @ CM1CON1.6
#pragma bit  C1INTP  @ CM1CON1.7

#pragma bit  MCOUT1  @ CMOUT.0
#pragma bit  MCOUT2  @ CMOUT.1

#pragma bit  SLRC4   @ SLRCONC.4
#pragma bit  SLRC5   @ SLRCONC.5

#pragma bit  BOR_    @ PCON.0
#pragma bit  POR_    @ PCON.1

#pragma bit  TMR2ON  @ T2CON.2

#pragma bit  H1CKPS0 @ HLT1CON0.0
#pragma bit  H1CKPS1 @ HLT1CON0.1
#pragma bit  H1ON    @ HLT1CON0.2

#pragma bit  H1REREN @ HLT1CON1.0
#pragma bit  H1FEREN @ HLT1CON1.1
#pragma bit  H1ERS0  @ HLT1CON1.2
#pragma bit  H1ERS1  @ HLT1CON1.3
#pragma bit  H1ERS2  @ HLT1CON1.4
#pragma bit  H1RES   @ HLT1CON1.6
#pragma bit  H1FES   @ HLT1CON1.7

#pragma bit  H2CKPS0 @ HLT2CON0.0
#pragma bit  H2CKPS1 @ HLT2CON0.1
#pragma bit  H2ON    @ HLT2CON0.2

#pragma bit  H2REREN @ HLT2CON1.0
#pragma bit  H2FEREN @ HLT2CON1.1
#pragma bit  H2ERS0  @ HLT2CON1.2
#pragma bit  H2ERS1  @ HLT2CON1.3
#pragma bit  H2ERS2  @ HLT2CON1.4
#pragma bit  H2RES   @ HLT2CON1.6
#pragma bit  H2FES   @ HLT2CON1.7

#pragma bit  SC1INS  @ SLPCCON0.0
#pragma bit  SC1TSS0 @ SLPCCON0.2
#pragma bit  SC1TSS1 @ SLPCCON0.3
#pragma bit  SC1POL  @ SLPCCON0.4
#pragma bit  SC1EN   @ SLPCCON0.7

#pragma bit  SC1RNG  @ SLPCCON1.4

#pragma bit  T1GSEL  @ APFCON.4

#pragma bit  RD      @ PMCON1.0
#pragma bit  WR      @ PMCON1.1
#pragma bit  WREN    @ PMCON1.2

#pragma bit  G1MD    @ COG1CON0.0
#pragma bit  G1LD    @ COG1CON0.2
#pragma bit  G1POL0  @ COG1CON0.3
#pragma bit  G1POL1  @ COG1CON0.4
#pragma bit  G1OE0   @ COG1CON0.5
#pragma bit  G1OE1   @ COG1CON0.6
#pragma bit  G1EN    @ COG1CON0.7

#pragma bit  G1CS0   @ COG1CON1.0
#pragma bit  G1CS1   @ COG1CON1.1
#pragma bit  G1FDBTS @ COG1CON1.6
#pragma bit  G1RDBTS @ COG1CON1.7

#pragma bit  G1ASD0L0 @ COG1ASD0.2
#pragma bit  G1ASD0L1 @ COG1ASD0.3
#pragma bit  G1ASD1L0 @ COG1ASD0.4
#pragma bit  G1ASD1L1 @ COG1ASD0.5
#pragma bit  C1ARSEN @ COG1ASD0.6
#pragma bit  C1ASDE  @ COG1ASD0.7

#pragma bit  G1ASDSFLT @ COG1ASD1.0
#pragma bit  G1ASDSC1 @ COG1ASD1.1
#pragma bit  G1ASDSC2 @ COG1ASD1.2
#pragma bit  G1ASDSHLT1 @ COG1ASD1.3
#pragma bit  G1ASDSHLT2 @ COG1ASD1.4
