#include "Conteudo.h"

Conteudo::Conteudo(int id, string titulo, string sinopse, string diretor, vector<string> elenco, string genero, 
    string subgenero, int anoLançamento, string classificacao, float duracao){
    this->id = id;
    this->titulo = titulo;
    this->sinopse = sinopse;
    this->diretor = diretor;
    this->elenco = elenco;
    this->genero = genero;
    this->subgenero = subgenero;
    this->anoLançamento = anoLançamento;
    this->classificacao = classificacao;
    this->duracao = duracao;
}

void Conteudo::exibir() const {
    cout << "ID: " << id << endl;
    cout << "Titulo: " << titulo << endl;
    cout << "Sinopse: " << sinopse << endl;
    cout << "Diretor: " << diretor << endl;
    cout << "Elenco: ";
    for (const string& ator : elenco) {
        cout << ator << ", ";
    }
    cout << endl;
    cout << "Genero: " << genero << endl;
    cout << "Subgenero: " << subgenero << endl;
    cout << "Ano de Lançamento: " << anoLançamento << endl;
    cout << "Classificacao: " << classificacao << endl;
    cout << "Duracao: " << duracao << " minutos" << endl;
}