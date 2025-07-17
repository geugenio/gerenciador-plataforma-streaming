#include "Utils.h"
#include <vector>
#include <memory>
#include <algorithm>
#include <stdexcept>



string lerString(string msg)
{
    string in;
    cout << msg << endl;
    getline(cin, in);
    return in;
}

void exibirMenuLogin()
{
    cout << "++=============================++" << endl;
    cout << "||          LOGIN              ||" << endl;
    cout << "++==+==========================++" << endl;
    cout << "| 1 | Entrar                   ||" << endl;
    cout << "| 2 | Cadastrar                ||" << endl;
    cout << "| 0 | Voltar                   ||" << endl;
    cout << "+===+==========================++" << endl;
}

// Primeira tela de menu pro usuário comum (não admin)
void exibirMenuConteudoUsuario()
{
    cout << "++=============================++" << endl;
    cout << "||          CATALOGO           ||" << endl;
    cout << "++==+==========================++" << endl;
    cout << "| 1 | Listar todos             ||" << endl;
    cout << "| 2 | Buscar por titulo        ||" << endl;
    cout << "| 3 | Buscar por genero        ||" << endl;
    cout << "| 4 | Ver detalhes/reviews      ||" << endl;
    cout << "| 5 | Minhas playlists         ||" << endl; // exibe playlists
    cout << "| 6 | Minhas reviews           ||" << endl; // exibe todas as reviews associadas ao usuário, em ordem cronologica (mais novas primeiro)
    cout << "| 7 | Editar meu Perfil        ||" << endl;
    cout << "| 0 | Voltar                   ||" << endl;
    cout << "+===+==========================++" << endl;
}

// Primeira tela de menu pra administrador do sistema
void exibirMenuConteudoAdmin()
{
    cout << "++=============================++" << endl;
    cout << "||        ADMINISTRACAO        ||" << endl;
    cout << "++==+==========================++" << endl;
    cout << "| 1 | Adicionar conteudo       ||" << endl;
    cout << "| 2 | Remover conteudo         ||" << endl;
    cout << "| 3 | Adicionar usuario        ||" << endl;
    cout << "| 4 | Remover usuario          ||" << endl;
    cout << "| 0 | Voltar                   ||" << endl;
    cout << "+===+==========================++" << endl;
}

void exibirMenuDetalhesConteudo()
{
    cout << "++============================++" << endl;
    cout << "||    DETALHES DO CONTEÚDO    ||" << endl;
    cout << "++==+=========================++" << endl;
    cout << "| 1 | Adicionar review        ||" << endl; // adiciona uma nova review
    cout << "| 2 | Atualizar review        ||" << endl;
    cout << "| 3 | Ler reviews             ||" << endl; // exibe todas as avaliações em uma lista
    cout << "| 4 | Adicionar a playlist    ||" << endl; //(aqui pode exibir o nome e o id das playlists do usuario, ai pergunta qual q quer inserir)
    cout << "| 0 | Voltar                  ||" << endl;
    cout << "+===+==========================++" << endl;
}

void exibirMenuPlaylists() {
    cout << "++=============================++" << endl;
    cout << "||        MINHAS PLAYLISTS     ||" << endl;
    cout << "++==+==========================++" << endl;
    cout << "| 1 | Listar Playlists         ||" << endl;
    cout << "| 2 | Criar Nova Playlist      ||" << endl;
    cout << "| 3 | Gerenciar Playlist       ||" << endl; // Para editar/remover conteúdos
    cout << "| 4 | Remover Playlist         ||" << endl;
    cout << "| 0 | Voltar                   ||" << endl;
    cout << "+===+==========================++" << endl;
}

void exibirTodosConteudos(const Catalogo &catalogo)
{
    const vector<Conteudo *> &conteudos = catalogo.getConteudos();
    cout << "++===============================++" << endl;
    cout << "||       LISTA DE CONTEUDOS      ||" << endl;
    cout << "++==+============================++" << endl;

    if (conteudos.empty())
    {
        cout << "Nenhum conteudo cadastrado." << endl;
        return;
    }
    for (const auto &conteudo : conteudos)
    {
        cout << "ID: " << conteudo->getId() << endl;
        cout << "Titulo: " << conteudo->getTitulo() << endl;
        cout << "Ano: " << conteudo->getAnoLancamento() << endl;
        cout << "--------------------------------" << endl;
    }
}

