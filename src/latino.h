#ifndef _LATINO_H_
#define _LATINO_H_ 1

#define LATINO_HUGE 1

#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <memory.h>
#include <stdlib.h>
#include <stdarg.h>
#include <float.h>
#include "ast.h"

#if defined(__GNUC__) && ((__GNUC__*100 + __GNUC_MINOR__) >= 302) && \
defined(__ELF__)
#define LAT_FUNC    __attribute__((visibility("hidden"))) extern
#define lnsprintf(s, l, f, i)  snprintf(s, l, f, i)
#else
#define LAT_FUNC    extern
#define lnsprintf(s, l, f, i)  _snprintf(s, l, f, i)
#endif

#pragma once

#define false   0
#define true    1

#ifndef bool
#define bool int
#endif // bool

/*
 * global variable
 */
extern int debug;
#define BUF_SIZE 1048576
#define MAX_ERROR_LENGTH 1024

/*
 * lex & parse
 */
/*extern int yylex(void);*/
extern void dumpRow(void);
extern int getNextChar(char *b, int maxBuffer);
extern void beginToken(char*);
extern void printError(char *s, ...);

/* interface to the lexer */
typedef struct YYLTYPE
{
	int first_line;
	int first_column;
	int last_line;
	int last_column;
} YYLTYPE;
#define YYLTYPE_IS_DECLARED 1
struct ast;

#define YY_NO_UNISTD_H 1

/* from lexer */
/*extern int yylineno;*/
void yyerror(char *s, ...);
/*int yyerror(struct YYLTYPE *yylloc_param, void *scanner, struct ast **root, const char *s);*/
void report_error(char *string);

#endif /* _LATINO_H_ */
