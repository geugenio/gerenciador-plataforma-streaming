#include "Review.h"
#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;
int Review::proxId = 1;

Review::Review(User* criador, Conteudo* conteudo, int estrela, const string& resenha)
    : idReview(proxId++), criadorReview(criador), conteudoAvaliado(conteudo), resenha(resenha) 
{
    if (estrela >= 0 && estrela <= 5) {
        this->nota = estrela;
    } else {
        cerr << "Nota inválida! Definindo nota para 0." << endl;
        this->nota = 0;
    }
    this->dataReview = time(0);
}

// getter e setter
int Review::getIdReview() const {
    return idReview;
}

User* Review::getCriadorReview() const {
    return criadorReview;
}

Conteudo* Review::getConteudoAvaliado() const {
    return conteudoAvaliado;
}

int Review::getNota() const {
    return nota;
}

string Review::getResenha() const {
    return resenha;
}

time_t Review::getDataReview() const {
    return dataReview;
}

void Review::setNota(int novaNota) {
    if (novaNota >= 0 && novaNota <= 5) {
        this->nota = novaNota;
    } else {
        cerr << "A alteração da nota falhou. Nota Invãlida. A nota não foi alterada." << endl;
    }
}

void Review::setResenha(const string& novaResenha) {
    this->resenha = novaResenha;
}

void Review::exibirDetalhes() const {
    cout << "--- Detalhes da Review ---" << endl;
    cout << "ID da Review: " << idReview << endl;

    if (criadorReview) {
        cout << "Usuário: " << criadorReview->getNome() << " (ID: " << criadorReview->getId() << ")" << endl;
    } else {
        cout << "Usuário: Desconhecido" << endl;
    }

    if (conteudoAvaliado) {
        cout << "Conteúdo Avaliado: " << conteudoAvaliado->getTitulo() << " (ID: " << conteudoAvaliado->getId() << ")" << endl;
    } else {
        cout << "Conteúdo: Desconhecido" << endl;
    }

    cout << "Nota: " << nota << "/5" << endl;
    cout << "Resenha: " << resenha << endl;

    char dataHora[80];
    if (strftime(dataHora, sizeof(dataHora), "%d/%m/%Y %H:%M:%S", localtime(&dataReview))) {
        cout << "Data da Review: " << dataHora << endl;
    } else {
        cout << "Data da Review: Erro ao formatar data" << endl;
    }
    cout << "--------------------------" << endl;
}
