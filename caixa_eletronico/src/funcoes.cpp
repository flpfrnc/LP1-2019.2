#include <iostream>
#include <string.h>
#include "../include/funcoes.hpp"
#include <stdlib.h>
#include <chrono>
#include <iomanip>

using namespace std;


float moneyValue;
char autenticarArquivos[15];
float recebeDados[5];   
char recebeNome[30];  
int opc, verErro = 0;

void dadosConta(Cliente *cliente) {
    char rcvData[15];
    snprintf(rcvData, 15, "%d", cliente->cpf);
    strcat(rcvData, ".txt");
    FILE *arq = fopen(rcvData, "w");

    fprintf(arq,"%s\n %.2f\n %d\n %d\n %d\n %d", cliente->nome, cliente->saldo = 0.00, cliente->agencia, cliente->conta, cliente->senha, cliente->cpf);
    fclose(arq); 

    menuPrincipal();
}

Cliente criarConta(){

    Cliente cliente_cr;

    cout << "Digite o CPF: ";
    cin >> cliente_cr.cpf;
    cout << "Digite a senha: ";
    cin >> cliente_cr.senha;
    cout << "Digite o nome: ";
    fflush(stdin);
    cin >> cliente_cr.nome;

    srand(time(NULL));
    cliente_cr.agencia =  rand() % 998 + 1;
    cliente_cr.conta = rand() % 9998 + 1;   
   
    return cliente_cr;
}

void verificaDadosConta(){

    Cliente cliente_verf;
    cout << "Digite o CPF: ";
    cin >> cliente_verf.cpf;

    snprintf(autenticarArquivos, 15, "%d", cliente_verf.cpf);
    strcat(autenticarArquivos, ".txt");

    FILE *arq = fopen(autenticarArquivos, "r");

        if(arq == NULL){
            cout << "Conta nao encontrada!";
            cout << endl;
        }else{
            while(!feof(arq)){
                fscanf(arq, "%s %f %f %f %f %f", recebeNome, &recebeDados[0], &recebeDados[1], &recebeDados[2], &recebeDados[3], &recebeDados[4]);
            }

    system("clear");
    cout << endl;
    cout << endl;
    cout << recebeNome;
    cout << endl;
    cout << endl;
    cout << "Agencia / Conta" << endl;
    cout << endl;
    cout << recebeDados[1] << "   / " << recebeDados[2];;
    cout << endl;
    cout << endl;

    cout << "--------------------";
    cout << endl;
    cout << endl;
    cout << "Voltar - 0";
    cout << endl;

    cin >> opc;        
        if(opc == 0)
            menuPrincipal();

    fclose(arq);
        }

}

void menuPrincipal(){

    system("clear");
    cout << "---------------------------------Escolha o que deseja fazer---------------------------------";
    cout << endl;
    cout << endl;
    cout << "       | 1 | Login        | 2 | Criar Conta      | 3 | Verificar dados     | 9 | Sair";
    cout << endl;
    cout << endl;
    cout << "--------------------------------------------------------------------------------------------";
    cout << endl;
    cout << endl;

    cin >> opc;   
    if(opc == 1){
        Cliente cliente = acessarConta();
        menuOps(&cliente);
        }else
            if(opc == 2){
            Cliente cliente = criarConta();
            dadosConta(&cliente);
            }else
            if(opc == 3){
            verificaDadosConta();
            }else{
                system("break");
            }
}


void menuOps(Cliente *cliente){   //menu principal de escolha

    system("clear");
    cout << " --------- Escolha a operacao: ---------";
    cout << endl;
    cout << endl;
    cout << "1- Saldo";
    cout << endl;
    cout << endl;
    cout << "2- Deposito";
    cout << endl;
    cout << endl;
    cout << "3- Saque";
    cout << endl;
    cout << endl;
    cout << "4- Transferencia";
    cout << endl;
    cout << endl;
    cout << "9- Sair";
    cout << endl;
    cout << endl;



     cin >> opc;   
        if(opc == 1){
            verSaldo(cliente);
        }else
        if(opc == 2){
            Deposito(cliente);
        }else
        if(opc == 3){
            Saque(cliente);
        }else
        if(opc == 4){
            Transferencia(cliente);
        }else
        if(opc == 4){
            system("clear");
        }else{
            system("clear");
            inicio();
        }
}

