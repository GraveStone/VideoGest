///\file
///\brief função menu_aluguer()- menu para o aluguer
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
