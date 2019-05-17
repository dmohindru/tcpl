/* Date: 16/05/19
   Description: Set x with n bits that begin at position p set to the rightmost n bits of y
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

short setbits(short x, short p, short n, short y) 
{
    short x_val, ymask, y_bits;
    /* create mask to extract bits in y */
    ymask = ~(~0 << n);
    
    /* extract y bits and move to required position */
    y_bits = (y & ymask) << (p - n);
    
    /* Generate mask to clear rest of y bits and required x bits */
    ymask = (ymask ) << (p - n);
    
    /* clear required bits in x*/
    x_val = x & ~ymask; 

    /* clear rest of y bits and or result with rest of x bits */
    x_val = x_val | (y_bits & ymask);
    
    return x_val;
}

int main()
{
    short x, y;
    x = 0xFFFF;
    y = 0x0000;
    show_bits(x, 16);
    
    show_bits(setbits(x, 12, 4, y), 16);
}