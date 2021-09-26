#include "sobremuestreo.h"



sobremuestreo::sobremuestreo(unsigned **erojo, unsigned **everde, unsigned **eazul,unsigned long fila,unsigned long columna)
{
    rojo=erojo;
    verde=everde;
    azul=eazul;
    ffila=fila;
    ccolumna=columna;

}

void sobremuestreo::sobreproceso(unsigned** matriz)
{
    if(ffila==1 || ccolumna==1)
    {
        ;
    }

}

