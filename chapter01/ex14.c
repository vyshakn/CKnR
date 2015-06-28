#include<stdio.h>

#define RESET 0
#define MAX 26

/* Horizontal Histogram of frequencies of characters */

int main()
{

	int c,count,index;
	int times[MAX] = {0};

	count = RESET;
	index = RESET;

	while((c = getchar()) != EOF ) {
		if (c > 96 && c < 123)
			++times[c-97];
		else if (c > 64 && c < 91)
			++times[c-65];
	}

	for(index = 0; index < MAX; index++) {
		if (times[index] > 0) {
			printf(" %c \t", index+65);
			for(count = 1; count <= times[index]; count++)
				printf("-");
			printf("\n");
		}
	}

	return 0;
}
