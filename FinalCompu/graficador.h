#ifndef GRAFICADOR_H
#define GRAFICADOR_H
#include <QOpenGLWindow>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QApplication>
#include <imagen.h>
#include <gestordearchivos.h>

class Graficador : public QOpenGLWidget
{
public:
    Graficador(GestorDeArchivos *pGestorDeArchivos);
    ~Graficador();

    void mostrar(int pAncho, int pAlto, QApplication *pPtrApp);
    void cargarImagen();

protected:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;

private:
    void dibujarImagen();
    GestorDeArchivos *ptrGestorDeArchivos;
    Imagen imagenAGraficar;
    float escala; //mantiene las proporciones para cualquier tamaño de ventana
    float desplx;
    float desply;
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
