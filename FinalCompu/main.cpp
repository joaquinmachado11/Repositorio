#include <QCoreApplication>
#include <pixel.h>
#include <iostream>

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

    return a.exec();
}
