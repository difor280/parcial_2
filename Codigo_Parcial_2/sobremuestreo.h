#ifndef SOBREMUESTREO_H
#define SOBREMUESTREO_H
#include <cmath>
#include <iostream>

class sobremuestreo
{
public:
    sobremuestreo(unsigned**erojo,unsigned**everde,unsigned**eazul,unsigned long ffila,unsigned long ccolumna);
    void sobreproceso(); //funcion donde van todas las funciones
    void rellenar(unsigned freco,unsigned creco, unsigned mc, unsigned mf, unsigned **matriz1, unsigned **matriz2, unsigned **matriz3);
    void dinamicaI(unsigned ffila,unsigned columna);//es ir convirtiendo todas las memorias necesacias a dinamica
    void dinamicaE(unsigned ffila, unsigned columna);
    void duplicar(unsigned **);// duplica los valores en X y Y con su diagonal


private:
    unsigned **rojo,**verde,**azul,**red,**green,**blue;
    unsigned long fila,columna,recofila,recolumna;
    //los colores en español son las matrices a convertir
    //y los colores en ingles son las matrices que van a guardar lo convertido
    //las filas y columnas son las posisiciones a analizar
    //fila1 y columna1 es igual a posicion1
};




#endif // SOBREMUESTEO_H
