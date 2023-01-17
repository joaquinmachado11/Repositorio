#ifndef ESPACIODETRABAJO_H
#define ESPACIODETRABAJO_H
#include <iostream>
#include <vector>
#include <dirent.h>
#include <string>

using namespace std;

class EspacioDeTrabajo
{
public:
    EspacioDeTrabajo();
    vector <string> generarListadoDeArchivos(string rutaDirectorio);
    void setListaArch(string pRuta);

private:
    vector <string> listaArchivos;
};

#endif // ESPACIODETRABAJO_H

