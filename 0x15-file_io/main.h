#ifndef MAIN_H
#define MAIN_H

#define USAGE_STATUS 97
#define READ_FAIL_STATUS 98
#define WRITE_FAIL_STATUS 99
#define CLOSE_FAIL_STATUS 100
#define BUFFER_SIZE 1024
#define WFILE_MODE 0664

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>
#include <stdarg.h>

ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);

#endif /* MAIN_H */
