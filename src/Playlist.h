#pragma once
#include <iostream>
#include <vector>
#include "Conteudo.h"
#include "User.h"


class Playlist{
    private:
    static int proxId;
        int id;
        string nome;
        User* criador;
        vector<Conteudo*> conteudos;
    public:
        Playlist();
        Playlist(string nome, User* criador);
        void adicionarConteudo(Conteudo* conteudo);
        void removerConteudo(Conteudo* conteudo);

};