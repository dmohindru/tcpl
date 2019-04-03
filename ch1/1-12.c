#include <stdio.h>

#define IN  0           /*  inside a word  */
#define OUT 1           /*  outside a word */

/* count lines, words, and characters in input */

main()
{
    int c, state;

    state = OUT;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c =='\n' || c == '\t') {
            if (state == OUT) {
                state = IN;
                putchar('\n');
            }
        }
        else if (state == IN) {
            state = OUT;
            putchar(c);
        }
        else 
            putchar(c);
    }
}