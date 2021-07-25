// Program to "fold" long input lines into two or more shorter lines after
// the last non-blank character tjat occurs beforethe n-th column of input. Make
// sure your program does osmethign intelligent with very long lines, and if 
// there are no blanks or tabs before specified column.

#include <stdio.h>

#define LINELENGTH 1080
#define LIMIT 20

// Functions
int getline1(char [], int);
int skip_blank(char [], int);
void fold_line(char[], char[], int);

int main(void) {

	int len; 												// Current line length
	char line[LINELENGTH];					// Current line
	char foldedLine[LINELENGTH];		// Folded line

	while ((len = getline1(line, LINELENGTH)) > 0) {

		if (len > LIMIT) {
			fold_line(line, foldedLine, LIMIT);
			printf("%s", foldedLine);
		} else {
			printf("%s", line);
		}	
	}
	return 0;
}

int getline1(char s[], int lim) {
	int c, i;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;

	if (c == '\n') {
		s[i] = c;
		++i;
	}

	s[i] = '\0';
	return i;
}

int skip_blanks(char line[], int i) {

	while (line[i] == ' ' || line[i] == '\t')
		++i;
	
	return --i;
}

void fold_line(char oldline[], char newline[], int limit) {

	int i;
	int nchar;
	int lastBlank;
	int inBlank;

	nchar = lastBlank = inBlank = 0;
	for (i = 0; oldline[i] != '\0'; ++i) {
		newline[i] = oldline[i];
		++nchar;

		if (oldline[i] == ' ' || oldline[i] == '\t') {
			if (!inBlank)
				lastBlank = i;
			inBlank = 1;
		} else {
			inBlank = 0;
		}

		if (nchar >= limit && lastBlank != 0) {
			newline[lastBlank] = '\n';
			i = lastBlank;
			i = skip_blanks(oldline, i);
			nchar = lastBlank = inBlank = 0;
		}
	} 

	newline[i] = '\0';
}











































