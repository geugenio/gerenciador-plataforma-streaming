#pragma once
#include <iostream>
#include "Plano.h"
#include <vector>
#include <memory>


class Conteudo;
class Review;
class Playlist;

class User{
    private:
        static int proxId; //id gerador automatico
        int id;
        std::string nome;
        std::string email;
        std::string senha;
        Plano* planoAssinatura;
        std::vector<Review*> reviews;
        std::vector<Playlist*> playlists;
        bool isAdmin = false;

    public:
        User(const std::string& nome, const std::string& email, const std::string& senha, Plano* planoAssinatura, bool isAdmin);
        User() = default;

        // Getter e Setter
        int getId() const;
        std::string getNome() const;
        std::string getEmail() const;
        std::string getSenha() const;
        Plano* getPlanoAssinatura() const;
        bool eAdmin() const;
        const std::vector<Review*>& getReviews() const;
        
        void setNome(const std::string& nome);
        void setEmail(const std::string& email);
        void setSenha(const std::string& senha);
        void setPlanoAssinatura(Plano* plano); 

        //Métodos
        void exibir() const;
        bool autenticar(std::string e, std::string s) const;
        void addReview(Review* review);
        void addPlaylist(Playlist* playlist);
        void removerPlaylistPorId(int idPlaylist);
        const std::vector<Playlist*>& getPlaylists() const;
        Review* buscarReviewPorConteudo(Conteudo* conteudo) const;
        User* autenticarUsuario(const std::vector<std::unique_ptr<User>>& usuarios);
        void cadastrarUsuario(std::vector<std::unique_ptr<User>>& usuarios);
};
