#pragma once
#include <iostream>
#include <string> // Adicionado
#include <vector>  // Adicionado
#include "Conteudo.h"

class Serie : public Conteudo{
    private:
        int episodiosTotais;
        int temporadas;
    public:
        Serie();
        Serie(std::string titulo, std::string sinopse, std::string diretor, std::vector<std::string> elenco, 
              std::string genero, std::string subgenero, int anoLancamento, std::string classificacao, 
              float duracao, int episodiosTotais, int temporadas);
        void exibir() const override;
        int getTemporadas() const;
        int getEpisodiosTotais() const;

        void setTemporadas(int temporadas);
        void setEpisodiosTotais(int episodiosTotais);
};