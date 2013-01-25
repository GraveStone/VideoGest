#define Mnome 50
#define Mmorada 50
/// Cria uma estrutura com os dados dos sócios
typedef struct
{
 char nome[Mnome];
 char morada[Mmorada];
 int num_soc;
 DATA dt_nasc;
 long int contacto;
 int estado;
}SOCIO;

SOCIO aux_soc;
/// funcao para mostrar a lista de socios
/// param ficheiro Socios, estutura Socios
int ver_lista()
{
     FILE *fp_ver;
     int teste;


     fp_ver=fopen("socios.txt","rb");
     if(!fp_ver)
    {
        printf("\n\t Erro a abrir o Ficheiro!!");
        getch();
        return;
    }
    system("cls");
    printf("\n\tN.de Soc. ||  Nome  ||  Morada  ||  Data de Nasci.  || Contacto\n\n");
    do
    {
     teste=fread(&aux_soc,sizeof(SOCIO),1,fp_ver);
    if(teste==1)
    {
    if(aux_soc.estado==1)
    {
        printf("\n\t%d || %s || %s || %ld-%d-%d || %ld",aux_soc.num_soc,aux_soc.nome,aux_soc.morada,aux_soc.dt_nasc,aux_soc.contacto);
    }
    }
    }
    while (!feof(fp_ver));
    getch();
 }

///funcao para ver que socio existem
///param
 int socio_existe(long int n_soc)
{
  FILE *fp_soc;
  int teste;

  system("cls");
  fp_soc=fopen("socios.txt","rb");
  if(!fp_soc)
   {
    printf("\n\t Erro na leitura do Ficheiro!!");
    getch();
    return 0;
   }
   do
   {
        teste=fread(&aux_soc,sizeof(SOCIO),1,fp_soc);
        if(teste==1)
        {
            if(aux_soc.num_soc==n_soc)
            {
               fclose(fp_soc);
               return 1;
            }
        }
    }
    while(!feof(fp_soc));
    getch();
    fclose(fp_soc);
    return 0;
}

/// funcao para adicionar socio
/// \param nome do socio
/// \param morada
/// \param numero de socio
/// \param data de nascimento
/// \param contacto
int adicionar_soc()
{
   FILE *fp_soc;
    char op;
    int n_reg;

    system("CLS");
    fp_soc=fopen("socios.txt","a+b");
    if(!fp_soc)
    {
        printf("\n\t Erro a criar o Ficheiro!!");
        getch();
        return;
    }
    do
    {
    fseek(fp_soc,0L,SEEK_END);
    n_reg=(ftell(fp_soc))/sizeof(SOCIO);
    rewind(fp_soc);
    if(n_reg==0)
    {
     aux_soc.num_soc=n_reg+1;
    }
    aux_soc.num_soc=n_reg+1;
    system("CLS");
    printf("\n                  Ficha de Socio:");
    printf("\n\nNumero do socio:%d",aux_soc.num_soc);
    printf("\n\nInsira nome do socio:\n");
    rewind(stdin);
    gets(aux_soc.nome);
    printf("\nInsira a DATA de nascimento formato aaaa-mm-dd:\n\nANO:");
    ins_data(&aux_soc.dt_nasc.ano,&aux_soc.dt_nasc.mes,&aux_soc.dt_nasc.dia);
    printf("\n\nInsira a morada: ");
    rewind(stdin);
    gets(aux_soc.morada);
    printf("\nInsira contacto: ");
    scanf("%ld",&aux_soc.contacto);
    aux_soc.estado=1;
    fwrite(&aux_soc,sizeof(SOCIO),1,fp_soc);
    rewind(stdin);  // para limpar o buffer do teclado
    do
    {
    printf("\nQuer inserir outro Socio?\n\n S-SIM\n N-NAO");
    op=toupper(getch());
    if(op!='S' && op!='N')
    {
      printf("\ntecla nao e valida");
    }
    }
    while(op!='S' && op!='N');
    }
    while(op!='N');
    fclose(fp_soc);
}


