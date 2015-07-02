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
	int  i, temp, endl;

	endl = fold;

	while(endl <= len) {
		temp = endl - fold;
		for(; endl > temp && input[endl] != ' '; --endl);
		if( input[endl] == ' ' ) 
			input[endl] = '\n';
		else {
			/* Found No blanks condition */
			endl = temp + fold;

			if(len > MAXLINE - 3) {		//very long input line

				/* Nothing Intelligent ,
				   Just removes extra characters
				   keeping '\n' and '\0' */

				if(input[len-1] == '\n')
					input[MAXLINE - 4] = '\n';
				len = MAXLINE - 3;
				input[len] = '\0';
			}

			/* Shift characters 2 steps to add 
			   '-' and '\n' inbetween */

			for(i = len; i >=  endl - 2 ; i = i - 2) {
				input[i+2] = input[i];
				input[i+1] = input[i-1];
			}
			len = len + 2;
			endl = endl - 1;
			input[endl - 1] = '-';
			input[endl] = '\n';
		}
		endl += fold;
	}
}
