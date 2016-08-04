/* Clinton Andrews
 * 04-08-2016
 *
 * The C Programming Language
 * Exercise 5-13:
 * Write the program tail, which prints the last n lines of its
 * input. By default, n is 10, let us say but it can be changed
 * by an optional argument, so that
 *
 * tail -n
 *
 * prints the last n lines. The program should behave rationally
 * now matter how unreasonable the input or the value of n. Write
 * the program so it makes the best use of storage; lines should
 * be stored as in the sorting program of Section 5.6, not in a
 * two dimensional array of fixed size.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEFAULT_LINES   10
#define MAX_LINES   5000

#define ALLOCSIZE   10000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(int n)
{
    if (allocbuf + ALLOCSIZE - allocp >= n) {
        allocp += n;
        return allocp - n;
    } else
        return 0;
}

void afree(char *p)
{
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
        allocp = p;
}

char *lineptr[MAX_LINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
int mgetline(char s[], int lim);

int main(int argc, char *argv[])
{
    int nlines;
    int last_n = DEFAULT_LINES;

    while (*++argv != 0) {
        if ((*argv)[0] == '-') {
            last_n = atoi(&(*argv)[1]) ?: DEFAULT_LINES;
        }
    }

    nlines = readlines(lineptr, MAX_LINES);
    if (last_n > nlines) {
        last_n = nlines;
    }
    writelines(&lineptr[nlines - last_n], last_n);
    return 0;
}

int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAX_LINES];

    nlines = 0;
    while ((len = mgetline(line, MAX_LINES)) > 0)
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
            return -1;
        else {
            line[len - 1] = '\0'; /* delete newline */
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    return nlines;
}

void writelines(char *lineptr[], int nlines)
{
    int i;

    for (i = 0; i < nlines; i++)
        printf("%s\n", lineptr[i]);
}

int mgetline(char s[], int lim)
{
    int c, i;

    i = 0;
    while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}