void inicio(){           //funcao de inicializacao da conta

     menuPrincipal();
}


Cliente acessarConta(){  //acesso aos dados iniciais de login

    system("clear");
	printf("\n---------- Insira seus dados -----------\n\n\n");

    Cliente cliente, cliente_a;

    do{
        cout << "Digite o CPF: ";
        cin >> cliente.cpf;
    	cout << "Agencia ......: ";
    	cin >> cliente.agencia;
        cout << "Conta ......: ";
        cin >> cliente.conta;
    	cout << "Senha ......: ";
        cin >> cliente.senha;

        cliente_a = autenticarConta(&cliente);   //envio dos dados padrao para a struct cliente atraves
    }while(verErro <= 0);                   //do retorno da funcao autenticarConta();

    return cliente_a;
}

Cliente autenticarConta(Cliente *cliente){   //autenticacao das informacoes inseridas

    Cliente cliente_pd;

              //valor receberá saldo a ser enviado para o arquivo saldoconta.txt

    
    snprintf(autenticarArquivos, 15, "%d", cliente->cpf);
    strcat(autenticarArquivos, ".txt");
    FILE *arq = fopen(autenticarArquivos, "r");


    if(arq == NULL){
        cout << "Saldo nao encontrado";
        cout << endl;
        }else{
            while(!feof(arq)){
        fscanf(arq, "%s %f %f %f %f %f", recebeNome, &recebeDados[0], &recebeDados[1], &recebeDados[2], &recebeDados[3], &recebeDados[4]);
            }
        fclose(arq);
        }
    
    
    strcpy(cliente_pd.nome, recebeNome);
    cliente_pd.saldo = recebeDados[0];
    cliente_pd.agencia = recebeDados[1];
    cliente_pd.conta = recebeDados[2];
    cliente_pd.senha = recebeDados[3];    
    cliente_pd.cpf = recebeDados[4];
    


    if ((cliente->senha == cliente_pd.senha) && (cliente->conta == cliente_pd.conta)
    && (cliente->agencia == cliente_pd.agencia))
        {                                               //autenticação de dados
        verErro = 1;                                    //variavel de teste recebe 1 para autenticado
    return cliente_pd;
        }else{
            system("clear");
            cout << endl;
            cout << "-----------Dados Incorretos-----------";
            cout << endl;

            verErro = -1;                                   //...recebe -1 para erro de autenticacao.
        }
    return cliente_pd;
}

void verSaldo(Cliente* cliente){  //verificacao de saldo

    system("clear");
    cout << endl;
    cout <<"-----------------------------";
    cout << endl;
    cout <<"| Seu saldo atual e: R$" << cliente->saldo << endl;
    cout << endl;
    cout <<"-----------------------------";
    cout << endl;

    cout << endl;
    cout << "0- Voltar:";
    cout << endl;
    cout << endl;
    cout << "8- Logout:";
    cout << endl;
    cout << endl;
    cout << "9- Sair:";
    cout << endl;

    cin >> opc;
        if(opc == 0){
            system("clear");
            menuOps(cliente);
        }else
        if(opc == 8){
            system("clear");
            acessarConta();
        }else{
            system("break");
        }
}

void Deposito(Cliente* cliente){  //deposito + dados do mesmo inserido em arquivo "extrato"

    system("clear");
    cout << endl;
    cout << "Deposito--------------------";
    cout << endl;
    cout << "Digite a quantia: ";
    cout << endl;
    cin >> moneyValue;


    cliente->saldo += moneyValue; //o saldo recebe o valor de deposito inserido


    FILE *arq = fopen("extrato.txt","a");


    if(arq == NULL){
        cout << "Problema ao registrar deposito";
    }else{
        fprintf(arq,"Ag/conta: |   Cliente:");
        fprintf(arq,"\n%i/%i    |   %s\n+R$%.2f ~ Deposito\n", cliente->agencia, cliente->conta, cliente->nome, moneyValue);
        fprintf(arq,"Total = %.2f\n",cliente->saldo);
        fprintf(arq,"---------------\n");

        fclose(arq);
    }

    char rcvDataDepo[15];
    snprintf(rcvDataDepo, 15, "%d", cliente->cpf);
    strcat(rcvDataDepo, ".txt");
    FILE *arq2 = fopen(rcvDataDepo, "w");

    if(arq2 == NULL){
        cout << "Problema ao gravar saldo!";
    }else{

        fprintf(arq2,"%s\n %.2f\n %d\n %d\n %d\n %d", cliente->nome, cliente->saldo, cliente->agencia, cliente->conta, cliente->senha, cliente->cpf);
        fclose(arq2);
    }

    verSaldo(cliente);
}


