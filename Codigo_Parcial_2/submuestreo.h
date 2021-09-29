#ifndef SUBMUESTREO_H
#define SUBMUESTREO_H


class submuestreo
{
public:
    submuestreo(unsigned**erojo,unsigned**everde,unsigned**eazul,unsigned long ffila,unsigned long ccolumna);
    void subproceso();
private:
    unsigned **rojo,**verde,**azul,**red,**green,**blue;
    unsigned long fila,columna;
};

#endif // SUBMUESTREO_H
