// DEMO-ENH.C : Example syntax for new Enhanced 14 bit Core

#pragma chip PIC16F1938  // select device (or use option -p..)

#pragma rambank 0
char a0, b0;

#pragma rambank 1
char a1, b1;

#pragma rambank 12
char a12, b12;

#pragma rambank -     // unbanked region
char a, bx;

bit bt1, bt;

#pragma rambank 0

// bank type modifier can also be used
bank2 int ib2;
bank5 int ib5;


// ************************************************
// ************************************************
// INTERRUPT SUPPORT

#include "int16CXX.h"  // device dependent interrupt definitions

#pragma origin 4   // start address of interrupt routine (14 bit core)

interrupt serverX( void)
{
    /* W, STATUS, BSR, FSRx registers and PCLATH are automatically saved
       in shadow registers */
    int_save_registers      // including PCLATH updating

    // handle the interrupt
    if (TMR0IF)  {
        // .. handle TMR0 overflow
        TMR0IF = 0;  /* reset flag */
    }

    if (INTF)  {
        // .. handle INT interrupt
        INTF = 0;  /* reset flag */
    }

    int_restore_registers
    /* W, STATUS, BSR, FSR registers and PCLATH are automatically restored
       from shadow registers by RETFIE */
    // GIE is automatically set to 1 on exit (by RETFIE).
}
/* IMPORTANT : GIE should normally NOT be set or cleared in
   the interrupt routine. GIE is AUTOMATICALLY cleared on
   interrupt entry by the CPU and set to 1 on exit (by
   RETFIE). Setting GIE to 1 inside the interrupt service
   routine will cause nested interrupts if an interrupt is
   pending. Too deep nesting may crash the program! */


#pragma packedCdataStrings 0   //Store following strings unpacked
#define DDATA 0x700
#pragma cdata[DDATA] = "Hello world!\0"
#pragma cdata.ID2 = "Another string\r\n"
#pragma packedCdataStrings 1


void const_data( void)
{
    char x;

    // Normal 'const' data does not (yet) use FSRx for fast access
    const char *pt = "Hello";
    x = *pt++;

    // Fast access of constant data stored in FLASH requires cdata[] (CTATA.TXT)
    FSR0 = 0x8000 + DDATA;   // offset 0x8000 must be added manually
    x = *FSR0++;
    //..
    FSR0 = 0x8000 + ID2;      // load address to "label" in cdata[]
}


#pragma origin 0xFD

char c_goto( char W)
{
    skip(W);     // computed branch (W = 0..4)
    return 10;
    return 11;
    return 12;
    return 13;
    return 14;
}

char tab[30];
bank1 char tab1[30];
bank2 char tab2[30];

void read_indirect( void)
{
    char z, q;
    char i;

    // Using FSRx registers directly

    FSR0 = &tab1[i];  // load RAM address
    FSR1 = &tab[3];   // load RAM address

    *FSR1++ = q & 3;
    *--FSR0 = q & 6;
    z = *FSR0++ & 3;

    *FSR0++ = *FSR1++;

    *FSR1 = 0;

    FSR0 += 10;
    FSR1 -= 5;

    char *p2 = &tab[i];
    *p2 = 0;

    INDF0 = 0;
    INDF1 = 0;
}


// large tables that cross bank boundaries
#define MAX_tabXL 100
char tabXL[MAX_tabXL];
char tabX[32] @ 0x260;    // locate at specific address

void large_table( void)
{
    char *pc;
    char i, z;
    uns16 i16;

    tabXL[i] = 0;      // 8 bit index variable
    tabXL[i16] = 0;    // 16 bit index variable

    pc = tabXL;        // first element
    pc[i16] = 0;
    pc[i] = 0;
    pc = &tabXL[MAX_tabXL-1];   // last element

    z = tabX[15];
    z = tabX[16];
}


// small tables located within one bank

#define MAX_tabS 70
bank6 char tabS[MAX_tabS];

void small_tables( void)
{
    char *pst;
    char i, z;

    tabS[i] = 0;

    pst = &tabS[MAX_tabS-1];
    *pst = 0;

    pst = tabS;
    z = pst[i];

    char *p = &tab[i+1];
    char x = tab[i];

    *p = 0;
    p[2] = 0;

    tab[0] = 1;
}


void inline_asm( void)
{
    char i;

   #asm
    NOP
   LBL:
    ADDWFC   i,W
    SUBWFB   i,1
    LSLF     i,0
    LSRF     i
    ASRF     i,W
    MOVLB    1
    MOVLP    1

    NOP
    BTFSC      STATUS,Carry
    GOTO       LBL
    NOP

    RESET

    ADDFSR INDF0,31
    ADDFSR INDF1,-1

    MOVWI ++INDF0
    MOVIW INDF0--

    MOVIW 1[INDF0]
    MOVIW -2[INDF1]

   #endasm
}


void internalFunctions( void)
{
    char mm, q;

    mm = asr(mm);  // ASRF mm
    mm = lsl(mm);  // LSLF mm
    W = lsr(mm);   // LSRF mm,W
    mm = addWFC(mm);  // ADDWFC mm
    mm = subWFB(mm);  // SUBWFB mm

    softReset();

    // W and WREG are the same register
    WREG = swap(WREG);
    WREG = rl(W);
    if (WREG.3)  nop();
    if (W & 0x20)  nop();
}



void main(void)
{
    char e, y;
    clearRAM();  // built in function

    e = c_goto( y);
    const_data();
    read_indirect();
    large_table();
    small_tables();
    inline_asm();
    internalFunctions();
}



