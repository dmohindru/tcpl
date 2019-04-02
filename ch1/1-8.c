#include <stdio.h>

/* Count blanks, tabs and new lines */

main()
{
    int nb, nt, nl, c;
    nb = nt = nl = 0;

    while ((c = getchar()) != EOF) {
        if (c == '\n')
            ++nl;
        else if (c == '\t')
            ++nt;
        else if (c == ' ')
            ++nb;

    }
    printf("Number of blanks: %d\n", nb);
    printf("Number of tabs: %d\n", nt);
    printf("Number of newlines: %d\n", nl);

}