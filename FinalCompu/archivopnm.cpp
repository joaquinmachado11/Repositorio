#include "archivopnm.h"
#include "archivo.h"
#include <stdlib.h>

ArchivoPNM::ArchivoPNM()
{

}

Imagen ArchivoPNM::leerImagen(string pNombreArchivo)
{
    setNombreArchivo(pNombreArchivo);
    Imagen imagen;
    string identificacion, descripcion;
    int filas, columnas;

    archivo.open(getNombreArchivo(), ios::in);

    /*if (!archivo.is_open()) {
        cerr << "Could not open the file - '"
             << nombreArchivo << "'" << endl;
        return EXIT_FAILURE;
    }*/
    archivo>>identificacion;    archivo.ignore();
    imagen.setCodigo(identificacion);

    archivo>>descripcion;       archivo.ignore();

    archivo>>columnas;
    imagen.setColumnas(columnas);//agregar ignorar los espacios

    archivo>>filas;
    imagen.setFilas(filas);

    imagen.dimensionar();
    archivo.close();

    if (imagen.getCodigo()=="P1" or imagen.getCodigo()=="P2" or imagen.getCodigo()=="P3")
    {
        leerTexto(imagen);
    }
    else
    {
        if (imagen.getCodigo()=="P4" or imagen.getCodigo()=="P5" or imagen.getCodigo()=="P6")
        {
            leerBinario(imagen);
        }
        else
        {
            //error
        }
    }

    return imagen;
}

const string &ArchivoPNM::getNombreArchivo() const
{
    return nombreArchivo;
}

void ArchivoPNM::setNombreArchivo(const string &newNombreArchivo)
{
    nombreArchivo = newNombreArchivo;
}

void ArchivoPNM::leerTexto(Imagen &pImagen)
{
    archivo.open(getNombreArchivo(), ios::in);

    /*if (!archivo.is_open()) {
        cerr << "Could not open the file - '"
             << nombreArchivo << "'" << endl;
        return EXIT_FAILURE;
    }*/

    if (pImagen.getCodigo()=="P2" or pImagen.getCodigo()=="P3")
    {
        int rangoDinamico;
        archivo>>rangoDinamico;
        pImagen.setRangoDinamico(rangoDinamico);
    }

    if (pImagen.getCodigo()=="P1") //monocromatico
    {
        float datoPixel;

        for (unsigned int f=0; f<pImagen.getFilas(); f++)
        {
            for (unsigned int c=0; c<pImagen.getColumnas(); c++)
            {
                archivo>>datoPixel; //agregar control de error
                pImagen.getPixel(f,c).definirPixel(datoPixel,datoPixel,datoPixel);
            }
        }
    }

    if (pImagen.getCodigo()=="P2") //escala de grises
    {
        float datoPixel;

        for (unsigned int f=0; f<pImagen.getFilas(); f++)
        {
            for (unsigned int c=0; c<pImagen.getColumnas(); c++)
            {
                archivo>>datoPixel; //agregar control de error
                pImagen.getPixel(f,c).definirPixel(datoPixel,datoPixel,datoPixel);
            }
        }
    }

    if (pImagen.getCodigo()=="P3") //RGB
    {
        float datoPixel;

        for (unsigned int f=0; f<pImagen.getFilas(); f++)
        {
            for (unsigned int c=0; c<pImagen.getColumnas(); c++)
            {
                archivo>>datoPixel; //agregar control de error
                pImagen.getPixel(f,c).definirComponente(0,datoPixel);

                archivo>>datoPixel;
                pImagen.getPixel(f,c).definirComponente(1,datoPixel);

                archivo>>datoPixel;
                pImagen.getPixel(f,c).definirComponente(2,datoPixel);
            }
        }
    }

    archivo.close();
}

void ArchivoPNM::leerBinario(Imagen &pImagen)
{
    if (pImagen.getCodigo()=="P5" or pImagen.getCodigo()=="P6")
    {
        archivo.open(getNombreArchivo(), ios::in);

        int rangoDinamico;
        archivo>>rangoDinamico;
        pImagen.setRangoDinamico(rangoDinamico);

        archivo.close();

        archivo.open(getNombreArchivo(), ios::in | ios::binary);
    }
    else
    {
        archivo.open(getNombreArchivo(), ios::in | ios::binary);
    }

    if (pImagen.getCodigo()=="P4") //monocromatico
    {

    }

    if (pImagen.getCodigo()=="P5") //escala de grises
    {

    }

    if (pImagen.getCodigo()=="P6") //rgb
    {

    }


}
