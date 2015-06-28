#include<stdio.h>

#define RESET 0
#define MAX 10

/* Horizontal Histogram of length of words */

int main()
{

	int c,count,index;
	int wordsize[MAX] = {0};

	count = RESET;
	index = 0;

	while((c = getchar()) != EOF ) {
		switch(c) {
		case ' ' :
		case '\t':
		case '\n':
			if (count > 0 && count < MAX + 1)
				++wordsize[count-1];
			count = RESET;
			break;
	
		case ',' :
		case '.' :
		case '\'':
		case ':' :
		case '?' :
		case '!' :
		case '(' :
		case ')' : 
			break;

		default :
			++count;
			break;
		}
	}

	for(index = 0; index < MAX; index++) {
		if (wordsize[index] > 0) {
			printf(" %d \t", index+1);
			for(count = 1; count <= wordsize[index]; count++)
				printf("|*|");
			printf("\n");
		}
	}

	return 0;
}
