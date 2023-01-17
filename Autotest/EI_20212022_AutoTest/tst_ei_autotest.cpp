#include <QtTest>
// add necessary includes here
#include <vector>
#include <string>
#include "../../ProcesamientoDigital/imagen.h"
#include "../../ProcesamientoDigital/archivopnm.h"
#include "../../ProcesamientoDigital/archivoaic.h"
#include "../../ProcesamientoDigital/filtro.h"
#include "../../ProcesamientoDigital/filtromediana.h"
#include "../../ProcesamientoDigital/filtrosuavizado.h"
#include "../../ProcesamientoDigital/editorimagen.h"
#include "../../ProcesamientoDigital/lut.h"
#include "../../ProcesamientoDigital/gestordearchivos.h"
#include "../../ProcesamientoDigital/procesadorestadistico.h"


typedef unsigned int uint;

using namespace std;

class EI_AutoTest : public QObject
{
    Q_OBJECT
    
public:
    EI_AutoTest();
    ~EI_AutoTest();

private:
    // -*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-
    // -*-*-*-*-*- Archivos -*-*-*-*-*-
    // -*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-
    /*!
     * \brief listaDeArchivosDeImagen
     * \return Listado de archivos en directorio 1. Los nombres de archivo deben
     *  guardarse en un vector de strings.
     */
    vector<string> listaDeArchivosDeImagen();

    /*!
     * \brief tipoDeArchivo01 Determinar el tipo de archivo de imagen
     * \return Tipo de archivo
     */
    string tipoDeArchivo01();

    /*!
     * \brief tipoDeArchivo02 Determinar el tipo de archivo de imagen
     * \return Tipo de archivo
     */
    string tipoDeArchivo02();


    // -*-*-*-*-*-*-*-*-*--*-*-*-*-*-
    // -*-*-*-*-*- Imagen -*-*-*-*-*-
    // -*-*-*-*-*-*-*-*-*--*-*-*-*-*-
    /*!
     * \brief getFilasYColumnas01 Obtiene el número de filas y el número de
     * columnas de una imagen
     * \return Número de filas y columnas de la imagen
     */
    tuple<uint, uint> getFilasYColumnas01();

    /*!
     * \brief getIntensidadNivelDeGris01 Obtiene el nivel de gris en una
     * posición concreta de una imagen en formato P5
     * \return Nivel de gris
     */
    uint getIntensidadNivelDeGris01();

    /*!
     * \brief getIntensidadNivelDeGris02 Obtiene el nivel de gris en una
     * posición concreta de una imagen en formato P5
     * \return Nivel de gris
     */
    uint getIntensidadNivelDeGris02();

    /*!
     * \brief getIntensidadesRGB01 Obtiene el nivel de rojo, verde y azul en
     * una posición concreta de una imagen en formato P6
     * \return Niveles RGB
     */
    tuple<uint, uint, uint> getIntensidadesRGB01();

    /*!
     * \brief getIntensidadesRGB02 Obtiene el nivel de rojo, verde y azul en
     * una posición concreta de una imagen en formato P6
     * \return Niveles RGB
     */
    tuple<uint, uint, uint> getIntensidadesRGB02();

    /*!
     * \brief getIntensidadesRGB03 Obtiene el nivel de rojo, verde y azul en una
     *  posición concreta de una imagen en formato P6
     * \return Niveles RGB
     */
    tuple<uint, uint, uint> getIntensidadesRGB03();

    /*!
     * \brief getIntensidadesRGB04 Obtiene el nivel de rojo, verde y azul en una
     *  posición concreta de una imagen en formato P6
     * \return Niveles RGB
     */
    tuple<uint, uint, uint> getIntensidadesRGB04();

    // -*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-
    // -*-*-*-*-*- Procesamientos -*-*-*-*-*-
    // -*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-

    // -*-*-*-*-*- Histogramas -*-*-*-*-*-
    /*!
     * \brief getPixelGrisMasFrecuenteYSuCantidad01 Obtiene nivel de gris más
     * frecuente y su cantidad en una imagen en formato P5
     * \return Nivel de gris del pixel mas frecuente y su cantidad de
     * apariciones
     */
    tuple<int, uint> getPixelGrisMasFrecuenteYSuCantidad01();

    /*!
     * \brief getPixelColorMasFrecuenteYSuCantidad01 Obtiene nivel de gris más
     *  frecuente y su cantidad en una imagen en formato P6
     * \return Nivel de intensidad mas frecuente en canal R (rojo) y su
     * cantidad de apariciones
     */
    tuple<int, uint> getPixelColorMasFrecuenteYSuCantidad01();

