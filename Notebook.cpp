#pragma once
#include "Produto.cpp"

class Notebook : public Produto{
    private:
        int quantidade;
    public:
        Notebook(int qntd){
            quantidade = qntd;
        }

        void MenuNotebook(){
            
        }
};


