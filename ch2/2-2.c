/* Date: 13/05/19
   Description: This program write for loop version without using 
                logical operator
*/
#include <stdio.h>
enum loop {NO, YES};
enum loop okloop = YES;

int main()
{
    int i, lim = 100;
    char c, s[lim];
    i = 0;
    while(okloop == YES) {
        if (i >= lim-1) 
            okloop = NO;
        else if ((c = getchar()) == '\n')
            okloop = NO;
        else if(c == EOF)
            okloop = NO;
        else {
            s[i] = c;
            ++i;
        }
    }
}