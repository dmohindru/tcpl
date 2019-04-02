#include <stdio.h>

/* Replace each string of one or more blanks by a single blank */
#define NONBLANK 'a'

main()
{
    int c, lastc;
    lastc = NONBLANK;

    while ((c = getchar()) != EOF) {
        if (c != ' ' || lastc != ' ')
            putchar(c);
        lastc = c;
    }
}