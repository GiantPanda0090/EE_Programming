
#include "16F690.h"
#include "int16Cxx.h"
#pragma config |= 0x00D4
#pragma char X @ 0x115

#define LCD_RS TRISA.2
#define LCD_RW TRISA.4

#define LCD_EN TRISA.1

#define LCD_DATA PORTC

#define LCD_STROBE() ((LCD_EN=1), (LCD_EN=0))

/*write a byte to the LCD In 4 bit mode */
void delay( char millisec)
{
    OPTION = 2;  /* prescaler divide by 8        */
    do  {  TMR0 = 0;
           while ( TMR0 < 125)   /* 125 * 8 = 1000  */ ;
        } while ( -- millisec > 0);
}

void lcd_write (unsigned char c)
{
delay(1);
LCD_DATA= ((c >>4) & 0x0F);
LCD_STROBE();
LCD_DATA= (c & 0x0F);
LCD_STROBE();
}

/* Clear and home the LCD */

void lcd_clear(void) 
{
LCD_RS= 0;
lcd_write(0x1);
delay(2);
}

/* write a string of chars to the LCD */

void lcd_puts (const char * s)
{
LCD_RS=1; //write characters
while(*s)
lcd_write(*s++);
}



/* write one character to the LCD */

void lcd_putch (char c)
{
LCD_RS= 1; //write characters
lcd_write(c);
}


/* Go to the specified position */

void lcd_goto (unsigned char pos)
{
LCD_RS= 0;
lcd_write(0x80+pos);
}

/* initalize the LCD- put it into 4 bit mode */
void lcd_init()
{
char init_value;

ANSEL= 0; //Disable analog pins on PORTA
ANSELH= 0;
CM1CON0= 0;
CM2CON0= 0;
init_value= 0x3;
TRISA= 0;
TRISC= 0;
LCD_RS= 0;
LCD_EN= 0;
LCD_RW= 0;

delay(15); //wait 15ms after power is applied
LCD_DATA = init_value;
LCD_STROBE();
delay(10);
LCD_STROBE();
delay(10);
LCD_DATA=2; //4-bit mode
LCD_STROBE();

lcd_write(0x28); //Set interface length
lcd_write(0xF); //Display On, Cursor On, Cursor Blink
lcd_clear(); //Clear Screen
lcd_write(0x6); //Set entry mode
}

void main( void)
{
lcd_init();
while (1){
lcd_clear();//this clears the LCD 
lcd_goto(0); //selects the first line of the LCD
for (b0=0; b0<10; b0++) {
lcd_putch(b0+number); //this displays a count on the LCD
delay(250); //delays 250 milliseconds between count
}

lcd_goto(0x40); //selects the second line on the LCD
lcd_puts("Hello World"); //displays the line, Hello World
delay(1000); //creates 1 second delay
}
}
