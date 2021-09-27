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
    if(fila<=2 or columna<=2)
    {
        if(fila<=2)
        {
            unsigned int green[16],red[16];blue[16];
            for(unsigned int i=1 ; i<= 16 ; i++){
                red[i]=**rojo;
                green[i]=**verde;
                blue[i]=*azul;

            }

        }
        if(columna<=2){
            unsigned int green[16],red[16];blue[16];
            for(unsigned int i=1 ; i<= 16 ; i++){
                red[i]=**rojo;
                green[i]=**verde;
                blue[i]=*azul;
        }

        }

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

