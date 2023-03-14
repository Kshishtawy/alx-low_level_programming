#include "main.h"
#include <stdlib.h>

/**
 * alloc_grid - create a 2D array of integers
 * @width: width of the grid
 * @height: height of the grid
 *
 * Return: pointer to 2D array, NULL if failure or width/height <= 0
 */
int **alloc_grid(int width, int height)
{
    int **grid;
    int row, col;

    if (width <= 0 || height <= 0)
        return (NULL);

    grid = malloc(height * sizeof(int *));
    if (grid == NULL)
        return (NULL);

    for (row = 0; row < height; row++)
    {
        grid[row] = malloc(width * sizeof(int));
        if (grid[row] == NULL)
        {
            while (row >= 0)
                free(grid[row--]);
            free(grid);
            return (NULL);
        }
    }

    for (row = 0; row < height; row++)
    {
        for (col = 0; col < width; col++)
        {
            grid[row][col] = 0;
        }
    }

    return (grid);
}
