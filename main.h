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
#define SPECIFIERS "sSc%diuboxXp"
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

int handle_char(char c, str_builder *sb);
int handle_str(char *s, str_builder *sb);
int handle_npstr(char *s, str_builder *sb);
int handle_int(int n, str_builder *sb, str_builder *f);
int handle_uint(uint32_t n, str_builder *sb, str_builder *f);
int handle_bin(uint32_t n, str_builder *sb);
int handle_oct(uint32_t n, str_builder *sb, str_builder *f);
int handle_hex(uint32_t n, str_builder *sb, str_builder *f, int is_upper);
int handle_default(char **ptr, str_builder *sb);
int handle_ptr(void *n, str_builder *sb);

int handle_intflags(int64_t n, str_builder *sb, str_builder *f, char spec);


int _printf(const char *format, ...);
int _write(str_builder *sb, char *s, int s_len);
char *getflag(char *percent_ptr, str_builder *sb);

int write_int(int64_t n, str_builder *sb);
int write_bin(uint64_t n, str_builder *sb);
int write_oct(uint64_t n, str_builder *sb);
int write_hex(uint64_t n, str_builder *sb, int is_upper, int w);


#endif /*_MAIN_H*/
