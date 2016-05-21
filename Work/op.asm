
; CC5X Version 3.4H, Copyright (c) B Knudsen Data
; C compiler for the PICmicro family
; ************  21. May 2016  14:53  *************

	processor  16F690
	radix  DEC

	__config 0xD4

TMR0        EQU   0x01
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
EN_DC       EQU   5
TREN_DC     EQU   5
DR_DC       EQU   7
TRDR_DC     EQU   7
receiver_flag EQU   0
receiver_byte EQU   0x34
svrWREG     EQU   0x70
svrSTATUS   EQU   0x20
svrPCLATH   EQU   0x21
bitCount    EQU   0x22
ti          EQU   0x23
choice      EQU   0x24
cnt         EQU   0x25
s           EQU   0x26
save        EQU   0x28
s_2         EQU   0x29
start       EQU   0x29
text        EQU   0x2A
i_2         EQU   0x2B
k           EQU   0x2C
data        EQU   0x2D
ch          EQU   0x30
bitCount_2  EQU   0x31
ti_2        EQU   0x32
string      EQU   0x29
variable    EQU   0x2A
i_3         EQU   0x2B
k_2         EQU   0x2C
m           EQU   0x2D
a           EQU   0x2E
b           EQU   0x2F
C1cnt       EQU   0x30
C2tmp       EQU   0x31
C3rem       EQU   0x32
C4cnt       EQU   0x30
C5tmp       EQU   0x31
C6cnt       EQU   0x30
C7tmp       EQU   0x31
C8rem       EQU   0x32
C9cnt       EQU   0x30
C10tmp      EQU   0x31
millisec    EQU   0x2E
data_2      EQU   0x7F
adress      EQU   0x7F
adress_2    EQU   0x7F
temp        EQU   0x7F
ci          EQU   0x30

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
			;#pragma bit DR_DC  @ PORTB.7
			;#pragma bit TRDR_DC  @ TRISB.7
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
			;void lcd_putline(char start, const char * text);
			;//char text1( char );
			;//char text2( char );
			;//char text3( char );
			;//char text4( char );
			;void putchar( char );
			;char getchar( void );
			;void force_stop(void);
			;void power_on(void);
			;void power_off(void);
			;void printf(const char *string, char variable);
			;//void lcd_poweron(void);
			;//void lcd_poweroff(void);
			;char getchar_eedata( char adress );
			;void putchar_eedata( char data, char adress );
			;int direc_change();
			;void lcd_reset(void);
			;//******************************************************************************//
			;
			;/*interupt*/
			;/* FOR INPUT CHARACTOR FROM  PC WITH UART BITBANING*/
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
	BSF   0x33,receiver_flag
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
			;/*MAIN*/
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
	DW    0x3749
	DW    0x3A69
	DW    0x30E9
	DW    0x34EC
	DW    0x30FA
	DW    0x34F4
	DW    0x376F
	DW    0x31A0
	DW    0x36EF
	DW    0x3670
	DW    0x3A65
	DW    0x6E5
	DW    0xA
	DW    0x32CD
	DW    0x3AEE
	DW    0x103A
	DW    0x1631
	DW    0x1920
	DW    0x102C
	DW    0x1633
	DW    0x1A20
	DW    0x102C
	DW    0x6E8
	DW    0xA
	DW    0x37D0
	DW    0x32F7
	DW    0x1072
	DW    0x376F
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
	DW    0x37D0
	DW    0x32F7
	DW    0x1072
	DW    0x336F
	DW    0x66
	DW    0x31A5
	DW    0x2820
	DW    0x3BEF
	DW    0x3965
	DW    0x37A0
	DW    0x3366
	DW    0x50D
	DW    0x2180
	DW    0x37EC
	DW    0x35E3
	DW    0x34F7
	DW    0x32F3
	DW    0x3180
	DW    0x34F4
	DW    0x376F
	DW    0x3080
	DW    0x3A6E
	DW    0x31E9
	DW    0x37EC
	DW    0x35E3
	DW    0x34F7
	DW    0x32F3
	DW    0x3200
	DW    0x3969
	DW    0x31E5
	DW    0x74
	DW    0x31A5
	DW    0x2220
	DW    0x3969
	DW    0x31E5
	DW    0x34F4
	DW    0x376F
	DW    0x31A0
	DW    0x30E8
	DW    0x33EE
	DW    0x3265
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
	DW    0x1633
	DW    0x1A20
	DW    0x102C
	DW    0x50D
	DW    0x0
