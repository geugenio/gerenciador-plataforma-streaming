#pragma once
#include <iostream>
#include <vector>
#include "Conteudo.h"
#include "User.h"


class Playlist{
    private:
        static int proxId;
        int id;
        std::string nome;
        User* criador;
        std::vector<Conteudo*> conteudos;
    public:
        Playlist();
        Playlist(std::string nome, User* criador);
        void adicionarConteudo(Conteudo* conteudo);
        void removerConteudo(Conteudo* conteudo);

        string getNome() const;
        std::vector<Conteudo*> getConteudos() const;
        int getId() const;

};