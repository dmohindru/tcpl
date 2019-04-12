
#include <stdio.h>



main()
{
    char c, nextc;
    int multi_comments = 0; 
    int single_comments = 0; 

    while ((c = getchar()) != EOF) {
        if (c == '/' && multi_comments == 0 && single_comments == 0) { 
            nextc = getchar();
            if (nextc == '*')  
                multi_comments = 1;
            else if (nextc == '/') 
                single_comments = 1;
            else { 
                putchar(c);
                putchar(nextc);
            }
        }
        else if(c == '*' && multi_comments == 1) {
            nextc = getchar();
            if (nextc == '/') 
                multi_comments = 0;    
        }
        else if(c == '\n' && single_comments == 1) { 
            putchar(c);
            single_comments = 0;
        }
        else if (multi_comments == 0 && single_comments == 0)
            putchar(c);
    }
    return 0;
        
            
}
    
    

