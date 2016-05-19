// HEADER FILE
#pragma chip PIC12F519, core 12, code 1023, ram 7 : 0x3F
// NOTE: last code location is omitted   ^--

#pragma resetVector 0

#pragma config_def 0x0010

#pragma data_area  0x400 : 0x43F

#pragma user_ID_addr 0x440

#if __CC5X__ < 3305
 #error 12F519 requires CC5X version 3.3E or later
#endif

/* Predefined:
  char W;
  char INDF, TMR0, PCL, STATUS, FSR, PORTB;
  char OPTION;
  bit Carry, DC, Zero_, PD, TO, PA0, PA1, PA2;
  bit FSR_5, FSR_6;
*/

#pragma char OSCCAL @ 5

#pragma char EECON  @ 0x21
#pragma char EEDATA @ 0x25
#pragma char EEADR  @ 0x26

#pragma bit  RBWUF  @ STATUS.7

#pragma bit  RD      @ EECON.0
#pragma bit  WR      @ EECON.1
#pragma bit  WREN    @ EECON.2
#pragma bit  WRERR   @ EECON.3
#pragma bit  FREE    @ EECON.4
