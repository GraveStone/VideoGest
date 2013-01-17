void menu_princ(void)
{
    char op;

    do
    {
        system("CLS");
        printf("\n\n\t\t\tNRM");
        printf("\n\n\t\t\tVideo Gest");
        printf("\nA - Socios");
        printf("\nB - Filmes");
        printf("\nC - Alugueres");
        printf("\nS - Sair");
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
