#include <iostream>
#include"contabancaria.h"

void Iniciar(ContaBancaria *conta, int numero, float saldo){
conta->numero = numero;
conta->saldo = saldo;
}
void Depositar(ContaBancaria *conta, float valor){
conta->saldo += valor;
}
void Sacar(ContaBancaria *conta, float valor){
conta->saldo -= valor;
}
void Imprimir(ContaBancaria conta) {
cout << "Conta: " << conta.numero << endl;;
cout << "Saldo: " << conta.saldo << endl << endl;

}