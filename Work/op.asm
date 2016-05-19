
; CC5X Version 3.4H, Copyright (c) B Knudsen Data
; C compiler for the PICmicro family
; ************  19. May 2016  17:03  *************

	processor  16F690
	radix  DEC

	__config 0xD4

TMR0        EQU   0x01
PCL         EQU   0x02
STATUS      EQU   0x03
PORTA       EQU   0x05
TRISA       EQU   0x85
TRISB       EQU   0x86
PCLATH      EQU   0x0A
Carry       EQU   0
Zero_       EQU   2
RP0         EQU   5
RP1         EQU   6
GIE         EQU   7
OPTION_REG  EQU   0x81
T2CON       EQU   0x12
CCPR1L      EQU   0x15
CCP1CON     EQU   0x17
TRISC       EQU   0x87
PR2         EQU   0x92
IOCA        EQU   0x96
EEDATA      EQU   0x10C
EEADR       EQU   0x10D
EEDATH      EQU   0x10E
EEADRH      EQU   0x10F
ANSEL       EQU   0x11E
ANSELH      EQU   0x11F
EECON2      EQU   0x18D
RABIF       EQU   0
RABIE       EQU   3
EEIF        EQU   4
RD          EQU   0
WR          EQU   1
WREN        EQU   2
EEPGD       EQU   7
RS          EQU   4
EN          EQU   6
D7          EQU   3
D6          EQU   2
D5          EQU   1
D4          EQU   0
receiver_flag EQU   0
receiver_byte EQU   0x33
svrWREG     EQU   0x70
svrSTATUS   EQU   0x20
svrPCLATH   EQU   0x21
bitCount    EQU   0x22
ti          EQU   0x23
choice      EQU   0x24
cnt         EQU   0x25
save        EQU   0x27
i_2         EQU   0x28
i_3         EQU   0x7F
x           EQU   0x29
x_2         EQU   0x7F
x_3         EQU   0x7F
x_4         EQU   0x7F
ch          EQU   0x2F
bitCount_2  EQU   0x30
ti_2        EQU   0x31
data        EQU   0x29
string      EQU   0x28
variable    EQU   0x29
i_4         EQU   0x2A
k           EQU   0x2B
m           EQU   0x2C
a           EQU   0x2D
b           EQU   0x2E
C1cnt       EQU   0x2F
C2tmp       EQU   0x30
C3rem       EQU   0x31
C4cnt       EQU   0x2F
C5tmp       EQU   0x30
C6cnt       EQU   0x2F
C7tmp       EQU   0x30
C8rem       EQU   0x31
C9cnt       EQU   0x2F
C10tmp      EQU   0x30
millisec    EQU   0x2A
data_2      EQU   0x7F
adress      EQU   0x7F
adress_2    EQU   0x7F
temp        EQU   0x7F
ci          EQU   0x2F

	GOTO main

  ; FILE op.c
			;#include "16F690.h"
			;#include "int16Cxx.h"
			;#pragma config |= 0x00D4
			;
			;/* I/O-pin definitions                               */ 
			;/* change if you need a pin for a different purpose  */
			;#pragma bit RS  @ PORTB.4
			;#pragma bit EN  @ PORTB.6
			;
			;#pragma bit D7  @ PORTC.3
			;#pragma bit D6  @ PORTC.2
			;#pragma bit D5  @ PORTC.1
			;#pragma bit D4  @ PORTC.0
			;
			;#pragma bit EN_DC  @ PORTC.5
			;#pragma bit TREN_DC  @ TRISC.5
			;
			;#define DUTY 128
			;
			;//define//
			;//************************************************************************//
			;void init( void );
			;void initserial( void );
			;void init_io_ports( void );
			;void init_serial( void );
			;void init_interrupt( void );
			;void delay( char ); // ms delay function
			;void lcd_init( void );
			;void lcd_putchar( char );
			;char text1( char );
			;char text2( char );
			;char text3( char );
			;char text4( char );
			;void putchar( char );
			;char getchar( void );
			;void power_on(void);
			;void power_off(void);
			;void printf(const char *string, char variable);
			;void lcd_poweron(void);
			;void lcd_poweroff(void);
			;char getchar_eedata( char adress );
			;void putchar_eedata( char data, char adress );
			;void direc_change(void);
			;//******************************************************************************//
			;
			;/*interupt*/
			;//*****************************************************************************//
			;bit receiver_flag;   /* Signal-flag used by interrupt routine   */
			;char receiver_byte;  /* Transfer Byte used by interrupt routine */
			;
			;#pragma origin 4
	ORG 0x0004
			;interrupt int_server( void ) /* the place for the interrupt routine */
			;{
int_server
			;  int_save_registers
	MOVWF svrWREG
	SWAPF STATUS,W
	BCF   0x03,RP0
	BCF   0x03,RP1
	MOVWF svrSTATUS
	MOVF  PCLATH,W
	MOVWF svrPCLATH
	CLRF  PCLATH
			;  /* New interrupts are automaticaly disabled            */
			;  /* "Interrupt on change" at pin RA1 from PK2 UART-tool */
			;  
			;  if( PORTA.1 == 0 )  /* Interpret this as the startbit  */
	BTFSC PORTA,1
	GOTO  m006
			;    {  /* Receive one full character   */
			;      char bitCount, ti;
			;      /* delay 1,5 bit 156 usec at 4 MHz         */
			;      /* 5+28*5-1+1+2+9=156 without optimization */
			;      ti = 28; do ; while( --ti > 0); nop(); nop2();
	MOVLW 28
	MOVWF ti
m001	BCF   0x03,RP0
	BCF   0x03,RP1
	DECFSZ ti,1
	GOTO  m001
	NOP  
	GOTO  m002
			;      for( bitCount = 8; bitCount > 0 ; bitCount--)
m002	MOVLW 8
	BCF   0x03,RP0
	BCF   0x03,RP1
	MOVWF bitCount
m003	BCF   0x03,RP0
	BCF   0x03,RP1
	MOVF  bitCount,1
	BTFSC 0x03,Zero_
	GOTO  m005
			;       {
			;         Carry = PORTA.1;
	BCF   0x03,Carry
	BTFSC PORTA,1
	BSF   0x03,Carry
			;         receiver_byte = rr( receiver_byte);  /* rotate carry */
	RRF   receiver_byte,1
			;         /* delay one bit 104 usec at 4 MHz       */
			;         /* 5+18*5-1+1+9=104 without optimization */ 
			;         ti = 18; do ; while( --ti > 0); nop(); 
	MOVLW 18
	MOVWF ti
m004	BCF   0x03,RP0
	BCF   0x03,RP1
	DECFSZ ti,1
	GOTO  m004
	NOP  
			;        }
	DECF  bitCount,1
	GOTO  m003
			;      receiver_flag = 1; /* A full character is now received */
m005	BCF   0x03,RP0
	BCF   0x03,RP1
	BSF   0x32,receiver_flag
			;    }
			;  RABIF = 0;    /* Reset the RABIF-flag before leaving   */
m006	BCF   0x0B,RABIF
			;  int_restore_registers
	BCF   0x03,RP0
	BCF   0x03,RP1
	MOVF  svrPCLATH,W
	MOVWF PCLATH
	SWAPF svrSTATUS,W
	MOVWF STATUS
	SWAPF svrWREG,1
	SWAPF svrWREG,W
			;  /* New interrupts are now enabled */
			;}
	RETFIE
			;//******************************************************************************//
			;
			;void main(void)
			;{
_const1
	BCF   0x03,RP0
	BCF   0x03,RP1
	MOVWF ci
	MOVLW 0
	BSF   0x03,RP1
	MOVWF EEADRH
	BCF   0x03,RP1
	RRF   ci,W
	ANDLW 127
	ADDLW 90
	BSF   0x03,RP1
	MOVWF EEADR
	BTFSC 0x03,Carry
	INCF  EEADRH,1
	BSF   0x03,RP0
	BSF   0x03,RP1
	BSF   0x18C,EEPGD
	BSF   0x18C,RD
	NOP  
	NOP  
	BCF   0x03,RP0
	BCF   0x03,RP1
	BTFSC ci,0
	GOTO  m007
	BSF   0x03,RP1
	MOVF  EEDATA,W
	ANDLW 127
	RETURN
m007	BCF   0x03,RP0
	BSF   0x03,RP1
	RLF   EEDATA,W
	RLF   EEDATH,W
	RETURN
	DW    0x32CD
	DW    0x3AEE
	DW    0x103A
	DW    0x1631
	DW    0x1920
	DW    0x102C
	DW    0x1633
	DW    0x3420
	DW    0x50D
	DW    0x1280
	DW    0x1063
	DW    0x3454
	DW    0x1065
	DW    0x37F0
	DW    0x32F7
	DW    0x1072
	DW    0x39E9
	DW    0x3720
	DW    0x3BEF
	DW    0x37A0
	DW    0x176E
	DW    0x2820
	DW    0x32F2
	DW    0x39F3
	DW    0x30A0
	DW    0x3A20
	DW    0x106F
	DW    0x3161
	DW    0x396F
	DW    0x1074
	DW    0x37F4
	DW    0x36A0
	DW    0x34E1
	DW    0x106E
	DW    0x32ED
	DW    0x3AEE
	DW    0x6AE
	DW    0xA
	DW    0x31A5
	DW    0x2820
	DW    0x3BEF
	DW    0x3965
	DW    0x37A0
	DW    0x3366
	DW    0x50D
	DW    0x1280
	DW    0x1063
	DW    0x34C4
	DW    0x32F2
	DW    0x3A63
	DW    0x37E9
	DW    0x106E
	DW    0x3463
	DW    0x3761
	DW    0x32E7
	DW    0x1D64
	DW    0x20
	DW    0x31A5
	DW    0x31A0
	DW    0x37E8
	DW    0x39EF
	DW    0x1065
	DW    0x1048
	DW    0x37E6
	DW    0x1072
	DW    0x32E8
	DW    0x386C
	DW    0x6A0
	DW    0xA
	DW    0x31A5
	DW    0x2CA0
	DW    0x3AEF
	DW    0x36A0
	DW    0x39F5
	DW    0x1074
	DW    0x3463
	DW    0x37EF
	DW    0x32F3
	DW    0x3120
	DW    0x3A65
	DW    0x32F7
	DW    0x3765
	DW    0x103A
	DW    0x1631
	DW    0x1920
	DW    0x102C
	DW    0x1033
	DW    0x50D
	DW    0x0
main
			; char choice;  int cnt = 0;
	BCF   0x03,RP0
	BCF   0x03,RP1
	CLRF  cnt
			;  
			; //***********************************************************//  
			;init_serial();
	CALL  init_serial
			; init_interrupt(); 
	CALL  init_interrupt
			;   T2CON = 0b0.0000.1.01; /* prescale 1:1     */
	MOVLW 5
	BCF   0x03,RP0
	BCF   0x03,RP1
	MOVWF T2CON
			;   //CCP1CON = 0b01.00.1100 ;  /* PWM-mode         */
			;   PR2     = 255;            /* max value        */
	MOVLW 255
	BSF   0x03,RP0
	MOVWF PR2
			;   CCPR1L  = 200; 
	MOVLW 200
	BCF   0x03,RP0
	MOVWF CCPR1L
			;     
			;/* I/O-pin direction in/out definitions, change if needed  */
			;	ANSEL=0; 	//  PORTC digital I/O
	BSF   0x03,RP1
	CLRF  ANSEL
			;	ANSELH=0;
	CLRF  ANSELH
			;	TRISC = 0b1101.0000;  /* RC3,2,1,0 out*/
	MOVLW 208
	BSF   0x03,RP0
	BCF   0x03,RP1
	MOVWF TRISC
			;    TRISB.4=0; /* RB4, RB6 out */
	BCF   TRISB,4
			;    TRISB.6=0;	
	BCF   TRISB,6
			;	
			;//power_off();
			;
			;    char i;
			;    lcd_init();
	CALL  lcd_init
			;//***************************************************************//
			;
			; 
			;
			;  /* You should "connect" PK2 UART-tool in one second after power on! */
			;  delay(1000); 
	MOVLW 232
	CALL  delay
			;
			;  printf("Menu: 1, 2, 3, h\r\n",0);
	BCF   0x03,RP0
	BCF   0x03,RP1
	CLRF  string
	MOVLW 0
	CALL  printf
			; char save;
			;/* uart_ choose*/
			;//****************************************************************************//
			;  while(1)
			;   {
			;   
			;     if( receiver_flag ) /* Character received? */ 
m008	BCF   0x03,RP0
	BCF   0x03,RP1
	BTFSS 0x32,receiver_flag
	GOTO  m014
			;      {
			;	 
			;        choice = receiver_byte; /* get Character from interrupt routine */
	MOVF  receiver_byte,W
	MOVWF choice
			;        receiver_flag = 0;      /* Character now taken - reset the flag */
	BCF   0x32,receiver_flag
			;		 save = choice;
	MOVF  choice,W
	MOVWF save
			;		
			;		switch (choice)
	MOVF  choice,W
	XORLW 49
	BTFSC 0x03,Zero_
	GOTO  m009
	XORLW 3
	BTFSC 0x03,Zero_
	GOTO  m010
	XORLW 1
	BTFSC 0x03,Zero_
	GOTO  m011
	XORLW 91
	BTFSC 0x03,Zero_
	GOTO  m013
	GOTO  m012
			;         {
			;          case '1':
			;		   lcd_poweron();
m009	CALL  lcd_poweron
			;		   nop();
	NOP  
			;           printf("%c The power is now on. Press a to abort to main menu.\r\n", choice);
	MOVLW 19
	BCF   0x03,RP0
	BCF   0x03,RP1
	MOVWF string
	MOVF  choice,W
	CALL  printf
			;		   nop();
	NOP  
			;           break;
	GOTO  m013
			;          case '2':
			;		  //lcd_poweroff();
			;		   nop();
m010	NOP  
			;           printf("%c Power off\r\n", choice);
	MOVLW 76
	BCF   0x03,RP0
	BCF   0x03,RP1
	MOVWF string
	MOVF  choice,W
	CALL  printf
			;		   nop();
	NOP  
			;           break;
	GOTO  m013
			;          case '3':
			;           printf("%c Direction changed: ", choice);
m011	MOVLW 91
	BCF   0x03,RP0
	BCF   0x03,RP1
	MOVWF string
	MOVF  choice,W
	CALL  printf
			;           //printf("%u\r\n", (char) PORTB.6);
			;           break;
	GOTO  m013
			;   case 'h':
			;  
			;   break;
			;          default:
			;		  printf("%c choose H for help \r\n", choice);
m012	MOVLW 114
	BCF   0x03,RP0
	BCF   0x03,RP1
	MOVWF string
	MOVF  choice,W
	CALL  printf
			;           printf("%c You must choose between: 1, 2, 3 \r\n", choice);
	MOVLW 138
	BCF   0x03,RP0
	BCF   0x03,RP1
	MOVWF string
	MOVF  choice,W
	CALL  printf
			;			 //printf(getchar_eedata(1), 0);
			;         }
			;		 nop();
m013	NOP  
			;      }
			;	  
			;nop();
m014	NOP  
			;choice = save;
	BCF   0x03,RP0
	BCF   0x03,RP1
	MOVF  save,W
	MOVWF choice
			;nop();
	NOP  
			; switch (choice)
	MOVF  choice,W
	XORLW 49
	BTFSC 0x03,Zero_
	GOTO  m015
	XORLW 3
	BTFSC 0x03,Zero_
	GOTO  m016
	XORLW 1
	BTFSC 0x03,Zero_
	GOTO  m017
	XORLW 91
	BTFSC 0x03,Zero_
	GOTO  m018
	GOTO  m018
			;         {
			;          case '1':
			;		 
			;           power_on();
m015	CALL  power_on
			;		   //putchar_eedata((char) PORTB.6,1);
			;		   nop();
	NOP  
			;		  
			;           break;
	GOTO  m018
			;          case '2':
			;		  nop();
m016	NOP  
			;           power_off();
	CALL  power_off
			;		   nop();
	NOP  
			;		  // putchar_eedata((char) PORTB.6,1);
			;           break;
	GOTO  m018
			;          case '3':
			;          direc_change();
m017	CALL  direc_change
			;           break;
			;   case 'h':
			;  
			;   break;
			;          default:
			;		  
			;			 
			;			 //printf(getchar_eedata(1), 0);
			;         }
			;		 nop();
m018	NOP  
			;	  }
	GOTO  m008
			;     /* if no Character is received we always loop here */
			;//*******************************************************************************************//
			;
			;
			;
			;	
			;	
			;   // reposition to "line 2" (the next 8 chars)
			;   // RS = 0;  // LCD in command-mode
			;    //lcd_putchar( 0b11000000 );
			;  
			;    //RS = 1;  // LCD in character-mode
			;    // display the 8 char text2() sentence
			;  // for(i=0; i<8; i++) lcd_putchar(text2(i));	
			;	
			;	
			; 
			;
			;}
			;//***************************************************************************************************************************************************************************************************//
			;void power_off(void){
power_off
			; 
			;CCP1CON = 0b00.00.0000 ; 
	BCF   0x03,RP0
	BCF   0x03,RP1
	CLRF  CCP1CON
			;}
	RETURN
			;void direc_change(void){
direc_change
			;CCP1CON = 0b11.00.1100 ; 
	MOVLW 204
	BCF   0x03,RP0
	BCF   0x03,RP1
	MOVWF CCP1CON
			;}
	RETURN
			;
			;void lcd_poweron(void){
lcd_poweron
			;int i;
			;
			;    RS = 0;  // LCD in command-mode
	BCF   0x03,RP0
	BCF   0x03,RP1
	BCF   0x06,RS
			;    lcd_putchar(0b00000001); 
	MOVLW 1
	CALL  lcd_putchar
			;	
			;RS = 1;  // LCD in character-mode
	BCF   0x03,RP0
	BCF   0x03,RP1
	BSF   0x06,RS
			;    // display the 8 char text1() sentence
			;    for(i=0; i<8; i++) lcd_putchar(text1(i)); 
	CLRF  i_2
m019	BCF   0x03,RP0
	BCF   0x03,RP1
	BTFSC i_2,7
	GOTO  m020
	MOVLW 8
	SUBWF i_2,W
	BTFSC 0x03,Carry
	GOTO  m021
m020	BCF   0x03,RP0
	BCF   0x03,RP1
	MOVF  i_2,W
	CALL  text1
	CALL  lcd_putchar
	BCF   0x03,RP0
	BCF   0x03,RP1
	INCF  i_2,1
	GOTO  m019
			;	RS = 0;
m021	BCF   0x03,RP0
	BCF   0x03,RP1
	BCF   0x06,RS
			;}
	RETURN
			;
			;void lcd_poweroff(void){
lcd_poweroff
			;int i;
			;
			;    RS = 0;  // LCD in command-mode
	BCF   0x03,RP0
	BCF   0x03,RP1
	BCF   0x06,RS
			;    lcd_putchar(0b00000001); 
	MOVLW 1
	CALL  lcd_putchar
			;	
			;RS = 1;  // LCD in character-mode
	BCF   0x03,RP0
	BCF   0x03,RP1
	BSF   0x06,RS
			;    // display the 8 char text1() sentence
			;    for(i=0; i<8; i++) lcd_putchar(text3(i)); 
	CLRF  i_3
m022	BTFSC i_3,7
	GOTO  m023
	MOVLW 8
	SUBWF i_3,W
	BTFSC 0x03,Carry
	GOTO  m024
m023	MOVF  i_3,W
	CALL  text3
	CALL  lcd_putchar
	INCF  i_3,1
	GOTO  m022
			;RS = 0;
m024	BCF   0x03,RP0
	BCF   0x03,RP1
	BCF   0x06,RS
			;}
	RETURN
			;
			;void power_on(void){
power_on
			;CCP1CON = 0b01.00.1100 ; 
	MOVLW 76
	BCF   0x03,RP0
	BCF   0x03,RP1
	MOVWF CCP1CON
			;}
	RETURN
			;
			;char text1( char x)   // this is the way to store a sentence
			;{
text1
	BCF   0x03,RP0
	BCF   0x03,RP1
	MOVWF x
			;   skip(x); /* internal function CC5x.  */
	MOVLW 1
	MOVWF PCLATH
	MOVF  x,W
	ADDWF PCL,1
			;   #pragma return[] = "Power on"    // 8 chars max!
	RETLW 80
	RETLW 111
	RETLW 119
	RETLW 101
	RETLW 114
	RETLW 32
	RETLW 111
	RETLW 110
			;}
			;
			;char text2( char x)   // this is the way to store a sentence
			;{
text2
	MOVWF x_2
			;   skip(x); /* internal function CC5x.  */
	MOVLW 1
	MOVWF PCLATH
	MOVF  x_2,W
	ADDWF PCL,1
			;   #pragma return[] = ""    // 8 chars max!
			;}
			;char text3( char x)   // this is the way to store a sentence
			;{
text3
	MOVWF x_3
			;   skip(x); /* internal function CC5x.  */
	MOVLW 1
	MOVWF PCLATH
	MOVF  x_3,W
	ADDWF PCL,1
			;   #pragma return[] = "Power off"    // 8 chars max!
	RETLW 80
	RETLW 111
	RETLW 119
	RETLW 101
	RETLW 114
	RETLW 32
	RETLW 111
	RETLW 102
	RETLW 102
			;}
			;char text4( char x)   // this is the way to store a sentence
			;{
text4
	MOVWF x_4
			;   skip(x); /* internal function CC5x.  */
	MOVLW 1
	MOVWF PCLATH
	MOVF  x_4,W
	ADDWF PCL,1
			;   #pragma return[] = ""    // 8 chars max!
			;}
			;void init_serial( void )  /* initialise PIC16F690 bitbang serialcom */
			;{
init_serial
			;   ANSEL.0 = 0; /* No AD on RA0             */
	BCF   0x03,RP0
	BSF   0x03,RP1
	BCF   ANSEL,0
			;   ANSEL.1 = 0; /* No AD on RA1             */
	BCF   ANSEL,1
			;   PORTA.0 = 1; /* marking line             */
	BCF   0x03,RP1
	BSF   PORTA,0
			;   TRISA.0 = 0; /* output to PK2 UART-tool  */
	BSF   0x03,RP0
	BCF   TRISA,0
			;   TRISA.1 = 1; /* input from PK2 UART-tool */
	BSF   TRISA,1
			;   receiver_flag = 0 ;
	BCF   0x03,RP0
	BCF   0x32,receiver_flag
			;   return;      
	RETURN
			;}
			;
			;void init_interrupt( void )
			;{
init_interrupt
			;  IOCA.1 = 1; /* PORTA.1 interrupt on change */
	BSF   0x03,RP0
	BCF   0x03,RP1
	BSF   IOCA,1
			;  RABIE =1;   /* interrupt on change         */
	BSF   0x0B,RABIE
			;  GIE = 1;    /* interrupt enable            */
	BSF   0x0B,GIE
			;  return;
	RETURN
			;}
			;
			;void lcd_init( void ) // must be run once before using the display
			;{
lcd_init
			;  delay(40);  // give LCD time to settle
	MOVLW 40
	CALL  delay
			;  RS = 0;     // LCD in command-mode
	BCF   0x03,RP0
	BCF   0x03,RP1
	BCF   0x06,RS
			;  lcd_putchar(0b0011.0011); /* LCD starts in 8 bit mode          */
	MOVLW 51
	CALL  lcd_putchar
			;  lcd_putchar(0b0011.0010); /* change to 4 bit mode              */
	MOVLW 50
	CALL  lcd_putchar
			;  lcd_putchar(0b00101000);  /* two line (8+8 chars in the row)   */ 
	MOVLW 40
	CALL  lcd_putchar
			;  lcd_putchar(0b00001100);  /* display on, cursor off, blink off */
	MOVLW 12
	CALL  lcd_putchar
			;  lcd_putchar(0b00000001);  /* display clear                     */
	MOVLW 1
	CALL  lcd_putchar
			;  lcd_putchar(0b00000110);  /* increment mode, shift off         */
	MOVLW 6
	CALL  lcd_putchar
			;  RS = 1;    // LCD in character-mode
	BCF   0x03,RP0
	BCF   0x03,RP1
	BSF   0x06,RS
			;             // initialization is done!
			;}
	RETURN
			;
			;void putchar( char ch )  /* sends one char */
			;{
putchar
	BCF   0x03,RP0
	BCF   0x03,RP1
	MOVWF ch
			;  char bitCount, ti;
			;  PORTA.0 = 0; /* set startbit */
	BCF   PORTA,0
			;  for ( bitCount = 10; bitCount > 0 ; bitCount-- )
	MOVLW 10
	MOVWF bitCount_2
m025	BCF   0x03,RP0
	BCF   0x03,RP1
	MOVF  bitCount_2,1
	BTFSC 0x03,Zero_
	GOTO  m027
			;   {
			;     /* delay one bit 104 usec at 4 MHz       */
			;     /* 5+18*5-1+1+9=104 without optimization */ 
			;     ti = 18; do ; while( --ti > 0); nop(); 
	MOVLW 18
	MOVWF ti_2
m026	BCF   0x03,RP0
	BCF   0x03,RP1
	DECFSZ ti_2,1
	GOTO  m026
	NOP  
			;     Carry = 1;     /* stopbit                    */
	BSF   0x03,Carry
			;     ch = rr( ch ); /* Rotate Right through Carry */
	RRF   ch,1
			;     PORTA.0 = Carry;
	BTFSS 0x03,Carry
	BCF   PORTA,0
	BTFSC 0x03,Carry
	BSF   PORTA,0
			;   }
	DECF  bitCount_2,1
	GOTO  m025
			;  return;
m027	RETURN
			;}
			;
			;void lcd_putchar( char data )
			;{
lcd_putchar
	BCF   0x03,RP0
	BCF   0x03,RP1
	MOVWF data
			;  // must set LCD-mode before calling this function!
			;  // RS = 1 LCD in character-mode
			;  // RS = 0 LCD in command-mode
			;  // upper Nybble
			;  D7 = data.7;
	BTFSS data,7
	BCF   0x07,D7
	BTFSC data,7
	BSF   0x07,D7
			;  D6 = data.6;
	BTFSS data,6
	BCF   0x07,D6
	BTFSC data,6
	BSF   0x07,D6
			;  D5 = data.5;
	BTFSS data,5
	BCF   0x07,D5
	BTFSC data,5
	BSF   0x07,D5
			;  D4 = data.4;
	BTFSS data,4
	BCF   0x07,D4
	BTFSC data,4
	BSF   0x07,D4
			;  EN = 0;
	BCF   0x06,EN
			;  nop();
	NOP  
			;  EN = 1;
	BSF   0x06,EN
			;  delay(5);
	MOVLW 5
	CALL  delay
			;  // lower Nybble
			;  D7 = data.3;
	BCF   0x03,RP0
	BCF   0x03,RP1
	BTFSS data,3
	BCF   0x07,D7
	BTFSC data,3
	BSF   0x07,D7
			;  D6 = data.2;
	BTFSS data,2
	BCF   0x07,D6
	BTFSC data,2
	BSF   0x07,D6
			;  D5 = data.1;
	BTFSS data,1
	BCF   0x07,D5
	BTFSC data,1
	BSF   0x07,D5
			;  D4 = data.0;
	BTFSS data,0
	BCF   0x07,D4
	BTFSC data,0
	BSF   0x07,D4
			;  EN = 0;
	BCF   0x06,EN
			;  nop();
	NOP  
			;  EN = 1;
	BSF   0x06,EN
			;  delay(5);
	MOVLW 5
	GOTO  delay
			;}
			;void printf(const char *string, char variable)
			;{
printf
	BCF   0x03,RP0
	BCF   0x03,RP1
	MOVWF variable
			;  char i, k, m, a, b;
			;  for(i = 0 ; ; i++)
	CLRF  i_4
			;   {
			;     k = string[i];
m028	BCF   0x03,RP0
	BCF   0x03,RP1
	MOVF  i_4,W
	ADDWF string,W
	CALL  _const1
	BCF   0x03,RP0
	BCF   0x03,RP1
	MOVWF k
			;     if( k == '\0') break;   // at end of string
	MOVF  k,1
	BTFSC 0x03,Zero_
	GOTO  m050
			;     if( k == '%')           // insert variable in string
	BCF   0x03,RP0
	BCF   0x03,RP1
	MOVF  k,W
	XORLW 37
	BTFSS 0x03,Zero_
	GOTO  m048
			;      {
			;        i++;
	INCF  i_4,1
			;        k = string[i];
	MOVF  i_4,W
	ADDWF string,W
	CALL  _const1
	BCF   0x03,RP0
	BCF   0x03,RP1
	MOVWF k
			;        switch(k)
	MOVF  k,W
	XORLW 100
	BTFSC 0x03,Zero_
	GOTO  m029
	XORLW 17
	BTFSC 0x03,Zero_
	GOTO  m032
	XORLW 23
	BTFSC 0x03,Zero_
	GOTO  m041
	XORLW 1
	BTFSC 0x03,Zero_
	GOTO  m045
	XORLW 70
	BTFSC 0x03,Zero_
	GOTO  m046
	GOTO  m047
			;         {
			;           case 'd':         // %d  signed 8bit
			;             if( variable.7 ==1) putchar('-');
m029	BCF   0x03,RP0
	BCF   0x03,RP1
	BTFSS variable,7
	GOTO  m030
	MOVLW 45
	CALL  putchar
			;             else putchar(' ');
	GOTO  m031
m030	MOVLW 32
	CALL  putchar
			;             if( variable > 127) variable = -variable;  // no break!
m031	MOVLW 128
	BCF   0x03,RP0
	BCF   0x03,RP1
	SUBWF variable,W
	BTFSS 0x03,Carry
	GOTO  m032
	COMF  variable,1
	INCF  variable,1
			;           case 'u':         // %u unsigned 8bit
			;             a = variable/100;
m032	BCF   0x03,RP0
	BCF   0x03,RP1
	MOVF  variable,W
	MOVWF C2tmp
	CLRF  C3rem
	MOVLW 8
	MOVWF C1cnt
m033	BCF   0x03,RP0
	BCF   0x03,RP1
	RLF   C2tmp,1
	RLF   C3rem,1
	MOVLW 100
	SUBWF C3rem,W
	BTFSS 0x03,Carry
	GOTO  m034
	MOVLW 100
	BCF   0x03,RP0
	BCF   0x03,RP1
	SUBWF C3rem,1
	BSF   0x03,Carry
m034	BCF   0x03,RP0
	BCF   0x03,RP1
	RLF   a,1
	DECFSZ C1cnt,1
	GOTO  m033
			;             putchar('0'+a); // print 100's
	MOVLW 48
	ADDWF a,W
	CALL  putchar
			;             b = variable%100;
	BCF   0x03,RP0
	BCF   0x03,RP1
	MOVF  variable,W
	MOVWF C5tmp
	CLRF  b
	MOVLW 8
	MOVWF C4cnt
m035	BCF   0x03,RP0
	BCF   0x03,RP1
	RLF   C5tmp,1
	RLF   b,1
	MOVLW 100
	SUBWF b,W
	BTFSS 0x03,Carry
	GOTO  m036
	MOVLW 100
	BCF   0x03,RP0
	BCF   0x03,RP1
	SUBWF b,1
m036	BCF   0x03,RP0
	BCF   0x03,RP1
	DECFSZ C4cnt,1
	GOTO  m035
			;             a = b/10;
	MOVF  b,W
	MOVWF C7tmp
	CLRF  C8rem
	MOVLW 8
	MOVWF C6cnt
m037	BCF   0x03,RP0
	BCF   0x03,RP1
	RLF   C7tmp,1
	RLF   C8rem,1
	MOVLW 10
	SUBWF C8rem,W
	BTFSS 0x03,Carry
	GOTO  m038
	MOVLW 10
	BCF   0x03,RP0
	BCF   0x03,RP1
	SUBWF C8rem,1
	BSF   0x03,Carry
m038	BCF   0x03,RP0
	BCF   0x03,RP1
	RLF   a,1
	DECFSZ C6cnt,1
	GOTO  m037
			;             putchar('0'+a); // print 10's
	MOVLW 48
	ADDWF a,W
	CALL  putchar
			;             a = b%10;        
	BCF   0x03,RP0
	BCF   0x03,RP1
	MOVF  b,W
	MOVWF C10tmp
	CLRF  a
	MOVLW 8
	MOVWF C9cnt
m039	BCF   0x03,RP0
	BCF   0x03,RP1
	RLF   C10tmp,1
	RLF   a,1
	MOVLW 10
	SUBWF a,W
	BTFSS 0x03,Carry
	GOTO  m040
	MOVLW 10
	BCF   0x03,RP0
	BCF   0x03,RP1
	SUBWF a,1
m040	BCF   0x03,RP0
	BCF   0x03,RP1
	DECFSZ C9cnt,1
	GOTO  m039
			;             putchar('0'+a); // print 1's
	MOVLW 48
	ADDWF a,W
	CALL  putchar
			;             break;
	GOTO  m049
			;           case 'b':         // %b BINARY 8bit
			;             for( m = 0 ; m < 8 ; m++ )
m041	BCF   0x03,RP0
	BCF   0x03,RP1
	CLRF  m
m042	MOVLW 8
	BCF   0x03,RP0
	BCF   0x03,RP1
	SUBWF m,W
	BTFSC 0x03,Carry
	GOTO  m049
			;              {
			;                if (variable.7 == 1) putchar('1');
	BTFSS variable,7
	GOTO  m043
	MOVLW 49
	CALL  putchar
			;                else putchar('0');
	GOTO  m044
m043	MOVLW 48
	CALL  putchar
			;                variable = rl(variable);
m044	BCF   0x03,RP0
	BCF   0x03,RP1
	RLF   variable,1
			;               }
	INCF  m,1
	GOTO  m042
			;              break;
			;           case 'c':         // %c  'char'
			;             putchar(variable);
m045	BCF   0x03,RP0
	BCF   0x03,RP1
	MOVF  variable,W
	CALL  putchar
			;             break;
	GOTO  m049
			;           case '%':
			;             putchar('%');
m046	MOVLW 37
	CALL  putchar
			;             break;
	GOTO  m049
			;           default:          // not implemented
			;             putchar('!');  
m047	MOVLW 33
	CALL  putchar
			;         }  
			;      }
			;      else putchar(k);
	GOTO  m049
m048	BCF   0x03,RP0
	BCF   0x03,RP1
	MOVF  k,W
	CALL  putchar
			;   }
m049	BCF   0x03,RP0
	BCF   0x03,RP1
	INCF  i_4,1
	GOTO  m028
			;}
