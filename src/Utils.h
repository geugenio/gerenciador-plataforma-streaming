#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <memory>
#include <sstream>
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
void exibirMenuPlaylists();

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
void menuPlaylists(User& usuario, Catalogo& catalogo);

User* autenticarUsuario(const std::vector<std::unique_ptr<User>>& usuarios);
void cadastrarUsuario(std::vector<std::unique_ptr<User>>& usuarios);

//Funções template

template <typename T>
T lerValor(std::string msg) {
    T valor;
    std::string linha;
    while (true) {
        std::cout << msg << std::endl;
        std::getline(std::cin, linha);
        std::istringstream ss(linha);  // use istringstream aqui
        if (ss >> valor) {
            char c;
            if (!(ss >> c))  // garante que não tenha resto na string
                break;
        }
        std::cout << "Entrada inválida! Por favor, insira um valor válido." << std::endl;
    }
    return valor;
}

template <typename T>
T lerValorIntervalo(std::string msg, T min, T max) {
    T valor;
    while (true) {
        try {
            valor = lerValor<T>(msg);
            if (valor < min || valor > max) {
                throw std::runtime_error(
                    "Entrada invalida, o numero precisa estar no intervalo (" +
                    std::to_string(min) + " a " + std::to_string(max) + ")."
                );
            }
            return valor;
        } catch (const std::runtime_error &e) {
            std::cout << e.what() << std::endl;
        }
    }
}
