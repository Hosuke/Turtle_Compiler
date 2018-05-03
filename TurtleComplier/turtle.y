%{
	/* File/Module name: (turtle.y)
   * Author: <Yunen He>, u<5251400> and <Geyang Huang> , u<5421856>
	 * Date: <23 Oct 2015>
	 * Description:
	 */
	
	#include <stdio.h>
	#include "symtab.h"
	#include "codegen.h"
	
	void yyerror(const char *s);
	  
	/* TABLE FOR UNRESOLVED FUNCTION CALLS
	 * It is legal to call a function before defining it. 
	 * Keeping unresolved functions, we can backpatch their addresses.
	 */
	
	typedef struct {
		// function name
		char *ident;
		// the number of parameters
		char num_param;
		// a location where the function is defined
	  unsigned short jump_to;
		int line;
	} unresolved_func_call;
	
	int unresolved_func_call_index = 0;
  unresolved_func_call unresolved_func_call_table[1000];
	
	/* prototypes */
	// generate PDPlot-2 code to call a function
	// return 1 on successfully emitting code or keeping an unresovled function call
	// return 0 on mismatch between the number of parameters in the definition of a function and the number of arguments in a call
	int call_func(char *ident, int num_args);	
	
	/* the scope of global variables is NULL */
	sym_func *scope = NULL;
	
%}

%locations

%code requires {
    #include "symtab.h"
    typedef unsigned short address;
}

%union {
	char *ident;
	int ival;
	sym_func *func;
	address address;
}

%token <ident> IDENT
%token <ival> NUM

%token TURTLE
%token UP DOWN MOVETO
%token VAR
%token ASSIGN
%token READ
%token IF ELSE
%token WHILE
%token RETURN
%token FUNC 
%token LE EQ

%nonassoc IFX
%nonassoc ELSE

%left '+' '-'
%left '*'
%nonassoc UMINUS

%type <func> func_ident
%type <ival> parameters
%type <ival> parameter_list
%type <ival> actuals
%type <ival> actual_list

%type <address> global_variables
%type <address> comp
%type <address> whilepart
%type <address> elsepart

%start program

