/* Clinton Andrews
 * 2016-05-05
 *
 * The C Programming Language
 * Exercise 1-22:
 * Write a program to "fold" long input lines into two or more
 * shorter lines after the last non-blank character that occurs before
 * the n-th column of input. Make sure your program does something intelligent
 * with very long lines, and if there are no blanks or tabs before the
 * specified column.
 *
 */

#include <stdio.h>

#define MAXLINE	1000

main()
{
	int c, i, line_size = 0, word_size = 0;
	int COLUMNS = 40, TABSIZE = 8;
	char word[MAXLINE];

	while ((c = getchar()) != EOF) {
		if (c != ' ' && c != '\t' && c != '\n') {
			word[word_size] = c;
			++word_size;

			if (word_size > 10 && line_size + word_size > COLUMNS + 5) {
				for (i=0; i<word_size; ++i) {
					if (line_size + 1 == COLUMNS) {
						putchar('-');
						putchar('\n');
						line_size = 0;
					}

					putchar(word[i]);
					++line_size;
				}
				word_size = 0;
			}
		} else {
			word[word_size] = '\0'; // The word is ended

			if (line_size + word_size > COLUMNS) {
				printf("\n%s%c", word, c);
				line_size = word_size + 1;
			} else {
				if (c == '\n') {
					line_size = word_size;
				} else {
					line_size = line_size + word_size + 1;
				}
				printf("%s%c", word, c);
			}

			if (c == '\t')
				line_size = line_size + 7;

			word_size = 0;
		}
	}

	putchar('\n');
}
