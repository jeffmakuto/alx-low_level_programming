#include "main.h"

/**
 * print_title - prints section formated title
 * @title: the title with a colon at the end
 */
void print_title(const char *title)
{
	printf("  %-35s", title);
}

/**
 * print_header_hex - print the elf header in hex
 * @header: the address of the header object
 */
void print_header_hex(Elf64_Ehdr *header)
{
	int i;

	printf("  Magic:  ");
	for (i = 0; i < 16;  i++)
		printf(" %02x", header->e_ident[i]);
	printf(10);
}

/**
 * print_version - prints the elf's file version
 * @header: the pointer of the header object
 */
void print_version(Elf64_Ehdr *header)
{
	print_title("Version:");
	switch (header->e_version)
	{
		case EV_CURRENT:
			puts("1 (current)");
			break;
		default:
			puts("0 (invalid)");
	}
}

/**
 * print_class - prints the elf's file class
 * @header: the address of the header object
 */
void print_class(Elf64_Ehdr *header)
{
	print_title("Class:");
	switch (header->e_ident[EI_CLASS])
	{
		case ELFCLASS32:
			puts("ELF32");
			break;
		case ELFCLASS64:
			puts("ELF64");
			break;
		default:
			puts("Invalid");
	}
}

/**
 * print_data - prints the data formated
 * @header: address of the header object
 */
void print_data(Elf64_Ehdr *header)
{
	print_title("Data:");
	switch (header->e_ident[EI_DATA])
	{
		case ELFDATANONE:
			puts("None");
			break;
		case ELFDATA2LSB:
			puts("2's complement, little endian");
			break;
		case ELFDATA2MSB:
			puts("2's complement, big endian");
			break;
		default:
			printf("<unknown: %02x>\n", header->e_ident[EI_DATA]);
	}
}

/**
 * print_os_abi - prints the OS/ABI formated
 * @header: the address of the elf header object
 */
void print_os_abi(Elf64_Ehdr *header)
{
	print_title("OS/ABI:");
	switch (header->e_ident[EI_OSABI])
	{
		case ELFOSABI_SYSV:
			puts("UNIX - System V");
			break;
		case ELFOSABI_HPUX:
			puts("UNIX - HP-UX");
			break;
		case ELFOSABI_NETBSD:
			puts("UNIX - NetBSD");
			break;
		case ELFOSABI_LINUX:
			puts("UNIX - Linux");
			break;
		case ELFOSABI_SOLARIS:
			puts("UNIX - Solaris");
			break;
		case ELFOSABI_IRIX:
			puts("UNIX - IRIX");
			break;
		case ELFOSABI_FREEBSD:
			puts("UNIX - FreeBSD");
			break;
		case ELFOSABI_TRU64:
			puts("UNIX - TRU64");
			break;
		case ELFOSABI_ARM:
			puts("ARM");
			break;
		case ELFOSABI_STANDALONE:
			puts("Standalone");
			break;
		default:
			printf("<unknown %02x>\n", header->e_ident[EI_OSABI]);
	}
}

/**
 * print_abi_version - prints the version of the ABI
 * @header: the address of the elf header object
 */
void print_abi_version(Elf64_Ehdr *header)
{
	print_title("ABI Version:");
	printf("%d\n", header->e_ident[EI_ABIVERSION]);
}

/**
 * print_type - prints the type of the elf file
 * @header: the address of the elf object
 */
void print_type(Elf64_Ehdr *header)
{
	print_title("Type:");
	switch (header->e_type)
	{
		case ET_NONE:
			puts("NONE (None)");
			break;
		case ET_REL:
			puts("REL (Relocatable file)");
			break;
		case ET_EXEC:
			puts("EXEC (Executable file)");
			break;
		case ET_DYN:
			puts("DYN (Shared object file)");
			break;
		case ET_CORE:
			puts("CORE (Core file)");
			break;
		default:
			printf("<unknown %02x>\n", header->e_type);
	}
}

/**
 * print_entry - prints the entry point address of the elf file
 * @header: the address of the elf file header
 */
void print_entry(Elf64_Ehdr *header)
{
	void *ptr = &header->e_entry;

	print_title("Entry point address:");
	if (header->e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", *(unsigned int *)ptr);
	else
		printf("%#lx\n", *(unsigned long *)ptr);
}

/**
 * print_header - prints the header of the elf file formated
 * @header: the address of the elf object
 */
void print_header(Elf64_Ehdr *header)
{
	int i;

	void (*formats[])(Elf64_Ehdr *) = {
		print_header_hex, print_class, print_data, print_version,
		print_os_abi, print_abi_version, print_type, print_entry,
		NULL
	};
	puts("ELF Header:");
	for (i = 0; formats[i]; i++)
		formats[i](header);

}

/**
 * main - display the information contained in the ELF header of an ELF file
 * @argc: the number of arguments
 * @argv: array of arguments
 *
 * Return: 1 on success otherwise 98 on fial.
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
