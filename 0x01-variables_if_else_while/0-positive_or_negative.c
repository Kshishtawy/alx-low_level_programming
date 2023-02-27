#include <stdlib.h>
#include <time.h>
/* more headers goes there */
#include <stdio.h>

/* betty style doc for function main goes there */
/**
 * main - print a random number and tell if it is positive, negative, or zero
 */
int main(void)
{
	int n;

	srand(time(0));
	n = rand() - RAND_MAX / 2;

	if (n < 0)
	{
		printf("the number is %d, which is negative", n);
	}
	else if (n == 0)
	{
		printf("the number is %d, which is exactly zero", n);
	}
	else
	{
		printf("the number is %d, which is positive", n);
	}

	return (0);
}
