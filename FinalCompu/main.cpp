#include <QCoreApplication>
#include <pixel.h>
#include <iostream>
#include <archivo.h>
#include <gestordearchivos.h>
#include <imagen.h>
#include <graficador.h>
#include <procesadorestadistico.h>
#include <interfaz.h>
#include <histograma.h>

using namespace std;
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

//pruebas para pixel
    /*
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

    pixel1=pixel2;
    if (pixel1==pixel2)
        cout<<"Son iguales"<<endl;
    else
        cout<<"Son distintos"<<endl;
*/

//pruebas archivo
    /*
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


        Pixel pixelAUX;
        for(int f=0; f<imagen.getFilas(); f++)
        {
            for(int c=0; c<imagen.getColumnas(); c++)
            {
                pixelAUX = imagen.getPixel(f,c);
                cout<<pixelAUX.devolverComponente(0)<<" "
                    <<pixelAUX.devolverComponente(1)<<" "
                    <<pixelAUX.devolverComponente(2)<<"/";
            }
            cout<<endl;
        }

        cout<<"Elegir otro archivo: "; cin >> opcion;
    }
*/


//pruebas graficador
    /*
    GestorDeArchivos gestorArchivos;
    Graficador graficador(&gestorArchivos);
    gestorArchivos.setRuta("C:/Users/Usuario/Desktop/Final compu/Repositorio/FinalCompu/Autotest/");
    gestorArchivos.setRaiz("grupo_imagenes_1/");
    gestorArchivos.setRaizGuardado("imagenes_guardadas/");

    gestorArchivos.mostrarArchivos();

    int opcion;
    cout << "Elegir archivo a leer: "; cin >> opcion;
    while (opcion!=99)
    {
        gestorArchivos.setID(opcion);
        graficador.cargarImagen();
        cout << "Se selecciono el archivo: " << gestorArchivos.getNombreArchivo() << endl;
        cout << "Ubicacion del archivo: " << gestorArchivos.getUbicacionArchivo() << endl;
        graficador.mostrar(800, 800, &app);

        cout<<"Elija otra opcion: "; cin >> opcion;
    }
*/

//pruebas editor y procesador estadistico

    GestorDeArchivos gestorArchivos;
    Interfaz interfaz (&gestorArchivos);
    Graficador graficador(&gestorArchivos);

    gestorArchivos.setRuta("C:/Users/Usuario/Desktop/Final compu/Repositorio/FinalCompu/Autotest/");
    gestorArchivos.setRaiz("grupo_imagenes_1/");
    gestorArchivos.setRaizGuardado("imagenes_guardadas/");

    interfaz.mostrarArchivos();
    interfaz.elegirArchivo();

    graficador.cargarImagen();
    graficador.mostrar(500, 500, &app);


    return app.exec();
}
/*
imagenes_pruebaPBM
grupo_imagenes_1
grupo_imagenes_2
*/
