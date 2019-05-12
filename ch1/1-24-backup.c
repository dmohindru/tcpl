/* Date: 12/04/19
   Description: Program to check a c program for  unbalanced 
   parentheses, brackets, braces, quotes (single and double), 
   esacpe sequences and comments
*/
#include <stdio.h>

int braces, brack, paren;

void in_quote(int c);
void in_comment(void);
void search();

/* rudimentary syntax checker for C program */
main()
{
    int c;
    extern int braces, brack, paren;

    while((c = getchar()) != EOF) {
        if (c == '/') {
            if ((c = getchar()) == '*')
                in_comment();   /* insdie comment */
            else
                search(c);
        }
        else if (c == '\'' || c == '"')
            in_quote(c);        /* inside quote */
        else
            search(c);
        
        if (braces < 0) {
            printf("Unbalanced braces\n");
            braces = 0;
        }
        else if (brack < 0) {
            printf("Unbalanced brackets\n");
            brack = 0;
        }
        else if (paren < 0) {
            printf("Unbalanced parentheses\n");
            paren = 0;
        }
    }

    if (braces > 0)
        printf("Unbalanced braces\n");
    if (brack >0)
        printf("Unbalanced brackets\n");
    if (paren > 0)
        printf("Unbalanced parentheses\n");
        
}

/* search: search for rudimentary syntax errors */
void search(int c)
{
    extern int braces, brack, paren;

    if (c == '{')
        ++braces;
    else if (c == '}')
        --braces;
    else if (c == '[')
        ++brack;
    else if (c == ']')
        --brack;
    else if (c == '(')
        ++paren;
    else if (c == ')')
        --paren;
}

/* in_comment: inside of a valid comment */
void in_comment()
{
<<<<<<< HEAD
    char c;
    int ret_val = 0; /* By default we assume it is a error */
    while ((c=getchar()) != EOF) {
        if (c == '*') { /* It may be a end of comment block */

        }

||||||| merged common ancestors
    char c;
    int ret_val = 0; /* By default we assume it is a error */
    while ((c=getchar()) != EOF) {
        
=======
    int c, d;
    c= getchar();                   /* prev character */
    d = getchar();                  /* curr character */
    while (c != '*' || d != '/') {  /* search for end */
        c = d;
        d = getchar();
>>>>>>> 49f12eb1937bb3aaff1d2bf1f0cdcd837cd2a497
    }
}

/* in_quote: inside quote */
void in_quote(int c)
{
    int d;

<<<<<<< HEAD
    return ret_val;

||||||| merged common ancestors
=======
    while ((d = getchar()) != c)        /* search end quote */
        if (d == '\\')                  /* igore escape seq */
            getchar();
>>>>>>> 49f12eb1937bb3aaff1d2bf1f0cdcd837cd2a497
}