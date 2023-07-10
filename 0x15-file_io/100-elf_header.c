#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

#define BUFF_SIZE 64

/**
 * print_title - prints section formatted title
 * @title: the title with a colon at the end
 */
void print_title(const char *title)
{
	printf("%s:\t", title);
}

/**
 * print_header - prints the ELF header information
 * @header: pointer to the ELF header structure
 */
void print_header(Elf64_Ehdr *header)
{
	print_title("Magic");
	for (int i = 0; i < EI_NIDENT; i++)
		printf(" %02x", header->e_ident[i]);
	printf("\n");

	print_title("Class");
	switch (header->e_ident[EI_CLASS])
	{
		case ELFCLASS32:
			printf("ELF32\n");
			break;
		case ELFCLASS64:
			printf("ELF64\n");
			break;
		default:
			printf("Invalid\n");
			break;
	}

	print_title("Data");
	switch (header->e_ident[EI_DATA])
	{
		case ELFDATA2LSB:
			printf("2's complement, little endian\n");
			break;
		case ELFDATA2MSB:
			printf("2's complement, big endian\n");
			break;
		default:
			printf("Invalid\n");
			break;
	}

	print_title("Version");
	switch (header->e_ident[EI_VERSION])
	{
		case EV_NONE:
			printf("Invalid version\n");
			break;
		case EV_CURRENT:
			printf("1 (current)\n");
			break;
		default:
			printf("Unknown version\n");
			break;
	}

	print_title("OS/ABI");
	switch (header->e_ident[EI_OSABI])
	{
		case ELFOSABI_SYSV:
			printf("UNIX - System V\n");
			break;
		case ELFOSABI_HPUX:
			printf("UNIX - HP-UX\n");
			break;
		case ELFOSABI_NETBSD:
			printf("UNIX - NetBSD\n");
			break;
		case ELFOSABI_LINUX:
			printf("UNIX - Linux\n");
			break;
		case ELFOSABI_SOLARIS:
			printf("UNIX - Solaris\n");
			break;
		case ELFOSABI_IRIX:
			printf("UNIX - IRIX\n");
			break;
		case ELFOSABI_FREEBSD:
			printf("UNIX - FreeBSD\n");
			break;
		case ELFOSABI_TRU64:
			printf("UNIX - TRU64\n");
			break;
		case ELFOSABI_ARM:
			printf("ARM\n");
			break;
		case ELFOSABI_STANDALONE:
			printf("Standalone\n");
			break;
		default:
			printf("<unknown: %02x>\n", header->e_ident[EI_OSABI]);
			break;
	}

	print_title("ABI Version");
	printf("%d\n", header->e_ident[EI_ABIVERSION]);

	print_title("Type");
	switch (header->e_type)
	{
		case ET_NONE:
			printf("NONE (No file type)\n");
			break;
		case ET_REL:
			printf("REL (Relocatable file)\n");
			break;
		case ET_EXEC:
			printf("EXEC (Executable file)\n");
			break;
		case ET_DYN:
			printf("DYN (Shared object file)\n");
			break;
		case ET_CORE:
			printf("CORE (Core file)\n");
			break;
		default:
			printf("Unknown type\n");
			break;
	}

	print_title("Entry point address");
	printf("%#lx\n", header->e_entry);
}

/**
 * print_error - prints an error message to stderr and exits with status 98
 * @msg: the error message to print
 */
void print_error(const char *msg)
{
	fprintf(stderr, "Error: %s\n", msg);
	exit(98);
}

/**
 * main - displays the information contained in the ELF header of an ELF file
 * @argc: the number of arguments
 * @argv: array of arguments
 *
 * Return: 0 on success, 98 on failure
 */
int main(int argc, char **argv)
{
	int fd, n_read;
	Elf64_Ehdr header;
	char buff[BUFF_SIZE];

	if (argc != 2)
		print_error("Usage: elf_header elf_filename");

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		print_error("Failed to open file");

	n_read = read(fd, &header, sizeof(header));
	if (n_read == -1 || n_read != sizeof(header))
		print_error("Failed to read ELF header");

	if (header.e_ident[EI_MAG0] != ELFMAG0 ||
	    header.e_ident[EI_MAG1] != ELFMAG1 ||
	    header.e_ident[EI_MAG2] != ELFMAG2 ||
	    header.e_ident[EI_MAG3] != ELFMAG3)
		print_error("Not an ELF file");

	lseek(fd, 0, SEEK_SET);
	n_read = read(fd, buff, BUFF_SIZE);
	if (n_read == -1)
		print_error("Failed to read ELF file");

	printf("ELF Header:\n");
	write(1, buff, n_read);

	close(fd);
	return 0;
}

