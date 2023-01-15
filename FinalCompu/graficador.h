#ifndef GRAFICADOR_H
#define GRAFICADOR_H
#include <imagen.h>
#include <gestordearchivos.h>

class Graficador
{
public: //(main) graficador.graficarImagen (int id)
    Graficador();
    void graficarImagen(int id);
    void graficarHistograma();
    void setGestorDeArchivos (GestorDeArchivos& gestorDeArchivos);

private:
    GestorDeArchivos *ptrGestorDeArchivos;
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
