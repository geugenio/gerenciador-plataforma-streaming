#include "Conteudo.h"
#include <vector>
using namespace std;
int Conteudo::proxId = 1;


Conteudo::Conteudo(string titulo, string sinopse, string diretor, vector<string> elenco, string genero, 
    string subgenero, int anoLancamento, string classificacao, float duracao)
    : id(proxId++), titulo(titulo), sinopse(sinopse), diretor(diretor), elenco(elenco),
      genero(genero), subgenero(subgenero), anoLancamento(anoLancamento),
      classificacao(classificacao), duracao(duracao)
{
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
    cout << "Numeros de reviews: " << reviews.size() << endl;
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

void Conteudo::addReview(Review* review) {
    reviews.push_back(review);
}

const std::vector<Review*>& Conteudo::getReviews() const {
    return reviews;
}
void Conteudo::exibirReviews() const{
    if(reviews.empty()){
        cout << "Nenhuma review cadastrada para este conteudo." << endl;
        return;
    }
    cout << "====| Reviews de " << titulo << "|===="<<endl;
    for (const auto& review : reviews){
        review->exibirDetalhes();
        cout << "--------------------------" << endl;
    }
}