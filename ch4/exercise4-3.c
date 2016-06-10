/* Clinton Andrews
 * 2016-06-09
 *
 * The C Programming Language
 * Exercise 4-3:
 * Given the basic framework, it's straightforward to extend the calculator.
 * Add the modulus (%) operator and provisions for negative numbers.
 *
 */

#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <ctype.h>

#define MAXOP	100
#define NUMBER	'0'
#define MAXVAL	100	/* maximum depth of val stack */
#define BUFSIZE	100

int sp = 0;
double val[MAXVAL];
char buf[BUFSIZE];	/* buffer for ungetch */
int bufp = 0;		/* next free position in buf */

int getop(char []);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);

/* reverse Polish calculator */
main()
{
	int type;
	double op2;
	char s[MAXOP];

	while((type = getop(s)) != EOF) {
		switch(type) {
		case NUMBER:
			push(atof(s));
			break;
		case '+':
			push(pop() + pop());
			break;
		case '*':
			push(pop() * pop());
			break;
		case '-':
			op2 = pop();
			push(pop() - op2);
			break;
		case '/':
			op2 = pop();
			if (op2 != 0.0)
				push(pop() / op2);
			else
				printf("error: zero divisor\n");
			break;
		case '%':
			op2 = pop();
			if (op2 != 0.0) {
				double op1 = pop();
				int truncate = op1 / op2;
				push(op1 - truncate*op2);
			} else
				printf("error: zero modulus\n");
			break;
		case '\n':
			printf("\t%.8g\n", pop());
			break;
		default:
			printf("error: unknown command %s\n", s);
			break;
		}
	}
	return 0;
}

/* push: push f onto value stack */
void push(double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return the value from the stack */
double pop(void)
{
	if (sp > 0)
		return val[--sp];
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
}

/* getop: get next operator or numeric operand */
int getop(char s[])
{
	int i, c;

	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if (!isdigit(c) && c != '.' && c != '-')
		return c;	/* not a number */
	if (c == '-') {
		c = getchar();
		ungetch(c);
		if (!isdigit(c) && c != '.')
			return c; /* not a number */
		s[0] = '-';
	}
	i = 0;
	if (isdigit(c))	/* collect integer part */
		while (isdigit(s[++i] = c = getch()))
			;
	if (c == '.')
		while (isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if (c != EOF)
		ungetch(c);
	return NUMBER;
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
