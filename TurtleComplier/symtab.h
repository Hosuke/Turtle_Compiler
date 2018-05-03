/* File/Module name: (symtab.h)
 * Author: <Yunen He>, u<5251400> and <Geyang Huang> , u<5421856>
 * Date: <15 Oct 2015>
 * Description: symbol tables for Turtle Compiler
 */

#ifndef SYMTAB
#define SYMTAB

/* CONSTANTS */
#define FUNC_TABLE_SIZE	1000
#define VAR_TABLE_SIZE 1000

/* SYMBOL TABLE FOR FUNCTION DECLARATIONS */
// a type for function declarations
typedef struct {
	// function name
	char *ident;
	// entry address
	int address;
	// the number of parameters
	char num_param;
	// the number of variables
	char num_var;
} sym_func;

/*
 * add a new function to the symbol table
 * If this new function was successfully added, then the method add_func returns the pointer of the new function.
 * Otherwsie, it returns NULL (This function has been added).
 */
sym_func *add_func(char *ident, int address);

/*
 * search for a function with the name inside the symbol table
 * If this function exists in the symbol table, then the method get_func returns the pointer of the function.
 * Otherwsie, it returns NULL (This function does not exist in the symbol table).
 */
sym_func *get_func(char *ident);

/* SYMBOL TABLE FOR VARIABLE DECLARATIONS */
// a type for variable declarations
typedef struct {
	// variable name
	char *ident;
	// a pointer referencing to a function containing this variable
	// NULL for a global variable
	sym_func *scope;
	// entry address
	char address;
} sym_var;

/*
 * add a new variable with the given scope (a function containning this new variable) and address to the symbol table
 * If this new variable was successfully added, then the method add_var returns the pointer of the new variable.
 * Otherwsie, it returns NULL (This variable exites in the given scope).
 */
sym_var *add_var(char *ident, sym_func *scope, signed char address);

/*
 * search for a variable with the given scope
 * If this variable with the given scope exists in the symbol table, then the method get_var returns an integer 1.
 * Otherwsie, it returns an integer 0 (This variable with the given scope does not exist in the symbol table).
 */
sym_var *get_var(char *ident, sym_func *scope);

/*
 * return an available variable address within a given scope. 
 */
signed char get_var_address(sym_func *scope);

#endif