main
			; char choice;  int cnt = 0;
	BCF   0x03,RP0
	BCF   0x03,RP1
	CLRF  cnt
			; //***********************************************************//  
			; /*initialize*/
			;init_serial();
	CALL  init_serial
			;nop();
	NOP  
			; init_interrupt(); 
	CALL  init_interrupt
			; nop();
	NOP  
			;  /* You should "connect" PK2 UART-tool in one second after power on! */
			;  delay(256); 
	MOVLW 0
	CALL  delay
			;  delay(100);
	MOVLW 100
	CALL  delay
			;  //***************************************************************//
			; /*PWM INIT*/
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
			;   delay(100);
	MOVLW 100
	CALL  delay
			;     /*LCD IO INIT*/
			;/* I/O-pin direction in/out definitions, change if needed  */
			;	ANSEL=0; 	//  PORTC digital I/O
	BCF   0x03,RP0
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
			;nop();
	NOP  
			;lcd_init();
	CALL  lcd_init
			;delay(100);
	MOVLW 100
	CALL  delay
			;//************************************************************************************// 
			;    printf("Initialization complete\r\n",0);
	BCF   0x03,RP0
	BCF   0x03,RP1
	CLRF  string
	MOVLW 0
	CALL  printf
			;//************************************************************************************//
			;int s;
			;
			;
			;char i;
			;  printf("Menu: 1, 2, 3, 4, h\r\n",0);
	MOVLW 26
	BCF   0x03,RP0
	BCF   0x03,RP1
	MOVWF string
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
	BTFSS 0x33,receiver_flag
	GOTO  m017
			;      {
			;	 /*initialize flages and save choice value to the swtich later (PWM)*/
			;        choice = receiver_byte; /* get Character from interrupt routine */
	MOVF  receiver_byte,W
	MOVWF choice
			;        receiver_flag = 0;      /* Character now taken - reset the flag */
	BCF   0x33,receiver_flag
			;		 save = choice;
	MOVF  choice,W
	MOVWF save
			;		 //force stop
			;
			;		/* NON-LOOP SEQUENCE*/
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
	XORLW 7
	BTFSC 0x03,Zero_
	GOTO  m014
	GOTO  m015
			;         {
			;          case '1':
			;		  TREN_DC=1;
m009	BSF   0x03,RP0
	BCF   0x03,RP1
	BSF   0x87,TREN_DC
			;		  nop();
	NOP  
			;		  lcd_reset();
	CALL  lcd_reset
			;		   nop();
	NOP  
			;		   lcd_putline(0,"Power on");
	BCF   0x03,RP0
	BCF   0x03,RP1
	CLRF  start
	MOVLW 48
	MOVWF text
	CALL  lcd_putline
			;		   delay(10);
	MOVLW 10
	CALL  delay
			;           printf("%c The power is now on. Press a to abort to main menu.\r\n", choice);
	MOVLW 57
	BCF   0x03,RP0
	BCF   0x03,RP1
	MOVWF string
	MOVF  choice,W
	CALL  printf
			;		   nop();
	NOP  
			;		   TREN_DC=0;
	BSF   0x03,RP0
	BCF   0x03,RP1
	BCF   0x87,TREN_DC
			;		   nop();
	NOP  
			;           break;
	GOTO  m016
			;          case '2':
			;		  nop();
m010	NOP  
			;           power_off();
	CALL  power_off
			;		   nop();
	NOP  
			;		  TREN_DC=0;
	BSF   0x03,RP0
	BCF   0x03,RP1
	BCF   0x87,TREN_DC
			;		  lcd_reset();
	CALL  lcd_reset
			;		 nop();
	NOP  
			;		 lcd_putline(0x0,"Power off");
	BCF   0x03,RP0
	BCF   0x03,RP1
	CLRF  start
	MOVLW 114
	MOVWF text
	CALL  lcd_putline
			;		 
			;		  lcd_putline(0x8,"f");
	MOVLW 8
	BCF   0x03,RP0
	BCF   0x03,RP1
	MOVWF start
	MOVLW 122
	MOVWF text
	CALL  lcd_putline
			;		   delay(10);
	MOVLW 10
	CALL  delay
			;           printf("%c Power off\r\n", choice);
	MOVLW 124
	BCF   0x03,RP0
	BCF   0x03,RP1
	MOVWF string
	MOVF  choice,W
	CALL  printf
			;		   nop();
	NOP  
			;		   TREN_DC=1;
	BSF   0x03,RP0
	BCF   0x03,RP1
	BSF   0x87,TREN_DC
			;           break;
	GOTO  m016
			;          case '3':
			;		  s=direc_change();
m011	CALL  direc_change
	BCF   0x03,RP0
	BCF   0x03,RP1
	MOVF  s_2,W
	MOVWF s
			;		  /*SWITCH MODE PWM OFF, PUSH 1 INESTEAD INCASE JAMMING LCD SIGNAL*/
			;		    CCP1CON = 0b00.00.0000 ;
	CLRF  CCP1CON
			;          TREN_DC=0;		  
	BSF   0x03,RP0
	BCF   0x87,TREN_DC
			;          EN_DC=1;
	BCF   0x03,RP0
	BSF   0x07,EN_DC
			;		  /*LCD OPORATION*/
			;		  nop();
	NOP  
			;		  lcd_reset();
	CALL  lcd_reset
			;		   nop();
	NOP  
			;		   if (s ==1){
	BCF   0x03,RP0
	BCF   0x03,RP1
	DECFSZ s,W
	GOTO  m012
			;		  lcd_putline(0x0,"Clockwise");
	CLRF  start
	MOVLW 139
	MOVWF text
	CALL  lcd_putline
			;		  lcd_putline(0x8,"ction");
	MOVLW 8
	BCF   0x03,RP0
	BCF   0x03,RP1
	MOVWF start
	MOVLW 149
	MOVWF text
	CALL  lcd_putline
			;		  }
			;		  if (s ==0){
m012	BCF   0x03,RP0
	BCF   0x03,RP1
	MOVF  s,1
	BTFSS 0x03,Zero_
	GOTO  m013
			;		  lcd_putline(0x0,"anticlockwise");
	CLRF  start
	MOVLW 155
	MOVWF text
	CALL  lcd_putline
			;		  lcd_putline(0x8,"direct");
	MOVLW 8
	BCF   0x03,RP0
	BCF   0x03,RP1
	MOVWF start
	MOVLW 169
	MOVWF text
	CALL  lcd_putline
			;		  }
			;		  power_on();
m013	CALL  power_on
			;           printf("%c Direction changed \r\n", choice);
	MOVLW 176
	BCF   0x03,RP0
	BCF   0x03,RP1
	MOVWF string
	MOVF  choice,W
	CALL  printf
			;           //printf("%u\r\n", (char) PORTB.6);
			;           break;
	GOTO  m016
			;		case '4':
			;		//PORTC.4=1;
			;       nop();
m014	NOP  
			;		break;
	GOTO  m016
			;          default:
			;		//PORTC.4=0;
			;           printf("%c You must choose between: 1, 2, 3, 4, \r\n", choice);
m015	MOVLW 200
	BCF   0x03,RP0
	BCF   0x03,RP1
	MOVWF string
	MOVF  choice,W
	CALL  printf
			;			 //printf(getchar_eedata(1), 0);
			;         }
			;		 nop();
m016	NOP  
			;      }
			;/*reload save value*/	  
			;nop();
