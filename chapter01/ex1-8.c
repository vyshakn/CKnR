#include<stdio.h>

/* count blanks,tabs, and newlines in output */

int main()
{

	int c,nb,nt,nl;

	nb=0;
	nt=0;
	nl=0;

	while((c = getchar()) != EOF ) {
		if (c == ' ')
			++nb;
		else if ( c == '\t')
			++nt;
		else if ( c == '\n')
			++nl;
	}

	printf("nb = %d\tnt = %d\tnl = %d\n",nb,nt,nl);

	return 0;
}
