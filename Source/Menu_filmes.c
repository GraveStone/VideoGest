/// funcao que mostra um menu para fazer cada uma das operaçoes: ver, adicionar, remover.
///\param
void menu_filmes()
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
                //ver_lista();
                 printf("\nA - Ver lista de filmes");
                break;
            case 'B':
                inserir_filme();
                break;
            case 'C':
                //remover();
                printf("\nC - Remover filme");
                break;
            case 'S': return;
        }
    }
    while(op!='S');
}
