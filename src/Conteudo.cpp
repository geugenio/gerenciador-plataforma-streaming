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

void Conteudo::setTitulo(const std::string& titulo) {
    this->titulo = titulo;
}
void Conteudo::setSinopse(const std::string& sinopse) {
    this->sinopse = sinopse;
}
void Conteudo::setDiretor(const std::string& diretor) {
    this->diretor = diretor;
}
void Conteudo::setElenco(const std::vector<std::string>& elenco) {
    this->elenco = elenco; // Uma implementação mais robusta pode permitir adicionar/remover um por um.
}
void Conteudo::setGenero(const std::string& genero) {
    this->genero = genero;
}
void Conteudo::setSubgenero(const std::string& subgenero) {
    this->subgenero = subgenero;
}
void Conteudo::setAnoLancamento(int anoLancamento) {
    this->anoLancamento = anoLancamento;
}
void Conteudo::setClassificacao(const std::string& classificacao) {
    this->classificacao = classificacao;
}
void Conteudo::setDuracao(float duracao) {
    this->duracao = duracao;
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

void Conteudo::removerReview(Review* reviewToRemove) {
    auto it = std::remove(reviews.begin(), reviews.end(), reviewToRemove);
    if (it != reviews.end()) {
        reviews.erase(it, reviews.end());
    }
}
