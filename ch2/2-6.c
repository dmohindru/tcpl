/* Date: 16/05/19
   Description: Set x with n bits that begin at position p set to the rightmost n bits of y
*/
#include <stdio.h>

/* print a number in binary format */
void binary(short x, short bits)
{
    int i;
    

}

short setbits(short x, short p, short n, short y) 
{
    int ymask = ~(~0 << n);
    printf("ymask: %d\n", ymask);
    ymask = (ymask & y) << p;
    printf("ymask: %d\n", ymask);
    return (x | ymask);
}

int main()
{
    short x, y;
    x = -1;
    y = 10;
    printf("%d\n", setbits(x, 28, 4, y));
}