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
    bool A = pPtrEvent->key() == Qt::Key_A;
    bool B = pPtrEvent->key() == Qt::Key_B;
    bool S = pPtrEvent->key() == Qt::Key_S;
    bool N = pPtrEvent->key() == Qt::Key_N;
    bool R = pPtrEvent->key() == Qt::Key_R;
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
        cout << "Se abrio: " << ptrGestorDeArchivos->getNombreArchivo() << endl << endl;
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
        cout << "Se abrio: " << ptrGestorDeArchivos->getNombreArchivo() <<endl << endl;
    }

    if (S)
    {
        filtro = new Suavizado;

        cout << "S --> Suavizado. "<<endl << endl;

        if(filtro != NULL)
        {
            filtro->aplicarFiltro(imagenAGraficar);
        }

        delete filtro;
    }

    if (R)
    {
        filtro = new RealceDeBordes;

        cout << "R --> Realce de bordes. "<<endl << endl;

        if(filtro != NULL)
        {
            filtro->aplicarFiltro(imagenAGraficar);
        }

        delete filtro;
    }

    if (M)
    {
        filtro = new Mediana;

        cout << "M --> Mediana. "<<endl << endl;

        if(filtro != NULL)
        {
            filtro->aplicarFiltro(imagenAGraficar);
        }

        delete filtro;
    }

    if (ctrl and G)
    {
        string codigo = imagenAGraficar.getCodigo();

        string nombreDeGuardado = ptrInterfaz->definirNombreDeGuardado();
        ptrInterfaz->mostrarOpcionesDeGuardado(codigo);

        int opc = ptrInterfaz->definirOpcion();

        imagenAGraficar.definirCodigoDeGuardado(opc);

        ptrGestorDeArchivos->guardarImagen(nombreDeGuardado, imagenAGraficar);

        cout <<  "Imagen guardada. " << endl << endl;
    }

    if (mas)
    {
        editor.aumentarBrillo();
    }

    if (menos)
    {
        editor.disminuirBrillo();
    }

    if (A)
    {
        editor.ajustarContraste();
        cout << "Ajuste de contraste." << endl << endl;
    }

    if (B)
    {
        if (imagenAGraficar.getCodigo() == "P2" or imagenAGraficar.getCodigo() == "P5")
        {
            int umbral = ptrInterfaz->definirUmbralBinarizado();

            editor.binarizar(umbral);
        }
        else
        {
            ptrInterfaz->opcNoPermitida();
            cout << endl << endl;
        }
    }

    if (N)
    {
        editor.negativo();
        cout << "Negativo de imagen. " << endl << endl;
    }

    if (ctrl and H)
    {
        cout << "Ctrl + H --> HISTOGRAMA" << endl;
        histograma.setImagen(&imagenAGraficar);
        histograma.procesar();
        histograma.datosEstadisticos();
        histograma.mostrar();
        cout << endl << endl;
    }

    if (ctrl and Z)
    {
        imagenAGraficar = ptrGestorDeArchivos->generarImagen();

        cout << "ctrl + Z --> Limpiar imagen." << endl << endl;
    }

    if (ctrl and X)
    {
        cout << "ctrl + X --> Ultima imagen abierta en la ejecucion de programa anterior." << endl << endl;
        imagenAGraficar = ptrGestorDeArchivos->generarUltimaImagen();
    }

    if (L)
    {
        if (imagenAGraficar.getCodigo() == "P5" or imagenAGraficar.getCodigo() == "P2" or imagenAGraficar.getCodigo() == "P2C")
        {
            ptrInterfaz->mostrarLUTS();
            int opc = ptrInterfaz->definirOpcion();

            lut.aplicarLUT(opc, imagenAGraficar);
            cout << "Se aplico " << ptrGestorDeArchivos->getNombreLUT(opc-1) <<endl<<endl;
        }

        else
        {
            ptrInterfaz->opcNoPermitida();
            cout << endl << endl;
        }
    }

    if (esc)//esc
    {
        ptrGestorDeArchivos->almacenarUltimaImagen(imagenAGraficar);
        cout << "Fin del programa." << endl << endl;
        exit(0);
    }

    repaint();

    ptrInterfaz->mostrarAtajos();
    cout<<endl<<endl;
}

void Graficador::mousePressEvent(QMouseEvent *pPtrEvent)
{
    bool clicIzq = pPtrEvent->button() == Qt::LeftButton;
    bool ctrl = pPtrEvent->modifiers()&Qt::ControlModifier;

    if (ctrl and clicIzq)
    {
        pintor.setImagen(&imagenAGraficar);
        cout<< "Ctrl + click izq." << endl;
        int pX = (pPtrEvent->x() - desplx) / escala;
        int pY = (pPtrEvent->y() - desply) / escala;
        pintor.aplicarAlgoritmo(pY, pX);
        cout<<"Area detectada: " << pintor.getAreaDetectada() << endl << endl;

        repaint();

        ptrInterfaz->mostrarAtajos();
        cout << endl << endl;

        pintor.reiniciarArea();
    }
}
