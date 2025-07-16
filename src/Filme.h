#pragma once
#include <iostream>
#include <string> 
#include <vector> 
#include "Conteudo.h"

class Filme : public Conteudo{
    private:
        std::string premiacoes;
    public:
        Filme();
        Filme(std::string titulo, std::string sinopse, std::string diretor, std::vector<std::string> elenco, 
              std::string genero, std::string subgenero, int anoLancamento, std::string classificacao, 
              float duracao, std::string premiacoes);
        void exibir() const override;
        
        std::string getPremiacoes() const;
        void setPremiacoes(std::string premiacoes);
};
