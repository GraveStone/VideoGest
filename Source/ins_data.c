
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



