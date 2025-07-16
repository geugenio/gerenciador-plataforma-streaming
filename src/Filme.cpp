#include "Filme.h"


Filme::Filme() : Conteudo() {
    this->premiacoes = "";
}

Filme::Filme(string titulo, string sinopse, string diretor, vector<string> elenco, 
             string genero, string subgenero, int anoLancamento, string classificacao, 
             float duracao, string premiacoes) : Conteudo(titulo, sinopse, diretor, elenco, 
             genero, subgenero, anoLancamento, classificacao, duracao) {
    this->premiacoes = premiacoes;
}


void Filme::exibir() const {
    Conteudo::exibir();
    cout << "Premiacoes: " << premiacoes << endl;
}

//Getters e Setters
string Filme::getPremiacoes() const {
    return premiacoes;
}
void Filme::setPremiacoes(string premiacoes) {
    this->premiacoes = premiacoes;
}
