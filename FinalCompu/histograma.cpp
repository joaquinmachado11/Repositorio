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
        datosRGB = procesadorEstadistico.obtenerDatosPixelesRGB();
    }
    else
    {
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
    xmin = -30;   xmax = w+30; //cuando modifico estos parámetros cambio lo que se proyecta
    ymin = -30;   ymax = h+30; //en el tamaño de la ventana(no cambio la cantidad de pixeles)
    zmin = -1;   zmax = 1;

    glOrtho(xmin, xmax, ymin, ymax, zmin, zmax);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void Histograma::paintGL()
{
    resizeGL(width(),height());
    glClear(GL_COLOR_BUFFER_BIT);

    float escalaX = (float)width()/((float)ptrImagen->getRangoDinamico() + 1);

    int mayorFrecuencia = procesadorEstadistico.getMayorFrecuencia();
    float escalaY = (float)height()/((float)mayorFrecuencia);

    if (ptrImagen->getCodigo() == "P1" or ptrImagen->getCodigo() == "P4")
    {
        glLineWidth(20.0f);
        glBegin(GL_LINES);
        glPushMatrix();
        glColor3f(0, 0, 0);

        for (int v = 0; v < ptrImagen->getRangoDinamico()+1; v++)
        {
            glVertex3f(v*escalaX + (float)width()/3, 0, 0);
            glVertex3f(v*escalaX + (float)width()/3, datosMonocGrises[v]*escalaY,0);
        }
    }

    if (ptrImagen->getCodigo() == "P2" or ptrImagen->getCodigo() == "P5" or ptrImagen->getCodigo() == "P2C")
    {
        glLineWidth(1.5f);
        glBegin(GL_LINES);

        glPushMatrix();
        glColor4f(0.5, 0.5, 0.5, 0.5f);

        for (int v = 0; v < ptrImagen->getRangoDinamico()+1; v++)
        {
            glVertex3f(v*escalaX, 0, 0);
            glVertex3f(v*escalaX, datosMonocGrises[v]*escalaY,0);
        }
    }

    if (ptrImagen->getCodigo() == "P3" or ptrImagen->getCodigo() == "P6")
    {
        glLineWidth(1.2f);
        glBegin(GL_LINES);

        glPushMatrix();

        for (int v = 0; v < ptrImagen->getRangoDinamico()+1; v++)
        {
            glColor3f(1,0,0); //RED
            glVertex3f((v-0.2)*escalaX, 0, 0);
            glVertex3f((v-0.2)*escalaX, datosRGB[0][v]*escalaY,0);
        }

        for (int v = 0; v < ptrImagen->getRangoDinamico()+1; v++)
        {
            glColor3f(0,1,0); //GREEN
            glVertex3f((v+0.2)*escalaX, 0, 0);
            glVertex3f((v+0.2)*escalaX, datosRGB[1][v]*escalaY,0);
        }

        for (int v = 0; v < ptrImagen->getRangoDinamico()+1; v++)
        {
            glColor3f(0,0,1); //BLUE
            glVertex3f(v*escalaX, 0, 0);
            glVertex3f(v*escalaX, datosRGB[2][v]*escalaY,0);
        }
    }
    glEnd();
    glPopMatrix();
}

void Histograma::mostrar()
{
    resize(1200,600);
    show();
}


