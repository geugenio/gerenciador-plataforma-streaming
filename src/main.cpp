
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
#include <string>

using namespace std;

//prototipo
void inicializarDados(Catalogo& catalogo, vector<unique_ptr<User>>& usuarios);


void menuInicial(Catalogo& catalogo, vector<unique_ptr<User>>& usuarios);
void menuUser(User& usuario, Catalogo& catalogo);
void menuAdmin(Catalogo& catalogo, vector<unique_ptr<User>>& usuarios);

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


void exibirMenuLogin(){
    cout << "++=============================++"<<endl;
    cout << "||          LOGIN              ||" << endl;
    cout << "++==+==========================++"<<endl;
    cout << "| 1 | Entrar                   ||" << endl;
    cout << "| 2 | Cadastrar                ||" << endl;
    cout << "| 0 | Voltar                   ||" << endl;
    cout << "+===+==========================++"<<endl;
}

//Primeira tela de menu pro usuário comum (não admin)
void exibirMenuConteudoUsuario(){
    cout << "++=============================++"<<endl;
    cout << "||          CATALOGO           ||" << endl;
    cout << "++==+==========================++"<<endl;
    cout << "| 1 | Listar todos             ||" << endl;
    cout << "| 2 | Buscar por titulo        ||" << endl;
    cout << "| 3 | Buscar por genero        ||" << endl;
    cout << "| 4 | Ver dtalhes/reviews      ||" << endl;
    cout << "| 5 | Minhas playlists         ||" << endl; //exibe playlists
    cout << "| 6 | Minhas reviews           ||" << endl; //exibe todas as reviews associadas ao usuário, em ordem cronologica (mais novas primeiro)
    cout << "| 0 | Voltar                   ||" << endl;
    cout << "+===+==========================++"<<endl;
}

//Primeira tela de menu pra administrador do sistema
void exibirMenuConteudoAdmin(){
    cout << "++=============================++"<<endl;
    cout << "||        ADMINISTRACAO        ||" << endl;
    cout << "++==+==========================++"<<endl;
    cout << "| 1 | Adicionar conteudo       ||" << endl;
    cout << "| 2 | Remover conteudo         ||" << endl;
    cout << "| 3 | Adicionar usuario        ||" << endl;
    cout << "| 4 | Remover usuario          ||" << endl;
    cout << "| 0 | Voltar                   ||" << endl;
    cout << "+===+==========================++"<<endl;
}

void menuConteudo(){
    cout << "++=============================++" << endl;
    cout << "||   DETALHES DO CONTEÚDO     ||" << endl;
    cout << "++==+=========================++" << endl;
    cout << "| 1 | Adicionar review        ||" << endl; //adiciona uma nova review
    cout << "| 2 | ler reviews             ||" << endl; //exibe todas as avaliações em uma lista
    cout << "| 3 | Adicionar a playlist    ||" << endl; //(aqui pode exibir o nome e o id das playlists do usuario, ai pergunta qual q quer inserir)
    cout << "| 0 | Voltar                  ||" << endl;
    cout << "+===+==========================++"<<endl;
}

void exibirTodosConteudos(const Catalogo& catalogo){
    const vector<Conteudo*>& conteudos = catalogo.getConteudos();
    cout << "++===============================++"<<endl;
    cout << "||       LISTA DE CONTEUDOS      ||" << endl;
    cout << "++==+============================++"<<endl;
    
    if(conteudos.empty()){
        cout << "Nenhum conteudo cadastrado." << endl;
        return;
    }
    for(const auto& conteudo : conteudos){
        cout << "ID: " << conteudo->getId() << endl;
        cout << "Titulo: " << conteudo->getTitulo() << endl;
        cout<< "Ano: " << conteudo->getAnoLancamento() << endl;
        cout << "--------------------------------" << endl;
    }
}


using namespace std;
int main(){
    Catalogo catalogo;
    vector<unique_ptr<User>> usuarios;
    inicializarDados(catalogo, usuarios);
    int opc = 0;
    cout << "===============================================" << endl;
    cout << "||           BEM VINDO AO SISTEMA DE          ||" << endl;
    cout << "||         GERENCIAMENTO DE STREAMING         ||" << endl;
    cout << "===============================================" << endl;




    
    return 0;
}




