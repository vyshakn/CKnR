#include <stdio.h>
#define MAXLINE 1000	/* set limit */

int getaline(char line[], int maxline);
void splitline(char input[], int len, int fold);

/* Fold Lines by number of characters */

int main()
{
	int len;	/* current line length */
	int max;	/* maximum length */
	char line[MAXLINE];	/* current input line */

	max = 10;	/* set fold point*/
	while ((len = getaline(line, MAXLINE)) > 0)
		if (len > max) {
			splitline(line, len, max);
			printf("%s", line);	
		} else {
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
/* splitline : splits input string into multiple sections
	of size fold at blanks */
void splitline(char input[], int len, int fold)
{
	int  temp, endl;

	endl = fold;

	while(endl < len) {
		temp = endl - fold;
		for(; endl > temp && input[endl] != ' '; --endl);
		if( input[endl] == ' ' ) 
			input[endl] = '\n';
		else {
			/* Found No blanks condition */
			; 
		}
		endl += fold;
	}
}
