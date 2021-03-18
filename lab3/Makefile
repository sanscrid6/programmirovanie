task: task1.c
	gcc -pedantic -ansi task1.c -o task -lm
test: task1.c test.c
	gcc -pedantic -ansi -o test test.c task1.c -D TESTING -lm