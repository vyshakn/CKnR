#include <stdio.h>
#define MAXLINE 1000	/* set limit */

int getaline(char line[], int maxline);

/* print lines greater than 80 characters */

int main()
{
	int len;	/* current line length */
	int max;	/* maximum length */
	char line[MAXLINE];	/* current input line */

	max = 80;	/* set filter*/
	while ((len = getaline(line, MAXLINE)) > 0)
		if (len > max) {
			printf("%s", line);
		}
	return 0;
}
/* getaline: read a line into s, return length	*/
int getaline(char s[],int lim)
{
	int c, i;
	for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}