m017	NOP  
			;choice = save;
	BCF   0x03,RP0
	BCF   0x03,RP1
	MOVF  save,W
	MOVWF choice
			;nop();
	NOP  
			;
			;/*PWM oporation*/
			; switch (choice)
	MOVF  choice,W
	XORLW 49
	BTFSC 0x03,Zero_
	GOTO  m018
	XORLW 3
	BTFSC 0x03,Zero_
	GOTO  m022
	XORLW 1
	BTFSC 0x03,Zero_
	GOTO  m019
	XORLW 7
	BTFSC 0x03,Zero_
	GOTO  m020
	GOTO  m021
			;         {
			;          case '1':
			;		 nop();
m018	NOP  
			;           power_on();
	CALL  power_on
			;		   //putchar_eedata((char) PORTB.6,1);
			;		   nop();
	NOP  
			;           break;
	GOTO  m022
			;          case '2':
			;		  /*
			;		  nop();
			;           power_off();
			;		   nop();
			;		   */
			;		  // putchar_eedata((char) PORTB.6,1);
			;           break;
			;          case '3':
			;          DR_DC=s;
m019	BCF   0x03,RP0
	BCF   0x03,RP1
	MOVF  s,W
	BTFSS 0x03,Zero_
	BSF   0x06,DR_DC
	BTFSC 0x03,Zero_
	BCF   0x06,DR_DC
			;           break;
	GOTO  m022
			;				case '4':
			;				
			;nop();
m020	NOP  
			;		break;
	GOTO  m022
			;  
			;   
			;   
			;          default:
			;
			;		  nop();
m021	NOP  
			;			 
			;			 //printf(getchar_eedata(1), 0);
			;         }
			;		 nop();
