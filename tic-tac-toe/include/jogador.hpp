#ifndef JOGADOR_HPP
#define JOGADOR_HPP

#include <iostream>
#include <cmath>
#include <cstring>
#include <stdlib.h>

using namespace std;

class Player{ 	//classe jogador contendo dados necessários para que o game seja iniciado e wins/turnos contados
	
	public:
		string name;	
		int wins;

};

extern int turn;
extern int x, y;
extern Player player1, player2;
		
void inputPlayers();
void playerTurn();
void wrongMove();
	

#endif