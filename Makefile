run : a.out
	./a.out "test.c"
clean: 
	rm lex.yy.c parser.tab.c *.o  parser.tab.h a.out
	
lex.yy.c : lexer.l parser.tab.c
	flex lexer.l
parser.tab.c : parser.y
	bison -d parser.y
lex.yy.o : lex.yy.c
	gcc -c lex.yy.c
parser.tab.o : parser.tab.c
	gcc -c parser.tab.c
symboltable.o : symboltable.c
	gcc -c symboltable.c	
a.out : lex.yy.o parser.tab.o symboltable.o
	gcc parser.tab.o lex.yy.o symboltable.o -lm -ll 