#ifndef __FUNCOES_H__
#define __FUNCOES_H__

//*Criacao da struct contendo os dados da conta

typedef struct Cliente
  {
    int conta;
    int agencia;
    int senha;
    int cpf;
    char nome[30];
    float saldo;
  } Cliente;

void dadosConta(Cliente* cliente);
Cliente criarConta();
void verificaDadosConta();
void menuPrincipal();
void menuOps(Cliente* cliente);
void inicio();
Cliente acessarConta();
Cliente autenticarConta(Cliente* cliente);
void verSaldo(Cliente* cliente);
void Deposito(Cliente* cliente);
void Saque(Cliente* cliente);
void Transferencia(Cliente* cliente);


#endif // FUNCOES_H
