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
    /**
     * @brief Graficador Metodo constructor de la clase Graficador
     * @param pGestorDeArchivos Puntero a gestor de archivos
     * @param pInterfaz Puntero a interfaz
     */
    Graficador(GestorDeArchivos *pGestorDeArchivos, Interfaz *pInterfaz);
    /**
     * @brief ~Graficador Metodo destructor de la clase Grafiador
     */
    ~Graficador();

    /**
     * @brief mostrar Metodo que crea la ventana donde se graficara la imagen
     * @param pAncho Ancho de ventana
     * @param pAlto Alto de ventana
     * @param pPtrApp Puntero a un objeto QApplication que se encarga de ejecutar el programa
     */
    void mostrar(int pAncho, int pAlto, QApplication *pPtrApp);
    /**
     * @brief cargarImagen Carga la imagen al graficador y al editor
     */
    void cargarImagen();

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
     * @brief paintGL Permite graficar
     */
    void paintGL() override;

    /**
     * @brief keyPressEvent Metodo que permite captar y responder a un evento de teclado
     * @param pPtrEvent Evento captado
     */
    void keyPressEvent(QKeyEvent *pPtrEvent) override;
    /**
     * @brief mousePressEvent Metodo que permite captar y responder a un evento de mouse
     * @param pPtrEvent Evento captado
     */
    void mousePressEvent(QMouseEvent *pPtrEvent) override;

private:
    /**
     * @brief dibujarImagen Grafica la imagen utilizando funciones de OpenGL
     */
    void dibujarImagen();

    GestorDeArchivos *ptrGestorDeArchivos; /**< Puntero a gestor de archivos */
    Interfaz *ptrInterfaz; /**< Puntero a interfaz */
    Imagen imagenAGraficar; /**< Imagen que se graficara */
    float escala; /**< Mantiene las proporciones para cualquier tamaño de ventana */
    float desplx; /**< Desplazamiento en x de la imagen */
    float desply; /**< Desplazamiento en y de la imagen */
    Editor editor; /**< Editor de imagen */
    Filtro *filtro; /**< Puntero a filtro de imagen */
    AlgoritmoPintor pintor; /**< Pintor de imagen */
    Histograma histograma; /**< Histograma de imagen */
    LUT lut; /**< LUT para imagen */
};

#endif // GRAFICADOR_H
