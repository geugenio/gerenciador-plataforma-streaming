#pragma once
#include <iostream>

class Plano{
    private:
        std::string nome;
        double preco;
        std::string qualidadeMaxima;
        int dispositivos;
        //construtor privado
        Plano(const std::string& nome, double preco, const std::string& qualidadeMaxima, int dispositivos);
    public:
        static const Plano& getSimples();
        static const Plano& getPadrao();
        static const Plano& getPremium();
        
        std::string getNome() const;
        double getPreco() const;
        std::string getQualidadeMaxima() const;
        int getDispositivos() const;


        void exibir() const;
};
