#pragma once
#include <iostream>
#include <vector>


class Conteudo{
    protected:
        int id;
        std::string titulo;
        std::string sinopse;
        std::string diretor;
        std::vector<std::string> elenco;
        std::string genero;
        std::string subgenero;
        int anoLancamento;
        std::string classificacao;
        float duracao;

    public:
        // Construtores e destrutores
        Conteudo(int id, std::string titulo, std::string sinopse, std::string diretor, std::vector<std::string> elenco, 
            std::string genero, std::string subgenero, int anoLancamento, std::string classificacao, float duracao);
        Conteudo() = default;

        //Destrutor default
        virtual ~Conteudo() = default;
        // Métodos
        virtual void exibir() const;

        //Getters e Setters
        int getId() const;
        std::string getTitulo() const;
        std::string getGenero() const;
        int getAnoLancamento() const;
};