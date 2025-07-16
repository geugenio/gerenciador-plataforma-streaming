
#include "Serie.h"
using namespace std;

//Construtor

Serie::Serie(string titulo, string sinopse, string diretor, vector<string> elenco, 
             string genero, string subgenero, int anoLancamento, string classificacao, 
             float duracao, int episodiosTotais, int temporadas) : Conteudo(titulo, sinopse, diretor, elenco, 
             genero, subgenero, anoLancamento, classificacao, duracao), episodiosTotais(episodiosTotais), temporadas(temporadas){
}

//Getters e Setters

int Serie::getTemporadas() const{
    return temporadas;
}
int Serie::getEpisodiosTotais() const{
    return episodiosTotais;
}
void Serie::setTemporadas(int temporadas){
    this->temporadas = temporadas;
}
void Serie::setEpisodiosTotais(int episodiosTotais){
    this->episodiosTotais  = episodiosTotais;
}

//Métodos

void Serie::exibir() const {
    Conteudo::exibir();
    cout << "Episodios Totais: " << episodiosTotais << endl;
    cout << "Temporadas: " << temporadas << endl;
}