    // -*-*-*-*-*- Filtrados -*-*-*-*-*-
    /*!
     * \brief getIntensidadMediaYLocalLuegoDeSuavizado01 Obtiene la intensidad
     * media y local de un pixel de una imagen en escala de intensidades antes
     * y después de aplicar el filtro de suavizado una vez
     * \return intensidad media antes y despues de aplicar el filtrado
     */
    tuple<uint, uint, uint, uint>
    getIntensidadMediaYLocalLuegoDeSuavizado01();


private slots:
    // -*-*-*-*-*- Archivos -*-*-*-*-*-
    void test_case_archivos_01();
    void test_case_archivos_02();
    void test_case_archivos_03();

    // -*-*-*-*-*- Imagen -*-*-*-*-*-
    void test_case_imagenes_01();
    void test_case_imagenes_pixeles_grises_01();
    void test_case_imagenes_pixeles_grises_02();
    void test_case_imagenes_pixeles_rgb_01();
    void test_case_imagenes_pixeles_rgb_02();
    void test_case_imagenes_pixeles_rgb_03();

    // -*-*-*-*-*- Procesamientos -*-*-*-*-*-
    // histograma
    void test_case_histograma_escala_grises_01();
    void test_case_histograma_rgb_01();
    // filtrados
    void test_case_suavizado_escala_grises_01();
};

EI_AutoTest::EI_AutoTest()
{

}

EI_AutoTest::~EI_AutoTest()
{

}

vector<string> EI_AutoTest::listaDeArchivosDeImagen()
{
    string ruta = "../EI_20212022_AutoTest/directorio_1/";
    vector<string> resultado;

    GestorDeArchivos gestor;
    gestor.setRaiz(ruta);
    resultado = gestor.getListaCarpetas();

    return resultado;
}

string EI_AutoTest::tipoDeArchivo01()
{
    string tipo;
    /** TODO: Cargar el tipo de archivo: P1, P2, P3, P4, P5 o P6, según
     *  corresponda de la imagen en el archivo "grupo_imagenes_1/test_01.pgm"
    */

    // Aquí el código de la prueba
    Archivo *ptrArchivo;
    Imagen imagenPrueba;
    string ruta = "../grupo_imagenes_1/test_01.pgm";
    string nombre = "test_01.pgm";
    string extension = nombre.substr(nombre.find_last_of('.'), nombre.size());
    if(extension == ".pbm" or  extension == ".pgm" or  extension == ".ppm" or  extension == ".pnm")
        ptrArchivo = new ArchivoPNM;
    else if(extension == ".aic")
        ptrArchivo = new ArchivoAIC;
    else (throw (string) "No se reconoce");

    imagenPrueba = ptrArchivo->leerImagen(ruta);

    delete ptrArchivo;

    tipo = imagenPrueba.getCodigo();

    return tipo;
}

string EI_AutoTest::tipoDeArchivo02()
{
    string tipo;

    /** TODO: Cargar el tipo de archivo: P1, P2, P3, P4, P5 o P6, según
     *  corresponda de la imagen en el archivo
     *  "grupo_imagenes_1/entre_rios_03.ppm"
    */
    // Aquí el código de la prueba
    Archivo *ptrArchivo;
    Imagen imagenPrueba;
    string ruta = "../grupo_imagenes_1/entre_rios_03.ppm";
    string nombre = "test_01.pgm";
    string extension = nombre.substr(nombre.find_last_of('.'), nombre.size());
    if(extension == ".pbm" or  extension == ".pgm" or  extension == ".ppm" or  extension == ".pnm")
        ptrArchivo = new ArchivoPNM;
    else if(extension == ".aic")
        ptrArchivo = new ArchivoAIC;
    else (throw (string) "No se reconoce");

    imagenPrueba = ptrArchivo->leerImagen(ruta);

    delete ptrArchivo;

    tipo = imagenPrueba.getCodigo();

    return tipo;
}

tuple<uint, uint> EI_AutoTest::getFilasYColumnas01()
{
    uint filas, columnas;
    filas = columnas = 0;
    /** TODO: Cargar el número de filas y el número de columnas de la imagen
     *  en el archivo "grupo_imagenes_1/test_01.pgm"
    */

    // Aquí el código de la prueba
    Archivo *ptrArchivo;
    Imagen imagenPrueba;
    string ruta = "../grupo_imagenes_1/test_01.pgm";
    string nombre = "test_01.pgm";
    string extension = nombre.substr(nombre.find_last_of('.'), nombre.size());
    if(extension == ".pbm" or  extension == ".pgm" or  extension == ".ppm" or  extension == ".pnm")
        ptrArchivo = new ArchivoPNM;
    else if(extension == ".aic")
        ptrArchivo = new ArchivoAIC;
    else (throw (string) "No se reconoce");

    imagenPrueba = ptrArchivo->leerImagen(ruta);

    delete ptrArchivo;

    filas = imagenPrueba.getAlto();
    columnas = imagenPrueba.getAncho();

    return make_tuple(filas, columnas);
}

