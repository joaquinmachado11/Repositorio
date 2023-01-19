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

    int datoPixel, repeticiones;
    int contadorColumnas=0, contadorRepeticiones=0;

    for (int f=0; f<filas; f++)
    {
        do
        {
            archivo >> datoPixel >> repeticiones;

            while (contadorRepeticiones<repeticiones)
            {
                imagen.getPixel(f, contadorColumnas).definirPixel(datoPixel,datoPixel,datoPixel);
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
