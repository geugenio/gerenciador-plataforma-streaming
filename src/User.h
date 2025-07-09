#pragma once
#include <iostream>
#include <chrono>

#include "Plano.h"

using namespace std;

class User{
    private:
        int id;
        string nome;
        string email;
        string senha;
        Plano* planoAssinatura;
    public:
        User(int id, string nome, string email, string senha, Plano* planoAssinatura);
        User();

        // Getter e Setter
        int getId() const;
        string getNome() const;
        string getEmail() const;
        string getSenha() const;
        Plano* getPlanoAssinatura() const;

        void setNome(string nome);
        void setEmail(string email);
        void setSenha(string senha);
        void setPlanoAssinatura(Plano* plano);

        //Métodos
        void exibir() const;
};