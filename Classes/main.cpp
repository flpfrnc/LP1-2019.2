#include "carro.hpp"
#include "livro.hpp"

int main(int argc, char const *argv[])
{
    Carro c;
        c.setDoors(4);
        c.setColor("Vermelho");
        c.setPlate("FFF7F34");
        c.setSpeed(100);

        cout << "Portas: " << c.getDoors() << endl;
        cout << "Cor: " << c.getColor() << endl;
        cout << "Placa: " << c.getPlate() << endl;
        cout << "Velocidade: " << c.getSpeed() << endl;

        c.accel(25);
        cout << "Velocidade apos aceleracao: " << c.getSpeed() << endl;
        c.brake(10);
        cout << "Velocidade apos frenagem: " << c.getSpeed() << endl;
    
    cout <<"----Class Carro----end"<< endl << endl << "-----TAD Livro----begin"<< endl;

    Livro* livro1 = set_Author("Felipe Franca", "How to deal with lack of attention", 57);
    Livro* livro2 = set_Author("Samuel Oliveira", "Linguagem de Progrmacao", 262);
        
        cout << "Livro com " << get_Pages(livro1) << " paginas." << endl;
        cout << "Titulo: " << get_Title(livro1) << endl;
        cout << "Livro com " << get_Pages(livro2) << " paginas." << endl;
        cout << "Titulo: " << get_Title(livro2) << endl;


    return 0;
}