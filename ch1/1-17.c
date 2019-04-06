/* Date: 06/04/19
   Description: Print line that are longer than 80 characters
*/
#include <stdio.h>

#define MAXLINE 1000    /* Maximum input line size */
#define LONGLINE 80      /* Maximum limit for line to be printed */

int mygetline(char line[], int maxline);
void copy(char to[], char from[]);

/* Print longest input line */
main()
{
    int len;        /* current line length */
    char line[MAXLINE];  /* current input line */

    while ((len = mygetline(line, MAXLINE)) > 0)
        if (len > LONGLINE)
            printf("%s", line);
    
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