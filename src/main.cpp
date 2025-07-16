
#include <iostream>
#include "Catalogo.h"
#include "User.h"
#include "Playlist.h"
#include "Filme.h"
#include "Serie.h"
#include "Plano.h"
#include "Review.h"

#include <vector>
#include <limits>
#include <memory>
#include <string>
#include <algorithm>

using namespace std;
int proximoConteudoId = 1;

vector<unique_ptr<Review>> reviews;
vector<unique_ptr<Playlist>> playlists;

//prototipos das funções
void inicializarDados(Catalogo& catalogo, vector<unique_ptr<User>>& usuarios);
void menuInicial(Catalogo& catalogo, vector<unique_ptr<User>>& usuarios);
void menuUser(User& usuario, Catalogo& catalogo);
void menuAdmin(Catalogo& catalogo, vector<unique_ptr<User>>& usuarios);
void menuConteudo(Conteudo& conteudo, User& usuario);
User* autenticarUsuario(const vector<unique_ptr<User>>& usuarios);
void cadastrarUsuario(vector<unique_ptr<User>>& usuarios);
int lerNum(string msg);
int lerNumIntervalo(string msg, int min, int max);
string lerString(string msg);
