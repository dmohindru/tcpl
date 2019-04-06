/* Date: 05/04/19
   Description: Program to reverse character string of input line
*/
#include <stdio.h>

#define MAXLINE 1000    /* Maximum input line size */

int mygetline(char line[], int maxline);
void reverse(char s[]);

/* Print longest input line */
main()
{
    int len;        /* current line length */
    char line[MAXLINE];  /* current input line */
    int i;

    while ((len = mygetline(line, MAXLINE)) > 0) {
        reverse(line);
        printf("%s", line);
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

/* Function to reverse character string */
void reverse(char s[])
{
    int i, j;
    char temp;
    
    /* Move till end */
    i = 0;
    while (s[i] != '\0')
        ++i;
    
    --i;   /* Backoff one position from '\0' character */
    if (s[i] == '\n') /* If its a new line character leave in its place */
        --i;
    

    /* Start reversing characters */
    j = 0;
    while (j < i) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        ++j;
        --i;
    }
}