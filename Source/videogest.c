#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
#include"creditos.c"
#include"menu_princ.c"
#include"menu_aluguer.c"
#include"Menu_socios.c"
#include"Menu_filmes.c"
#include"aluguer.c"
#include"socios.c"
#include"filmes.c"

void main(void)
{
    creditos();
    system("CLS");
    menu_princ();
    system("CLS");
    printf("The end");
    getch();
}

