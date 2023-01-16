#include "espaciodetrabajo.h"

EspacioDeTrabajo::EspacioDeTrabajo()
{

}

void EspacioDeTrabajo::setListadoDeArchivos(string rutaDirectorio)
{
    listadoDeArchivos.clear();

    DIR *dir = opendir(rutaDirectorio.c_str());
    if (dir != NULL)
    {
        string pto("."), ptopto("..");
        struct dirent *entry;
        while ((entry = readdir(dir)) != NULL)
        {
            if( entry->d_name != pto and entry->d_name != ptopto )
            {
                listadoDeArchivos.push_back(entry->d_name);
            }
        }
        closedir(dir);
    }
}

string EspacioDeTrabajo::getArchivo(int id)
{
    return listadoDeArchivos[id];
}

vector <string> EspacioDeTrabajo::getListadoDeArchivos()
{
    return listadoDeArchivos;
}
