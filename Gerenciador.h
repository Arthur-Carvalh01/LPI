#ifndef GERENCIADOR_H
#define GERENCIADOR_H

#include <vector>
#include "Computador.h"
#include "Notebook.h"

class Gerenciador {
    private:
        int resp;
        vector<Produto*> listaComputadores; // Agora é um vetor de ponteiros
        vector<Produto*> listaNotebooks;   // Agora é um vetor de ponteiros

public:
    Gerenciador() {
        resp = 0;
    }

    void menu() {
        while (true) {
            limparTerminal(); // Limpa o terminal antes de exibir o menu
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
                case 2:
                    gerenciarNotebooks();
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
            cout << "3 - Alterar Computador por Nome" << endl;
            cout << "4 - Remover Computador por Nome" << endl;
            cout << "5 - Exibir Relatório" << endl;
            cout << "6 - Voltar ao Menu Principal" << endl;
    
            cin >> opcao;
            cin.ignore(); // Limpa o buffer após leitura numérica
    
            switch (opcao) {
                case 1: {
                    Computador* pc = new Computador(); // Cria um novo Computador no heap
                    pc->Inserir();                   // Usa -> para acessar métodos
                    listaComputadores.push_back(pc); // Adiciona o ponteiro à lista
                    cout << "Computador adicionado com sucesso!" << endl;
                    break;
                }
                case 2:
                    cout << "\nLISTA DE COMPUTADORES: " << listaComputadores.size() << " cadastrados." << endl;
                    if (listaComputadores.empty()) {
                        cout << "Nenhum computador cadastrado." << endl;
                    } else {
                        for (size_t i = 0; i < listaComputadores.size(); i++) {
                            cout << "\nComputador " << i + 1 << ":" << endl;
                            listaComputadores[i]->ListarTodos(); // Usa -> para acessar métodos
                        }
                    }
                    break;
                case 3:
                    Produto::AlterarPorNome(listaComputadores);
                    break;
                case 4:
                    Produto::RemoverPorNome(listaComputadores);
                    break;
                case 5:
                    Produto::ExibirRelatorio(listaComputadores);
                    break;
                case 6:
                    return;
                default:
                    cout << "Opção inválida! Tente novamente." << endl;
                    break;
            }
        }
    }
    
    void gerenciarNotebooks() {
        int opcao;
        while (true) {
            cout << "\nGERENCIAR NOTEBOOKS" << endl;
            cout << "1 - Inserir Notebook" << endl;
            cout << "2 - Listar Notebooks" << endl;
            cout << "3 - Alterar Notebook por Nome" << endl;
            cout << "4 - Remover Notebook por Nome" << endl;
            cout << "5 - Exibir Relatório" << endl;
            cout << "6 - Voltar ao Menu Principal" << endl;
    
            cin >> opcao;
            cin.ignore(); // Limpa o buffer após leitura numérica
    
            switch (opcao) {
                case 1: {
                    Notebook* note = new Notebook(); // Cria um novo Notebook no heap
                    note->Inserir();               // Usa -> para acessar métodos
                    listaNotebooks.push_back(note); // Adiciona o ponteiro à lista
                    cout << "Notebook adicionado com sucesso!" << endl;
                    break;
                }
                case 2:
                    cout << "\nLISTA DE NOTEBOOKS: " << listaNotebooks.size() << " cadastrados." << endl;
                    if (listaNotebooks.empty()) {
                        cout << "Nenhum notebook cadastrado." << endl;
                    } else {
                        for (size_t i = 0; i < listaNotebooks.size(); i++) {
                            cout << "\nNotebook " << i + 1 << ":" << endl;
                            listaNotebooks[i]->ListarTodos(); // Usa -> para acessar métodos
                        }
                    }
                    break;
                case 3:
                    Produto::AlterarPorNome(listaNotebooks);
                    break;
                case 4:
                    Produto::RemoverPorNome(listaNotebooks);
                    break;
                case 5:
                    Produto::ExibirRelatorio(listaNotebooks);
                    break;
                case 6:
                    return;
                default:
                    cout << "Opção inválida! Tente novamente." << endl;
                    break;
            }
        }
    }

    void limparTerminal() {
        #ifdef _WIN32
            system("cls"); 
        #else
            system("clear"); 
        #endif
    }

    ~Gerenciador() {
        // Libera a memória alocada para computadores
        for (auto& pc : listaComputadores) {
            delete pc;
        }
        listaComputadores.clear();
    
        // Libera a memória alocada para notebooks
        for (auto& note : listaNotebooks) {
            delete note;
        }
        listaNotebooks.clear();
    }
};

#endif