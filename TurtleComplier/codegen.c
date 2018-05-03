/* File/Module name: (codegen.c)
 * Author: <Yunen He>, u<5251400> and <Geyang Huang> , u<5421856>
 * Date: <16 Oct 2015>
 * Description: code generation
 */

#include <stdio.h>
#include "codegen.h"

// The PDPlot-2 is a contrived line plotting machine with 16-bit words addressed from 0 to 65535.
unsigned short buffer[65536];
address counter = 0;

address emit(unsigned short instruction) {
	address instruction_addr = counter;
	buffer[instruction_addr] = instruction;
	counter = counter + 1;
	return instruction_addr;
}

address emit_offset(unsigned short instruction, int fp, signed char index_offset) {
	if (fp) {
		// The bottom bit of the top byte (bit 8) indicates the register to be indexed: 0 for GP and 1 for FP.
		// change index register to 1 due to the subroutine call instruction
		instruction = instruction | 0x0100;
	}
	
  instruction = instruction | ((unsigned char) index_offset);
	
	return emit(instruction);
}

address emit_two(unsigned short instruction, unsigned short argument) {
	address first_word_addr = emit(instruction);
	emit(argument);
	return first_word_addr;
}

void backpatch(address first_word_address, address target_address) {
	address second_word_address = first_word_address + 1;
	buffer[second_word_address] = target_address;
}

address get_address() {
	return counter;
}

void print_code(char *filename) {
	FILE *fptr = fopen(filename, "w");
	int i;
	for (i = 0; i < counter; i++) {
		fprintf(fptr, "%d\n", buffer[i]);
	}
	fclose(fptr);
}