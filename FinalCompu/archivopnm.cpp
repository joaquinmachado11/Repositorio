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
    Imagen imagen;
    string codigo, descripcion;
    char numeral;
    int filas, columnas;

    archivo.open(pNombreArchivo, ios::in | ios::binary);

    if (!archivo.is_open())
    {
        cout << "Error al abrir el archivo. " << endl;
    }
    else
    {
        try
        {
            archivo>>codigo; archivo.ignore();
            imagen.setCodigo(codigo);

            archivo>>numeral;
            if (numeral != '#')
                throw (excepcion);

            getline(archivo, descripcion);
            imagen.setDescripcion(descripcion);

            archivo >> columnas;
            if (columnas <= 0)
                throw (excepcion);
            imagen.setColumnas(columnas);

            archivo >> filas;
            if (filas <= 0)
                throw (excepcion);
            imagen.setFilas(filas);

            imagen.dimensionar();

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
                    throw (excepcion);
                }
            }

            return imagen;
        }
        catch (ExcepcionArchivoCorrupto)
        {

        }
    }
}

void ArchivoPNM::escribirImagen(Imagen &imagen, string pNombreArchivo, string directorio)
{
    string codigo = imagen.getCodigo();
    string extension = definirExtension(codigo);

    archivo.open(directorio + pNombreArchivo + extension, ios:: out | ios::binary | ios::trunc); //ios::noreplace

    if (!archivo.is_open())
    {
        cout << "Error al guardar la imagen." <<endl;
    }
    else
    {
        archivo << codigo << endl;
        archivo << "#" << imagen.getDescripcion() << endl;
        archivo << imagen.getColumnas() << " " << imagen.getFilas() << endl;

        if (codigo != "P1" and codigo != "P4")
            archivo << imagen.getRangoDinamico() << endl;

        switch (codigo[1])
        {
        case '1':
            escribirP1(imagen);
            break;
        case '2':
            escribirP2(imagen);
            break;
        case '3':
            escribirP3(imagen);
            break;
        case '4':
            escribirP4(imagen);
            break;
        case '5':
            escribirP5(imagen);
            break;
        case '6':
            escribirP6(imagen);
            break;
        }
    }

    archivo.close();
}

void ArchivoPNM::escribirP1(Imagen &imagen)
{
    int intensidad;

    for (int f= 0; f< imagen.getFilas(); f++)
    {
        for (int c=0; c<imagen.getColumnas(); c++)
        {
            intensidad = imagen.getPixel(f,c).devolverComponente(0);
            archivo << intensidad << " ";
        }
    }
}

void ArchivoPNM::escribirP2(Imagen &imagen)
{
    int intensidad;

    for (int f= 0; f< imagen.getFilas(); f++)
    {
        for (int c=0; c<imagen.getColumnas(); c++)
        {
            intensidad = imagen.getPixel(f,c).devolverComponente(0);
            archivo << intensidad << " ";
        }
    }
}

void ArchivoPNM::escribirP3(Imagen &imagen)
{
    int intensidadR, intensidadG, intensidadB;
    Pixel pixelAux;

    for (int f= 0; f< imagen.getFilas(); f++)
    {
        for (int c=0; c<imagen.getColumnas(); c++)
        {
            pixelAux = imagen.getPixel(f,c);
            intensidadR = pixelAux.devolverComponente(0);
            intensidadG = pixelAux.devolverComponente(1);
            intensidadB = pixelAux.devolverComponente(2);

            archivo << intensidadR << " " << intensidadG << " " << intensidadB << " ";
        }
    }
}

void ArchivoPNM::escribirP4(Imagen &imagen)
{
    unsigned char intensidad;

    for (int f= 0; f< imagen.getFilas(); f++)
    {
        for (int c=0; c<imagen.getColumnas(); c++)
        {
            intensidad = imagen.getPixel(f,c).devolverComponente(0);
            archivo.write((char*) &intensidad, sizeof (intensidad));
        }
    }
}

void ArchivoPNM::escribirP5(Imagen &imagen)
{
    unsigned char intensidad;

    for (int f= 0; f< imagen.getFilas(); f++)
    {
        for (int c=0; c<imagen.getColumnas(); c++)
        {
            intensidad = imagen.getPixel(f,c).devolverComponente(0);
            archivo.write((char*) &intensidad, sizeof (intensidad));
        }
    }
}

void ArchivoPNM::escribirP6(Imagen &imagen)
{
    unsigned char r,g,b;
    Pixel pixelAux;

    for (int f= 0; f< imagen.getFilas(); f++)
    {
        for (int c=0; c<imagen.getColumnas(); c++)
        {
            pixelAux = imagen.getPixel(f,c);
            r = pixelAux.devolverComponente(0);
            g = pixelAux.devolverComponente(1);
            b = pixelAux.devolverComponente(2);

            archivo.write((char*) &r, sizeof (r));
            archivo.write((char*) &g, sizeof (g));
            archivo.write((char*) &b, sizeof (b));
        }
    }
}

