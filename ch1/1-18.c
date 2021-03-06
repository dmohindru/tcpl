/* Date: 05/04/19
   Description: Program to reverse character string of input line
*/
#include <stdio.h>

#define MAXLINE 1000    /* Maximum input line size */

int mygetline(char line[], int maxline);
int removeblanks(char s[]);

/* Print longest input line */
main()
{
    int len;        /* current line length */
    char line[MAXLINE];  /* current input line */
    int i;

    while ((len = mygetline(line, MAXLINE)) > 0)
        if ((i = removeblanks(line)) > 0)
            printf("%d %s", i, line);
    return 0;
}

/* getline: read a line into s, return length */
int mygetline(char s[], int lim)
{
    int c, i;
    
    for (i=0; i < lim-1 && (c=getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

/* remove trailing blanks from line and return lenght of new line */
int removeblanks(char s[])
{
    int i = 0;
    
    /* find \n character */
    while (s[i] != '\n')
        ++i;
    --i;    /* Back off from \n character */
    
    /* move backwards till non blank character is found */
    while (i >=0 && (s[i] == ' ' || s[i] == '\t'))
        --i;

    if (i >= 0) {
        ++i;
        s[i] = '\n';        /* Put trailing \n character */
        ++i;
        s[i] = '\0';        /* Terminate string */
    }
    return i;
}