typedef struct
{
    long int ano;
    int mes, dia;
}
DATA;

typedef struct
{
    unsigned long num_filme, num_socio;
    DATA data_lev, data_ent;
    int dias, estado;
}
ALUGAR;

ALUGAR aux_al;

void aluguer()
{
    FILE *fp_al;
    char op;
    int bissexto;

    system("CLS");
    fp_al=fopen("alugados.txt","a+b");
    if(!fp_al)
    {
        printf("\n\t Erro a criar o Ficheiro!!");
        getch();
        return;
    }
    do
    {
    system("CLS");
    printf("\nFicha de Aluger:");
    printf("\n\nInsira o numero de Socio:");
    scanf("%lu",&aux_al.num_socio);
    printf("\n\nInsira o numero de Filme:");
    scanf("%lu",&aux_al.num_filme);
    printf("\nData:\n\nInsira a DATA formato aaaa-mm-dd:\n\nANO:");
    scanf("%ld",&aux_al.data_lev.ano);
    printf("\n\nInsira o MES:");
    getchar();
    do
    {
     scanf("%d",&aux_al.data_lev.mes);
    }
    while(aux_al.data_lev.mes<=0||aux_al.data_lev.mes>12);
    printf("\n\nInsira o dia:");
    if(aux_al.data_lev.mes==2)
    {
        if ( ( (!(aux_al.data_lev.ano % 4)) && (aux_al.data_lev.ano % 100) ) || (!(aux_al.data_lev.ano % 400)) )
        {
            do
            {
                scanf("%d",&aux_al.data_lev.dia);
            }
            while(aux_al.data_lev.dia<=0||aux_al.data_lev.dia>29);
            bissexto=1;
        }
        else
        {
            do
            {
                scanf("%d",&aux_al.data_lev.dia);
            }
            while(aux_al.data_lev.dia<=0||aux_al.data_lev.dia>28);
            bissexto=0;
        }
    }
    else
    {
        if(aux_al.data_lev.mes==1 || aux_al.data_lev.mes==3 || aux_al.data_lev.mes==5 || aux_al.data_lev.mes==7 || aux_al.data_lev.mes==8 || aux_al.data_lev.mes==10 || aux_al.data_lev.mes==12)
        {
            do
            {
                scanf("%d",&aux_al.data_lev.dia);
            }
            while(aux_al.data_lev.dia<=0||aux_al.data_lev.dia>31);
        }
        else
        {
            do


            {
                scanf("%d",&aux_al.data_lev.dia);
            }
            while(aux_al.data_lev.dia<=0||aux_al.data_lev.dia>30);
        }
    }
    aux_al.estado=1;
    fwrite(&aux_al,sizeof(ALUGAR),1,fp_al);
    rewind(stdin);  // para limpar o buffer do teclado
    printf("Continuar o aluguer");
    op=toupper(getch());
    }
    while(op!='N');
    fclose(fp_al);
}

void devolucao()
{
    FILE *fp_ver;
    int teste,n_reg,dev;

    system("cls");     //clrscr();
    fp_ver=fopen("alugados.txt","r+b");
    if(!fp_ver)
    {
        printf("\n\t Erro na leitura do Ficheiro!!");
        getch();
        return;
    }
    fseek(fp_ver,0L,SEEK_END);
    n_reg=(ftell(fp_ver))/sizeof(ALUGAR);
    rewind(fp_ver);
    if(n_reg==0)
    {
        printf("\n Ficheiro vazio");
        getch();
        fclose(fp_ver);
        return;
    }
    printf("Qual o Numero de Socio para devolucao:");
    scanf("%d",&dev);
    printf("\nN§ filme\tSocio");
    do
    {
        teste=fread(&aux_al,sizeof(ALUGAR),1,fp_ver);
        if(teste==1)
        {
            if(aux_al.num_socio==dev)
            {
               printf("\n%lu\t%lu\t%ld-%d-%d\t%d n_reg %d",aux_al.num_filme,aux_al.num_socio,aux_al.data_lev.ano, aux_al.data_lev.mes, aux_al.data_lev.dia,aux_al.estado,n_reg);
            }

        }
    }
    while(!feof(fp_ver));
    getch();
    fclose(fp_ver);
}

void ver_alugados(void)
 {
  FILE *fp_ver;
  int teste,n_reg;

  system("cls");     //clrscr();
  fp_ver=fopen("alugados.txt","rb");
  if(!fp_ver)
   {
    printf("\n\t Erro na leitura do Ficheiro!!");
    getch();
    return;
   }
  fseek(fp_ver,0L,SEEK_END);
  n_reg=(ftell(fp_ver))/sizeof(ALUGAR);
  rewind(fp_ver);
  if(n_reg==0)
   {
    printf("\n Ficheiro vazio");
    getch();
    fclose(fp_ver);
    return;
   }
  printf("\nN§ filme\tSocio");
  do
   {
    teste=fread(&aux_al,sizeof(ALUGAR),1,fp_ver);
    if(teste==1)
     {
      printf("\n%lu\t%lu\t%ld-%d-%d\t%d n_reg %d",aux_al.num_filme,aux_al.num_socio,aux_al.data_lev.ano, aux_al.data_lev.mes, aux_al.data_lev.dia,aux_al.estado,n_reg);
     }
   }
  while(!feof(fp_ver));
  getch();
  fclose(fp_ver);
}
