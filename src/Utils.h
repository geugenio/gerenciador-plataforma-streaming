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

// funções de navegação do menu 
void menuInicial(Catalogo& catalogo, vector<unique_ptr<User>>& usuarios);
void menuUser(User& usuario, Catalogo& catalogo);
void menuAdmin(Catalogo& catalogo, vector<unique_ptr<User>>& usuarios);
void menuConteudo(Conteudo& conteudo, User& usuario);
