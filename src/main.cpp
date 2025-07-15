
#include <iostream>
#include "Catalogo.h"
#include "User.h"
#include "Playlist.h"
#include "Filme.h"
#include "Serie.h"
#include "Plano.h"

#include <vector>
#include <limits>
#include <memory>

using namespace std;

//Prototipos das funções do main
void inicializarDados(Catalogo& catalogo, vector<unique_ptr<Usuario>>& usuarios);
void menuInicial(Catalogo& catalogo, vector<unique_ptr<Usuario>>& usuarios);
void menuUsuario(Usuario& usuario, Catalogo& catalogo);
void menuAdmin(Catalogo& catalogo, vector<unique_ptr<Usuario>>& usuarios);
int lerNum(string msg);
int lerNumIntervalo(string msg, int min, int max);


void exibirMenuConteudo(){
    cout << "++=============================++"<<endl;
    cout << "||          CATALOGO           ||" << endl;
    cout << "++==+==========================++"<<endl;
    cout << "| 1 | Listar todos             ||" << endl;
    cout << "| 2 | Buscar por titulo        ||" << endl;
    cout << "| 3 | Buscar por genero        ||" << endl;
    cout << "| 4 | Detalhe de conteudo      ||" << endl;
    cout << "| 0 | Voltar                   ||" << endl;
    cout << "+===+==========================++"<<endl;
}


using namespace std;
int main(){
    Catalogo catalogo;
    
    return 0;
}

int lerNum(string msg){
    string in;
    int num;

    while(true){
        cout << msg << endl;
        getline(cin, in);
        try{
            num = stoi(in);
            break;
        } catch(const exception& e){
            cout << "Entrada invalida! Insira um numero." << endl;
        }
    }
    return num;
}

int lerNumIntervalo(string msg, int min, int max){
    int num;
    do{
        num = lerNum(msg);
        if(num < min || num > max){
            cout<< "Entrada invalida, digite um numero dentro do intervalo" 
            << "(" << min <<" a " << max << ")." << endl;
        }
    } while(num<min || num>max);
    return num;
}

void menuAdmin(Catalogo& catalogo, vector<unique_ptr<Usuario>>& usuarios)