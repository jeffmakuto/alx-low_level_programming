#include <stdlib.h>

/**
 * free_grid - free grid created by  alloc_grid
 *
 * @grid: reference to the grid
 *
 * @height: the height of the grid
 */
void free_grid(int **grid, int height __attribute__((unused)))
{
	free(grid);
}

