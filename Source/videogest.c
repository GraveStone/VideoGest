#include<stdio.h>
#include<stdlib.h>
#include"creditos.c"
#include"menu_princ.c"

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

