#ifndef FUNKS_H
#define FUNKS_H
int isPalindrome(char* str);
void initMatrix(char*** matrix, int verticalSize, int horizontalSize, char** strings);
void freeMatrix(char*** matrix, int verticalSize);
void editMatrix(char*** matrix, int verticalSize, int horizontalSize);
#endif