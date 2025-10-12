%{ 
#include<stdio.h> 
int valid=1; 
%} 
  

%token digit letter 

  
%% 
start: letter s 
s: letter s | digit s |; 
%% 

  
int yyerror() 
{ 
	printf("invalid identifier.\n"); 
	valid=0; 
	return 0; 
} 

  

int main() 
{ 
	printf("enter identifier:"); 
	yyparse(); 
	if(valid) 
	{ 
		printf("Valid Identifier.\n"); 
	} 

} 
