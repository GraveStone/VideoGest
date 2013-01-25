///\file
///\authors Nelson Fernandes N.º 15390
///\authors Rita Serra       N.º 47086
///\authors Marta Santos     N.º 47181
///\date Jan. 2013
///\version 1.0
///\copyright NRM
///\brief função menu_aluguer() - menu para o aluguer
///\details Função que mostra um menu para fazer cada uma das operações: alugar, devolver, .

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
        printf("\n\t\tC - Historico");
        printf("\n\t\tS - Voltar ao Menu Principal");
        op=toupper(getch());
        switch(op)
        {
            case 'A':
                aluguer();
                printf("Alugar");
                break;
            case 'B':
                devolucao();
                printf("Devolver");
                break;
            case 'C':
                ver_alugados();
                printf("Historico");
                break;
            case 'S':
                return;
        }
    }
    while(op!='S');

}
