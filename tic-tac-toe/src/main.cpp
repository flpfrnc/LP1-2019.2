#include "../include/jogo.hpp"
#include "../include/tabuleiro.hpp"
#include "../include/jogador.hpp"

int main(int argc, char const *argv[])
{
	
	int board[3][3]; //tabuleiro principal, recebe -1, 1 e 
	                 //(' ', 'X' e 'O' respectivamente no tabuleiro visível)

	gameStart(board);

	return 0;
}