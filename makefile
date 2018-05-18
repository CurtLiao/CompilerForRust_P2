scanner: lex.yy.o y.tab.o symbols.o y.tab.h
	gcc -o p symbols.o y.tab.o -ll

y.tab.h: yaccpro2.y
	byacc -d yaccpro2.y

lex.yy.o: scanner.l y.tab.h
	flex scanner.l
	gcc -c -g lex.yy.c
y.tab.o: y.tab.c
	gcc -c -g y.tab.c

symbols.o: symbols.c symbols.h
	gcc -c -g symbols.c

clean:
	rm -f *.o lex.yy.c y.tab.h y.tab.c
