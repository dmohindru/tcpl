/* Date: 12/04/19
   Description: Program to check a c program for  unbalanced 
   parentheses, brackets, braces, quotes (single and double), 
   esacpe sequences and comments
*/
#include <stdio.h>
int comments();      /* Function to check comments block */

main()
{
    char c, nextc;

    while ((c = getchar()) != EOF) {
        if (c == '/') {/* It maybe a start of comment block */ 
            nextc = getchar();
            if (nextc == '*') {  /* Its a start of comment block, mark its begining */

            }
        }
        
    }
    return 0;
        
            
}