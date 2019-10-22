#include <iostream>
#include <cstring>

using namespace std;

typedef struct livro Livro;

Livro* set_Author(string author, string title, int pages);

int get_Pages(Livro* livro);

string get_Title(Livro* livro);