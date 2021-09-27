#include "sobremuestreo.h"


sobremuestreo::sobremuestreo(unsigned **erojo, unsigned **everde, unsigned **eazul,unsigned long ffila,unsigned long ccolumna)
{
    rojo=erojo;
    verde=everde;
    azul=eazul;
    fila=ffila;
    columna=ccolumna;

}

void sobremuestreo::sobreproceso()
{
    if(fila<=2 or columna<=2)
    {
        if(fila<=2)
        {
           dinamicaI(fila*2,columna);
            for(unsigned int c=0 ; c<=columna ; c++)
            {
                for(unsigned int f=0 ; f<= fila*2 ; f=f+2)
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
             for(unsigned int c=0 ; c<=columna*2 ; c++)
             {
                 for(unsigned int f=0 ; f<= fila ; f++)
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
    unsigned int creciente=3,guardarfilas=0, guardarcolumna=0;

    while (true)
    {
        for(unsigned c=0,co=0; c<columna ; c++,co++)
        {
            if(co==round(columna/creciente))
            {
                guardarcolumna=guardarcolumna+1;
            }
            for(unsigned d=0,f=0 ; f<=fila and guardarfilas<16  ; d++,f++)
            {
                 guardarfilas=guardarfilas+1;
                 if(d==round(fila/creciente))
                 {
                    guardarfilas=guardarfilas+1;
                    rellenar(f,c,guardarcolumna,guardarfilas,green,blue,red);

                    green[c][guardarfilas-1]=verde[c][f];
                    blue[c][guardarfilas-1]=azul[c][f];
                    red[c][guardarfilas-1]=red[c][f];

                    green[c][guardarfilas]=verde[c][f]+(((verde[c][f+1]-verde[c][f])/((f+2)-f))*((f+1)-f));
                    blue[c][guardarfilas]=azul[c][f]+(((azul[c][f+1]-azul[c][f])/((f+2)-f))*((f+1)-f));
                    red[c][guardarfilas]=rojo[c][f]+(((rojo[c][f+1]-rojo[c][f])/((f+2)-f))*((f+1)-f));
                    d=0;

                 }
                 if(co==round(columna/creciente))
                 {
                     guardarcolumna=guardarcolumna+1;
                     rellenar(f,c,guardarcolumna,guardarfilas,green,blue,red);
                     green[guardarcolumna-1][f]=verde[c][f];
                     blue[guardarcolumna-1][f]=azul[c][f];
                     red[guardarcolumna-1][f]=red[c][f];

                     green[guardarcolumna][f]=verde[c][f]+(((verde[c+1][f]-verde[c][f])/((c+2)-c))*((c+1)-c));
                     blue[guardarcolumna][f]=azul[c][f]+(((azul[c+1][f]-azul[c][f])/((c+2)-c))*((c+1)-c));
                     red[guardarcolumna][f]=rojo[c][f]+(((rojo[c+1][f]-rojo[c][f])/((c+2)-c))*((c+1)-c));

                 }

            }
            fila=guardarfilas;
            guardarfilas=0;
            if(co==round(columna/creciente))
            {
                co=0;
            }
        }
        guardarcolumna=0;
        if(fila==16 and columna==16)    break;
    }

}





void sobremuestreo::dinamicaI(unsigned ffila,unsigned ccolumna)
{
   delete green;
   delete blue;
   delete red;

   blue= new unsigned *[ccolumna];
   green= new unsigned *[ccolumna];
   red= new unsigned *[ccolumna];

   for(unsigned c=0;c<ccolumna*4;c++)
   {
       blue[c]=new unsigned [ffila];
       green[c]=new unsigned [ffila];
       red[c]=new unsigned [ffila];
   }
}

void sobremuestreo::dinamicaE(unsigned ffila, unsigned ccolumna)
{
    delete verde;
    delete azul;
    delete rojo;

    azul= new unsigned *[ccolumna];
    verde= new unsigned *[ccolumna];
    rojo= new unsigned *[ccolumna];

    for(unsigned c=0;c<ccolumna*4;c++)
    {
        azul[c]=new unsigned [ffila];
        verde[c]=new unsigned [ffila];
        rojo[c]=new unsigned [ffila];
    }
}

void sobremuestreo::rellenar(unsigned freco, unsigned creco, unsigned mc, unsigned mf, unsigned **matriz1, unsigned **matriz2, unsigned **matriz3)
{
    dinamicaI(mf, mc);
    for(unsigned c=0 ; c<=creco ; c++)
    {
        for(unsigned f=0 ; f<=freco ; f++)
        {
            green[c][f]=matriz1[c][f];
            blue[c][f]=matriz2[c][f];
            red[c][f]=matriz3[c][f];
        }
    }
}

