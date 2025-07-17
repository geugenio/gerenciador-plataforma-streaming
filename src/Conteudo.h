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
        void setTitulo(const std::string& titulo);
        void setSinopse(const std::string& sinopse);
        void setDiretor(const std::string& diretor);
        void setElenco(const std::vector<std::string>& elenco); // Pode ser mais complexo para editar um a um
        void setGenero(const std::string& genero);
        void setSubgenero(const std::string& subgenero);
        void setAnoLancamento(int anoLancamento);
        void setClassificacao(const std::string& classificacao);
        void setDuracao(float duracao);

        // Métodos
        virtual void exibir() const;
        void addReview(Review* review);
        void exibirReviews() const;

};
