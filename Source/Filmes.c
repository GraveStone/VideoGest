
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


/// Fun��o para inserir um novo filme.

void inserir_filme()
{
    FILE *fp_fil;
    char op;
    int n_reg;

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
    fseek(fp_fil,0L,SEEK_END);
    n_reg=(ftell(fp_fil))/sizeof(filme);
    rewind(fp_fil);
    if(n_reg==0)
    {
     aux_fil.num_filme=n_reg+1;
    }
    aux_fil.num_filme=n_reg+1;
    system("CLS");
    printf("\nFicha de Aluger:");
    printf("\n\nNumero do Filme:%d",aux_fil.num_filme);
    printf("\n\nInsira o nome do filme:\n");
    rewind(stdin);
    gets(aux_fil.nome);
    printf("\nInserir a duracao do filme:");
    scanf("%ld",&aux_fil.duracao);
    printf("\n\nInsira o genero:");
    rewind(stdin);
    gets(aux_fil.genero);
    aux_fil.estado=1;
    fwrite(&aux_fil,sizeof(filme),1,fp_fil);
    rewind(stdin);  // para limpar o buffer do teclado
    do
    {
    printf("\nQuer inserir outro Filme? (S/N)");
    op=toupper(getch());
    if(op!='S' && op!='N')
    {
      printf("\ntecla nao e valida");
    }
    }
    while(op!='S' && op!='N');
    }
    while(op!='N');
    fclose(fp_fil);
}

/// Fun��o para modificar filme.

int modificar_filme()
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





