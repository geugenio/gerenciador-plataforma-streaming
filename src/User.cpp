#include "User.h"
#include <iostream>

using namespace std;

User::User(int id, const string& nome, const string& email, const string& senha, Plano* planoAssinatura)
: id(id), nome(nome), email(email), senha(senha), planoAssinatura(planoAssinatura) {}

// Getters
int User::getId() const {
    return id;
}

string User::getNome() const {
    return nome;
}

string User::getEmail() const {
    return email;
}

string User::getSenha() const {
    return senha;
}

Plano* User::getPlanoAssinatura() const {
    return planoAssinatura;
}

// Setters
void User::setNome(const string& nome) {
    this-> nome = nome;
}

void User::setEmail(const string& email) {
    this-> email = email;
}

void User::setSenha(const string& senha) {
    this-> senha = senha;;
}

void User::setPlanoAssinatura(Plano* plano) {
    this-> planoAssinatura = plano;
}

// Método exibir
void User::exibir() const {
    cout << "ID: " << id << endl;
    cout << "Nome: " << nome << endl;
    cout << "Email: " << email << endl;
    if (planoAssinatura) {
        cout << "Plano: ";
        planoAssinatura->exibir();
    } else {
        cout << "Plano: Nenhum" << endl;
    }
}