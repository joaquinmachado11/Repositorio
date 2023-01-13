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
    void setListadoDeArchivos(string rutaDirectorio);
    string getListadoDeArchivos(int id);

private:
    vector <string> listadoDeArchivos;
};

#endif // ESPACIODETRABAJO_H

