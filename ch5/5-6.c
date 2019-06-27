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

/* strindex: pointer version of strindex */
int strindex(char *s, char *t)
{
    char *s1, *t1, *s2;
    for (s2 = s; *s2 != '\0'; s2++) {
        for (s1 = s2, t1 = t; *t1 != '\0' && *s1 == *t1; s1++, t1++)
            ;
        if (*t1 == '\0' && t1 > t)
            return s2 - s;
    }
    return -1;
}

/* atof: convert string s to double my version*/
double atof(char *s)
{
    double val, power;
    int sign;

    for (; isspace(*s); s++) /* skip white space */
        ;
    sign = (*s == '-')? -1 : 1;
    if (*s == '+' || *s == '-')
        s++;
    for (val = 0.0; isdigit(*s); s++)
        val = 10.0 * val + (*s - '0');
    if (*s == '.')
        s++;
    for (power = 1.0; isdigit(*s); s++) {
        val = 10.0 * val + (*s - '0');
        power *= 10.0;
    }
    return sign * val / power;
}

#define NUMBER '0'      /* Signal that a number was found */
/* getop: pointer version of getopt */
int getop(char *s)
{
    int i, c;

    while ((*s = c = getch()) == ' ' || c == '\t');
    *(s+1) = '\0';
    if (!isdigit(c) && c != '.')
        return c;           /* not a number */
    i = 0;
    if (isdigit(c))         /* collect integer part */
        while (isdigit(*++s = c = getch()));
    if (c == '.')           /* collect fraction part */
        while (isdigit(*++s = c = getch()));
    *s = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}

