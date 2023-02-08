#include "procesadorestadistico.h"
#include <bits/stdc++.h>

ProcesadorEstadistico::ProcesadorEstadistico()
{

}

void ProcesadorEstadistico::setPtrImagen(Imagen *pImagen)
{
    ptrImagen = pImagen;
}

vector <float> ProcesadorEstadistico::promedio()
{
    vector <float> prom;
    prom.resize(3);
    int totalDePixeles = ptrImagen->getFilas() * ptrImagen->getColumnas();
    Pixel pixelAux;
    if (ptrImagen->getCodigo() == "P3" or ptrImagen->getCodigo() == "P6")
    {
        int sumaR = 0, sumaG = 0, sumaB = 0;
        for (int f=0; f<ptrImagen->getFilas(); f++)
        {
            for(int c=0; c<ptrImagen->getColumnas(); c++)
            {
                pixelAux = ptrImagen->getPixel(f,c);

                sumaR += pixelAux.devolverComponente(0);
                sumaG += pixelAux.devolverComponente(1);
                sumaB += pixelAux.devolverComponente(2);
            }
        }
        prom[0]=sumaR/(float)totalDePixeles;
        prom[1]=sumaG/(float)totalDePixeles;
        prom[2]=sumaB/(float)totalDePixeles;
    }
    else
    {
        int suma=0;
        for (int f=0; f<ptrImagen->getFilas(); f++)
        {
            for(int c=0; c<ptrImagen->getColumnas(); c++)
            {
                pixelAux = ptrImagen->getPixel(f,c);

                suma += pixelAux.devolverComponente(0);
            }
        }
        prom[0] = prom[1] = prom[2] = suma/(float)totalDePixeles;
    }
    return prom;
}

Pixel ProcesadorEstadistico::mediana(vector<Pixel> datos)
{
    Pixel med;

    vector <int> datosR, datosG, datosB;

    for (unsigned int i = 0; i<datos.size(); i++)
    {
        datosR.push_back(datos[i].devolverComponente(0));
        datosG.push_back(datos[i].devolverComponente(1));
        datosB.push_back(datos[i].devolverComponente(2));
    }

    sort(datosR.begin(), datosR.end());
    sort(datosG.begin(), datosG.end());
    sort(datosB.begin(), datosB.end());

    int longitud = datos.size();
    if (longitud%2 != 0)
    {
        med.definirPixel(datosR[(longitud+1)/2], datosG[(longitud+1)/2], datosB[(longitud+1)/2]);
    }
    else
    {
        int medianaR, medianaG, medianaB;

        medianaR = (datosR[longitud/2]+datosR[(longitud/2)+1])/2;
        medianaG = (datosG[longitud/2]+datosG[(longitud/2)+1])/2;
        medianaB = (datosB[longitud/2]+datosB[(longitud/2)+1])/2;

        med.definirPixel(medianaR, medianaG, medianaB);
    }

    datosR.clear();
    datosG.clear();
    datosB.clear();

    return med;
}

Pixel ProcesadorEstadistico::minimo()
{
    int M = ptrImagen->getRangoDinamico();
    Pixel min (M, M, M);
    Pixel pixelAUX;

    if (ptrImagen->getCodigo() == "P3" or ptrImagen->getCodigo() == "P6")
    {
        for (int f=0; f<ptrImagen->getFilas(); f++)
        {
            for(int c=0; c<ptrImagen->getColumnas(); c++)
            {
                pixelAUX = ptrImagen->getPixel(f,c);

                if (pixelAUX.devolverComponente(0) < min.devolverComponente(0))
                    min.definirComponente(0, pixelAUX.devolverComponente(0));

                if (pixelAUX.devolverComponente(1) < min.devolverComponente(1))
                    min.definirComponente(1, pixelAUX.devolverComponente(1));

                if (pixelAUX.devolverComponente(2) < min.devolverComponente(2))
                    min.definirComponente(2, pixelAUX.devolverComponente(2));
            }
        }
    }
    else
    {
        for (int f=0; f<ptrImagen->getFilas(); f++)
        {
            for(int c=0; c<ptrImagen->getColumnas(); c++)
            {
                pixelAUX = ptrImagen->getPixel(f,c);
                if (pixelAUX.devolverComponente(0) < min.devolverComponente(0))
                    min = pixelAUX;
            }
        }
    }

    return min;
}

