classDiagram
    %% Relacionamentos com cardinalidades 1:1, 1:n, n:m
    User "1" *-- "n" Playlist : Cria
    User "1" *-- "n" Review : Faz
    Conteudo "1" *-- "n" Review : Recebe
    Playlist "n" *-- "m" Conteudo : Contém
    User "n" --o "1" Plano : Assina

    %% Classes do Domínio
    class Catalogo {
        -std::vector<Conteudo*> conteudos
        +~Catalogo()
        +adicionarConteudo(Conteudo*)
        +removerConteudo(int)
        +buscarConteudoId(int) Conteudo*
        +buscarConteudosPorTitulo(string) vector<Conteudo*>
        +buscarConteudosPorGenero(string) vector<Conteudo*>
    }

    class Conteudo {
        #int id
        #static int proxId
        #string titulo
        #string sinopse
        #string genero
        #vector<Review*> reviews
        +getTitulo() string
        +getGenero() string
        +addReview(Review*)
        +exibir() virtual
        +~Conteudo()
    }

    class Filme {
        -string premiacoes
        +exibir() override
    }

    class Serie {
        -int episodiosTotais
        -int temporadas
        +exibir() override
    }

    class Playlist {
        -static int proxId
        -int id
        -string nome
        -User* criador
        -vector<Conteudo*> conteudos
        +adicionarConteudo(Conteudo*)
        +removerConteudo(Conteudo*)
    }

    class Review {
        -static int proxId
        -int idReview
        -User* criadorReview
        -Conteudo* conteudoAvaliado
        -int nota
        -string resenha
        +getNota() int
        +getResenha() string
    }

    class Plano {
        -string nome
        -double preco
        -string qualidadeMaxima
        -int dispositivos
        +getSimples() static Plano&
        +getPremium() static Plano&
    }

    class User {
        -static int proxId
        -int id
        -string nome
        -Plano* planoAssinatura
        -vector<Review*> reviews
        -vector<Playlist*> playlists
        +addReview(Review*)
        +addPlaylist(Playlist*)
        +autenticar() bool
    }

    %% Classe Utils 
    class Utils {
        <<utility>>
        +lerValor(T, string) T*
        +lerValorIntervalo(T, string, T, T) T*
        +lerString(string) string
    }

    %% Heranças
    Conteudo <|-- Filme
    Conteudo <|-- Serie

    %% Dependências para Utils
    User ..> Utils : «uses»
    Catalogo ..> Utils : «uses»
    Playlist ..> Utils : «uses»