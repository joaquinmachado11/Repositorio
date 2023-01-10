#include "archivopnm.h"
#include "archivo.h"

ArchivoPNM::ArchivoPNM()
{

}

Imagen ArchivoPNM::cargarImagen(string nombreArchivo)
{
    Imagen imagen;
    string identificacion;
    int filas, columnas, rangodinamico;

    archivo.open(nombreArchivo, ios::in);
/*
    ifstream input_file(filename);
        if (!input_file.is_open()) {
            cerr << "Could not open the file - '"
                << filename << "'" << endl;
            return EXIT_FAILURE;
    }
*/
    archivo>>identificacion;    archivo.ignore();

    if (identificacion=="P1" or identificacion=="P2" or identificacion=="P3")
    {
        //ignorar linea q comienza con #
        archivo>>columnas;
        imagen.setColumnas(columnas);//agregar ignorar los espacios
        archivo>>filas;
        imagen.setFilas(filas);

        imagen.dimensionar();

        if (identificacion=="P2" or identificacion=="P3")
        {
            archivo>>rangodinamico;
            imagen.setRangoDinamico(rangodinamico);
        }

        if (identificacion=="P1") //monocromatico
        {
            int datoPixel;

            for (unsigned int f=0; f<filas; f++)
            {
                for (unsigned int c=0; c<columnas; c++)
                {
                    archivo>>datoPixel; //agregar control de error
                    imagen.getPixel(f,c).definirComponente(0,datoPixel);
                }
            }
        }

        if (identificacion=="P2") //escala de grises
        {
            int datoPixel;

            for (unsigned int f=0; f<filas; f++)
            {
                for (unsigned int c=0; c<columnas; c++)
                {
                    archivo>>datoPixel; //agregar control de error
                    imagen.getPixel(f,c).definirComponente(0,datoPixel);
                }
            }
        }

        if (identificacion=="P3") //RGB
        {
            int datoPixel;

            for (unsigned int f=0; f<filas; f++)
            {
                for (unsigned int c=0; c<columnas; c++)
                {
                    archivo>>datoPixel; //agregar control de error
                    imagen.getPixel(f,c).definirComponente(0,datoPixel);

                    archivo>>datoPixel;
                    imagen.getPixel(f,c).definirComponente(1,datoPixel);

                    archivo>>datoPixel;
                    imagen.getPixel(f,c).definirComponente(2,datoPixel);
                }
            }
        }
    }
}
