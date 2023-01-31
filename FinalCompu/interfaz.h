#ifndef INTERFAZ_H
#define INTERFAZ_H
#include <gestordearchivos.h>


class Interfaz
{
public:
    Interfaz(GestorDeArchivos *pGestor);
    void mostrarAtajos();
    void mostrarArchivos();
    void elegirArchivo();
    void mostrarLUTS();

private:
    GestorDeArchivos *ptrGestorDeArchivos;
};

#endif // INTERFAZ_H
/*
Contiene los atajos de teclado
Muestra en pantalla las opciones
Informa los atajos de teclado
Recibe la indicacion para abrir un archivo
*/