Pixel ProcesadorEstadistico::maximo()
{
    Pixel max (0,0,0);
    Pixel pixelAUX;

    if (ptrImagen->getCodigo() == "P3" or ptrImagen->getCodigo() == "P6")
    {
        for (int f=0; f<ptrImagen->getFilas(); f++)
        {
            for(int c=0; c<ptrImagen->getColumnas(); c++)
            {
                pixelAUX = ptrImagen->getPixel(f,c);

                if (pixelAUX.devolverComponente(0) > max.devolverComponente(0))
                    max.definirComponente(0, pixelAUX.devolverComponente(0));

                if (pixelAUX.devolverComponente(1) > max.devolverComponente(1))
                    max.definirComponente(1, pixelAUX.devolverComponente(1));

                if (pixelAUX.devolverComponente(2) > max.devolverComponente(2))
                    max.definirComponente(2, pixelAUX.devolverComponente(2));
            }
        }
    }
    else
    {
        for (int f=0; f<ptrImagen->getFilas(); f++)
        {
            for(int c=0; c<ptrImagen->getColumnas(); c++)
            {
                pixelAUX = ptrImagen->getPixel(f,c);

                if (pixelAUX.devolverComponente(0) > max.devolverComponente(0))
                    max = pixelAUX;
            }
        }
    }

    return max;
}

void ProcesadorEstadistico::modaGrises(vector<int> &datosDeFrecuencia)
{
    int frecuenciaMax = 0;
    int posDeMaximaFrecuencia;

    for (unsigned int i=0; i<datosDeFrecuencia.size(); i++)
    {
        if (datosDeFrecuencia[i]>frecuenciaMax)
        {
            posDeMaximaFrecuencia = i;
            frecuenciaMax = datosDeFrecuencia[i];
        }
    }

    mayorFrecuencia = frecuenciaMax;
    cout << "El valor de mayor frecuencia es " << posDeMaximaFrecuencia << ", se repite " << frecuenciaMax << " veces." <<endl;
}

void ProcesadorEstadistico::modaRGB(vector<vector<int> > &datosDeFrecuencia)
{
    int frecuenciaMax = 0;
    int posDeMaximaFrecuencia;
    mayorFrecuencia = 0;

    vector < tuple <int,int> > datosModa; //tuple<posMaxFrec><frecuenciaMax>
    datosModa.resize(3);

    for (int componente = 0; componente<3; componente++)
    {
        for (int pos = 0; pos< ptrImagen->getRangoDinamico()+1; pos++)
        {
            if (datosDeFrecuencia[componente][pos]>frecuenciaMax)
            {
                posDeMaximaFrecuencia = pos;
                frecuenciaMax = datosDeFrecuencia[componente][pos];
            }
        }

        datosModa[componente] = make_tuple (posDeMaximaFrecuencia, frecuenciaMax);

        frecuenciaMax = 0;
    }

    for (int i = 0; i<3; i++)
    {
       if (get<1>(datosModa[i]) > mayorFrecuencia)
           mayorFrecuencia = get<1>(datosModa[i]);
    }

    cout << "El valor de mayor frecuencia R es " << get<0>(datosModa[0]) << ", se repite " << get<1>(datosModa[0]) << " veces." <<endl;
    cout << "El valor de mayor frecuencia G es " << get<0>(datosModa[1]) << ", se repite " << get<1>(datosModa[1]) << " veces." <<endl;
    cout << "El valor de mayor frecuencia B es " << get<0>(datosModa[2]) << ", se repite " << get<1>(datosModa[2]) << " veces." <<endl;
}

