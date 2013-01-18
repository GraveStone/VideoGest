/// funcao que mostra um menu para fazer cada uma das operaçoes: ver, adicionar, remover.
///\param
void menu_filmes()
{
    char op;

    do
    {
        system("CLS");
        printf("\n\n\t\t\tNRM");
        printf("\n\n\t\t\tVideo Gest");
        printf("\nA - Ver lista de filmes");
        printf("\nB - Adicionar filme");
        printf("\nC - Remover filme");
        printf("\nS - Sair");
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
            case 'S': exit(0);
        }
    }
    while(op!='S');
}
