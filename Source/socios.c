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
    printf("nome: \n morada: \n numero de socio: \n data de nascimento: \n contacto: \n estado:");
    do
    {
     teste=fread(&aux_soc,sizeof(SOCIO),1,fp_ver);
    if(teste==1)
    {
        printf("\n %s\n %s\n %ld\n %ld\n %d",aux_soc.nome,aux_soc.morada,aux_soc.num_soc,aux_soc.dt_nasc,aux_soc.contacto,aux_soc.estado);
    }

    } while (!feof(fp_ver));
 }
 
///funcao para ver que socio existem
///param  
 int socio_existe(long int n_soc)
{
  FILE *fp_soc;
  int teste;

  system("cls");
  fp_fil=fopen("socios.txt","rb");
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
 
/// funcao para adicionar socio
/// \param nome do socio
/// \param morada
/// \param numero de socio
/// \param data de nascimento
/// \param contacto
int adicionar_soc(SOCIOS *soc)
{
    int n;
    long int inserir;
    
    system ("cls");
    printf("Qual o número de sócio que quer inserir? ");
    scanf("%ld",&inserir);
    for(n=1;n<NS;n++)
    {
                     if(soc[n].estado!=1)
                     {
                                         soc[n].num_soc=inserir;
                                         printf("\n Nome do socio: ");
                                         scanf("%s";soc[n].nome);
                                         printf("\n Data de nascimento: ");
                                         scaf("%s",soc[n].dt_nasc);
                                         printf("\n Morada: ");
                                         scanf("%s",soc[n].morada);
                                         printf("\n Contacto: ");
                                         scanf("%ld",soc[n].contacto);
                                         printf("\n\n\n SOCIO ADICIONADO COM SUCESSO!!");
                                         getch();
                                         return(1);
                     }
     printf("ERRO!! NÃO É POSSÍVEL INSERIR SOCIO!");
     getch();
     return(0);                
}
/// funcao para modificar a ficha de socio
/// \param nome do socio
/// \param morada
/// \param numero de socio
/// \param data de nascimento
/// \param contacto
int modificar_soc (SOCIOS *soc)
{
    int n;
    long int alterar;
    char escolha;
    
    system("cls");
    printf("Qual o numero de socio que quer alterar?");
    scanf("%ld",&alterar);
    for(n=1;n<NA;n++)
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
                                                                    {  system("cls")
                                                                       printf("Qual a nova morada?");
                                                                       scanf("%s",soc[n].morada);
                                                                       getch(); return(1);
                                                                       break;
                                                                    }
                                                               case '2':
                                                                    {  system("cls")
                                                                       printf("Qual o novo contacto?");
                                                                       scanf("%ld",soc[n].contacto);
                                                                       getch(); return(1);
                                                                       break;
                                                                    }
                                                               case '3':
                                                                    {  system("cls")
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
/// funcao para remover socio
void remover_soc(SOCIO *soc)
{
     char confere;
     int n;
     long int eliminar;
     
     system("cls");
     printf("Qual o numero de socio que pretende eliminar?");
     scanf("%d",&eliminar);
     for(n=1;n<NA;n++)
     {
                      if(soc[n].num_soc==eliminar)
                      {
                                                 printf("\n Nome:%s\n Data de nascimento:%ld\n Morada:%s\n Contacto:%ld\n",soc[n].nome,soc[n].dt_nasc,soc[n].morada,soc[n].contacto);
                                                 printf("Tem a certeza que pretende eliminar o socio? Sim[S] Nao[N]");
                                                 scanf("%c",&confere);
                                                 if(confere!='S' && confere!='s')
                                                                 return(0)
                                                 else
                                                  {
                                                                 soc[n].estado=0;
                                                                 printf("\n \n SOCIO ELIMMINADO <ENTER para continuar>");
                                                                 getch();
                                                                 return(1);
                                                  }
                      }
     }
     printf("ERRO! SOCIO NÃO ENCONTRADO <ENTER para continuar>");
     getch(); return(0);                                                                                                     
     
 }
/// funcao para gravar no ficheiro
void gravar_ficheiro(SOCIO *soc)
{
     int n;
     FILE *fs;
     
     fs=fopen("socios.txt","w");
     for(n=1;n<NA;n++)
     {
                      if(soc[n].estado==1)
                      fprintf(fs," %d\n %s\n %ld\n %s\n %ld\n",soc[n].num_soc,soc[n].nome,soc[n].dt_nasc,soc[n].morada,soc[n].contacto);
     }
     printf("\n\n GRAVADO COM SUCESSO!!\n<ENTER para continuar>");
     getch(); fclose(fs);                
 }
/// funcao para ler do ficheiro
void ler_ficheiro(SOCIOS *soc)
{
     int n;
     FILE *fs;
     
     if(!(fs=fopen("socios.txt","r")))
	{
		printf("Erro na Abertura de Leitura <Enter para Sair>");
        getch(); exit(0);
	}
	for(n=1;n<NA;n++)
	                 fscanf(fs," %d\n %s\n %ld\n %s\n %ld\n %d",&soc[n].num_soc,&soc[n].nome,&soc[n].dt_nasc,&soc[n].morada,&soc[n].contacto,&soc[n].estado);
	fclose(fa);
	printf("\n\n LIDO COM SUCESSO <Enter para Continuar>");
    getch();return(1)
 }




