#ifndef GRAFICADOR_H
#define GRAFICADOR_H
#include <QOpenGLWindow>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QKeyEvent>
#include <QApplication>
#include <imagen.h>
#include <gestordearchivos.h>
#include <editor.h>
#include <algoritmopintor.h>
#include <histograma.h>
#include <filtro.h>
#include <mediana.h>
#include <interfaz.h>

/**
 * @brief Grafica imagenes quedando a la espera de eventos
 * @author Machado Joaquin
 */

class Graficador : public QOpenGLWidget
{
public:
    Graficador(GestorDeArchivos *pGestorDeArchivos, Interfaz *pInterfaz);
    ~Graficador();

    void mostrar(int pAncho, int pAlto, QApplication *pPtrApp);
    void cargarImagen();

protected:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;

    void keyPressEvent(QKeyEvent *pPtrEvent) override;
    void mousePressEvent(QMouseEvent *pPtrEvent) override;

private:
    void dibujarImagen();
    GestorDeArchivos *ptrGestorDeArchivos;
    Interfaz *ptrInterfaz;
    Imagen imagenAGraficar;
    float escala; //mantiene las proporciones para cualquier tamaño de ventana
    float desplx;
    float desply;
    Editor editor;
    Filtro *filtro;
    AlgoritmoPintor pintor;
    Histograma histograma;
    LUT lut;
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
