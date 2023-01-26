#ifndef HISTOGRAMA_H
#define HISTOGRAMA_H
#include <QOpenGLWindow>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QApplication>
#include <imagen.h>
#include <gestordearchivos.h>

class Histograma : public QOpenGLWidget
{
public:
    Histograma(GestorDeArchivos *pGestorDeArchivos);
    void mostrar(int pAncho, int pAlto, QApplication *pPtrApp);

protected:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;

private:
    Imagen imagenAProcesar;
    GestorDeArchivos *ptrGestorDeArchivos;
};

#endif // HISTOGRAMA_H
