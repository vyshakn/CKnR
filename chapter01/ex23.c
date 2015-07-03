#include<stdio.h>
/* Remove Comments */

int main()
{

	int c,x;
	
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
