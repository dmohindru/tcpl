/* Date: 25/06/19
   Description: Concatenate two strings */

#include <stdio.h>

/* strcat: concatenate to to end of s; s must be big enough */
void mystrcat(char *s, char *t)
{
    while (*s != '\0') /* Find end of string */
        s++;
    while (*s++ = *t++) /* Copy t */
    ;
}

int main()
{
    char str1[] = "Dhruv ";
    char str2[] = "Mohindru";
    char str3[50];
    mystrcat(str3, str1);
    printf("%s\n", str3);
    mystrcat(str3, str2);
    printf("%s\n", str3);
    return 0;
}