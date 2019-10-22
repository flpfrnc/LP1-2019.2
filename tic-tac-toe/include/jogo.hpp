#ifndef JOGO_HPP
#define JOGO_HPP

#include <iostream>
#include <cmath>
#include <cstring>
#include <stdlib.h>

using namespace std;

void gameStart(int (*v)[3]);
void playerPick(int (*v)[3]);
int manageTurn();
int checkFilling(int (*v)[3]);
bool checkCol(int (*v)[3], int p);
bool checkRow(int (*v)[3], int p);
bool checkDiag(int (*v)[3], int p);
int checkEquals(int (*v)[3]);
int checkWinner(int (*v)[3]);
void printWinner(int (*v)[3]);
void newRound(int (*v)[3]);
void finishGame(int (*v)[3]);



#endif