///\file
///\brief Função ins_data() - Insere a data no formato AAAA-MM-DD.
///\details Função implementada para inserção da data no formato AAAA-MM-DD.
///\authors Nelson Fernandes N.º 15390
///\authors Rita Serra       N.º 47086
///\authors Marta Santos     N.º 47181
///\date Jan. 2013
///\version 1.0
///\copyright NRM


///\brief Função para criar uma data
///\details Esta função tem como objectivo de inserir a data quando é solicitada retornando a data por meio de Apontadores.
///\param *year Apontador do tipo long int usado para devolver o ano.
///\param *month Apontador do tipo int usado para devolver o mês.
///\param *day Apontador do tipo int usado para devolver o dia.
///\return Retorna a data por meio de Apontadores.
int ins_data (long int *year, int *month, int *day)
{
    int bissexto,mon,da;
    long int an;

    scanf("%ld",&an);
    printf("\n\nInsira o MES:");
    *year=an;
    getchar();
    do
    {
     scanf("%d",&mon);
    }
    while(mon<=0||mon>12);
    printf("\n\nInsira o dia:");
    if(mon==2)
    {
        if ( ( (!(an % 4)) && (an % 100) ) || (!(an % 400)) )
        {
            do
            {
                scanf("%d",&da);
            }
            while(da<=0||da>29);
            bissexto=1;
        }
        else
        {
            do
            {
                scanf("%d",&da);
            }
            while(da<=0||da>28);
            bissexto=0;
        }
    }
    else
    {
        if(mon==1 || mon==3 || mon==5 || mon==7 || mon==8 || mon==10 || mon==12)
        {
            do
            {
                scanf("%d",&da);
            }
            while(da<=0||da>31);
        }
        else
        {
            do
            {
                scanf("%d",&da);
            }
            while(da<=0||da>30);
        }
    }
*day=da;
*month=mon;
}



