#ifndef PLATFORM_UNIX_H
#define PLATFORM_UNIX_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

unsigned int platform_get_print_width(void);

int platform_open_save_file(char *name);
void platform_write_save_file(char *fmt, ...);
void platform_close_save_file(void);

int platform_open_load_file(char *name);
char *platform_read_load_file_statement(void);
void platform_close_load_file(void);

#define platform_printf printf
#define platform_flush() fflush(stdout)
#define platform_printerror printf
#define platform_strlen strlen
#define platform_malloc malloc
#define platform_free free
#define platform_sprintf sprintf
#define platform_strcpy strcpy
#define platform_memcpy memcpy
#define platform_time time

#endif
/***   End Of File   ***/

