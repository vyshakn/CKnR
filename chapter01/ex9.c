#include<stdio.h>

#define SET 1
#define UNSET 0

/* replaces multiple blanks with single ones */

int main()
{

	int c,state;

	state = UNSET;

	while((c = getchar()) != EOF ) {
		if (c == ' ') {
			if(state == UNSET) {
				state = SET;
				putchar(c);
			}
		} else {
			if (state == SET)
				state = UNSET;
			putchar(c);
		}
	}

	return 0;
}