void editarPerfilUsuario(User &usuario)
{
    int opc;
    do
    {
        cout << "++============================++" << endl;
        cout << "||      EDITAR PERFIL         ||" << endl;
        cout << "++==+=========================++" << endl;
        cout << "| 1 | Alterar Nome            ||" << endl;
        cout << "| 2 | Alterar Email           ||" << endl;
        cout << "| 3 | Alterar Senha           ||" << endl;
        cout << "| 4 | Alterar Plano           ||" << endl;
        cout << "| 0 | Voltar                  ||" << endl;
        cout << "+===+==========================++" << endl;
        opc = lerValorIntervalo<int>("Escolha uma opcao:", 0, 4);

        switch (opc)
        {
        case 1:
        {
            string novoNome = lerString("Digite o novo nome:");
            usuario.setNome(novoNome);
            cout << "Nome atualizado com sucesso!" << endl;
            break;
        }
        case 2:
        {
            string novoEmail = lerString("Digite o novo email:");
            usuario.setEmail(novoEmail);
            cout << "Email atualizado com sucesso!" << endl;
            break;
        }
        case 3:
        {
            string novaSenha = lerString("Digite a nova senha:");
            usuario.setSenha(novaSenha);
            cout << "Senha atualizada com sucesso!" << endl;
            break;
        }
        case 4:
        {
            cout << "Escolha um novo plano:" << endl;
            cout << "1. Simples (SD, 1 dispositivo)" << endl;
            cout << "2. Padrao (HD, 2 dispositivos)" << endl;
            cout << "3. Premium (4K, 4 dispositivos)" << endl;
            int planoOpc = lerValorIntervalo<int>("Opcao:", 1, 3);
            Plano *novoPlano = nullptr;
            switch (planoOpc)
            {
            case 1:
                novoPlano = const_cast<Plano *>(&Plano::getSimples());
                break;
            case 2:
                novoPlano = const_cast<Plano *>(&Plano::getPadrao());
                break;
            case 3:
                novoPlano = const_cast<Plano *>(&Plano::getPremium());
                break;
            }
            usuario.setPlanoAssinatura(novoPlano);
            cout << "Plano atualizado com sucesso!" << endl;
            break;
        }
        case 0:
            cout << "Voltando..." << endl;
            break;
        default:
            cout << "Opcao invalida." << endl;
            break;
        }
    } while (opc != 0);
}

