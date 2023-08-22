#ifndef INSTRUMENTOS_H_INCLUDED
#define INSTRUMENTOS_H_INCLUDED

class Instrumentos{
private:
    int id;
    char nombre[30];
    int clasificacion;
    bool estado;

public:
    ///SETTERS
     void setID(const int IDI){id=IDI;}
    void setNombre(const char *n){strcpy(nombre,n);}
    void setClasif(const int clasif){clasificacion=clasif;}
    void setESTADO(bool e){estado=e;}

    ///GETTERS
        int getID(){return id;}
    const char* getNombre(){return nombre;}
    int getClasif(){return clasificacion;}
    bool getESTADO(){return estado;}

    void AutoID() {
        FILE* pCli;
        pCli = fopen("instrumentos.dat", "rb");
        if (pCli == NULL) {
            std::cout << "NO SE PUDO ABRIR EL ARCHIVO" << std::endl;
            return;
        }
        fseek(pCli, 0, SEEK_END);
        id = ftell(pCli) / sizeof(Instrumentos) + 1;
        fclose(pCli);   ///LEE EL ARCHIVO Y AL EJECUTARSE, LE SUMA 1 AL NUMERO DE REGISTROS PARA ASIGNAR LA NUEVA ID
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


void AgregarInstrumento() {
    AutoID();
    std::cout << "Ingrese el Nombre del instrumento: ";
    cargarCadena(nombre, 30);
    std::cout << "Ingrese la clasificacion del instrumento: ";
    std::cin >> clasificacion;
    estado = true;
}


void MostrarInstrumentos(){
    std::cout<<"ID: "<<id<<std::endl;
    std::cout<<"Nombre del instrumento: "<<nombre<<std::endl;
    std::cout<<"Clasificacion del instrumento: "<<clasificacion<<std::endl;

}


   };

   #endif // INSTUMENTOS_H_INCLUDED
