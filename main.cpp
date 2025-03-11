#include <iostream>
#include "Produto.cpp"
#include "Computador.cpp"
#include "Notebook.cpp"
#include "Servico.cpp"

using namespace std;

int main() {
    Produto prod;
    Computador comp(10);  // Exemplo: 10 unidades
    Notebook note(5);      // Exemplo: 5 unidades
    Servico serv;
    int resp = 0;

    while (true) {
        
        }
    }
}

/*

Para listar todos os produtos (sejam Notebooks, Computadores ou Serviços), podemos fazer o seguinte:

Criar um vetor de ponteiros (vector<Produto*>) que armazena diferentes tipos de produtos.
Usar polimorfismo para exibir a informação de cada produto chamando exibirInfo().

listagem dos produtos -------------------- ve isso ae
*/