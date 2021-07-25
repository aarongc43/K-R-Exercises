// Replace strings of blanks by the minimun number of tabs and blanks to achieve
// the same spacing. Use the same tabstops as for detab.

#include <stdio.h>

#define COLUMN 4

int main(void) {
	int c, i, column, blank;

	column = blank = 0;

	while ((c = getchar()) != EOF) {
		if (c == ' ') {
			blank = blank + 1;
		} else {
				if (blank > 0) {
					for (i = 0; i < blank / COLUMN; ++i) {
						putchar('\t');
					}
					for (i = 0; i < blank % COLUMN; ++i) {
						putchar('*');
					}
					blank = 0;
				}
			putchar(c);
		}
	}
	return 0;
}
