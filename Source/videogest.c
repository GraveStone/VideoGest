///\file
///\brief VideoGest - Gestão de videoclube ficheiro principal para execução do programa.
///\details VideoGest - programa de gestão de videoclube para gerir os socios, filmes e alugueres.
///\authors Nelson Fernandes N.º 15390
///\authors Rita Serra       N.º 47086
///\authors Marta Santos     N.º 47181
///\date Jan. 2013
///\version 1.0
///\copyright NRM
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
#include"calculo_dias.c"
#include"ins_data.c"

///\brief Função principal para execução do programa.
///\details Nesta função é iniciado o programa com a chamada das funções creditos() e menu_princ().
int main()
{
    creditos();
    system("CLS");
    menu_princ();
    system("CLS");
    printf("The end");
    getch();
}
