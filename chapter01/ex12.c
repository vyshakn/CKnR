#include<stdio.h>

#define SET 1
#define UNSET 0

/* Prints word by word in newline */

int main()
{

	int c,state;

	state = UNSET;

	while((c = getchar()) != EOF ) {
		if (c == ' ' ||  c == '\t') {
			if (state == UNSET) {
				state = SET;
				putchar('\n');
			}
		} else {
			if ( state == SET)
				state = UNSET;
			putchar(c);
		}
	}

	return 0;
}
