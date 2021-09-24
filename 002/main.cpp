#include <iostream>
#include <QImage>
#include <fstream>
#include <string>
#include <stdlib.h> //new delete


using namespace std;

void entrega(unsigned **entreg);

int main()
{
    string filename= "../001/Imagenes/Bandera_02.png";
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
        for(unsigned int y=0 ; y <= pixelY ; ++y)
        {
            azul[y][x]=im.pixelColor(x,y).blue();
            verde[y][x]=im.pixelColor(x,y).green();
            rojo[y][x]=im.pixelColor(x,y).red();
       }
    }
    entrega(azul);

    return 0;
}

void entrega(unsigned **entreg){
    fstream archivo;
    archivo.open("entrega.txt", fstream::app | fstream::ate);
    string llenado="byte arr[3][16][16]=\n";
    archivo<<llenado;
    for(unsigned i=0 ; i<3 ; i++){
        llenado="{";
        archivo<<llenado;
        for(unsigned e=0 ; e<16 ; e++){
            llenado="{";
            archivo<<llenado;
            for(unsigned a=0 ; a<16 ;a++){
                llenado="{";
                llenado= llenado + to_string((entreg[e][a]))+",";
            }
            llenado="}";
            archivo<<llenado;
        }
    }
}
