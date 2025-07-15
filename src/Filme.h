#pragma once
#include <iostream>
#include "Conteudo.h"

using namespace std;

class Filme : public Conteudo{
    private:
        string premiacoes;
    public:
        Filme();
        Filme(int id, string titulo, string sinopse, string diretor, vector<string> elenco, 
              string genero, string subgenero, int anoLancamento, string classificacao, 
              float duracao, string premiacoes);
        void exibir() const override;
        
        string getPremiacoes() const;
        void setPremiacoes(string premiacoes);
};