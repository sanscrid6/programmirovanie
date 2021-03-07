task: task1.c
	gcc -pedantic -ansi task1.c -o task -lm
test: task1.c task1test.c
	gcc -pedantic -ansi -o test task1test.c task1.c -D TESTING -lm