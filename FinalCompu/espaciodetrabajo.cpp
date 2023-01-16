#include "espaciodetrabajo.h"

EspacioDeTrabajo::EspacioDeTrabajo()
{

}

vector<string> EspacioDeTrabajo::generarListadoDeArchivos(string rutaDirectorio)
{
    vector <string> listaArchivos;

    DIR *dir = opendir(rutaDirectorio.c_str());
    if (dir != NULL)
    {
        string pto("."), ptopto("..");
        struct dirent *entry;
        while ((entry = readdir(dir)) != NULL)
        {
            if( entry->d_name != pto and entry->d_name != ptopto )
            {
                listaArchivos.push_back(entry->d_name);
            }
        }
        closedir(dir);
    }

    return listaArchivos;
}

