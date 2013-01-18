void menu_aluguer(void)
{
    char op;

    do
    {
        system("CLS");
        printf("\n\n\t\t\tNRM");
        printf("\n\n\t\t\tVideo Gest");
        printf("\nA - Alugar");
        printf("\nB - Devolver");
        printf("\nC - Historico");
        printf("\nS - Sair");
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
