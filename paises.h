#ifndef PAISES_H_INCLUDED
#define PAISES_H_INCLUDED

class Paises{
private:
    int id;
    char nombre[30];
    char continente[30];
    bool estado;

public:

    ///SETTERS
     void setID(const int IDP){id=IDP;}
    void setNombre(const char *n){strcpy(nombre,n);}
    void setContinente(const char *c){strcpy(continente,c);}
    void setESTADO(bool e){estado=e;}

    ///GETTERS
    int getID(){return id;}
    const char* getNombre(){return nombre;}
    const char* getContinente(){return continente;}
    bool getESTADO(){return estado;}


    void AutoID() {
        FILE* pCli;
        pCli = fopen("pais.dat", "rb");
        if (pCli == NULL) {
            std::cout << "NO SE PUDO ABRIR EL ARCHIVO" << std::endl;
            return;
        }
        fseek(pCli, 0, SEEK_END);
        id = ftell(pCli) / sizeof(Paises) + 1;
        fclose(pCli);
    }

    void cargarCadena(char *pal, int tam){
    int i;
    fflush(stdin);
    for(i=0; i<tam; i++)
    {
        pal[i]=std::cin.get();
        if(pal[i]=='\n') break;
    }
    pal[i]='\0';
    fflush(stdin);
}

void AgregarPaises() {
    AutoID();
    std::cout << "Ingrese el Nombre del pais: ";
    cargarCadena(nombre, 30);
    std::cout << "Ingrese el Nombre del Continente: ";
    cargarCadena(continente, 30);
    estado = true;
}


    void MostrarPaises() {
        std::cout << "ID: " << id << std::endl;
        std::cout << "Nombre del pais: " << nombre << std::endl;
        std::cout << "Nombre del Continente: " << continente << std::endl;
    }
};

    #endif // PAISES_H_INCLUDED