void Saque(Cliente* cliente){  //saque + dados do mesmo inserido em arquivo "extrato"

    system("clear");
    cout << endl;
    cout << "Saque-----------------------";
    cout << endl;
    cout << "Digite a quantia: ";
    cout << endl;
    cin >> moneyValue;


    cliente->saldo -= moneyValue;

    FILE *arq = fopen("extrato.txt","a");

    

    if(arq == NULL){
        cout << "Problema ao registrar deposito";
    }else{
        fprintf(arq,"Ag/conta: |   Cliente:");
        fprintf(arq,"\n%i/%i    |   %s\n-R$%.2f ~ Saque\n", cliente->agencia, cliente->conta, cliente->nome, moneyValue);
        fprintf(arq,"Total = %.2f\n",cliente->saldo);
        fprintf(arq,"---------------\n");
        fclose(arq);
    }

    snprintf(autenticarArquivos, 15, "%d", cliente->cpf);
    strcat(autenticarArquivos, ".txt");
    FILE *arq2 = fopen(autenticarArquivos, "w");

    if(arq2 == NULL){
        cout << "Problema ao gravar saldo!";
    }else{

        fprintf(arq2,"%s\n %.2f\n %d\n %d\n %d\n %d", cliente->nome, cliente->saldo, cliente->agencia, cliente->conta, cliente->senha, cliente->cpf);
        fclose(arq2);
    }

    verSaldo(cliente);       //funcao versaldo é chamada sempre que uma operacao é executada
}

void Transferencia(Cliente* cliente){  //deposito + dados do mesmo inserido em arquivo "extrato"
    
    Cliente transfe;

    system("clear");
    cout << endl;
    cout << "Transferencia---------------";
    cout << endl;

    cout << endl;
    cout << "Digite o CPF de quem voce vai enviar: ";
    cin >> transfe.cpf;

    cout << endl;
    cout << "Digite a agencia: ";
    cin >> transfe.agencia;

    cout << endl;
    cout << "Digite a conta: ";
    cin >> transfe.conta;

    cout << endl;
    cout << "Digite a quantia: ";
    cin >> moneyValue;

    cliente->saldo -= moneyValue; //o saldo recebe o valor de deposito inserido

    transfe = autenticarConta(&transfe);

    snprintf(autenticarArquivos, 15, "%d", transfe.cpf);
    strcat(autenticarArquivos, ".txt");

    FILE *arq = fopen(autenticarArquivos, "w+");

        if(arq == NULL){
            cout << "Conta nao encontrada!";
            cout << endl;
        }else{
            fprintf(arq, "%s\n %.2f\n %i\n %.i\n %i\n %i", transfe.nome, transfe.saldo += moneyValue, transfe.agencia, transfe.conta, transfe.senha, transfe.cpf);    
            fclose(arq); 
        }

    FILE *arq2 = fopen("extrato.txt","a");


        if(arq2 == NULL){
            cout << "Problema ao registrar transferencia!";
            cout << endl;
        }else{
            fprintf(arq2,"Ag/conta: |   Cliente:");
            fprintf(arq2,"\n%i/%i    |   %s\n-R$%.2f ~ Transferencia\n", cliente->agencia, cliente->conta, cliente->nome, moneyValue);
            fprintf(arq2,"Total = %.2f\n",cliente->saldo);
            fprintf(arq2,"---------------\n");

            fclose(arq2);
            }


    snprintf(autenticarArquivos, 15, "%d", cliente->cpf);
    strcat(autenticarArquivos, ".txt");
    FILE *arq3 = fopen(autenticarArquivos, "w");

        if(arq3 == NULL){
            cout << "Problema ao gravar saldo!";
            cout << endl;
        }else{

        fprintf(arq3,"%s\n %.2f\n %d\n %d\n %d\n %d", cliente->nome, cliente->saldo, cliente->agencia, cliente->conta, cliente->senha, cliente->cpf);
        fclose(arq3);
        }

    verSaldo(cliente);
}

