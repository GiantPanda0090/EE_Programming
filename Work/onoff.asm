
; CC5X Version 3.5D, Copyright (c) B Knudsen Data
; C compiler for the PICmicro family
; ************   5. Apr 2016  13:20  *************

        processor  16F690
        radix  DEC

        __config 0xD4

PORTB       EQU   0x06
TRISB       EQU   0x86
RP0         EQU   5
RP1         EQU   6
PORTC       EQU   0x07
TRISC       EQU   0x87

        GOTO main

  ; FILE onoff.c
                        ;/* onoff.c Inbyggd Elektronik Lab1       */ 
                        ;/* B Knudsen Cc5x C-compiler - not ANSI-C */
                        ;#include "16F690.h"
                        ;#pragma config |= 0x00D4 
                        ;
                        ;void init( void );
                        ;
                        ;void main( void)
                        ;{
main
                        ;  init();
        CALL  init
                        ;  
                        ;  while(1)
                        ;    {
                        ;      if(!PORTB.6) PORTC.0 = 1; /* PORTC LED0 ON  */
m001    BCF   0x03,RP0
        BCF   0x03,RP1
        BTFSC PORTB,6
        GOTO  m002
        BSF   PORTC,0
                        ;      else PORTC.0 = 0;         /* PORTC LED0 OFF */
        GOTO  m001
m002    BCF   0x03,RP0
        BCF   0x03,RP1
        BCF   PORTC,0
                        ;    }
        GOTO  m001
                        ;}
                        ;
                        ;
                        ;/* *********************************** */
                        ;/*            FUNCTIONS                */
                        ;/* *********************************** */
                        ;
                        ;void init( void )
                        ;{
init
                        ;  TRISC.0 = 0;  /* PORTC pin 0 output */
        BSF   0x03,RP0
        BCF   0x03,RP1
        BCF   TRISC,0
                        ;  TRISB.6 = 1;  /* PORTB pin 6 input  */
        BSF   TRISB,6
                        ;  PORTC.0 = 0;  /* PORTC pin 0 "0"    */
        BCF   0x03,RP0
        BCF   PORTC,0
                        ;
                        ;  /* Later on in lab - insert "weak pullup" for RB6. */
                        ;  /* Preparation task is to find out how?            */
                        ;
                        ;}
        RETURN

        END


; *** KEY INFO ***

; 0x000C P0    7 word(s)  0 % : init
; 0x0001 P0   11 word(s)  0 % : main

; RAM usage: 0 bytes (0 local), 256 bytes free
; Maximum call level: 1
;  Codepage 0 has   19 word(s) :   0 %
;  Codepage 1 has    0 word(s) :   0 %
; Total of 19 code words (0 %)
