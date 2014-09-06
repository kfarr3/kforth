#include "kforth.h"

#include <sys/ioctl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdarg.h>

unsigned int platform_get_print_width(void)
{
    struct winsize ws;

    if (ioctl(0,TIOCGWINSZ,&ws)!=0) 
    {
        return 80;
    }
    return ws.ws_col;
}


static FILE *fd=NULL;

int platform_open_load_file(char *name)
{
	fd=fopen(name, "r");
	if (fd==NULL) return -1;
	return 0;
}

char file_statement[1000];
char *platform_read_load_file_statement(void)
{
	char *statement;
	statement = fgets(file_statement, 1000, fd);
	if (statement==NULL) return NULL;
    if ((statement[strlen(statement)-1]==0x0D)||(statement[strlen(statement)-1]==0x0A)) statement[strlen(statement)-1]='\0';
    if ((statement[strlen(statement)-1]==0x0D)||(statement[strlen(statement)-1]==0x0A)) statement[strlen(statement)-1]='\0';
	return statement;
}

void platform_close_load_file(void)
{
	if (fd!=NULL)
	{
		fclose(fd);
	}
}

int platform_open_save_file(char *name)
{
	fd=fopen(name, "w");
	if (fd==NULL) return -1;
	return 0;
}


void platform_write_save_file(char *fmt, ...)
{
	va_list arg;
	va_start(arg, fmt);

	if (fd!=NULL)
	{
		vfprintf(fd, fmt, arg);
	}

	va_end(arg);
}

void platform_close_save_file(void)
{
	if (fd!=NULL)
	{
		fclose(fd);
		fd=NULL;
	}
}

/***   End Of File   ***/

