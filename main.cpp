#include <iostream>
#include <fstream>
#include <string>
#include "Gerenciador.cpp"

using namespace std;

Gerenciador gerenciar;
int main() {
    gerenciar.menu_opcao();


}


/*

Para listar todos os produtos (sejam Notebooks, Computadores ou Serviços), podemos fazer o seguinte:

Criar um vetor de ponteiros (vector<Produto*>) que armazena diferentes tipos de produtos.
Usar polimorfismo para exibir a informação de cada produto chamando exibirInfo().

listagem dos produtos -------------------- ve isso ae
*/