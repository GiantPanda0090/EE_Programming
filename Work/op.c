#include "16F690.h"
#include "int16Cxx.h"
#pragma config |= 0x00D4

/* I/O-pin definitions                               */ 
/* change if you need a pin for a different purpose  */
#pragma bit RS  @ PORTB.4
#pragma bit EN  @ PORTB.6

#pragma bit D7  @ PORTC.3
#pragma bit D6  @ PORTC.2
#pragma bit D5  @ PORTC.1
#pragma bit D4  @ PORTC.0

#pragma bit EN_DC  @ PORTC.5
#pragma bit TREN_DC  @ TRISC.5

#define DUTY 128

//define//
//************************************************************************//
void init( void );
void initserial( void );
void init_io_ports( void );
void init_serial( void );
void init_interrupt( void );
void delay( char ); // ms delay function
void lcd_init( void );
void lcd_putchar( char );
char text1( char );
char text2( char );
char text3( char );
char text4( char );
void putchar( char );
char getchar( void );
void power_on(void);
void power_off(void);
void printf(const char *string, char variable);
void lcd_poweron(void);
void lcd_poweroff(void);
char getchar_eedata( char adress );
void putchar_eedata( char data, char adress );
void direc_change(void);
//******************************************************************************//

/*interupt*/
//*****************************************************************************//
bit receiver_flag;   /* Signal-flag used by interrupt routine   */
char receiver_byte;  /* Transfer Byte used by interrupt routine */

#pragma origin 4
interrupt int_server( void ) /* the place for the interrupt routine */
{
  int_save_registers
  /* New interrupts are automaticaly disabled            */
  /* "Interrupt on change" at pin RA1 from PK2 UART-tool */
  
  if( PORTA.1 == 0 )  /* Interpret this as the startbit  */
    {  /* Receive one full character   */
      char bitCount, ti;
      /* delay 1,5 bit 156 usec at 4 MHz         */
      /* 5+28*5-1+1+2+9=156 without optimization */
      ti = 28; do ; while( --ti > 0); nop(); nop2();
      for( bitCount = 8; bitCount > 0 ; bitCount--)
       {
         Carry = PORTA.1;
         receiver_byte = rr( receiver_byte);  /* rotate carry */
         /* delay one bit 104 usec at 4 MHz       */
         /* 5+18*5-1+1+9=104 without optimization */ 
         ti = 18; do ; while( --ti > 0); nop(); 
        }
      receiver_flag = 1; /* A full character is now received */
    }
  RABIF = 0;    /* Reset the RABIF-flag before leaving   */
  int_restore_registers
  /* New interrupts are now enabled */
}
//******************************************************************************//

