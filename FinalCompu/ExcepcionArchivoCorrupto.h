#ifndef EXCEPCIONARCHIVOCORRUPTO_H
#define EXCEPCIONARCHIVOCORRUPTO_H
#include <stdexcept>
using namespace std;

/**
 * @brief Manejo de excepciones para archivos corruptos
 */

class ExcepcionArchivoCorrupto : public runtime_error
{
public:
    ExcepcionArchivoCorrupto()
        : runtime_error ("Archivo corrupto. No se puede abrir la imagen. ") {}
};

#endif // EXCEPCIONARCHIVOCORRUPTO_H
