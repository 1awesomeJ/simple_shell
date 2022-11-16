#ifndef MAIN_H
#define MAIN_H

#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>
#include <stddef.h>
extern char **environ;
int shell(char **env);
char *_strcpy(char *dest, char *src);
int _putchar(va_list pams);
int prntstr(va_list pams);
int _printf(const char *format, ...);
int _putchar2(char c);
int count_digits(unsigned int n);
int prntbnry(va_list pams);
int prntoct(va_list pams);
int _prntnum(va_list pams);
int countbnry(unsigned int n);
int countoct(unsigned int n);
int _prntnum1(int n);
int prntbnry1(int a);
int prntoct1(int a);
int prnt_unsigned1(int a);
int prnt_unsigned(va_list pams);
int _strcmp(char *s1, char *s2);
int count_hex(unsigned int n);
int hex0(va_list pams);
int hex(va_list pams);
int hex1(int n);
int hex2(int n);
int cus_prntstr(va_list pams);
void _print_env(char **env);
char *_getenv(char *name);
char *_strcat(char *dest, char *src);
char *findpath(char *cmnd);


/**
 * struct func_array - array of functions and specifier symbols
 *@t: the specifier symbol
 *@fp: pointer to the appropriate function
 *
 */
struct func_array
{
	char t;
	int (*fp)(va_list pams);
};

typedef struct func_array fa;
int (*sel_func(char c)) (va_list pams);


#endif
