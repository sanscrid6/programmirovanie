task: task2.c
	gcc -pedantic -ansi task2.c -o task -lm
test: task2.c task2test.c
	gcc -pedantic -ansi -o test task2test.c task2.c -D TESTING -lm