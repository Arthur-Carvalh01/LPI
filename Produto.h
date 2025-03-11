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
            getline(cin, nome);
            cout << "Descrição: ";
            getline(cin, descricao);
            cout << "Quantidade: ";
            cin >> quantidade;
            cout << "Preço: ";
            cin >> preco;
            cin.ignore();
        }
    
        virtual void ListarTodos() {
            cout << "\n=== PRODUTO ===" << endl;
            cout << "Nome: " << nome << endl;
            cout << "Descrição: " << descricao << endl;
            cout << "Quantidade: " << quantidade << endl;
            cout << "Preço: R$ " << preco << endl;
        }
    
        // Métodos estáticos para operações em listas de produtos
        static void AlterarPorNome(vector<Produto*>& listaProdutos) {
            string nomeBusca;
            cout << "\nDigite o nome do produto que deseja alterar: ";
            getline(cin, nomeBusca);
    
            bool encontrado = false;
            for (auto& produto : listaProdutos) {
                if (produto->getNome() == nomeBusca) {
                    encontrado = true;
                    cout << "\nProduto encontrado. Insira os novos dados:" << endl;
    
                    string novoNome, novaDescricao;
                    int novaQuantidade;
                    float novoPreco;
    
                    cout << "Novo nome: ";
                    getline(cin, novoNome);
                    cout << "Nova descrição: ";
                    getline(cin, novaDescricao);
                    cout << "Nova quantidade: ";
                    cin >> novaQuantidade;
                    cout << "Novo preço: ";
                    cin >> novoPreco;
                    cin.ignore(); // Limpa o buffer
    
                    produto->setNome(novoNome);
                    produto->setDescricao(novaDescricao);
                    produto->setQuantidade(novaQuantidade);
                    produto->setPreco(novoPreco);
    
                    cout << "\nProduto alterado com sucesso!" << endl;
                    break;
                }
            }
    
            if (!encontrado) {
                cout << "\nProduto não encontrado." << endl;
            }
        }
    
        static void RemoverPorNome(vector<Produto*>& listaProdutos) {
            string nomeBusca;
            cout << "\nDigite o nome do produto que deseja remover: ";
            getline(cin, nomeBusca);
    
            bool encontrado = false;
            for (auto it = listaProdutos.begin(); it != listaProdutos.end(); ++it) {
                if ((*it)->getNome() == nomeBusca) {
                    encontrado = true;
                    listaProdutos.erase(it); // Remove o produto da lista
                    cout << "\nProduto removido com sucesso!" << endl;
                    break;
                }
            }
    
            if (!encontrado) {
                cout << "\nProduto não encontrado." << endl;
            }
        }
    
        static void ExibirRelatorio(const vector<Produto*>& listaProdutos) {
            if (listaProdutos.empty()) {
                cout << "\nNenhum produto cadastrado." << endl;
                return;
            }
    
            cout << "\n=== RELATÓRIO DE PRODUTOS ===" << endl;
            float valorTotalEstoque = 0.0;
    
            for (const auto& produto : listaProdutos) {
                cout << "\nNome: " << produto->getNome() << endl;
                cout << "Descrição: " << produto->getDescricao() << endl;
                cout << "Quantidade: " << produto->getQuantidade() << endl;
                cout << "Preço: R$ " << produto->getPreco() << endl;
    
                // Calcula o valor total em estoque
                float valorProduto = produto->getQuantidade() * produto->getPreco();
                valorTotalEstoque += valorProduto;
            }
    
            cout << "\nVALOR TOTAL EM ESTOQUE: R$ " << valorTotalEstoque << endl;
        }
    };
    
#endif