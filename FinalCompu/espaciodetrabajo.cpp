#include "espaciodetrabajo.h"

EspacioDeTrabajo::EspacioDeTrabajo()
{

}

void EspacioDeTrabajo::setListadoDeArchivos(string pRutaDirectorio)
{
    DIR *dir = opendir(pRutaDirectorio.c_str());
    if (dir != NULL)
    {
        string pto("."), ptopto("..");
        struct dirent *entry;
        while ((entry = readdir(dir)) != NULL)
        {
            if( entry->d_name != pto and entry->d_name != ptopto )
            {
                ListadoDeArchivos.push_back(entry->d_name);
            }
        }
        closedir(dir);
    }
}

string EspacioDeTrabajo::getListadoDeArchivos(int id)
{
    return ListadoDeArchivos[id];
}
