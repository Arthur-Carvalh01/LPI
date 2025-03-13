#ifndef FORNECEDOR_H
#define FORNECEDOR_H

#include <string>
using namespace std;

class Fornecedor {
private:
    string nome;
    string contato;

public:
    Fornecedor() : nome("Desconhecido"), contato("Sem contato") {}
    Fornecedor(string n, string c) : nome(n), contato(c) {}

    string getNome() { return nome; }
    string getContato() { return contato; }

    void setNome(string n) { nome = n; }
    void setContato(string c) { contato = c; }
};

#endif