m022	NOP  
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
			;//library
			;//***************************************************************************************************************************************************************************************************//
			;/*PWM ACTION*/
			;
			;void power_off(void){
power_off
			;CCP1CON = 0b00.00.0000 ; 
	BCF   0x03,RP0
	BCF   0x03,RP1
	CLRF  CCP1CON
			;EN_DC=0;
	BCF   0x07,EN_DC
			;}
	RETURN
			;int direc_change(){
direc_change
			;int s;
			;nop();
	NOP  
			;		  TRDR_DC=0;
	BSF   0x03,RP0
	BCF   0x03,RP1
	BCF   0x86,TRDR_DC
			;		  if(DR_DC==1){
	BCF   0x03,RP0
	BTFSS 0x06,DR_DC
	GOTO  m023
			;		  s=0;
	CLRF  s_2
			;		  }
			;		  else{
	GOTO  m024
			;		  s=1;
m023	MOVLW 1
	BCF   0x03,RP0
	BCF   0x03,RP1
	MOVWF s_2
			;		  }
			;		  nop();
m024	NOP  
			;		  return s;
	BCF   0x03,RP0
	BCF   0x03,RP1
	MOVF  s_2,W
	RETURN
			;}
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
			;/*INITIALIZATION*/
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
	BCF   0x33,receiver_flag
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
			;  nop();
	NOP  
			;  lcd_putchar(0b0011.0010); /* change to 4 bit mode              */
	MOVLW 50
	CALL  lcd_putchar
			;  nop();
	NOP  
			;  lcd_putchar(0b00101000);  /* two line (8+8 chars in the row)   */ 
	MOVLW 40
	CALL  lcd_putchar
			;  nop();
	NOP  
			;  lcd_putchar(0b00001100);  /* display on, cursor off, blink off */
	MOVLW 12
	CALL  lcd_putchar
			;  nop();
	NOP  
			;  lcd_putchar(0b00000001);  /* display clear                     */
	MOVLW 1
	CALL  lcd_putchar
			;  nop();
	NOP  
			;  lcd_putchar(0b00000110);  /* increment mode, shift off         */
	MOVLW 6
	CALL  lcd_putchar
			;  nop();
	NOP  
			;  RS = 1;    // LCD in character-mode
	BCF   0x03,RP0
	BCF   0x03,RP1
	BSF   0x06,RS
			;             // initialization is done!
			;}
	RETURN
			;/*PRINT ACTION*/
			;/*lcd*/
			;void lcd_reset(void){
lcd_reset
			;   nop();
	NOP  
			;   RS=0;
	BCF   0x03,RP0
	BCF   0x03,RP1
	BCF   0x06,RS
			;  nop();
	NOP  
			;  lcd_putchar(0b00001000);  /* display off, cursor off, blink off */
	MOVLW 8
	CALL  lcd_putchar
			;  delay(10);  // give LCD time to settle
	MOVLW 10
	CALL  delay
			;  lcd_putchar(0b00001100);  /* display on, cursor off, blink off */
	MOVLW 12
	CALL  lcd_putchar
			;  nop();
	NOP  
			;  lcd_putchar(0b00000001);  /* display clear                     */
	MOVLW 1
	CALL  lcd_putchar
			;  nop();
	NOP  
			;  lcd_putchar(0b00000110);  /* increment mode, shift off         */
	MOVLW 6
	CALL  lcd_putchar
			;  nop();
	NOP  
			;  RS = 1;    // LCD in character-mode
	BCF   0x03,RP0
	BCF   0x03,RP1
	BSF   0x06,RS
			;             // initialization is done!
			;}
	RETURN
			;void lcd_putline(char start, const char * text)
			;{
lcd_putline
			;if (start >0x7){
	MOVLW 8
	BCF   0x03,RP0
	BCF   0x03,RP1
	SUBWF start,W
	BTFSS 0x03,Carry
	GOTO  m025
			;      // reposition to "line 2" (the next 8 chars)
			;          RS = 0;  // LCD in command-mode
	BCF   0x06,RS
			;          lcd_putchar( 0b11000000 );
	MOVLW 192
	CALL  lcd_putchar
			;		  start=start-0x8;
	MOVLW 8
	BCF   0x03,RP0
	BCF   0x03,RP1
	SUBWF start,1
			;		  }
			;   RS = 0;  // LCD in command-mode
m025	BCF   0x03,RP0
	BCF   0x03,RP1
	BCF   0x06,RS
			;   lcd_putchar( start );  // move to text position
	MOVF  start,W
	CALL  lcd_putchar
			;   RS = 1;  // LCD in character-mode
	BCF   0x03,RP0
	BCF   0x03,RP1
	BSF   0x06,RS
			;   
			;   char i, k;
			;   for(i = 0 ; ; i++)
	CLRF  i_2
			;    {
			;      k = text[i];
m026	BCF   0x03,RP0
	BCF   0x03,RP1
	MOVF  i_2,W
	ADDWF text,W
	CALL  _const1
	BCF   0x03,RP0
	BCF   0x03,RP1
	MOVWF k
			;      if( k == '\0') return;   // found end of string
	MOVF  k,1
	BTFSC 0x03,Zero_
	RETURN
			;      lcd_putchar(k); 
	BCF   0x03,RP0
	BCF   0x03,RP1
	MOVF  k,W
	CALL  lcd_putchar
			;    }
	BCF   0x03,RP0
	BCF   0x03,RP1
	INCF  i_2,1
	GOTO  m026
			;   return;  
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
			;/*uart*/
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
m027	BCF   0x03,RP0
	BCF   0x03,RP1
	MOVF  bitCount_2,1
	BTFSC 0x03,Zero_
	GOTO  m029
			;   {
			;     /* delay one bit 104 usec at 4 MHz       */
			;     /* 5+18*5-1+1+9=104 without optimization */ 
			;     ti = 18; do ; while( --ti > 0); nop(); 
	MOVLW 18
	MOVWF ti_2
m028	BCF   0x03,RP0
	BCF   0x03,RP1
	DECFSZ ti_2,1
	GOTO  m028
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
	GOTO  m027
			;  return;
m029	RETURN
			;}
			;
			;
			;void printf(const char *string, char variable)
			;{
printf
	BCF   0x03,RP0
	BCF   0x03,RP1
	MOVWF variable
			;  char i, k, m, a, b;
			;  for(i = 0 ; ; i++)
	CLRF  i_3
			;   {
			;     k = string[i];
m030	BCF   0x03,RP0
	BCF   0x03,RP1
	MOVF  i_3,W
	ADDWF string,W
	CALL  _const1
	BCF   0x03,RP0
	BCF   0x03,RP1
	MOVWF k_2
			;     if( k == '\0') break;   // at end of string
	MOVF  k_2,1
	BTFSC 0x03,Zero_
	GOTO  m052
			;     if( k == '%')           // insert variable in string
	BCF   0x03,RP0
	BCF   0x03,RP1
	MOVF  k_2,W
	XORLW 37
	BTFSS 0x03,Zero_
	GOTO  m050
			;      {
			;        i++;
	INCF  i_3,1
			;        k = string[i];
	MOVF  i_3,W
	ADDWF string,W
	CALL  _const1
	BCF   0x03,RP0
	BCF   0x03,RP1
	MOVWF k_2
			;        switch(k)
	MOVF  k_2,W
	XORLW 100
	BTFSC 0x03,Zero_
	GOTO  m031
	XORLW 17
	BTFSC 0x03,Zero_
	GOTO  m034
	XORLW 23
	BTFSC 0x03,Zero_
	GOTO  m043
	XORLW 1
	BTFSC 0x03,Zero_
	GOTO  m047
	XORLW 70
	BTFSC 0x03,Zero_
	GOTO  m048
	GOTO  m049
			;         {
			;           case 'd':         // %d  signed 8bit
			;             if( variable.7 ==1) putchar('-');
m031	BCF   0x03,RP0
	BCF   0x03,RP1
	BTFSS variable,7
	GOTO  m032
	MOVLW 45
	CALL  putchar
			;             else putchar(' ');
	GOTO  m033
m032	MOVLW 32
	CALL  putchar
			;             if( variable > 127) variable = -variable;  // no break!
m033	MOVLW 128
	BCF   0x03,RP0
	BCF   0x03,RP1
	SUBWF variable,W
	BTFSS 0x03,Carry
	GOTO  m034
	COMF  variable,1
	INCF  variable,1
			;           case 'u':         // %u unsigned 8bit
			;             a = variable/100;
m034	BCF   0x03,RP0
	BCF   0x03,RP1
	MOVF  variable,W
	MOVWF C2tmp
	CLRF  C3rem
	MOVLW 8
	MOVWF C1cnt
m035	BCF   0x03,RP0
	BCF   0x03,RP1
	RLF   C2tmp,1
	RLF   C3rem,1
	MOVLW 100
	SUBWF C3rem,W
	BTFSS 0x03,Carry
	GOTO  m036
	MOVLW 100
	BCF   0x03,RP0
	BCF   0x03,RP1
	SUBWF C3rem,1
	BSF   0x03,Carry
m036	BCF   0x03,RP0
	BCF   0x03,RP1
	RLF   a,1
	DECFSZ C1cnt,1
	GOTO  m035
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
m037	BCF   0x03,RP0
	BCF   0x03,RP1
	RLF   C5tmp,1
	RLF   b,1
	MOVLW 100
	SUBWF b,W
	BTFSS 0x03,Carry
	GOTO  m038
	MOVLW 100
	BCF   0x03,RP0
	BCF   0x03,RP1
	SUBWF b,1
m038	BCF   0x03,RP0
	BCF   0x03,RP1
	DECFSZ C4cnt,1
	GOTO  m037
			;             a = b/10;
	MOVF  b,W
	MOVWF C7tmp
	CLRF  C8rem
	MOVLW 8
	MOVWF C6cnt
m039	BCF   0x03,RP0
	BCF   0x03,RP1
	RLF   C7tmp,1
	RLF   C8rem,1
	MOVLW 10
	SUBWF C8rem,W
	BTFSS 0x03,Carry
	GOTO  m040
	MOVLW 10
	BCF   0x03,RP0
	BCF   0x03,RP1
	SUBWF C8rem,1
	BSF   0x03,Carry
m040	BCF   0x03,RP0
	BCF   0x03,RP1
	RLF   a,1
	DECFSZ C6cnt,1
	GOTO  m039
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
m041	BCF   0x03,RP0
	BCF   0x03,RP1
	RLF   C10tmp,1
	RLF   a,1
	MOVLW 10
	SUBWF a,W
	BTFSS 0x03,Carry
	GOTO  m042
	MOVLW 10
	BCF   0x03,RP0
	BCF   0x03,RP1
	SUBWF a,1
m042	BCF   0x03,RP0
	BCF   0x03,RP1
	DECFSZ C9cnt,1
	GOTO  m041
			;             putchar('0'+a); // print 1's
	MOVLW 48
	ADDWF a,W
	CALL  putchar
			;             break;
	GOTO  m051
			;           case 'b':         // %b BINARY 8bit
			;             for( m = 0 ; m < 8 ; m++ )
m043	BCF   0x03,RP0
	BCF   0x03,RP1
	CLRF  m
m044	MOVLW 8
	BCF   0x03,RP0
	BCF   0x03,RP1
	SUBWF m,W
	BTFSC 0x03,Carry
	GOTO  m051
			;              {
			;                if (variable.7 == 1) putchar('1');
	BTFSS variable,7
	GOTO  m045
	MOVLW 49
	CALL  putchar
			;                else putchar('0');
	GOTO  m046
m045	MOVLW 48
	CALL  putchar
			;                variable = rl(variable);
m046	BCF   0x03,RP0
	BCF   0x03,RP1
	RLF   variable,1
			;               }
	INCF  m,1
	GOTO  m044
			;              break;
			;           case 'c':         // %c  'char'
			;             putchar(variable);
m047	BCF   0x03,RP0
	BCF   0x03,RP1
	MOVF  variable,W
	CALL  putchar
			;             break;
	GOTO  m051
			;           case '%':
			;             putchar('%');
m048	MOVLW 37
	CALL  putchar
			;             break;
	GOTO  m051
			;           default:          // not implemented
			;             putchar('!');  
m049	MOVLW 33
	CALL  putchar
			;         }  
			;      }
			;      else putchar(k);
	GOTO  m051
m050	BCF   0x03,RP0
	BCF   0x03,RP1
	MOVF  k_2,W
	CALL  putchar
			;   }
m051	BCF   0x03,RP0
	BCF   0x03,RP1
	INCF  i_3,1
	GOTO  m030
			;}
m052	RETURN
			;/*DELAY*/
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
m053	BCF   0x03,RP0
	BCF   0x03,RP1
	CLRF  TMR0
			;        while ( TMR0 < 125)   /* 125 * 8 = 1000  */
m054	MOVLW 125
	BCF   0x03,RP0
	BCF   0x03,RP1
	SUBWF TMR0,W
	BTFSS 0x03,Carry
			;            ;
	GOTO  m054
			;    } while ( -- millisec > 0);
	BCF   0x03,RP0
	BCF   0x03,RP1
	DECFSZ millisec,1
	GOTO  m053
			;}
	RETURN
			;/*MEMORY ACCESS*/
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
m055	BCF   0x03,RP0
	BCF   0x03,RP1
	BTFSS 0x0D,EEIF
	GOTO  m055
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