// funções de inicialização e gerenciamento
void inicializarDados(Catalogo &catalogo, vector<unique_ptr<User>> &usuarios)
{
    catalogo.adicionarConteudo(new Filme("Spider-Man 2", "Cansado de ser o Homem-Aranha, Peter Parker tenta equilibrar sua vida pessoal e suas responsabilidades de herói enquanto enfrenta o vilão Dr. Octopus.",
                                         "Sam Raimi", vector<string>{"Tobey Maguire", "Kirsten Dunst", "Alfred Molina"}, "Ação", "Super-herói", 2004, "PG-13", 127.0f, "Oscar de Melhor Efeitos Visuais"));
    catalogo.adicionarConteudo(new Filme("Jurassic Park", "Um parque temático com dinossauros clonados se torna um pesadelo quando as criaturas escapam.",
                                         "Steven Spielberg", vector<string>{"Sam Neill", "Laura Dern", "Jeff Goldblum"}, "Aventura", "Ficção Científica", 1993, "PG-13", 127.0f, "Oscar de Melhor Som, Melhor Edição de Som, Melhores Efeitos Visuais"));
    catalogo.adicionarConteudo(new Filme("Pulp Fiction", "A trama entrelaça várias histórias de criminosos em Los Angeles.",
                                         "Quentin Tarantino", vector<string>{"John Travolta", "Uma Thurman", "Samuel L. Jackson"}, "Crime", "Drama", 1994, "R", 154.0f, "Oscar de Melhor Roteiro Original"));
    catalogo.adicionarConteudo(new Filme("Enigma de Outro Mundo", "Em uma base na Antártida, uma equipe de pesquisadores enfrenta uma entidade alienígena capaz de imitar qualquer ser vivo.",
                                         "John Carpenter", vector<string>{"Kurt Russell", "Wilford Brimley", "Keith David"}, "Terror", "Ficção Científica", 1982, "R", 109.0f, "Indicado ao Saturn Award de Melhor Filme de Terror"));
    catalogo.adicionarConteudo(new Filme("Os Caçadores da Arca Perdida", "O arqueólogo Indiana Jones enfrenta nazistas em busca da Arca da Aliança, um artefato bíblico de imenso poder.",
                                         "Steven Spielberg", vector<string>{"Harrison Ford", "Karen Allen", "Paul Freeman"}, "Aventura", "Ação", 1981, "PG", 115.0f, "Oscar de Melhor Direção de Arte, Melhor Som, Melhor Edição, Melhores Efeitos Visuais"));
    catalogo.adicionarConteudo(new Filme("Indiana Jones e o Templo da Perdição", "Indiana Jones se envolve em uma missão para recuperar uma pedra sagrada e enfrenta uma seita secreta na Índia.",
                                         "Steven Spielberg", vector<string>{"Harrison Ford", "Kate Capshaw", "Ke Huy Quan"}, "Aventura", "Ação", 1984, "PG", 118.0f, "Oscar de Melhores Efeitos Visuais"));
    catalogo.adicionarConteudo(new Filme("Indiana Jones e a Última Cruzada", "Indiana Jones parte em busca do Santo Graal ao lado de seu pai, enfrentando nazistas e perigos mortais.",
                                         "Steven Spielberg", vector<string>{"Harrison Ford", "Sean Connery", "Denholm Elliott"}, "Aventura", "Ação", 1989, "PG-13", 127.0f, "Oscar de Melhor Edição de Som"));
    catalogo.adicionarConteudo(new Filme("A Viagem de Chihiro", "Chihiro, uma garota de 10 anos, entra em um mundo mágico e precisa encontrar coragem para salvar seus pais transformados em porcos.",
                                         "Hayao Miyazaki", vector<string>{"Rumi Hiiragi", "Miyu Irino", "Mari Natsuki"}, "Animação", "Fantasia", 2001, "Livre", 125.0f, "Oscar de Melhor Filme de Animação"));
    catalogo.adicionarConteudo(new Filme("O Serviço de Entregas da Kiki", "A jovem bruxa Kiki parte para a cidade grande para iniciar seu serviço de entregas enquanto aprende a lidar com a responsabilidade e a autoconfiança.",
                                         "Hayao Miyazaki", vector<string>{"Minami Takayama", "Rei Sakuma", "Kappei Yamaguchi"}, "Animação", "Fantasia", 1989, "Livre", 103.0f, "Indicado ao Prêmio Anime Grand Prix de Melhor Filme"));
    // Series (id, titulo, sinopse, diretor, elenco, genero, subgenero, anoLancamento, classificacao, duracao, episodiosTotais, temporadas)
    catalogo.adicionarConteudo(new Serie("Breaking Bad", "Um professor de química se torna fabricante de metanfetamina após ser diagnosticado com câncer.",
                                         "Vince Gilligan", {"Bryan Cranston", "Aaron Paul", "Anna Gunn"}, "Crime", "Drama", 2008, "TV-MA", 49.0, 5, 62));
    catalogo.adicionarConteudo(new Serie("Game of Thrones", "Nobres casas lutam pelo controle do Trono de Ferro em um mundo medieval cheio de intrigas e dragões.",
                                         "David Benioff", {"Emilia Clarke", "Kit Harington", "Peter Dinklage"}, "Fantasia", "Drama", 2011, "TV-MA", 60.0, 8, 73));
    catalogo.adicionarConteudo(new Serie("Twin Peaks", "O agente do FBI Dale Cooper investiga o assassinato de Laura Palmer em uma pequena e misteriosa cidade.",
                                         "David Lynch", {"Kyle MacLachlan", "Michael Ontkean", "Sheryl Lee"}, "Mistério", "Drama", 1990, "TV-14", 47.0, 30, 2));
    catalogo.adicionarConteudo(new Serie("The Office", "Uma comédia de situação que retrata o cotidiano dos funcionários de uma empresa de papel.",
                                         "Greg Daniels", {"Steve Carell", "Rainn Wilson", "John Krasinski"}, "Comédia", "Série de TV", 2005, "TV-14", 22.0, 201, 9));
    catalogo.adicionarConteudo(new Serie("Round 6", "Centenas de pessoas endividadas participam de um jogo mortal em busca de um prêmio bilionário, sem saber o verdadeiro preço da competição.",
                                         "Hwang Dong-hyuk", {"Lee Jung-jae", "Park Hae-soo", "Jung Ho-yeon"}, "Drama", "Suspense", 2021, "18", 55.0, 22, 3));
    catalogo.adicionarConteudo(new Serie("Família Soprano", "Tony Soprano, um mafioso de Nova Jersey, enfrenta os desafios de liderar uma organização criminosa enquanto lida com problemas familiares e crises pessoais.",
                                         "David Chase", {"James Gandolfini", "Lorraine Bracco", "Edie Falco"}, "Drama", "Crime", 1999, "18", 55.0, 86, 6));

    // Usuario administrador
    // id, nome, email, senha, planoAssinatura, isAdmin
    usuarios.push_back(make_unique<User>("admin", "admin@gmail.com", "admin123", nullptr, true));
}

