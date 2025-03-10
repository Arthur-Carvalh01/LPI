#pragma once
#include <string>
#include <iostream>

using namespace std;

class Produto{
    private:
        string nome, descricao;
        int quantidade ;
        float preco;
        
    public:     // METODO CONSTRUTOR
        Produto(){

        }

        Produto(string n , string desc, int quant, float prec){
            quantidade = quant;
            nome = n;
            descricao = desc;
            preco = prec;
        }

		void Menu(){
			int resp;

			cout << "1-Inserir" << endl;
			cout << "2-Listar Todos" << endl;
			cout << "3-Exibir Um" << endl;
			cout << "4-Alterar" << endl;
			cout << "5-Remover" << endl;
			cout << "6-Exibir Relatorio" << endl;
			cout << "7-Voltar" << endl;
			cout << "8-Sair" << endl;
			cin >> resp;

		}

        void Inserir(){

        }
        
        void ListarTodos(){
            
        }
        
        void AlterarPorNome(){

        }

        void RemoverPorNome(){

        }

        void ExibirRelatorio(){
            
        }
};