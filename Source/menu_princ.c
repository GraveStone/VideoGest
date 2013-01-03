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
                printf("Socios");
                break;
            case 'B':
                printf("Filmes");
                break;
            case 'C':
                printf("Alugueres");
                break;
            case 'S': exit(0);
        }
    }
    while(op!='S');

}
