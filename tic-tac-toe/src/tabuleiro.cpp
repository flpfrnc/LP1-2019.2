#include "../include/jogo.hpp"
#include "../include/tabuleiro.hpp"
#include "../include/jogador.hpp"

char showableGame[3][3]; //tabuleiro visível com dados de X ou O

void resetBoard(int (*v)[3]){  //reseta o tabuleiro para -1
	int i, j;

	for(i = 0; i < 3; i++)
		for(j = 0; j < 3; j++)
			v[i][j] = -1;

	for(i = 0; i < 3; i++)
		for(j = 0; j < 3; j++)
			if(v[i][j] == -1)
				showableGame[i][j] = ' '; //atribui espaço às casas com valor -1
				
}

void printBoard(int (*v)[3]){	//mostra o tabuleiro visível juntamente com pontuação dos jogadores

	system("clear");
	cout << "	-----------------" << endl;
	cout << "	$  Tic-Tac-Toe  $" << endl;
	cout << "	-----------------" << endl;
	cout << endl;
	cout << player1.name << ": " << player1.wins << " vitórias  |  " << player2.name << ": " << player2.wins << " vitórias";
	cout << endl;
	cout << endl;
	
 	cout << "	     |     |     " << endl;
    cout << "	  " << showableGame[0][0] << "  |  " << showableGame[0][1] << "  |  " << showableGame[0][2] << endl;
    cout << "	-----|-----|-----" << endl;
	cout << "	  " << showableGame[1][0] << "  |  " << showableGame[1][1] << "  |  " << showableGame[1][2] << endl;
    cout << "	     |     |     " << endl; 
    cout << "	-----|-----|-----" << endl;
	cout << "	  " << showableGame[2][0] << "  |  " << showableGame[2][1] << "  |  " << showableGame[2][2] << endl;
    cout << "	     |     |     " << endl;
    
	cout << endl;
	cout << endl;	

	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			cout << v[i][j] << "\t";
			if(j == 2) cout << endl;
		}
	}
}

int initBoard(int (*v)[3]){	//inicializa o tabuleiro, utilizando a função reset para zerá-lo
	int i, j;

	resetBoard(v);		

	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			if(v[i][j] == -1){
			return v[i][j];
			printBoard(v);			
			}
		}
	}	

	cout << "Tabuleiro não inicializado corretamente!" << endl;
	return 0;
}


void positX(int (*v)[3]){	//input de dados do player 1

	if(v[x-1][y-1] == -1){
		v[x-1][y-1] = 1;
		showableGame[x-1][y-1] = 'X';
		manageTurn();
		printBoard(v);

	}else
		if((v[x-1][y-1] == 0) || (v[x-1][y-1] == 1)){
			cout << "Posição já escolhida!" << endl;	
		}

	checkFilling(v);
	checkEquals(v);
}

void positO(int (*v)[3]){   //input de dados do player 2

	if(v[x-1][y-1] == -1){
		v[x-1][y-1] = 0;
		showableGame[x-1][y-1] = 'O';
		manageTurn();
		printBoard(v);

	}else
		if(v[x-1][y-1] == 0 || v[x-1][y-1] == 1){
			cout << "Posição já escolhida!" << endl;
		}
	checkFilling(v);
	checkEquals(v);
	
	
}

void inputPosition(int (*v)[3], int t){	 //verifica o turno do jogador da vez escolhe o input de acordo

	printBoard(v);
	playerTurn();
	
	cout << "x: ";
	cin >> x;
	cout << "y: ";
	cin >> y;
	cout << endl;

	if(t == 1){
		positX(v);
		printWinner(v);;
	}
	else if(t == 2){
		positO(v);
		printWinner(v);
	}
}