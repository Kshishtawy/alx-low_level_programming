#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * free_grid - Frees a 2D array previously created by alloc_grid
 * @grid: Pointer to the 2D array
 * @height: Height of the grid
 *
 * Description: This function frees the memory of a 2D array of integers.
 *
 * Return: Nothing.
 */

void free_grid(int **grid, int height)
{
	int i;

	for (i = 0; i < height; i++)
	{
		free(grid[i]);
	}

	free(grid);
}
