#ifndef COMPUTADOR_H
#define COMPUTADOR_H

#include "Produto.h"

class Computador : public Produto {
public:
    Computador() : Produto() {}

    Computador(string n, string desc, int quant, float prec)
        : Produto(n, desc, quant, prec) {}

    void Inserir() override {
        cout << "\nINSERIR COMPUTADOR" << endl;
        Produto::Inserir();
    }

    void ListarTodos() override {
        cout << "\n=== COMPUTADOR ===" << endl;
        Produto::ListarTodos();
    }
};

#endif