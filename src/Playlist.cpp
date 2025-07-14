#include "Playlist.h"
#include "Conteudo.h"
using namespace std;

int Playlist::proxId = 1;

Playlist::Playlist() {
    this->id = proxId++;
    this->nome = "";
    this->criador = nullptr;
}

Playlist::Playlist(string nome, User* criador) {
    this->id = proxId++;
    this->nome = nome;
    this->criador = criador;
}

void Playlist::adicionarConteudo(Conteudo* conteudo) {
    conteudos.push_back(conteudo);
}

void Playlist::removerConteudo(Conteudo* conteudo) {
    for (size_t i = 0; i < conteudos.size(); ++i) {
        if (conteudos[i] == conteudo) {
            conteudos.erase(conteudos.begin() + i);
            return;
        }
    }
    throw std::runtime_error("Conteudo nao foi encontrado dentro da playlist.");
}