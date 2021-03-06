///\file
///\brief Função num_dias() - para calcular o numero de dias entre duas datas
///\details Função que permite calcular os numeros de dias entre duas datas e devolve o numero de dias.
///\details tem como parametros de entrada a data inicial e a data final e devolve o numero de dias
///\authors Nelson Fernandes N.º 15390
///\authors Rita Serra       N.º 47086
///\authors Marta Santos     N.º 47181
///\date Jan. 2013
///\version 1.0
///\copyright NRM

///\brief Função que calcula o numero de dias entre duas datas.
///\details Esta função foi criada para  calcular o numero de dias entre duas datas.
///\param ano_lev  ano_lev é o ano de levantamento do filme
///\param ano_dev  ano_dev é o ano de devolução do filme
///\param mes_lev  mes_lev é o mes de levantamento do filme
///\param mes_dev  mes_dev é o mes de devolução do filme
///\param dia_lev  dia_lev é o dia de levantamento do filme
///\param dia_dev  dia_dev é o dia de devolução do filme
///\return O numero de dias entre as duas datas
int num_dias(long int ano_lev, long int ano_dev, int mes_lev, int mes_dev, int dia_lev, int dia_dev)
{
 int tab365[12]={31,28,31,30,31,30,31,31,30,31,30,31};
 int tab366[12]={31,29,31,30,31,30,31,31,30,31,30,31};
 int i,b,c;
 long int a, temp=0;

for(a=ano_lev;a<=ano_dev;a++)
{
if(a!=ano_dev)
{
  if(a==ano_lev)
  {
    b=mes_lev;
    c=12;
  }
  else
  {
    b=1;
    c=12;
  }
}
else
{
    b=1;
    c=mes_dev;
}
for(i=b;i<=c;i++)
{
    if ( ( (!(a % 4)) && (a % 100) ) || (!(a % 400)) )
    {
    if(ano_lev==ano_dev)
    {
      if(mes_lev<=mes_dev)
      {
        temp=tab366[i-1]+temp;
      }
    }
    else
    {
      temp=tab366[i-1]+temp;
    }
  }
  else
  {
     if(ano_lev==ano_dev)
    {
      if(mes_lev<=mes_dev)
      {
          temp=tab365[i-1]+temp;
      }
    }
    else
    {
      temp=tab365[i-1]+temp;
    }
  }
}
}
if ( ( (!(ano_dev % 4)) && (ano_dev % 100) ) || (!(ano_dev % 400)) )
{
    temp=temp+dia_dev-tab366[mes_dev-1]-dia_lev;
}
else
{
    temp=temp+dia_dev-tab365[mes_dev-1]-dia_lev;
}
return temp;
}
