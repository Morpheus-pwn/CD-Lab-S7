%{ 
#include<stdio.h> 
int v=0,c=0; 
%} 

  

%% 
[aeiouAEIOU] {v++;} 
. {c++;} 
%% 

  

int main()
{ 
	printf("enter ip:"); 
	yylex(); 
	printf("consonent: %d",c); 
	printf("\nvowel: %d\n",v); 
} 


int yywrap()
{ 
	return 1; 
} 