void menuInicial(Catalogo &catalogo, vector<unique_ptr<User>> &usuarios)
{
    int opc;
    do
    {
        exibirMenuLogin();
        opc = lerValorIntervalo<int>("Escolha uma opcao:", 0, 2);
        switch (opc)
        {
        case 1:
        { // Entrar
            User *usuario = autenticarUsuario(usuarios);
            if (usuario)
            {
                if (usuario->eAdmin())
                {
                    menuAdmin(catalogo, usuarios);
                }
                else
                {
                    menuUser(*usuario, catalogo);
                }
            }
            else
            {
                cout << "Email ou senha incorretos." << endl;
            }
            break;
        }
        case 2: // Cadastrar
            cadastrarUsuario(usuarios);
            break;
        case 0: // Sair
            cout << "Saindo do programa..." << endl;
            break;
        }
    } while (opc != 0);
}

void menuConteudo(Conteudo &conteudo, User &usuario)
{
    int opc;
    do
    {
        exibirMenuDetalhesConteudo();
        opc = lerValorIntervalo<int>("Escolha uma opcao:", 0, 4);
        switch (opc)
        {
        case 1:
        { // adicionando review
            cout << "=============|  Adicionar Review   |============" << endl;
            string resenha;
            int estrela = lerValorIntervalo<int>("Estrelas (1-5)", 1, 5);
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Resenha: ";
            getline(cin, resenha);
            Review *novaReview = new Review(&usuario, &conteudo, estrela, resenha);
            usuario.addReview(novaReview);
            conteudo.addReview(novaReview);
            cout << endl
                 << "Review adicionada com sucesso!" << endl;
            break;
        }
        case 2:
        { // Atualizar review
            Review *review = usuario.buscarReviewPorConteudo(&conteudo);
            if (review)
            {
                cout << "Review encontrada. Adicione novos dados." << endl;
                int novaNota = lerValorIntervalo<int>("Nova nota(1-5):", 1, 5);
                cout << "Nova Resenha: ";
                string novaResenha;
                getline(cin, novaResenha);
                review->setNota(novaNota);
                review->setResenha(novaResenha);
                review->atualizarDataReview();
                cout << "Review atualizada com sucesso!" << endl;
            }
            else
            {
                cout << "Parece que voce ainda nao fez uma review para esse conteudo." << endl;
            }

            break;
        }
        case 3:
        { //
            conteudo.exibirReviews();
            break;
        }
        case 4:
        {
            vector<Playlist *> playlists = usuario.getPlaylists();
            if (playlists.empty())
            {
                cout << "Voce nao tem playlists ainda!" << endl;
                break;
            }

            cout << "=======| Playlists |======" << endl;
            for (const Playlist *p : playlists)
            {
                cout << "ID: " << p->getId()
                     << " | Nome: " << p->getNome()
                     << " | Quantidade de conteúdos: " << p->getConteudos().size()
                     << endl;
            }

            int idEscolhido = lerValor<int>("Digite o ID da playlist para adicionar o conteudo:");

            // Buscando
            Playlist *playlistEscolhida = nullptr;
            for (Playlist *p : playlists)
            {
                if (p->getId() == idEscolhido)
                {
                    playlistEscolhida = p;
                    break;
                }
            }
            if (!playlistEscolhida)
            {
                cout << "Playlist de ID" << idEscolhido << " nao encontrada." << endl;
                break;
            }

            cout << "Playlist " << playlistEscolhida->getNome() << " selecionada!" << endl;
            const auto &conteudos = playlistEscolhida->getConteudos();
            bool jaAdicionada = false;
            for (const Conteudo *c : conteudos)
            {
                if (c->getId() == conteudo.getId())
                {
                    jaAdicionada = true;
                    break;
                }
            }

            if (jaAdicionada)
            {
                cout << "O conteudo ja esta na playlist" << endl;
            }
            else
            {
                playlistEscolhida->adicionarConteudo(&conteudo);
                cout << "Conteudo adicionado com sucesso!" << endl;
            }
            break;
        }
        default:
        {
            break;
        }
        }
    } while (opc != 0);
}

