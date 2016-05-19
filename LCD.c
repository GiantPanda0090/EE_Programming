#include <htc.h>
#include "lcd.h"

void pause (unsigned short usvalue); //Establish puase routine function

#define LCD_RS TRISA.2
#define LCD_RW TRISA.4

#define LCD_EN TRISA.1

#define LCD_DATA PORTC

#define LCD_STROBE() ((LCD_EN=1), (LCD_EN=0))

/void delay( char millisec)
{
    OPTION = 2;  /* prescaler divide by 8        */
    do  {  TMR0 = 0;
           while ( TMR0 < 125)   /* 125 * 8 = 1000  */ ;
        } while ( -- millisec > 0);
}

void delay10( char n)
{
    char i; OPTION = 7;
    do  { i = TMR0 + 39; /* 256 microsec * 39 = 10 ms */
           while ( i != TMR0)  ;
        } while ( --n > 0);
}
void init_led(void){
LCD_RW = 0;  /* input rpgA        */
  LCD_RS = 0;  /* input rpgB        */
  delay(15); //wait 15ms after power is applied
   LCD_DATA = 0x3;  /* input rpgB        */
   
   LCD_STROBE();
pause(10);
LCD_STROBE();
pause(10);
LCD_DATA=2; //4-bit mode
LCD_STROBE();
   
  
}
void init_io_ports( void )
{
  TRISC = 0xF8; /* 11111000 0 is for outputbit  */
  PORTC = 0b000;    /* initial value */

  ANSEL =0;     /* not AD-input      */
  TRISA.5 = 1;  /* input rpgA        */
  TRISA.4 = 1;  /* input rpgB        */
   
  
  /* Enable week pullup's            */
  OPTION.7 = 0; /* !RABPU bit        */
  WPUA.5   = 1; /* rpgA pullup       */
  WPUA.4   = 1; /* rpgB pullup       */
  X.6 = 1;
  TRISB.6 = 1;  /* PORTB pin 6 input */
  
  return;
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




/* *********************************** */
/*            HARDWARE                 */
/* *********************************** */

/*           _____________  _____________ 
            |             \/             |
      +5V---|Vdd        16F690        Vss|---Gnd
     rpgA->-|RA5            RA0/AN0/(PGD)|bbTx->- PK2 UART-tool
     rpgB->-|RA4/AN3            RA1/(PGC)|bbRx-<- PK2 UART-tool
            |RA3/!MCLR/(Vpp)  RA2/AN2/INT|
            |RC5/CCP                  RC0|->-LED0
            |RC4                      RC1|->-LED1
            |RC3/AN7                  RC2|->-LED2
            |RC6/AN8             AN10/RB4|
            |RC7/AN9               RB5/Rx|
            |RB7/Tx                   RB6|-<-Butt
            |____________________________|                                      
*/ 

