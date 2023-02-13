#ifndef INTERFAZ_H
#define INTERFAZ_H
#include <gestordearchivos.h>
#include <windows.h>

/**
 * @brief Muestra los textos por consola, permite que el usuario interactue con el graficador
 * @author Machado Joaquin
 */

class Interfaz
{
public:
    /**
     * @brief Interfaz Contructor de clase Interfaz
     * @param pGestor Puntero a gestor de archivo
     */
    Interfaz(GestorDeArchivos *pGestor);

    /**
     * @brief mostrarAtajos Muestra los atajos de teclado disponibles
     */
    void mostrarAtajos();

    /**
     * @brief mostrarArchivos Muestra los archivos disponibles
     */
    void mostrarArchivos();

    /**
     * @brief mostrarOpcionesDeGuardado Muestra las opciones de guardado
     * @param cod Codigo de la imagen a guardar
     */
    void mostrarOpcionesDeGuardado(string cod);

    /**
     * @brief mostrarLUTS Muestra las tablas LUT disponibles
     */
    void mostrarLUTS();

    /**
     * @brief elegirArchivo Permite al usuario seleccionar un archivo
     */
    void elegirArchivo();

    /**
     * @brief definirNombreDeGuardado Permite al usuario ingresar el nombre con el que desea guardar la imagen
     * @return String con el nombre que eligio el usuario
     */
    string definirNombreDeGuardado();

    /**
     * @brief definirOpcion Perimte al usuario ingresar una opcion
     * @return Entero de 4 bytes con la opcion elegida
     */
    int definirOpcion();

    /**
     * @brief definirUmbralBinarizado Permite al usuario elegir un umbral para binarizar
     * @return Entero de 4 bytes con el umbral elegido
     */
    int definirUmbralBinarizado();

    /**
     * @brief opcNoPermitida Informa que no se permite la opcion seleccionada
     */
    void opcNoPermitida();

    /**
     * @brief opcionesDeCarpetas Muestra las carpetas disponibles
     * @return Entero de 4 bytes con la opcion de carpeta elegida
     */
    int opcionesDeCarpetas();

    /**
     * @brief preguntarSiSeguir Pregunta si quiere seguir con el programa
     * @return Bool que define si se sigue o no con el programa
     */
    bool preguntarSiSeguir();

    /**
     * @brief finPrograma Muestra texto de fin de programa
     */
    void finPrograma();

    /**
     * @brief limpiar Limpia los textos en consola
     */
    void limpiar();

    /**
     * @brief seAbrio Informa que se abrio una imagen
     * @param pNombre Nombre de la imagen
     */
    void seAbrio(string pNombre);

    /**
     * @brief seAplico Informa que se aplico una LUT
     * @param nombreLUT Nombre de la LUT
     */
    void seAplico (string nombreLUT);

    /**
     * @brief areaDetectada Informa el area detectada
     * @param area Area detectada
     */
    void areaDetectada (int area);

    /**
     * @brief informarAtajo Informa el atajo seleccionado
     * @param atajo Atajo seleccionado
     */
    void informarAtajo (char atajo);

private:
    GestorDeArchivos *ptrGestorDeArchivos; /**< Puntero a gestor de archivos */
};

#endif // INTERFAZ_H
