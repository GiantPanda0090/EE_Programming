/* test3.c  float Multiplication          */
/* No hardware needed                     */
/* B Knudsen Cc5x C-compiler - not ANSI-C */

#include "16F690.h"
#include "math24f.h"
#pragma config |= 0x00D4

void main( void)
{
  long a;
  float b;
  b = (float)a * 5.0/1023.0;
}