uint EI_AutoTest::getIntensidadNivelDeGris01()
{
    uint nivelDeGris = -1;

    /* TODO: Retornar el nivel de gris en la posición (fila, columna) = (1, 3)
     *  de la imagen que se encuentra en el archivo:
     *      "grupo_imagenes_1/test_01.pgm"
     */

    // Aquí el código de la prueba
    Archivo *ptrArchivo;
    Imagen imagenPrueba;
    string ruta = "../grupo_imagenes_1/test_01.pgm";
    string nombre = "test_01.pgm";
    string extension = nombre.substr(nombre.find_last_of('.'), nombre.size());

    if(extension == ".pbm" or  extension == ".pgm" or  extension == ".ppm" or  extension == ".pnm")
        ptrArchivo = new ArchivoPNM;
    else if(extension == ".aic")
        ptrArchivo = new ArchivoAIC;
    else (throw (string) "No se reconoce");

    imagenPrueba = ptrArchivo->leerImagen(ruta);

    delete ptrArchivo;

    nivelDeGris = imagenPrueba.getPixel(1,3).getR();

    return nivelDeGris;
}

uint EI_AutoTest::getIntensidadNivelDeGris02()
{
    uint nivelDeGris = -1;

    /* TODO: Retornar el nivel de gris en la posición (fila, columna) = (1, 2)
     *  de la imagen que se encuentra en el archivo:
     *      "grupo_imagenes_1/test_01.pgm"
     */

    // Aquí el código de la prueba
    Archivo *ptrArchivo;
    Imagen imagenPrueba;
    string ruta = "../grupo_imagenes_1/test_01.pgm";
    string nombre = "test_01.pgm";
    string extension = nombre.substr(nombre.find_last_of('.'), nombre.size());

    if(extension == ".pbm" or  extension == ".pgm" or  extension == ".ppm" or  extension == ".pnm")
        ptrArchivo = new ArchivoPNM;
    else if(extension == ".aic")
        ptrArchivo = new ArchivoAIC;
    else (throw (string) "No se reconoce");

    imagenPrueba = ptrArchivo->leerImagen(ruta);

    delete ptrArchivo;

    nivelDeGris = imagenPrueba.getPixel(1,2).getR();

    return nivelDeGris;
}

tuple<uint, uint, uint> EI_AutoTest::getIntensidadesRGB01()
{
    uint R, G, B;
    R = G = B = -1;

    /* TODO: Cargar en las variables R, G y B el nivel de cada color
     * correspondiente a la posición (fila, columna) = (1, 3) de la imagen que
     * se encuentra en el archivo: "grupo_imagenes_1/test_02.ppm"
     */

    // Aquí el código de la prueba
    Archivo *ptrArchivo;
    Imagen imagenPrueba;
    string ruta = "../grupo_imagenes_1/test_02.ppm";
    string nombre = "test_02.ppm";
    string extension = nombre.substr(nombre.find_last_of('.'), nombre.size());

    if(extension == ".pbm" or  extension == ".pgm" or  extension == ".ppm" or  extension == ".pnm")
        ptrArchivo = new ArchivoPNM;
    else if(extension == ".aic")
        ptrArchivo = new ArchivoAIC;
    else (throw (string) "No se reconoce");

    imagenPrueba = ptrArchivo->leerImagen(ruta);

    delete ptrArchivo;

    R = imagenPrueba.getPixel(1,3).getR();
    G = imagenPrueba.getPixel(1,3).getG();
    B = imagenPrueba.getPixel(1,3).getB();


    return make_tuple(R, G, B);
}

tuple<uint, uint, uint> EI_AutoTest::getIntensidadesRGB02()
{
    uint R, G, B;
    R = G = B = -1;

    /* TODO: Cargar en las variables R, G y B el nivel de cada color
     * correspondiente a la posición (fila, columna) = (1, 2) de la imagen que
     * se encuentra en el archivo: "grupo_imagenes_1/test_02.ppm"
     */

    // Aquí el código de la prueba
    Archivo *ptrArchivo;
    Imagen imagenPrueba;
    string ruta = "../grupo_imagenes_1/test_02.ppm";
    string nombre = "test_02.ppm";
    string extension = nombre.substr(nombre.find_last_of('.'), nombre.size());

    if(extension == ".pbm" or  extension == ".pgm" or  extension == ".ppm" or  extension == ".pnm")
        ptrArchivo = new ArchivoPNM;
    else if(extension == ".aic")
        ptrArchivo = new ArchivoAIC;
    else (throw (string) "No se reconoce");

    imagenPrueba = ptrArchivo->leerImagen(ruta);

    delete ptrArchivo;

    R = imagenPrueba.getPixel(1,2).getR();
    G = imagenPrueba.getPixel(1,2).getG();
    B = imagenPrueba.getPixel(1,2).getB();


    return make_tuple(R, G, B);
}

