
; CC5X Version 3.5D, Copyright (c) B Knudsen Data
; C compiler for the PICmicro family
; ************  15. Apr 2016  14:54  *************

        processor  16F690
        radix  DEC

        __config 0xD4

TMR0        EQU   0x01
PORTA       EQU   0x05
TRISA       EQU   0x85
TRISB       EQU   0x86
Carry       EQU   0
Zero_       EQU   2
RP0         EQU   5
RP1         EQU   6
OPTION_REG  EQU   0x81
PORTC       EQU   0x07
T2CON       EQU   0x12
CCPR1L      EQU   0x15
CCP1CON     EQU   0x17
ADCON0      EQU   0x1F
TRISC       EQU   0x87
PR2         EQU   0x92
ADCON1      EQU   0x9F
ANSEL       EQU   0x11E
ch          EQU   0x7F
bitCount    EQU   0x7F
ti          EQU   0x7F
string      EQU   0x7F
variable    EQU   0x7F
i           EQU   0x7F
k           EQU   0x7F
m           EQU   0x7F
a           EQU   0x7F
b           EQU   0x7F
C1cnt       EQU   0x7F
C2tmp       EQU   0x7F
C3rem       EQU   0x7F
C4cnt       EQU   0x7F
C5tmp       EQU   0x7F
C6cnt       EQU   0x7F
C7tmp       EQU   0x7F
C8rem       EQU   0x7F
C9cnt       EQU   0x7F
C10tmp      EQU   0x7F
n           EQU   0x26
i_2         EQU   0x27

        GOTO main

  ; FILE duty_value.c
                        ;/* duty_value.c PIC 16F690 reads PWM-duty from POT           */
                        ;/* prints DutyCycle in percent with UART tool on key-press   */
                        ;
                        ;/* B Knudsen Cc5x C-compiler - not ANSI-C */
                        ;#include "16F690.h"
                        ;#pragma config |= 0x00D4 
                        ;
                        ;void initserial( void );
                        ;void ADinit( void );
                        ;void PWMinit( void );
                        ;void putchar( char );
                        ;void printf(const char *string, char variable);
                        ;void delay10( char );
                        ;
                        ;
                        ;void main(void)
                        ;{
_const1
        RETLW 0
main
                        ;  char advalue, duty;
                        ;  unsigned long tmp1,tmp2;
                        ;  TRISC.4 = 0; // lightdiode at RC4 is output
        BSF   0x03,RP0
        BCF   0x03,RP1
        BCF   TRISC,4
                        ;  PORTC.4 = 0; // no light
        BCF   0x03,RP0
        BCF   PORTC,4
                        ;  TRISB.6 = 1; // switch SW is input
        BSF   0x03,RP0
        BSF   TRISB,6
                        ;
                        ;  initserial();
        CALL  initserial
                        ;  ADinit();
        CALL  ADinit
                        ;  PWMinit();
        CALL  PWMinit
                        ;  
                        ;  delay10(100); 
        MOVLW 100
        CALL  delay10
                        ;  // Header text
                        ;
                        ;
                        ;  while(1)
                        ;   {
                        ;      
                        ;PORTC.5=0;
m001    BCF   0x03,RP0
        BCF   0x03,RP1
        BCF   PORTC,5
                        ;	  
                        ;      
                        ;   }
        GOTO  m001
                        ;}
                        ;
                        ;
                        ;
                        ;
                        ;/* *********************************** */
                        ;/*            FUNCTIONS                */
                        ;/* *********************************** */
                        ;
                        ;
                        ;/* **** ADconverter function ************** */
                        ;
                        ;void ADinit( void )
                        ;{
ADinit
                        ;  // AD setup AN6 at RC2 pin 14
                        ;  TRISC.2 = 1;  // AN6 input
        BSF   0x03,RP0
        BCF   0x03,RP1
        BSF   TRISC,2
                        ;  ANSEL.6 = 1;  /* RC2 AN6 analog configurated        */  
        BCF   0x03,RP0
        BSF   0x03,RP1
        BSF   ANSEL,6
                        ;  ADCON1 = 0b0.101.0000;   /* AD conversion clock 'fosc/16' */
        MOVLW 80
        BSF   0x03,RP0
        BCF   0x03,RP1
        MOVWF ADCON1
                        ;  ADCON0 = 0b0.0.0110.0.1; /* AD-channel 6 pin 14           */ 
        MOVLW 25
        BCF   0x03,RP0
        MOVWF ADCON0
                        ;}
        RETURN
                        ;
                        ;/* **** CCP PWM function ************** */
                        ;
                        ;void PWMinit( void )
                        ;{
PWMinit
                        ;   TRISC.5 = 0;              /* CCP1 output      */
        BSF   0x03,RP0
        BCF   0x03,RP1
        BCF   TRISC,5
                        ;   T2CON   = 0b00000.1.00;   /* prescale 1:1     */
        MOVLW 4
        BCF   0x03,RP0
        MOVWF T2CON
                        ;   CCP1CON = 0b00.00.1100;   /* PWM-mode         */
        MOVLW 12
        MOVWF CCP1CON
                        ;   PR2     = 255;            /* max value        */
        MOVLW 255
        BSF   0x03,RP0
        MOVWF PR2
                        ;   CCPR1L  = 128;            /* Duty 50% initial */
        MOVLW 128
        BCF   0x03,RP0
        MOVWF CCPR1L
                        ;}
        RETURN
                        ;
                        ;
                        ;/* **** bitbanging serial communication **** */
                        ;
                        ;void initserial( void )  /* initialise PIC16F690 bbCom */
                        ;{
initserial
                        ;   ANSEL.0 = 0; // No AD on RA0
        BCF   0x03,RP0
        BSF   0x03,RP1
        BCF   ANSEL,0
                        ;   ANSEL.1 = 0; // No AD on RA1
        BCF   ANSEL,1
                        ;   PORTA.0 = 1; // marking line
        BCF   0x03,RP1
        BSF   PORTA,0
                        ;   TRISA.0 = 0; // output to PK2 UART-tool
        BSF   0x03,RP0
        BCF   TRISA,0
                        ;   TRISA.1 = 1; // input from PK2 UART-tool
        BSF   TRISA,1
                        ;   return;      
        RETURN
                        ;}
                        ;
                        ;void putchar( char ch )  // sends one char bitbanging
                        ;{
putchar
        MOVWF ch
                        ;  char bitCount, ti;
                        ;  PORTA.0 = 0; // set startbit
        BCF   0x03,RP0
        BCF   0x03,RP1
        BCF   PORTA,0
                        ;  for ( bitCount = 10; bitCount > 0 ; bitCount-- )
        MOVLW 10
        MOVWF bitCount
m002    MOVF  bitCount,1
        BTFSC 0x03,Zero_
        GOTO  m004
                        ;   {
                        ;     // delay one bit 104 usec at 4 MHz
                        ;     // 5+18*5-1+1+9=104 without optimization 
                        ;     ti = 18; do ; while( --ti > 0); nop(); 
        MOVLW 18
        MOVWF ti
m003    DECFSZ ti,1
        GOTO  m003
        NOP  
                        ;     Carry = 1;     // stopbit
        BSF   0x03,Carry
                        ;     ch = rr( ch ); // Rotate Right through Carry
        RRF   ch,1
                        ;     PORTA.0 = Carry;
        BCF   0x03,RP0
        BCF   0x03,RP1
        BTFSS 0x03,Carry
        BCF   PORTA,0
        BTFSC 0x03,Carry
        BSF   PORTA,0
                        ;   }
        DECF  bitCount,1
        GOTO  m002
                        ;  return;
m004    RETURN
                        ;}
                        ;
                        ;void printf(const char *string, char variable)
                        ;{
printf
        MOVWF variable
                        ;  char i, k, m, a, b;
                        ;  for(i = 0 ; ; i++)
        CLRF  i
                        ;   {
                        ;     k = string[i];
m005    MOVF  i,W
        ADDWF string,W
        CALL  _const1
        MOVWF k
                        ;     if( k == '\0') break;   // at end of string
        MOVF  k,1
        BTFSC 0x03,Zero_
        GOTO  m027
                        ;     if( k == '%')           // insert variable in string
        MOVF  k,W
        XORLW 37
        BTFSS 0x03,Zero_
        GOTO  m025
                        ;      {
                        ;        i++;
        INCF  i,1
                        ;        k = string[i];
        MOVF  i,W
        ADDWF string,W
        CALL  _const1
        MOVWF k
                        ;        switch(k)
        MOVF  k,W
        XORLW 100
        BTFSC 0x03,Zero_
        GOTO  m006
        XORLW 17
        BTFSC 0x03,Zero_
        GOTO  m009
        XORLW 23
        BTFSC 0x03,Zero_
        GOTO  m018
        XORLW 1
        BTFSC 0x03,Zero_
        GOTO  m022
        XORLW 70
        BTFSC 0x03,Zero_
        GOTO  m023
        GOTO  m024
                        ;         {
                        ;           case 'd':         // %d  signed 8bit
                        ;             if( variable.7 ==1) putchar('-');
m006    BTFSS variable,7
        GOTO  m007
        MOVLW 45
        CALL  putchar
                        ;             else putchar(' ');
        GOTO  m008
m007    MOVLW 32
        CALL  putchar
                        ;             if( variable > 127) variable = -variable;  // no break!
m008    MOVLW 128
        SUBWF variable,W
        BTFSS 0x03,Carry
        GOTO  m009
        COMF  variable,1
        INCF  variable,1
                        ;           case 'u':         // %u unsigned 8bit
                        ;             a = variable/100;
m009    MOVF  variable,W
        MOVWF C2tmp
        CLRF  C3rem
        MOVLW 8
        MOVWF C1cnt
m010    RLF   C2tmp,1
        RLF   C3rem,1
        MOVLW 100
        SUBWF C3rem,W
        BTFSS 0x03,Carry
        GOTO  m011
        MOVLW 100
        SUBWF C3rem,1
        BSF   0x03,Carry
m011    RLF   a,1
        DECFSZ C1cnt,1
        GOTO  m010
                        ;             putchar('0'+a); // print 100's
        MOVLW 48
        ADDWF a,W
        CALL  putchar
                        ;             b = variable%100;
        MOVF  variable,W
        MOVWF C5tmp
        CLRF  b
        MOVLW 8
        MOVWF C4cnt
m012    RLF   C5tmp,1
        RLF   b,1
        MOVLW 100
        SUBWF b,W
        BTFSS 0x03,Carry
        GOTO  m013
        MOVLW 100
        SUBWF b,1
m013    DECFSZ C4cnt,1
        GOTO  m012
                        ;             a = b/10;
        MOVF  b,W
        MOVWF C7tmp
        CLRF  C8rem
        MOVLW 8
        MOVWF C6cnt
m014    RLF   C7tmp,1
        RLF   C8rem,1
        MOVLW 10
        SUBWF C8rem,W
        BTFSS 0x03,Carry
        GOTO  m015
        MOVLW 10
        SUBWF C8rem,1
        BSF   0x03,Carry
m015    RLF   a,1
        DECFSZ C6cnt,1
        GOTO  m014
                        ;             putchar('0'+a); // print 10's
        MOVLW 48
        ADDWF a,W
        CALL  putchar
                        ;             a = b%10;
        MOVF  b,W
        MOVWF C10tmp
        CLRF  a
        MOVLW 8
        MOVWF C9cnt
m016    RLF   C10tmp,1
        RLF   a,1
        MOVLW 10
        SUBWF a,W
        BTFSS 0x03,Carry
        GOTO  m017
        MOVLW 10
        SUBWF a,1
m017    DECFSZ C9cnt,1
        GOTO  m016
                        ;             putchar('0'+a); // print 1's
        MOVLW 48
        ADDWF a,W
        CALL  putchar
                        ;             break;
        GOTO  m026
                        ;           case 'b':         // %b BINARY 8bit
                        ;             for( m = 0 ; m < 8 ; m++ )
m018    CLRF  m
m019    MOVLW 8
        SUBWF m,W
        BTFSC 0x03,Carry
        GOTO  m026
                        ;              {
                        ;                if (variable.7 == 1) putchar('1');
        BTFSS variable,7
        GOTO  m020
        MOVLW 49
        CALL  putchar
                        ;                else putchar('0');
        GOTO  m021
m020    MOVLW 48
        CALL  putchar
                        ;                variable = rl(variable);
m021    RLF   variable,1
                        ;               }
        INCF  m,1
        GOTO  m019
                        ;              break;
                        ;           case 'c':         // %c  'char'
                        ;             putchar(variable);
m022    MOVF  variable,W
        CALL  putchar
                        ;             break;
        GOTO  m026
                        ;           case '%':
                        ;             putchar('%');
m023    MOVLW 37
        CALL  putchar
                        ;             break;
        GOTO  m026
                        ;           default:          // not implemented
                        ;             putchar('!');
m024    MOVLW 33
        CALL  putchar
                        ;         }
                        ;      }
                        ;      else putchar(k);
        GOTO  m026
m025    MOVF  k,W
        CALL  putchar
                        ;   }
m026    INCF  i,1
        GOTO  m005
                        ;}
