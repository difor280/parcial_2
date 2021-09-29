#include "submuestreo.h"

submuestreo::submuestreo(unsigned**erojo,unsigned**everde,unsigned**eazul,unsigned long ffila,unsigned long ccolumna)
{
    rojo=erojo;
    verde=everde;
    azul=eazul;
    fila=ffila;
    green= new unsigned*;
    blue =new unsigned*;
    red= new unsigned*;
    columna=ccolumna;
}
