#include "sobremuestreo.h"



sobremuestreo::sobremuestreo(unsigned **erojo, unsigned **everde, unsigned **eazul,unsigned long ffila,unsigned long ccolumna)
{
    rojo=erojo;
    verde=everde;
    azul=eazul;
    fila=ffila;
    columna=ccolumna;

}

void sobremuestreo::sobreproceso(unsigned** matriz)
{
    duplicar(verde,green);
    duplicar(rojo,red);
    duplicar(azul,blue);
    bool salida=true;
    while(salida)
    {
  /*      if()
        {



        }
        else if (columna)
        {

        }*/
    }
}

void sobremuestreo::aumentoX()
{


}

void sobremuestreo::AumentoY()
{

}

void sobremuestreo::dinamica(unsigned **mDimanica,unsigned ffila,unsigned ccolumna)
{
   mDimanica= new unsigned *[ccolumna];
   for(unsigned c=0;c<columna*4;c++)
   {
       mDimanica[c]=new unsigned [ffila];
   }
}

void sobremuestreo::duplicar(unsigned ** matrizE,unsigned ** matrizS)
{

    for(unsigned c=0;c<columna;c=c+2)
    {
        for(unsigned f=0;f<fila;f=f+2)
        {
             =matrizE[c][f];

        }
    }
}
