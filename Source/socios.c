#define Mnome 50
#define Mmorada 50
/// Cria uma estrutura com os dados dos sócios
typedef struct
{
 char nome[Mnome];
 char morada[Mmorada];
 int num_soc;
 int dt_nasc;
 long int contacto;
 int estado;
}SOCIO;

SOCIO aux_soc;
/// funcao para mostrar a lista de socios
/// param ficheiro Socios, estutura Socios
void ver_lista()
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
        printf("\n %s\n %s\n %d\n %n\n %d",aux_soc.nome,aux_soc.morada,aux_soc.num_soc,aux_soc.dt_nasc,aux_soc.contacto,aux_soc.estado);
    }

    } while (!feof(fp_ver));
 }
/// funcao para adicionar socio
/// \param nome do socio
/// \param morada
/// \param numero de socio
/// \param data de nascimento
/// \param contacto
int adicionar(char nome[Mnome], char morada [Mmorada], int num_soc, int dt_nasc, int contacto, int estado)
{
}
/// funcao para modificar a ficha de socio
/// \param nome do socio
/// \param morada
/// \param numero de socio
/// \param data de nascimento
/// \param contacto
int modificar (char nome[Mnome],char morada [Mmorada],int num_soc,int dt_nasc,int contacto,int estado)
{
}
/// funcao para remover socio
void remover()
{
 }
/// funcao para gravar no ficheiro
void gravar_ficheiro()
{
 }
/// funcao para ler do ficheiro
void ler_ficheiro()
{
 }




