#include <iostream>
#include <QImage>
#include <fstream>
#include <string>
#include <stdlib.h> //new delete


using namespace std;

void entrega(unsigned **,unsigned**,unsigned**);
void meterDat(unsigned**);

int main()
{
    string filename= "../002/Imagenes/Bandera_02.png";
    QImage im(filename.c_str());



    unsigned int pixelX= im.height();
    unsigned int pixelY= im.width();
    unsigned int **azul=new unsigned *[pixelX],**verde=new unsigned *[pixelX],**rojo=new unsigned *[pixelX];//las tres matrices de colores diferentes
    //en la posicion 0 es se guarda azul
    //en la posision 1 se guarda en verde
    //en la posision 3 se guarda en rojo

    for(unsigned int x=0 ; x <= pixelX ; ++x )
    {
        azul[x]=new unsigned [pixelY];
        verde[x]=new unsigned [pixelY];
        rojo[x]=new unsigned [pixelY];
        for(unsigned int y=0 ; y < pixelY ; ++y)
        {
            azul[x][y]=im.pixelColor(x,y).blue();
            verde[x][y]=im.pixelColor(x,y).green();
            rojo[x][y]=im.pixelColor(x,y).red();
       }
    }
    entrega(azul,verde,rojo);

    return 0;
}

void entrega(unsigned **azul,unsigned **verde, unsigned **rojo)
{
    fstream archivo;
    archivo.open("entrega.txt", fstream::app | fstream::ate);
    string llenado="byte arr[3][16][16]=\n{";

    archivo<<llenado;
    archivo.close();
    meterDat(rojo);
    archivo.open("entrega.txt", fstream::app | fstream::ate);
    archivo<<",\n";
    archivo.close();
    meterDat(verde);
    archivo.open("entrega.txt", fstream::app | fstream::ate);
    archivo<<",\n";
    archivo.close();
    meterDat(azul);
    archivo.open("entrega.txt", fstream::app | fstream::ate);
    archivo<<"};";
    archivo.close();


}

void meterDat(unsigned**entrega)
{
    fstream archivo;
    archivo.open("entrega.txt", fstream::app | fstream::ate);

    string llenado;
    llenado=llenado+"{";
    archivo<<llenado;

      for(unsigned e=0 ; e<16 ; e++)
      {
            llenado="{";
            archivo<<llenado;
            llenado="";
            for(unsigned a=0 ; a<16 ;a++)
            {
                llenado= llenado + to_string(entrega[e][a])+",";
                 archivo<<llenado;
                 llenado="";
            }
            llenado="},";
            archivo<<llenado;
       }
        llenado="}";
        archivo<<llenado;


    archivo.close();

}
