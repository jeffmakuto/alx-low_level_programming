#include "main.h"

/**
 * print_error - prints standard error and exits with 98
 *
 * @msg: pointer to message printed
 *
 */
void print_error(const char *msg);

/**
 * print_header - prints the ELF header information
 *
 * @ehdr: pointer to ELF header structure
 *
 */
void print_header(const Elf64_Ehdr *ehdr);

/**
 * main - entry level
 *
 * @argc: number of arguments passed
 *
 * @argv: arguments in the function
 *
 * Return: 0, On Success.
 */
int main(int argc, char **argv)
{
	if (argc != 2)
		print_error("Usage: elf_header elf_filename");

	int fd = open(argv[1], O_RDONLY);

	if (fd == -1)
		print_error("Cannot open file");

	Elf64_Ehdr ehdr;
	ssize_t n = read(fd, &ehdr, sizeof(ehdr));

	if (n != sizeof(ehdr))
		print_error("Cannot read ELF header");

	print_header(&ehdr);

	close(fd);
	return (0);
}

void print_error(const char *msg)
{
	fprintf(stderr, "Error: %s\n", msg);
	exit(98);
}

void print_header(const Elf64_Ehdr *ehdr)
{
	printf("  Magic:   %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x\n",
			ehdr->e_ident[EI_MAG0], ehdr->e_ident[EI_MAG1],
			ehdr->e_ident[EI_MAG2], ehdr->e_ident[EI_MAG3],
			ehdr->e_ident[EI_CLASS], ehdr->e_ident[EI_DATA],
			ehdr->e_ident[EI_VERSION], ehdr->e_ident[EI_OSABI],
			ehdr->e_ident[EI_ABIVERSION], ehdr->e_type, ehdr->e_machine, ehdr->e_version,
			ehdr->e_entry, ehdr->e_phoff, ehdr->e_shoff, ehdr->e_flags);
	printf("  Class:                             %s\n",
			ehdr->e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" : "ELF64");

	printf("  Data:                              %s\n",
			ehdr->e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" : "Unknown");

	printf("  Version:                           %d (current)\n",
			ehdr->e_ident[EI_VERSION]);

	printf("  OS/ABI:                            %s\n",
			ehdr->e_ident[EI_OSABI] == ELFOSABI_SYSV ? "UNIX - System V" : "Unknown");

	printf("  ABI Version:                       %d\n",
			ehdr->e_ident[EI_ABIVERSION]);

	printf("  Type:                              %s\n",
			ehdr->e_type == ET_EXEC ? "EXEC (Executable file)" :
			ehdr->e_type == ET_DYN ? "DYN (Shared object file)" : "Unknown");

	printf("  Entry point address:               %lx\n",
			ehdr->e_entry);
}
