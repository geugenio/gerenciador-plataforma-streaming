#include "User.h"
#include <iostream>

using namespace std;
int User::proxId = 1;

User::User(const string& nome, const string& email, const string& senha, Plano* planoAssinatura, bool isAdmin)
: id(proxId++), nome(nome), email(email), senha(senha), planoAssinatura(planoAssinatura), isAdmin(isAdmin){}

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
bool User::eAdmin() const {
    return isAdmin;
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

// MÉTODOS
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

bool User::autenticar(string e, string s)const{
    return email == e && senha == s;
}

void User::addReview(Review* review) {
    reviews.push_back(review);
}

const vector<Review*>& User::getReviews() const {
    return reviews;
}