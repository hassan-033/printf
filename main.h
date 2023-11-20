#ifndef _MAIN_H
#define _MAIN_H
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <ctype.h>

#define BUFFER_SIZE 1024
#define MAX_FLAG_LEN 6
#define SPECIFIERS "sc%diuboxX"
/**
 * struct str_builder - string builder
 * @buffer: the buffer string (malloc'ed)
 * @len: length of the string
 * @cap: size (max capacity) of the buffer
 *
 * Description: string builder data structure
 * for appending char * effectively and efficiently
 * to buffer.
 */
typedef struct str_builder
{
	char *buffer;
	int len;
	int cap;
} str_builder;

int sb_init(str_builder *sb, int init_capacity);
void sb_append(str_builder *sb, char *s, int n);
void sb_clean(str_builder *sb);
int sb_is_full(str_builder *sb, int len);

void handle_char(char c, str_builder *sb);
void handle_str(char *s, str_builder *sb);
void handle_int(int n, str_builder *sb);
void handle_uint(uint32_t n, str_builder *sb);
void handle_bin(uint32_t n, str_builder *sb);
void handle_oct(uint32_t n, str_builder *sb);
void handle_hex(uint32_t n, str_builder *sb, int is_upper);
void handle_npstr(char *s, str_builder *sb);

int _printf(const char *format, ...);
void _write(str_builder *sb, char *s, int s_len);
char *getflag(char *percent_ptr, str_builder *sb);

void write_int(int64_t n, str_builder *sb);
void write_bin(uint64_t n, str_builder *sb);
void write_oct(uint64_t n, str_builder *sb);
void write_hex(uint64_t n, str_builder *sb, int isUpper);


#endif /*_MAIN_H*/
