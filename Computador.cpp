#pragma once
#include "Produto.cpp"

class Computador : public Produto {
    private:
        int quantidade;
    public:
        Computador(int qntd) {
            quantidade = qntd;
        }

        void MenuComputador(){
            cout << "1-pecas" << endl;
            cout << "2-pc's" << endl;
        }
};
