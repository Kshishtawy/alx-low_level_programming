#include "main.h"
/**
  *puts2 - function to print every other charachter
  *starting with the first one
  *@str: input
  */
void puts2(char *s)
{
	_putchar(*s);
	while (*s != '\0')
	{
		s++;
		_putchar(*++s);
	}
	_putchar('\n');
}
