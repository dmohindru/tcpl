/* Date: 08/04/19
   Description: Entab program to replace string of spaces with tabs 
*/
#include <stdio.h>

#define MAXLINE 1000    /* Maximum input line size */
#define TABSTOP 8       /* Tab stop position */

int mygetline(char line[], int maxline);
void entab(char new[], char old[]);

/* Print longest input line */
main()
{
    int len;        /* current line length */
    char line[MAXLINE];  /* current input line */
    char newline[MAXLINE]; /* detabbed line */

    while ((len = mygetline(line, MAXLINE)) > 0) {
        printf("%s", line);
        entab(newline, line);
        printf("%s", newline);
    }
        

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

/* new: buffer which contains detab string; 
   old: buffer that contains buffer with tabs */
void entab(char new[], char old[] )
{
    int i, j, k, nspace;
    char c;
    
    i = j = 0;
    while ((c=old[i]) != '\0') {
        if (c == '\t') {
            k = j / TABSTOP;        /* Get index into tab stops */
            nspace = TABSTOP -  (j - (k * TABSTOP)); /* Calucate no of spaces to next tab stop */
            /* Fill up blank spaces */
            k = j;
            while (j < k + nspace) {
                new[j] = ' ';
                ++j;
            }    
            /* increment i and j to point to next character */
            ++i;
        }
        else {
            new[j] = c;
            ++j;
            ++i;
        }
    }
    /* Terminate new string */
    new[j] = '\0';
}