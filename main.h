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
#define SPECIFIERS "sScrR%diuboxXp"
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

int handle_char(char c, str_builder *sb, str_builder *f, int w);
int handle_str(char *s, str_builder *sb, str_builder *f, int w, int p);
int handle_npstr(char *s, str_builder *sb);
int handle_rot13(char *s, str_builder *sb);
int handle_revstr(char *s, str_builder *sb);

int handle_int(int64_t n, str_builder *sb, str_builder *f, int w, int p);
int handle_uint(uint64_t n, str_builder *sb, str_builder *f, int w, int p);
int handle_bin(uint32_t n, str_builder *sb);
int handle_oct(uint64_t n, str_builder *sb, str_builder *f, int w, int p);
int handle_hex(uint64_t n, str_builder *sb, str_builder *f,
							 int is_upper, int w, int p);
int handle_default(char **ptr, str_builder *sb);
int handle_ptr(void *n, str_builder *sb, str_builder *f, int w);

int handle_intflags(uint64_t n, int is_negative, str_builder *sb,
									str_builder *f,	char spec, int hzflag, int cp, int zp);
int handle_strflags(str_builder *sb, int hzflag, int cp);
int hyphen_zero_flag(int w, str_builder *f);


int _printf(const char *format, ...);
int _write(str_builder *sb, char *s, int s_len);

int write_int(int64_t n, str_builder *sb);
int write_uint(uint64_t n, str_builder *sb);
int write_bin(uint64_t n, str_builder *sb);
int write_oct(uint64_t n, str_builder *sb);
int write_hex(uint64_t n, str_builder *sb, int is_upper, int w);

int do_int(va_list ap, str_builder *sb, str_builder *f, char *p,
						int w, int pr);
int do_uint(va_list ap, str_builder *sb, str_builder *f, char *p,
						int w, int pr);
int do_oct(va_list ap, str_builder *sb, str_builder *f, char *p,
						int w, int pr);
int do_hex(va_list ap, str_builder *sb, str_builder *f, char *p,
						int w, int pr);

int getprecision(va_list ap, str_builder *f);
int getwidth(va_list ap, str_builder *f);
char *getflag(char *percent_ptr, str_builder *sb);

int isnum(char c);
int digits(int64_t n, char spec);
int padding(str_builder *sb, char c, int count);
int int_align_pads(uint64_t n, int is_negative, int is_zero_p,
				char spec, int w, int zp);
int int_precision_pads(uint64_t n, char spec, int p);

#endif /*_MAIN_H*/
