#ifndef HISTOGRAMA_H
#define HISTOGRAMA_H
#include <QOpenGLWindow>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QApplication>
#include <imagen.h>
#include <gestordearchivos.h>
#include <procesadorestadistico.h>

/**
 * @brief Genera un grafico de histograma y muestra datos estadisticos de una imagen.
 * @author Machado Joaquin
 */

class Histograma : public QOpenGLWidget
{
public:
    /**
     * @brief Histograma Metodo constructor de clase Histograma
     */
    Histograma();

    /**
     * @brief setImagen Metodo que define el puntero a imagen
     * @param pImagen Imagen de la que se quiere obtener el histograma y sus datos
     */
    void setImagen(Imagen *pImagen);

    /**
     * @brief mostrar Muestra una ventana con el grafico de histograma
     */
    void mostrar();

    /**
     * @brief datosEstadisticos Muestra los datos estadisticos del histograma
     */
    void datosEstadisticos();

    /**
     * @brief procesar Procesa los datos estadisticos del histograma
     */
    void procesar();

protected:
    /**
     * @brief initializeGL Inicializa los recursos necesarios para utilizar OpenGL
     */
    void initializeGL() override;

    /**
     * @brief resizeGL Se modifica el tamaño cuando se modifica el tamaño de la ventana
     * @param w Nuevo ancho
     * @param h Nuevo alto
     */
    void resizeGL(int w, int h) override;

    /**
     * @brief paintGL Grafica el histograma
     */
    void paintGL() override;

private:
    Imagen *ptrImagen; /**< Puntero a imagen de la que se quiere obtener el histograma y sus datos */
    vector < vector <int> > datosRGB; /**< Matriz con los datos de frecuencia de los distintos valores RGB */
    vector <int> datosMonocGrises; /**< Matriz con los datos de frecuencia de los distintos valores monocromaticos o grises */
    ProcesadorEstadistico procesadorEstadistico; /**< Atributo utilizado para obtener los datos del histograma */
};

#endif // HISTOGRAMA_H
