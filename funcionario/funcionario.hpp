#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

class Funcionario{
    private:
    string name;
    double salary;
    string hiring;

    public:
    Funcionario();
    ~Funcionario();

    void setName(string name);
    string getName();
    void setSalary(double salary);
    double getSalary();
    void setHiringDate(string hire);
    string getHiringDate();
};

class Empresa{
    private:
    string name;
    string cnpj;
    Funcionario* employee;

    public:
    Empresa();
    ~Empresa();
    
    void menu();
    void regCompany();
    void addEmployee(int qnt);
    void setCompany(string reg);
    string getCompany();
    void setRegister(string register);
    string getRegister();
};

void file_is_Empty();
