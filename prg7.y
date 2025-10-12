%{
#include<stdio.h>
#include<stdlib.h>
int yyerror(char *s);
extern int yylex();
int error_flag=0;
%}

%token NUMBER ID
%left '+''-'
%left '*''/'

%%
expression:
	term
	|expression'+' term
	|expression'-' term
;

term:
	factor
	|term'*' factor
	|term'/' factor
;

factor:
	NUMBER
	|ID
	|'(' expression ')'
;
%%

int yyerror(char *s){
	fprintf(stderr,"Invalid expression: %s\n",s);
	error_flag=1;
	return 0;
}

int main()
{
	printf("enter an arithmetic expression:");
	yyparse();
	
	if(error_flag){
		printf("expression validation failed. \n");
		return 1;
	}
	else{
		printf("expression is valid.\n");
		return 0;
	}
}

