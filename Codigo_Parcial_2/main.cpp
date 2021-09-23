#include <iostream>
#include <QImage>
#include <fstream>
#include <string>


using namespace std;
int main()
{
    string filename= "../001/Imagenes/Bandera.png", cadena;
    QImage im(filename.c_str() );


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




    return 0;
}

