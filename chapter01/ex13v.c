#include<stdio.h>

#define RESET 0
#define MAX 10
#define HEIGHT 10

/* Vertical Histogram of length of words */

int main()
{

	int c,count,index;
	int wordsize[MAX] = {0};
	char histogram[HEIGHT][MAX];

	for(index = 0 ; index < MAX ; index++)
		for(count = 0 ; count < HEIGHT ; count++)
			histogram[count][index] = ' ';

	count = RESET;
	index = RESET;

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
			for(count = 1; count <= wordsize[index]; count++)
				histogram[count-1][index] =  '|';
		}
	}

	printf("\n\n");
	for(index = HEIGHT-1; index >= 0; index--) {
		printf("%d\t",index+1);
		for(count = 0; count < MAX; count++) {
			printf("%c ",histogram[index][count]);
		}
		printf("\n");
	}
	printf(" \t");
	for(count=0;count < MAX; count++)
		printf("%d ",count+1);
	printf("\n");

	return 0;
}
