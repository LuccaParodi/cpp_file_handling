#ifndef GENEROS_H_INCLUDED
#define GENEROS_H_INCLUDED
#include "paises.h"

class generos{
private:
    int id;
    char Nombre [30];
    int pais; /// entre 1 y 100
    int AnioDeOrigen; ///Número entre 1500 y el año actual
    bool estado;

public:
    //SETTERS
    void setID(const int IDG){id=IDG;}
    void setNombre(const char *n){strcpy(Nombre,n);}
    void setPais(const int p){pais=p;}
    void setAnio(const int ado){AnioDeOrigen=ado;}
    void setESTADO(bool e){estado=e;}


    ///GETTERS


    int getID(){return id;}
    const char* getNombre(){return Nombre;}
    int getPais(){return pais;}
    int getAnio(){return AnioDeOrigen;}
    bool getESTADO(){return estado;}

    void AutoID() {
        FILE* pCli;
        pCli = fopen("generos.dat", "rb");
        if (pCli == NULL) {
            std::cout << "NO SE PUDO ABRIR EL ARCHIVO" << std::endl;
            return;
        }
        fseek(pCli, 0, SEEK_END);
        id = ftell(pCli) / sizeof(generos) + 1;
        fclose(pCli);   ///LEE EL ARCHIVO Y AL EJECUTARSE, LE SUMA 1 AL NUMERO DE REGISTROS PARA ASIGNAR LA NUEVA ID
    }



    void agregarGenero(){
        AutoID();
    //std::cout<<"Ingrese la ID del genero: ";
    //std::cin>>id;
    std::cout<<"Ingrese el Nombre: ";
    std::cin>>Nombre;

 bool paisValido = false;
    while (!paisValido) {
        CompararID();
        if (pais >= 1 && pais <= 100) {
            paisValido = true;
        } else {
            std::cout << "Por favor, ingrese un codigo de pais valido." << std::endl;
        }
    }
    std::cout<<"Ingrese el anio de origen del genero (1500 hasta el anio actual): ";
    std::cin>>AnioDeOrigen;
    while(AnioDeOrigen <1500 || AnioDeOrigen >2023){
        std::cout<<"por favor ingrese un anio valido"<<std::endl;
        std::cin>>AnioDeOrigen;
    }
    estado=true;
        }

    void mostrarGeneros(){
    std::cout<<"ID del genero: "<<id<<std::endl;
    std::cout<<"Nombre: "<<Nombre<<std::endl;
     std::cout<<"Codigo de pais: "<<pais<<std::endl;
      std::cout<<"Anio de origen del genero: "<<AnioDeOrigen<<std::endl;
    }


void CompararID() {
    Paises obj;
    bool PaisValido = false;
    while (!PaisValido) {
        std::cout << "Ingrese el ID del pais de origen del genero: ";
        std::cin >> pais;

        FILE* pPaises;
        pPaises = fopen("pais.dat", "rb");
        if (pPaises == NULL) {
            std::cout << "NO SE PUDO ABRIR EL ARCHIVO DE PAISES" << std::endl;
            return;
        }

        bool PaisEncontrado = false;
        while (fread(&obj, sizeof(Paises), 1, pPaises) == 1) {
            if (obj.getID() == pais) {
                PaisEncontrado = true;
            }
        }

        fclose(pPaises);

        if (PaisEncontrado) {
            PaisValido = true;
        } else {
            std::cout << "El ID del pais no existe en nuestros registros. Ingrese otro ID." << std::endl;
        }
    }
    /*EL FUNCIONAMIENTO ES BASTANTE SENCILLO, SE CREA UN BOOL EN FALSO PARA ENTRAR SI O SI AL LOOP, SE INGRESA LA ID DEL PAIS Y SE ABRE
    EL ARCHIVO DE PAIS EN LECTURA, ACTO SEGUIDO SE CREA OTRA BANDERA Y SE LEE EL ARCHIVO, COMPARANDO EL ID QUE INGRESAMOS CON ANTERIORIDAD
    CON EL DE UN OBJETO DE LA CLASE "PAISES", SI ESTO ES VERDADERO, CERRAMOS EL SEGUNDO BOOL, CERRAMOS EL ARCHIVO Y CERRAMOS EL PRIMER BOOL
    JUNTO CON EL LOOP EN SU TOTALIDAD, SI ESTO NO ES ASI, EL PROGRAMA ARROJA UN MENSAJE DE ERROR, FUNCIONA IGUAL CON LOS DEMAS "COMPARAR"*/
}


};


#endif // GENEROS_H_INCLUDED
