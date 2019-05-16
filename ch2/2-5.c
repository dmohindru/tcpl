/* Date: 15/05/19
   Description: This program implements any(s1[], s2[]) which returns first location in the
                string s1 where any character from string s2 or -1 if s1 contains no
                character from s2
*/
#include <stdio.h>

int any(char s1[], char s2[])
{
    int i, j;
    
    for (i = 0; s1[i] != '\0'; i++) {
        for (j = 0; s2[j] != '\0'; j++ )
        {
            if (s2[j] == s1[i])
                return i;
        }
    }
    return -1;
}

int main()
{
    char s1[] = "Dhruv Mohindru";
    char s2[] = "drv";
    char s3[] = "xyz";
    printf("any(s1, s2): %d\n", any(s1, s2));
    printf("any(s1, s3): %d\n", any(s1, s3));
}