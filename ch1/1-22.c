/* Date: 09/04/19
   Description: Fold long input line into one or more line after non-blank 
                character occurs before nth column
*/
#include <stdio.h>

#define MAXCOL 10   /* maximum column of input */
#define TABINC 8    /* tab increment size */

char line[MAXCOL];  /* input line */

int expandtab(int pos);
int findblnk(int pos);
int newpos(int pos);
void printl(int pos);

/* fold long input lines into two or more shorter lines */
main()
{
    int c, pos;

    pos = 0;
    while ((c = getchar()) != EOF) {
        line[pos] = c;      /* store current character */
        if (c == '\t')      /* expand current character */
            pos = expandtab(pos);
        else if (c == '\n') {
            printl(pos);    /* print the current input line */
            pos = 0;
        }
        else if (++pos >= MAXCOL) {
            pos = findblnk(pos);
            printl(pos);
            pos = newpos(pos);
        }
    }
}

/*printl: print line unitl pos column */
void printl(int pos)
{
    int i;

    for (i = 0; i < pos; ++i)
        putchar(line[i]);
    if (pos > 0)        /* any chars printed */
        putchar('\n');

}

/* expandtab: expand tab into blanks */
int expandtab(int pos)
{
    line[pos] = ' ';    /* tab is at least one blank */
    for (++pos; pos < MAXCOL && pos % TABINC != 0; ++pos)
        line[pos] = ' ';
    if (pos < MAXCOL)   /* room left in current line */
        return pos;
    else {
        printl(pos);    /* reset current position */
        return 0;
    }
}

/* findblnk: find blank's position */
int  findblnk(int pos)
{
    while (pos > 0 && line[pos] != ' ')
        --pos;
    if (pos == 0)       /* no blanks in line */
        return MAXCOL;
    else                /* at least one blank */
        return pos+1;   /* position after the blank */
}

/* newpos: rearrange line with new position */
int newpos(int pos)
{
    int i, j;

    if (pos <= 0 || pos >= MAXCOL)
        return 0;               /* nothing to rearrange */
    else {
        i = 0;
        for (j = pos; j < MAXCOL; j++) {
            line[i] = line[j];
            ++i;
        }
        return i;   /* new position in line */
    }
}
