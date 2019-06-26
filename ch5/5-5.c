/* Date: 26/05/19
   Description: Implementation of library function
          strncpy, strncat, strncmp */

#include <stdio.h>

void mystrncpy(char *s, char *t, int n);
void mystrncat(char *s, char *t, int n);
int  mystrncmp(char *s, char *t, int n);

int main()
{
    char str1[50];
    char *str2 = "Dhruv";
    char *str3 = "Moh";
    mystrncat(str1, str2, 3);
    mystrncat(str1, str3, 4);
    printf("%s\n", str1);
    //printf("Comparing strings str2, str3: %d\n", mystrncmp(str3, str2, 3));
    return 0;
}


/*mystrncpy: copy at most n character from string t to string s */
void mystrncpy(char *s, char *t, int n)
{
    while ((*s++ = *t++) && --n > 0)
    ;
    if (*t)
        *s = '\0';

}

/*mystrncat: concatinate at most n character from string t to string s */
void mystrncat(char *s, char *t, int n)
{
    while (*s != '\0') /* Find end of string */
        s++;
    while ((*s++ = *t++) && --n > 0)  /* Copy t */
    ;
    if (*t)
        *s = '\0';

}

/*mystrncmp: compare at most n character from string t to string s */
int mystrncmp(char *s, char *t, int n)
{
    for ( ; (*s == *t) && (--n > 0); s++, t++ )
    ;
    if (n == 0 || *s == '\0')
        return 0;
    else
        return *s - *t;
}