#pragma once
#include <iostream>
#include <vector>

using namespace std;


class Conteudo{
    protected:
        int id;
        string titulo;
        string sinopse;
        string diretor;
        vector<string> elenco;
        string genero;
        string subgenero;
        int anoLançamento;
        string classificacao;
        float duracao;

    public:
        // Construtores e destrutores
        Conteudo(int id, string titulo, string sinopse, string diretor, vector<string> elenco, 
            string genero, string subgenero, int anoLançamento, string classificacao, float duracao);
        Conteudo();

        //Destrutor default
        virtual ~Conteudo() = default;
        // Métodos
        virtual void exibir() const;

        //Getters e Setters
        int getId() const;
        string getTitulo() const;
};