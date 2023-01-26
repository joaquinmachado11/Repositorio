#include "archivopnm.h"
#include "archivo.h"
#include <stdlib.h>

ArchivoPNM::~ArchivoPNM()
{

}

ArchivoPNM::ArchivoPNM()
{

}

Imagen ArchivoPNM::leerImagen(string pNombreArchivo)
{
    setNombreArchivo(pNombreArchivo);
    Imagen imagen;
    string identificacion, descripcion;
    char numeral;
    int filas, columnas;

    archivo.open(getNombreArchivo(), ios::in | ios::binary);

    if (!archivo.is_open())
    {
        cout<<"Error al abrir el archivo."<<endl;
    }
    else
    {
        archivo>>identificacion;    archivo.ignore();
        imagen.setCodigo(identificacion);
        //control de error para el codigo

        archivo>>numeral;
        if (numeral!='#')
            cout<<"Error. (corrupta)";

        getline(archivo, descripcion);
        imagen.setDescripcion(descripcion);

        archivo>>columnas;
        imagen.setColumnas(columnas);

        archivo>>filas;
        imagen.setFilas(filas);

        imagen.dimensionar();
        //archivo.close();

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
    //archivo.open(getNombreArchivo(), ios::in);

    if (pImagen.getCodigo()!="P1")
    {
        int rangoDinamico;
        archivo>>rangoDinamico;
        pImagen.setRangoDinamico(rangoDinamico);
    }
    else
    {
        pImagen.setRangoDinamico(1);
    }

    float datoPixel;
    Pixel pixelAUX;

    switch (pImagen.getCodigo()[1])
    {
    case '1':
        for (unsigned int f=0; f<pImagen.getFilas(); f++)
        {
            for (unsigned int c=0; c<pImagen.getColumnas(); c++)
            {
                archivo>>datoPixel; //agregar control de error q sea menor a M
                pixelAUX = pImagen.getPixel(f,c);
                pixelAUX.definirPixel(datoPixel,datoPixel,datoPixel);
                pImagen.setPixel(f, c, pixelAUX);
            }
        }
        break;

    case '2':
        for (unsigned int f=0; f<pImagen.getFilas(); f++)
        {
            for (unsigned int c=0; c<pImagen.getColumnas(); c++)
            {
                archivo>>datoPixel; //agregar control de error q sea menor a M
                pixelAUX = pImagen.getPixel(f,c);
                pixelAUX.definirPixel(datoPixel,datoPixel,datoPixel);
                pImagen.setPixel(f, c, pixelAUX);
            }
        }
        break;

    case '3':
        float datoPixel;
        for (unsigned int f=0; f<pImagen.getFilas(); f++)
        {
            for (unsigned int c=0; c<pImagen.getColumnas(); c++)
            {
                pixelAUX = pImagen.getPixel(f,c);

                archivo>>datoPixel; //agregar control de error q sea menor a M
                pixelAUX.definirComponente(0,datoPixel);

                archivo>>datoPixel;
                pixelAUX.definirComponente(1,datoPixel);

                archivo>>datoPixel;
                pixelAUX.definirComponente(2,datoPixel);

                pImagen.setPixel(f, c, pixelAUX);
            }
        }
        break;
    }

    /*if (pImagen.getCodigo()=="P1") //monocromatico
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
        for (unsigned int f=0; f<pImagen.getFilas(); f++)
        {
            for (unsigned int c=0; c<pImagen.getColumnas(); c++)
            {
                pixelAUX = pImagen.getPixel(f,c);

                archivo>>datoPixel; //agregar control de error q sea menor a M
                pixelAUX.definirComponente(0,datoPixel);

                archivo>>datoPixel;
                pixelAUX.definirComponente(1,datoPixel);

                archivo>>datoPixel;
                pixelAUX.definirComponente(2,datoPixel);

                pImagen.setPixel(f, c, pixelAUX);
            }
        }
    }*/

    archivo.close();
}

void ArchivoPNM::leerBinario(Imagen &pImagen)
{
    if (pImagen.getCodigo()=="P5" or pImagen.getCodigo()=="P6")
    {
        int rangoDinamico;
        archivo>>rangoDinamico;
        pImagen.setRangoDinamico(rangoDinamico);
    }
    else
    {
        pImagen.setRangoDinamico(1);
    }

    unsigned char datoPixel = 0;
    Pixel pixelAUX;

    switch (pImagen.getCodigo()[1])
    {
    case '4':
        for (unsigned int f=0; f<pImagen.getFilas(); f++)
        {
            for (unsigned int c=0; c<pImagen.getColumnas(); c++)
            {
                archivo.read((char * ) &datoPixel , sizeof(datoPixel));
                //agregar control de error, datoPixel <=M y >= 0
                pixelAUX = pImagen.getPixel(f,c);
                pixelAUX.definirPixel(datoPixel,datoPixel,datoPixel);
                pImagen.setPixel(f, c, pixelAUX);
            }
        }
        break;

    case '5':
        for (unsigned int f=0; f<pImagen.getFilas(); f++)
        {
            for (unsigned int c=0; c<pImagen.getColumnas(); c++)
            {
                archivo.read((char * ) &datoPixel , sizeof(datoPixel));
                //agregar control de error, datoPixel <=M y >= 0
                pixelAUX = pImagen.getPixel(f,c);
                pixelAUX.definirPixel(datoPixel,datoPixel,datoPixel);
                pImagen.setPixel(f, c, pixelAUX);
            }
        }
        break;

    case '6':
        unsigned char r = 0, g = 0, b = 0;
        for (unsigned int f=0; f<pImagen.getFilas(); f++)
        {
            for (unsigned int c=0; c<pImagen.getColumnas(); c++)
            {
                pixelAUX = pImagen.getPixel(f,c);

                archivo.read((char * ) &r , sizeof(r));
                archivo.read((char * ) &g , sizeof(g));
                archivo.read((char * ) &b , sizeof(b));
                //agregar control de error, datoPixel <=M y >= 0

                pixelAUX.definirPixel(r,g,b);
                pImagen.setPixel(f, c, pixelAUX);
            }
        }
        break;
    }

/*
    if (pImagen.getCodigo()=="P4") //monocromatico
    {
        for (unsigned int f=0; f<pImagen.getFilas(); f++)
        {
            for (unsigned int c=0; c<pImagen.getColumnas(); c++)
            {
                archivo.read((char * ) &datoPixel , sizeof(datoPixel));
                //agregar control de error, datoPixel <=M y >= 0
                pixelAUX = pImagen.getPixel(f,c);
                pixelAUX.definirPixel(datoPixel,datoPixel,datoPixel);
                pImagen.setPixel(f, c, pixelAUX);
            }
        }
    }

    if (pImagen.getCodigo()=="P5") //escala de grises
    {
        for (unsigned int f=0; f<pImagen.getFilas(); f++)
        {
            for (unsigned int c=0; c<pImagen.getColumnas(); c++)
            {
                archivo.read((char * ) &datoPixel , sizeof(datoPixel));
                //agregar control de error, datoPixel <=M y >= 0
                pixelAUX = pImagen.getPixel(f,c);
                pixelAUX.definirPixel(datoPixel,datoPixel,datoPixel);
                pImagen.setPixel(f, c, pixelAUX);
            }
        }
    }

    if (pImagen.getCodigo()=="P6") //rgb
    {
        for (unsigned int f=0; f<pImagen.getFilas(); f++)
        {
            for (unsigned int c=0; c<pImagen.getColumnas(); c++)
            {
                pixelAUX = pImagen.getPixel(f,c);

                archivo.read((char * ) &datoPixel , sizeof(datoPixel));
                //agregar control de error, datoPixel <=M y >= 0
                pixelAUX.definirComponente(0, datoPixel);

                archivo.read((char * ) &datoPixel , sizeof(datoPixel));
                pixelAUX.definirComponente(1, datoPixel);

                archivo.read((char * ) &datoPixel , sizeof(datoPixel));
                pixelAUX.definirComponente(2, datoPixel);

                pImagen.setPixel(f, c, pixelAUX);
            }
        }
    }
*/

    archivo.close();
}
