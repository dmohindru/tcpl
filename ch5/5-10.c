/* Date: 01/07/19
   Description: Reverse polish calculator taking its input from command line
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXOP   100     /* Max sixe of operand or operator */
#define NUMBER '0'      /* Signal that a number was found */
#define MAXVAL  100     /* maximum depth of val stack */
#define BUFSIZE 100
int sp = 0;             /* next free stack position */
double val[MAXVAL];     /* value stack */
int bufp = 0;           /* next free position in buf */
char buf[BUFSIZE];      /* buffer for ungetch */

int getop(char []);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);

/* reverse Polish calculator */

int main(int argc, char *argv[])
{
    int type;
    double op2;
    char s[MAXOP];

    if (argc < 4) {
        printf("usage: expr num1 num2 operator\n");
        return 1;
    }
    /* while (*++argv) 
        printf("%s\n", *argv);

    return 0; */
    while (*++argv) {
        type = getop(*argv);
        switch (type) {
            case NUMBER:
                //printf("Got a number\n");
                push(atof(*argv));
                break;
            case '+':
                //printf("Got a +\n");
                push(pop() + pop());
                break;
            case '*':
                //printf("Got a *\n");
                push(pop() * pop());
                break;
            case '-':
                //printf("Got a -\n");
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                //printf("Got a /\n");
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
            default:
                printf("error: unknown command %s\n", *argv);
                break;
        }
    }
    /* Print result */
    printf("\t%.8g\n", pop());
    return 0;
}

/* push: push f onto value stack */
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

/* getop: get next operator or numeric operand */
int getop(char *s)
{
    int c;

    c = *s;
    if (!isdigit(c) && c != '.')
        return c;           /* not a number */
    if (isdigit(c))         /* collect integer part */
        while (++s != NULL && isdigit(*s));
    if (*s == '.')           /* collect fraction part */
        while (++s != NULL && isdigit(*s));
    return NUMBER;
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