//Prototipos das funções do main
void inicializarDados(Catalogo& catalogo, vector<unique_ptr<User>>& usuarios){
    //Filmes (id, titulo, sinopse, diretor, elenco, genero, subgenero, anoLancamento, classificacao, duracao, premiacoes)
    catalogo.adicionarConteudo(new Filme(1, "Spider-Man 2", "Cansado de ser o Homem-Aranha, Peter Parker tenta equilibrar sua vida pessoal e suas responsabilidades de herói enquanto enfrenta o vilão Dr. Octopus.", 
        "Sam Raimi", {"Tobey Maguire", "Kirsten Dunst", "Alfred Molina"}, "Ação", "Super-herói", 2004, "PG-13", 127.0, "Oscar de Melhor Efeitos Visuais"));
    catalogo.adicionarConteudo(new Filme(2, "Jurassic Park", "Um parque temático com dinossauros clonados se torna um pesadelo quando as criaturas escapam.", 
        "Steven Spielberg", {"Sam Neill", "Laura Dern", "Jeff Goldblum"}, "Aventura", "Ficção Científica", 1993, "PG-13", 127.0, "Oscar de Melhor Som, Melhor Edição de Som, Melhores Efeitos Visuais"));
    catalogo.adicionarConteudo(new Filme(3, "Pulp Fiction", "A trama entrelaça várias histórias de criminosos em Los Angeles.", 
        "Quentin Tarantino", {"John Travolta", "Uma Thurman", "Samuel L. Jackson"}, "Crime", "Drama", 1994, "R", 154.0, "Oscar de Melhor Roteiro Original"));
    catalogo.adicionarConteudo(new Filme(4, "Enigma de Outro Mundo", "Em uma base na Antártida, uma equipe de pesquisadores enfrenta uma entidade alienígena capaz de imitar qualquer ser vivo.", 
        "John Carpenter", {"Kurt Russell", "Wilford Brimley", "Keith David"}, "Terror", "Ficção Científica", 1982, "R", 109.0, "Indicado ao Saturn Award de Melhor Filme de Terror"));
    catalogo.adicionarConteudo(new Filme(5, "Os Caçadores da Arca Perdida", "O arqueólogo Indiana Jones enfrenta nazistas em busca da Arca da Aliança, um artefato bíblico de imenso poder.",
        "Steven Spielberg", {"Harrison Ford", "Karen Allen", "Paul Freeman"}, "Aventura", "Ação", 1981, "PG", 115.0, "Oscar de Melhor Direção de Arte, Melhor Som, Melhor Edição, Melhores Efeitos Visuais"));
    catalogo.adicionarConteudo(new Filme(6, "Indiana Jones e o Templo da Perdição", "Indiana Jones se envolve em uma missão para recuperar uma pedra sagrada e enfrenta uma seita secreta na Índia.",
        "Steven Spielberg", {"Harrison Ford", "Kate Capshaw", "Ke Huy Quan"}, "Aventura", "Ação", 1984, "PG", 118.0, "Oscar de Melhores Efeitos Visuais"));
    catalogo.adicionarConteudo(new Filme(7, "Indiana Jones e a Última Cruzada","Indiana Jones parte em busca do Santo Graal ao lado de seu pai, enfrentando nazistas e perigos mortais.",
        "Steven Spielberg", {"Harrison Ford", "Sean Connery", "Denholm Elliott"}, "Aventura", "Ação", 1989, "PG-13", 127.0, "Oscar de Melhor Edição de Som"));
    catalogo.adicionarConteudo(new Filme(8, "A Viagem de Chihiro", "Chihiro, uma garota de 10 anos, entra em um mundo mágico e precisa encontrar coragem para salvar seus pais transformados em porcos.",
        "Hayao Miyazaki", {"Rumi Hiiragi", "Miyu Irino", "Mari Natsuki"}, "Animação", "Fantasia", 2001, "Livre", 125.0, "Oscar de Melhor Filme de Animação"));
    catalogo.adicionarConteudo(new Filme(9, "O Serviço de Entregas da Kiki", "A jovem bruxa Kiki parte para a cidade grande para iniciar seu serviço de entregas enquanto aprende a lidar com a responsabilidade e a autoconfiança.",
        "Hayao Miyazaki", {"Minami Takayama", "Rei Sakuma", "Kappei Yamaguchi"}, "Animação", "Fantasia", 1989, "Livre", 103.0, "Indicado ao Prêmio Anime Grand Prix de Melhor Filme"));
    //Series (id, titulo, sinopse, diretor, elenco, genero, subgenero, anoLancamento, classificacao, duracao, episodiosTotais, temporadas)
    catalogo.adicionarConteudo(new Serie(10, "Breaking Bad", "Um professor de química se torna fabricante de metanfetamina após ser diagnosticado com câncer.", 
        "Vince Gilligan", {"Bryan Cranston", "Aaron Paul", "Anna Gunn"}, "Crime", "Drama", 2008, "TV-MA", 49.0, 5, 62)); 
     catalogo.adicionarConteudo(new Serie(11, "Game of Thrones", "Nobres casas lutam pelo controle do Trono de Ferro em um mundo medieval cheio de intrigas e dragões.", 
        "David Benioff", {"Emilia Clarke", "Kit Harington", "Peter Dinklage"}, "Fantasia", "Drama", 2011, "TV-MA", 60.0, 8, 73));
    catalogo.adicionarConteudo(new Serie(12, "Twin Peaks", "O agente do FBI Dale Cooper investiga o assassinato de Laura Palmer em uma pequena e misteriosa cidade.", 
        "David Lynch", {"Kyle MacLachlan", "Michael Ontkean", "Sheryl Lee"}, "Mistério", "Drama", 1990, "TV-14", 47.0, 30, 2));
    catalogo.adicionarConteudo(new Serie(13, "The Office", "Uma comédia de situação que retrata o cotidiano dos funcionários de uma empresa de papel.", 
        "Greg Daniels", {"Steve Carell", "Rainn Wilson", "John Krasinski"}, "Comédia", "Série de TV", 2005, "TV-14", 22.0, 201, 9));
    catalogo.adicionarConteudo(new Serie(14, "Round 6", "Centenas de pessoas endividadas participam de um jogo mortal em busca de um prêmio bilionário, sem saber o verdadeiro preço da competição.",
        "Hwang Dong-hyuk", {"Lee Jung-jae", "Park Hae-soo", "Jung Ho-yeon"}, "Drama", "Suspense", 2021, "18", 55.0, 22, 3));
    catalogo.adicionarConteudo(new Serie(15, "Família Soprano", "Tony Soprano, um mafioso de Nova Jersey, enfrenta os desafios de liderar uma organização criminosa enquanto lida com problemas familiares e crises pessoais.",
        "David Chase",{"James Gandolfini", "Lorraine Bracco", "Edie Falco"}, "Drama", "Crime", 1999, "18", 55.0, 86, 6));

    //Usuario administrador
    //id, nome, email, senha, planoAssinatura, isAdmin
    usuarios.push_back(make_unique<User>(1, "admin", "admin@gmail.com", "admin123", nullptr, true));

}