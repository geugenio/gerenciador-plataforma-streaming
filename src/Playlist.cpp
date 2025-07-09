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

void Playlist::removerConteudo(Conteudo* conteudo){
    auto it = find(conteudos.begin(), conteudos.end(), conteudo);
    if (it != conteudos.end()) {
        // Conteudo encontrado, removendo da playlist
        conteudos.erase(it);
    } else {
        throw runtime_error("Conteudo nao encontrado na playlist.");
    }
}