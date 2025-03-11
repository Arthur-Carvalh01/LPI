#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "produto.cpp"

    using namespace std;

class Gerenciador{
				private :
				public:
						void menu(){
								cout << "BEM VINDO A TOURO TEC" << endl;
       	cout << "1-Computadores" << endl;
       	cout << "2-Notebooks" << endl;
       	cout << "3-Servicos" << endl;
       	cout << "4-Sair" << endl;
				}

						void menu_opcao(){
								cout << "1-Inserir" << endl;
								cout << "2-Listar Todos" << endl;
								cout << "3-Exibir Um" << endl;
								cout << "4-Alterar" << endl;
								cout << "5-Remover" << endl;
								cout << "6-Exibir Relatorio" << endl;
								cout << "7-Voltar" << endl;
								cout << "8-Sair" << endl;
				}
};