#include "Gerenciador.h"
#include <windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    Gerenciador sistema; // O construtor já carrega os dados
    sistema.menu();      // Inicia o menu principal
    return 0;
}