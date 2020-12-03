#include "Lexer.c"

const char* fileName = "C:\\Users\\George Deker\\Desktop\\Compila TP\\program.pascal";

int main(){

    program = fopen(fileName, "r");
    if(program == NULL){
        perror("Error while opening the file");
        exit(1);
    }
    NextChar();
    getToken();
    do{
        printf("%s_TOKEN\n", currentToken.name);
        getToken();
    }while(strcmp(currentToken.name,"EOF"));

    return 1;
} 