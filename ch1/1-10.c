#include <stdio.h>

/* Replace each tab by \t, backspace by \b and each backslast by \\ */

main()
{
    int c;

    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            putchar('\\');
            putchar('t');

        }
        else if (c == '\b') {
            putchar('\\');
            putchar('b');
        }
        else if (c == '\\') {
            putchar('\\');
            putchar('\\');
        }
        else
            putchar(c);
        
    }
}