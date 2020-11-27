#include "header.h"

//----- Definitions :

#define MAXDIGIT 11
#define MAXCHAR  20

//----- Declarations of Variable :

char currentChar;
Token currentToken;

//----- Functions Prototype :

char NextChar();
void LexError();
void getToken();
void ignoreWhiteSpaces();
bool isNumber();
bool isWord();
bool isSpecial();

//----- Functions -------------- :

char NextChar(){
    return currentChar=getc(program);
}

void LexError(char *message){
    printf("%s\n", message);
    exit(1);
}

void getToken(){
    // Clear Token
    memset(currentToken.name, '\0', lenName);
    memset(currentToken.value, '\0', lenValue);

    // Ignore Whitespaces and Newlines and Comments
    ignoreWhiteSpaces();

    if(currentChar == EOF){ strcpy(currentToken.name, "EOF");}
    else if( isNumber() ){}
    else if( isWord() ){}
    else if( isSpecial() ){}
    else{ LexError("Invalid Token"); }
}

void ignoreWhiteSpaces(){

    // Ignore blank space, tabulation, newline
    while( currentChar == ' ' || currentChar == '\t' || 
    currentChar == '\n' || currentChar == '{'){
        NextChar();
        // Ignore Comments
        if( currentChar == '{'){
            if((currentChar=NextChar()) == '*')
                while((currentChar=NextChar()) != '*' || currentChar != EOF);
            else 
                LexError("Error in comment, open brace");

            if(currentChar != '}')
                LexError("Error in comment, close brace");
        }
    }
}

bool isNumber(){

    if(!isdigit(currentChar))
        return FALSE;

    char num[MAXDIGIT];
    int i = 0;
    num[0] = currentChar;

    while( ++i < MAXDIGIT && isdigit(num[i] = currentChar = NextChar()));

    if(i >= MAXDIGIT)
        LexError("Number has several digit");
        
    num[i] = '\0';

    strcpy(currentToken.name, "NUM");
    strcpy(currentToken.value, num);
    currentChar = NextChar();
    return TRUE;
}

bool isWord(){

    if( !isalpha(currentChar) )
        return FALSE;
    
    char word[MAXCHAR];
    int i = 0, j = 0, cmp=0;
    word[0] = toupper(currentChar);

    while( ++i < MAXCHAR && (isalnum( word[i] = currentChar = toupper(NextChar()) ) || word[i] == '_' ));

    if(i == MAXCHAR)
        LexError("there is many characters in this word");

    word[i] = '\0';

    // Verify this word match a keyword in the list of keywords
    while( (cmp=strcmp(word , keyword_list[j++])) != 0 && j < NBRKEYWORDS);

    if(cmp == 0){ // is keyword
        strcpy(currentToken.name, keyword_list[j-1]);
        strcpy(currentToken.value, word);
    }

    else{ // If not keyword, so it's an ID
        strcpy(currentToken.name, "ID"); 
        strcpy(currentToken.value, word);
    }
    
    return TRUE;
}

bool isSpecial(){

    int i=0,cmp=0;
    char op[3];
    memset(op,'\0',sizeof(op));

    op[0] = currentChar;
    if((op[1] = currentChar = NextChar()) != '=')
        op[1] =  '\0';
    else
        NextChar();
     
    while( (cmp = strcmp(op, specialTokens_symb[i++]) != 0) && i < NBRSPECIALTOKENS);

    if(cmp != 0)
        return FALSE;

    strcpy(currentToken.name, specialTokens_list[i-1]); 
    strcpy(currentToken.value, op);

    return TRUE;
}