#pragma once

#include <iostream>
#include <vector>
#include "Conteudo.h"
#include "Playlist.h"


class Catalogo{
    private:
        std::vector<Conteudo*> conteudos;

    public:
        ~Catalogo();
        std::vector<Conteudo*> getConteudos() const;
        void adicionarConteudo(Conteudo* conteudo);
        Conteudo* buscarConteudoId(int id) const;
        std::vector<Conteudo*> buscarConteudosPorTitulo(const std::string& titulo) const;
        std::vector<Conteudo*> buscarConteudosPorGenero(const std::string& genero) const;
        void removerConteudo(int id);
};