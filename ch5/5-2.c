/* Date: 23/06/19
   Description: collect floating value from input to array  */

#include <stdio.h>
#include <ctype.h>

#define BUFSIZE 100
#define SIZE    5
int bufp = 0;           /* next free position in buf */
char buf[BUFSIZE];      /* buffer for ungetch */


int getch(void);
void ungetch(int c);
int getfloat(float *pn);

int main()
{
    int n;
    float array[SIZE];
    
    for (n = 0; n < SIZE && getfloat(&array[n]) != EOF; n++)  /* getint into array */
    ;

    /*display collected ints */
    for( n = 0; n < SIZE; n++)
        printf("%g\n", array[n]);

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

/* getint: get next integer from input into *pn. Function type remains int*/
int getfloat(float *pn)
{
    int c, d, sign;
    float f;

    while (isspace(c = getch()))      /* skip white space */
    ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);                 /* it's not a number */
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
        c = getch();
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    /* check for fraction part */
    if (c == '.')
        c = getch();
    for (f = 1; isdigit(c); c = getch())
    {
        f /= 10;
        *pn += (c - '0') * f;
    }
    *pn *= sign; 
   
    if (c != EOF)
        ungetch(c);
    return c;
}