void menuUser(User &usuario, Catalogo &catalogo)
{
    int opc;
    do
    {
        exibirMenuConteudoUsuario();
        opc = lerValorIntervalo<int>("Escolha uma opcao:", 0, 7);
        switch (opc)
        {
        case 1:
        { // Listar todos
            cout << "\n--- Lista de Todos os Conteudos ---" << endl;
            for (const auto &c : catalogo.getConteudos())
            {
                c->exibir();
                cout << "----------------------\n" << endl;
            }
            break;
        }
        case 2:
        { // Buscar por titulo
            string titulo = lerString("Digite o titulo:");
            auto resultados = catalogo.buscarConteudosPorTitulo(titulo);
            for (const auto &c : resultados)
            {
                c->exibir();
                cout << "---------------------\n" << endl;
            }
            break;
        }
        case 3:
        { // Buscar por genero
            string genero = lerString("Digite o genero:");
            auto resultados = catalogo.buscarConteudosPorGenero(genero);
            for (const auto &c : resultados)
            {
                c->exibir();
                cout << "-----\n";
            }
            break;
        }
        case 4:
        { // Ver detalhes/reviews
            int id = lerValor<int>("Digite o ID do conteudo para ver os detalhes:");
            Conteudo *c = catalogo.buscarConteudoId(id);
            if (c)
            {
                menuConteudo(*c, usuario); // desreferenciando o ponteiro
            }
            else
            {
                cout << "Conteudo nao encontrado." << endl;
            }
            break;
        }
        case 5:
        { // Minhas Playlists
            menuPlaylists(usuario, catalogo); // Chama o novo submenu
            break;
        }
        case 6:
        { // Minhas reviews
            cout << "\n--- Minhas Reviews ---" << endl;
            bool encontrou = false;
            for (const auto &r : reviews)
            {
                if (r->getCriadorReview()->getId() == usuario.getId())
                {
                    r->exibirDetalhes();
                    encontrou = true;
                }
            }
            if (!encontrou)
            {
                cout << "Voce ainda nao fez nenhuma review." << endl;
            }
            break;
        }
        case 7:
        { // editar perfil
            cout << "\n--- Editar Meu Perfil ---" << endl;
            editarPerfilUsuario(usuario);
            break;
        }

        case 0:
            cout << "Deslogando..." << endl;
            break;
        }
    } while (opc != 0);
}

