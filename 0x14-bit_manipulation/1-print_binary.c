void print_binary(unsigned long int n)
{
	unsigned long int mask;
	int flag = 0;

	if (!n)
	{
		_putchar('0');
		return;
	}

	mask = 1UL << (sizeof(unsigned long int) * 8 - 1);

	while (mask > 0)
	{
		if ((n & mask))
		{
			_putchar('1');
			flag = 1;
		}
		else if (flag == 1 || mask == 1)
			_putchar('0');
		mask >>= 1;
	}
}

