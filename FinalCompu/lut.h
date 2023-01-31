#ifndef LUT_H
#define LUT_H
#include <gestordearchivos.h>

class LUT
{
public:
    LUT();
    void setGestor(GestorDeArchivos *pGestor);

    void aplicarLUT (int opcion, Imagen &pImagen);

    void setTablaLUT(int id);

private:
    GestorDeArchivos *ptrGestorDeArchivos;
    vector <Pixel> tablaLUT;
};

#endif // LUT_H
