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
                cout << "Archivo corrupto." << endl;
            }
        }

        return imagen;
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

    int datoPixel;
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

    case '6': //error en los colores
        unsigned char r , g , b;
        r = g = b = 0;
        for (unsigned int f=0; f<pImagen.getFilas(); f++)
        {
            for (unsigned int c=0; c<pImagen.getColumnas(); c++)
            {
                pixelAUX = pImagen.getPixel(f,c);

                archivo.read((char * ) &r , sizeof(r));
                archivo.read((char * ) &g , sizeof(g));
                archivo.read((char * ) &b , sizeof(b));
                //agregar control de error, datoPixel <=M y >= 0

                //pixelAUX.definirPixel(r,g,b);
                pixelAUX.definirComponente(0, r);
                pixelAUX.definirComponente(1, g);
                pixelAUX.definirComponente(2, b);
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

