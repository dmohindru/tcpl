/* Date: 05/04/19
   Description: Program to remove trailing blanks and tabs from each line
                and delete entirely blank lines.
*/
#include <stdio.h>

#define MAXLINE 1000    /* Maximum input line size */

int mygetline(char line[], int maxline);
void copy(char to[], char from[]);
int removeblanks(char s[]);

/* Print longest input line */
main()
{
    int len;        /* current line length */
    char line[MAXLINE];  /* current input line */


    while ((len = mygetline(line, MAXLINE)) > 0)
        if (removeblanks(line) > 0)
            printf("%d %s", len, line);
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

/* copy: copy from 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[] )
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        i++;

}

/* remove trailing blanks from line and return lenght of new line */
int removeblanks(char s[])
{
    int i = 0;
    /* find \n character */
    while (s[i] != '\n')
        ++i;
    
    /* move backwards till non blank character is found */

    return i;
}