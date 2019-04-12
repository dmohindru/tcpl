/* Date: 12/04/19
   Description: Program to check a c program for  unbalanced 
   parentheses, brackets, braces, quotes (single and double), 
   esacpe sequences and comments
*/
#include <stdio.h>

main()
{
    char c, nextc;
    int multi_comments = 0; /* Multiple line comments */
    int single_comments = 0; /* Single line comments */

    while ((c = getchar()) != EOF) {
        if (c == '/' && multi_comments == 0 && single_comments == 0) {/* It maybe a start of comment block */ 
            nextc = getchar();
            if (nextc == '*')  /* Its a start of comment block, mark its begining */
                multi_comments = 1;
            else if (nextc == '/') // Its a start of single line comment
                single_comments = 1;
            else { /* Its not a comment block print c and nextc */
                putchar(c);
                putchar(nextc);
            }
        }
        else if(c == '*' && multi_comments == 1) {/* It maybe a end of comment block */
            nextc = getchar();
            if (nextc == '/') /* Its a end of comment block, mark its end */
                multi_comments = 0;    
        }
        else if(c == '\n' && single_comments == 1) { // Its a end of single line comment
            putchar(c);
            single_comments = 0;
        }
        else if (multi_comments == 0 && single_comments == 0)
            putchar(c);
    }
    return 0;
        
            
}