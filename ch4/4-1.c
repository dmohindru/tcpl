/* Date: 13/06/19
   Description: strindex which returns the position of rightmost occurrence of t in s
                or -1 if there is none.
*/

#include <stdio.h>
#define MAXLINE 1000

int mygetline(char line[], int max);
int strindex(char source[], char searchfor[]);

char pattern[] = "ould";    /* pattern to search for */

/* find all line matching pattern */
int main()
{
    char line[MAXLINE];
    int found = 0;

    while (mygetline(line, MAXLINE) > 0) {

        if ((found = strindex(line, pattern)) >= 0) {
            printf("found string at index %d\n", found);
        }
    }
    return 0;
}

/* getline: get line into s, return lenght */
int mygetline(char s[], int lim)
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
    int i, j, s_end, t_end;

    /* find end of string */
    for (s_end = 0; s[s_end] != '\0'; s_end++);
    
    for (t_end = 0; t[t_end] != '\0'; t_end++);

    /* start comparing in reverse order */
    for (s_end--; s_end >=0; s_end--){

        for (i=s_end, j=t_end-1; j >=0 && s[i] == t[j]; i--, j--);
        if (j < 0)
            return i + 1;
    } 
    return -1;
}