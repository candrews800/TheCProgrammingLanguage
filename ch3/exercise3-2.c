/* Clinton Andrews
 * 2016-06-01
 *
 * The C Programming Language
 * Exercise 3-2:
 * Write a function escape(s,t) that converts characters like
 * newline and tab into visible escape sequences like \n and \t
 * as it copies the string t to s. Write a function for the 
 * other direction as well, converting escape sequences into the
 * real characters.
 *
 */

void escape(char s[], char t[]);
void deescape(char s[], char t[]);

#include <stdio.h>

main()
{
	char s[1000] = "This \n has \n new \n lines.";
	char t[1000];

	escape(s,t);
	printf("%s\n", s);
	printf("%s\n", t);

	deescape(t, s);
	printf("%s\n", t);
	printf("%s\n", s);
}

void escape(char s[], char t[])
{
	int i, added = 0;

	for (i = 0; s[i] != '\0'; ++i) {
		switch(s[i]) {
		case '\n':
			t[i+added] = '\\';
			++added;
			t[i+added] = 'n';
			break;
		case '\t':
			t[i+added] = '\\';
			++added;
			t[i+added] = 't';
			break;
		default:
			t[i+added] = s[i];
			break;
		}
	}
	t[i+added] = '\0';
}

void deescape(char s[], char t[])
{
	int i, removed = 0;
	for (i = 1; s[i] != '\0'; ++i) {
		if (s[i-1] == '\\') {
			switch(s[i]) {
			case 'n':
				t[i-removed-1] = '\n';
				++removed;
				break;
			case 't':
				t[i-removed-1] = '\t';
				++removed;
				break;
			default:
				t[i-removed-1] = '\\';
				t[i-removed] = s[i];
				break;
			}
		} else {
			t[i-removed] = s[i];
		}
	}
}
