/* Date: 23/04/19
   Description: convert integer to character representation which is minimum field wide
*/

#include <stdio.h>
#include <string.h>
#include <limits.h>


/* reverse: reverse string s in place */
void reverse(char s[])
{
    int c, i, j;

    /* skip blank chars */
    for (i = 0; s[i] == ' '; i++);

    for (j = strlen(s)-1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}


/* itoa: convert n to characters in s which is minimum w char wide */
void itoa(int n, char s[], int w)
{
    int i, sign;
    
    sign = (n < 0) ? -1: 1; /* record sign */    
    i = 0;
    do {       /* generate digits in reverse order */
        s[i++] = (n % 10 * sign) + '0';
    } while((n /= 10) != 0);
    if (sign < 0)
        s[i++] = '-';
    while (i < w)
        s[i++] = ' ';
    s[i] = '\0';
    reverse(s);
}


int main()
{
    int num = 123456;
    //int num = 20;
    char s[30];
    
    printf("Num: %d\n", num);
    itoa(num, s, 8);
    printf("Width 8: %s\n", s);
    itoa(num, s, 16);
    printf("Width 16: %s\n", s);
    itoa(num, s, 2);
    printf("Width 2: %s\n", s);

}