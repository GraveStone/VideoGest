///\file
///\brief Ficheiro que contem todas funções relativas ao aluguer do filme
///\details
///\authors Nelson Fernandes N.º 15390
///\authors Rita Serra       N.º 47086
///\authors Marta Santos     N.º 47181
///\date Jan. 2013
///\version 1.0
///\copyright NRM


/// Cria uma estrutura para guardar o datos relativos aos alugueres.
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
    int bissexto, teste, a, b;
    int n_filme, n_socio;

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
    system("CLS");
    printf("\nFicha de Aluger:");
    printf("\n\nInsira o numero de Socio:");
    scanf("%d",&n_socio);
    do
    {
       a=socio_existe(n_socio);
       if(a==0)
       {
        printf("\n\nNumero não valido insira novo numero de Socio:");
        scanf("%d",&n_socio);
       }
       else
       {
        aux_al.num_socio=n_socio;
       }
    }
    while(aux_al.num_socio!=n_socio);
    printf("\n\nInsira o numero de Filme:");
    scanf("%d",&n_filme);
    do
    {
       b=filme_existe(n_filme);
       if(b==0)
       {
        printf("\n\nNumero não valido insira novo numero de Filme:");
        scanf("%d",&n_filme);
       }
       else
       {
        aux_al.num_filme=n_filme;
       }
    }
    while(aux_al.num_filme!=n_filme);
    printf("\nData:\n\nInsira a DATA de Aluguer formato aaaa-mm-dd:\n\nANO:");
    ins_data(&aux_al.data_lev.ano,&aux_al.data_lev.mes,&aux_al.data_lev.dia);
    aux_al.estado=1;
    fwrite(&aux_al,sizeof(ALUGAR),1,fp_al);
    rewind(stdin);
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
    int teste,n_reg,dev, bissexto,alugado;
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
    do
    {
        teste=fread(&aux_al,sizeof(ALUGAR),1,fp_ver);
        if(teste==1)
        {
            if(aux_al.estado==1)
            {
               printf("\n%d\t%d\t%ld-%d-%d\t%d n_reg %d",aux_al.num_filme,aux_al.num_socio,aux_al.data_lev.ano, aux_al.data_lev.mes, aux_al.data_lev.dia,aux_al.estado,n_reg);
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

    printf("Qual o Numero de Socio para devolucao:");
    scanf("%d",&dev);
    printf("\nN§ filme\tSocio");
    do
    {
        teste=fread(&aux_al,sizeof(ALUGAR),1,fp_ver);
        if(teste==1)
        {
            if(aux_al.num_socio==dev)
            {
               printf("\n%d\t%d\t%ld-%d-%d\t%d n_reg %d",aux_al.num_filme,aux_al.num_socio,aux_al.data_lev.ano, aux_al.data_lev.mes, aux_al.data_lev.dia,aux_al.estado,n_reg);
            }
        }
    }
    while(!feof(fp_ver));
    rewind(fp_ver);
    printf("Qual o Numero de filme para devolucao:");
    scanf("%d",&dev);
    printf("\nN§ filme\tSocio");
    do
    {
        fgetpos(fp_ver,&filepos);
        teste=fread(&aux_al,sizeof(ALUGAR),1,fp_ver);
        if(teste==1)
        {
            if(aux_al.num_filme==dev)
            {
                do
                {
                printf("\nData:\n\nInsira a DATA devolução formato aaaa-mm-dd:\n\nANO:");
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
                printf("\n%d\t%d\t%ld-%d-%d\t%d n_reg %ld",aux_al.num_filme,aux_al.num_socio,aux_al.data_lev.ano, aux_al.data_lev.mes, aux_al.data_lev.dia,aux_al.estado,aux_al.dias);
                fclose(fp_ver);
                getch();
                return;
            }
        }
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
  printf("\nN§ filme\tSocio");
  do
   {
    teste=fread(&aux_al,sizeof(ALUGAR),1,fp_ver);
    if(teste==1)
     {
      printf("\n%d\t%d\t%ld-%d-%d\t%d n_reg %ld",aux_al.num_filme,aux_al.num_socio,aux_al.data_lev.ano, aux_al.data_lev.mes, aux_al.data_lev.dia,aux_al.estado,aux_al.dias);
     }
   }
  while(!feof(fp_ver));
  getch();
  fclose(fp_ver);
}