m050	RETURN
			;
			;void delay( char millisec)
			;/* 
			;  Delays a multiple of 1 milliseconds at 4 MHz (16F628 internal clock)
			;  using the TMR0 timer 
			;*/
			;{
delay
	BCF   0x03,RP0
	BCF   0x03,RP1
	MOVWF millisec
			;    OPTION = 2;  /* prescaler divide by 8        */
	MOVLW 2
	BSF   0x03,RP0
	MOVWF OPTION_REG
			;    do  {
			;        TMR0 = 0;
m051	BCF   0x03,RP0
	BCF   0x03,RP1
	CLRF  TMR0
			;        while ( TMR0 < 125)   /* 125 * 8 = 1000  */
m052	MOVLW 125
	BCF   0x03,RP0
	BCF   0x03,RP1
	SUBWF TMR0,W
	BTFSS 0x03,Carry
			;            ;
	GOTO  m052
			;    } while ( -- millisec > 0);
	BCF   0x03,RP0
	BCF   0x03,RP1
	DECFSZ millisec,1
	GOTO  m051
			;}
	RETURN
			;void putchar_eedata( char data, char adress )
			;{
putchar_eedata
	MOVWF adress
			;/* Put char in specific EEPROM-adress */
			;      /* Write EEPROM-data sequence                          */
			;      EEADR = adress;     /* EEPROM-data adress 0x00 => 0x40 */
	MOVF  adress,W
	BCF   0x03,RP0
	BSF   0x03,RP1
	MOVWF EEADR
			;      EEPGD = 0;          /* Data, not Program memory        */  
	BSF   0x03,RP0
	BCF   0x18C,EEPGD
			;      EEDATA = data;      /* data to be written              */
	MOVF  data_2,W
	BCF   0x03,RP0
	MOVWF EEDATA
			;      WREN = 1;           /* write enable                    */
	BSF   0x03,RP0
	BSF   0x18C,WREN
			;      EECON2 = 0x55;      /* first Byte in comandsequence    */
	MOVLW 85
	MOVWF EECON2
			;      EECON2 = 0xAA;      /* second Byte in comandsequence   */
	MOVLW 170
	MOVWF EECON2
			;      WR = 1;             /* write                           */
	BSF   0x18C,WR
			;      while( EEIF == 0) ; /* wait for done (EEIF=1)          */
m053	BCF   0x03,RP0
	BCF   0x03,RP1
	BTFSS 0x0D,EEIF
	GOTO  m053
			;      WR = 0;
	BSF   0x03,RP0
	BSF   0x03,RP1
	BCF   0x18C,WR
			;      WREN = 0;           /* write disable - safety first    */
	BCF   0x18C,WREN
			;      EEIF = 0;           /* Reset EEIF bit in software      */
	BCF   0x03,RP0
	BCF   0x03,RP1
	BCF   0x0D,EEIF
			;      /* End of write EEPROM-data sequence                   */
			;}
	RETURN
			;
			;
			;char getchar_eedata( char adress )
			;{
getchar_eedata
	MOVWF adress_2
			;/* Get char from specific EEPROM-adress */
			;      /* Start of read EEPROM-data sequence                */
			;      char temp;
			;      EEADR = adress;  /* EEPROM-data adress 0x00 => 0x40  */ 
	MOVF  adress_2,W
	BCF   0x03,RP0
	BSF   0x03,RP1
	MOVWF EEADR
			;      EEPGD = 0;       /* Data not Program -memory         */      
	BSF   0x03,RP0
	BCF   0x18C,EEPGD
			;      RD = 1;          /* Read                             */
	BSF   0x18C,RD
			;      temp = EEDATA;
	BCF   0x03,RP0
	MOVF  EEDATA,W
	MOVWF temp
			;      RD = 0;
	BSF   0x03,RP0
	BCF   0x18C,RD
			;      return temp;     /* data to be read                  */
	MOVF  temp,W
	RETURN

	END


; *** KEY INFO ***

; 0x019A P0   12 word(s)  0 % : init_serial
; 0x01A6 P0    6 word(s)  0 % : init_interrupt
; 0x02DA P0   20 word(s)  0 % : delay
; 0x01AC P0   21 word(s)  1 % : lcd_init
; 0x01DC P0   47 word(s)  2 % : lcd_putchar
; 0x0173 P0   15 word(s)  0 % : text1
; 0x0182 P0    5 word(s)  0 % : text2
; 0x0187 P0   14 word(s)  0 % : text3
; 0x0195 P0    5 word(s)  0 % : text4
; 0x01C1 P0   27 word(s)  1 % : putchar
; 0x016E P0    5 word(s)  0 % : power_on
; 0x012F P0    4 word(s)  0 % : power_off
; 0x020B P0  207 word(s) 10 % : printf
; 0x0138 P0   30 word(s)  1 % : lcd_poweron
; 0x0156 P0   24 word(s)  1 % : lcd_poweroff
; 0x030B P0   15 word(s)  0 % : getchar_eedata
; 0x02EE P0   29 word(s)  1 % : putchar_eedata
; 0x0133 P0    5 word(s)  0 % : direc_change
; 0x0004 P0   53 word(s)  2 % : int_server
; 0x00B3 P0  124 word(s)  6 % : main
; 0x0039 P0  122 word(s)  5 % : _const1

; RAM usage: 21 bytes (19 local), 235 bytes free
; Maximum call level: 3 (+1 for interrupt)
;  Codepage 0 has  791 word(s) :  38 %
;  Codepage 1 has    0 word(s) :   0 %
; Total of 791 code words (19 %)
