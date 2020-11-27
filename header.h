#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
#include <string.h>
#include <ctype.h>

#define TRUE    1
#define FALSE   0

#define NBRKEYWORDS 11
#define NBRSPECIALTOKENS 16


typedef enum          
{PROGRAM,   BEGIN,   END,   CONST,    VAR,   IF,   THEN,   WHILE,   DO,   READ,   WRITE} keyword_code;
const char* keyword_list[]= 
{"PROGRAM", "BEGIN", "END", "CONST" , "VAR", "IF", "THEN", "WHILE", "DO", "READ", "WRITE"};

typedef enum                 
{ PV,  PT,  PLUS, MOINS, MULT, DIV, VIR,  EG, AFF, INF,  INFEG, SUP, SUPEG, DIFF, PO,  PF} specialTokens_code;
const char* specialTokens_list[] = 
{ "PV",  "PT",  "PLUS", "MOINS", "MULT", "DIV", "VIR",  "EG", "AFF", "INF",  "INFEG", "SUP", "SUPEG", "DIFF", "PO",  "PF"};
const char* specialTokens_symb[] = 
{";",    ".",    "+",    "-",     "*",    "/",   "," ,   "=",  ":=",  "<",    "<=",    ">",    ">=",  "!",     "(",   ")"};


/***** Declarations ******/

FILE* program ;

#define lenValue    20
#define lenName     20

typedef struct{
    char name[lenName];
    char value[lenValue];
} Token;