typedef struct
{
    long int ano;
    int mes, dia;
}
DATA;

typedef struct
{
    int num_filme, num_socio;
    DATA data_lev, data_ent;
    int estado;
    long int dias;
}
ALUGAR;

ALUGAR aux_al;

int aluguer()
{
    FILE *fp_al;
    char op;
    int bissexto, teste, a, b;
    int n_filme, n_socio;

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
    scanf("%d",&n_socio);
    do
    {
       a=socio_existe(n_socio);
       if(a==0)
       {
        printf("\n\nNumero não valido insira novo numero de Socio:");
        scanf("%d",&n_socio);
       }
       else
       {
        aux_al.num_socio=n_socio;
       }
    }
    while(aux_al.num_socio!=n_socio);
    printf("\n\nInsira o numero de Filme:");
    scanf("%d",&n_filme);
    do
    {
       b=filme_existe(n_filme);
       if(b==0)
       {
        printf("\n\nNumero não valido insira novo numero de Filme:");
        scanf("%d",&n_filme);
       }
       else
       {
        aux_al.num_filme=n_filme;
       }
    }
    while(aux_al.num_filme!=n_filme);
    printf("\nData:\n\nInsira a DATA de Aluguer formato aaaa-mm-dd:\n\nANO:");
    ins_data(&aux_al.data_lev.ano,&aux_al.data_lev.mes,&aux_al.data_lev.dia);
    aux_al.estado=1;
    fwrite(&aux_al,sizeof(ALUGAR),1,fp_al);
    rewind(stdin);
    do
    {
    printf("\nQuer Alugar outro filme?\n\n S-SIM\n N-NAO");
    op=toupper(getch());
    if(op!='S' && op!='N')
    {
      printf("\ntecla nao e valida");
    }
    }
    while(op!='S' && op!='N');
    }
    while(op!='N');
    fclose(fp_al);
}

int devolucao()
{
    FILE *fp_ver;
    int teste,n_reg,dev, bissexto;
    fpos_t filepos;

    system("cls");
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
               printf("\n%d\t%d\t%ld-%d-%d\t%d n_reg %d",aux_al.num_filme,aux_al.num_socio,aux_al.data_lev.ano, aux_al.data_lev.mes, aux_al.data_lev.dia,aux_al.estado,n_reg);
            }
        }
    }
    while(!feof(fp_ver));
    rewind(fp_ver);
    printf("Qual o Numero de filme para devolucao:");
    scanf("%d",&dev);
    printf("\nN§ filme\tSocio");
    do
    {
        fgetpos(fp_ver,&filepos);
        teste=fread(&aux_al,sizeof(ALUGAR),1,fp_ver);
        if(teste==1)
        {
            if(aux_al.num_filme==dev)
            {
                printf("\nData:\n\nInsira a DATA devolução formato aaaa-mm-dd:\n\nANO:");
                ins_data(&aux_al.data_ent.ano,&aux_al.data_ent.mes,&aux_al.data_ent.dia);
                aux_al.dias=num_dias(aux_al.data_lev.ano,aux_al.data_ent.ano,aux_al.data_lev.mes,aux_al.data_ent.mes,aux_al.data_lev.dia,aux_al.data_ent.dia);
                aux_al.estado=0;
                fsetpos(fp_ver,&filepos);
                fwrite(&aux_al,sizeof(ALUGAR),1,fp_ver);
                printf("\n%d\t%d\t%ld-%d-%d\t%d n_reg %ld",aux_al.num_filme,aux_al.num_socio,aux_al.data_lev.ano, aux_al.data_lev.mes, aux_al.data_lev.dia,aux_al.estado,aux_al.dias);
                fclose(fp_ver);
                getch();
                return;
            }
        }
    }
    while(!feof(fp_ver));
    getch();
    fclose(fp_ver);
}

int ver_alugados(void)
 {
  FILE *fp_ver;
  int teste,n_reg;

  system("cls");
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
      printf("\n%d\t%d\t%ld-%d-%d\t%d n_reg %ld",aux_al.num_filme,aux_al.num_socio,aux_al.data_lev.ano, aux_al.data_lev.mes, aux_al.data_lev.dia,aux_al.estado,aux_al.dias);
     }
   }
  while(!feof(fp_ver));
  getch();
  fclose(fp_ver);
}
