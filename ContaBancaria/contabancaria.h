using namespace std;

typedef struct {int numero; float saldo;} ContaBancaria;

void Iniciar(ContaBancaria *, int, float);
void Depositar(ContaBancaria *, float);
void Sacar(ContaBancaria *, float);
void Imprimir(ContaBancaria);