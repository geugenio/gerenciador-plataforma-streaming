#include "Catalogo.h"
#include <vector>

using namespace std;

void Catalogo::adicionarConteudo(Conteudo* conteudo) {
    conteudos.push_back(conteudo);
}

vector<Conteudo*> Catalogo:: buscarConteudosPorTitulo(const string& titulo) const{
    vector<Conteudo*> result;
    for(const auto& conteudo: conteudos){
        if(conteudo->getTitulo().find(titulo) != std::string::npos){
            result.push_back(conteudo);
        }
    }
    return result;
}

vector<Conteudo*> Catalogo::buscarConteudosPorGenero(const string& genero) const {
    vector<Conteudo*> resultado;
    for (const auto& conteudo : conteudos) {
        if (conteudo->getGenero() == genero) {
            resultado.push_back(conteudo);
        }
    }
    return resultado;
}



Conteudo* Catalogo::buscarConteudoId(int id) const {
    for (const auto& conteudo : conteudos) {
        if (conteudo->getId() == id) {
            return conteudo;
        }
    }
    return nullptr;
}