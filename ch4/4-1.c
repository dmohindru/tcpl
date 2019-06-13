/* Date: 13/06/19
   Description: strindex which returns the position of rightmost occurrence of t in s
                or -1 if there is none.
*/

#include <stdio.h>
#define MAXLINE 1000

int getline(char line[], int max);
int strindex(char source[], char searchfor[]);

char pattern[] = "ould";    /* pattern to search for */

/* find all line matching pattern */
main()
{
    char line[MAXLINE];
    int found = 0;

    while (getline(line, MAXLINE) > 0)
        if (strindex(line, pattern) >= 0) {
            printf("%s", line);
            found++;
        }
    return found;
}

/* getline: get line into s, return lenght */
int getline(char s[], int lim)
{
    int c, i;

    i = 0;
    while (--lim > 0 && (c=getchar()) !=EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

/*strindex: return the position of right most occurrence of t in s, or -1 if there none */
int strindex(char s[], char t[])
{
    int i, j, k, m;

    /* find end of string */
    for (i = 0; s[i] != '\0'; i++);
    
    for (j = 0; t[j] != '\0'; j++);

    /* start comparing in reverse order */
    for (i--; i >=0; i--){

        for (k=i, m=j; m >=0 && s[k] == t[m]; k--, m--);
        if (m < 0)
            return k;
    } 
    return -1;
}