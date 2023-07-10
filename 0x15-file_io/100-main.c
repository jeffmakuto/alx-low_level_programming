#include "main.h"

/**
 * main - display the information contained in the ELF header of an ELF file
 *
 * @argc: the number of arguments
 *
 * @argv: array of arguments
 *
 * Return: 0 on success otherwise 98 on fail
 */
int main(int argc, char **argv)
{
	Elf64_Ehdr header;
	unsigned char magic[] = {0x7f, 'E', 'L', 'F'};
	char *filename;
	int fd;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: %s elf_filename\n", argv[0]);
		return (98);
	}
	filename = argv[1];

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: failed to open file %s\n", filename);
		return (98);
	}

	/* read the elf header section of the file */
	if (read(fd, &header, sizeof(header)) == -1)
	{
		dprintf(STDERR_FILENO,
					"Error: failed to read the elf file header of %s\n", filename);
		return (98);
	}

	/* check if the file is a valid ELF file */
	if (memcmp(header.e_ident, magic, 4))
	{
		dprintf(STDERR_FILENO, "Error: Invalid ELF file %s\n", filename);
		return (98);
	}
	print_header(&header); /* print a formated form of the elf header */
	close(fd); /* close the file */
	return (0);
}
