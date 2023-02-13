#include "interfaz.h"

Interfaz::Interfaz(GestorDeArchivos *pGestor)
{
    ptrGestorDeArchivos = pGestor;
}

void Interfaz::mostrarAtajos()
{
    cout << "+ --> Aumentar brillo." << endl;
    cout << "- --> Disminuir brillo." << endl;
    cout << "ctrl + A --> Ajustar contraste." << endl;
    cout << "ctrl + N --> Negativo." << endl;
    cout << "ctrl + S --> Suavizado." << endl;
    cout << "ctrl + M --> Mediana." << endl;
    cout << "ctrl + L --> Aplicar LUT." << endl;
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

    while (opcion < 1 or opcion > ptrGestorDeArchivos->cantidadDeArchivos())
    {
        limpiar();
        opcNoPermitida();
        mostrarArchivos();
        cout << "Elegir archivo a leer: "; cin >> opcion;
    }

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
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    cout << "No se permite esta opción." << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
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

    opcion = definirOpcion();

    while (opcion < 1 or opcion > 5)
    {
        limpiar();
        opcNoPermitida();
        cout << "Ingrese la carpeta que desea abrir: " << endl;
        cout << "\t 1) Grupo de imagenes 1." << endl;
        cout << "\t 2) Grupo de imagenes 2." << endl;
        cout << "\t 3) Grupo de imagenes 3." << endl;
        cout << "\t 4) Grupo de imagenes corruptas." << endl;
        cout << "\t 5) Imagenes guardadas." << endl;

        opcion = definirOpcion();
    }

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
        limpiar();
        opcNoPermitida();
        cout << "¿Desea continuar con el programa? Ingrese '1' si lo desea, '2' para finalizar. " << endl;
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
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); //Cambio color de texto a rojo
    cout << "Fin del programa. ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); //Cambiamos nuevamente el color del texto para que se mantenga el original

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
        cout << "ctrl + A --> Ajuste de contraste." << endl << endl;
        break;
    case 'B':
        cout << "ctrl + B --> Binarizado." <<endl <<endl;
        break;
    case 'G':
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3); //Cambio color de texto a azul
        cout << "Imagen guardada. " << endl << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); //Vuelvo al color original
        break;
    case 'H':
        cout << "ctrl + H --> Histograma" << endl;
        break;
    case 'M':
        cout << "ctrl + M --> Mediana. " << endl << endl;
        break;
    case 'N':
        cout << "ctrl + N --> Negativo de imagen. " << endl << endl;
        break;
    case 'P':
        cout << "ctrl + click izq --> Algoritmo de pintor " << endl << endl;
        break;
    case 'S':
        cout << "ctrl + S --> Suavizado. "<<endl << endl;
        break;
    case 'X':
        cout << "ctrl + X --> Ultima imagen abierta en la ejecucion de programa anterior." << endl << endl;
        break;
    case 'Z':
        cout << "ctrl + Z --> Limpiar imagen." << endl << endl;
        break;
    }
}
