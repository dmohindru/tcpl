/* Date: 11/04/19
   Description: remove all comments from a C program
*/
#include <stdio.h>

/* Print longest input line */
main()
{
    char c, prevc;
    int comments = 0;

    while ((c = getchar()) != EOF) {
        if (c =='/' && comments == 0) {  /* May be its a start of comment don't print '/' yet */
            prevc = c;
        }
        else if (prevc == '/' && c == '*' && comments == 0) {  /* Definately its a start of comment don't print anything */
            comments = 1;
            prevc = 0;
        }
        else if (c == '*' && comments == 1) /* It may be end of comments so record it */ 
            prevc = c;
        else if (prevc == '*' && c == '/' && comments == 1) { /* Definately its a end of comments, start print chars */
            comments = 0;
            prevc = 0;
        }

        if (comments == 0) {
            //if (prevc == '/')
            //    putchar(prevc);
            putchar(c);

        }
            
    }
    
    return 0;
}
