#include "funcionario.hpp"

string CompanyName, fileName;

Funcionario::Funcionario(){
}

Funcionario::~Funcionario(){

}

void Funcionario::setName(string name){
    this->name = name;
}
string Funcionario::getName(){
    return this->name;
}
void Funcionario::setSalary(double salary){
    this->salary = salary;
}
double Funcionario::getSalary(){
    return this->salary;
}
void Funcionario::setHiringDate(string hire){
    this->hiring = hire;
}
string Funcionario::getHiringDate(){
    return this->hiring;
}

Empresa::Empresa(){
    //input de nome de empresa para definir o DB
    cout << "Digite o nome da empresa em questao: ";
    cin >> CompanyName;
    fileName = CompanyName + ".csv";
}

Empresa::~Empresa(){

    cout << "Removendo dados de registro" << endl;   
    delete[] employee;
}

void Empresa::regCompany(){
    //input de cnpj da empresa juntamente com setting do nome da mesma
    string CompanyReg;
    cout << "Digite o CNPJ da empresa: ";
    cin >> CompanyReg;    
    this->setCompany(CompanyName);
    this->setRegister(CompanyReg);

    this->menu();
}

void Empresa::menu(){
        //menu de opcoes
        ofstream EmpBD(fileName, ios::app);
        cout << "-----------------------------" << endl;
        cout << "| Adicionar funcionarios - 1 |" << endl;
        cout << "----------------------------" << endl;
        cout << "|       Ler tabelas - 2      |" << endl;
        cout << "-----------------------------" << endl << endl;

        int option, quantity;
        cin >> option;

        if(option == 1){
        
            if(!EmpBD.is_open())
                cout << "Erro ao abrir arquivo!" << endl;

            //pedindo quantidade de funcionarios para input    
            cout << "Digite a quantidade de funcionarios: ";
            cin >> quantity;

            file_is_Empty(); //caso o arquivo esteja vazio, imprime categorias na primeira linha
            this->addEmployee(quantity); //cadastro de funcionarios
        }else{
            cout << "Leitura de tabelas || Not yet implemented**" << endl;
        }
}

void Empresa::addEmployee(int qnt){
    string name, hire, sal;
    ifstream dataEmp("funcionarios.txt", ios::in);

    this->employee = new Funcionario[qnt];
    
    for(int i = 0; i < qnt; i++){
        
        //cout << "Digite o nome do funcionario ["<< i+1 <<"]: ";
        getline(dataEmp, name, ' ');
        //cin >> name;
        employee[i].setName(name);
        //cout << "Digite o valor salariao do funcionario ["<< i+1 <<"]: ";
        getline(dataEmp, sal, ' ');
        //cin >> sal;
        employee[i].setSalary(stod(sal));
        //cout << "Digite a data de contratacao do funcionario ["<< i+1 <<"]: ";
        getline(dataEmp, hire, ' ');
        //cin >> hire;
        employee[i].setHiringDate(hire);

    }
    dataEmp.close();

    ofstream EmpBD(fileName, ios::app);

    if(!EmpBD.is_open()){
        cout << "Erro ao abrir arquivo!" << endl;
    }else{
        int j = 0;
        for(j; j < qnt; j++){
            //input de dados dos funcionarios no arquivo            
            EmpBD << employee[j].getName() << "," << employee[j].getSalary() << "," << employee[j].getHiringDate();
        }
        EmpBD << endl;
    }
    EmpBD.close();

}

void file_is_Empty(){ //input de categorias
     
        ifstream EmpBD(fileName, ios::in);
        string line;
        getline(EmpBD, line);

        if(EmpBD.eof()){
            ofstream EmpBD(fileName, ios::app);
            EmpBD <<"Nome   , Salario   , Data Contratacao    " << endl;
        }    
}
//setting de nome da empresa
void Empresa::setCompany(string nameComp){
    this->name = nameComp;
}
string Empresa::getCompany(){
    return this->name;
}
//setting de cnpj da empresa
void Empresa::setRegister(string reg){
    this->cnpj = reg;
}
string Empresa::getRegister(){
    return this->cnpj;
}