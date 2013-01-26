/// Cria uma estrutura para guardar uma Data.
typedef struct
{
/// O Ano da Data.
    long int ano;
/// O Mês da Data.
    int mes;
/// O Dia da Data.
    int dia;
}
DATA;

///\file
///\brief Função menu_princ() - Menu principal do programa.
///\details A função menu_princ() permite-nos ir para os menus dos Sócios, Filmes, Alugueres e Sair do programa.
///\authors Nelson Fernandes N.º 15390
///\authors Rita Serra       N.º 47086
///\authors Marta Santos     N.º 47181
///\date Jan. 2013
///\version 1.0
///\copyright NRM


///\brief Função que mostra o Menu principal do programa.
///\details Esta função lista no ecran as opções disponiveis epermite-nos ir para os menus dos Sócios, Filmes, Alugueres e Sair do programa.
void menu_princ(void)
{
    char op;

    do
    {
        system("CLS");
        printf("\n\n\t\t\t     NRM");
        printf("\n\n\t\t\t  Video Gest");
        printf("\n\n\t\t\tMenu Principal");
        printf("\n\n\t\tA - Socios");
        printf("\n\t\tB - Filmes");
        printf("\n\t\tC - Alugueres");
        printf("\n\t\tS - Sair");
        op=toupper(getch());
        switch(op)
        {
            case 'A':
                menu_socios();
                printf("Socios");
                break;
            case 'B':
                menu_filmes();
                printf("Filmes");
                break;
            case 'C':
                menu_aluguer();
                printf("Alugueres");
                break;
            case 'S': exit(0);
        }
    }
    while(op!='S');

}
