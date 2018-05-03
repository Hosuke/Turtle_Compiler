%{
	/* File/Module name: (turtle.l)
   * Author: <Yunen He>, u<5251400> and <Geyang Huang> , u<5421856>
	 * Date: <23 Oct 2015>
	 * Description:
	 */
	
	#include <stdio.h>
	#include <string.h>
	#include "turtle.tab.h"
	
	#define YY_USER_ACTION {        \
		yylloc.first_line = yylineno; \
		yylloc.last_line = yylineno;  \
	}
		
%}

DIGIT [0-9]
ALPHA [A-Za-z]

%option yylineno

%%

\/\/.*\n

turtle	return TURTLE;
var     return VAR;
fun     return FUNC;
if      return IF;
else    return ELSE;
up      return UP;
down    return DOWN;
moveto  return MOVETO;
read    return READ;
while   return WHILE;
return  return RETURN;

\==		  return EQ;
\<			return LE;
\+			return yytext[0];
\-			return yytext[0];
\*			return yytext[0];

\=			return ASSIGN;
\,			return yytext[0];
\(			return yytext[0];
\)			return yytext[0];       
\{			return yytext[0];             
\}			return yytext[0];

{DIGIT}+ {
	yylval.ival = atoi(yytext);
	return NUM;
}

{ALPHA}[A-Za-z0-9_']* {
	yylval.ident = strdup(yytext);
	return IDENT;
}

[\t\n\r]+

<<eof>>     { yyterminate(); }

%%