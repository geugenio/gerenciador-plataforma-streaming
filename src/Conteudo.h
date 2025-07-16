#pragma once
#include <iostream>
#include <vector>
#include "Review.h"

class Conteudo{
    protected:
        int id;
        static int proxId;
        
        std::string titulo;
        std::string sinopse;
        std::string diretor;
        std::vector<std::string> elenco;
        std::string genero;
        std::string subgenero;
        int anoLancamento;
        std::string classificacao;
        float duracao;
        std::vector<Review*> reviews;

    public:
        // Construtores e destrutores
        Conteudo(std::string titulo, std::string sinopse, std::string diretor, std::vector<std::string> elenco, 
            std::string genero, std::string subgenero, int anoLancamento, std::string classificacao, float duracao);
        Conteudo() = default;

        //Destrutor default
        virtual ~Conteudo() = default;

        //Getters e Setters
        int getId() const;
        std::string getTitulo() const;
        std::string getGenero() const;
        int getAnoLancamento() const;
        const std::vector<Review*>& getReviews() const;

        // Métodos
        virtual void exibir() const;
        void addReview(Review* review);

};