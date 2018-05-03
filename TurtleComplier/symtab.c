/* File/Module name: (symtab.c)
 * Author: <Yunen He>, u<5251400> and <Geyang Huang> , u<5421856>
 * Date: <15 Oct 2015>
 * Description: symbol tables for Turtle Compiler
 */

#include "symtab.h"
#include <stdio.h>
#include <string.h>

/* SYMBOL TABLE FOR FUNCTION DECLARATIONS */
int func_index = 0;
sym_func func_table[FUNC_TABLE_SIZE];

sym_func *add_func(char *ident, int address) {
	if (get_func(ident)) {
		return NULL;
	}

	sym_func *entry = &func_table[func_index];
	(*entry).ident = ident;
	(*entry).address = address;
	(*entry).num_param = 0;
	(*entry).num_var = 0;
	
  func_index = func_index + 1;
	
	return entry;
}

sym_func *get_func(char *ident) {
	int i;
	for (i = 0; i < func_index; i++) {
		if(strcmp(ident, func_table[i].ident) == 0) {
	    return &func_table[i];
		}
	}
	return NULL;
}

/* SYMBOL TABLE FOR VARIABLE DECLARATIONS */
sym_var var_table[VAR_TABLE_SIZE];
int var_index = 0;
signed char num_global_vars = 0;

sym_var *add_var(char *ident, sym_func *scope, signed char address) {
	/* 
	 * Variables allowed to be added should satisfy any one of following conditions.
	 * Case 1 Variable name already exists in the symbol table but the scope is different.
	 * Case 2 different variable name
	*/
	
	int i;
  for(i = 0; i < var_index; i++) {
		if(strcmp(ident, var_table[i].ident) == 0) {
			if(scope == var_table[i].scope) {
				// duplicated
				// refuse to add this variable
				return NULL;
			}
			else {
				// This variable has a different scope.
				// It is allowed to be added. 
				break;
			}
		}
	}
	
	sym_var *entry = &var_table[var_index];
	(*entry).ident = ident;
	(*entry).scope = scope;
	(*entry).address = address;
	
	var_index = var_index + 1;
	
	return entry;
}

sym_var *get_var(char * ident, sym_func *scope) {
  sym_var *var = NULL;
	
	int i;
	for(i = 0; i < var_index; i++) {
		// found in the symbol table
		if(strcmp(ident, var_table[i].ident) == 0) {		
			
			// Is a global variable or local variable?
			if(var_table[i].scope == NULL) {
				// global variable
				var = &var_table[i];
				
				if(scope == NULL) {
					// global variable used in the main body of program
					return var;
				}
				
			}
			else if(scope != NULL && scope == var_table[i].scope) {
				// local variable
				return &var_table[i];
			}
		}
	}	
	
	// global variable used outside of the main body of program
  return var;
}

signed char get_var_address(sym_func *scope) {
	// global variable
	if(scope == NULL) {
		num_global_vars = num_global_vars + 1;
		return num_global_vars;
	}
	else {
		// local variable
		(*scope).num_var = (*scope).num_var + 1;
		return (*scope).num_var;
	}
}