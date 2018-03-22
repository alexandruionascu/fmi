%{
   #include <math.h>
   #include <stdio.h>
%}

%option yylineno
digit [0-9]
alpha [a-zA-Z]
id   [a-zA-Z_][a-zA-Z0-9_]*
keyword auto|double|int|struct|break|else|long|switch|case|enum|register|typedef|char|extern|return|union|const|float|short|unsigned|continue|for|signed|void|default|goto|sizeof|volatile|if|static|while|asm|bool|catch|class|const_cast|delete|dynamic_cast|explicit|export|false|friend|inline|mutable|namespace|new|operator|private|protected|public|reinterpret_cast|static_cast|template|this|throw|true|try|typeid|typename|using|virtual|wchar_t
string \"[^\n"]*\"
character ['].[']
int_nr {digit}+
float_nr1 {int_nr}\.?({int_nr})?([eE]([+-]?{int_nr}))?
float_nr2 \.?({int_nr})([eE]([+-]?{int_nr}))?
number {int_nr}|{float_nr1}|{float_nr2}
arithmetic_operators "+"|"-"|"*"|"/"|"++"|"--"|"%"|"="|"+="|"-="|"*="|"/="|"%="|"++"|"--"
logical_operators "||"|"&&"|"!"|"!="|"|"|"&"|"^"
bit_operators "~"|">>"|"<<"
comp_operators "<"|">"|"<="|">="|"=="
other_operators "typeof"|"sizeof"|"new"|"malloc"|"delete"|"type"|"."|"#"|"->"
separator ";"|":"|","|"("|")"|"["|"]"|"{"|"}"|"()"|"{}"|"[]"
single_line_comment "//".*
multi_line_comment [/][*][^*]*[*]+([^*/][^*]*[*]+)*[/]
%%

{int_nr} {
	printf("line %d: INTEGER: %s\n", yylineno, yytext);
}
{float_nr1}|{float_nr2} {
	printf("line %d: FLOAT: %s \n", yylineno, yytext);
}
{keyword} {
	printf("line %d: KEYWORD: %s\n", yylineno, yytext);
}
{id} printf("line %d: IDENTIFIER: %s\n", yylineno, yytext);
{arithmetic_operators}|{logical_operators}|{bit_operators}|{comp_operators}|{other_operators} {
	printf("line %d: OPERATOR: %s\n", yylineno, yytext);
}
{string} printf("line %d: STRING: %s\n", yylineno, yytext);
{character} printf("line %d: CHARACTER %s\n", yylineno, yytext);
{separator} printf("line %d: SEPARATOR %s\n", yylineno, yytext);
{single_line_comment} printf("line %d: SINGLE_LINE_COMMENT: %s\n", yylineno, yytext);
{multi_line_comment} {
	// count how many lines
	int lines = 1;	
	int length = strlen(yytext);								
	for(int i = 1; i < length; i++) {
		if(yytext[i] == '\n') {
			lines++;
		}
	}
	
	// parse each line
	char* input = strtok(yytext,"\n");
	char* first_line = input;
	char* last_line;				
	while (input != NULL) {					
		last_line = input;
		input = strtok (NULL, "\n");
	}			
			
	if (lines == 1) {
		printf("line %d: SINGLE_LINE_COMMENT: %s\n", yylineno, yytext);
	} else {
		printf("line %d: MULTI_LINE_COMMENT (%d lines): \n \t - first line: %s \n \t - last line: %s\n", 
			yylineno - lines + 1, lines, first_line, last_line);		
	}
}

[ \t\n]+ /* eat whitespace */
. printf("line %d: UNKNOWN CHARACTER: %s\n", yylineno, yytext);
%%

int main( int argc, char **argv ) {	
	
	if (argc > 1) {
		yyin = fopen(argv[1], "r" );
		yylex();
 	}
	else {
    	printf("Please select an input file");
  	}
}

int yywrap() {
	return(1);
}


