#include "Conteudo.h"
using namespace std;


Conteudo::Conteudo(int id, string titulo, string sinopse, string diretor, vector<string> elenco, string genero, 
    string subgenero, int anoLancamento, string classificacao, float duracao){
    this->id = id;
    this->titulo = titulo;
    this->sinopse = sinopse;
    this->diretor = diretor;
    this->elenco = elenco;
    this->genero = genero;
    this->subgenero = subgenero;
    this->anoLancamento = anoLancamento;
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
    cout << "Ano de Lançamento: " << anoLancamento << endl;
    cout << "Classificacao: " << classificacao << endl;
    cout << "Duracao: " << duracao << " minutos" << endl;
}


string Conteudo::getTitulo() const{
    return titulo;
}

int Conteudo::getId() const{
    return id;
}

string Conteudo::getGenero() const{
    return genero;
}
int Conteudo::getAnoLancamento() const {
    return anoLancamento;
}