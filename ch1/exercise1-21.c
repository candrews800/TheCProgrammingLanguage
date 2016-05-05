/* Clinton Andrews
 * 2016-05-04
 *
 * The C Programming Language
 * Exercise 1-21:
 * Write a program entab that replaces strings of blanks by the
 * minimum number of tabs and blanks to achieve the same spacing.
 * Use the same tab stops as for detab. When either a tab or a
 * single blank would suffice to reach a tab stop, which should
 * be given preference?
 * Answer: Single blank - normal program input has places where
 * a single space would be in this case.
 *
 */

#include <stdio.h>

main()
{
	int SPACES = 8;

	int c, i, s = 0, t = 0;

	while ((c = getchar()) != EOF) {
		++t;
		if (c == '\t' || c == '\n') {
			s = 0;
			t = 0;
			putchar(c);
		} else if (c != ' ') {
			// Output 'saved' spaces
			for (i=0;i<s;++i)
				putchar(' ');
			s = 0;
			putchar(c);
		} else {
			++s;
		}

		if (t == SPACES && s > 1) {
			putchar('\t');
			t = 0;
			s = 0;
		} else if (t == SPACES && s == 1) {
			putchar(' ');
			t = 0;
			s = 0;
		} else if (t == 8) {
			t = 0;
			s = 0;
		}
	}
}