tuple<uint, uint, uint> EI_AutoTest::getIntensidadesRGB03()
{
    uint R, G, B;
    R = G = B = -1;

    /* TODO: Cargar en las variables R, G y B el nivel de cada color
     * correspondiente a la posición (fila, columna) = (163, 401) de la imagen
     * que se encuentra en el archivo: "grupo_imagenes_1/entre_rios_03.ppm"
     */

    // Aquí el código de la prueba
    Archivo *ptrArchivo;
    Imagen imagenPrueba;
    string ruta = "../grupo_imagenes_1/entre_rios_03.ppm";
    string nombre = "entre_rios_03.ppm";
    string extension = nombre.substr(nombre.find_last_of('.'), nombre.size());

    if(extension == ".pbm" or  extension == ".pgm" or  extension == ".ppm" or  extension == ".pnm")
        ptrArchivo = new ArchivoPNM;
    else if(extension == ".aic")
        ptrArchivo = new ArchivoAIC;
    else (throw (string) "No se reconoce");

    imagenPrueba = ptrArchivo->leerImagen(ruta);

    delete ptrArchivo;

    R = imagenPrueba.getPixel(163, 401).getR();
    G = imagenPrueba.getPixel(163, 401).getG();
    B = imagenPrueba.getPixel(163, 401).getB();



    return make_tuple(R, G, B);
}

tuple<int, uint> EI_AutoTest::getPixelGrisMasFrecuenteYSuCantidad01()
{
    int nivel = -1;
    uint cantidad = -1;

    /* TODO: Cargar en las variables el nivel de gris más frecuente, y la
     * cantidad de veces que aparece en la imagen que se encuentra en el archivo:
     *      "grupo_imagenes_1/tigre_01.pgm"
     */

    // Aquí el código de la prueba
    Archivo *ptrArchivo;
    Imagen imagenPrueba;
    string ruta = "../grupo_imagenes_1/tigre_01.pgm";
    string nombre = "tigre_01.pgm";
    string extension = nombre.substr(nombre.find_last_of('.'), nombre.size());

    if(extension == ".pbm" or  extension == ".pgm" or  extension == ".ppm" or  extension == ".pnm")
        ptrArchivo = new ArchivoPNM;
    else if(extension == ".aic")
        ptrArchivo = new ArchivoAIC;
    else (throw (string) "No se reconoce");

    imagenPrueba = ptrArchivo->leerImagen(ruta);

    delete ptrArchivo;

    ProcesadorEstadistico procesador;
    procesador.procesarImagen(imagenPrueba);

    nivel = procesador.getModa().getR();
    cantidad = get<0>(procesador.getFrecuencias())[procesador.getModa().getR()];

    return make_tuple(nivel, cantidad);
}

tuple<int, uint> EI_AutoTest::getPixelColorMasFrecuenteYSuCantidad01()
{
    int nivelRojo = -1;
    uint cantidad = -1;

    /* TODO: Cargar en las variables el nivel de color rojo (R) más frecuente,
     * y la cantidad de veces que aparece en la imagen que se encuentra en
     * el archivo: "grupo_imagenes_2/predio_fi_uner_01.ppm"
     */

    // Aquí el código de la prueba

    Archivo *ptrArchivo;
    Imagen imagenPrueba;
    string ruta = "../grupo_imagenes_2/predio_fi_uner_01.ppm";
    string nombre = "predio_fi_uner_01.ppm";
    string extension = nombre.substr(nombre.find_last_of('.'), nombre.size());

    if(extension == ".pbm" or  extension == ".pgm" or  extension == ".ppm" or  extension == ".pnm")
        ptrArchivo = new ArchivoPNM;
    else if(extension == ".aic")
        ptrArchivo = new ArchivoAIC;
    else (throw (string) "No se reconoce");

    imagenPrueba = ptrArchivo->leerImagen(ruta);

    delete ptrArchivo;

    ProcesadorEstadistico procesador;
    procesador.procesarImagen(imagenPrueba);

    nivelRojo = procesador.getModa().getR();
    cantidad = get<0>(procesador.getFrecuencias())[procesador.getModa().getR()];

    return make_tuple(nivelRojo, cantidad);
}

