#pragma once
#include <iostream>

#include "Plano.h"

class User{
    private:
        int id;
        std::string nome;
        std::string email;
        std::string senha;
        Plano* planoAssinatura;
        bool isAdmin = false;
    public:
        User(int id, const std::string& nome, const std::string& email, const std::string& senha, Plano* planoAssinatura, bool isAdmin);
        User() = default;

        // Getter e Setter
        int getId() const;
        std::string getNome() const;
        std::string getEmail() const;
        std::string getSenha() const;
        Plano* getPlanoAssinatura() const;
        bool eAdmin() const;

        void setNome(const std::string& nome);
        void setEmail(const std::string& email);
        void setSenha(const std::string& senha);
        void setPlanoAssinatura(Plano* plano);

        //Métodos
        void exibir() const;
        bool autenticar(string e, string s) const;
        
};