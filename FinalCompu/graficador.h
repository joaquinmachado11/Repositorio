#ifndef GRAFICADOR_H
#define GRAFICADOR_H
#include <imagen.h>

class Graficador
{
public:
    Graficador();
    void graficarImagen(Imagen& imagen);
    void graficarHistograma();
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
