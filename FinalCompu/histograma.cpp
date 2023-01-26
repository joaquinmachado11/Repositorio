#include "histograma.h"

Histograma::Histograma()
{

}

void Histograma::setImagen(Imagen *pImagen)
{
    ptrImagen = pImagen;
}

void Histograma::mostrar()
{
    resize(1200,600);
    show();
}

void Histograma::procesar()
{
    string codigo = ptrImagen->getCodigo();

    if (codigo == "P3" or codigo == "P6")
    {
        datosRGB.resize(3, vector<int>(ptrImagen->getRangoDinamico()+1, 0));
        obtenerDatosRGB();
    }
    else
    {
        datosMonocGrises.resize(ptrImagen->getRangoDinamico()+1, 0);
        obtenerDatosMonocGrises();
    }
}

void Histograma::obtenerDatosRGB()
{
    Pixel pixelAux;
    int valor_r,valor_g,valor_b;
    for (int f=0; f<ptrImagen->getFilas(); f++)
    {
        for (int c=0; c<ptrImagen->getColumnas(); c++)
        {
            pixelAux = ptrImagen->getPixel(f,c);

            valor_r = pixelAux.devolverComponente(0);
            datosRGB[0][valor_r]++;

            valor_g = pixelAux.devolverComponente(1);
            datosRGB[1][valor_g]++;

            valor_b = pixelAux.devolverComponente(2);
            datosRGB[2][valor_b]++;
        }
    }
}

void Histograma::obtenerDatosMonocGrises()
{
    Pixel pixelAux;
    int valor;
    for (int f=0; f<ptrImagen->getFilas(); f++)
    {
        for (int c=0; c<ptrImagen->getColumnas(); c++)
        {
            pixelAux = ptrImagen->getPixel(f,c);
            valor = pixelAux.devolverComponente(0);
            datosMonocGrises[valor]++;
        }
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



