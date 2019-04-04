#include <stdio.h>

#define IN              0           /* inside a word  */
#define OUT             1           /* outside a word */
#define MAX_WORD_LEN    11          /* Maximum lenght of word */
#define MAX_HIST        30          /* Maximum lenght count */

/* print histrogram of different length of words */

main()
{
    int c, i, wlen, state, word_histro[MAX_WORD_LEN];
    state = OUT;
    wlen = 0;

    /* Initalize array */
    for (c = 0; c < MAX_WORD_LEN; c++)
        word_histro[c] = 0;


    while ((c = getchar()) != EOF) {

        if (c == ' ' || c =='\n' || c == '\t') {
            state = OUT;
            if (wlen > 0 && wlen < MAX_WORD_LEN)
                ++word_histro[wlen];
            wlen = 0;
        }
            
        else if (state == OUT) {
            state = IN;
            ++wlen;
        }
        else
            ++wlen;
    }

    /* Display results
       Skip words of zero length 
    */

    for (c = 1; c < MAX_WORD_LEN; c++) {
        printf("%d: ", c);
        if (word_histro[c] < MAX_HIST)
            i = word_histro[c];
        else
            i = MAX_HIST;
        
        while (i >= 1) {
            printf("=");
            --i;
        }
        printf("\n");
    }
}