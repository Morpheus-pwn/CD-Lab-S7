%{
#include "y.tab.h"
	#include<stdlib.h>
	extern int yylval;
%}	

%%
[0-9]+ { yylval = atoi(yytext); return NUMBER; }
[a-zA-Z_][a-zA-Z_0-9]* { return ID; };
"+" {return '+';}
"-" {return '-';}
"*" {return '*';}
"/" {return '/';}
"(" {return '(';}
")" {return ')';}
[\t]+ ;
\n { return 0; }
. { return yytext[0]; }
%%

int yywrap()
{
	return 1;
}

