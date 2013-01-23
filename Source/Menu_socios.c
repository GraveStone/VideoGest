/// funcao que mostra um menu para fazer cada uma das operaçoes: ver, adicionar, remover.
///\param
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
        printf("\n\t\tC - Remover socio");
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
                //remover();
                printf("Remover socio");
                break;
            case 'S': return;
        }
    }
    while(op!='S');

}
