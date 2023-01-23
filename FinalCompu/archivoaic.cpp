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
    archivo.open(pNombreArchivo, ios::in);
    Imagen imagen;
    string identificacion, descripcion;
    int filas, columnas;
    int rangoDin;
    char numeral;

    if (!archivo.is_open())
        cout<<"Error.";

    archivo>>identificacion;    archivo.ignore();
    imagen.setCodigo(identificacion);
    //control de error para el codigo

    archivo>>numeral;
    if (numeral!='#')
        cout<<"Error. (corrupta)";

    getline(archivo, descripcion);
    imagen.setDescripcion(descripcion);

    archivo>>columnas;
    imagen.setColumnas(columnas);//agregar ignorar los espacios

    archivo>>filas;
    imagen.setFilas(filas);

    imagen.dimensionar();

    archivo>>rangoDin;
    imagen.setRangoDinamico(rangoDin);

    archivo.ignore();

    int datoPixel, repeticiones;
    int contadorColumnas=0, contadorRepeticiones=0;

    Pixel pixelAUX;

    for (int f=0; f<filas; f++)
    {
        do
        {
            archivo >> datoPixel >> repeticiones;
            //control de error datoPixel y repeticiones>0

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
                cout<<"Error.";
            if (archivo.eof() and (f<filas or contadorColumnas<columnas))
                cout<<"Error.";

        } while (contadorColumnas<columnas);

        contadorColumnas=0;
    }

    return imagen;
}

void ArchivoAIC::escribirImagen(Imagen &imagen, string pNombreArchivo, string directorio)
{

}
