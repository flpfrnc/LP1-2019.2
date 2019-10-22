#include "../include/jogo.hpp"
#include "../include/tabuleiro.hpp"
#include "../include/jogador.hpp"

int turn = 1;
Player player1, player2;
int x, y;

void inputPlayers(){	//recebe dados (nomes) dos jogadores

	cout << "Digite o nome do jogador 1: ";
    cin >> player1.name;
    cout << endl;
    cout << "Digite o nome do jogador 2: ";
    cin >> player2.name;
}

void playerTurn(){	//imprime a escolha de posição no tabuleiro de cada jogador de acordo com a vez

	if(turn == 1){
	wrongMove();
	cout << "Jogador " << player1.name << " escolha a posição: " << endl;
	}else{
	wrongMove();
	cout << "Jogador " << player2.name << " escolha a posição: " << endl;
	}
}

void wrongMove(){	//verifica se a posição no tabuleiro foi inserida incorretamente (fora dos limites do array)
					//condição de 'posição já escolhida' já foi implementada no input dos players

	if(x < 0 || x > 9 || y < 0 || y > 9){
		cout << "Posição inválida, escolha novamente!" << endl;
		cout << endl;
	}

}