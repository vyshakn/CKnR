#include <stdio.h>
#define MAXLINE 10	/* maximum input line length */

int getaline(char line[], int maxline);
void copy(char to[], char from[]);

/* print correct length of arbitary long input line */

int main()
{
	int len;	/* current line length */
	int max;	/* maximum length seen so far */
	char line[MAXLINE];	/* current input line */
	char longest[MAXLINE];	/* longest line saved here */
	max = 0;
	while ((len = getaline(line, MAXLINE)) > 0)
		if (len > max) {
			max = len;
			copy(longest, line);
		}
	if (max > 0) /* there was a line */
		printf("%d %s\n", max, longest);
	return 0;
}
/* getaline: read a line into s, return length	*/
int getaline(char s[],int lim)
{
	int c, i, k = 0;
	for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	} else if (c != EOF ) {
		for(k=0;(c=getchar()) != EOF && c != '\n'; ++k);
		if (c == '\n')
			++k;
	}
	s[i] = '\0';
	i += k;
	return i;
}
/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
	int i;
	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}
