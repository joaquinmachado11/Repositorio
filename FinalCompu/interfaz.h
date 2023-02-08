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
    void mostrarOpcionesDeGuardado(string cod);
    void mostrarLUTS();

    void elegirArchivo();

    string definirNombreDeGuardado();
    int definirOpcion();
    int definirUmbralBinarizado();

    void opcNoPermitida();
    int opcionesDeCarpetas();

    bool preguntarSiSeguir();
    void finPrograma();
    void limpiar();
    void seAbrio(string pNombre);
    void seAplico (string nombreLUT);
    void areaDetectada (int area);

    void informarAtajo (char atajo);

private:
    GestorDeArchivos *ptrGestorDeArchivos;
};

#endif // INTERFAZ_H
/*
Muestra en pantalla las opciones
Informa los atajos de teclado
*/
