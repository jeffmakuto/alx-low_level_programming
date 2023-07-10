#include "main.h"

/**
 * print_title - prints section formated title
 *
 * @title: the title with a colon at the end
 *
 * Return: Void
 */
void print_title(const char *title)
{
	printf("  %-35s", title);
}

/**
 * print_header_hex - print the elf header in hex
 *
 * @header: the address of the header object
 *
 * Return: Void
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
 *
 * @header: the pointer of the header object
 *
 * Return: Void
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
 *
 * @header: the address of the header object
 *
 * Return: Void
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
 *
 * @header: address of the header object
 *
 * Return: Void
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

