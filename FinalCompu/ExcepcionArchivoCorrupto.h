#ifndef EXCEPCIONARCHIVOCORRUPTO_H
#define EXCEPCIONARCHIVOCORRUPTO_H

#endif // EXCEPCIONARCHIVOCORRUPTO_H

#include <stdexcept>
using namespace std;

class ExcepcionArchivoCorrupto : public runtime_error
{
public:
    ExcepcionArchivoCorrupto()
        : runtime_error ("Archivo corrupto. No se puede abrir la imagen. ") {}
};
