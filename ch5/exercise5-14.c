/* Clinton Andrews
 * 11-08-2016
 *
 * The C Programming Language
 * Exercise 5-14:
 * Modify the sort program to handle a -r flag, which indicates
 * sorting in reverse (decreasing) order. Be sure that -r works
 * with -n.
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

void mqsort(void *lineptr[], int left, int right, int (*comp)(void *, void *), int reverse);
int numcmp(char *, char *);

int main(int argc, char *argv[])
{
    int nlines;
    int numeric = 0, reverse = 0;

    while (--argc && ++argv) {
        if (strcmp(*argv, "-r") == 0) {
            reverse = 1;
        } else if (strcmp(*argv, "-n") == 0) {
            numeric = 1;
        }
    }

    if (argc > 1 && strcmp(argv[1], "-n") == 0)
        numeric = 1;
    if ((nlines = readlines(lineptr, MAX_LINES)) >= 0) {
        mqsort((void **) lineptr, 0, nlines-1, (int (*)(void*,void*))(numeric ? numcmp : strcmp), reverse);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("input too big to sort\n");
        return 1;
    }
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

void mqsort(void *v[], int left, int right, int (*comp)(void *, void *), int reverse)
{
    int i, last;

    void swap(void *v[], int, int);

    if (left >= right)
        return;
    swap(v, left, (left + right)/2);
    last = left;
    for (i = left+1; i <= right; i++)
        if (!reverse && (*comp)(v[i], v[left]) < 0)
            swap(v,  ++last, i);
        else if (reverse && (*comp)(v[i], v[left]) > 0)
            swap(v,  ++last, i);
    swap(v, left, last);
    mqsort(v, left, last-1, comp, reverse);
    mqsort(v, last+1, right, comp, reverse);
}

int numcmp(char *s1, char *s2)
{
    double v1, v2;

    v1 = atof(s1);
    v2 = atof(s2);
    if (v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else
        return 0;
}

void swap(void *v[], int i, int j)
{
    void *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}