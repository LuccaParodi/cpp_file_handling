#ifndef REPORTES_H_INCLUDED
#define REPORTES_H_INCLUDED
#include <iostream>
#include "obj musicos.h"
#include "generos.h"
#include "instrumentos.h"
#include "paises.h"
#include "fecha.h"

///1) A partir de un nombre de país que se ingresa por teclado, generar un archivo con todos los géneros que tengan ese país como país de origen. Listar el archivo nuevo.

///2) Informar el año de origen del presente siglo con menor cantidad de géneros musicales.

///3) Hacer un listado de los músicos del claustro no docente utilizando asignación dinámica de memoria.



void consigna1()
{
    Paises obj;
    generos reg;
    bool encontro = false;
    char nombrePais[30];

    FILE* archivoPaises = fopen("pais.dat", "rb");
    if (archivoPaises == NULL)
    {
        std::cout << "NO SE PUDO ABRIR EL ARCHIVO DE PAISES" << std::endl;
        return;
    }

    std::cout << "Ingrese el nombre del pais a buscar: ";
    std::cin >> nombrePais;

    while (fread(&obj, sizeof(Paises), 1, archivoPaises) == 1)
    {
        if (obj.getESTADO() && strcmp(obj.getNombre(), nombrePais) == 0)
        {
            obj.MostrarPaises();
            std::cout << std::endl;
            encontro = true;

            FILE* archivoGeneros = fopen("generos.dat", "rb");
            if (archivoGeneros == NULL)
            {
                std::cout << "NO SE PUDO ABRIR EL ARCHIVO DE GENEROS" << std::endl;
                fclose(archivoPaises);
                return;
            }

            FILE* archivoGenerosPorPais = fopen("consigna1.dat", "ab");
            if (archivoGenerosPorPais == NULL)
            {
                std::cout << "NO SE PUDO CREAR EL ARCHIVO DE GENEROS" << std::endl;
                fclose(archivoPaises);
                fclose(archivoGeneros);
                return;
            }

            int idPais = obj.getID();

            fwrite(nombrePais, sizeof(char), strlen(nombrePais), archivoGenerosPorPais);
            fwrite("\n", sizeof(char), 1, archivoGenerosPorPais);


            while (fread(&reg, sizeof(generos), 1, archivoGeneros) == 1)
            {
                if (reg.getPais() == idPais)
                {
                    reg.mostrarGeneros();
                    std::cout << std::endl;

                    fwrite(reg.getNombre(), sizeof(char), strlen(reg.getNombre()), archivoGenerosPorPais);
                    fwrite("\n", sizeof(char), 1, archivoGenerosPorPais);
                }
            }

            fclose(archivoGeneros);
            fclose(archivoGenerosPorPais);
        }
    }

    fclose(archivoPaises);

    if (!encontro)
    {
        std::cout << "NO SE ENCONTRO ESE PAIS" << std::endl;
    }

    system("pause");
    system("cls");
}


void consigna2()
{
    generos obj;
    FILE* archivoGeneros = fopen("generos.dat", "rb");
    if (archivoGeneros == NULL)
    {
        std::cout << "NO SE PUDO LEER EL ARCHIVO" << std::endl;
        return;
    }

    std::time_t tiempoActual = std::time(nullptr);
    std::tm* fechaActual = std::localtime(&tiempoActual);
    int anioActual = fechaActual->tm_year + 1900;

    int* GenerosPorAnio = new int[anioActual - 2000 + 1] {0};

    while (fread(&obj, sizeof(obj), 1, archivoGeneros) == 1)
    {
        if (obj.getESTADO())
        {
            int anio = obj.getAnio();
            if (anio >= 2000 && anio <= anioActual)
            {
                GenerosPorAnio[anio - 2000]++;
            }
        }
    }

    int menorCantidadGeneros = GenerosPorAnio[0];
    int anioMenorCantidadGeneros = 2000;
    for (int i = 1; i < anioActual - 2000 + 1; i++)
    {
        if (GenerosPorAnio[i] < menorCantidadGeneros)
        {
            menorCantidadGeneros = GenerosPorAnio[i];
            anioMenorCantidadGeneros = 2000 + i;
        }
    }

    delete[] GenerosPorAnio;
    fclose(archivoGeneros);

    std::cout << "El anio de origen del presente siglo con menor cantidad de generos musicales es: " << anioMenorCantidadGeneros << std::endl;

    system("pause");
    system("cls");
}




void consigna3()
{
    musicos obj;
    FILE* pCli;
    pCli = fopen("musicos.dat", "rb");
    if (pCli == NULL)
    {
        std::cout << "NO SE PUDO LEER EL ARCHIVO" << std::endl;
        return;
    }


    int contador = 0;

    while (fread(&obj, sizeof(obj), 1, pCli) == 1)
    {
        if (obj.getESTADO() && obj.getClaustro() == 3)
        {
            contador++;
        }
    }


    musicos* vec = new musicos[contador];


    fseek(pCli, 0, SEEK_SET);

    int i = 0;
    while (fread(&obj, sizeof(obj), 1, pCli) == 1)
    {
        if (obj.getESTADO() && obj.getClaustro() == 3)
        {
            vec[i] = obj;
            i++;
        }
    }

    fclose(pCli);


    for (int j = 0; j < contador; j++)
    {
        vec[j].mostrarmusicos();
        std::cout << std::endl;
    }


    delete[] vec;

    system("pause");
    system("cls");
}




#endif // REPORTES_H_INCLUDED
