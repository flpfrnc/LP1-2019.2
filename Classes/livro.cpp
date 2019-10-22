#include "livro.hpp"

struct livro{
    string author;
    string title;
    int pages;
};

Livro* set_Author(string author, string title, int pages){
    Livro* livro = new Livro();
    livro->author = author;
    livro->title = title;
    livro->pages = pages;

    return livro;
}

int get_Pages(Livro* livro){

    return livro->pages;
}

string get_Title(Livro* livro){
    
    return livro->title;
}