#ifndef GERENCIADOR_H
#define GERENCIADOR_H

#include <vector>
#include "Computador.h"

class Gerenciador {
private:
    int resp;
    vector<Computador> listaComputadores;

public:
    Gerenciador() {
        resp = 0;
    }

    void menu() {
        while (true) {
            cout << "\nBEM VINDO A TOURO TEC" << endl;
            cout << "1 - Computadores" << endl;
            cout << "2 - Notebooks" << endl;
            cout << "3 - Sair" << endl;

            cin >> resp;
            cin.ignore(); // Limpa o buffer após leitura numérica

            switch (resp) {
                case 1:
                    gerenciarComputadores();
                    break;
                case 3:
                    exit(0);
                default:
                    cout << "Opção inválida! Tente novamente." << endl;
                    break;
            }
        }
    }

    void gerenciarComputadores() {
        int opcao;
        while (true) {
            cout << "\nGERENCIAR COMPUTADORES" << endl;
            cout << "1 - Inserir Computador" << endl;
            cout << "2 - Listar Computadores" << endl;
            cout << "3 - Voltar ao Menu Principal" << endl;

            cin >> opcao;
            cin.ignore(); // Limpa o buffer após leitura numérica

            switch (opcao) {
                case 1: {
                    Computador pc;
                    pc.Inserir();
                    listaComputadores.push_back(pc);
                    cout << "Computador adicionado com sucesso!" << endl;
                    cout << "Total de computadores cadastrados: " << listaComputadores.size() << endl;
                    break;
                }
        
                case 2:
                    cout << "\nLISTA DE COMPUTADORES: " << listaComputadores.size() << " cadastrados." << endl;
                
                    if (listaComputadores.empty()) {
                        cout << "Nenhum computador cadastrado." << endl;
                    } else {
                        for (size_t i = 0; i < listaComputadores.size(); i++) {
                            cout << "\nComputador " << i + 1 << ":" << endl;
                            listaComputadores[i].ListarTodos();
                        }
                    }
                    break;
            
                case 3:
                    return;
                default:
                    cout << "Opção inválida! Tente novamente." << endl;
                    break;
            }
        }
    }
};

#endif