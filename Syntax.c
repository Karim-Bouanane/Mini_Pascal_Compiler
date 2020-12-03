/** 
     GRAMMAR for Pascal Language
 
PROGRAM     ::= program ID ; BLOCK .
BLOCK       ::= CONSTS VARS INSTS
CONSTS      ::= const ID = NUM ; { ID = NUM ; } | e
VARS        ::= var ID { , ID } ; | e
INSTS       ::= begin INST { ; INST } end
INST        ::= INSTS | AFFEC | SI | TANTQUE | ECRIRE | LIRE | e
AFFEC       ::= ID := EXPR
SI          ::= if COND then INST
TANTQUE     ::= while COND do INST
ECRIRE      ::= write ( EXPR { , EXPR } )
LIRE        ::= read ( ID { , ID } )
COND        ::= EXPR RELOP EXPR
RELOP       ::= = | <> | < | > | <= | >=
EXPR        ::= TERM { ADDOP TERM }
ADDOP       ::= + | -
TERM        ::= FACT { MULOP FACT }
MULOP       ::= * | /
FACT        ::= ID | NUM | ( EXPR )
ID          ::= lettre {lettre | chiffre}
NUM         ::= chiffre {chiffre}
Chiffre     ::= 0|..|9
Lettre      ::= a|b|..|z|A|..|Z

/**********************************/

#include "Lexer.c"

typedef enum {INORDER, ANY} Method;

/*********** Functions Prototype **********/

void verifyToken();
void Program();
void Block();
void Consts();
void Vars();
void Insts();
void Inst();
void Affec();
void Si();
void Tantque();
void Ecrire();
void Lire();
void Cond();
void Expr();
void AddOp();
void Term();
void MulOp();
void Fact();
void ID();
void Num();
void Chiffre();
void Lettre();

/*********** Main **********/

int main(){
    Program();
    return 1;
}

/*********** Functions **********/

bool verifyToken(token_code code_to_test){

    if( (currentToken = getToken()).code != code_to_test )
        return FALSE;
    return TRUE;
}

void SyntaxError(token_code code){
    printf("Syntax Error");
    exit(1);
}

void Program(){

    verifyToken(PROGRAM);
    verifyToken(ID);
    verifyToken(PV);
    Block();
    verifyToken(PT);
}

void Block(){
    Consts();
    Vars();
    Insts();
}

void Consts(){
    verifyToken(CONST);
    verifyToken(ID);
    do{
        verifyToken(EG);
        verifyToken(NUM);
        verifyToken(PV);
    }while(verifyToken(ID));
}

void Vars(){
    verifyToken(VAR);
    do{
        verifyToken(ID);
    }while(verifyToken(VIR));
    verifyToken(PV);
}

void Insts(){
    verifyToken(BEGIN);

    while (Inst())  
        verifyToken(PV);

    verifyToken(END);
}

void Inst(){

    switch((currentToken=getToken()).code){
        case BEGIN  :Insts();break;
        case ID     :Affec();break;
        case IF     :Si();break;
        case WHILE  :Tantque();break;
        case WRITE  :Ecrire();break;
        case READ   :Lire();break;
        default:
            SyntaxError();
    }
}

void Affec(){
    verifyToken(ID);
    verifyToken(AFF);
    Expr();
}

void Si(){
    verifyToken(IF);
    Cond();
    verifyToken(THEN);
    Inst();
}

void Tantque(){
    verifyToken(WHILE);
    Cond();
    verifyToken(DO);
    Inst();
}

void Ecrire(){
    verifyToken(WRITE);
    verifyToken(PO);
    
    while()
        Expr();
        verifyToken(VIR);

    verifyToken(PF);
}

void Lire(){
    verifyToken(WRITE);
    verifyToken(PO);
    
    while()
        verifyToken(ID);
        verifyToken(VIR);
    
    verifyToken(PF);
}

void Cond(){
    Expr();
    switch((currentToken=getToken()).code){
        case EG: case PLUS: case MOINS: case MULT:
        case DIV: case INF: case INFEG: case SUP:
        case SUPEG: break;
        default:
            SyntaxError();break;
    }
    Expr();
}

void Expr(){
    
    do{
        Term();
    }while(AddOp(););
        
    verifyToken(PV);
}

void AddOp(){
    switch((currentToken=getToken()).code ){
        case PLUS: case MOINS: break;
        default :
        SyntaxError();break;
    }
}

void Term(){

    do {
        Fact();
    } while(MulOp());
        
}

void MulOp(){
    switch((currentToken=getToken()).code ){
        case MULT: case DIV: break;
        default :
        SyntaxError();break;
    }
}

void Fact(){

    if(! (verifyToken(ID) || verifyToken(ID) || Expr()) )
        SyntaxError();
}