// Replace tabs in the input with the proper number of blanks to space to the 
// next tba stop. Assume fixed set of tab stops, say every n columns.
// Should n be a variable or symbolic parameter

#include <stdio.h>

#define COLUMN 4				// tab stops every 8 columns

int main(void) {
	int c, i, col, spaces;
	col = 0;

	while ((c = getchar()) != EOF) {
		if (c != '\t' && c !='\n')
			col = (col + 1) % COLUMN;
		if (c == '\n')
			col = 0;
		if (c == '\t') {
			for (i = 0; i <= (COLUMN - col); ++i)
				putchar('-');
			col = 0;
		} else 
			putchar(c);
	}
	return 0;
}
