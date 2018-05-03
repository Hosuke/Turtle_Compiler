flex turtle.l
bison -d turtle.y
gcc -o turtle turtle.tab.c lex.yy.c turtle.c codegen.c symtab.c -ll -ggdb