vector<float> ProcesadorEstadistico::desvioEstandar()
{
    int totalDePixeles = ptrImagen->getFilas() * ptrImagen->getColumnas();
    vector <float> prom = promedio();
    Pixel pixelAux;
    vector <float> desvio;
    desvio.resize(3);

    if (ptrImagen->getCodigo() == "P3" or ptrImagen->getCodigo() == "P6")
    {
        float sumaDeDiferenciasR = 0, sumaDeDiferenciasG = 0, sumaDeDiferenciasB = 0;
        for (int f=0; f<ptrImagen->getFilas(); f++)
        {
            for(int c=0; c<ptrImagen->getColumnas(); c++)
            {
                pixelAux = ptrImagen->getPixel(f,c);

                sumaDeDiferenciasR += (pixelAux.devolverComponente(0)-prom[0])*(pixelAux.devolverComponente(0)-prom[0]);
                sumaDeDiferenciasG += (pixelAux.devolverComponente(1)-prom[1])*(pixelAux.devolverComponente(1)-prom[1]);
                sumaDeDiferenciasB += (pixelAux.devolverComponente(2)-prom[2])*(pixelAux.devolverComponente(2)-prom[2]);
            }
        }
        desvio[0] = sqrt(sumaDeDiferenciasR/(float)totalDePixeles);
        desvio[1] = sqrt(sumaDeDiferenciasG/(float)totalDePixeles);
        desvio[2] = sqrt(sumaDeDiferenciasB/(float)totalDePixeles);
    }
    else
    {
        float sumaDeDiferencias = 0;
        for (int f=0; f<ptrImagen->getFilas(); f++)
        {
            for(int c=0; c<ptrImagen->getColumnas(); c++)
            {
                pixelAux = ptrImagen->getPixel(f,c);

                sumaDeDiferencias += (pixelAux.devolverComponente(0)-prom[0])*(pixelAux.devolverComponente(0)-prom[0]);
            }
        }
        desvio[0] = sqrt(sumaDeDiferencias/(float)totalDePixeles);
        desvio[1] = sqrt(sumaDeDiferencias/(float)totalDePixeles);
        desvio[2] = sqrt(sumaDeDiferencias/(float)totalDePixeles);
    }
    return desvio;
}

vector<vector<int> > ProcesadorEstadistico::obtenerDatosPixelesRGB()
{
    vector<vector<int>> datos;
    datos.resize(3, vector<int>(ptrImagen->getRangoDinamico()+1, 0));
    Pixel pixelAux;
    int valor_r,valor_g,valor_b;

    for (int f=0; f<ptrImagen->getFilas(); f++)
    {
        for (int c=0; c<ptrImagen->getColumnas(); c++)
        {
            pixelAux = ptrImagen->getPixel(f,c);

            valor_r = pixelAux.devolverComponente(0);
            datos[0][valor_r]++;

            valor_g = pixelAux.devolverComponente(1);
            datos[1][valor_g]++;

            valor_b = pixelAux.devolverComponente(2);
            datos[2][valor_b]++;
        }
    }

    return datos;
}

vector<int> ProcesadorEstadistico::obtenerDatosPixelesMonocGrises()
{
    int M = ptrImagen->getRangoDinamico();
    vector <int> datos;
    datos.resize(M+1,0);

    Pixel pixelAux;
    int valor;

    for (int f=0; f<ptrImagen->getFilas(); f++)
    {
        for (int c=0; c<ptrImagen->getColumnas(); c++)
        {
            pixelAux = ptrImagen->getPixel(f,c);
            valor = pixelAux.devolverComponente(0);
            datos[valor]++;
        }
    }

    return datos;
}

int ProcesadorEstadistico::getMayorFrecuencia() const
{
    return mayorFrecuencia;
}


