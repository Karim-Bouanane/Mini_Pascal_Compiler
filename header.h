/***** Libraries ******/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef enum{FALSE, TRUE} bool;

/***** Definitions of Tokens ******/

typedef enum          
{
// keywords tokens
PROGRAM,  BEGIN,  END,  CONST,  VAR,  IF,  THEN,  WHILE,  DO,  READ,  WRITE,
// Symbol tokens
PV,  PT,  PLUS,  MOINS,  MULT,  DIV,  VIR,  EG,  AFF,  INF,  INFEG,  SUP,  SUPEG,  DIFF,  PO,  PF,
// Other tokens
ID,  NUM, EndOfFile
} token_code;


const char* keywords_list[]= 
{"PROGRAM", "BEGIN", "END", "CONST" , "VAR", "IF", "THEN", "WHILE", "DO", "READ", "WRITE"};

const char* specialTokens_list[] = 
{ "PV",  "PT",  "PLUS", "MOINS", "MULT", "DIV", "VIR",  "EG", "AFF", "INF",  "INFEG", "SUP", "SUPEG", "DIFF", "PO",  "PF"};
const char* specialTokens_symb[] = 
{";",    ".",    "+",    "-",     "*",    "/",   "," ,   "=",  ":=",  "<",    "<=",    ">",    ">=",  "!",     "(",   ")"};


int keywords_list_size = sizeof(keywords_list) / sizeof(keywords_list[0]);
int specialTokens_list_size = sizeof(specialTokens_list) / sizeof(specialTokens_list[0]);

#define NBRKEYWORDS         keywords_list_size
#define NBRSPECIALTOKENS    specialTokens_list_size

/***** Global Declarations ******/

FILE* program ;

#define lenValue    20
#define lenName     20

typedef struct{
    token_code code;
    char name[lenName];
    char value[lenValue];
} Token;