#include<stdio.h>
/* Value of getchar() != EOF */

int main()
{
	int c = 2;

	c = getchar() != EOF;
	printf("%d\n",c);

	return 0;
}
