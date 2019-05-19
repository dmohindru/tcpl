/* Date: 19/05/19
   Description: lower function written with conditional expression
*/
#include <stdio.h>

int lower(int c)
{
    return (c >= 'A' && c <= 'Z') ? (c + 'a' - 'A') : c;
}

int main()
{
    char c = 'B';
    printf("%c\n", lower(c));
    c = 'c';
    printf("%c\n", lower(c));
    c = 'X';
    printf("%c\n", lower(c));
}