///\file
///\brief Ficheiro que contem todas funções relativas ao aluguer do filme
///\details
///\authors Nelson Fernandes N.º 15390
///\authors Rita Serra       N.º 47086
///\authors Marta Santos     N.º 47181
///\date Jan. 2013
///\version 1.0
///\copyright NRM


/// Cria uma estrutura para guardar o dados relativos aos alugueres.
typedef struct
{
/// Guarda o ID do Filme
    int num_filme;
/// Guarda o ID do Sócio
    int num_socio;
/// Guarda a data de levantamento do filme
    DATA data_lev;
/// Guarda a data de devolução do filme
    DATA data_ent;
/// Guarda o estado do aluguer 1 - alugado, 0 - devolvido
    int estado;
/// Guarda o numero de dias que o filme foi alugado
    long int dias;
}
ALUGAR;

/// Variavel golbal para guardar os dados relativos ao aluguer
ALUGAR aux_al;


///\brief Função aluguer() - função para alugar um filme.
///\details Nesta função de aluguer é solicitado o numero do socio e do filme e a data de levantamento e coloca o estado a 1 para indicar aluguer activo.
int aluguer()
{
    FILE *fp_al;
    char op;
    int alt=0, teste, a, b;
    int n_filme, n_socio;
    fpos_t filepos;

    system("CLS");
    fp_al=fopen("alugados.txt","a+b");
    if(!fp_al)
    {
        printf("\n\t Erro a criar o Ficheiro!!");
        getch();
        return;
    }
    do
    {
    do
    {
    system("CLS");
    printf("\nFicha de Aluger:");
    printf("\n\nInsira o numero de Socio:");
    scanf("%d",&n_socio);
    if(n_socio<=0)
    {
        printf("\nNumero nao valido!!!");
        getch();
        rewind(stdin);
    }
    }
    while(n_socio<=0);
    do
    {
       a=socio_existe(n_socio);
       if(a==1)
       {
        aux_al.num_socio=n_socio;
       }
       else
       {
        do
        {
        system("CLS");
        printf("\n\nNumero nao valido insira novo numero de Socio:");
        scanf("%d",&n_socio);
        if(n_socio<=0)
           {
            printf("\nNumero nao valido!!!");
            getch();
            rewind(stdin);
            }
        }
        while(n_socio<=0);
       }
       }

    while(aux_al.num_socio!=n_socio);

    do
    {
    system("CLS");
    printf("\n\nInsira o numero de Filme:");
    scanf("%d",&n_filme);
    if(n_filme<=0)
    {
        printf("\nNumero nao valido!!!");
        getch();
        rewind(stdin);
    }
    }
    while(n_filme<=0);
    do
    {
    do
    {
       b=filme_existe(n_filme);
       if(b==1)
       {
        aux_al.num_filme=n_filme;
       }
       else
       {
        do
        {
        system("CLS");
        rewind(stdin);
        printf("\nNumero nao valido insira novo numero de Filme:");
        scanf("%d",&n_filme);
        rewind(stdin);
        if(n_filme<=0)
           {
            printf("\nNumero nao valido!!!");
            getch();
            rewind(stdin);
            }
        }
        while(n_filme<=0);
       }
    }
    while(b==0);
    }
    while(aux_al.num_filme!=n_filme);
    rewind(stdin);
    printf("\nData:\n\nInsira a Data de Aluguer formato aaaa-mm-dd:\n\nANO:");
    ins_data(&aux_al.data_lev.ano,&aux_al.data_lev.mes,&aux_al.data_lev.dia);
    aux_al.estado=1;
    fwrite(&aux_al,sizeof(ALUGAR),1,fp_al);
    rewind(stdin);
    altera_estado_fil(n_filme,alt);
    do
    {
    printf("\nQuer Alugar outro filme?\n\n S-SIM\n N-NAO");
    op=toupper(getch());
    if(op!='S' && op!='N')
    {
      printf("\ntecla nao e valida");
    }
    }
    while(op!='S' && op!='N');
    }
    while(op!='N');
    fclose(fp_al);
}

