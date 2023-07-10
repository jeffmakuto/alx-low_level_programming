#ifndef MAIN_H
#define MAIN_H

/* Header Files */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <elf.h>
#include <stdarg.h>

/* Macros */
#define BUF_SIZE 64
#define BUFFER_SIZE 1024
#define USAGE_STATUS 97
#define READ_FAIL_STATUS 98
#define WRITE_FAIL_STATUS 99
#define CLOSE_FAIL_STATUS 100
#define WFILE_MODE 0664

/**
 * struct Elf64_Ehdr - ELF header structure
 * @magic:      Magic number identifying the file as an ELF object file
 * @class:      Identifies the class (32-bit or 64-bit) of the object file
 * @data:       Identifies the data encoding of the object file
 * @version:    Identifies the version of the object file format
 * @os_abi:     Identifies the operating system and ABI for which the object is prepared
 * @abi_version: Identifies the ABI version
 * @padding:    Unused padding bytes
 * @type:       Identifies the object file type
 * @machine:    Specifies the target architecture of the object file
 * @version2:   Identifies the version of the object file format (extended version)
 * @entry:      Virtual address to which the system first transfers control
 * @phoff:      Offset to the start of the program header table
 * @shoff:      Offset to the start of the section header table
 * @flags:      Processor-specific flags associated with the file
 * @ehsize:     Size of this ELF header
 * @phentsize:  Size of a program header table entry
 * @phnum:      Number of entries in the program header table
 * @shentsize:  Size of a section header table entry
 * @shnum:      Number of entries in the section header table
 * @shstrndx:   Index of the section header table entry that contains the section names
 */
typedef struct {
	unsigned char magic[4];
	unsigned char class;
	unsigned char data;
	unsigned char version;
	unsigned char os_abi;
	unsigned char abi_version;
	unsigned char padding[7];
	uint16_t type;
	uint16_t machine;
	uint32_t version2;
	uint64_t entry;
	uint64_t phoff;
	uint64_t shoff;
	uint32_t flags;
	uint16_t ehsize;
	uint16_t phentsize;
	uint16_t phnum;
	uint16_t shentsize;
	uint16_t shnum;
	uint16_t shstrndx;
} Elf64_Ehdr;

/* Prototype functions */
ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
void close_all(int count, ...);
void copy_content(int fd_dest, int fd_src, char *file_src, char *file_dest);
void print_error(const char *msg);
void print_elf_header(const Elf64_Ehdr *header);
void read_elf_header(const char *filename);

#endif /* MAIN_H */
