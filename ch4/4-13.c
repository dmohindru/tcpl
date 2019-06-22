/* Date: 22/06/19
   Description: recursive version of revers(s) function 
*/

#include <stdio.h>

/* reverse1: recursive version of  reverse function */
void reverse1(char s[], int index, int len)
{
    char temp;

    if (s[index+1] != '\0') {
        reverse1(s, index+1, len);
    }
    
    if (index > (len - index - 1)) {
        temp = s[index];
        s[index] = s[len - index - 1];
        s[len - index - 1] = temp;
    }
}

/* reverse: reverse string in place */
void reverse(char s[])
{
    int len, i;

    /* get length of string */
    for (len = 0; s[len] != '\0'; len++)
    ;
    reverse1(s, 0, len);
}

int main()
{
    char str[] = "0123456789ABCDEF";
    
    printf("str = %s\n", str);
    reverse(str);
    printf("str = %s\n", str);
    return 0;
}