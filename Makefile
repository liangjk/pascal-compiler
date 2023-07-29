all : pascal.l pascal.y
	bison -d pascal.y
	flex -i --yylineno pascal.l
	g++ lex.yy.c pascal.tab.c interpret.c -o compiler

clean :
	-rm compiler syntax.out lex.yy.c pascal.tab.c pascal.tab.h