void main(void)
{
 char choice;  int cnt = 0;
  
 //***********************************************************//  
init_serial();
 init_interrupt(); 
   T2CON = 0b0.0000.1.01; /* prescale 1:1     */
   //CCP1CON = 0b01.00.1100 ;  /* PWM-mode         */
   PR2     = 255;            /* max value        */
   CCPR1L  = 200; 
     
/* I/O-pin direction in/out definitions, change if needed  */
	ANSEL=0; 	//  PORTC digital I/O
	ANSELH=0;
	TRISC = 0b1101.0000;  /* RC3,2,1,0 out*/
    TRISB.4=0; /* RB4, RB6 out */
    TRISB.6=0;	
	
//power_off();

    char i;
    lcd_init();
//***************************************************************//

 

  /* You should "connect" PK2 UART-tool in one second after power on! */
  delay(1000); 

  printf("Menu: 1, 2, 3, h\r\n",0);
 char save;
/* uart_ choose*/
//****************************************************************************//
  while(1)
   {
   
     if( receiver_flag ) /* Character received? */ 
      {
	 
        choice = receiver_byte; /* get Character from interrupt routine */
        receiver_flag = 0;      /* Character now taken - reset the flag */
		 save = choice;
		
		switch (choice)
         {
          case '1':
		   lcd_poweron();
		   nop();
           printf("%c The power is now on. Press a to abort to main menu.\r\n", choice);
		   nop();
           break;
          case '2':
		  //lcd_poweroff();
		   nop();
           printf("%c Power off\r\n", choice);
		   nop();
           break;
          case '3':
           printf("%c Direction changed: ", choice);
           //printf("%u\r\n", (char) PORTB.6);
           break;
   case 'h':
  
   break;
          default:
		  printf("%c choose H for help \r\n", choice);
           printf("%c You must choose between: 1, 2, 3 \r\n", choice);
			 //printf(getchar_eedata(1), 0);
         }
		 nop();
      }
	  
nop();
choice = save;
nop();
 switch (choice)
         {
          case '1':
		 
           power_on();
		   //putchar_eedata((char) PORTB.6,1);
		   nop();
		  
           break;
          case '2':
		  nop();
           power_off();
		   nop();
		  // putchar_eedata((char) PORTB.6,1);
           break;
          case '3':
          direc_change();
           break;
   case 'h':
  
   break;
          default:
		  
			 
			 //printf(getchar_eedata(1), 0);
         }
		 nop();
	  }
     /* if no Character is received we always loop here */
//*******************************************************************************************//



	
	
   // reposition to "line 2" (the next 8 chars)
   // RS = 0;  // LCD in command-mode
    //lcd_putchar( 0b11000000 );
  
    //RS = 1;  // LCD in character-mode
    // display the 8 char text2() sentence
  // for(i=0; i<8; i++) lcd_putchar(text2(i));	
	
	
 

}
//***************************************************************************************************************************************************************************************************//
void power_off(void){
 
CCP1CON = 0b00.00.0000 ; 
}
void direc_change(void){
CCP1CON = 0b11.00.1100 ; 
}

void lcd_poweron(void){
int i;

    RS = 0;  // LCD in command-mode
    lcd_putchar(0b00000001); 
	lcd_putchar(0b00000110);
	
RS = 1;  // LCD in character-mode
    // display the 8 char text1() sentence
    for(i=0; i<8; i++) lcd_putchar(text1(i)); 
	RS = 0;
}

void lcd_poweroff(void){
int i;

    RS = 0;  // LCD in command-mode
    lcd_putchar(0b00000001); 
	lcd_putchar(0b00000110);
	
RS = 1;  // LCD in character-mode
    // display the 8 char text1() sentence
    for(i=0; i<8; i++) lcd_putchar(text3(i)); 
RS = 0;
}

void power_on(void){
CCP1CON = 0b01.00.1100 ; 
}

char text1( char x)   // this is the way to store a sentence
{
   skip(x); /* internal function CC5x.  */
   #pragma return[] = "Power on"    // 8 chars max!
}

char text2( char x)   // this is the way to store a sentence
{
   skip(x); /* internal function CC5x.  */
   #pragma return[] = ""    // 8 chars max!
}
char text3( char x)   // this is the way to store a sentence
{
   skip(x); /* internal function CC5x.  */
   #pragma return[] = "Power off"    // 8 chars max!
}
char text4( char x)   // this is the way to store a sentence
{
   skip(x); /* internal function CC5x.  */
   #pragma return[] = ""    // 8 chars max!
}
void init_serial( void )  /* initialise PIC16F690 bitbang serialcom */
{
   ANSEL.0 = 0; /* No AD on RA0             */
   ANSEL.1 = 0; /* No AD on RA1             */
   PORTA.0 = 1; /* marking line             */
   TRISA.0 = 0; /* output to PK2 UART-tool  */
   TRISA.1 = 1; /* input from PK2 UART-tool */
   receiver_flag = 0 ;
   return;      
}

void init_interrupt( void )
{
  IOCA.1 = 1; /* PORTA.1 interrupt on change */
  RABIE =1;   /* interrupt on change         */
  GIE = 1;    /* interrupt enable            */
  return;
}

void lcd_init( void ) // must be run once before using the display
{
  delay(40);  // give LCD time to settle
  RS = 0;     // LCD in command-mode
  lcd_putchar(0b0011.0011); /* LCD starts in 8 bit mode          */
  lcd_putchar(0b0011.0010); /* change to 4 bit mode              */
  lcd_putchar(0b00101000);  /* two line (8+8 chars in the row)   */ 
  lcd_putchar(0b00001100);  /* display on, cursor off, blink off */
  lcd_putchar(0b00000001);  /* display clear                     */
  lcd_putchar(0b00000110);  /* increment mode, shift off         */
  RS = 1;    // LCD in character-mode
             // initialization is done!
}

