#include <stdio.h>

#define MAX_HIST        30          /* Maximum lenght count */

/* print histrogram of different length of words */

main()
{
    int nchars = '~' - ' ' + 1;  /* No of printable ascii characters */
    int c, i, char_histro[nchars];
    

    /* Initalize array */
    for (c = 0; c < nchars; c++)
        char_histro[c] = 0;

    while ((c = getchar()) != EOF)
        if ((c - ' ') < nchars)
            ++char_histro[c - ' '];

    /* Display results */

    for (c = 0; c < nchars; c++) {
        printf("%c: ", c + ' ');
        if (char_histro[c] < MAX_HIST)
            i = char_histro[c];
        else
            i = MAX_HIST;
        
        while (i >= 1) {
            printf("=");
            --i;
        }
        printf("\n");
    }
}