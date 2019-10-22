#include "../include/jogo.hpp"
#include "../include/tabuleiro.hpp"
#include "../include/jogador.hpp"


void gameStart(int (*v)[3]){    //função inicializa o jogo, chamando funções de inicio de tabuleiro e input
   
        initBoard(v);
        inputPlayers();
        playerPick(v);
 }

void playerPick(int (*v)[3]){   //inicializa o input das posições com o turno começado em 1 (player 1 sempre começa)

    inputPosition(v, turn);
}

int manageTurn(){   //faz a troca dos turnos (entre jogador 1 e 2)

    if(turn == 1){
        turn = 2;
    }
    else{
        turn = 1;
    }   

    return turn;
}

int checkFilling(int (*v)[3]){   //checa se o tabuleiro já foi completado
    int i, j, chkCompletion = 0;

    for(i = 0; i < 3; i++)
        for(j = 0; j < 3; j++)
            if(v[i][j] > -1){

                chkCompletion += 1;
                
            }else{

                chkCompletion = 0;
            }

    return chkCompletion;
}

bool checkCol(int (*v)[3], int p){  //checa se houve vitória nas colunas
    
    for(int i = 0; i < 3; ++i) {
        if(v[0][i] == v[1][i] && v[1][i] == v[2][i] && v[2][i] == p)
        {
            return true;           
        }
    }
return false;
}

bool checkRow(int (*v)[3], int p){  //checa se houve vitória nas linhas

    for(int i = 0; i < 3; ++i) {
        if(v[i][0] == v[i][1] && v[i][1] == v[i][2] && v[i][2] == p)
        {
            return true;                                  
        }
    }
return false;
}

bool checkDiag(int (*v)[3], int p){  //checa se houve vitória nas diagonais

    if(v[0][0] == v[1][1] && v[1][1] == v[2][2] && v[2][2] == p){
        return true;
    }else
        if(v[0][2] == v[1][1] && v[1][1] == v[2][0] && v[2][0] == p){
            return true;
        }

return false;
}


int checkEquals(int (*v)[3]){   //checa se alguém já completou 3 fileiras (e consequentemente ganhou)
   

    if(checkRow(v, 1) || checkCol(v, 1) || checkDiag(v, 1)){
        return 1;
    }else
        if(checkRow(v, 0) || checkCol(v, 0) || checkDiag(v, 0)){
            return 2;
    }else{
        return 0;
    }

    return -1;
}

int checkWinner(int (*v)[3]){   //utiliza retorno da função anterior para decidir se houve ganhador na rodada
                                
    if(checkEquals(v) == 1){
        return 1;

    }else
        if(checkEquals(v) == 2){
            return 2;

        }else
             if(checkFilling(v) == 9 && checkEquals(v) == 0){     
            return 0;   //retorno checkFilling + checkEquals garante que se o tabuleiro estiver completo e sem ganhadores o retorno é 0

        }

    return -1;
}

void printWinner(int (*v)[3]){      //imprime o ganhador da rodada de acordo com o retorno da função checkWinner
                                    //incrementa uma vitória para o jogador vencedor
    if(checkWinner(v) == 1){
        player1.wins += 1;
        turn = 1;
        if(player1.wins == 3){      //verifica se já houveram 3 vitórias (condição de fim do jogo)
            finishGame(v);
        }else{
            newRound(v);  
                  
        }
    }else
        if(checkWinner(v) == 2){
            player2.wins += 1;
            turn = 1;
            if(player1.wins == 3){
                finishGame(v);
            }else{
                newRound(v);
                
            }
            
        }else
            if(checkWinner(v) == 0){
                newRound(v);            //começa um novo round caso haja empate
            }else
                if(checkWinner(v) == -1){
                    inputPosition(v, turn);
            }
}

void newRound(int (*v)[3]){       //em caso de vitórias de rodada de cada jogador serem menores que 3, inicia uma nova rodada

    if(player1.wins < 3 || player2.wins < 3){

        initBoard(v);
        inputPosition(v, turn);
    }

}

void finishGame(int (*v)[3]){  //verifica se algum dos jogadores atingiu o requisito (3 rodadas ganhas) para terminar o jogo
    
    if(player1.wins == 3){
        printBoard(v);
        cout << player1.name << " ganhou o jogo!!!" << endl;
    }else
        if(player2.wins == 3){
            printBoard(v);
            cout << player2.name << " ganhou o jogo!!!" << endl;
        }
}