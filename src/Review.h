#pragma once
#include <string>
#include <ctime>
#include <ctime>
class User;
class Conteudo;


class Review {
private:
    static int proxId; //id gerador automatico
    int idReview;
    User* criadorReview;
    Conteudo* conteudoAvaliado;
    int nota;
    std::string resenha;
    std::time_t dataReview;

public:
    Review(User* criador, Conteudo* conteudo, int nota, const std::string& resenha);
    ~Review() = default;

    int getIdReview() const;
    User* getCriadorReview() const;
    Conteudo* getConteudoAvaliado() const;
    int getNota() const;
    std::string getResenha() const;
    std::time_t getDataReview() const;

    void setNota(int novaNota);
    void setResenha(const std::string& novaResenha);

    void exibirDetalhes() const;
    void atualizarDataReview();
};
