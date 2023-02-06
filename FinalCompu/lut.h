#ifndef LUT_H
#define LUT_H
#include <gestordearchivos.h>

/**
 * @brief Aplica pseudocoloreados a imagenes de intensidades.
 * @author Machado Joaquin
 */

class LUT
{
public:
    /**
     * @brief LUT Metodo constructor de la clase LUT
     */
    LUT();
    /**
     * @brief setGestor Metodo que define el puntero a un gestor de archivos
     * @param pGestor gestor de archivos
     */
    void setGestor(GestorDeArchivos *pGestor);

    /**
     * @brief aplicarLUT Metodo que aplica la tabla LUT a una imagen de intensidades
     * @param opcion LUT que se quiere aplicar
     * @param pImagen Imagen sobre la que se quiere aplicar
     */
    void aplicarLUT (int opcion, Imagen &pImagen);

private:
    GestorDeArchivos *ptrGestorDeArchivos; /**< Gestor de archivo que conoce las tablas LUT disponibles */
    vector <Pixel> tablaLUT; /**< vector que contiene los nuevos pixeles para las distintas intensidades */
};

#endif // LUT_H
