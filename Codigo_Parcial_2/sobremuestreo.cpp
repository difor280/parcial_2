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
           dinamica(fila*2,columna);
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

        }
        if(columna<=2)
        {
             dinamica(fila,columna*2);
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
        }


    }
    unsigned int creciente=3,guardarfilas=0;

    while (true)
    {
        for(unsigned c=0; c<columna ; c++)
        {
            for(unsigned d=0,f=0 ; f<=fila and guardarfilas<16  ; d++,f++)
            {
                 guardarfilas=guardarfilas+1;
                 if(d==round(fila/creciente))
                 {

                    green[c][guardarfilas]=verde[c][f];
                    guardarfilas=guardarfilas+1;
                    green[c][guardarfilas]=verde[c][f]+(((verde[c][f+1]-verde[c][f])/((f+2)-f))*((f+1)-f));
                    blue[c][guardarfilas]=azul[c][f]+(((azul[c][f+1]-azul[c][f])/((f+2)-f))*((f+1)-f));
                    red[c][guardarfilas]=rojo[c][f]+(((rojo[c][f+1]-rojo[c][f])/((f+2)-f))*((f+1)-f));
                    d=0;
                 }

            }
        }
        if(guardarfilas>=16)    break;
    }

}



void sobremuestreo::dinamica(unsigned ffila,unsigned ccolumna)
{
   delete green;
   delete blue;
   delete red;

   blue= new unsigned *[ccolumna];
   green= new unsigned *[ccolumna];
   red= new unsigned *[ccolumna];

   for(unsigned c=0;c<columna*4;c++)
   {
       blue[c]=new unsigned [ffila];
       green[c]=new unsigned [ffila];
       red[c]=new unsigned [ffila];
   }
}

