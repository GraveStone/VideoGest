///\file
///\authors Nelson Fernandes N.º 15390
///\authors Rita Serra       N.º 47086
///\authors Marta Santos     N.º 47181
///\date Jan. 2013
///\version 1.0
///\copyright NRM
///\brief função menu_filmes() - menu para os filmes
///\details Função que mostra um menu para fazer cada uma das operações: ver, adicionar, remover.

int menu_filmes()
{
    char op;

    do
    {
        system("CLS");
        printf("\n\n\t\t\t     NRM");
        printf("\n\n\t\t\t  Video Gest");
        printf("\n\n\t\t\t Menu Filmes");
        printf("\n\n\t\tA - Ver lista de filmes");
        printf("\n\t\tB - Adicionar filme");
        printf("\n\t\tC - Remover filme");
        printf("\n\t\tS - Voltar ao Menu Principal");
        op=toupper(getch());
        switch(op)
        {
            case 'A':
                 ver_filmes();
                 break;
            case 'B':
                inserir_filme();
                break;
            case 'C':
                apagar_filme();
                break;
            case 'S': return;
        }
    }
    while(op!='S');
}
