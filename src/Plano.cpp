#include "Plano.h"
#include <iostream>
using namespace std;

Plano::Plano(const string& nome, double preco, const string& qualidadeMaxima, int dispositivos)
: nome(nome), preco(preco), qualidadeMaxima(qualidadeMaxima), dispositivos(dispositivos) {
    
}

const Plano& Plano::getSimples() {
    static Plano plano("Simples", 9.99, "SD", 1);
    return plano;
}

const Plano& Plano::getPadrao() {
    static Plano plano("Padrão", 19.99, "HD", 2);
    return plano;
}

const Plano& Plano::getPremium() {
    static Plano plano("Premium", 29.99, "4K", 4);
    return plano;
}

string Plano::getNome() const {
    return nome;
}
double Plano::getPreco() const { return preco; }
string Plano::getQualidadeMaxima() const { return qualidadeMaxima; }
int Plano::getDispositivos() const { return dispositivos; }

void Plano::exibir() const {
    cout << "Plano: " << nome
              << "\nPreço: R$" << preco
              << "\nQualidade Máxima: " << qualidadeMaxima
              << "\nDispositivos Simultâneos: " << dispositivos
              << "\n------------------------\n";
}