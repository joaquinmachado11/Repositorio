#include "graficador.h"

Graficador::Graficador(GestorDeArchivos *pGestorDeArchivos)
{
    ptrGestorDeArchivos = pGestorDeArchivos;
    imagenAGraficar = ptrGestorDeArchivos->generarImagen();
}

Graficador::~Graficador()
{

}

void Graficador::mostrar(int pAncho, int pAlto, QApplication *pPtrApp)
{
    resize(pAncho, pAlto);
    show();
    pPtrApp -> exec();
}

void Graficador::initializeGL()
{
    //Se establece el color de fondo de la ventana
    glClearColor(0.5, 0.5, 0.5, 0); //la mitad de cada color para obtener gris
}

void Graficador::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h); //área de dibujo dentro de la ventana
    //Establecemos la matriz que se va a usar
    //En este caso se activa la matriz de proyección
    //Los comandos que se usen después van a afectar a esta matriz
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity(); //limpio cualquier transformación previa

    float xmin, xmax, ymin, ymax, zmin, zmax;
    xmin = -1;   xmax = 1; //cuando modifico estos parámetros cambio lo que se proyecta
    ymin = -1;   ymax = 1; //en el tamaño de la ventana(no cambio la cantidad de pixeles)
    zmin = -1;   zmax = 1;

    glOrtho(xmin, xmax, ymin, ymax, zmin, zmax);

    //Establezco matriz de modelo-vista y limpio las transformaciones
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void Graficador::paintGL()
{
    resizeGL(width(),height());

    glClear(GL_CLEAR_BUFFER);
}
