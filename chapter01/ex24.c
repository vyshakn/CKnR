#include <stdio.h>
#include <stdlib.h>
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

			switch(line[i]) {
			case '\'':
				if(i == 0 || line[i-1] != '\\') {
					for(++i; line[i] != '\0' && line[i] != '\''; i++) {
						if(line[i] == '\\')
							i++;
					}
					--i;
				}
				break;
			case '\"':
				if(i == 0 || line[i-1] != '\\') {
					for(++i; line[i] != '\0' && line[i] != '\"'; i++) {
						if(line[i] == '\\')
							i++;
					}
					--i;
				}
				break;
			case '/':
				if(i == 0 || line[i-1] == '/')
					for(;line[i+1] != '\n';i++);
				break;
			case '(':
				++count[0];
				break;
			case ')':
				if (count[0] < 1)
					count[0] = -9999;
				else
					--count[0];
				break;
			case '{':
				++count[1];
				break;
			case '}':
				if (count[1] < 1)
					count[1] = -9999;
				else
					--count[1];
				break;
			case '[':
				++count[2];
				break;
			case ']':
				if (count[2] < 1)
					count[2] = -9999;
				else
					--count[2];
				break;
			}
		}
	}

	// DRY ;(
	if( count[0] != 0 )
		printf("Unmatched ()\n");
	if( count[1] != 0 )
		printf("Unmatched {}\n");
	if( count[2] != 0 )
		printf("Unmatched []\n");
}
 
