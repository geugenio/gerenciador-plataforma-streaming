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

template<typename T>
T* buscarPorId(const std::vector<T*>& container, int id) {
    for (T* elemento : container) {
        if (elemento->getId() == id) {
            return elemento;
        }
    }
    return nullptr;
}

template<typename T>
T* buscarPorId(const std::vector<std::unique_ptr<T>>& container, int id) {
    for (const auto& elemento : container) {
        if (elemento->getId() == id) {
            return elemento.get();
        }
    }
    return nullptr;
}

using namespace std;

extern int proximoConteudoId;

class Review;
class Playlist;
extern std::vector<std::unique_ptr<Review>> reviews;
extern std::vector<std::unique_ptr<Playlist>> playlists;

int lerNum(string msg);
int lerNumIntervalo(string msg, int min, int max);
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
