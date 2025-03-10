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