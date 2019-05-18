/* Date: 18/05/19
   Description: rotate integer by n bits
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

short rightrot(short x, short n)
{
    unsigned short u_bits;
    unsigned short mask = ~(~0 << n);
    mask = mask << (sizeof(x) * 8) - n;
    u_bits = x & mask;
    u_bits = u_bits >> (sizeof(x) * 8) - n;
    return x << n | u_bits;
}
int main()
{
    short x = 0XFA98;
    show_bits(x, 16);
    show_bits(rightrot(x, 4), 16);
}