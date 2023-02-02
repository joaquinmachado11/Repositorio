#include "interfaz.h"

Interfaz::Interfaz(GestorDeArchivos *pGestor)
{
    ptrGestorDeArchivos = pGestor;
}

void Interfaz::mostrarAtajos()
{
    cout << "+ --> Aumentar brillo." << endl;
    cout << "- --> Disminuir brillo." << endl;
    cout << "A --> Ajustar contraste." << endl;
    cout << "N --> Negativo." << endl;
    cout << "S --> Suavizado." << endl;
    cout << "M --> Mediana." << endl;
    cout << "R --> Realce de bordes." << endl;
    cout << "L --> Aplicar LUT." << endl;
    cout << "ctrl + H --> Histograma." << endl;
    cout << "ctrl + G --> Guardar imagen." << endl;
    cout << "ctrl + Z --> Limpiar imagen." << endl;
    cout << "ctrl + X --> Ultima imagen abierta en la ejecucion de programa anterior." << endl;
    cout << "esc --> Finalizar el programa." << endl;
}

void Interfaz::mostrarArchivos()
{
    vector <string> archivos = ptrGestorDeArchivos->getListadoDeArchivos();
    string nombre;
    int largo;

    for (unsigned int i=0; i<archivos.size(); i++)
    {
        nombre = archivos[i];
        largo = nombre.length();
        nombre.resize(largo-4);
        nombre.shrink_to_fit();

        cout<<"Archivo "<<i+1<<": ";
        cout<<nombre<<endl;
    }
}

void Interfaz::elegirArchivo()
{
    int opcion;
    cout << "Elegir archivo a leer: "; cin >> opcion;
        ptrGestorDeArchivos->setID(opcion-1);
        cout << "Se selecciono el archivo: " << ptrGestorDeArchivos->getNombreArchivo() << endl;
        //cout << "Ubicacion del archivo: " << ptrGestorDeArchivos->getUbicacionArchivo() << endl;
}

void Interfaz::mostrarLUTS()
{
    vector <string> luts = ptrGestorDeArchivos->getListadoDeLUTS();
    string nombreLUT;
    int largo;

    for (unsigned int i=0; i<luts.size(); i++)
    {
        nombreLUT = luts[i];
        largo = nombreLUT.length();
        nombreLUT.resize(largo-4);
        nombreLUT.shrink_to_fit();

        cout<<"LUT "<<i+1<<": ";
        cout<<nombreLUT<<endl;
    }
    cout << endl;
}

string Interfaz::definirNombreDeGuardado()
{

}

int Interfaz::definirOpcionDeGuardado()
{

}

int Interfaz::definirOpcion()
{

}