%%
	/* PROGRAM */
	program : TURTLE IDENT global_variables funcs {
		// After parsing function declarations, turtle compiler knows their location. 
		// Therefore, the compiler could jump over function declarations from global variables.
		backpatch($3, get_address());
	}
	block {
    emit(OPR_HALT);
		 
		int i;
    for(i = 0; i < unresolved_func_call_index; i++) {
			unresolved_func_call call = unresolved_func_call_table[i];
			sym_func *f = get_func(call.ident);			
			if(f == NULL) {
			  printf("undefined function : %s, line %d \n", call.ident, call.line);
				YYERROR;
			} else if((*f).num_param != call.num_param) {
	      printf("%d parameter(s) defined in the function %s, %d argument(s) in this call, line %d \n", call.num_param, call.ident, call.num_param, call.line);
        YYERROR;
			}
			else {
				backpatch(call.jump_to, (*f).address);
			}
    }
		
	}
	;

	/* VARIABLE DECLARATIONS */
	global_variables : var_declarations {
		// jump to block (compound statements)
		$$ = emit_two(OPR_JUMP, 0);
	}
	;

	var_declarations : decl var_declarations
									 | /* empty */
									 ;

	decl : VAR IDENT initialization {
		// create a new variable within the scope
		signed char address = get_var_address(scope);
		sym_var *var = add_var($2, scope, address);
		
		if (var == NULL) {
			char error_msg[100];
		  sprintf(error_msg, "The variable %s is declared twice in the same scope.", $2);
		  yyerror(error_msg);
      YYERROR;
		}
	}
	;

	initialization : ASSIGN expr
								 | /* empty */ {
									 // push a value onto the top of the stack
									 emit_two(OPR_LOADI, 0);
								 }
								 ;

	/* FUNCTION DECLARATIONS */
	funcs : func funcs 
				| /* empty */
				;

	func : func_ident '(' parameters ')' {
		// keep the number of parameters for the symbol table
		(*$1).num_param = $3;
	}
	var_declarations block {
		// reset the scope once parsing the current function is complete.
		scope = NULL;
		emit(OPR_RTS);
	}
	;
	
	func_ident : FUNC IDENT {
		// add a new function
		sym_func *f = add_func($2, get_address());
		
		if (!f) {
			char error_msg[100];
		  sprintf(error_msg, "The function %s is declared twice in the same scope.", $2);
		  yyerror(error_msg);
      YYERROR;
		}
		
		// update the scope
		scope = f;
		// flow up to keep the number of parameters
		$$ = f;
	}
	;

	parameters : IDENT parameter_list {
		// The formal parameters are also referenced relative to the FP.
		// Notice that the first parameter is (–n–1) away from FP and the last is at -2(FP).
		signed char address = -2 - $2;
		add_var($1, scope, address);
		$$ = $2 + 1;
	}
	           | /* empty */ { $$ = 0; }
						 ;

	parameter_list : ',' IDENT parameter_list {
		signed char address = -2 - $3;
		add_var($2, scope, address);
		$$ = $3 + 1;
	}
	               | /* empty */ { $$ = 0; }
								 ;

	/* STATEMENTS */
	block : '{' stmts '}' 
	      | '{''}' 
	      ; 

	stmts : stmt stmts 
	      | stmt
				;

	stmt : UP { emit(OPR_UP); }
	     | DOWN { emit(OPR_DOWN); }
			 | MOVETO '(' expr ',' expr ')' { emit(OPR_MOVE); }
			 | READ '(' IDENT ')' {
				 
				 sym_var *var = get_var($3, scope);
				 
		 		if (var == NULL) {
					char error_msg[100];
				  sprintf(error_msg, "undeclared variable : %s", $3);
				  yyerror(error_msg);
					YYERROR;
		 		}
				
				 emit_offset(OPR_READ, (*var).scope != NULL ? 1 : 0, (*var).address);
				 
			 }
			 | IDENT ASSIGN expr {
				 sym_var *var = get_var($1, scope);
				 
				 if (var == NULL) {
 					char error_msg[100];
				  sprintf(error_msg, "undeclared variable : %s", $1);
 				  yyerror(error_msg);
 					YYERROR;
				 }
				 else {
					 emit_offset(OPR_STORE, (*var).scope != NULL ? 1 : 0, (*var).address);				 
				 }
				 
			 }
			 | IF '(' comp ')' stmt {
				 // hop over the stmt
				 backpatch($3, get_address());
			 } %prec IFX 
			 | IF '(' comp ')' stmt elsepart stmt {
				 // hop over the second stmt
				 backpatch($6, get_address());
				 // jump to the first stmt
				 backpatch($3, $6+2);
			 }
			 | whilepart '(' comp ')' stmt {
				 // build a loop and keep watching the condition
				 emit_two(OPR_JUMP, $1);
				 backpatch($3, get_address());
			 }
			 | RETURN expr {
				 // Error
				 if (scope == NULL) {
					 char error_msg[100];
				   sprintf(error_msg, "A return statement is in the main program.");
				   yyerror(error_msg);
           YYERROR;
				 }
				 else {
					 // Notice that the first parameter is (–n–1) away from FP and the last is at -2(FP).
					 emit_offset(OPR_STORE, 1, -2 - (*scope).num_param);
					 emit(OPR_RTS);
				 }
			 }
			 | IDENT {
				 emit_two(OPR_LOADI, 0);
			 }'(' actuals ')' {				 
         if(call_func($1, $4) == 0) { YYERROR; } 
			 }
			 | block
			 ;
	
	comp: expr EQ expr {
		emit(OPR_SUB);
		emit(OPR_TEST);
		emit_two(OPR_POP, 1);
		// hop over the escape Jump
		emit_two(OPR_JEQ, get_address() + 4);
		// jump over <code for body>
		$$ = emit_two(OPR_JUMP, 0);
	}
			| expr LE expr {
				emit(OPR_SUB);
				emit(OPR_TEST);
				emit_two(OPR_POP, 1);
				// hop over the escape Jump
				emit_two(OPR_JLT, get_address() + 4);
				// jump over <code for body>
				$$ = emit_two(OPR_JUMP, 0);
			}
			;
	
	elsepart : ELSE { $$ = emit_two(OPR_JUMP, 0); };
	
	whilepart : WHILE { $$ = get_address(); };

	/* EXPRESSIONS AND ARGUMENTS */
	expr : NUM {

		unsigned short val = $1;
		
		if (val >= 0 && val <= 32767) {
			emit_two(OPR_LOADI, val);
		}
		else {
      char error_msg[100];
      sprintf(error_msg, "out of range error: %d", val);
      yyerror(error_msg);
      YYERROR;
		}
		
	}
 			 | IDENT {
				 
				 sym_var *var = get_var($1, scope);
				 
				 if (var == NULL) {
  					char error_msg[100];
					  sprintf(error_msg, "undeclared variable : %s", $1);
  				  yyerror(error_msg);
  					YYERROR;
				 }
				 else {
					 emit_offset(OPR_LOAD, (*var).scope != NULL ? 1 : 0, (*var).address);
				 }
				 
			 }
	     | IDENT '(' 
	       {					 					 
					 emit_two(OPR_LOADI, 0);
	       } actuals ')' 
	        {
	          if(call_func($1, $4) == 0) { YYERROR; } 
	        } 
	 		 | '-' expr  %prec UMINUS {
				 emit(OPR_NEG);
			 }
			 | expr '+' expr {
				 emit(OPR_ADD);
			 }
			 | expr '-' expr {
				 emit(OPR_SUB);
			 }
			 | expr '*' expr {
				 emit(OPR_MUL);
			 }
	 		 | '(' expr ')'	 
			 ;
		 
	actuals : expr actual_list {$$ = $2 + 1;}
	        | /* empty */ {$$ = 0;}
					;

	actual_list : ',' expr actual_list {$$ = $3 + 1;}
		          | /* empty */ {$$ = 0;}
						  ;
%%

void yyerror(const char *s) {
	printf("%s line: %d \n", s, yylloc.first_line);
}

int call_func(char *name, int num_args) {
	
	sym_func *f = get_func(name);
	
	if (f) {
		if ((*f).num_param == num_args) {
			emit_two(OPR_JSR, (*f).address);
			emit_two(OPR_POP, (*f).num_param);
			return 1;
		}
		else {
			char error_msg[100];
      sprintf(error_msg, "%d parameter(s) defined in the function %s, %d argument(s) in this call", (*f).num_param, name, num_args);
		  yyerror(error_msg);
		}
	}
	else {
		// keep an unresovled function call
		
    unresolved_func_call func_call;
		
    func_call.num_param = num_args;
    func_call.ident = name;
    func_call.line = yylloc.first_line;
    func_call.jump_to = emit_two(OPR_JSR, 0);
    emit_two(OPR_POP, num_args);

    unresolved_func_call_table[unresolved_func_call_index] = func_call;
    unresolved_func_call_index = unresolved_func_call_index + 1;
		
		return 1;
	}
	return 0;
}