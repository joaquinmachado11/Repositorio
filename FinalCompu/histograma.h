#ifndef HISTOGRAMA_H
#define HISTOGRAMA_H
#include <QOpenGLWindow>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QApplication>
#include <imagen.h>
#include <gestordearchivos.h>
#include <procesadorestadistico.h>

class Histograma : public QOpenGLWidget
{
public:
    Histograma();
    void setImagen(Imagen *pImagen);

    void mostrar();
    void datosEstadisticos();
    void procesar();

protected:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;

private:
    Imagen *ptrImagen;
    vector < vector <int> > datosRGB;
    vector <int> datosMonocGrises;
    ProcesadorEstadistico procesadorEstadistico;
};

#endif // HISTOGRAMA_H
