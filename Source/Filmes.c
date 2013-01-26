///\file
///\brief Ficheiro que contem todas funções relativas ao dados do filme
///\details Neste ficheiro contem funções para inserir apagar e modificar dados de Filmes
///\authors Nelson Fernandes N.º 15390
///\authors Rita Serra       N.º 47086
///\authors Marta Santos     N.º 47181
///\date Jan. 2013
///\version 1.0
///\copyright NRM


///\brief Função inserir_filme() - função para inserir dados dos filmes.
///\details Nesta função são solicitados diversos campos para preencher dados relativos ao filme.
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
    printf("\n\nInsira o nome do filme(mim):\n");
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

///\brief Função ver_filmes() - função para ver lista dos filmes.
///\details Nesta função apresenta no ecran a lista de filmes activos
int ver_filmes()
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
     if(aux_fil.estado!=0)
     {
         printf("\n\t%d  ||  %s  ||  %d  ||  %s",aux_fil.num_filme,aux_fil.nome,aux_fil.duracao, aux_fil.genero);
     }
     }
   }
  while(!feof(fp_ver_fil));
  getch();
  fclose(fp_ver_fil);
}

///\brief Função modificar_filme() - função para modificar dados dos filmes.
///\details Nesta função pode ser alterados alguns dados relativos aos filmes.
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
    rewind(fp_fil);
     do
    {
     system("CLS");
     printf("Insira o numero do filme que quer alterar: ");
     scanf("%d",&alterar);
     rewind(fp_fil);
     fseek(fp_fil,0L,SEEK_END);
     teste=fread(&aux_fil,sizeof(filme),1,fp_fil);
     if(alterar>aux_fil.num_filme)
      {
          printf("numero de filme:%d nao existe so existe ate ao filme numero %d",alterar,aux_fil.num_filme);
          getch();
      }
    }
    while(alterar>aux_fil.num_filme);
    rewind(fp_fil);
    do
    {
    fgetpos(fp_fil,&filepos);
    teste=fread(&aux_fil,sizeof(filme),1,fp_fil);
    if(teste==1)
    {
        if(aux_fil.num_filme==alterar)
         {
            if(aux_fil.estado==0)
             {
                printf("\nN.filme\tTitulo\tDuracao\tGenero\tEstado");
                printf("\n%d\t%s\t%d\t%s\t%d",aux_fil.num_filme,aux_fil.nome,aux_fil.duracao, aux_fil.genero, aux_fil.estado);
                printf("\nFilme eliminado pretende recuperar? S/N");
                do
                {
                    op=toupper(getch());
                    switch(op)
                    {
                           case 'S':
                                {
                                    aux_fil.estado=1;
                                    fsetpos(fp_fil,&filepos);
                                    fwrite(&aux_fil,sizeof(filme),1,fp_fil);
                                    fclose(fp_fil);
                                    return;
                                }

                          case 'N':
                                    {
                                    fclose(fp_fil);
                                    return;
                                    }


                    }
                }
                while(op!='N' && op!='S');
             }
            if(aux_fil.estado!=0)
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
}
 while(!feof(fp_fil));
    fclose(fp_fil);
}


///\brief Função apagar_filmes() - função para apagar filmes.
///\details Nesta função altera o estado do filme para 0 indicando que foi removido e que deixou de estar disponivel
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
    rewind(fp_fil);
    do
    {
     system("CLS");
     printf("Insira o numero do filme a eliminar: ");
     scanf("%d",&n_fil);
     rewind(fp_fil);
     fseek(fp_fil,0L,SEEK_END);
     teste=fread(&aux_fil,sizeof(filme),1,fp_fil);
     if(n_fil>aux_fil.num_filme)
      {
          printf("numero de filme:%d nao existe so existe ate ao filme numero %d",n_fil,aux_fil.num_filme);
          getch();
      }
      else
      {
          if(aux_fil.estado==0)
          {
              printf("\n Filme ja tinha sido eliminado!!!");
              getch();
              fclose(fp_fil);
              return;
          }
      }
    }
    while(n_fil>aux_fil.num_filme);
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

///\brief Função filme_existe() - função para ver se o filme existe.
///\details Nesta função vai procurar no ficheiro o numero de um filme para ver se ele existe ou não
///\param n_filme do tipo int recebe o numero do filme que se pretende procurar.
///\return devolve um valor para indicar se o filme existe ou nao.
int filme_existe(int n_filme)
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
                if(aux_fil.estado==1)
               {
                fclose(fp_fil);
                return 1;
               }
               else
               {
                    printf("\nFilme nao se encontra disponivel!!!");
                    getch();
                    return 0;
              }
            }
        }
    }
    while(!feof(fp_fil));
    getch();
    fclose(fp_fil);
    return 0;
}
