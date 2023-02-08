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
    cout << "ctrl + clickIzq --> Algoritmo de pintor." << endl;
    cout << "ctrl + H --> Histograma." << endl;
    cout << "ctrl + G --> Guardar imagen." << endl;
    cout << "ctrl + Z --> Limpiar imagen." << endl;
    cout << "ctrl + X --> Última imagen abierta en la ejecución de programa anterior." << endl;
    cout << "esc --> Cerrar imagen." << endl;
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
    cout << endl;
}

void Interfaz::elegirArchivo()
{
    int opcion;
    cout << "Elegir archivo a leer: "; cin >> opcion;
    ptrGestorDeArchivos->setID(opcion-1);

    limpiar();

    cout << "Se seleccionó el archivo: " << ptrGestorDeArchivos->getNombreArchivo() << endl << endl;
    mostrarAtajos();
    cout << endl;

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
    string nombre;
    cout << "Ingrese el nombre con el que desea guardar la imagen: ";
    cin >> nombre;

    return nombre;
}

void Interfaz::mostrarOpcionesDeGuardado(string cod)
{
    cout << "Seleccione como desea guardarlo: \n";
    cout << "\t1) Binario. " << endl;
    cout << "\t2) Texto. " << endl;
    if (cod != "P3" and cod != "P6")
        cout << "\t3) Comprimido. " << endl;
}

int Interfaz::definirOpcion()
{
    int opc;
    cout << "Seleccione una opción: ";
    cin >> opc;

    return opc;
}

int Interfaz::definirUmbralBinarizado()
{
    int umbral;
    cout << "Ingresar valor umbral: ";
    cin >> umbral;

    return umbral;
}

void Interfaz::opcNoPermitida()
{
    cout << "No se permite esta opción." << endl;
}

int Interfaz::opcionesDeCarpetas()
{
    int opcion;
    cout << "Ingrese la carpeta que desea abrir: " << endl;
    cout << "\t 1) Grupo de imagenes 1." << endl;
    cout << "\t 2) Grupo de imagenes 2." << endl;
    cout << "\t 3) Grupo de imagenes 3." << endl;
    cout << "\t 4) Grupo de imagenes corruptas." << endl;
    cout << "\t 5) Imagenes guardadas." << endl;
    cout << "\t 6) Grupo de imagenes lolo." << endl;

    opcion = definirOpcion();

    return opcion;
}

bool Interfaz::preguntarSiSeguir()
{
    bool seguir;
    int opcion;
    cout << "¿Desea continuar con el programa? Ingrese '1' si lo desea, '2' para finalizar. " << endl;
    opcion = definirOpcion();

    while (opcion != 1 and opcion != 2)
    {
        opcNoPermitida();
        opcion = definirOpcion();
    }

    switch (opcion)
    {
    case 1:
        seguir = true;
        break;
    case 2:
        seguir = false;
        break;
    }

    return seguir;
}

void Interfaz::finPrograma()
{
    cout << "Fin del programa. ";
}

void Interfaz::limpiar()
{
    system("CLS");
}

void Interfaz::seAbrio(string pNombre)
{
    cout << "Se abrió " << pNombre << endl << endl;
}

void Interfaz::seAplico(string nombreLUT)
{
    cout << "Se aplicó " << nombreLUT << endl << endl;
}

void Interfaz::areaDetectada(int area)
{
    cout<<"Área detectada: " << area << endl << endl;
}

void Interfaz::informarAtajo(char atajo)
{
    switch (atajo)
    {
    case 'A':
        cout << "Ajuste de contraste." << endl << endl;
        break;
    case 'B':
        cout << "Binarizado." <<endl <<endl;
        break;
    case 'G':
        cout << "Imagen guardada. " << endl << endl;
        break;
    case 'H':
        cout << "Ctrl + H --> Histograma" << endl;
        break;
    case 'M':
        cout << "M --> Mediana. " << endl << endl;
        break;
    case 'N':
        cout << "Negativo de imagen. " << endl << endl;
        break;
    case 'P':
        cout << "Ctrl + click izq --> Algoritmo de pintor " << endl << endl;
        break;
    case 'R':
        cout << "R --> Realce de bordes. "<<endl << endl;
        break;
    case 'S':
        cout << "S --> Suavizado. "<<endl << endl;
        break;
    case 'X':
        cout << "ctrl + X --> Ultima imagen abierta en la ejecucion de programa anterior." << endl << endl;
        break;
    case 'Z':
        cout << "ctrl + Z --> Limpiar imagen." << endl << endl;
        break;
    }
}