void menuPlaylists(User& usuario, Catalogo& catalogo) {
    int opc;
    do {
        exibirMenuPlaylists();
        opc = lerNumIntervalo("Escolha uma opcao:", 0, 4);
        switch (opc) {
            case 1: { // Listar Playlists
                cout << "=======| Minhas playlists |======" << endl;
                const vector<Playlist*>& playlists = usuario.getPlaylists();
                if (playlists.empty()) {
                    cout << "Voce nao tem playlists ainda!" << endl;
                } else {
                    for (const Playlist* p : playlists) {
                        cout << "ID: " << p->getId()
                             << " | Nome: " << p->getNome()
                             << " | Quantidade de conteudos: " << p->getConteudos().size()
                             << endl;
                    }
                }
                break;
            }
            case 2: { // Criar Nova Playlist
                string nomePlaylist = lerString("Digite o nome da nova playlist:");
                auto novaPlaylistPtr = std::make_unique<Playlist>(nomePlaylist, &usuario);
                usuario.addPlaylist(novaPlaylistPtr.get());

                playlists.push_back(std::move(novaPlaylistPtr));

                cout << "Playlist '" << nomePlaylist << "' criada com sucesso!" << endl;
                break;
            }
            case 3: { // Gerenciar Playlist
                const vector<Playlist*>& userPlaylists = usuario.getPlaylists();
                if (userPlaylists.empty()) {
                    cout << "Voce nao tem playlists para gerenciar ainda!" << endl;
                    break;
                }

                cout << "=======| Suas Playlists |======" << endl;
                for (const Playlist* p : userPlaylists) {
                    cout << "ID: " << p->getId()
                             << " | Nome: " << p->getNome()
                             << " | Quantidade de conteudos: " << p->getConteudos().size()
                             << endl;
                }
                int idPlaylistGerenciar = lerNum("Digite o ID da playlist que deseja gerenciar:");

                Playlist* playlistGerenciar = nullptr;
                for (Playlist* p : userPlaylists) {
                    if (p->getId() == idPlaylistGerenciar) {
                        playlistGerenciar = p;
                        break;
                    }
                }

                if (playlistGerenciar) {
                    gerenciarPlaylist(usuario, playlistGerenciar, catalogo);
                } else {
                    cout << "Playlist com o ID especificado nao foi encontrada." << endl;
                }
                break;
            }
            case 4: { // Remover Playlist
                const vector<Playlist*>& userPlaylists = usuario.getPlaylists();
                if (userPlaylists.empty()) {
                    cout << "Voce nao tem playlists para remover ainda!" << endl;
                    break;
                }

                cout << "=======| Suas Playlists |======" << endl;
                for (const Playlist* p : userPlaylists) {
                    cout << "ID: " << p->getId()
                             << " | Nome: " << p->getNome()
                             << " | Quantidade de conteudos: " << p->getConteudos().size()
                             << endl;
                }
                int idPlaylistRemover = lerNum("Digite o ID da playlist que deseja remover:");

                usuario.removerPlaylistPorId(idPlaylistRemover);

                auto it = std::remove_if(playlists.begin(), playlists.end(),
                                         [idPlaylistRemover](const std::unique_ptr<Playlist>& p) {
                                             return p->getId() == idPlaylistRemover;
                                         });
                if (it != playlists.end()) {
                    playlists.erase(it, playlists.end());
                    cout << "Playlist removida com sucesso (ID: " << idPlaylistRemover << ")!" << endl;
                } else {
                    cout << "Playlist com o ID especificado nao encontrada no sistema." << endl;
                }
                break;
            }
            case 0:
                cout << "Voltando ao menu principal..." << endl;
                break;
            default:
                cout << "Opcao invalida." << endl;
                break;
        }
    } while (opc != 0);
}
        