m027    RETURN
                        ;
                        ;
                        ;
                        ;
                        ;/* **** delay function **** */
                        ;
                        ;void delay10( char n)
                        ;{
delay10
        BCF   0x03,RP0
        BCF   0x03,RP1
        MOVWF n
                        ;    char i;
                        ;    OPTION = 7;
        MOVLW 7
        BSF   0x03,RP0
        MOVWF OPTION_REG
                        ;    do  {  i = TMR0 + 39; /* 256 microsec * 39 = 10 ms */
m028    MOVLW 39
        BCF   0x03,RP0
        BCF   0x03,RP1
        ADDWF TMR0,W
        MOVWF i_2
                        ;        while ( i != TMR0) ;
m029    BCF   0x03,RP0
        BCF   0x03,RP1
        MOVF  i_2,W
        XORWF TMR0,W
        BTFSS 0x03,Zero_
        GOTO  m029
                        ;    } while ( --n > 0);
        BCF   0x03,RP0
        BCF   0x03,RP1
        DECFSZ n,1
        GOTO  m028
                        ;}
        RETURN

        END


; *** KEY INFO ***

; 0x002F P0   10 word(s)  0 % : initserial
; 0x0012 P0   14 word(s)  0 % : ADinit
; 0x0020 P0   15 word(s)  0 % : PWMinit
; 0x0039 P0   25 word(s)  1 % : putchar
; 0x0052 P0  151 word(s)  7 % : printf
; 0x00E9 P0   22 word(s)  1 % : delay10
; 0x0002 P0   16 word(s)  0 % : main
; 0x0001 P0    1 word(s)  0 % : _const1

; RAM usage: 8 bytes (8 local), 248 bytes free
; Maximum call level: 1
;  Codepage 0 has  255 word(s) :  12 %
;  Codepage 1 has    0 word(s) :   0 %
; Total of 255 code words (6 %)
