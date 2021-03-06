/* Date: 05/04/19
   Description: Print lenght of arbitrarily long input lines
*/
#include <stdio.h>

#define MAXLINE 1000    /* Maximum input line size */

int mygetline(char line[], int maxline);
void copy(char to[], char from[]);

/* Print longest input line */
main()
{
    int len;        /* current line length */
    int max;        /* maximum lenght seen so far */
    char line[MAXLINE];  /* current input line */
    char longest[MAXLINE]; /* longest line saved here */

    max = 0;
    while ((len = mygetline(line, MAXLINE)) > 0)
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    
    if (max > 0)    /* there was a line */
        printf("%d %s", max, longest);
    
    return 0;
}

/* getline: read a line into s, return length */
int mygetline(char s[], int lim)
{
    int c, i, j;

    j = 0;    
    for (i=0; (c=getchar()) != EOF && c != '\n'; ++i)
        if (i < lim-2) {
            s[i] = c;
            j++;
        }
        
    if (c == '\n') {
        s[j] = c;
        ++j;
        ++i;
    }
    s[j] = '\0';
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