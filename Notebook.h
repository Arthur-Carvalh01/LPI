#ifndef NOTEBOOK_H
#define NOTEBOOK_H

#include "Produto.h"

class Notebook : public Produto {
public:
    Notebook() : Produto() {}

    Notebook(string n, string desc, int quant, float prec, Fornecedor forn)
        : Produto(n, desc, quant, prec, forn) {}

    void Inserir() override {
        cout << "\nINSERIR NOTEBOOK" << endl;
        Produto::Inserir();
    }

    void ListarTodos() override {
        cout << "\n=== NOTEBOOK ===" << endl;
        Produto::ListarTodos();
    }
};

#endif