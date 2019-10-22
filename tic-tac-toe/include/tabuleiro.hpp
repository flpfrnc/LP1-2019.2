#ifndef TABULEIRO_HPP
#define TABULEIRO_HPP

#include <iostream>
#include <cmath>
#include <cstring>
#include <stdlib.h>

using namespace std;

void resetBoard(int (*v)[3]);
void printBoard(int (*v)[3]);
int initBoard(int (*v)[3]);
void positX(int (*v)[3]);
void positO(int (*v)[3]);
void inputPosition(int (*v)[3], int t);

#endif