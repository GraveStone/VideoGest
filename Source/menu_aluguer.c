///\file
///\brief Função menu_aluguer() - menu para o aluguer
///\details Função que mostra um menu para fazer cada uma das operações: alugar, devolver, .
///\authors Nelson Fernandes N.º 15390
///\authors Rita Serra       N.º 47086
///\authors Marta Santos     N.º 47181
///\date Jan. 2013
///\version 1.0
///\copyright NRM


///\brief Função que mostra Menu para o aluguer
///\details Esta função mostra no ecran um menu  com algumas opeçoes de operação relacionadas com o aluguer: alugar, devolver,...
int menu_aluguer(void)
{
    char op;

    do
    {
        system("CLS");
        printf("\n\n\t\t\t     NRM");
        printf("\n\n\t\t\t  Video Gest");
        printf("\n\n\t\t\t Menu aluguer");
        printf("\n\n\t\tA - Alugar");
        printf("\n\t\tB - Devolver");
        printf("\n\t\tC - Ver filmes Alugados ou Devolvidos");
        printf("\n\t\tD - Ver os filmes disponiveis");
        printf("\n\t\tS - Voltar ao Menu Principal");
        op=toupper(getch());
        switch(op)
        {
            case 'A':
                aluguer();
                break;
            case 'B':
                devolucao();
                break;
            case 'C':
                ver_alugados();
                break;
            case 'D':
                ver_filmes_dis();
                break;
            case 'S':
                return;
        }
    }
    while(op!='S');

}
