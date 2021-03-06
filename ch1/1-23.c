/* Date: 11/04/19
   Description: remove all multi line and single line comments from a C program
*/
#include <stdio.h>

/* Print longest input line */
/*
1. Read character
2. If char is / it might be a start of comment don't print it yet
3. Read next char, if its * then mark a start of comment.
4. Keep reading and don't print any char util char * is read. Which might indicate a end of comment
5. Read next char if its a / char, mark end of comment and start printing any further chars read.
*/
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
    
    

