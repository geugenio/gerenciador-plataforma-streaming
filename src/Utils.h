#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <memory>

#include "Catalogo.h"
#include "User.h"
#include "Plano.h"
#include "Filme.h"
#include "Serie.h"
#include "Review.h"

using namespace std;

extern int proximoConteudoId;

class Review;
class Playlist;
extern std::vector<std::unique_ptr<Review>> reviews;
extern std::vector<std::unique_ptr<Playlist>> playlists;
string lerString(string msg);

// funções de exibição do menu
void exibirMenuLogin();
void exibirMenuConteudoUsuario();
void exibirMenuConteudoAdmin();
void exibirMenuDetalhesConteudo();

// funções de inicialização e gerenciamento
void inicializarDados(Catalogo& catalogo, vector<unique_ptr<User>>& usuarios);
void exibirTodosConteudos(const Catalogo& catalogo);
void editarPerfilUsuario(User& usuario);
void atualizarDetalhesConteudo(Conteudo* conteudo);

// funções de navegação do menu 
void menuInicial(Catalogo& catalogo, vector<unique_ptr<User>>& usuarios);
void menuUser(User& usuario, Catalogo& catalogo);
void menuAdmin(Catalogo& catalogo, vector<unique_ptr<User>>& usuarios);
void menuConteudo(Conteudo& conteudo, User& usuario);

User* autenticarUsuario(const std::vector<std::unique_ptr<User>>& usuarios);
void cadastrarUsuario(std::vector<std::unique_ptr<User>>& usuarios);

//Funções template

template <typename T>
T lerValor(string msg) {
    T valor;
    string linha;
    while (true) {
        cout << msg << endl;
        getline(cin, linha);
        stringstream ss(linha);
        if (ss >> valor) {
            char c;
            if (!(ss >> c))  // garante que não tenha resto na string
                break;
        }
        cout << "Entrada inválida! Por favor, insira um valor válido." << endl;
    }
    return valor;
}

template <typename T>
T lerValorIntervalo(string msg, T min, T max) {
    T valor;
    while (true) {
        try {
            valor = lerValor<T>(msg);
            if (valor < min || valor > max) {
                throw runtime_error(
                    "Entrada invalida, o numero precisa estar no intervalo (" +
                    to_string(min) + " a " + to_string(max) + ")."
                );
            }
            return valor;
        } catch (const runtime_error &e) {
            cout << e.what() << endl;
        }
    }
}
