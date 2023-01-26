#include "interfaz.h"

Interfaz::Interfaz(GestorDeArchivos *pGestor)
{
    ptrGestorDeArchivos = pGestor;
}

void Interfaz::mostrarAtajos()
{

}

void Interfaz::mostrarArchivos()
{
    ptrGestorDeArchivos->mostrarArchivos();
}

void Interfaz::elegirArchivo()
{
    int opcion;
    cout << "Elegir archivo a leer: "; cin >> opcion;
        ptrGestorDeArchivos->setID(opcion-1);
        cout << "Se selecciono el archivo: " << ptrGestorDeArchivos->getNombreArchivo() << endl;
        cout << "Ubicacion del archivo: " << ptrGestorDeArchivos->getUbicacionArchivo() << endl;
}