///\brief Função devolucao() - função para devolver um filme.
///\details Nesta função de devolição é solicitado o numero do socio e do filme e a data de devolução e coloca o estado a 0 para indicar que terminou o aluguer e calcula o numero de dias que o filme teve alugado .
int devolucao()
{
    FILE *fp_ver;
    int teste,n_reg,dev,alugado=0, alt=1;
    fpos_t filepos;

    system("cls");
    fp_ver=fopen("alugados.txt","r+b");
    if(!fp_ver)
    {
        printf("\n\t Erro na leitura do Ficheiro!!");
        getch();
        return;
    }
    fseek(fp_ver,0L,SEEK_END);
    n_reg=(ftell(fp_ver))/sizeof(ALUGAR);
    rewind(fp_ver);
    if(n_reg==0)
    {
        printf("\n Ficheiro vazio");
        getch();
        fclose(fp_ver);
        return;
    }
    printf("\n\tN.filme  ||  N. Socio  || Data Req.\n\n");
    do
    {
        teste=fread(&aux_al,sizeof(ALUGAR),1,fp_ver);
        if(teste==1)
        {
            if(aux_al.estado==1)
            {
               printf("\n\t%d  ||  %d  ||  %ld-%d-%d ",aux_al.num_filme,aux_al.num_socio,aux_al.data_lev.ano, aux_al.data_lev.mes, aux_al.data_lev.dia);
               alugado++;
            }
        }
    }
    while(!feof(fp_ver));
    rewind(fp_ver);
    if(alugado==0)
    {
        printf("\n\t Nao ha filmes para devolver!!!");
        getch();
        fclose(fp_ver);
        return;
    }
    rewind(fp_ver);

    do
    {
        printf("\n\nQual o Numero de filme para devolucao:");
        scanf("%d",&dev);
        do
        {
        fgetpos(fp_ver,&filepos);
        teste=fread(&aux_al,sizeof(ALUGAR),1,fp_ver);
        if(teste==1)
        {
            if(aux_al.num_filme==dev)
            {
                if(aux_al.estado==1)
                {
                do
                {
                printf("\nData:\n\nInsira a DATA devolucaoo formato aaaa-mm-dd:\n\nANO:");
                ins_data(&aux_al.data_ent.ano,&aux_al.data_ent.mes,&aux_al.data_ent.dia);
                aux_al.dias=num_dias(aux_al.data_lev.ano,aux_al.data_ent.ano,aux_al.data_lev.mes,aux_al.data_ent.mes,aux_al.data_lev.dia,aux_al.data_ent.dia);
                if(aux_al.dias<0)
                {
                    printf("\n Data de devolucao nao e valida!!! insira uma data valida");
                }

                }
                while(aux_al.dias<0);
                aux_al.estado=0;
                fsetpos(fp_ver,&filepos);
                fwrite(&aux_al,sizeof(ALUGAR),1,fp_ver);
                printf("\n\tN.filme  ||  N. Socio  || Data Req.  ||  Data Dev.  ||  Dias alugado\n");
                printf("\n\t%d  ||  %d  || %ld-%d-%d  ||  %ld-%d-%d  ||  %d",aux_al.num_filme,aux_al.num_socio,aux_al.data_lev.ano, aux_al.data_lev.mes, aux_al.data_lev.dia,aux_al.data_ent.ano, aux_al.data_ent.mes, aux_al.data_ent.dia,aux_al.dias);
                getch();
                fclose(fp_ver);
                altera_estado_fil(dev,alt);
                return;
                }
            }
        }
    }while(!feof(fp_ver));
    rewind(fp_ver);
    }
    while(!feof(fp_ver));
    getch();
    fclose(fp_ver);
}

