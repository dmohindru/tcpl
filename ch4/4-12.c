/* Date: 22/06/19
   Description: recursive version of itoa */

#include <stdio.h>
#include <limits.h>



void itoa(int n, char s[])
{
    static int i;
    int sign = (n < 0) ? -1 : 1;
    
    if (n / 10)
        itoa(n /10, s);
    else {
        i = 0;
        if (n < 0)
            s[i++] = '-';
    }
    s[i++] = (n % 10) * sign + '0';
    s[i] = '\0';
}

int main()
{
    int num = INT_MIN;
    //int num = -12345;
    char s[30];
    itoa(num, s);
    printf("%d\n", num);
    printf("%s\n", s);
}