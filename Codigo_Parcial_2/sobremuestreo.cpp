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
    aumentoX();


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
     unsigned int creciente=3, guardarcolumna=0;
    while (true)
    {


        for(unsigned fc=0,c=0; c<columna and guardarcolumna<16 ; c++,fc++)
        {

            if(fc>round(columna/creciente) and guardarcolumna<16)
            {
                guardarcolumna=guardarcolumna+1;

            }
            unsigned **g=green,**b=blue,**r=red;
            rellenar(guardarcolumna+1,fila,fila,guardarcolumna,g,b,r);

            for(unsigned f=0 ; f<fila  and guardarcolumna<=16; f++)
            {
                unsigned a;
                 if(fc>round(columna/creciente) and c != columna-1 and guardarcolumna<16 and columna!=16)
                 {
                     a=verde[c][f];
                     green[guardarcolumna-1][f]=verde[c][f];
                     a=azul[c][f];
                     blue[guardarcolumna-1][f]=azul[c][f];
                     a=rojo[c][f];
                     red[guardarcolumna-1][f]=rojo[c][f];

                     green[guardarcolumna][f]=((verde[c+1][f]+verde[c][f])/2);
                     a=green[guardarcolumna][f];
                     blue[guardarcolumna][f]=(((azul[c+1][f]+azul[c][f])/2));
                     a=blue[guardarcolumna][f];
                     red[guardarcolumna][f]=((rojo[c+1][f]+rojo[c][f])/2);
                     a=red[guardarcolumna][f];


                 }
                 else if(fc<=round(columna/creciente) and guardarcolumna<16 and columna!=16)
                 {
                     green[guardarcolumna][f]=verde[c][f];
                     blue[guardarcolumna][f]=azul[c][f];
                     red[guardarcolumna][f]=rojo[c][f];
                 }


            }
            guardarcolumna=guardarcolumna+1;
            if(fc>round(columna/creciente))
            {
                fc=0;
            }
        }

        columna=guardarcolumna;
        guardarcolumna=0;
        if( columna==16)    break;
        verde=green;
        rojo=red;
        azul=blue;
        creciente++;


    }
}

void sobremuestreo::aumentoX()
{
    while (true)
    {
        unsigned int creciente=3, guardarfila=0;

        for(unsigned fc=0,c=0; c<fila  and guardarfila< 16; c++,fc++)
        {
            guardarfila=guardarfila+1;
            if(fc>=round(fila/creciente) and guardarfila<16)
            {
                guardarfila=guardarfila+1;
            }
             unsigned **g=green,**b=blue,**r=red;
            rellenar(columna,guardarfila,guardarfila-1,columna,g,b,r);

            for(unsigned f=0 ; f<columna  and guardarfila<16; f++)
            {

                 if(fc>=round(fila/creciente) and c != fila-1 and guardarfila<16 and fila!=16)
                 {
                     green[c][guardarfila-1]=verde[c][f];
                     blue[c][guardarfila-1]=azul[c][f];
                     red[c][guardarfila-1]=red[c][f];

                     green[c][guardarfila]=((verde[c][f+1]+verde[c][f])/2);
                     blue[c][guardarfila]=((azul[c][f+1]+azul[c][f])/2);
                     red[c][guardarfila]=(((rojo[c][f+1]+rojo[c][f])/2));


                 }
                 else if(fc<=round(fila/creciente) and guardarfila<16 and fila!=16)
                 {
                     green[c][guardarfila]=verde[c][f];
                     blue[c][guardarfila]=azul[c][f];
                     red[c][guardarfila]=red[c][f];
                 }


            }

            if(fc>=round(fila/creciente))
            {
                fc=0;
            }
        }

        fila=guardarfila;
        guardarfila=0;
        if(fila==16 )    break;
        verde=green;
        rojo=red;
        azul=blue;
        creciente++;

    }
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

void sobremuestreo::rellenar( unsigned mc, unsigned mf, unsigned fc,unsigned cc, unsigned **matriz1, unsigned **matriz2, unsigned **matriz3)
{
    dinamicaI(mf, mc);
    for(unsigned c=0 ; c<cc ; c++)
    {
        for(unsigned f=0 ; f<fc; f++)
        {
            green[c][f]=matriz1[c][f];
            blue[c][f]=matriz2[c][f];
            red[c][f]=matriz3[c][f];
        }
    }
}

