/* Clinton Andrews
 * 08-03-2016
 *
 * The C Programming Language
 * Exercise 5-11:
 * Modify the program detab to accept a list
 * of tab stops as arguments. Use the default tab
 * settings if there are no arguments.
 *
 */

#include <stdio.h>
#include <stdlib.h> /* for atoi() */

#define DEFAULT_SPACES  16

int main(int argc, char *argv[])
{
    int SPACES = DEFAULT_SPACES;
    if (argc > 1) {
        SPACES = atoi(*++argv);
    }

    int c, i, nt = SPACES;

    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            for (i=0;i<nt;++i)
                putchar(' ');

            nt = SPACES;
        } else if (c == '\n') {
            nt = SPACES;
            putchar(c);
        } else {
            nt = --nt == 0 ? SPACES : nt;
            putchar(c);
        }
    }
}

