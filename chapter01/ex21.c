#include<stdio.h>

#define SET 1
#define RESET 0
#define TABSTOP 4

/* Replaces Multiple blanks by tabs and spaces */

int main()
{

	int c, state, count;
	int tabs, spaces;

	state = RESET;
	count = RESET;

	while((c = getchar()) != EOF ) {
		if (c == ' ') {
			if(state == RESET) {
				state = SET;
				++count;
			} else {
				++count;
			}
		} else {
			if (state == SET) {
				tabs = count / TABSTOP;
				spaces = count % TABSTOP;
//				printf("%d %d", tabs, spaces); /* DEBUG */
				for(; tabs > 0 ; --tabs)
					putchar('\t');
				for(; spaces > 0; --spaces)
					putchar(' ');
				state = RESET;
				count = RESET;
			}
			putchar(c);
		}
	}

	return 0;
}
