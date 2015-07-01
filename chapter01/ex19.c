#include <stdio.h>
#define MAXLINE 1000	/* set limit */

int getaline(char line[], int maxline);
void reverse(char input[]);

/* Reverse input lines*/

int main()
{
	int len;	/* current line length */
	char line[MAXLINE];	/* current input line */

	while ((len = getaline(line, MAXLINE)) > 0) {
		reverse(line);
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
/* reverse: reverses string input */
void reverse(char input[])
{
	int init, len;
	char temp;

	init = 0;	/* Beginning of string */
	len = 0;	/* Ending of string */

	while(input[len] != '\0')
		++len;
	--len;

	if( len >= 0 && input[len] == '\n')
		--len;


	while(init < len) {
		temp = input[init];
		input[init] = input[len];
		input[len] = temp;
		++init;
		--len;
	}
} 
