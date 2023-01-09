#ifndef EDITOR_H
#define EDITOR_H
#include <imagen.h>
#include <lut.h>
#include <filtro.h>

class Editor
{
public:
    Editor();
    void aplicarLUT(Imagen&);

    void aumentarBrillo(Imagen&);
    void disminuirBrillo(Imagen&);

    void aumentarContraste(Imagen&);
    void disminuirContraste(Imagen&);

    //algoritmo pintor

    void aplicarFiltro(Imagen&);

private:
    LUT lut;
    Filtro filtro;
};

#endif // EDITOR_H
