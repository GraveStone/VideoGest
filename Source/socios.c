#define Mnome 50
#define Mmorada 50
#define NS 150 ///Define uma variavel global NS que é o numero total de sócios que o programa pode guardar
/// Cria uma estrutura com os dados dos sócios
typedef struct
{
 char nome[Mnome];
 char morada[Mmorada];
 int num_soc;
 long int dt_nasc;
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
    printf("numero de socio \tnome: \t morada \t data de nascimento: \t contacto: \t estado:");
    do
    {
     teste=fread(&aux_soc,sizeof(SOCIO),1,fp_ver);
    if(teste==1)
    {
    if(aux_soc.estado==1)
    {
        printf("\n%d\t%s\t%s\t%ld\t%ld\t%d",aux_soc.num_soc,aux_soc.nome,aux_soc.morada,aux_soc.dt_nasc,aux_soc.contacto,aux_soc.estado);
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
int adicionar_soc(SOCIO *soc)
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
    printf("\nInserir data de nascimento: ");
    scanf("%ld",&aux_soc.dt_nasc);
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
int modificar_soc (SOCIO *soc)
{
    int n;
    long int alterar;
    char escolha;

    system("cls");
    printf("Qual o numero de socio que quer alterar?");
    scanf("%ld",&alterar);
    for(n=1;n<NS;n++)
    {
                     if(soc[n].num_soc==alterar)
                     {
                                                printf("\n Nome:%s\n Data de nascimento:%ld\n Morada:%s\n Contacto:%ld\n",soc[n].nome,soc[n].dt_nasc,soc[n].morada,soc[n].contacto);
                                                printf("Apenas pode ser modificado a morada e o o contacto");getch(); printf("Prima ENTER para continuar");
                                                system("cls");
                                                printf("Pretende alterar:\n [1]Morada\n [2]Contacto\n [3]Ambos\n [S]SAIR ");
                                                scanf("%c",&escolha);
                                                switch(escolha)
                                                {
                                                               case '1':
                                                                    {  system("cls");
                                                                       printf("Qual a nova morada?");
                                                                       scanf("%s",soc[n].morada);
                                                                       getch(); return(1);
                                                                       break;
                                                                    }
                                                               case '2':
                                                                    {  system("cls");
                                                                       printf("Qual o novo contacto?");
                                                                       scanf("%ld",soc[n].contacto);
                                                                       getch(); return(1);
                                                                       break;
                                                                    }
                                                               case '3':
                                                                    {  system("cls");
                                                                       printf("Qual a nova morada?");
                                                                       scanf("%s",soc[n].morada);
                                                                       printf("Qual o novo contacto?");
                                                                       scanf("%ld",soc[n].contacto);
                                                                       getch(); return(1);
                                                                       break;
                                                                    }
                                                               case 's': case 'S': exit(0);
                                                               }
               }
     printf("ERRO!! NUMERO DE SOCIO NAO ENCONTRADO!"); getch(); return(0);


}
}
/// funcao para remover socio
int remover_soc(SOCIO *soc)
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

/// funcao para gravar no ficheiro
void gravar_ficheiro(SOCIO *soc)
{
     int n;
     FILE *fs;

     fs=fopen("socios.txt","w");
     for(n=1;n<NS;n++)
     {
                      if(soc[n].estado==1)
                      fprintf(fs," %d\n %s\n %ld\n %s\n %ld\n",soc[n].num_soc,soc[n].nome,soc[n].dt_nasc,soc[n].morada,soc[n].contacto);
     }
     printf("\n\n GRAVADO COM SUCESSO!!\n<ENTER para continuar>");
     getch(); fclose(fs);
 }
/// funcao para ler do ficheiro
int ler_ficheiro(SOCIO *soc)
{
     int n;
     FILE *fs;

     if(!(fs=fopen("socios.txt","r")))
	{
		printf("Erro na Abertura de Leitura <Enter para Sair>");
        getch(); exit(0);
	}
	for(n=1;n<NS;n++)
	                 fscanf(fs," %d\n %s\n %ld\n %s\n %ld\n %d",&soc[n].num_soc,&soc[n].nome,&soc[n].dt_nasc,&soc[n].morada,&soc[n].contacto,&soc[n].estado);
	fclose(fs);
	printf("\n\n LIDO COM SUCESSO <Enter para Continuar>");
    getch();return(1);
 }




