/* Date: 23/04/19
   Description: convert integer to character representation in base b
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


/* itoa: convert n to characters in s in base b */
void itoab(int n, char s[], int b)
{
    int i, sign, rem;
    
    sign = (n < 0) ? -1: 1; /* record sign */    
    i = 0;
    do {       /* generate digits in reverse order */
        rem = (n % b * sign);
        s[i++] = rem > 9 ? rem - 10 + 'A' : rem + '0';
    } while((n /= b) != 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}


int main()
{
    int num = 123456;
    //int num = 20;
    char s[30];
    
    printf("Num: %d\n", num);
    itoab(num, s, 8);
    printf("Base 8: %s\n", s);
    itoab(num, s, 16);
    printf("Base 16: %s\n", s);
    itoab(num, s, 2);
    printf("Base 2: %s\n", s);

}