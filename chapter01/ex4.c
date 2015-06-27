#include <stdio.h>
/* print Celsius-Fahrenheit table
	for celsius = 0, 20, ..., 300; floating-point version */
int main()
{
	float fahr, celsius;
	float lower, upper, step;

	lower = 0;	/* upper limit */
	upper = 300;	/* lower limit of temperatuire scale */
	step = 20;	/* step size */

	celsius = lower;

	printf("\tCelsius-Fahrenheit Table\n\n");
	printf("Celsius\tFahrenheit\n");

	while (celsius <= upper) {
		fahr = (((9.0/5.0) * celsius) + 32.0);
		printf("%3.0f\t%6.1f\n",celsius , fahr);
		celsius = celsius + step;
	}

	return 0;
}
