#include<stdio.h>
#include<stdlib.h>

void creditos(void);
void menu_princ(void);

void main(void)
{
    creditos();
    system("CLS");
    printf("Prima uma tecla para o ecran seguinte");
    getch();
    menu_princ();
    system("CLS");
    printf("The end");
    getch();
}

void creditos(void)
{
    system("CLS");
    printf("\n\t\t\tUniversidade do Algarve");
    printf("\n\n\t\t    Instituto Superior de Engenharia");
    printf("\n\n\t Licenciatura em Tecnologias da Informacao e Comunicacao");
    printf("\n\n\t   Projecto do Modulo Tematico de Informatica Aplicada ");
    printf("\n\n\n\t\t\t\t   NRM");
    printf("\n\n\n\t\t\t\tVIDEOGEST");
    printf("\n\n\n\tDocentes:\n\tCarlos Marinho\n\tPedro Cardoso \n\n\tTrabalho Realizado por: ");
    printf("\n\tNelson Fernandes \t N. 15390\n");
    printf("\tRita Serra         \t N. 47086\n");
    printf("\tMarta Santos       \t N. 47181\n");
    printf("\n'Prima uma tecla para continuar'");
    getch();
}

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

