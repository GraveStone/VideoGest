
#define Mnome 50
#define Mgenero 20
typedef struct
{
        int num_filme;
        char nome[Mnome];
        int duracao;
        char genero[Mgenero];
        int estado;
        
}filme;

filme tab[5];


/// Fun��o para inserir um novo filme.
/// \param nome : nome do filme
/// \paramduracao,
/// \paramgenero[Mgenero],
/// \paramestado
int inserir_filme(        
        char nome[Mnome],
        int duracao,
        char genero[Mgenero],
        int estado
)
{
}

/// Fun��o para modificar filme.
/// \param num_filme : numero do filme
/// \param nome : nome do filme
/// \paramduracao,
/// \paramgenero[Mgenero],
/// \paramestado
int modificar_filme(
        int num_filme,        
        char nome[Mnome],
        int duracao,
        char genero[Mgenero],
        int estado
)
{
}
/// Fun��o para apagar filme.
/// \param nome : nome do filme
/// \param nome : nome do filme
/// \paramduracao,
/// \paramgenero[Mgenero],
/// \paramestado
int apagar_filme(
        int num_filme,        
        char nome[Mnome],
        int duracao,
        char genero[Mgenero],
        int estado
)
{
}


void gravar_filmes()
{

}

void carregar_filmes()
{}




   
