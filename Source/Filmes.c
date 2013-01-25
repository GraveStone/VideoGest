
#define Mnome 50
#define Mgenero 20
typedef struct
{
        /// ID do filme na base de dados
        int num_filme;
        /// ID do filme na base de dados
        char nome[Mnome];
        int duracao;
        char genero[Mgenero];
        int estado;

}filme;

filme aux_fil;


/// Função para inserir um novo filme.

int inserir_filme()
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

/// Função para ver filmes


int ver_filmes(void)
 {
  FILE *fp_ver_fil;
  int teste,n_reg;

  system("cls");
  fp_ver_fil=fopen("filmes.txt","rb");
  if(!fp_ver_fil)
   {
    printf("\n\t Erro na leitura do Ficheiro!!");
    getch();
    return;
   }
  fseek(fp_ver_fil,0L,SEEK_END);
  n_reg=(ftell(fp_ver_fil))/sizeof(filme);
  rewind(fp_ver_fil);
  if(n_reg==0)
   {
    printf("\n Ficheiro vazio");
    getch();
    fclose(fp_ver_fil);
    return;
   }
  printf("\n\tN.filme  ||  Titulo  ||  Duracao ||  Genero\n\n");
  do
   {
    teste=fread(&aux_fil,sizeof(filme),1,fp_ver_fil);
    if(teste==1)
     {
     if(aux_fil.estado==1)
     {
         printf("\n\t%d  ||  %s  ||  %d  ||  %s",aux_fil.num_filme,aux_fil.nome,aux_fil.duracao, aux_fil.genero);
     }
     }
   }
  while(!feof(fp_ver_fil));
  getch();
  fclose(fp_ver_fil);
}


/// Função para modificar filme.

int modificar_filme()
{

    FILE *fp_fil;
    int alterar,teste;
    char op;
    fpos_t filepos;

    system("CLS");
    fp_fil=fopen("filmes.txt","r+b");
    if(!fp_fil)
    {
        printf("\n\t Erro de abertura do Ficheiro!!");
        getch();
        return;
    }
    system("cls");
    printf("Qual o numero de filme que quer alterar?");
    scanf("%d",&alterar);
    rewind(fp_fil);
    do
    {
    fgetpos(fp_fil,&filepos);
    teste=fread(&aux_fil,sizeof(filme),1,fp_fil);
    if(teste==1)
    {
        if(aux_fil.num_filme==alterar)
         {

                                                printf("\nN.filme\tTitulo\tDuracao\tGenero\tEstado");
                                                printf("\n%d\t%s\t%d\t%s\t%d",aux_fil.num_filme,aux_fil.nome,aux_fil.duracao, aux_fil.genero, aux_fil.estado);
                                                printf("\nApenas pode ser modificado o Titulo, Duracao e Genero");
                                                //getch(); printf("Prima ENTER para continuar");

                                                do
                                                {
                                                printf("\nPretende alterar:\n[A] Titulo\n[B] Duracao\n[C] Genero \n[D] Todos\n [S]SAIR ");
                                                op=toupper(getch());
                                                switch(op)
                                                {
                                                              case 'A':
                                                                   {

                                                                        printf("\n\nInsira o nome do filme:\n");
                                                                        rewind(stdin);
                                                                        gets(aux_fil.nome);
                                                                        fsetpos(fp_fil,&filepos);
                                                                        fwrite(&aux_fil,sizeof(filme),1,fp_fil);
                                                                        fclose(fp_fil);
                                                                        return;
                                                                   }


                                                               case 'B':
                                                                    {

                                                                        printf("\nInserir a duracao do filme:");
                                                                        scanf("%ld",&aux_fil.duracao);
                                                                        fsetpos(fp_fil,&filepos);
                                                                        fwrite(&aux_fil,sizeof(filme),1,fp_fil);
                                                                        fclose(fp_fil);
                                                                        return;
                                                                    }

                                                               case 'C':
                                                                    {

                                                                        printf("\n\nInsira o genero:");
                                                                        rewind(stdin);
                                                                        gets(aux_fil.genero);
                                                                        fsetpos(fp_fil,&filepos);
                                                                        fwrite(&aux_fil,sizeof(filme),1,fp_fil);
                                                                        fclose(fp_fil);
                                                                        return;
                                                                    }

                                                                case 'D':
                                                                        {
                                                                        printf("\n\nInsira o nome do filme:\n");
                                                                        rewind(stdin);
                                                                        gets(aux_fil.nome);
                                                                        printf("\nInserir a duracao do filme:");
                                                                        scanf("%ld",&aux_fil.duracao);
                                                                        printf("\n\nInsira o genero:");
                                                                        rewind(stdin);
                                                                        gets(aux_fil.genero);
                                                                        fsetpos(fp_fil,&filepos);
                                                                        fwrite(&aux_fil,sizeof(filme),1,fp_fil);
                                                                        fclose(fp_fil);
                                                                        return;
                                                                        }

                                                               case 'S':
                                                                   {
                                                                    fclose(fp_fil);
                                                                    return;
                                                                   }
               }

       }
        while(op!='S');
   }

}
}
 while(!feof(fp_fil));
    fclose(fp_fil);
}



///Apagar filme

int apagar_filme()
{
    FILE *fp_fil;
    char op;
    int n_fil,teste;
    fpos_t filepos;

    system("CLS");
    fp_fil=fopen("filmes.txt","r+b");
    if(!fp_fil)
    {
        printf("\n\t Erro de abertura do Ficheiro!!");
        getch();
        return;
    }

    printf("Insira o numero do filme a eliminar: ");
    scanf("%d",&n_fil);
    rewind(fp_fil);
    do
    {
    fgetpos(fp_fil,&filepos);
    teste=fread(&aux_fil,sizeof(filme),1,fp_fil);
    if(teste==1)
    {
        if(aux_fil.num_filme==n_fil)
         {
              aux_fil.estado=0;
              fsetpos(fp_fil,&filepos);
              fwrite(&aux_fil,sizeof(filme),1,fp_fil);
              fclose(fp_fil);
              return;
        }
    }
    }
    while(!feof(fp_fil));
    fclose(fp_fil);
}



int filme_existe(long int n_filme)
{
  FILE *fp_fil;
  int teste;

  system("cls");
  fp_fil=fopen("filmes.txt","rb");
  if(!fp_fil)
   {
    printf("\n\t Erro na leitura do Ficheiro!!");
    getch();
    return 0;
   }
   do
   {
        teste=fread(&aux_fil,sizeof(filme),1,fp_fil);
        if(teste==1)
        {
            if(aux_fil.num_filme==n_filme)
            {
               fclose(fp_fil);
               return 1;
            }
        }
    }
    while(!feof(fp_fil));
    getch();
    fclose(fp_fil);
    return 0;
}
