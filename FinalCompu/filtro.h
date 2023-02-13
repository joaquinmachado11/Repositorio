#ifndef FILTRO_H
#define FILTRO_H
#include <imagen.h>

/**
 * @brief Filtrado espacial de los pixeles de la imagen
 * @author Machado Joaquin
 */

class Filtro
{
public:
    /**
     * @brief Filtro Metodo constructor de la clase Filtro
     */
    Filtro();

    /**
     * @brief ~Filtro Metodo destructor virtual de la clase Filtro
     */
    virtual ~Filtro();

    /**
     * @brief aplicarFiltro Metodo virtual que aplica el filtro
     * @param pImagen Imagen a la que se le aplica el filtro
     */
    virtual void aplicarFiltro(Imagen &pImagen) = 0;
};

struct Espacio
{ int f, c; };
const vector < Espacio > recorrido=
{{0,0},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};

#endif // FILTRO_H
