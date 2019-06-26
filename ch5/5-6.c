/* Date: 26/06/19
   Description: pointer version of function getline, atoi, itoa, reverse, strindex
                atof, getop */

/* getline: read a line into s, return length */
#include <stdio.h>

/*getline: pointer version of getline function chapter 1 */
int getline(char *s, int lim)
{
    int c, i;
    
    for (i=0; i < lim-1 && (c=getchar()) != EOF && c != '\n'; ++i)
        *(s+i) = c;
    if (c == '\n') {
        *(s+i) = c;
        ++i;
    }
    *(s+i) = '\0';
    return i;
}

/*atoi: pointer version of atoi */
int atoi(char *s)
{
    int i, n;

    n = 0;
    for ( ; *s >= '0' && *s <= '9'; s++)
        n = 10 *n + (*s - '0');
    return n;
}

/* itoa: pointer version of itoa */
void itoa(int n, char *s)
{
    int sign;
    char *t = s;
    
    sign = (n < 0) ? -1: 1; /* record sign */    
    do {       /* generate digits in reverse order */
        *s++ = (n % 10 * sign) + '0';
    } while((n /= 10) != 0);
    if (sign < 0)
        *s++ = '-';
    *s = '\0';
    reverse(t);
}

/* reverse: pointer version of reverse */
void reverse(char *s)
{
    int c;
    char *s_end;

    for (s_end = s+strlen(s)-1; s < s_end; s++, s_end--) {
        c = *s;
        *s = *s_end;
        *s_end = c;
    }
    
}