#pragma once
#include <iostream>
#include <vector>

class User;
class Conteudo;


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
        void setNome(const std::string& novoNome);

        std::string getNome() const;
        std::vector<Conteudo*> getConteudos() const;
        User* getCriador() const;
        int getId() const;

};
