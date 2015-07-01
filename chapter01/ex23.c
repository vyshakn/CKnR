#include<stdio.h>
/*
#define SET 1
#define RESET 0
#define SL 0
#define ML 1
*/

/* Remove Comments */

int main()
{

	int c,x;
	/*
	state[SL] = RESET;
	state[ML] = RESET;
	*/
	while((c = getchar()) != EOF ) {
		if (c == '/') {
			x = getchar();
			if (x == '*') {
				c = getchar();
				while(1) {
					x = getchar();
					if( c == '*' && x == '/')
						break;
					else
						c = x;
				}
			} else if (x == '/') {
				for(;(c = getchar()) != '\n';);
			} else {
				putchar(c);
				putchar(x);
			}
		} else {
			putchar(c);
		}
	}

	return 0;
}
