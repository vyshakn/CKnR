#include <stdio.h>
#define MAXLINE 1000	/* set limit */

int getaline(char line[], int maxline);
int removeblanks(char input[], int length);

/* Remove trailing blanks and tabs*/

int main()
{
	int len;	/* current line length */
	int nlen;	/* new line length */
	char line[MAXLINE];	/* current input line */

	while ((len = getaline(line, MAXLINE)) > 0)
		if ((nlen = removeblanks(line, len)) > 1) {
			printf("%s", line);
//			printf("%d %d", len, nlen);	/* DEBUG */
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
/* removeblanks: removes blanks and tabs in input, returns new length */
int removeblanks(char input[], int length)
{
	int nl,new;

	nl = 0;
	new = length-1;

	if( new >= 0 && input[new] == '\n') {
		nl = 1;
		--new;
	}

	while( new >= 0 &&  (input[new] == '\t' || input[new] == ' ')) 
		--new;

	if (new >= 0 && nl == 1) 
		input[++new] = '\n';
	input[++new] = '\0';

	return new;
} 