; 0x01D5 P0   12 word(s)  0 % : init_serial
; 0x01E1 P0    6 word(s)  0 % : init_interrupt
; 0x035A P0   20 word(s)  0 % : delay
; 0x01E7 P0   27 word(s)  1 % : lcd_init
; 0x0241 P0   47 word(s)  2 % : lcd_putchar
; 0x0218 P0   41 word(s)  2 % : lcd_putline
; 0x0270 P0   27 word(s)  1 % : putchar
; 0x01D0 P0    5 word(s)  0 % : power_on
; 0x01B9 P0    5 word(s)  0 % : power_off
; 0x028B P0  207 word(s) 10 % : printf
; 0x038B P0   15 word(s)  0 % : getchar_eedata
; 0x036E P0   29 word(s)  1 % : putchar_eedata
; 0x01BE P0   18 word(s)  0 % : direc_change
; 0x0202 P0   22 word(s)  1 % : lcd_reset
; 0x0004 P0   53 word(s)  2 % : int_server
; 0x00D4 P0  229 word(s) 11 % : main
; 0x0039 P0  155 word(s)  7 % : _const1

; RAM usage: 22 bytes (20 local), 234 bytes free
; Maximum call level: 3 (+1 for interrupt)
;  Codepage 0 has  919 word(s) :  44 %
;  Codepage 1 has    0 word(s) :   0 %
; Total of 919 code words (22 %)
