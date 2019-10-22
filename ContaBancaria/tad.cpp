#include <iostream>
#include "contabancaria.h"

int main(){

    ContaBancaria account;
    //inicializando uma nova conta
    Iniciar(&account, 123456, 133.76);
    //impressão de valores para verificação de corretude
    Imprimir(account);

    //realização de depósito e saque
    Depositar(&account, 25.00);
    Sacar(&account, 43.56);
    
    //nova impressão para verificar se operações foram realizadas corretamente
    cout << "Saldo apos operacoes: " << endl;
    Imprimir(account);

return 0;
}