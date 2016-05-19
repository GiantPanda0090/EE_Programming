
; CC5X Version 3.4H, Copyright (c) B Knudsen Data
; C compiler for the PICmicro family
; ************  12. May 2016  10:07  *************

	processor  16F690
	radix  DEC

	__config 0xD5

INDF        EQU   0x00
TMR0        EQU   0x01
PCL         EQU   0x02
FSR         EQU   0x04
PORTA       EQU   0x05
TRISA       EQU   0x85
PCLATH      EQU   0x0A
Carry       EQU   0
Zero_       EQU   2
RP0         EQU   5
RP1         EQU   6
IRP         EQU   7
OPTION_REG  EQU   0x81
PORTC       EQU   0x07
T1CON       EQU   0x10
CCPR1L      EQU   0x15
CCPR1H      EQU   0x16
CCP1CON     EQU   0x17
TRISC       EQU   0x87
ANSEL       EQU   0x11E
CCP1IF      EQU   2
arg1_5      EQU   0x35
arg2_5      EQU   0x37
rm          EQU   0x38
counter_5   EQU   0x39
tmp         EQU   0x3A
arg1_9      EQU   0x35
arg2_9      EQU   0x37
rm_5        EQU   0x38
counter_9   EQU   0x39
tmp_2       EQU   0x3A
T           EQU   0x20
f           EQU   0x22
t1          EQU   0x24
t2          EQU   0x26
C1cnt       EQU   0x2A
C2tmp       EQU   0x2B
C3rem       EQU   0x2E
ch          EQU   0x35
bitCount    EQU   0x36
ti          EQU   0x37
string      EQU   0x2A
i           EQU   0x2B
k           EQU   0x2C
number      EQU   0x2A
string_2    EQU   0x2C
i_2         EQU   0x33
temp        EQU   0x34
n           EQU   0x2A
i_3         EQU   0x2B
ci          EQU   0x2D

	GOTO main

  ; FILE math16.h
			;// SIZE
			;
			;#pragma library 1
			;/*
			;uns16 operator* _mult8x8( uns8 arg1, uns8 arg2);
			;int16 operator* _multS8x8( int8 arg1, int8 arg2);
			;uns16 operator* _multU16x8( uns16 arg1, uns8 arg2);
			;uns16 operator* _mult16x16( uns16 arg1, uns16 arg2);
			;uns16 operator/ _divU16_8( uns16 arg1, uns8 arg2);
			;uns16 operator/ _divU16_16( uns16 arg1, uns16 arg2);
			;int16 operator/ _divS16_8( int16 arg1, int8 arg2);
			;int16 operator/ _divS16_16( int16 arg1, int16 arg2);
			;uns8 operator% _remU16_8( uns16 arg1, uns8 arg2);
			;uns16 operator% _remU16_16( uns16 arg1, uns16 arg2);
			;int8 operator% _remS16_8( int16 arg1, int8 arg2);
			;int16 operator% _remS16_16( int16 arg1, int16 arg2);
			;*/
			;
			;#if __CoreSet__ < 1410
			; #define genAdd(r,a) W=a; btsc(Carry); W=incsz(a); r+=W
			; #define genSub(r,a) W=a; btss(Carry); W=incsz(a); r-=W
			; #define genAddW(r,a) W=a; btsc(Carry); W=incsz(a); W=r+W
			; #define genSubW(r,a) W=a; btss(Carry); W=incsz(a); W=r-W
			;#else
			; #define genAdd(r,a) W=a; r=addWFC(r)
			; #define genSub(r,a) W=a; r=subWFB(r)
			; #define genAddW(r,a) W=a; W=addWFC(r)
			; #define genSubW(r,a) W=a; W=subWFB(r)
			;#endif
			;
			;
			;int8 operator*( int8 arg1, int8 arg2)  @
			;
			;uns16 operator* _mult8x8( uns8 arg1, uns8 arg2)
			;{
_const1
	BCF   0x03,RP0
	BCF   0x03,RP1
	MOVWF ci
	MOVLW 43
	SUBWF ci,W
	BTFSC 0x03,Carry
	RETLW 0
	BCF   0x03,RP0
	BCF   0x03,RP1
	CLRF  PCLATH
	MOVF  ci,W
	ADDWF PCL,1
	RETLW 70
	RETLW 114
	RETLW 101
	RETLW 113
	RETLW 117
	RETLW 101
	RETLW 110
	RETLW 99
	RETLW 121
	RETLW 32
	RETLW 102
	RETLW 32
	RETLW 105
	RETLW 115
	RETLW 32
	RETLW 91
	RETLW 72
	RETLW 122
	RETLW 93
	RETLW 58
	RETLW 32
	RETLW 0
	RETLW 32
	RETLW 32
	RETLW 80
	RETLW 101
	RETLW 114
	RETLW 105
	RETLW 111
	RETLW 100
	RETLW 32
	RETLW 84
	RETLW 32
	RETLW 105
	RETLW 115
	RETLW 32
	RETLW 91
	RETLW 117
	RETLW 115
	RETLW 93
	RETLW 58
	RETLW 32
	RETLW 0
_mult8x8
			;    uns16 rval;
			;    char counter = sizeof(arg2)*8;
			;    rval.high8 = 0;
			;    W = arg1;
			;    do  {
			;        arg2 = rr( arg2);
			;        if (Carry)
			;            rval.high8 += W;
			;        rval = rr( rval);
			;        counter = decsz(counter);
			;    } while (1);
			;    return rval;
			;}
			;
			;
			;int16 operator* _multS8x8( int8 arg1, int8 arg2)
			;{
_multS8x8
			;    uns16 rval;
			;    char counter = sizeof(arg2)*8;
			;    int8 tmpArg2 = arg2;
			;    rval.high8 = 0;
			;    W = arg1;
			;    do  {
			;        tmpArg2 = rr( tmpArg2);
			;        if (Carry)
			;            rval.high8 += W;
			;        rval = rr( rval);
			;        counter = decsz(counter);
			;    } while (1);
			;    W = arg2;
			;    if (arg1 < 0)
			;        rval.high8 -= W;
			;    W = arg1;
			;    if (arg2 < 0)
			;        rval.high8 -= W;
			;    return rval;
			;}
			;
			;
			;uns16 operator*( uns8 arg1, uns16 arg2) exchangeArgs @
			;
			;uns16 operator* _multU16x8( uns16 arg1, uns8 arg2)
			;{
_multU16x8
			;    uns16 rval;
			;    uns8 rvalH = 0;
			;    char counter = sizeof(arg1)*8;
			;    W = arg2;
			;    do  {
			;        arg1 = rr( arg1);
			;        if (Carry)
			;            rvalH += W;
			;        rvalH = rr(rvalH);
			;        rval = rr(rval);
			;        counter = decsz(counter);
			;    } while (1);
			;    return rval;
			;}
			;
			;
			;int16 operator*( int16 arg1, int16 arg2) @
			;
			;uns16 operator* _mult16x16( uns16 arg1, uns16 arg2)
			;{
_mult16x16
			;    uns16 rval;
			;    char counter = sizeof(arg1)*8;
			;    do  {
			;        Carry = 0;
			;        rval = rl( rval);
			;        arg1 = rl( arg1);
			;        if (Carry)
			;            rval += arg2;
			;        counter = decsz(counter);
			;    } while (1);
			;    return rval;
			;}
			;
			;
			;
			;uns16 operator/ _divU16_8( uns16 arg1, uns8 arg2)
			;{
_divU16_8
	BCF   0x03,RP0
	BCF   0x03,RP1
	MOVWF arg2_5
			;    uns8 rm = 0;
	CLRF  rm
			;    char counter = sizeof(arg1)*8+1;
	MOVLW 17
	MOVWF counter_5
			;    goto ENTRY_ML;
	GOTO  m002
			;    do  {
			;        rm = rl( rm);
m001	BCF   0x03,RP0
	BCF   0x03,RP1
	RLF   rm,1
			;        uns8 tmp = rl( tmp);
	RLF   tmp,1
			;        W = rm - arg2;
	MOVF  arg2_5,W
	SUBWF rm,W
			;        if (tmp&1)
	BTFSC tmp,0
			;            Carry = 1;
	BSF   0x03,Carry
			;        if (Carry)
	BTFSS 0x03,Carry
	GOTO  m002
			;            rm = W;
	BCF   0x03,RP0
	BCF   0x03,RP1
	MOVWF rm
			;       ENTRY_ML:
			;        arg1 = rl( arg1);
m002	BCF   0x03,RP0
	BCF   0x03,RP1
	RLF   arg1_5,1
	RLF   arg1_5+1,1
			;        counter = decsz(counter);
	DECFSZ counter_5,1
			;    } while (1);
	GOTO  m001
			;    return arg1;
	MOVF  arg1_5,W
	RETURN
			;}
			;
			;
			;uns16 operator/ _divU16_16( uns16 arg1, uns16 arg2)
			;{
_divU16_16
			;    uns16 rm = 0;
			;    char counter = sizeof(arg1)*8+1;
			;    goto ENTRY_ML;
			;    do  {
			;        rm = rl( rm);
			;        W = rm.low8 - arg2.low8;
			;        genSubW( rm.high8, arg2.high8);
			;        if (!Carry)
			;            goto ENTRY_ML;
			;        rm.high8 = W;
			;        rm.low8 -= arg2.low8;
			;        Carry = 1;
			;       ENTRY_ML:
			;        arg1 = rl( arg1);
			;        counter = decsz(counter);
			;    } while (1);
			;    return arg1;
			;}
			;
			;
			;int8  operator/ (int8 arg1, int8 arg2) @
			;
			;int16 operator/ _divS16_8( int16 arg1, int8 arg2)
			;{
_divS16_8
			;    uns8 rm = 0;
			;    char counter = 16+1;
			;    char sign = arg1.high8 ^ arg2.high8;
			;    if (arg1 < 0)  {
			;       INVERT_ML:
			;        arg1 = -arg1;
			;        if (!counter)
			;            return arg1;
			;    }
			;    if (arg2 < 0)
			;        arg2 = -arg2;
			;    goto ENTRY_ML;
			;    do  {
			;        rm = rl( rm);
			;        W = rm - arg2;
			;        if (Carry)
			;            rm = W;
			;       ENTRY_ML:
			;        arg1 = rl( arg1);
			;        counter = decsz(counter);
			;    } while (1);
			;    if (sign & 0x80)
			;        goto INVERT_ML;
			;    return arg1;
			;}
			;
			;
			;int16 operator/ _divS16_16( int16 arg1, int16 arg2)
			;{
_divS16_16
			;    uns16 rm = 0;
			;    char counter = sizeof(arg1)*8+1;
			;    char sign = arg1.high8 ^ arg2.high8;
			;    if (arg1 < 0)  {
			;       INVERT_ML:
			;        arg1 = -arg1;
			;        if (!counter)
			;            return arg1;
			;    }
			;    if (arg2 < 0)
			;        arg2 = -arg2;
			;    goto ENTRY_ML;
			;    do  {
			;        rm = rl( rm);
			;        W = rm.low8 - arg2.low8;
			;        genSubW( rm.high8, arg2.high8);
			;        if (!Carry)
			;            goto ENTRY_ML;
			;        rm.high8 = W;
			;        rm.low8 -= arg2.low8;
			;        Carry = 1;
			;       ENTRY_ML:
			;        arg1 = rl( arg1);
			;        counter = decsz(counter);
			;    } while (1);
			;    if (sign & 0x80)
			;        goto INVERT_ML;
			;    return arg1;
			;}
			;
			;
			;uns8 operator% _remU16_8( uns16 arg1, uns8 arg2)
			;{
_remU16_8
	BCF   0x03,RP0
	BCF   0x03,RP1
	MOVWF arg2_9
			;    uns8 rm = 0;
	CLRF  rm_5
			;    char counter = sizeof(arg1)*8;
	MOVLW 16
	MOVWF counter_9
			;    do  {
			;        arg1 = rl( arg1);
m003	BCF   0x03,RP0
	BCF   0x03,RP1
	RLF   arg1_9,1
	RLF   arg1_9+1,1
			;        rm = rl( rm);
	RLF   rm_5,1
			;        uns8 tmp = rl( tmp);
	RLF   tmp_2,1
			;        W = rm - arg2;
	MOVF  arg2_9,W
	SUBWF rm_5,W
			;        if (tmp&1)
	BTFSC tmp_2,0
			;            Carry = 1;
	BSF   0x03,Carry
			;        if (Carry)
	BTFSS 0x03,Carry
	GOTO  m004
			;            rm = W;
	BCF   0x03,RP0
	BCF   0x03,RP1
	MOVWF rm_5
			;        counter = decsz(counter);
m004	BCF   0x03,RP0
	BCF   0x03,RP1
	DECFSZ counter_9,1
			;    } while (1);
	GOTO  m003
			;    return rm;
	MOVF  rm_5,W
	RETURN
			;}
			;
			;
			;uns16 operator% _remU16_16( uns16 arg1, uns16 arg2)
			;{
_remU16_16
			;    uns16 rm = 0;
			;    char counter = sizeof(arg1)*8;
			;    do  {
			;        arg1 = rl( arg1);
			;        rm = rl( rm);
			;        W = rm.low8 - arg2.low8;
			;        genSubW( rm.high8, arg2.high8);
			;        if (!Carry)
			;            goto NOSUB;
			;        rm.high8 = W;
			;        rm.low8 -= arg2.low8;
			;      NOSUB:
			;        counter = decsz(counter);
			;    } while (1);
			;    return rm;
			;}
			;
			;
			;int8 operator% (int8 arg1, int8 arg2) @
			;
			;int8 operator% _remS16_8( int16 arg1, int8 arg2)
			;{
_remS16_8
			;    int8 rm = 0;
			;    char counter = 16;
			;    char sign = arg1.high8;
			;    if (arg1 < 0)
			;        arg1 = -arg1;
			;    if (arg2 < 0)
			;        arg2 = -arg2;
			;    do  {
			;        arg1 = rl( arg1);
			;        rm = rl( rm);
			;        W = rm - arg2;
			;        if (Carry)
			;            rm = W;
			;        counter = decsz(counter);
			;    } while (1);
			;    if (sign & 0x80)
			;        rm = -rm;
			;    return rm;
			;}
			;
			;
			;int16 operator% _remS16_16( int16 arg1, int16 arg2)
			;{
_remS16_16
			;    int16 rm = 0;
			;    char counter = sizeof(arg1)*8;
			;    char sign = arg1.high8;
			;    if (arg1 < 0)
			;        arg1 = -arg1;
			;    if (arg2 < 0)
			;        arg2 = -arg2;
			;    do  {
			;        arg1 = rl( arg1);
			;        rm = rl( rm);
			;        W = rm.low8 - arg2.low8;
			;        genSubW( rm.high8, arg2.high8);
			;        if (!Carry)
			;            goto NOSUB;
			;        rm.high8 = W;
			;        rm.low8 -= arg2.low8;
			;      NOSUB:
			;        counter = decsz(counter);
			;    } while (1);
			;    if (sign & 0x80)
			;        rm = -rm;
			;    return rm;

  ; FILE frequency.c
			;/* frequency.c measure frequency on CCP-pin.        */
			;/* input frequency 100 Hz - 10 kHz  at CCP1-pin     */
			;/* Output 1 MHz clock for 4040 counter.             */
			;
			;
			;/* B Knudsen Cc5x C-compiler - not ANSI-C */
			;#include "16F690.h"
			;#include "math16.h"
			;/* RA4 is used as 1 MHz Clockout pin */
			;#pragma config |= 0xD5  
			;
			;/*  function prototypes  */
			;void initserial( void );
			;void putchar( char );
			;void string_out( const char * ); 
			;void unsLong_out(unsigned long number);
			;void delay10( char );
			;
			;void main( void)
			;{
main
			;   unsigned long T, f, t1, t2,save;
			;   TRISC.5 = 1;  /* CCP1-pin is input                 */
	BSF   0x03,RP0
	BCF   0x03,RP1
	BSF   TRISC,5
			;   TRISA.4 = 0;  /* Clockout is output                */
	BCF   TRISA,4
			; TRISC.0=0;
	BCF   TRISC,0
			;   TRISC.1=0;
	BCF   TRISC,1
			;   
			;   initserial();
	CALL  initserial
			;   delay10(100); /* 1 sek delay                  */
	MOVLW 100
	CALL  delay10
			;   /* 1 sek to turn on VDD and Connect UART-Tool */
			;
			;/* Setup TIMER1 */
			;/*
			;00.xx.x.x.x.x  --
			;xx.00.x.x.x.x  Prescale 1/1
			;xx.xx.0.x.x.x  TMR1-oscillator is shut off
			;xx.xx.x.0.x.x  - (clock input synchronization)
			;xx.xx.x.x.0.x  Use internal clock f_osc/4
			;xx.xx.x.x.x.1  TIMER1 is ON
			;*/
			;   T1CON = 0b00.00.0.0.0.1 ;
	MOVLW 1
	BCF   0x03,RP0
	BCF   0x03,RP1
	MOVWF T1CON
			;
			;/* Setup CCP1 */
			;/*
			;00.00.xxxx  -- --
			;xx.xx.0101  Capture each positive edge
			;*/
			;   CCP1CON = 0b00.00.0101 ;
	MOVLW 5
	MOVWF CCP1CON
			;
			;
			;while(1)
			;  {
			;    CCP1IF = 0 ;          /* reset flag            */
m005	BCF   0x03,RP0
	BCF   0x03,RP1
	BCF   0x0C,CCP1IF
			;    while (CCP1IF == 0 ); /* wait for capture      */
m006	BCF   0x03,RP0
	BCF   0x03,RP1
	BTFSS 0x0C,CCP1IF
	GOTO  m006
			;    t1  = CCPR1H*256;
	BCF   0x03,RP0
	BCF   0x03,RP1
	MOVF  CCPR1H,W
	MOVWF t1+1
	CLRF  t1
			;    t1 += CCPR1L;
	MOVF  CCPR1L,W
	ADDWF t1,1
	BTFSC 0x03,Carry
	INCF  t1+1,1
			;    CCP1IF = 0 ;          /* reset flag            */
	BCF   0x0C,CCP1IF
			;    while (CCP1IF == 0 ); /* wait for next capture */
m007	BCF   0x03,RP0
	BCF   0x03,RP1
	BTFSS 0x0C,CCP1IF
	GOTO  m007
			;    t2  = CCPR1H*256;
	BCF   0x03,RP0
	BCF   0x03,RP1
	MOVF  CCPR1H,W
	MOVWF t2+1
	CLRF  t2
			;    t2 += CCPR1L;
	MOVF  CCPR1L,W
	ADDWF t2,1
	BTFSC 0x03,Carry
	INCF  t2+1,1
			;
			;    /* Calculations  */
			;    T = t2 - t1;          /* calculate period                 */
	MOVF  t1+1,W
	SUBWF t2+1,W
	MOVWF T+1
	MOVF  t1,W
	SUBWF t2,W
	MOVWF T
	BTFSS 0x03,Carry
	DECF  T+1,1
			;	
			;	if ( 3700 > T){
	MOVLW 14
	SUBWF T+1,W
	BTFSS 0x03,Carry
	GOTO  m008
	BTFSS 0x03,Zero_
	GOTO  m009
	MOVLW 116
	SUBWF T,W
	BTFSC 0x03,Carry
	GOTO  m009
			;	PORTC.1=1;
m008	BCF   0x03,RP0
	BCF   0x03,RP1
	BSF   PORTC,1
			;	}
			;	else if ( 4100< T){
	GOTO  m012
m009	MOVLW 16
	BCF   0x03,RP0
	BCF   0x03,RP1
	SUBWF T+1,W
	BTFSS 0x03,Carry
	GOTO  m011
	BTFSS 0x03,Zero_
	GOTO  m010
	MOVLW 5
	SUBWF T,W
	BTFSS 0x03,Carry
	GOTO  m011
			;	PORTC.0=1;
m010	BCF   0x03,RP0
	BCF   0x03,RP1
	BSF   PORTC,0
			;	}
			;	else{
	GOTO  m012
			;	PORTC.0=0;
m011	BCF   0x03,RP0
	BCF   0x03,RP1
	BCF   PORTC,0
			;	nop();
	NOP  
			;	PORTC.1=0;
	BCF   PORTC,1
			;	}
			;	
			;    f = 1000000/T;        /* calculate frequency              */
m012	MOVLW 64
	BCF   0x03,RP0
	BCF   0x03,RP1
	MOVWF C2tmp
	MOVLW 66
	MOVWF C2tmp+1
	MOVLW 15
	MOVWF C2tmp+2
	CLRF  C3rem
	CLRF  C3rem+1
	MOVLW 24
	MOVWF C1cnt
m013	BCF   0x03,RP0
	BCF   0x03,RP1
	RLF   C2tmp,1
	RLF   C2tmp+1,1
	RLF   C2tmp+2,1
	RLF   C3rem,1
	RLF   C3rem+1,1
	BTFSC 0x03,Carry
	GOTO  m014
	MOVF  T+1,W
	SUBWF C3rem+1,W
	BTFSS 0x03,Carry
	GOTO  m015
	BTFSS 0x03,Zero_
	GOTO  m014
	MOVF  T,W
	SUBWF C3rem,W
	BTFSS 0x03,Carry
	GOTO  m015
m014	BCF   0x03,RP0
	BCF   0x03,RP1
	MOVF  T+1,W
	SUBWF C3rem+1,1
	MOVF  T,W
	SUBWF C3rem,1
	BTFSS 0x03,Carry
	DECF  C3rem+1,1
	BSF   0x03,Carry
m015	BCF   0x03,RP0
	BCF   0x03,RP1
	RLF   f,1
	RLF   f+1,1
	DECFSZ C1cnt,1
	GOTO  m013
			;    delay10(10);         /* 1 sek delay between measurements */
	MOVLW 10
	CALL  delay10
			;
			;    /* print values */
			;	string_out( "Frequency f is [Hz]: " );
	BCF   0x03,RP0
	BCF   0x03,RP1
	CLRF  string
	CALL  string_out
			;    unsLong_out(f); 
	BCF   0x03,RP0
	BCF   0x03,RP1
	MOVF  f,W
	MOVWF number
	MOVF  f+1,W
	MOVWF number+1
	CALL  unsLong_out
			;    string_out( "  Period T is [us]: " );
	MOVLW 22
	BCF   0x03,RP0
	BCF   0x03,RP1
	MOVWF string
	CALL  string_out
			;    unsLong_out(T); 
	BCF   0x03,RP0
	BCF   0x03,RP1
	MOVF  T,W
	MOVWF number
	MOVF  T+1,W
	MOVWF number+1
	CALL  unsLong_out
			;   
			;    putchar('\r'); putchar('\n');
	MOVLW 13
	CALL  putchar
	MOVLW 10
	CALL  putchar
			;
			;  }
	GOTO  m005
			;}
			;
			;
			;
			;/* *********************************** */
			;/*            FUNCTIONS                */
			;/* *********************************** */
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
			;   TRISA.1 = 1; // input from PK2 UART-tool - not used
	BSF   TRISA,1
			;   return;      
	RETURN
			;}
			;
			;void putchar( char ch )  // sends one char bitbanging
			;{
putchar
	BCF   0x03,RP0
	BCF   0x03,RP1
	MOVWF ch
			;  char bitCount, ti;
			;  PORTA.0 = 0; // set startbit
	BCF   PORTA,0
			;  for ( bitCount = 10; bitCount > 0 ; bitCount-- )
	MOVLW 10
	MOVWF bitCount
m016	BCF   0x03,RP0
	BCF   0x03,RP1
	MOVF  bitCount,1
	BTFSC 0x03,Zero_
	GOTO  m018
			;   {
			;     // delay one bit 104 usec at 4 MHz
			;     // 5+18*5-1+1+9=104 without optimization 
			;     ti = 18; do ; while( --ti > 0); nop(); 
	MOVLW 18
	MOVWF ti
m017	BCF   0x03,RP0
	BCF   0x03,RP1
	DECFSZ ti,1
	GOTO  m017
	NOP  
			;     Carry = 1;     // stopbit
	BSF   0x03,Carry
			;     ch = rr( ch ); // Rotate Right through Carry
	RRF   ch,1
			;     PORTA.0 = Carry;
	BTFSS 0x03,Carry
	BCF   PORTA,0
	BTFSC 0x03,Carry
	BSF   PORTA,0
			;   }
	DECF  bitCount,1
	GOTO  m016
			;  return;
m018	RETURN
			;}
			;
			;void string_out(const char * string)
			;{
string_out
			;  char i, k;
			;  for(i = 0 ; ; i++)
	BCF   0x03,RP0
	BCF   0x03,RP1
	CLRF  i
			;   {
			;     k = string[i];
m019	BCF   0x03,RP0
	BCF   0x03,RP1
	MOVF  i,W
	ADDWF string,W
	CALL  _const1
	BCF   0x03,RP0
	BCF   0x03,RP1
	MOVWF k
			;     if( k == '\0') return;   // found end of string
	MOVF  k,1
	BTFSC 0x03,Zero_
	RETURN
			;     putchar(k); 
	BCF   0x03,RP0
	BCF   0x03,RP1
	MOVF  k,W
	CALL  putchar
			;   }
	BCF   0x03,RP0
	BCF   0x03,RP1
	INCF  i,1
	GOTO  m019
			;}
			;
			;
			;
			;/* ******************************************** */
			;
			;/* **** print decimal number function **** */
			;
			;void unsLong_out(unsigned long number)
			;{
unsLong_out
			;   char string[7]; // temporary buffer for reordering characters
			;   char i,temp;
			;   string[6] = '\0';
	BCF   0x03,RP0
	BCF   0x03,RP1
	CLRF  string_2+6
			;   string[0] = ' '; // place for sign. Not used this time.
	MOVLW 32
	MOVWF string_2
			; 
			;  
			;   for (i = 5; ;i--)
	MOVLW 5
	MOVWF i_2
			;     {
			;       temp = (uns16)number % 10;
m020	BCF   0x03,RP0
	BCF   0x03,RP1
	MOVF  number,W
	MOVWF arg1_9
	MOVF  number+1,W
	MOVWF arg1_9+1
	MOVLW 10
	CALL  _remU16_8
	BCF   0x03,RP0
	BCF   0x03,RP1
	MOVWF temp
			;       temp += '0';
	MOVLW 48
	ADDWF temp,1
			;       string[i]=temp;
	MOVLW 44
	ADDWF i_2,W
	MOVWF FSR
	BCF   0x03,IRP
	MOVF  temp,W
	MOVWF INDF
			;       if (i==1) break;
	DECF  i_2,W
	BTFSC 0x03,Zero_
	GOTO  m021
			;       (uns16)number /= 10;
	BCF   0x03,RP0
	BCF   0x03,RP1
	MOVF  number,W
	MOVWF arg1_5
	MOVF  number+1,W
	MOVWF arg1_5+1
	MOVLW 10
	CALL  _divU16_8
	BCF   0x03,RP0
	BCF   0x03,RP1
	MOVF  arg1_5,W
	MOVWF number
	MOVF  arg1_5+1,W
	MOVWF number+1
			;     }
	DECF  i_2,1
	GOTO  m020
			;   for(i = 0 ; ; i++)
m021	BCF   0x03,RP0
	BCF   0x03,RP1
	CLRF  i_2
			;     { 
			;        temp = string[i];
m022	MOVLW 44
	BCF   0x03,RP0
	BCF   0x03,RP1
	ADDWF i_2,W
	MOVWF FSR
	BCF   0x03,IRP
	MOVF  INDF,W
	MOVWF temp
			;        if( temp == '\0') return;   // found end of string
	MOVF  temp,1
	BTFSC 0x03,Zero_
	RETURN
			;        putchar(temp); 
	BCF   0x03,RP0
	BCF   0x03,RP1
	MOVF  temp,W
	CALL  putchar
			;     }
	BCF   0x03,RP0
	BCF   0x03,RP1
	INCF  i_2,1
	GOTO  m022
			;} 
			;
			;/* ***************************************** */
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
m023	MOVLW 39
	BCF   0x03,RP0
	BCF   0x03,RP1
	ADDWF TMR0,W
	MOVWF i_3
			;        while ( i != TMR0) ;
m024	BCF   0x03,RP0
	BCF   0x03,RP1
	MOVF  i_3,W
	XORWF TMR0,W
	BTFSS 0x03,Zero_
	GOTO  m024
			;    } while ( --n > 0);
	BCF   0x03,RP0
	BCF   0x03,RP1
	DECFSZ n,1
	GOTO  m023
			;}
	RETURN

	END


; *** KEY INFO ***

; 0x0038 P0   28 word(s)  1 % : _divU16_8
; 0x0054 P0   27 word(s)  1 % : _remU16_8
; 0x0113 P0   10 word(s)  0 % : initserial
; 0x011D P0   27 word(s)  1 % : putchar
; 0x0138 P0   22 word(s)  1 % : string_out
; 0x014E P0   67 word(s)  3 % : unsLong_out
; 0x0191 P0   22 word(s)  1 % : delay10
; 0x006F P0  164 word(s)  8 % : main
; 0x0001 P0   55 word(s)  2 % : _const1

; RAM usage: 27 bytes (27 local), 229 bytes free
; Maximum call level: 2
;  Codepage 0 has  423 word(s) :  20 %
;  Codepage 1 has    0 word(s) :   0 %
; Total of 423 code words (10 %)
