#ifndef EDITOR_H
#define EDITOR_H
#include <imagen.h>
#include <lut.h>
#include <filtro.h>
#include <suavizado.h>

class Editor
{
public:
    Editor();
    void aplicarLUT(Imagen& imagen);

    void aumentarBrillo(Imagen& imagen);
    void disminuirBrillo(Imagen& imagen);

    void aumentarContraste(Imagen& imagen);
    void disminuirContraste(Imagen& imagen);

    //algoritmo pintor

    void aplicarFiltro(Imagen& imagen);
    void aplicarSuavizado(Imagen& imagen);


private:
    LUT lut;
    Filtro filtro;
    Suavizado suavizado;
};

#endif // EDITOR_H
