/* Date: 09/04/19
   Description: Fold long input line into one or more line after non-blank 
                character occurs before nth column
*/
#include <stdio.h>

#define MAXLINE 1000    /* Maximum input line size */
#define FOLDCOLUMN 10   /* Column where line has to be folded */ 

int mygetline(char line[], int maxline);
void fold(char to[], char from[]);

/* Print longest input line */
main()
{
    int len;        /* current line length */
    int max;        /* maximum lenght seen so far */
    char line[MAXLINE];  /* current input line */
    char newline[MAXLINE]; /* longest line saved here */

    max = 0;
    while ((len = mygetline(line, MAXLINE)) > 0) {
        fold(newline, line);
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

/* fold: fold from 'from' into 'to'; assume to is big enough */
void fold(char to[], char from[] )
{
    int i, j, k, colpos;
    char c;

    i = 0;
    j = 0;
    k = -1;
    colpos = 0;
    while ((c=from[i]) != '\0') {
        if (c == ' ' || c == '\t' || c == '\n')
            k = i;
        
        if (colpos >= FOLDCOLUMN) {
            if (k > -1) {
                to[k] = '\n';
                to[j] = from[i];
            }   
            else {
                to[j] = '\n';
                ++j;
                to[j] = from[i];
            }
            colpos = 0;
            k = -1;
            
        }
        else {
            to[j] = from[i];
            
        }
            
        ++i;
        ++j;
        ++colpos;
    } 
    /* Terminate new string */
    to[j] = '\0';     
}