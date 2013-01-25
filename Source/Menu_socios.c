
///\file
///\authors Nelson Fernandes N.º 15390
///\authors Rita Serra       N.º 47086
///\authors Marta Santos     N.º 47181
///\date Jan. 2013
///\version 1.0
///\copyright NRM
///\brief função menu_socios() - menu para os Sócios
///\details Função que mostra um menu para fazer cada uma das operações: alugar, devolver, remover .

int menu_socios()
{
    char op;

    do
    {
        system("CLS");
         printf("\n\n\t\t\t     NRM");
        printf("\n\n\t\t\t  Video Gest");
        printf("\n\n\t\t\t Menu Socios");
        printf("\n\n\t\tA - Ver lista de socios");
        printf("\n\t\tB - Adicionar socio");
        printf("\n\t\tC - Modificar socio");
        printf("\n\t\tD - Remover socio");
        printf("\n\t\tS - Voltar ao Menu Principal");
        op=toupper(getch());
        switch(op)
        {
            case 'A':
                ver_lista();
                printf("Lista de socios");
                break;
            case 'B':
                adicionar_soc();
                printf("Adicionar socio");
                break;
            case 'C':
                modificar_soc();
                printf("Modificar socio");
                break;
            case 'D':
                remover_soc();
                printf("Remover socio");
                break;
            case 'S': return;
        }
    }
    while(op!='S');

}
