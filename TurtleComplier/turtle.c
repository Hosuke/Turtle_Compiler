/* File/Module name: (turtle.h)
 * Author: <Yunen He>, u<5251400> and <Geyang Huang> , u<5421856>
 * Date: <23 Oct 2015>
 * Description: main program
 */

#include "symtab.h"
#include "codegen.h"
#include "turtle.tab.h"

#include <stdio.h>
#include <string.h>

extern FILE *yyin;

int main(int argc, char *argv[]) {
	if(argc < 3) {
		printf("command line usage: ./turtle input.t output.p \n");
		return 0;
	}
	
	yyin = fopen(argv[1], "r");
	
	if(yyin == NULL) {
		printf("Error! opening file %s \n", argv[1]);
		return 0;
	}
	
	yyparse ();
	
	print_code(argv[2]);
	
	return 1;
}
