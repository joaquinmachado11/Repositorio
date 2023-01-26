#include "graficador.h"

Graficador::Graficador(GestorDeArchivos *pGestorDeArchivos)
{
    ptrGestorDeArchivos = pGestorDeArchivos;
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

void Graficador::cargarImagen()
{
    imagenAGraficar = ptrGestorDeArchivos->generarImagen();
    editor.setImagen(&imagenAGraficar);
    pintor.setImagen(&imagenAGraficar);
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
    xmin = -1;   xmax = w+1; //cuando modifico estos parámetros cambio lo que se proyecta
    ymin = -1;   ymax = h+1; //en el tamaño de la ventana(no cambio la cantidad de pixeles)
    zmin = -1;   zmax = 1;

    glOrtho(xmin, xmax, ymin, ymax, zmin, zmax);

    //Establezco matriz de modelo-vista y limpio las transformaciones
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void Graficador::paintGL()
{
    resizeGL(width(), height());

    glClear(GL_COLOR_BUFFER_BIT);

    //relación entre pixeles_ventana/metros_imagen (para el ancho y el alto respectivamente)
    float relAncho = ((float)width())/((float)imagenAGraficar.getColumnas());
    float relAlto = ((float)height())/((float)imagenAGraficar.getFilas());

    escala=1.0f;
    //se realiza el dibujo en las coordenadas (0,0)
    desplx=0.0f;
    desply=0.0f;

    if(relAncho < relAlto)
    {
        escala=relAncho;
        desply=(height() - (float)imagenAGraficar.getFilas()*escala)*0.5f; //el alto menos el nuevo alto por 0,5 (medio espacio libre a cada lado de la imagen)
    }
    else
    {
        escala=relAlto;
        desplx=(width() - (float)imagenAGraficar.getColumnas()*escala)*0.5f; //el ancho menos el nuevo ancho por 0,5 (medio espacio libre a cada lado de la imagen)
    }

    dibujarImagen();
}

void Graficador::dibujarImagen()
{
    int filas = imagenAGraficar.getFilas();
    int columnas = imagenAGraficar.getColumnas();
    float M = imagenAGraficar.getRangoDinamico();
    Pixel pixelAUX;

    glPushMatrix();

    glTranslatef(desplx, desply + escala * filas, 0.0f); //se mueve la imagen al centro de la ventana
    glScalef(escala, -escala, 1.0f); //escalar que mantenga sus proporciones para cualquier tamaño de ventana

    glBegin (GL_QUADS);
    for (int f=0; f<filas; f++)
    {
        for (int c=0; c<columnas; c++)
        {
            pixelAUX = imagenAGraficar.getPixel(f,c);
//            float R = pixelAUX.devolverComponente(0)/(float)M;
//            float G = pixelAUX.devolverComponente(1)/(float)M;
//            float B = pixelAUX.devolverComponente(2)/(float)M;
//            float R = pixelAUX.getComponente0()/(float)M;
//            float G = pixelAUX.getComponente1()/(float)M;
//            float B = pixelAUX.getComponente2()/(float)M;

            glColor3f(pixelAUX.devolverComponente(0)/(float)M,
                      pixelAUX.devolverComponente(1)/(float)M,
                      pixelAUX.devolverComponente(2)/(float)M);
            glVertex3f(c  , f  , 0);
            glVertex3f(c  , f+1, 0);
            glVertex3f(c+1, f+1, 0);
            glVertex3f(c+1, f  , 0);
        }
    }
    glEnd();

    glPopMatrix();
}

void Graficador::keyPressEvent(QKeyEvent *pPtrEvent)
{
    bool flechaDerecha = pPtrEvent->key() == Qt::Key_Right;
    bool flechaIzquierda = pPtrEvent->key() == Qt::Key_Left;
    //bool S = pPtrEvent->key() == Qt::Key_S;
    bool ctrlMas = pPtrEvent->modifiers()&Qt::ControlModifier && pPtrEvent->key() == Qt::Key_Plus;
    bool ctrlMenos = pPtrEvent->modifiers()&Qt::ControlModifier && pPtrEvent->key() == Qt::Key_Minus;
    bool N = pPtrEvent->key() == Qt::Key_N;
    bool ctrlG = pPtrEvent->modifiers()&Qt::ControlModifier && pPtrEvent->key() == Qt::Key_G;
    bool mas = pPtrEvent->key() == Qt::Key_Plus;
    bool menos = pPtrEvent->key() == Qt::Key_Minus;
    //bool ctrl = event->modifiers() & Qt::ControlModifier;

    if (flechaDerecha)
    {
        int nuevoID = ptrGestorDeArchivos->getID()+1;

        if (nuevoID > ptrGestorDeArchivos->cantidadDeArchivos()-1)
        {
            ptrGestorDeArchivos->setID(0);
        }
        else
        {
            ptrGestorDeArchivos->setID(nuevoID);
        }

        cargarImagen();
        cout << "Se abrio: " << ptrGestorDeArchivos->getNombreArchivo() <<endl;
    }

    if (flechaIzquierda)
    {
        int nuevoID = ptrGestorDeArchivos->getID()-1;
        if (nuevoID < 0)
        {
            ptrGestorDeArchivos->setID(ptrGestorDeArchivos->cantidadDeArchivos()-1);
        }
        else
        {
            ptrGestorDeArchivos->setID(nuevoID);
        }
        cargarImagen();
        cout << "Se abrio: " << ptrGestorDeArchivos->getNombreArchivo() <<endl;
    }

    /*if (S)
    {
        editor.aplicarSuavizado();
    }*/

    if (ctrlG)
    {
        string nombreDeGuardado;
        cout << "Nombre con el que desea guardar el archivo: ";
        cin >> nombreDeGuardado;
        ptrGestorDeArchivos->guardarImagen(nombreDeGuardado, imagenAGraficar);
    }

    if (mas)
    {
        editor.aumentarBrillo();
    }

    if (menos)
    {
        editor.disminuirBrillo();
    }

    if (ctrlMas)
    {
        editor.aumentarContraste();
        cout << "Aumento de contraste." << endl;
    }

    if (ctrlMenos)
    {
        editor.disminuirContraste();
        cout << "Disminucion de contraste." << endl;
    }

    if (N)
    {
        editor.negativo();
        cout << "Negativo de imagen. " << endl;
    }
//    if ()
//    {

//    }

    repaint();
}

void Graficador::mousePressEvent(QMouseEvent *pPtrEvent)
{
    bool clicIzq = pPtrEvent->button() == Qt::LeftButton;
    bool ctrl = pPtrEvent->modifiers()&Qt::ControlModifier;

    if (ctrl and clicIzq)
    {
        cout<< "Ctrl + click izq." << endl;
        int pX = (pPtrEvent->x() - desplx) / escala;
        int pY = (pPtrEvent->y() - desply) / escala;
        pintor.aplicarAlgoritmo(pY, pX);
        cout<<"Area detectada: " << pintor.getAreaDetectada() << endl;

        repaint();

        pintor.reiniciarArea();
    }
}

void Graficador::mouseReleaseEvent(QMouseEvent *pPtrEvent)
{

}
