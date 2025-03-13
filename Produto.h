#ifndef PRODUTO_H
#define PRODUTO_H

#include <string>
#include <iostream>
#include <vector>
#include "Fornecedor.h"
using namespace std;

class Produto {
protected:
    string nome, descricao;
    int quantidade;
    float preco;
    Fornecedor fornecedor; // Composição

public:
    Produto() : nome("Desconhecido"), descricao("Sem descrição"), quantidade(0), preco(0.0), fornecedor() {}
    Produto(string n, string desc, int quant, float prec, Fornecedor forn)
        : nome(n), descricao(desc), quantidade(quant), preco(prec), fornecedor(forn) {}

    virtual ~Produto() {}

    string getNome() { return nome; }
    string getDescricao() { return descricao; }
    int getQuantidade() { return quantidade; }
    float getPreco() { return preco; }
    Fornecedor getFornecedor() { return fornecedor; }

    void setNome(string n) { nome = n; }
    void setDescricao(string d) { descricao = d; }
    void setQuantidade(int q) { quantidade = q; }
    void setPreco(float p) { preco = p; }
    void setFornecedor(Fornecedor forn) { fornecedor = forn; }

    virtual void Inserir() {
        cout << "\nINSERIR PRODUTO" << endl;
        cout << "Nome: ";
        getline(cin, nome);
        cout << "Descrição: ";
        getline(cin, descricao);
        cout << "Quantidade: ";
        cin >> quantidade;
        cout << "Preço: ";
        cin >> preco;
        cin.ignore();

        string nomeFornecedor, contatoFornecedor;
        cout << "Nome do Fornecedor: ";
        getline(cin, nomeFornecedor);
        cout << "Contato do Fornecedor: ";
        getline(cin, contatoFornecedor);
        fornecedor = Fornecedor(nomeFornecedor, contatoFornecedor);
    }

    virtual void ListarTodos() {
        cout << endl;
        cout << "Nome: " << nome << endl;
    }

    static int Pesquisar(const vector<Produto*>& lista, const string& nome) {
        for (size_t i = 0; i < lista.size(); i++) {
            if (lista[i]->getNome() == nome) {
                return i; // Retorna o índice do objeto encontrado
            }
        }
        return -1; // Retorna -1 se não encontrar
    }

    static void ExibirRelatorio(const vector<Produto*>& lista) {
        if (lista.empty()) {
            cout << "\nNenhum produto cadastrado." << endl;
            return;
        }
    
        cout << "\n=== RELATÓRIO DE PRODUTOS ===" << endl;
        float valorTotalEstoque = 0.0;
    
        for (const auto& produto : lista) {
            cout << endl;
            cout << "Nome: " << produto->getNome() << endl; // Acessando o nome do produto
            cout << "Descrição: " << produto->getDescricao() << endl; // Acessando a descrição
            cout << "Quantidade: " << produto->getQuantidade() << endl; // Acessando a quantidade
            cout << "Preço: R$ " << produto->getPreco() << endl; // Acessando o preço
            cout << "Fornecedor: " << produto->getFornecedor().getNome() << " (" 
                 << produto->getFornecedor().getContato() << ")" << endl; // Acessando o fornecedor
    
            // Calcula o valor total do produto em estoque
            float valorProduto = produto->getQuantidade() * produto->getPreco();
            valorTotalEstoque += valorProduto;
        }
    
        cout << "\nVALOR TOTAL EM ESTOQUE: R$ " << valorTotalEstoque << endl;
    }
};

#endif