void putchar( char ch )  /* sends one char */
{
  char bitCount, ti;
  PORTA.0 = 0; /* set startbit */
  for ( bitCount = 10; bitCount > 0 ; bitCount-- )
   {
     /* delay one bit 104 usec at 4 MHz       */
     /* 5+18*5-1+1+9=104 without optimization */ 
     ti = 18; do ; while( --ti > 0); nop(); 
     Carry = 1;     /* stopbit                    */
     ch = rr( ch ); /* Rotate Right through Carry */
     PORTA.0 = Carry;
   }
  return;
}

void lcd_putchar( char data )
{
  // must set LCD-mode before calling this function!
  // RS = 1 LCD in character-mode
  // RS = 0 LCD in command-mode
  // upper Nybble
  D7 = data.7;
  D6 = data.6;
  D5 = data.5;
  D4 = data.4;
  EN = 0;
  nop();
  EN = 1;
  delay(5);
  // lower Nybble
  D7 = data.3;
  D6 = data.2;
  D5 = data.1;
  D4 = data.0;
  EN = 0;
  nop();
  EN = 1;
  delay(5);
}
void printf(const char *string, char variable)
{
  char i, k, m, a, b;
  for(i = 0 ; ; i++)
   {
     k = string[i];
     if( k == '\0') break;   // at end of string
     if( k == '%')           // insert variable in string
      {
        i++;
        k = string[i];
        switch(k)
         {
           case 'd':         // %d  signed 8bit
             if( variable.7 ==1) putchar('-');
             else putchar(' ');
             if( variable > 127) variable = -variable;  // no break!
           case 'u':         // %u unsigned 8bit
             a = variable/100;
             putchar('0'+a); // print 100's
             b = variable%100;
             a = b/10;
             putchar('0'+a); // print 10's
             a = b%10;        
             putchar('0'+a); // print 1's
             break;
           case 'b':         // %b BINARY 8bit
             for( m = 0 ; m < 8 ; m++ )
              {
                if (variable.7 == 1) putchar('1');
                else putchar('0');
                variable = rl(variable);
               }
              break;
           case 'c':         // %c  'char'
             putchar(variable);
             break;
           case '%':
             putchar('%');
             break;
           default:          // not implemented
             putchar('!');  
         }  
      }
      else putchar(k);
   }
}

void delay( char millisec)
/* 
  Delays a multiple of 1 milliseconds at 4 MHz (16F628 internal clock)
  using the TMR0 timer 
*/
{
    OPTION = 2;  /* prescaler divide by 8        */
    do  {
        TMR0 = 0;
        while ( TMR0 < 125)   /* 125 * 8 = 1000  */
            ;
    } while ( -- millisec > 0);
}
void putchar_eedata( char data, char adress )
{
/* Put char in specific EEPROM-adress */
      /* Write EEPROM-data sequence                          */
      EEADR = adress;     /* EEPROM-data adress 0x00 => 0x40 */
      EEPGD = 0;          /* Data, not Program memory        */  
      EEDATA = data;      /* data to be written              */
      WREN = 1;           /* write enable                    */
      EECON2 = 0x55;      /* first Byte in comandsequence    */
      EECON2 = 0xAA;      /* second Byte in comandsequence   */
      WR = 1;             /* write                           */
      while( EEIF == 0) ; /* wait for done (EEIF=1)          */
      WR = 0;
      WREN = 0;           /* write disable - safety first    */
      EEIF = 0;           /* Reset EEIF bit in software      */
      /* End of write EEPROM-data sequence                   */
}


char getchar_eedata( char adress )
{
/* Get char from specific EEPROM-adress */
      /* Start of read EEPROM-data sequence                */
      char temp;
      EEADR = adress;  /* EEPROM-data adress 0x00 => 0x40  */ 
      EEPGD = 0;       /* Data not Program -memory         */      
      RD = 1;          /* Read                             */
      temp = EEDATA;
      RD = 0;
      return temp;     /* data to be read                  */
      /* End of read EEPROM-data sequence                  */  
}