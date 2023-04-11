#include <stdlib.h>

/**
 * alloc_grid - allocate 2d array
 *
 * @width: the array width
 *
 * @height: the array height
 *
 * Return: pointer to list of pointers to int[] else NULL on fail
 */
int **alloc_grid(int width, int height)
{
	int len, i;
	int **nums, *ptr;

	if (width <= 0 || height <= 0)
	{
		return (NULL);
	}

	len = sizeof(int *) * height + sizeof(int) * width * height;
	nums = calloc(1, len);

	if (nums)
	{
		ptr = (int *)(nums + height);
		for (i = 0; i < height; i++)
		{
			nums[i] = ptr + width * i;
		}
	}

	return (nums);
}
