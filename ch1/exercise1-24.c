/* Clinton Andrews
 * 2016-05-07
 *
 * The C Programming Language
 * Exercise 1-24:
 * Write a program to check a C program for rudimentary syntax
 * errors like unbalanced parentheses, brackets and braces. Don't forget
 * about quotes, both single and double, escape sequences, and comments.
 * (This program is hard if you do it in full generality.)
 *
 * ()[](){()((())){()()((){}()()()(){}()()(()){()}}()}(){()[]}
 */

#include <stdio.h>

int checkSyntax(char c);

char stack[1000];
int l = 0;

main()
{
	int c, w = '1', last_c = getchar(), i, line_num = 1;

	int MULTI = 0, SINGLE = 0, MULTIQUOTE = 0, SINGLEQUOTE = 0, IGNORE = 0;

	while ((c = getchar()) != EOF) {
		if (IGNORE) {
			IGNORE = 0;
			last_c = c;
			continue;
		}

		if (last_c == '/' && c == '*' && !SINGLE && !MULTIQUOTE && !SINGLEQUOTE)
			MULTI = 1;
		else if (last_c == '/' && c == '/' && !MULTI && !MULTIQUOTE && !SINGLEQUOTE)
			SINGLE = 1;
		else if (last_c == '\\' && (SINGLEQUOTE || MULTIQUOTE))
			IGNORE = 1;
		else if (last_c == '"' && !MULTI && !SINGLE && !SINGLEQUOTE)
			MULTIQUOTE = !MULTIQUOTE;
		else if (last_c == '\'' && !MULTI && !SINGLE && !MULTIQUOTE)
			SINGLEQUOTE = !SINGLEQUOTE;

		if (last_c == '\n')
			++line_num;

		if (last_c == '\n' && !MULTI) {
			SINGLE = 0;
			MULTIQUOTE = 0;
			SINGLEQUOTE = 0;
		} else if (MULTI && last_c == '*' && c == '/')
			MULTI = 0;

		if (!SINGLE && !MULTI && !SINGLEQUOTE && !MULTIQUOTE)
			if (i = checkSyntax(last_c)) {
				printf("Unbalanced %c found at line %d\n", i, line_num);
				return;
			}

		last_c = c;
	}

	if (l > 0)
		printf("Unbalanced %c\n", stack[l-1]);
}

int checkSyntax(char c)
{
	if (c != '(' && c != '[' && c != '{'
	    && c != ')' && c != ']' && c != '}')
		return 0;

	if (c == '(' || c == '[' || c == '{') {
		stack[l] = c;
		++l;
		return 0;
	}

	if ((c == ')' && stack[l-1] == '(') ||
	    (c == ']' && stack[l-1] == '[') ||
	    (c == '}' && stack[l-1] == '{')) {
		--l;
		return 0;
	}

	return c;
}
