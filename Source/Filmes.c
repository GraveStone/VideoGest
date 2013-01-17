
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

filme aux_fil;


/// Função para inserir um novo filme.

void inserir_filme()
{
    FILE *fp_fil;
    char op;


    system("CLS");
    fp_fil=fopen("filmes.txt","a+b");
    if(!fp_fil)
    {
        printf("\n\t Erro a criar o Ficheiro!!");
        getch();
        return;
    }
    do
    {
    system("CLS");
    printf("\nFicha de Aluger:");
    printf("\n\nInsira o numero do Filme:");
    scanf("%d",&aux_fil.num_filme);
    printf("\n\nInsira o nome do filme:\n");
    rewind(stdin);
    gets(aux_fil.nome);
    printf("\nInserir a duracao do filme:");
    scanf("%ld",&aux_fil.duracao);
    printf("\n\nInsira o genero:");
    rewind(stdin);
    gets(aux_fil.genero);
    aux_fil.estado=1;
    getchar();
    fwrite(&aux_fil,sizeof(filme),1,fp_fil);
    rewind(stdin);  // para limpar o buffer do teclado
    printf("Continuar s inserir filme");
    op=toupper(getch());
    }
    while(op!='N');
    fclose(fp_fil);

}

/// Função para modificar filme.

int modificar_filme()
{
}
/// Função para apagar filme.
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





