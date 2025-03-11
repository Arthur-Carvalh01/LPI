#ifndef PRODUTO_H
#define PRODUTO_H

#include <string>
#include <iostream>
using namespace std;

class Produto {
protected:
    string nome, descricao;
    int quantidade;
    float preco;

public:
    Produto() {
        nome = "Desconhecido";
        descricao = "Sem descrição";
        quantidade = 0;
        preco = 0.0;
    }

    Produto(string n, string desc, int quant, float prec) {
        nome = n;
        descricao = desc;
        quantidade = quant;
        preco = prec;
    }

    string getNome() { return nome; }
    string getDescricao() { return descricao; }
    int getQuantidade() { return quantidade; }
    float getPreco() { return preco; }

    void setNome(string n) { nome = n; }
    void setDescricao(string d) { descricao = d; }
    void setQuantidade(int q) { quantidade = q; }
    void setPreco(float p) { preco = p; }

    virtual void Inserir() {
        cout << "\nINSERIR PRODUTO" << endl;
        cout << "Nome: ";
        getline(cin, nome); // Captura o nome completo
        cout << "Descrição: ";
        getline(cin, descricao);
        cout << "Quantidade: ";
        cin >> quantidade;
        cout << "Preço: ";
        cin >> preco;
        cin.ignore(); // Limpa o buffer após leituras numéricas
    }

    virtual void ListarTodos() {
        cout << "\n=== PRODUTO ===" << endl;
        cout << "Nome: " << nome << endl;
        cout << "Descrição: " << descricao << endl;
        cout << "Quantidade: " << quantidade << endl;
        cout << "Preço: R$ " << preco << endl;
    }
};

#endif