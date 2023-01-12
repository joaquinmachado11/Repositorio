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
    void setListadoDeArchivos(string pRutaDirectorio);
    string getListadoDeArchivos(int);

private:
    vector <string> ListadoDeArchivos;
};

#endif // ESPACIODETRABAJO_H
/*
Conoce las carpetas con todos los archivos
gestiona directorios/archivos
*/
