#include "Catalogo.h"
#include <vector>
#include <algorithm> // std::remove_if

using namespace std;

Catalogo::~Catalogo() {
    for (Conteudo* c : conteudos) {
        delete c;
    }
}

void Catalogo::adicionarConteudo(Conteudo* conteudo) {
    conteudos.push_back(conteudo);
}

void Catalogo::removerConteudo(int id) {
    auto it = std::remove_if(conteudos.begin(), conteudos.end(), [id](const Conteudo* c) {
        if (c->getId() == id) {
            delete c;
            return true;
        }
        return false;
    });

    if (it != conteudos.end()) {
        conteudos.erase(it, conteudos.end());
        cout << "Conteudo removido com sucesso." << endl;
    } else {
        cout << "Conteudo com o ID especificado nao foi encontrado." << endl;
    }
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

vector<Conteudo*> Catalogo::getConteudos() const {
    return conteudos;
}