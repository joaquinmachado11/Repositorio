#include "graficador.h"

Graficador::Graficador(GestorDeArchivos *pGestorDeArchivos, Interfaz *pInterfaz)
{
    ptrGestorDeArchivos = pGestorDeArchivos;
    ptrInterfaz = pInterfaz;
    lut.setGestor(pGestorDeArchivos);
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
    bool A = pPtrEvent->key() == Qt::Key_A;
    bool B = pPtrEvent->key() == Qt::Key_B;
    bool S = pPtrEvent->key() == Qt::Key_S;
    bool N = pPtrEvent->key() == Qt::Key_N;
    bool M = pPtrEvent->key() == Qt::Key_M;
    bool G = pPtrEvent->key() == Qt::Key_G;
    bool H = pPtrEvent->key() == Qt::Key_H;
    bool Z = pPtrEvent->key() == Qt::Key_Z;
    bool X = pPtrEvent->key() == Qt::Key_X;
    bool L = pPtrEvent->key() == Qt::Key_L;

    bool mas = pPtrEvent->key() == Qt::Key_Plus;
    bool menos = pPtrEvent->key() == Qt::Key_Minus;

    bool esc = pPtrEvent->key() == Qt::Key_Escape;
    bool ctrl = pPtrEvent->modifiers() & Qt::ControlModifier;


    if (flechaDerecha)
    {
        ptrInterfaz->limpiar();
        unsigned int nuevoID = ptrGestorDeArchivos->getID()+1;

        if (nuevoID > ptrGestorDeArchivos->cantidadDeArchivos()-1)
        {
            ptrGestorDeArchivos->setID(0);
        }
        else
        {
            ptrGestorDeArchivos->setID(nuevoID);
        }

        cargarImagen();

        ptrInterfaz->seAbrio(ptrGestorDeArchivos->getNombreArchivo());
        ptrInterfaz->mostrarAtajos();
        cout<<endl<<endl;
    }

    if (flechaIzquierda)
    {
        ptrInterfaz->limpiar();
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

        ptrInterfaz->seAbrio(ptrGestorDeArchivos->getNombreArchivo());
        ptrInterfaz->mostrarAtajos();
        cout<<endl<<endl;
    }

    if (ctrl and S)
    {
        ptrInterfaz->limpiar();
        filtro = new Suavizado;

        ptrInterfaz->informarAtajo('S');

        if(filtro != NULL)
        {
            filtro->aplicarFiltro(imagenAGraficar);
        }

        delete filtro;

        ptrInterfaz->mostrarAtajos();
        cout<<endl<<endl;
    }

    if (ctrl and M)
    {
        ptrInterfaz->limpiar();
        filtro = new Mediana;

        ptrInterfaz->informarAtajo('M');

        if(filtro != NULL)
        {
            filtro->aplicarFiltro(imagenAGraficar);
        }

        delete filtro;

        ptrInterfaz->mostrarAtajos();
        cout<<endl<<endl;
    }

    if (ctrl and G)
    {
        ptrInterfaz->limpiar();
        string codigo = imagenAGraficar.getCodigo();

        string nombreDeGuardado = ptrInterfaz->definirNombreDeGuardado();
        ptrInterfaz->mostrarOpcionesDeGuardado(codigo);

        int opc = ptrInterfaz->definirOpcion();

        imagenAGraficar.definirCodigoDeGuardado(opc);

        ptrGestorDeArchivos->guardarImagen(nombreDeGuardado, imagenAGraficar);

        ptrInterfaz->limpiar();
        ptrInterfaz->informarAtajo('G');

        ptrInterfaz->mostrarAtajos();
        cout<<endl<<endl;
    }

    if (mas)
    {
        if (imagenAGraficar.getCodigo()!= "P1" and imagenAGraficar.getCodigo()!= "P4")
            editor.aumentarBrillo();
    }

    if (menos)
    {
        if (imagenAGraficar.getCodigo()!= "P1" and imagenAGraficar.getCodigo()!= "P4")
            editor.disminuirBrillo();
    }

    if (ctrl and A)
    {
        ptrInterfaz->limpiar();
        editor.ajustarContraste();
        ptrInterfaz->informarAtajo('A');

        ptrInterfaz->mostrarAtajos();
        cout<<endl<<endl;
    }

    if (ctrl and B)
    {
        ptrInterfaz->limpiar();
        if (imagenAGraficar.getCodigo() == "P2" or imagenAGraficar.getCodigo() == "P5")
        {
            ptrInterfaz->informarAtajo('B');
            int umbral = ptrInterfaz->definirUmbralBinarizado();
            editor.binarizar(umbral);

            if (imagenAGraficar.getCodigo() == "P2" or imagenAGraficar.getCodigo() == "P3")
                imagenAGraficar.setCodigo("P1");

            if (imagenAGraficar.getCodigo() == "P5" or imagenAGraficar.getCodigo() == "P6")
                imagenAGraficar.setCodigo("P4");
        }
        else
        {
            ptrInterfaz->opcNoPermitida();
            cout << endl << endl;
        }

        ptrInterfaz->mostrarAtajos();
        cout<<endl<<endl;
    }

    if (ctrl and N)
    {
        ptrInterfaz->limpiar();
        editor.negativo();
        ptrInterfaz->informarAtajo('N');

        ptrInterfaz->mostrarAtajos();
        cout<<endl<<endl;
    }

    if (ctrl and H)
    {
        ptrInterfaz->limpiar();
        ptrInterfaz->informarAtajo('H');
        histograma.setImagen(&imagenAGraficar);
        histograma.procesar();
        histograma.datosEstadisticos();
        histograma.mostrar();
        cout << endl << endl;

        ptrInterfaz->mostrarAtajos();
        cout<<endl<<endl;
    }

    if (ctrl and Z)
    {
        ptrInterfaz->limpiar();
        imagenAGraficar = ptrGestorDeArchivos->generarImagen();

        ptrInterfaz->informarAtajo('Z');

        ptrInterfaz->mostrarAtajos();
        cout<<endl<<endl;
    }

    if (ctrl and X)
    {
        ptrInterfaz->limpiar();
        ptrInterfaz->informarAtajo('X');
        imagenAGraficar = ptrGestorDeArchivos->generarUltimaImagen();

        ptrInterfaz->mostrarAtajos();
        cout<<endl<<endl;
    }

    if (ctrl and L)
    {
        ptrInterfaz->limpiar();
        if (imagenAGraficar.getCodigo() == "P5" or imagenAGraficar.getCodigo() == "P2" or imagenAGraficar.getCodigo() == "P2C")
        {
            ptrInterfaz->mostrarLUTS();
            int opc = ptrInterfaz->definirOpcion();

            lut.aplicarLUT(opc, imagenAGraficar);

            if (imagenAGraficar.getCodigo() == "P2" or imagenAGraficar.getCodigo() == "P2C")
                imagenAGraficar.setCodigo("P3");

            if (imagenAGraficar.getCodigo() == "P5")
                imagenAGraficar.setCodigo("P6");

            ptrInterfaz->limpiar();
            ptrInterfaz->seAplico(ptrGestorDeArchivos->getNombreLUT(opc-1));
            ptrInterfaz->mostrarAtajos();
        }

        else
        {
            ptrInterfaz->limpiar();
            ptrInterfaz->opcNoPermitida();
            cout << endl << endl;

            ptrInterfaz->mostrarAtajos();
            cout<<endl<<endl;
        }
    }

    if (esc)
    {
        ptrInterfaz->limpiar();
        ptrGestorDeArchivos->almacenarUltimaImagen(imagenAGraficar);
        close();
    }

    repaint();
}

void Graficador::mousePressEvent(QMouseEvent *pPtrEvent)
{
    bool clicIzq = pPtrEvent->button() == Qt::LeftButton;
    bool ctrl = pPtrEvent->modifiers()&Qt::ControlModifier;

    if (ctrl and clicIzq)
    {
        ptrInterfaz->limpiar();
        pintor.setImagen(&imagenAGraficar);
        ptrInterfaz->informarAtajo('P');
        int pX = (pPtrEvent->x() - desplx) / escala;
        int pY = (pPtrEvent->y() - desply) / escala;
        pintor.aplicarAlgoritmo(pY, pX);
        ptrInterfaz->areaDetectada(pintor.getAreaDetectada());

        if (imagenAGraficar.getCodigo() == "P2")
            imagenAGraficar.setCodigo("P3");
        if (imagenAGraficar.getCodigo() == "P5")
            imagenAGraficar.setCodigo("P6");

        repaint();

        ptrInterfaz->mostrarAtajos();
        cout << endl << endl;
    }
}
