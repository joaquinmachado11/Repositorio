#ifndef EDITOR_H
#define EDITOR_H
#include <imagen.h>
#include <lut.h>
#include <filtro.h>
#include <suavizado.h>
#include <procesadorestadistico.h>

/**
 * @brief Procesamiento de punto de los pixeles de la imagen
 * @author Machado Joaquin
 */

class Editor
{
public:
    /**
     * @brief Editor Metodo constructor de la clase Editor
     */
    Editor();

    /**
     * @brief setImagen Metodo que define el puntero a imagen
     * @param pImagen Imagen a modificar
     */
    void setImagen (Imagen *pImagen);

    /**
     * @brief aumentarBrillo Metodo que aumenta el brillo a los pixeles de la imagen
     */
    void aumentarBrillo();

    /**
     * @brief disminuirBrillo Metodo que disminuye el brillo a los pixeles de la imagen
     */
    void disminuirBrillo();

    /**
     * @brief ajustarContraste Metodo que ajusta el contraste de la imagen
     */
    void ajustarContraste();

    /**
     * @brief negativo Metodo que aplica el negativo de la imagen
     */
    void negativo();

    /**
     * @brief binarizar Metodo que binariza la imagen
     * @param valorUmbral Valor umbral que definira que valor tomara cada pixel
     */
    void binarizar(int valorUmbral);

private:
    Imagen *ptrImagen; /**< Puntero a imagen a modificar */
    ProcesadorEstadistico procesadorEstadistico; /**< Procesador estadistico de los pixeles de la imagen */
};

#endif // EDITOR_H
