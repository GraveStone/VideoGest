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

///\file
///\brief VideoGest - Gest�o de videoclube
///\details VideoGest - programa de gest�o de videoclube para gerir os socios, filmes e alugueres
///\authors Nelson Fernandes N.� 15390
///\authors Rita Serra       N.� 47086
///\authors Marta Santos     N.� 47181
///\date Jan. 2013
///\version 1.0
///\copyright NRM

///\brief main() nesta fun��o � iniciado o programa com a chamada das fun��es creditos() e menu_princ()

int main()
{
    creditos();
    system("CLS");
    menu_princ();
    system("CLS");
    printf("The end");
    getch();
}

