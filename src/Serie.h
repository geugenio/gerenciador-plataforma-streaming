#pragma once
#include <iostream>
#include "Conteudo.h"

using namespace std;

class Serie : public Conteudo{
    private:
        int episodiosTotais;
        int temporadas;
    public:
        Serie();
        Serie(int id, string titulo, string sinopse, string diretor, vector<string> elenco, 
              string genero, string subgenero, int anoLancamento, string classificacao, 
              float duracao, int episodiosTotais, int temporadas);
        void exibir() const override;
        Serie *buscarConteudoId(int id) const override;
};