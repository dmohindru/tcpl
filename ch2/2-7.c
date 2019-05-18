/* Date: 18/05/19
   Description: Invert n bits start at position p of x
*/
#include <stdio.h>

/* print a number in binary format */
void show_bits(short x, short bits)
{
    unsigned short mask, i = 1;
    for (mask = 1 << bits-1; mask > 0 ; mask = mask >> 1, i++)
    {
        if (!(x & mask))
            printf("0");
        else
            printf("1");
        /* Printf space after group of 4 bits */
        if (!(i % 4))
            printf(" ");
    }
    printf("\n");
}

short invert(short x, short p, short n) 
{
    return x ^ (~(~0 << n) << (p - n));
}

int main()
{
    short x = 0x8888;
    show_bits(x, 16);
    show_bits(invert(x, 13, 6), 16);
}
