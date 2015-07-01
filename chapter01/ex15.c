#include <stdio.h>

/* print Fahrenheit-Celsius table
	for fahr = 0, 20, ..., 300; floating-point version
	using function */

float convert(float fah);

int main()
{
	float fahr, celsius;
	float lower, upper, step;

	lower = 0;	/* upper limit */
	upper = 300;	/* lower limit of temperatuire scale */
	step = 20;	/* step size */

	fahr = lower;

	printf("\tFahrenheit-Celsius Table\n\n");
	printf("Fahrenheit\tCelsius\n");

	while (fahr <= upper) {
		celsius = convert(fahr);
		printf("%3.0f\t\t%6.1f\n",fahr , celsius);
		fahr = fahr + step;
	}

	return 0;
}

/* Conversion Function */
float convert(float fah)
{
	int cels;

	cels = (5.0/9.0) * (fah - 32.0);

	return cels;
}
