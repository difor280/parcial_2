#include "sobremuestreo.h"


sobremuestreo::sobremuestreo(unsigned **erojo, unsigned **everde, unsigned **eazul,unsigned long ffila,unsigned long ccolumna)
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

void sobremuestreo::sobreproceso()
{
    if(fila<=2 or columna<=2)
    {
        if(fila<=2)
        {
           dinamicaI(fila*2,columna);
            for(unsigned int c=0 ; c<columna ; c++)
            {
                for(unsigned int f=0 ; f< fila*2 ; f=f+2)
                {
                    green[c][f]=verde[c][f/2];
                    green[c][f+1]=verde[c][f/2];
                    blue[c][f]=azul[c][f/2];
                    blue[c][f+1]=azul[c][f/2];
                    red[c][f]=rojo[c][f/2];
                    red[c][f+1]=rojo[c][f/2];

                }
            }
            fila=fila*2;
            dinamicaE(fila, columna);
            azul=blue;
            verde=green;
            rojo=red;

        }
        if(columna<=2)
        {
             dinamicaI(fila,columna*2);
             for(unsigned int c=0 ; c<columna*2 ; c=c+2)
             {
                 for(unsigned int f=0 ; f< fila ; f++)
                 {
                     green[c][f]=verde[c/2][f];
                     green[c+1][f]=verde[c/2][f];
                     blue[c][f]=azul[c/2][f];
                     blue[c+1][f]=azul[c/2][f];
                     red[c][f]=rojo[c/2][f];
                     red[c+1][f]=rojo[c/2][f];

                 }
             }
             columna=columna*2;
             dinamicaE(fila, columna);
             azul=blue;
             verde=green;
             rojo=red;
        }


    }

    aumentoY();


}





void sobremuestreo::dinamicaI(unsigned ffila,unsigned ccolumna)
{


   blue= new unsigned *[ccolumna];
   green= new unsigned *[ccolumna];
   red= new unsigned *[ccolumna];

   for(unsigned c=0;c<ccolumna;c++)
   {
       blue[c]=new unsigned [ffila];
       green[c]=new unsigned [ffila];
       red[c]=new unsigned [ffila];
   }
}

void sobremuestreo::dinamicaE(unsigned ffila, unsigned ccolumna)
{


    azul= new unsigned *[ccolumna];
    verde= new unsigned *[ccolumna];
    rojo= new unsigned *[ccolumna];

    for(unsigned c=0;c<ccolumna;c++)
    {
        azul[c]=new unsigned [ffila];
        verde[c]=new unsigned [ffila];
        rojo[c]=new unsigned [ffila];
    }
}

void sobremuestreo::aumentoY()
{
    while (true)
    {
        unsigned int creciente=3, guardarcolumna=0;

        for(unsigned fc=0,c=0; c<columna ; c++,fc++)
        {
            guardarcolumna=guardarcolumna+1;
            if(fc==round(columna/creciente)-1 and guardarcolumna<16)
            {
                guardarcolumna=guardarcolumna+1;
                unsigned **g=green,**b=blue,**r=red;
                rellenar(guardarcolumna+3,fila,g,b,r);
            }
            for(unsigned f=0 ; f<fila ; f++)
            {

                 if(fc==round(columna/creciente)-1 and c != columna-1 and guardarcolumna<16 and columna!=16)
                 {
                     green[guardarcolumna-1][f]=verde[c][f];
                     blue[guardarcolumna-1][f]=azul[c][f];
                     red[guardarcolumna-1][f]=red[c][f];

                     green[guardarcolumna][f]=verde[c][f]+(((verde[c][f+1]-verde[c][f])/((f+2)-c))*((c+1)-c));
                     blue[guardarcolumna][f]=azul[c][f]+(((azul[c+1][f]-azul[c][f])/((c+2)-c))*((c+1)-c));
                     red[guardarcolumna][f]=rojo[c][f]+(((rojo[c+1][f]-rojo[c][f])/((c+2)-c))*((c+1)-c));


                 }
                 else if(fc!=round(columna/creciente)-1)
                 {
                     green[guardarcolumna][f]=verde[c][f];
                     blue[guardarcolumna][f]=azul[c][f];
                     red[guardarcolumna][f]=red[c][f];
                 }


            }

            if(fc==round(columna/creciente))
            {
                fc=0;
            }
        }

        columna=guardarcolumna;
        guardarcolumna=0;
        if(fila==16 and columna==16)    break;
        verde=green;
        rojo=red;
        azul=blue;
        creciente++;

    }
}

void sobremuestreo::aumentoX()
{

}

unsigned **sobremuestreo::mostrarverde()
{
    return verde;
}

unsigned **sobremuestreo::mostrarrojo()
{
    return rojo;
}

unsigned **sobremuestreo::mostrarazul()
{
    return azul;
}

void sobremuestreo::rellenar( unsigned mc, unsigned mf, unsigned **matriz1, unsigned **matriz2, unsigned **matriz3)
{
    dinamicaI(mf, mc);
    for(unsigned c=0 ; c<mc -3; c++)
    {
        for(unsigned f=0 ; f<mf-3; f++)
        {
            green[c][f]=matriz1[c][f];
            blue[c][f]=matriz2[c][f];
            red[c][f]=matriz3[c][f];
        }
    }
}

