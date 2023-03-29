#include <stdio.h>
#include <ctype.h>

/**
 * print_formated_buffer - print a formated 10 bytes or less buffer
 * @n: the line index
 * @buffer: the buffer to print @size bytes from
 * @size: the number of bytes to print, must be 10 or less
 */
void print_formated_buffer(int n, char *buffer, int size)
{
	int i;

	/* print index */
	printf("%08x: ", n);

	/* print bytes in hexdec */
	for (i = 0; i < 10; i++)
	{
		/* is bytes over, for the final line */
		int over = i >= size;
		/* character to print */
		char c = over ? 0 : *(buffer + i);

		/* if over print white space else char in hex form with 2 zeros padding */
		if (!over)
			printf("%02x", c);
		else
			printf("  ");

		/* puts white space char every 2 bytes */
		if (i % 2 == 1)
			putchar(' ');
	}

	/* print bytes as characters */
	for (i = 0; i < size; i++)
	{
		char c = *(buffer + i);

		putchar(isprint(c) ? c : '.');
	}
	putchar('\n');
}

/**
 * print_buffer - print @b of @size bytes in formatted form
 * @b: the buffer reference to print
 * @size: the number of bytes to format and print
 * Description:
 * print every 10bytes of @b at a single line,
 * starting the line with the first character index in the buffer
 * in hex form padded with 8 zeros.
 * then the 10bytes in hex forms padded with 2 zeros and a space char
 * every 2bytes. finally print the 10 printable characters.
 * if the character is not printable then prints a `.` character instead.
 */
void print_buffer(char *b, int size)
{
	int i;

	if (size <= 0)
	{
		putchar('\n');
		return;
	}

	for (i = 0; i < size; i += 10)
	{
		int r = size - i;

		print_formated_buffer(i, b, r < 10 ? r : 10);
		if (r > 10)
			b += 10;
	}
}
