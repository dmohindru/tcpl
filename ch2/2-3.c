/* Date: 14/05/19
   Description: This program implements htoi(s) function which converts hexadecimal
                digits into equivalent decimal value
*/
#include <stdio.h>

enum loop {NO, YES};

int htoi(char s[]);
int main()
{
    printf("decimal equivalent of 0xFF: %d\n", htoi("0xFF"));
    printf("decimal equivalent of 0x11: %d\n", htoi("0x11"));
    printf("decimal equivalent of 22: %d\n", htoi("22"));
    printf("decimal equivalent of 0XA1: %d\n", htoi("0xA1"));
    printf("decimal equivalent of 0XAa1aBc: %d\n", htoi("0XAa1aBc"));
    printf("decimal equivalent of 0XAZ1: %d\n", htoi("0xAZ1")); /* test with illegal hexadecimal digit */


}

/* Converts string of hexadecimal digits to its equivalent decimal integer */
int htoi(char s[])
{
    int i;
    int decimal = 0;
    enum loop loopok = YES;
    /* First check for leading 0x or 0X in string s */
    if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
        i = 2;
    else
        i = 0;
    
    while (s[i] != '\0' && loopok == YES) {
        if (s[i] >= '0' && s[i] <= '9')
            decimal = 16 * decimal + (s[i] - '0');
        else if (s[i] >= 'A' && s[i] <= 'F')
            decimal = 16 * decimal + (s[i] - 'A' + 10);
        else if (s[i] >= 'a' && s[i] <= 'f')
            decimal = 16 * decimal + (s[i] - 'a' + 10);
        else /* character is a valid hexadecimal digit */
            loopok = NO;
        i++;
    }

    return decimal;
}