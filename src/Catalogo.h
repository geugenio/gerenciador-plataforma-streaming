#include <iostream>
#include <vector>
#include "Conteudo.h"
#include "Playlist.h"

using namespace std;

class Catalogo{
    private:
        vector<Conteudo*> conteudos;
    public:
        void adicionarConteudo(Conteudo* conteudo);
        Conteudo* buscarConteudoId(int id) const;
        vector<Conteudo*> buscarConteudosPorTitulo(const string& titulo) const;
        vector<Conteudo*> buscarConteudosPorGenero(const string& genero) const;
        void removerConteudo(int id);
};