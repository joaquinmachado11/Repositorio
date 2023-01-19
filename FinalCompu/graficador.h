#ifndef GRAFICADOR_H
#define GRAFICADOR_H
#include <QOpenGLWindow>
#include <QOpenGLFunctions>
#include <QApplication>
#include <imagen.h>
#include <gestordearchivos.h>

class Graficador : public QOpenGLWindow, protected QOpenGLFunctions
{
public:
    Graficador(GestorDeArchivos *pGestorDeArchivos);
    ~Graficador();

    void mostrar(int pAncho, int pAlto, QApplication* pPtrApp);

    //void setGestorDeArchivos(*pGestorDeArchivos);

protected:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;

private:
    GestorDeArchivos *ptrGestorDeArchivos;
    Imagen imagenAGraficar;
};

#endif // GRAFICADOR_H

/*
Conoce la imagen
Mostrar las imágenes
Hace zoom a una region
Grafica histograma
Recibe ordenes de los atajos de teclados
Realiza zoom
*/

//(main) graficador.mostrar(...)
