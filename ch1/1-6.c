#include <stdio.h>

/* Copy input to output */

main()
{
    int c;

    while (c = getchar() != EOF)
        printf("%d", c);
    printf("%d - at EOF\n", c);
}