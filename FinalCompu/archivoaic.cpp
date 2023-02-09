#include "archivoaic.h"
#include "archivo.h"

ArchivoAIC::~ArchivoAIC()
{

}

ArchivoAIC::ArchivoAIC()
{

}

Imagen ArchivoAIC::leerImagen(string pNombreArchivo)
{
    archivo.open(pNombreArchivo, ios::in );
    Imagen imagen;
    string codigo, descripcion;
    int filas, columnas;
    int rangoDin;
    char numeral;

    if (!archivo.is_open())
        cout << "No se pudo abrir el archivo. " << endl;
    else
    {
        try
        {
            archivo>>codigo;    archivo.ignore();
            if (codigo!="P2C")
            {
                imagen.estaCorrupta();
                throw (ExcepcionArchivoCorrupto());
            }
            imagen.setCodigo(codigo);

            archivo>>numeral;
            if (numeral != '#')
            {
                imagen.estaCorrupta();
                throw (ExcepcionArchivoCorrupto());
            }

            getline(archivo, descripcion);
            imagen.setDescripcion(descripcion);

            archivo>>columnas;
            if (columnas <= 0)
            {
                imagen.estaCorrupta();
                throw (ExcepcionArchivoCorrupto());
            }
            imagen.setColumnas(columnas);

            archivo>>filas;
            if (filas <= 0)
            {
                imagen.estaCorrupta();
                throw (ExcepcionArchivoCorrupto());
            }
            imagen.setFilas(filas);

            imagen.dimensionar();

            archivo>>rangoDin;
            imagen.setRangoDinamico(rangoDin);
            if (filas <= 0)
            {
                imagen.estaCorrupta();
                throw (ExcepcionArchivoCorrupto());
            }

            archivo.ignore();

            int datoPixel, repeticiones;
            int contadorColumnas=0, contadorRepeticiones=0;

            Pixel pixelAUX;

            for (int f=0; f<filas; f++)
            {
                do
                {
                    archivo >> datoPixel >> repeticiones;
                    if (datoPixel > rangoDin or datoPixel < 0 or repeticiones <= 0)
                    {
                        imagen.estaCorrupta();
                        throw (ExcepcionArchivoCorrupto());
                    }

                    while (contadorRepeticiones<repeticiones)
                    {
                        pixelAUX = imagen.getPixel(f, contadorColumnas);
                        pixelAUX.definirPixel(datoPixel,datoPixel,datoPixel);
                        imagen.setPixel(f,contadorColumnas,pixelAUX);

                        contadorColumnas++;
                        contadorRepeticiones++;
                    }
                    contadorRepeticiones=0;

                    if (contadorColumnas>columnas)
                    {

                        throw (ExcepcionArchivoCorrupto());
                    }
                    if (archivo.eof() and (f<filas or contadorColumnas<columnas))
                    {
                        imagen.estaCorrupta();
                        throw (ExcepcionArchivoCorrupto());
                    }

                } while (contadorColumnas<columnas);

                contadorColumnas=0;
            }
        }
        catch (runtime_error &excep)
        {
            system("CLS");
            puts(excep.what());
            exit(0);
        }

        return imagen;
    }
}

void ArchivoAIC::escribirImagen(Imagen &imagen, string pNombreArchivo, string directorio)
{
    int intensidad, intensidadSiguiente;
    int repeticiones = 0;
    bool dejarDeContar;
    Pixel pixelAux;
    ProcesadorEstadistico procesador;
    procesador.setPtrImagen(&imagen);

    Pixel max = procesador.maximo();
    int M = 0;
    for (int i=0; i<3; i++)
    {
        if (max.devolverComponente(i)>M)
            M = max.devolverComponente(i);
    }
    imagen.setRangoDinamico(M);

    int filas = imagen.getFilas();
    int columnas = imagen.getColumnas();

    archivo.open(directorio + pNombreArchivo + ".aic", ios::out | ios::trunc);

    if (!archivo.is_open())
        cout << "No se pudo guardar el archivo." << endl;
    else
    {
        archivo << "P2C" << endl;
        archivo << "#"<<imagen.getDescripcion()<<endl;
        archivo << columnas << " " << filas <<endl;
        archivo << imagen.getRangoDinamico() << endl;

        for (int f=0; f<filas; f++)
        {
            for (int c=0; c<columnas; c++)
            {
                pixelAux = imagen.getPixel(f,c);
                intensidad = pixelAux.devolverComponente(0);
                repeticiones++;

                if (imagen.estaEnLaImagen(f,c+1))
                {
                    pixelAux = imagen.getPixel(f,c+1);
                    intensidadSiguiente = pixelAux.devolverComponente(0);

                    if (intensidad != intensidadSiguiente)
                    {
                        dejarDeContar = true;
                        archivo << intensidad << " " << repeticiones << " ";
                        repeticiones = 0;
                    }
                }

                if (c == columnas-1)
                {
                    dejarDeContar = true;
                    archivo << intensidad << " " << repeticiones<< " ";
                    repeticiones = 0;
                }

                if (repeticiones == 0)
                {
                    dejarDeContar = false;
                }
            }
        }
    }

    archivo.close();
}
