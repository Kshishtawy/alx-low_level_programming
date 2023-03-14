#include "main.h"
#include <stdlib.h>

/**
 * alloc_grid - creates a two dimensional integer grid.
 * @width: width of the grid.
 * @height: height of the grid.
 *
 * Return: If width or height is 0 or negative, or if the allocation fails - NULL.
 *         Otherwise - a pointer to the allocated grid.
 */
int **alloc_grid(int width, int height)
{
    int **grid;
    int x, y;

    if (width <= 0 || height <= 0)
        return (NULL);

    grid = malloc(sizeof(int *) * height);

    if (grid == NULL)
        return (NULL);

    for (x = 0; x < height; x++)
    {
        grid[x] = malloc(sizeof(int) * width);

        if (grid[x] == NULL)
        {
            for (; x >= 0; x--)
                free(grid[x]);
            free(grid);
            return (NULL);
        }
    }

    for (x = 0; x < height; x++)
    {
        for (y = 0; y < width; y++)
            grid[x][y] = 0;
    }

    return (grid);
}
