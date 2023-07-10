#include "main.h"

/**
 * print_os_abi - prints the OS/ABI formated
 *
 * @header: the address of the elf header object
 *
 * Return: Void
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
 *
 * @header: the address of the elf header object
 *
 * Return: Void
 */
void print_abi_version(Elf64_Ehdr *header)
{
	print_title("ABI Version:");
	printf("%d\n", header->e_ident[EI_ABIVERSION]);
}

/**
 * print_type - prints the type of the elf file
 *
 * @header: the address of the elf object
 *
 * Return: Void
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
 *
 * @header: the address of the elf file header
 *
 * Return: Void
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
 *
 * @header: the address of the elf object
 *
 * Return: Void
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
