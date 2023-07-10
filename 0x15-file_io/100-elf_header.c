#include "main.h"

/**
 * print_error - Print error message and exit with status code 98
 * @msg: The error message
 */
void print_error(const char *msg)
{
	fprintf(stderr, "%s\n", msg);
	exit(98);
}

/**
 * print_elf_header - Print the contents of the ELF header
 * @header: Pointer to the ELF header structure
 */
void print_elf_header(const Elf64_Ehdr *header)
{
	printf("ELF Header:\n");
	printf("	Magic:	%02x %02x %02x %02x\n", header->magic[0],
			header->magic[1], header->magic[2], header->magic[3]);
	printf("	Class:				ELF%d\n", header->class == 1 ? 32 : 64);
	printf("	Data:				%s\n",
		header->data == 1 ? "2's complement, little endian" :
		"2's complement, big endian");
	printf("	Version:			%d (current)\n", header->version);
	printf("	OS/ABI:				%s\n",
			header->os_abi == 0 ? "UNIX - System V" : "Unknown");
	printf("	ABI Version:			%d\n", header->abi_version);
	printf("	Type:				%d\n", header->type);
	printf("	Entry point address:		0x%lx\n", header->entry);
}

/**
 * read_elf_header - Read the ELF header from the specified file
 * @filename: The path to the ELF file
 */
void read_elf_header(const char *filename)
{
	int fd = open(filename, O_RDONLY);
	ssize_t bytes_read;

	if (fd == -1)
	{
		print_error("Error opening file");
	}

	Elf64_Ehdr header;
	bytes_read = read(fd, &header, sizeof(Elf64_Ehdr));
	if (bytes_read != sizeof(Elf64_Ehdr))
	{
		print_error("Error reading ELF header");
	}

	print_elf_header(&header);

	close(fd);
}

/**
 * main - Entry point of the program
 * @argc: The number of command-line arguments
 * @argv: An array of command-line argument strings
 * Return: 0 on success, other values on failure
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		print_error("Usage: elf_header elf_filename");
	}

	read_elf_header(argv[1]);

	return (0);
}

