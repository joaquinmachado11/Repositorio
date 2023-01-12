#ifndef GESTORDEARCHIVOS_H
#define GESTORDEARCHIVOS_H
#include <espaciodetrabajo.h>
#include <archivo.h>

class GestorDeArchivos
{
public:
    GestorDeArchivos();
    Imagen generarImagen(int id);
    void guardarImagen(string nombreImagen, Imagen& imagen);

    const string &getRaiz() const;
    void setRaiz(const string &newRaiz);

    const string &getRuta() const;
    void setRuta(const string &newRuta);

private:
    EspacioDeTrabajo espacioDeTrabajo; //genera un vector que luego usara gestor de archivo para generar los objetos imagen
    void reconocerFormato();//reconoce si es pnm o aic
    string raiz, ruta;//info que pasara al espacio de trabajo para pedirle un vector con nombres de archivos
    //objeto archivo
    int ID;
};

#endif // GESTORDEARCHIVOS_H
