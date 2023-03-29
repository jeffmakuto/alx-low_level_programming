/**
 * reverse_array - reverse array of integers of @n elements
 *
 * @a: a reference to integers array
 *
 * @n: number of elements in @a
 *
 * Return: void
 */
void reverse_array(int *a, int n)
{
	int i, mid = n-- / 2;

	for (i = 0; i < mid; i++)
	{
		int tmp = *(a + i);

		*(a + i) = *(a + n - i);
		*(a + n - i) = tmp;
	}
}
