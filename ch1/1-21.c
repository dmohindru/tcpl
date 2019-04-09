/* Date: 09/04/19
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

/* new: buffer which contains entab string; 
   old: buffer that contains buffer with string of spaces
   logic: look of string of spaces where they start. It it
   continues to next tab stop, replace those spaces with a \t.
   Else do the normal copy. */
void entab(char new[], char old[] )
{
    int i, j, nspace;
    char c;
    
    i = j = nspace = 0;
    while ((c=old[i]) != '\0') {
        if (c == ' ') {
            if (i % TABSTOP == 0 && nspace > 0) { /* If we have reached next tab stop with space */
                new[j] = '\t';
                nspace = 1;
                ++j;
            }
            else
                ++nspace;
            
            ++i;
        }
        else {
            if (nspace > 0) {
                if (i % TABSTOP == 0) {
                    new[j] = '\t';
                    nspace = 0;
                    ++j;
                }
                else {
                    while (nspace > 0) {
                        new[j] = ' ';
                        ++j;
                        --nspace;
                    }
                }
            }
            new[j] = c;
            ++j;
            ++i;
        }
    }
    /* Terminate new string */
    new[j] = '\0';
}