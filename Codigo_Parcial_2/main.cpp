#include <iostream>
#include <QImage>
#include <fstream>


using namespace std;

int main()
{
    string filename= "../001/Imagenes/Bandera.png", cadena;
    QImage im(filename.c_str() );
    ofstream archivo;

    unsigned int pixelX= im.height();
    unsigned int pixelY= im.width();
    unsigned int InfLeds[3][pixelX][pixelY];

    for(unsigned int x=0 ; x <= pixelX ; ++x ){
        for(unsigned int y=0 ; y <= pixelY ; ++y){
            InfLeds[0][y][x]=im.pixelColor(x,y).blue();
            InfLeds[1][y][x]=im.pixelColor(x,y).green();
            InfLeds[2][y][x]=im.pixelColor(x,y).red();
       }
    }


    archivo.open("prueba.txt", ios :: out);



    for (unsigned int i=0 ; i<= pixelY ; ++i){
        cadena=cadena+"[";
        for(unsigned int j=0 ; j <= pixelX ; ++j){

            cadena=cadena+"";
            archivo<<cadena;
        }
        cadena=cadena+"]"+"\n";
        }
    archivo.close();


    return 0;
}
