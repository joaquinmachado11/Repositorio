#include <QCoreApplication>
#include <pixel.h>
#include <iostream>
#include <archivo.h>
#include <gestordearchivos.h>
#include <imagen.h>

using namespace std;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

//pruebas para pixel
{/*
    //ejecucion de constructor de pixel y definicion
    Pixel pixel1(1,1,1), pixel2(2,2,2);
    //pixel1.definirPixel(1,1,1);
    //pixel2.definirPixel(2,2,2);

    //corroboro q se guardo bien
    cout<<"Pixel 1: "<<endl;
    for(int i=0; i<3; i++)
        cout<<pixel1.devolverComponente(i)<<"  ";

    cout<<endl<<"Pixel 2: "<<endl;
    for(int i=0; i<3; i++)
        cout<<pixel2.devolverComponente(i)<<"  ";

    //sobrecarga op++
    ++pixel1;
    cout<<endl<<"Pixel 1 (++): "<<endl;
    for(int i=0; i<3; i++)
        cout<<pixel1.devolverComponente(i)<<"  ";

    //sobrecarga op--
    --pixel2;
    cout<<endl<<"Pixel 2 (--): "<<endl;
    for(int i=0; i<3; i++)
        cout<<pixel2.devolverComponente(i)<<"  ";

    //sobrecarga op+
    cout<<endl<<"Suma pix1 + pix2: ";
    pixel1 + pixel2;
    for(int i=0; i<3; i++)
        cout<<pixel1.devolverComponente(i)<<"  ";

    //sobrecarga op-
    cout<<endl<<"Suma pix1 - pix2: ";
    pixel1 - pixel2;
    for(int i=0; i<3; i++)
        cout<<pixel1.devolverComponente(i)<<"  ";
    cout<<endl;

    //sobrecarga op==
    pixel1.definirPixel(1,1,1);
    pixel2.definirPixel(3,3,3);
    if (pixel1==pixel2)
        cout<<"Son iguales"<<endl;
    else
        cout<<"Son distintos"<<endl;

    pixel1.definirPixel(1,1,1);
    pixel2.definirPixel(1,1,1);
    if (pixel1==pixel2)
        cout<<"Son iguales"<<endl;
    else
        cout<<"Son distintos"<<endl;
*/}

//pruebas archivo
    GestorDeArchivos gestorArchivos;
    gestorArchivos.setRuta("C:/Users/Usuario/Desktop/Final compu/Repositorio/FinalCompu/Autotest/");
    gestorArchivos.setRaiz("imagenes_pruebaPBM/");

    gestorArchivos.mostrarArchivos();

    int opcion;
    cout<<"Elegir archivo a leer: "; cin>>opcion;
    while (opcion != 99)
    {
        gestorArchivos.setID(opcion);
        cout<<"Se selecciono el archivo: "<<gestorArchivos.getNombreArchivo()<<endl;
        cout<<"Ubicacion del archivo: "<<gestorArchivos.getUbicacionArchivo()<<endl;
        Imagen imagen = gestorArchivos.generarImagen();
        cout<<"Codigo: "<<imagen.getCodigo()<<endl;
        cout<<"Descripcion: "<<imagen.getDescripcion()<<endl;
        cout<<"Filas: "<<imagen.getFilas()<<endl;
        cout<<"Columnas: "<<imagen.getColumnas()<<endl;
        cout<<"Rango dinamico: "<<imagen.getRangoDinamico()<<endl;
        cout<<"Elegir otro archivo: "; cin >> opcion;
    }

    return a.exec();
}
