/* Date: 21/05/19
   Description: This program expands shorthand notations like a-z into equivalent
                complete list abc...xyz
*/

#include <stdio.h>

void expand(char s1[], char s2[])
{
    
}

int main()
{
    int max = 100;
    char s1[] = "a-z0-9";
    char s2[max];
    expand(s1, s2);
    printf("%s\n", s1);
    printf("%s\n", s2);
}