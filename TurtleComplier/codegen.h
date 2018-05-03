/* File/Module name: (codegen.h)
 * Author: <Yunen He>, u<5251400> and <Geyang Huang> , u<5421856>
 * Date: <16 Oct 2015>
 * Description: code generation
 */

/* SINGLE WORD INSTRUCTIONS */
#define OPR_HALT  0x0000
#define OPR_UP    0x0A00
#define OPR_DOWN  0x0C00
#define OPR_MOVE  0x0E00
#define OPR_ADD   0x1000
#define OPR_SUB   0x1200
#define OPR_NEG   0x2200
#define OPR_MUL   0x1400
#define OPR_TEST  0x1600
#define OPR_RTS   0x2800

/* SINGLE WORD INSTRUCTIONS WITH OFFSETS */
#define OPR_LOAD  0x0600
#define OPR_STORE 0x0400
#define OPR_READ  0x0200

/* TWO WORD INSTRUCTIONS */
#define OPR_JSR   0x6800
#define OPR_JUMP  0x7000
#define OPR_JEQ   0x7200
#define OPR_JLT   0x7400
#define OPR_LOADI 0x5600
#define OPR_POP   0x5E00

// The PDPlot-2 is a contrived line plotting machine with 16-bit words addressed from 0 to 65535.
// One instruction contains 16-bit words (Unsigned short (16-bit)). 
// Unsigned short (16-bit)
typedef unsigned short address;

/*
 * emit a single word instruction and return the address of this instruction
 */
address emit(unsigned short instruction);

/*
 * emit a single word instruction with offset and return the address of this instruction
 * fp (an activation frame pointer)
 * The index offset is a 2’s-complement byte-length integer (Signed char (8-bit) Two's complement). 
 */
address emit_offset(unsigned short instruction, int fp, signed char index_offset);

/*
 * emit a two-words instruction return the address of the first word
 */
address emit_two(unsigned short instruction, unsigned short argument);

/*
 * if (exp1 == exp2) {body}
 * <code to evaluate exp2>
 * <code to evaluate exp1>
 * 134 Sub
 * 135 Test
 * 136 Pop
 * 137 #1
 * 138 Jeq
 * 139 #142
 * 140 JUMP (first_word)
 * 141 #??? (second_word) 
 * 142 <code for body>  
 * ??? ...
 * 
 * repalce second_word with a new value target_address
 */
void backpatch(address first_word_address, address target_address);

/*
 * return an available address
 */
address get_address();

/*
 * print code to a file
 */
void print_code(char *filename);