tuple<uint, uint, uint, uint> EI_AutoTest::getIntensidadMediaYLocalLuegoDeSuavizado01()
{
    uint intensidad_media_inicial = -1;
    uint intensidad_media_final = -1;
    uint intensidad_local_inicial = -1;
    uint intensidad_local_final = -1;

    /* TODO: Calcular la intensidad media antes y despues de aplicar el
     * filtro de suavizado. Además obtener la intensidad del pixel en la
     * posición (50, 60) antes y después de aplicar el filtro de suavizado.
     * Lo anterior para la imagen que se encuentra en el archivo:
     *      "grupo_imagenes_1/hospital-robot_01.pgm"
     */

    // Aquí el código de la prueba

    Archivo *ptrArchivo;
    Imagen imagenPrueba;
    string ruta = "../grupo_imagenes_1/hospital-robot_01.pgm";
    string nombre = "hospital-robot_01.pgm";
    string extension = nombre.substr(nombre.find_last_of('.'), nombre.size());

    if(extension == ".pbm" or  extension == ".pgm" or  extension == ".ppm" or  extension == ".pnm")
        ptrArchivo = new ArchivoPNM;
    else if(extension == ".aic")
        ptrArchivo = new ArchivoAIC;
    else (throw (string) "No se reconoce");

    imagenPrueba = ptrArchivo->leerImagen(ruta);

    delete ptrArchivo;

    ProcesadorEstadistico procesador;
    procesador.procesarImagen(imagenPrueba);

    intensidad_media_inicial = procesador.getMedia().getR();
    intensidad_local_inicial = imagenPrueba.getPixel(50,60).getR();

    EditorImagen editor;

    editor.generarFiltro(imagenPrueba, 1);
    procesador.procesarImagen(imagenPrueba);

    intensidad_media_final = procesador.getMedia().getR();
    intensidad_local_final = imagenPrueba.getPixel(50,60).getR();


    return make_tuple(intensidad_media_inicial, intensidad_media_final, intensidad_local_inicial, intensidad_local_final);
}

// --------------------------------------------------
// --------------------------------------------------
// --------------------------------------------------

void EI_AutoTest::test_case_archivos_01()
{
    vector<string> archivos = {"archivo1.txt", "archivo2.pgm", "archivo3.pnm"};
    QCOMPARE(archivos, listaDeArchivosDeImagen());
}

void EI_AutoTest::test_case_archivos_02()
{
    QCOMPARE(string("P5"), tipoDeArchivo01());
}

void EI_AutoTest::test_case_archivos_03()
{
    QCOMPARE(string("P6"), tipoDeArchivo02());
}

void EI_AutoTest::test_case_imagenes_01()
{
    auto tupla1 = getFilasYColumnas01();
    auto tupla2 = make_tuple<unsigned, unsigned>(4,7);
    QCOMPARE(tupla1, tupla2);
}

void EI_AutoTest::test_case_imagenes_pixeles_grises_01()
{
    QCOMPARE(getIntensidadNivelDeGris01(), 182u);
}

void EI_AutoTest::test_case_imagenes_pixeles_grises_02()
{
    QCOMPARE(getIntensidadNivelDeGris02(), 54u);
}

void EI_AutoTest::test_case_imagenes_pixeles_rgb_01()
{
    QCOMPARE(getIntensidadesRGB01(), make_tuple(32u, 255u, 32u));
}

void EI_AutoTest::test_case_imagenes_pixeles_rgb_02()
{
    QCOMPARE(getIntensidadesRGB02(), make_tuple(255u, 32u, 32u));
}

void EI_AutoTest::test_case_imagenes_pixeles_rgb_03()
{
    QCOMPARE(getIntensidadesRGB03(), make_tuple(206u, 197u, 190u));
}

void EI_AutoTest::test_case_histograma_escala_grises_01()
{
    QCOMPARE(getPixelGrisMasFrecuenteYSuCantidad01(), make_tuple(142, 3058u));
}

void EI_AutoTest::test_case_histograma_rgb_01()
{
    QCOMPARE(getPixelColorMasFrecuenteYSuCantidad01(), make_tuple(112, 9207u));
}

void EI_AutoTest::test_case_suavizado_escala_grises_01()
{
    QCOMPARE(getIntensidadMediaYLocalLuegoDeSuavizado01(), make_tuple(137u, 137u, 123u, 124u));
}

QTEST_APPLESS_MAIN(EI_AutoTest)

#include "tst_ei_autotest.moc"
