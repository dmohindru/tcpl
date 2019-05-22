/* Date: 22/05/19
   Description: Program that print largest negetive number
                properly.
*/
#include <stdio.h>
#include <string.h>
#include <limits.h>


/* reverse: reverse string s in place */
void reverse(char s[])
{
    int c, i, j;

    for (i=0, j = strlen(s)-1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
/* Book version of itoa does not properly handles largest negetive number because of
   asymetric range of negetive and positive number in 2's complement number representation as
   INT_MAX = 2^(word_size-1) - 1
   INT_MIN = -2^(word_size-1)
*/

/* itoa: convert n to characters in s */
void itoa(int n, char s[])
{
    int i, sign;
    
    sign = (n < 0) ? -1: 1; /* record sign */    
    i = 0;
    do {       /* generate digits in reverse order */
        s[i++] = (n % 10 * sign) + '0';
    } while((n /= 10) != 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}


int main()
{
    int num = INT_MIN;
    //int num = 20;
    char s[30];
    itoa(num, s);
    printf("%d\n", num);
    printf("%s\n", s);
}