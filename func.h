#ifndef _FUNC_HEADER_
#define _FUNC_HEADER_

void userGuide();
void genMatrix(int** matrix, int n, int dir, int clock);
void printMatrix(int** matrix, int n);
void saveToFile(int** matrix, int cn, char* cd, char* cc);
void loadFromFile(int** matrix, char* fajlnev, int n);

#endif