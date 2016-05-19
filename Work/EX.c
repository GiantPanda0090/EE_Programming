#include "16F690.h"
#include "int16Cxx.h"
#pragma config |= 0x00D4
#pragma char X @ 0x115

void lcd_init (void){
TRISA =0;
TRISC=0;
 PORTC =0x3;
 
 SSPCON=0x0;
}
void lcd_write (char ch){
 while (SSPSTAT.0);
   char bitCount, ti;
  PORTC.7 = 0; /* set startbit */
  for ( bitCount = 10; bitCount > 0 ; bitCount-- )
   {
     /* delay one bit 104 usec at 4 MHz       */
     /* 5+18*5-1+1+9=104 without optimization */ 
     ti = 18; do ; while( --ti > 0); nop();         
	  PORTC.7 = 1;
     ch = rr( ch ); /* Rotate Right through Carry */
     PORTC.7 = ch;
   }
  return;
  }
  
  void main(void){
  lcd_init();
  while(1){
  lcd_write("lets");
  }
  