void gerenciarPlaylist(User& usuario, Playlist* playlist, Catalogo& catalogo) {
    int opc;
    do {
        cout << "++=============================++" << endl;
        cout << "||  GERENCIAR PLAYLIST: " << playlist->getNome() << " ||" << endl;
        cout << "++==+==========================++" << endl;
        cout << "| 1 | Exibir Conteudos         ||" << endl;
        cout << "| 2 | Adicionar Conteudo       ||" << endl;
        cout << "| 3 | Remover Conteudo         ||" << endl;
        cout << "| 4 | Renomear Playlist        ||" << endl;
        cout << "| 0 | Voltar                   ||" << endl;
        cout << "+===+==========================++" << endl;
        opc = lerNumIntervalo("Escolha uma opcao:", 0, 4);

        switch (opc) {
            case 1: { // Exibir Conteúdos
                const vector<Conteudo*>& conteudosPlaylist = playlist->getConteudos();
                if (conteudosPlaylist.empty()) {
                    cout << "A playlist esta vazia." << endl;
                } else {
                    cout << "--- Conteudos da Playlist ---" << endl;
                    for (const auto& c : conteudosPlaylist) {
                        cout << "ID: " << c->getId() << " | Titulo: " << c->getTitulo() << endl;
                    }
                }
                break;
            }
            case 2: { // Adicionar Conteúdo
                exibirTodosConteudos(catalogo); // Opcional: mostrar todos os conteúdos disponíveis
                int idConteudoAdd = lerNum("Digite o ID do conteudo para adicionar a playlist:");
                Conteudo* conteudoAdd = catalogo.buscarConteudoId(idConteudoAdd);
                if (conteudoAdd) {
                    bool jaAdicionada = false;
                    for (const Conteudo *c : playlist->getConteudos()) {
                        if (c->getId() == conteudoAdd->getId()) {
                            jaAdicionada = true;
                            break;
                        }
                    }
                    if (jaAdicionada) {
                        cout << "O conteudo ja esta na playlist" << endl;
                    } else {
                        playlist->adicionarConteudo(conteudoAdd);
                        cout << "Conteudo adicionado com sucesso!" << endl;
                    }
                } else {
                    cout << "Conteudo nao encontrado." << endl;
                }
                break;
            }
            case 3: { // Remover Conteúdo
                const vector<Conteudo*>& conteudosPlaylist = playlist->getConteudos();
                if (conteudosPlaylist.empty()) {
                    cout << "A playlist esta vazia. Nao ha conteudos para remover." << endl;
                    break;
                }
                cout << "--- Conteudos da Playlist ---" << endl;
                for (const auto& c : conteudosPlaylist) {
                    cout << "ID: " << c->getId() << " | Titulo: " << c->getTitulo() << endl;
                }
                int idConteudoRemover = lerNum("Digite o ID do conteudo para remover da playlist:");
                Conteudo* conteudoRemover = nullptr;
                for (Conteudo* c : playlist->getConteudos()) {
                    if (c->getId() == idConteudoRemover) {
                        conteudoRemover = c;
                        break;
                    }
                }
                if (conteudoRemover) {
                    try {
                        playlist->removerConteudo(conteudoRemover);
                        cout << "Conteudo removido com sucesso!" << endl;
                    } catch (const std::runtime_error& e) {
                        cout << "Erro: " << e.what() << endl;
                    }
                } else {
                    cout << "Conteudo com o ID especificado nao encontrado na playlist." << endl;
                }
                break;
            }
            case 4: { // Renomear Playlist
                string novoNome = lerString("Digite o novo nome para a playlist:");
                playlist->setNome(novoNome);
                cout << "Playlist renomeada para '" << novoNome << "' com sucesso!" << endl;
                break;
            }
            case 0:
                cout << "Voltando..." << endl;
                break;
            default:
                cout << "Opcao invalida." << endl;
                break;
        }
    } while (opc != 0);
}        

