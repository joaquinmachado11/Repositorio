#include "histograma.h"

Histograma::Histograma()
{

}

void Histograma::setImagen(Imagen *pImagen)
{
    ptrImagen = pImagen;
}

void Histograma::datosEstadisticos()
{
    procesadorEstadistico.setPtrImagen(ptrImagen);
    string codigo = ptrImagen->getCodigo();
    Pixel min, max;
    vector <float> prom,desvio;

    min = procesadorEstadistico.minimo();
    max = procesadorEstadistico.maximo();
    prom = procesadorEstadistico.promedio();
    desvio = procesadorEstadistico.desvioEstandar();

    if (codigo[1] == '3' or codigo[1] == '6')
    {
        cout << "Minima intensidad R: " << min.devolverComponente(0) << endl;
        cout << "Minima intensidad G: " << min.devolverComponente(1) << endl;
        cout << "Minima intensidad B: " << min.devolverComponente(2) << endl;

        cout << "Maxima intensidad R: " << max.devolverComponente(0) << endl;
        cout << "Maxima intensidad G: " << max.devolverComponente(1) << endl;
        cout << "Maxima intensidad B: " << max.devolverComponente(2) << endl;

        cout << "Promedio R: " << prom[0] << endl;
        cout << "Promedio G: " << prom[1] << endl;
        cout << "Promedio B: " << prom[2] << endl;

        cout << "Desvio R: " << desvio[0] << endl;
        cout << "Desvio G: " << desvio[1] << endl;
        cout << "Desvio B: " << desvio[2] << endl;

        procesadorEstadistico.modaRGB(datosRGB);
    }
    else
    {
         cout << "Minima intensidad: " << min.devolverComponente(0) << endl;
         cout << "Maxima intensidad: " << max.devolverComponente(0) << endl;
         cout << "Promedio: " << prom[0] << endl;
         cout << "Desvio: " << desvio[0] << endl;
         procesadorEstadistico.modaGrises(datosMonocGrises);
    }
}

void Histograma::procesar()
{
    string codigo = ptrImagen->getCodigo();
    procesadorEstadistico.setPtrImagen(ptrImagen);

    if (codigo == "P3" or codigo == "P6")
    {
        //datosRGB.resize(3, vector<int>(ptrImagen->getRangoDinamico()+1, 0));
        datosRGB = procesadorEstadistico.obtenerDatosPixelesRGB();
    }
    else
    {
        //datosMonocGrises.resize(ptrImagen->getRangoDinamico()+1, 0);
        datosMonocGrises = procesadorEstadistico.obtenerDatosPixelesMonocGrises();
    }
}

void Histograma::initializeGL()
{
    glClearColor(1,1,1,1);
}

void Histograma::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    float xmin, xmax, ymin, ymax, zmin, zmax;
    xmin = -1;   xmax = w+1; //cuando modifico estos parámetros cambio lo que se proyecta
    ymin = -1;   ymax = h+1; //en el tamaño de la ventana(no cambio la cantidad de pixeles)
    zmin = -1;   zmax = 1;

    glOrtho(xmin, xmax, ymin, ymax, zmin, zmax);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void Histograma::paintGL()
{
    resizeGL(width(),height());
    glClear(GL_COLOR_BUFFER_BIT);

    //float escalaX = (float)width()/((float)rango + 1);

    glPushMatrix();

    glBegin(GL_QUADS);

    glColor3f(0, 0, 0);
}

void Histograma::mostrar()
{
    resize(1200,600);
    show();
}


