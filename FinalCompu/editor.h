#ifndef EDITOR_H
#define EDITOR_H
#include <imagen.h>
#include <lut.h>
#include <filtro.h>
#include <suavizado.h>
#include <procesadorestadistico.h>

class Editor //procesadorDePunto
{
public:
    Editor();
    void setImagen (Imagen *pImagen);

    void aumentarBrillo();
    void disminuirBrillo();

    void ajustarContraste();

    void negativo();

    void binarizar(int valorUmbral); // metodo con los datos del histograma

private:
    Imagen *ptrImagen;
    ProcesadorEstadistico procesadorEstadistico;
};

#endif // EDITOR_H

/*
    Procesaimento de punto serian:
 - Brillo
 - Negativo
 - Contraste
 - Ecualizar
*/
