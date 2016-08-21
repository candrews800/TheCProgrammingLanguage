/* Clinton Andrews
 * 17-08-2016
 *
 * The C Programming Language
 * Exercise 6-1:
 * Our version of getword does not properly handle underscores, string
 * constants, comments, or preprocessor control lines. Write a better
 * version.
 *
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100
#define NKEYS (sizeof keytab / sizeof keytab[0])

#define BUFSIZE	100

char buf[BUFSIZE];	/* buffer for ungetch */
int bufp = 0;		/* next free position in buf */

int getch(void);
void ungetch(int);

struct key {
    char *word;
    int count;
} keytab[] = {
        "auto", 0,
        "break", 0,
        "case", 0,
        "char", 0,
        "const", 0,
        "continue", 0,
        "default", 0,
        "double", 0,
        "float", 0,
        "int", 0,
        "return", 0,
        "signed", 0,
        "sizeof", 0,
        "struct", 0,
        "unsigned", 0,
        "void", 0,
        "volatile", 0,
        "while", 0,
};

int getword(char *, int);
struct key *binsearch(char *, struct key *, int);
int isAlphaUnderscore(char);

/* count C keywords */
int main()
{
    char word[MAXWORD];
    struct key *p;

    while (getword(word, MAXWORD) != EOF)
        if (isAlphaUnderscore(word[0]))
            if ((p=binsearch(word, keytab, NKEYS)) != NULL)
                p->count++;
    for (p = keytab; p < keytab + NKEYS; p++)
        if (p->count > 0)
            printf("%4d %s\n", p->count, p->word);
    return 0;
}

/* getword: get next word or character from input */
int getword(char *word, int lim)
{
    static int inBlockComment = 0;
    static int inLineComment = 0;
    static int inQuote = 0;
    static int lastC = EOF;

    int c, getch(void), turnedOff = 0;
    void ungetch(int);
    char *w = word;

    while (isspace(c = getch()))
        if (c == '\n' && (inLineComment || inQuote)) {
            inLineComment = 0;
            inQuote = 0;
        }

    if (c != EOF)
        *w++ = c;

    if (lastC == '/' && c == '*') {
        inBlockComment = 1;
    }

    if (lastC == '/' && c == '/') {
        inLineComment = 1;
    }

    if (lastC == '*' && c == '/' && inBlockComment)
        inBlockComment = 0;

    if (c == '"') {
        inQuote = 1;
    }

    lastC = c;

    if (!isAlphaUnderscore(c) || inQuote || inLineComment || inBlockComment) {
        *w = '\0';
        return c;
    }
    for ( ; --lim > 0; w++) {
        c = *w = getch();
        if (c == '\n') {
            inLineComment = 0;
            inQuote = 0;
        }

        if (c == '"' && inQuote && !inBlockComment) {
            inQuote = 0;
            turnedOff = 1; // We need make sure we signal this quote is the end
        }

        if (lastC == '*' && c == '/' && inBlockComment)
            inBlockComment = 0;

        if (inQuote || inLineComment || inBlockComment) {
            word[0] = '\0';
            return word[0];
        }

        if (lastC == '/' && c == '*') {
            inBlockComment = 1;
        }

        if (lastC == '/' && c == '/') {
            inLineComment = 1;
        }

        if (c == '"' && !turnedOff) {
            inQuote = 1;
        }

        if (inQuote || inLineComment || inBlockComment) {
            *(--w) = '\0';
            return word[0];
        }

        lastC = c;
        turnedOff = 0;

        if (!isAlphaUnderscore(c)) {
            ungetch(*w);
            break;
        }
    }
    *w = '\0';
    return word[0];
}

/* binsearch: find word in tab[0]...tab[n-1] */
struct key *binsearch(char *word, struct key *tab, int n)
{
    int cond;
    struct key *low = &tab[0];
    struct key *high = &tab[n];
    struct key *mid;

    while (low < high) {
        mid = low + (high-low) / 2;
        if((cond = strcmp(word, mid->word)) < 0)
            high = mid;
        else if (cond > 0)
            low = mid + 1;
        else
            return mid;
    }
    return NULL;
}

int getch(void) /* get a (possibily pushed back) character */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* push character back on input */
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

int isAlphaUnderscore(char c)
{
    if (!isalpha(c) && c != '_')
        return 0;

    return 1;
}