///\brief Função ver_alugados - função para ver os alugueres activos.
///\details Nesta função mostra o filmes que ainda se encontram alugados
int ver_alugados()
 {
  FILE *fp_ver;
  int teste,n_reg;

  system("cls");
  fp_ver=fopen("alugados.txt","rb");
  if(!fp_ver)
   {
    printf("\n\t Erro na leitura do Ficheiro!!");
    getch();
    return;
   }
  fseek(fp_ver,0L,SEEK_END);
  n_reg=(ftell(fp_ver))/sizeof(ALUGAR);
  rewind(fp_ver);
  if(n_reg==0)
   {
    printf("\n Ficheiro vazio");
    getch();
    fclose(fp_ver);
    return;
   }
  printf("\n\tN.filme  ||  N. Socio  || Data Req.  ||  Data Dev.  ||  Dias alugado\n");

  do
   {
    teste=fread(&aux_al,sizeof(ALUGAR),1,fp_ver);
    if(teste==1)
     {
      printf("\n\t%d  ||  %d  || %ld-%d-%d  ||  %ld-%d-%d  ||  %d",aux_al.num_filme,aux_al.num_socio,aux_al.data_lev.ano, aux_al.data_lev.mes, aux_al.data_lev.dia,aux_al.data_ent.ano, aux_al.data_ent.mes, aux_al.data_ent.dia,aux_al.dias);
     }
   }
  while(!feof(fp_ver));
  getch();
  fclose(fp_ver);
}


///\brief Função altera_estado_fil() - função para colocar o filme como alugado.
///\details Nesta função vai alterar o estado do filme para o estado de alugado
///\param n_filme do tipo int recebe o numero do filme que se pretende procurar.
///\return devolve um valor para indicar se o filme existe ou nao.
int altera_estado_fil(int n_filme, int alt)
{
    FILE *fp_fil;
    fpos_t filepos;
    int teste;

    fp_fil=fopen("filmes.txt","r+b");
    if(!fp_fil)
    {
        printf("\n\t Erro a ler o Ficheiro!!");
        getch();
        return;
    }
   do
   {
   if(alt==0)
    {
        fgetpos(fp_fil,&filepos);
        teste=fread(&aux_fil,sizeof(filme),1,fp_fil);
        if(teste==1)
        {
            if(aux_fil.num_filme==n_filme)
            {
                if(aux_fil.estado==1)
               {
                aux_fil.estado=2;
                fsetpos(fp_fil,&filepos);
                fwrite(&aux_fil,sizeof(filme),1,fp_fil);
                fclose(fp_fil);
                return;
               }
               else
               {
                    printf("\nErro a alugar o filme!!!");
                    getch();
                    fclose(fp_fil);
                    return;
              }
            }
        }
    }

     if(alt==1)
    {
        fgetpos(fp_fil,&filepos);
        teste=fread(&aux_fil,sizeof(filme),1,fp_fil);
        if(teste==1)
        {
            if(aux_fil.num_filme==n_filme)
            {
                if(aux_fil.estado==2)
               {
                aux_fil.estado=1;
                fsetpos(fp_fil,&filepos);
                fwrite(&aux_fil,sizeof(filme),1,fp_fil);
                fclose(fp_fil);
                return;
               }
               else
               {
                    printf("\nErro a alugar o filme!!!");
                    getch();
                    fclose(fp_fil);
                    return;
              }
            }
        }
    }
    }
    while(!feof(fp_fil));
    fclose(fp_fil);
}

///\brief Função ver_filmes_dis() - função para ver lista dos filmes disponiveis para aluguer.
///\details Nesta função apresenta no ecran a lista de filmes activos
int ver_filmes_dis()
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
  printf("\n\tN.filme  ||  Titulo  ||  Duracao ||  Genero  || Estado\n\n");
  do
   {
    teste=fread(&aux_fil,sizeof(filme),1,fp_ver_fil);
    if(teste==1)
     {
     if(aux_fil.estado==1)
     {
         printf("\n\t%d  ||  %s  ||  %d  ||  %s  || %d",aux_fil.num_filme,aux_fil.nome,aux_fil.duracao, aux_fil.genero,aux_fil.estado);
     }
     }
   }
  while(!feof(fp_ver_fil));
  getch();
  fclose(fp_ver_fil);
}
