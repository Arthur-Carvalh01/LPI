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
        cout << "BEM VINDO A TOURO TEC" << endl;
        cout << "1-Computadores" << endl;
        cout << "2-Notebooks" << endl;
        cout << "3-Servicos" << endl;
        cout << "4-Sair" << endl;
        
        cin >> resp;

        switch (resp) {
            case 1:
                comp.MenuComputador();
                break;
            case 2:
                note.MenuNotebook();
                break;
            case 3:
                serv.MenuServicos();
                break;
            case 4:
                return 0;  // Termina o programa
            default:
                cout << "Opcao invalida! Tente novamente." << endl;
        }
    }
}

/*

Para listar todos os produtos (sejam Notebooks, Computadores ou Serviços), podemos fazer o seguinte:

Criar um vetor de ponteiros (vector<Produto*>) que armazena diferentes tipos de produtos.
Usar polimorfismo para exibir a informação de cada produto chamando exibirInfo().

listagem dos produtos -------------------- ve isso ae
*/