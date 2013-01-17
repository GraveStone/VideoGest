#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<ctype.h>
#include"creditos.c"
#include"menu_princ.c"
#include"menu_aluguer.c"
#include"Menu_socios.c"
#include"aluguer.c"
#include"socios.c"

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

