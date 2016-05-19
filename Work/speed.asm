
; CC5X Version 3.4H, Copyright (c) B Knudsen Data
; C compiler for the PICmicro family
; ************  12. May 2016  10:32  *************

	processor  16F690
	radix  DEC

	__config 0xD4

Carry       EQU   0
RP0         EQU   5
RP1         EQU   6
T2CON       EQU   0x12
CCPR1L      EQU   0x15
CCP1CON     EQU   0x17
ADRESH      EQU   0x1E
ADCON0      EQU   0x1F
TRISC       EQU   0x87
PR2         EQU   0x92
ADCON1      EQU   0x9F
ANSEL       EQU   0x11E
ANSELH      EQU   0x11F
GO          EQU   1
Duty        EQU   0x20

	GOTO main

  ; FILE speed.c
			;/* speed.c  motor speed from pot   */
			;
			;/* B Knudsen Cc5x C-compiler - not ANSI-C */
			;#include "16f690.h"
			;#pragma config |= 0x00D4
			;
			;void main(void)
			;{
main
			;  unsigned int Duty;
			;  TRISC.7  = 1; /* RC7 AN9 Pot input         */
	BSF   0x03,RP0
	BCF   0x03,RP1
	BSF   TRISC,7
			;  ANSELH.1 = 1; /* AN9 analog input          */
	BCF   0x03,RP0
	BSF   0x03,RP1
	BSF   ANSELH,1
			;  TRISC.4  = 0; /* RC4 P1B PWM+  output      */
	BSF   0x03,RP0
	BCF   0x03,RP1
	BCF   TRISC,4
			;  ANSEL.4  = 0; /* RC4 digital               */
	BCF   0x03,RP0
	BSF   0x03,RP1
	BCF   ANSEL,4
			;  TRISC.2  = 0; /* RC2 P1D PWM-  output      */
	BSF   0x03,RP0
	BCF   0x03,RP1
	BCF   TRISC,2
			;  ANSEL.2  = 0; /* RC2 digital               */
	BCF   0x03,RP0
	BSF   0x03,RP1
	BCF   ANSEL,2
			;
			;  /* AD setup */ 
			; 
			;  ADCON1 = 0b0.101.0000; /* AD conversion clock 'fosc/16' */
	MOVLW 80
	BSF   0x03,RP0
	BCF   0x03,RP1
	MOVWF ADCON1
			;  /* 
			;     0.x.xxxx.x.x  ADRESH:ADRESL is 10 bit left justified
			;     x.0.xxxx.x.x  Vref is Vdd
			;     x.x.1001.x.x  Channel 9 (AN9/RC7)
			;     x.x.xxxx.0.x  Go/!Done start later
			;     x.x.xxxx.x.1  Enable AD-converter
			;  */
			;  ADCON0 = 0b0.0.1001.0.1; 
	MOVLW 37
	BCF   0x03,RP0
	MOVWF ADCON0
			;
			;  /* Setup TIMER2 */
			;  /*
			;  0.xxxx.x.xx  - unimplemented
			;  x.0000.x.xx  Postscaler 1:1 (not used)
			;  x.xxxx.1.xx  TMR2 is on
			;  x.xxxx.x.00  Prescaler 1 (as fast as possible)
			;  */
			;  T2CON = 0b0.0000.1.01;   
	MOVLW 5
	MOVWF T2CON
			;
			;  /* Setup CCP1 PWM-mode  */ 
			;  /*
			;  01.xx.xxxx  PWM Full bridge forward
			;  xx.00.xxxx  PWM DutyCycle Two LSB not used
			;  xx.xx.1100  1100 Full bridge with not inverted outputs
			;  */
			;  CCP1CON = 0b01.00.1100 ;               
	MOVLW 76
	MOVWF CCP1CON
			;
			;  PR2 = 255; /* full 8 bit Duty */
	MOVLW 255
	BSF   0x03,RP0
	MOVWF PR2
			;
			;  while(1)
			;  {
			;    GO=1;          /* start AD                                       */
m001	BCF   0x03,RP0
	BCF   0x03,RP1
	BSF   0x1F,GO
			;    while(GO);     /* wait for done                                  */
m002	BCF   0x03,RP0
	BCF   0x03,RP1
	BTFSC 0x1F,GO
	GOTO  m002
			;    Duty = ADRESH; /* only using the 8 MSB of ADRES (=ADRESH)        */
	BCF   0x03,RP0
	BCF   0x03,RP1
	MOVF  ADRESH,W
	MOVWF Duty
			;
			;      /* make changes when pot is used for two directions! */
			;      if(Duty < 128)  
	MOVLW 128
	SUBWF Duty,W
	BTFSC 0x03,Carry
	GOTO  m003
			;	     {
			;           /* set direction reverse */
			;		     
			;           Duty = 127- Duty; 
	MOVF  Duty,W
	SUBLW 127
	MOVWF Duty
			;		   /* make change to reverse code */
			;		   CCP1CON = 0b11.00.1100 ; 
	MOVLW 204
	MOVWF CCP1CON
			;		 }
			;	  else 
	GOTO  m004
			;	    {
			;          /* set direction forward */	
			;		   Duty = Duty-128; 
m003	MOVLW 128
	BCF   0x03,RP0
	BCF   0x03,RP1
	SUBWF Duty,1
			;		   /* make change to forward code */
			;	    CCP1CON = 0b01.00.1100 ; 
	MOVLW 76
	MOVWF CCP1CON
			;		}
			;     Duty *= 2;  /* you need to rescale when pot is used for two directions! */
m004	BCF   0x03,Carry
	BCF   0x03,RP0
	BCF   0x03,RP1
	RLF   Duty,1
			;     CCPR1L = (unsigned int) Duty;  /* update PWM-value  */
	MOVF  Duty,W
	MOVWF CCPR1L
			;  }
	GOTO  m001

	END


; *** KEY INFO ***

; 0x0001 P0   66 word(s)  3 % : main

; RAM usage: 1 bytes (1 local), 255 bytes free
; Maximum call level: 0
;  Codepage 0 has   67 word(s) :   3 %
;  Codepage 1 has    0 word(s) :   0 %
; Total of 67 code words (1 %)
