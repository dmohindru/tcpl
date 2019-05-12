/* Date: 12/04/19
   Description: Program to check a c program for  unbalanced 
   parentheses, brackets, braces, quotes (single and double), 
   esacpe sequences and comments
*/
#include <stdio.h>
int check_comment();      /* Function to check comments block, return 1 on valid comments, 0 otherwise */

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


/* Function checks for proper comment block */
int check_comment()
{
    char c;
    int ret_val = 0; /* By default we assume it is a error */
    while ((c=getchar()) != EOF) {
        if (c == '*') { /* It may be a end of comment block */

        }

    }

    return ret_val;

}