/* Date: 28/06/19
   Description: readlines using array provided by main function */

#include <stdio.h>
#include <string.h>

#define MAXLEN      1000        /* max lenght of any input line */
#define MAXSTORE    5000        /* max character of all input line */

/* readline: read input lines */
int readline(char *lineptr[], char *linestore, int maxlines)
{
    int len, nlines;
    char *p, *linestop, line[MAXLEN];
    
    p = linestore;
    linestop = linestore + MAXSTORE;
    nlines = 0;
    while ((len = getline(line, MAXLEN)) > 0)
        if (nlines >= maxlines || p + len > linestop)
            return -1;
        else {
            line[len-1] = '\0';  /* delete newline */
            strcpy(p, line);
            lineptr[nlines++] = p;
            p += len;
        }
        return nlines;
}