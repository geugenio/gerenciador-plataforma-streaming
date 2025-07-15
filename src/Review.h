#pragma once
#include <string>
#include <ctime>

#include "User.h"
#include "Conteudo.h"
using namespace std;

class Review {
private:
    static int proxId; //id gerador automatico
    int idReview;
    User* criadorReview;
    Conteudo* conteudoAvaliado;
    int nota;
    string resenha;
    time_t dataReview;

public:
    Review(User* criador, Conteudo* conteudo, int nota, const string& resenha);
    ~Review() = default;

    int getIdReview() const;
    User* getCriadorReview() const;
    Conteudo* getConteudoAvaliado() const;
    int getNota() const;
    string getResenha() const;
    time_t getDataReview() const;

    void setNota(int novaNota);
    void setResenha(const string& novaResenha);

    void exibirDetalhes() const;
};
