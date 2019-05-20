/* Date: 20/05/19
   Description: program to convert character like \n, \t to visible escape sequence and
                visa vera
*/

#include <stdio.h>

void escape(char s[], char t[])
{
    int i, j;
    
    for (i = 0, j= 0; t[i] != '\0'; i++) {
        switch (t[i]) {
            case '\n':
                s[j++] = '\\';
                s[j++] = 'n';
                break;
            case '\t':
                s[j++] = '\\';
                s[j++] = 't';
                break;
            default:
                s[j++] = t[i];
                break;
        }
    }
    s[j] = '\0';  
}

void unescape(char s[], char t[])
{
    int i, j;
    
    for (i = 0, j= 0; t[i] != '\0'; i++) {
        if (t[i] == '\\'){
            switch (t[++i]) {
                case 'n':
                    s[j++] = '\n';
                    break;
                case 't':
                    s[j++] = '\t';
                    break;
            }
        }
        else
            s[j++] = t[i];
    }   
    s[j] = '\0';

}

int main()
{
    int max = 100;
    char t[] = "Dhruv\nMohindru\tPoonam\tMohindru";
    char s[max], s1[max];
    escape(s, t);
    printf("t: %s\n", t);
    printf("s: %s\n", s);
    unescape(s1, s);
    printf("s: %s\n", s);
    printf("s1: %s\n", s1);
    
}