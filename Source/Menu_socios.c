/// funcao que mostra um menu para fazer cada uma das operaçoes: ver, adicionar, remover.
///\param 
int menu_socios()
{
    char op;

    do
    {
        system("CLS");
        printf("\n\n\t\t\tNRM");
        printf("\n\n\t\t\tVideo Gest");
        printf("\nA - Ver lista de socios");
        printf("\nB - Adicionar socio");
        printf("\nC - Remover socio");
        printf("\nS - Sair");
        op=toupper(getch());
        switch(op)
        {
            case 'A':
                ver_lista();
                printf("Lista de socios");
                break;
            case 'B':
                adicionar();
                printf("Adicionar socio");
                break;
            case 'C':
                remover();
                printf("Remover socio");
                break;
            case 'S': exit(0);
        }
    }
    while(op!='S');

} 
