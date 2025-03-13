#ifndef GERENCIADOR_H
#define GERENCIADOR_H

#include <vector>
#include <fstream>
#include <limits>
#include "Computador.h"
#include "Notebook.h"
using namespace std;

class Gerenciador {
private:
    int resp;
    vector<Produto*> listaProdutos; // Lista única para todos os produtos

    // Função para limpar o terminal
    void limparTerminal() {
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
    }

    // Função para validar entradas numéricas
    int lerInteiro(const string& mensagem) {
        int valor;
        while (true) {
            cout << mensagem;
            cin >> valor;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Entrada inválida! Digite um número." << endl;
            } else {
                cin.ignore();
                return valor;
            }
        }
    }

    // Função para salvar dados em arquivo
    void salvarDados() {
        ofstream arquivo("produtos.txt");

        for (const auto& produto : listaProdutos) {
            if (dynamic_cast<Computador*>(produto)) {
                arquivo << "Computador" << endl;
            } else if (dynamic_cast<Notebook*>(produto)) {
                arquivo << "Notebook" << endl;
            }
            arquivo << produto->getNome() << endl;
            arquivo << produto->getDescricao() << endl;
            arquivo << produto->getQuantidade() << endl;
            arquivo << produto->getPreco() << endl;
            arquivo << produto->getFornecedor().getNome() << endl;
            arquivo << produto->getFornecedor().getContato() << endl;
        }

        arquivo.close();
    }

    // Função para carregar dados de arquivo
    void carregarDados() {
        ifstream arquivo("produtos.txt");
    
        string tipo, nome, descricao, nomeFornecedor, contatoFornecedor;
        int quantidade;
        float preco;
    
        while (getline(arquivo, tipo)) {
            getline(arquivo, nome);
            getline(arquivo, descricao);
            arquivo >> quantidade;
            arquivo >> preco;
            arquivo.ignore();
            getline(arquivo, nomeFornecedor);
            getline(arquivo, contatoFornecedor);
    
            Fornecedor fornecedor(nomeFornecedor, contatoFornecedor);
    
            if (tipo == "Computador") {
                listaProdutos.push_back(new Computador(nome, descricao, quantidade, preco, fornecedor));
            } else if (tipo == "Notebook") {
                listaProdutos.push_back(new Notebook(nome, descricao, quantidade, preco, fornecedor));
            }
        }
    
        arquivo.close();
    }

    // Função para exibir um produto por nome
    void exibirPorNome(const string& nome) {
        int indice = Produto::Pesquisar(listaProdutos, nome);
        if (indice != -1) {
            listaProdutos[indice]->ListarTodos();
        } else {
            cout << "\nProduto não encontrado." << endl;
        }
    }

    // Função para alterar um produto por nome
    void alterarPorNome(const string& nome) {
        int indice = Produto::Pesquisar(listaProdutos, nome);
        if (indice != -1) {
            cout << "\nProduto encontrado. Insira os novos dados:" << endl;
            listaProdutos[indice]->Inserir();
            cout << "\nProduto alterado com sucesso!" << endl;
        } else {
            cout << "\nProduto não encontrado." << endl;
        }
    }

    // Função para remover um produto por nome
    void removerPorNome(const string& nome) {
        int indice = Produto::Pesquisar(listaProdutos, nome);
        if (indice != -1) {
            delete listaProdutos[indice];
            listaProdutos.erase(listaProdutos.begin() + indice);
            cout << "\nProduto removido com sucesso!" << endl;
        } else {
            cout << "\nProduto não encontrado." << endl;
        }
    }

public:
    Gerenciador() {
        resp = 0;
        carregarDados();
    }

    ~Gerenciador() {
        for (auto& produto : listaProdutos) delete produto;
    }

    void menu() {
        while (true) {
            cout << "\nBEM VINDO A TOURO TEC" << endl;
            cout << "1 - Inserir Produto" << endl;
            cout << "2 - Listar Todos os Produtos" << endl;
            cout << "3 - Exibir Produto por Nome" << endl;
            cout << "4 - Alterar Produto por Nome" << endl;
            cout << "5 - Remover Produto por Nome" << endl;
            cout << "6 - Exibir Relatório" << endl;
            cout << "7 - Sair" << endl;

            resp = lerInteiro("Escolha uma opção: ");

            switch (resp) {
                case 1: {
                    int tipo;
                    cout << "\nEscolha o tipo de produto:" << endl;
                    cout << "1 - Computador" << endl;
                    cout << "2 - Notebook" << endl;
                    tipo = lerInteiro("Opção: ");

                    Produto* produto = nullptr;
                    if (tipo == 1) {
                        produto = new Computador();
                    } else if (tipo == 2) {
                        produto = new Notebook();
                    } else {
                        cout << "Opção inválida!" << endl;
                        break;
                    }

                    produto->Inserir();
                    listaProdutos.push_back(produto);
                    cout << "Produto adicionado com sucesso!" << endl;
                    break;
                }
                case 2:
                    for (const auto& produto : listaProdutos) {
                        produto->ListarTodos();
                    }
                    break;
                case 3: {
                    string nome;
                    cout << "\nDigite o nome do produto: ";
                    getline(cin, nome);
                    exibirPorNome(nome);
                    break;
                }
                case 4: {
                    string nome;
                    cout << "\nDigite o nome do produto: ";
                    getline(cin, nome);
                    alterarPorNome(nome);
                    break;
                }
                case 5: {
                    string nome;
                    cout << "\nDigite o nome do produto: ";
                    getline(cin, nome);
                    removerPorNome(nome);
                    break;
                }
                case 6:
                    Produto::ExibirRelatorio(listaProdutos);
                    break;
                case 7:
                    salvarDados();
                    exit(0);
                default:
                    cout << "Opção inválida! Tente novamente." << endl;
                    break;
            }
        }
    }
};

#endif