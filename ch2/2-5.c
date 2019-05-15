/* Date: 15/05/19
   Description: This program implements any(s1[], s2[]) which returns first location in the
                string s1 where any character from string s2 or -1 if s1 contains no
                character from s2
*/
#include <stdio.h>

int any(char s1[], char s2[])
{
    int i, j;
    for (i = 0; s1[i] != '\0' && s2[j] == '\0'; i++) {
        for (j = 0; s2[j] != '\0' && s2[j] != s1[i]; j++ );
    }
    if (s1[i] == '\0')
        return -1;
    else
        return i;
}