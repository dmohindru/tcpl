/* Date: 16/06/19
   Description: Reverse polish calculator
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAXOP   100     /* Max sixe of operand or operator */
#define NUMBER '0'      /* Signal that a number was found */
#define NAME    'n'     /* Signal that it is a name */
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
void clear(void); /* Function to stack */
void mathfunc(char []); /* Function for various math functions */

/* reverse Polish calculator */

int main()
{
    int type, i, var;
    double op2, op3, v;
    char s[MAXOP];
    double variable[26];

    for (i = 0; i < 26; i++)
        variable[i] = 0.0;

    while((type = getop(s)) != EOF) {
        printf("type: %d\n", type);
        switch (type) {
            
            case NUMBER:
                push(atof(s));
                break;
            case NAME:
                mathfunc(s);
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
            case '%':
                op2 = pop();
                if (op2 != 0.0)
                    push((int)pop() % (int)op2);
                else
                    printf("error: zero divisor\n");
                break;
            case '#':   /* print top element of stack */
                op2 = pop();
                printf("\t%.8g\n", op2);
                if (op2 != 0.0)
                    push(op2);
                break;
            case '$':   /* duplicate top elements of stack */
                op2 = pop();
                push(op2);
                push(op2);
                break;
            case '@':   /* swap top two elements of stack */
                op2 = pop();
                op3 = pop();
                push(op2);
                push(op3);
                break;
            case '!':   /* clear stack */
                clear();
                break;
            case '=':
                pop();
                if (var >='A' && var <='Z')
                    variable[var - 'A'] = pop();
                else
                    printf("Variable not supported\n");
                break;
                
            case '\n':
                v = pop();
                printf("\t%.8g\n", v);
                break;
            default:
                if (type >= 'A' && type <='Z')
                    push(variable[type - 'A']);
                else if (type == 'v')
                    push(v);
                else
                    printf("error: unknown command %s\n", s);
                break;
        }
        var = type;
    }
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
int getop(char s[])
{
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t');
    s[1] = '\0';
    
    i = 0;
    if (islower(c)) { /* Command or a name */
        while (islower(s[++i] = c = getch()));
        s[i] = '\0';
        if (c != EOF)
            ungetch(c);
        if (strlen(s) > 1)      /* It may be a name */
            return NAME;
        else 
            return c;           /* It may be a command */
    
    }
    
    if (!isdigit(c) && c != '.' && c != '-')
        return c;           /* not a number */

    if (c == '-') { /* It may be a negetive number or minus sign */
        if (isdigit(c = getch()) || c == '.' ) /* its a negetive number */
            s[++i] = c;
        else {  /* Its a negetive sign */
            if (c != EOF)
                ungetch(c);
            return '-';
        }

    }
    if (isdigit(c))         /* collect integer part */
        while (isdigit(s[++i] = c = getch()));
    if (c == '.')                       /* collect fraction part */
        while (isdigit(s[++i] = c = getch()));
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
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

/*ungets: push string back onto input */
void ungets(char s[])
{
    /* Ungets does need to know about buf and bufp. As its details are handled by ungetch and its error handling */
    int len = strlen(s);
    while (len > 0)
        ungetch(s[--len]);
}

/*clear: clear stack */
void clear(void)
{
    sp = 0;
}

/*mathfunc: perform various math functions */
void mathfunc(char s[])
{
    double op2;
    if (strcmp(s, "sin") == 0) {
        push(sin(pop()));
    }
    else if (strcmp(s, "cos") == 0) {
        push(cos(pop()));
    }
    else if (strcmp(s, "exp") == 0) {
         push(exp(pop()));
    }
    else if (strcmp(s, "pow") == 0) {
        op2 = pop();
        push(pow(pop(), op2));
    }
    else {
        printf("error: %s not supported\n", s);
    }
}

