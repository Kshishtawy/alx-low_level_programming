#include "main.h"

/**
  * print_alphabet - writes the alphabet in lowercase followed by a new line
  *
  */
void print_alphabet_x10(void)
{
	int i, count;

	for (count = 0; count < 10; count++)
	{
		for (i = 97; i < 123; i++)
		{
			_putchar(i);
		}
		_putchar('\n');
	}
}
