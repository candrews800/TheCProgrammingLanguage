/* Clinton Andrews
 * Date Created
 *
 * The C Programming Language
 * Exercise 5-7:
 * Rewrite readlines to store lines in an array supplied
 * by main, rather than calling alloc to maintain storage.
 * How much faster is the program?
 *
 */

#define MAXLEN 1000

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines, char currLine[])
{
	int len, nlines;
	char *p;

	nlines = 0;
	while ((len = getline(currLine, MAXLEN)) > 0) {
		if (nlines >= maxline || (p = alloc(len)) == NULL)
			return -1;
		else {
			currLine[len-1] = '\0';
			strcpy(p, currLine);
			lineptr[nlines++] = p;
		}
	}

	return nlines;
}
