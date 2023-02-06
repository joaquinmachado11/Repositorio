#ifndef INTERFAZ_H
#define INTERFAZ_H
#include <gestordearchivos.h>

/**
 * @brief Muestra los textos por consola, permite que el usuario interactue con el graficador
 * @author Machado Joaquin
 */

class Interfaz
{
public:
    Interfaz(GestorDeArchivos *pGestor);
    void mostrarAtajos();
    void mostrarArchivos();
    void elegirArchivo();
    void mostrarLUTS();
    string definirNombreDeGuardado();
    void mostrarOpcionesDeGuardado(string cod);
    int definirOpcion();
    int definirUmbralBinarizado();
    void opcNoPermitida();

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
