%{
#include <stdio.h>
%}

%option noyywrap

DIGIT       [0-9]
ID          [a-zA-Z_][a-zA-Z0-9_]*

%%

"if"|"else"|"while"|"do"|"for"|"int"|"float"|"char"|"double"|"return"|"void"|"main" {
    printf("KEYWORD: %s\n", yytext);
}

{ID} {
    printf("IDENTIFIER: %s\n", yytext);
}

{DIGIT}+(\.{DIGIT}+)? {
    printf("NUMBER: %s\n", yytext);
}

\"[^\"\n]*\" {
    printf("STRING: %s\n", yytext);
}

[-+*/%=<>!&|^] {
    printf("OPERATOR: %s\n", yytext);
}

[;,(){}\[\]] {
    printf("SYMBOL: %s\n", yytext);
}

[ \t\n]+ { 
    /* Do nothing */ 
}

. { 
    /* printf("UNKNOWN: %s\n", yytext); */ 
}

%%

int main() {
    printf("Enter code to tokenize (Press Ctrl+D or Ctrl+C to end input):\n");
    yylex();
    return 0;
}