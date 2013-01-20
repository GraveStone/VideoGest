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
