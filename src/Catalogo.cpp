#include "Catalogo.h"


void Catalogo::adicionarConteudo(Conteudo* conteudo) {
    conteudos.push_back(conteudo);
}

Conteudo* Catalogo::buscarConteudoId(int id) const {
    for (const auto& conteudo : conteudos) {
        if (conteudo->buscarConteudoId(id)) {
            return conteudo;
        }
    }
    return nullptr;
}