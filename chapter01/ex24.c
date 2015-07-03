#include <stdio.h>
#define MAXLINE 1000	/* set limit */

int getaline(char line[], int maxline);
void checkmatch(void);

/* Check for rudimentary syntax errors
	unmatched  '' "" () {} [] */

int main()
{

	checkmatch();

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
/* checkmatch : ... */
void checkmatch(void)
{
	int i;
	int len;	/* current line length */
	//int ignore[2]= 0;		
	int count[3] = {0} ;
	char line[MAXLINE];	/* current input line */

	while ((len = getaline(line, MAXLINE)) > 0) {
		for(i=0; i < len; i++) {

			// DRY ;(
			if(line[i] == '(')
				++count[0];
			else if (line[i] == ')')
				--count[0];

			if(line[i] == '{')
				++count[1];
			else if (line[i] == '}')
				--count[1];

			if(line[i] == '[')
				++count[2];
			else if (line[i] == ']')
				--count[2];

		}
	}
	// DRY ;(
	if( count[0] != 0 )
		printf("() unmatched\n");
	if( count[1] != 0 )
		printf("{} unmatched\n");
	if( count[2] != 0 )
		printf("[] unmatched\n");

}
 