/// funcao para modificar a ficha de socio
/// \param nome do socio
/// \param morada
/// \param numero de socio
/// \param data de nascimento
/// \param contacto
int modificar_soc ()
{

    FILE *fp_soc;
    int alterar,teste;
    char op;
    fpos_t filepos;

    system("CLS");
    fp_soc=fopen("socios.txt","r+b");
    if(!fp_soc)
    {
        printf("\n\t Erro de abertura do Ficheiro!!");
        getch();
        return;
    }
    system("cls");
    printf("Qual o numero de socio que quer alterar?");
    scanf("%d",&alterar);
    rewind(fp_soc);
    do
    {
    fgetpos(fp_soc,&filepos);
    teste=fread(&aux_soc,sizeof(SOCIO),1,fp_soc);
    if(teste==1)
    {
        if(aux_soc.num_soc==alterar)
         {

                                               printf("\n\t%d || %s || %s || %ld-%d-%d || %ld",aux_soc.num_soc,aux_soc.nome,aux_soc.morada,aux_soc.dt_nasc,aux_soc.contacto);
                                               printf("Apenas pode ser modificado a morada e o o contacto");
                                               getch();
                                               printf("Prima ENTER para continuar");
                                               system("cls");
                                                do
                                                {
                                                printf("Pretende alterar:\n [A] Morada\n [B] Contacto\n [C] Ambos\n [S] SAIR ");
                                                op=toupper(getch());
                                                switch(op)
                                                {
                                                              case 'A':
                                                                   {

                                                                        printf("\n\nInsira a nova morada:\n");
                                                                        rewind(stdin);
                                                                        gets(aux_soc.morada);
                                                                        fsetpos(fp_soc,&filepos);
                                                                        fwrite(&aux_soc,sizeof(SOCIO),1,fp_soc);
                                                                        fclose(fp_soc);
                                                                        return;
                                                                   }

                                                               case 'B':
                                                                    {
                                                                        printf("\nInsira novo contacto: ");
                                                                        scanf("%ld",&aux_soc.contacto);
                                                                        fsetpos(fp_soc,&filepos);
                                                                        fwrite(&aux_soc,sizeof(SOCIO),1,fp_soc);
                                                                        fclose(fp_soc);
                                                                        return;
                                                                    }

                                                               case 'C':
                                                                    {
                                                                        printf("\n\nInsira a nova morada:\n");
                                                                        rewind(stdin);
                                                                        gets(aux_soc.morada);
                                                                        printf("\nInsira novo contacto: ");
                                                                        scanf("%ld",&aux_soc.contacto);
                                                                        fsetpos(fp_soc,&filepos);
                                                                        fwrite(&aux_soc,sizeof(SOCIO),1,fp_soc);
                                                                        fclose(fp_soc);
                                                                        return;

                                                                    }

                                                               case 'S':
                                                                   {
                                                                    fclose(fp_soc);
                                                                    return;
                                                                   }
               }

       }
        while(op!='S');
   }

}
}
 while(!feof(fp_soc));
    fclose(fp_soc);
}



/// funcao para remover socio
int remover_soc()
{
    FILE *fp_soc;
    char op;
    int n_soc,teste;
    fpos_t filepos;

    system("CLS");
    fp_soc=fopen("socios.txt","r+b");
    if(!fp_soc)
    {
        printf("\n\t Erro de abertura do Ficheiro!!");
        getch();
        return;
    }

    printf("Insira o numero do socio a eliminar: ");
    scanf("%d",&n_soc);
    rewind(fp_soc);
    do
    {
    fgetpos(fp_soc,&filepos);
    teste=fread(&aux_soc,sizeof(SOCIO),1,fp_soc);
    if(teste==1)
    {
        if(aux_soc.num_soc==n_soc)
         {
              aux_soc.estado=0;
              fsetpos(fp_soc,&filepos);
              fwrite(&aux_soc,sizeof(SOCIO),1,fp_soc);
              fclose(fp_soc);
              return;
        }
    }
    }
    while(!feof(fp_soc));
    fclose(fp_soc);
}