void menuAdmin(Catalogo &catalogo, vector<unique_ptr<User>> &usuarios)
{
    int opc;
    do
    {
        exibirMenuConteudoAdmin();
        opc = lerValorIntervalo<int>("Escolha uma opcao:", 0, 4);
        switch (opc)
        {
        case 1:
        { // Adicionar conteudo
            int tipo = lerValorIntervalo<int>("Adicionar (1) Filme ou (2) Serie?", 1, 2);
            string titulo = lerString("Titulo:");
            string sinopse = lerString("Sinopse:");
            string diretor = lerString("Diretor:");
            string genero = lerString("Genero:");
            string subgenero = lerString("Subgenero:");
            int ano = lerValor<int>("Ano de Lancamento:");
            string classificacao = lerString("Classificacao:");
            float duracao = lerValor<float>("Duracao (minutos):");

            if (tipo == 1)
            { // Filme
                string premiacoes = lerString("Premiacoes:");
                catalogo.adicionarConteudo(new Filme(titulo, sinopse, diretor, {}, genero, subgenero, ano, classificacao, duracao, premiacoes));
            }
            else
            { // Serie
                int episodios = lerValor<int>("Numero total de episodios:");
                int temporadas = lerValor<int>("Numero de temporadas:");
                catalogo.adicionarConteudo(new Serie(titulo, sinopse, diretor, {}, genero, subgenero, ano, classificacao, duracao, episodios, temporadas));
            }
            // A linha original que criava o Filme deve ser removida
            cout << "Conteudo adicionado com sucesso!" << endl;
            break;
        }
        case 2: {
                cout << "\n--- Remover Conteudo ---" << endl;
                int removerOpc = lerValorIntervalo<int>("Remover por (1) ID ou (2) Titulo?", 1, 2);
                
                if (removerOpc == 1) { // Remover por ID
                    int id = lerValor<int>("Digite o ID do conteudo a ser removido:");
                    catalogo.removerConteudo(id); 
                } else { // Remover por Titulo
                    string tituloBusca = lerString("Digite o titulo do conteudo a ser removido:");
                    vector<Conteudo*> resultados = catalogo.buscarConteudosPorTitulo(tituloBusca);

                    if (resultados.empty()) {
                        cout << "Nenhum conteudo encontrado com o titulo '" << tituloBusca << "'." << endl;
                    } else {
                        cout << "Conteudos encontrados com o titulo '" << tituloBusca << "':" << endl;
                        for (const auto& c : resultados) {
                            cout << "ID: " << c->getId() << " | Titulo: " << c->getTitulo() << " | Genero: " << c->getGenero() << endl;
                        }

                        int idRemover = lerValor<int>("Digite o ID do conteudo EXATO para remover (ou 0 para cancelar):");
                        if (idRemover != 0) {
                            bool idEncontradoNaBusca = false;
                            for (const auto& c : resultados) {
                                if (c->getId() == idRemover) {
                                    idEncontradoNaBusca = true;
                                    break;
                                }
                            }
                            if (idEncontradoNaBusca) {
                                catalogo.removerConteudo(idRemover);
                            } else {
                                cout << "ID nao corresponde a um conteudo encontrado na busca. Remocao cancelada." << endl;
                            }
                        } else {
                            cout << "Remocao por titulo cancelada." << endl;
                        }
                    }
                }
                break;
            }
        case 3:
        { // Adicionar usuario
            cadastrarUsuario(usuarios);
            break;
        }
        case 4:
        { // Remover usuario
            cout << "\n--- Lista de Usuarios ---" << endl;
            for (const auto &u : usuarios)
            {
                cout << "ID: " << u->getId() << " | Nome: " << u->getNome() << " | Email: " << u->getEmail() << endl;
            }
            int id = lerValor<int>("Digite o ID do usuario a ser removido:");
            auto it = remove_if(usuarios.begin(), usuarios.end(), [id](const unique_ptr<User> &u)
                                { return u->getId() == id; });
            if (it != usuarios.end())
            {
                usuarios.erase(it, usuarios.end());
                cout << "Usuario removido com sucesso." << endl;
            }
            else
            {
                cout << "Usuario nao encontrado." << endl;
            }
            break;
        }
        case 0:
            cout << "Deslogando..." << endl;
            break;
        }
    } while (opc != 0);
}

User *autenticarUsuario(const vector<unique_ptr<User>> &usuarios)
{
    string email = lerString("Digite seu email:");
    string senha = lerString("Digite sua senha:");
    for (const auto &user : usuarios)
    {
        if (user->autenticar(email, senha))
        {
            return user.get();
        }
    }
    return nullptr;
}

void cadastrarUsuario(vector<unique_ptr<User>> &usuarios)
{
    string nome = lerString("Digite seu nome:");
    string email = lerString("Digite seu email:");
    string senha = lerString("Digite sua senha:");

    cout << "Escolha um plano:" << endl;
    cout << "1. Simples (SD, 1 dispositivo)" << endl;
    cout << "2. Padrao (HD, 2 dispositivos)" << endl;
    cout << "3. Premium (4K, 4 dispositivos)" << endl;
    int planoOpc = lerValorIntervalo<int>("Opcao:", 1, 3);

    Plano *planoAssinatura = nullptr;
    switch (planoOpc)
    {
    case 1:
        planoAssinatura = const_cast<Plano *>(&Plano::getSimples());
        break;
    case 2:
        planoAssinatura = const_cast<Plano *>(&Plano::getPadrao());
        break;
    case 3:
        planoAssinatura = const_cast<Plano *>(&Plano::getPremium());
        break;
    }

    usuarios.push_back(make_unique<User>(nome, email, senha, planoAssinatura, false));
    cout << "Usuario cadastrado com sucesso!" << endl;
}