string ArchivoPNM::definirExtension(string cod)
{
    if (cod == "P1" or cod == "P4")
        return ".pbm";

    if (cod == "P2" or cod == "P5")
        return ".pgm";

    if (cod == "P3" or cod == "P6")
        return ".ppm";
}

void ArchivoPNM::leerTexto(Imagen &pImagen)
{
    if (pImagen.getCodigo()!="P1")
    {
        int rangoDinamico;
        archivo >> rangoDinamico;
        if (rangoDinamico <= 0)
            throw (excepcion);
        pImagen.setRangoDinamico(rangoDinamico);
    }
    else
    {
        pImagen.setRangoDinamico(1);
    }

    int datoPixel;
    Pixel pixelAUX;

    switch (pImagen.getCodigo()[1])
    {
    case '1':
        for (int f=0; f<pImagen.getFilas(); f++)
        {
            for (int c=0; c<pImagen.getColumnas(); c++)
            {
                archivo>>datoPixel;

                if (datoPixel < 0 or datoPixel > pImagen.getRangoDinamico())
                    throw (excepcion);

                pixelAUX = pImagen.getPixel(f,c);
                pixelAUX.definirPixel(datoPixel,datoPixel,datoPixel);
                pImagen.setPixel(f, c, pixelAUX);
            }
        }
        break;

    case '2':
        for (int f=0; f<pImagen.getFilas(); f++)
        {
            for (int c=0; c<pImagen.getColumnas(); c++)
            {
                archivo>>datoPixel;

                if (datoPixel < 0 or datoPixel > pImagen.getRangoDinamico())
                    throw (excepcion);

                pixelAUX = pImagen.getPixel(f,c);
                pixelAUX.definirPixel(datoPixel,datoPixel,datoPixel);
                pImagen.setPixel(f, c, pixelAUX);
            }
        }
        break;

    case '3':
        for (int f=0; f<pImagen.getFilas(); f++)
        {
            for (int c=0; c<pImagen.getColumnas(); c++)
            {
                pixelAUX = pImagen.getPixel(f,c);

                archivo>>datoPixel;

                if (datoPixel < 0 or datoPixel > pImagen.getRangoDinamico())
                    throw (excepcion);

                pixelAUX.definirComponente(0,datoPixel);

                archivo>>datoPixel;

                if (datoPixel < 0 or datoPixel > pImagen.getRangoDinamico())
                    throw (excepcion);

                pixelAUX.definirComponente(1,datoPixel);

                archivo>>datoPixel;

                if (datoPixel < 0 or datoPixel > pImagen.getRangoDinamico())
                    throw (excepcion);

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
        if (rangoDinamico <= 0)
            throw (excepcion);
        pImagen.setRangoDinamico(rangoDinamico);
    }
    else
    {
        pImagen.setRangoDinamico(1);
    }

    string aux;
    getline(archivo, aux, '\n');

    unsigned char datoPixel = 0;
    Pixel pixelAUX;

    switch (pImagen.getCodigo()[1])
    {
    case '4':
        for (int f=0; f<pImagen.getFilas(); f++)
        {
            for (int c=0; c<pImagen.getColumnas(); c++)
            {
                archivo.read((char * ) &datoPixel , sizeof(datoPixel));

//                if (datoPixel < 0 or datoPixel > pImagen.getRangoDinamico())
//                    throw (excepcion);

                pixelAUX = pImagen.getPixel(f,c);
                pixelAUX.definirPixel(datoPixel,datoPixel,datoPixel);
                pImagen.setPixel(f, c, pixelAUX);
            }
        }
        break;

    case '5':
        for (int f=0; f<pImagen.getFilas(); f++)
        {
            for (int c=0; c<pImagen.getColumnas(); c++)
            {
                archivo.read((char * ) &datoPixel , sizeof(datoPixel));

//                if (datoPixel < 0 or datoPixel > pImagen.getRangoDinamico())
//                    throw (excepcion);

                pixelAUX = pImagen.getPixel(f,c);
                pixelAUX.definirPixel(datoPixel,datoPixel,datoPixel);
                pImagen.setPixel(f, c, pixelAUX);
            }
        }
        break;

    case '6': //error en los colores
        unsigned char r , g , b;
        r = g = b = 0;
        for (int f=0; f<pImagen.getFilas(); f++)
        {
            for (int c=0; c<pImagen.getColumnas(); c++)
            {
                pixelAUX = pImagen.getPixel(f,c);

                archivo.read((char * ) &r , sizeof(r));

//Ver esta excepcion, no se pueden comparar chars con valores enteros (0 y M)
//                if (r < 0 or r > pImagen.getRangoDinamico())
//                    throw (excepcion);

                archivo.read((char * ) &g , sizeof(g));

//                if (g < 0 or g > pImagen.getRangoDinamico())
//                    throw (excepcion);

                archivo.read((char * ) &b , sizeof(b));

//                if (b < 0 or b > pImagen.getRangoDinamico())
//                    throw (excepcion);

                pixelAUX.definirComponente(0, r);
                pixelAUX.definirComponente(1, g);
                pixelAUX.definirComponente(2, b);
                pImagen.setPixel(f, c, pixelAUX);
            }
        }
        break;
    }

    archivo.close();
}

