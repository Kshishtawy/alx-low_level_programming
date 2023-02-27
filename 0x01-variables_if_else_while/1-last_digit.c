 #include <stdlib.h>
 #include <time.h>
 /* more headers goes there */
 #include <stdio.h>

 /* betty style doc for function main goes there */
 /**
  * main - it prints stuff
  *
  * Return: 0 if successful
  */
int main(void)
{
	int n, digit;
	srand(time(0));
	n = rand() - RAND_MAX /2;
	digit = n % 10;
	printf("Last digit of %d is %d ", n, digit);
	if (digit > 5)
	{
		printf("and is greater than 5\n");
	}
	else if (digit < 6)
	{
		if (digit != 0)
		{
			printf("and is less than 6 and not 0\n");
		}
		else
		{
			printf("and is 0\n");
		}
	}
	return (0);
}
