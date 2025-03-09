#pragma once
#include <string>
#include <iostream>

using namespace std;

class Produto{
    private:
        string nome, descricao;
        
    public:     // METODO CONSTRUTOR
        Produto(){

        }

        Produto(string n , string desc){
            nome = n;
            descricao = desc;
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