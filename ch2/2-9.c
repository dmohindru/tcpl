/* Date: 19/05/19
   Description: count number of bits in a number
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

int bitcount(unsigned short x)
{
    int i = 0;
    while (x > 0)
    {
        x &= (x-1);
        i++;
    }
    return i;
}

int main()
{
    unsigned short x = 0XF0A7;
    show_bits(x, 16);
    printf("Number of set bits: %d\n", bitcount(x));
}