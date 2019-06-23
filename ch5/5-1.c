/* Date: 23/06/19
   Description: collect integer from input to a array */

#include <stdio.h>
#include <ctype.h>

#define BUFSIZE 100
#define SIZE    10
int bufp = 0;           /* next free position in buf */
char buf[BUFSIZE];      /* buffer for ungetch */


int getch(void);
void ungetch(int c);
int getint(int *pn);

int main()
{
    int n, array[SIZE];
    
    for (n = 0; n < SIZE && getint(&array[n]) != EOF; n++)  /* getint into array */
    ;

    /*display collected ints */
    for( n = 0; n < SIZE; n++)
        printf("%d\n", array[n]);

    return 0;

}


/* getch: get a (possibly pushed back) character */
int getch(void) 
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

/*ungetch: push character back on input */
void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

/* getint: get next integer from input into *pn */
int getint(int *pn)
{
    int c, d, sign;

    while (isspace(c = getch()))      /* skip white space */
    ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);                 /* it's not a number */
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') {
        d = c;
        if (!isdigit(c = getch())) {
            if (c != EOF)
                ungetch(c);
            ungetch(d);
            return d;           /* return sign character */
        } 
    }
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}