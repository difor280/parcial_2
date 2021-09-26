#ifndef SOBREMUESTREO_H
#define SOBREMUESTREO_H


class sobremuestreo
{
public:
    sobremuestreo(unsigned**erojo,unsigned**everde,unsigned**eazul,unsigned long fila,unsigned long columna);
    void sobreproceso(unsigned**);
    void comparacion4(unsigned **);
private:
    unsigned **rojo,**verde,**azul,**red,**green,**blue,fila1=0,fila2=1,columna1=0,columna2=1;
    unsigned long ffila,ccolumna;
    //los colores en español son las matrices a convertir
    //y los colores en ingles son las matrices que van a guardar lo convertido
    //las filas y columnas son las posisiciones a analizar
    //fila1 y columna1 es igual a posicion1
};



#endif // SOBREMUESTEO_H
