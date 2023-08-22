#ifndef OBJ_MUSICOS_H_INCLUDED
#define OBJ_MUSICOS_H_INCLUDED
#include "instrumentos.h"
#include "generos.h"

class musicos{
private:
int DNI;
char Nombre[30];
char Apellido[30];
char Email[30];
char Telefono[30];
int Claustro;// (1: docente; 2 alumno; 3 no docente; 4 graduado)
int Instrumentoprincipal;// (número entre 1 y 15)
int Tipodemusica; ///TIPO DE MUSICA ES LO MISMO QUE GENERO
Fecha inscripcion;
float Matricula;
bool estado;
public:
void cargarmusicos();
void mostrarmusicos();
void CompararID();
Fecha compararFechas(Fecha inscripcion);


      ///SETTERS
void setDNI(const int d){DNI=d;}
void setNombre(const char *n){strcpy(Nombre,n);}
void setApellido(const char *n){strcpy(Apellido,n);}
void setEmail(const char *n){strcpy (Email,n);}
void setTelefono(const char *t){strcpy(Telefono,t);}
void setClaustro( int C){while(C<1||C>4){std::cout<<"ingrese un Claustro correcto: ";std::cin>>C;}Claustro=C;}
void setInstrumentoPrincipal(int C){Instrumentoprincipal=C;}
void setTipodemusica( int C){while(C<1||C>10){std::cout<<"ingrese un tipo de musica correcto: ";std::cin>>C;}Tipodemusica=C;}
void setInscripcion(Fecha f){inscripcion=f;}
void setMatricula( float m){while(m<0){std::cout<<"ingrese ua matricula valida: ";std::cin>>m;}Matricula=m;}
void setESTADO(bool e){estado=e;}
     ///GETTERS
int getDNI(){return DNI;}
const char* getNombre(){return Nombre;}
const char* getApellido(){return Apellido;}
const char* getEmail(){return Email;}
const char* getTelefono(){return Telefono;}
int getClaustro(){return Claustro;}
int getInstrumentoPrincipal(){return Instrumentoprincipal;}
int getTipodemusica(){return Tipodemusica;}
Fecha getInscripcion(){return inscripcion;}
float getMatricula(){return Matricula;}
bool getESTADO(){return estado;}


int guardarDNI(int DNIactual);

void ExisteGen(){

        bool tipoMusicaValido = false;

while (!tipoMusicaValido) {
    std::cout << "Ingrese el tipo de musica (debe existir en el registro de los generos): ";
    std::cin >> Tipodemusica;

    FILE* pGeneros;
    pGeneros = fopen("generos.dat", "rb");
    if (pGeneros == NULL) {
        std::cout << "NO SE PUDO ABRIR EL ARCHIVO DE GENEROS" << std::endl;
        return;
    }

    bool tipoMusicaEncontrado = false;
    generos reg;

    while (fread(&reg, sizeof(generos), 1, pGeneros) == 1) {
        if (reg.getID() == Tipodemusica) {
            tipoMusicaEncontrado = true;
        }
    }

    fclose(pGeneros);

    if (tipoMusicaEncontrado) {
        tipoMusicaValido = true;
    } else {
        std::cout << "El tipo de musica no existe en nuestros registros. Ingrese otro tipo." << std::endl;
    }
}
}


};

void musicos::cargarmusicos(){
    int aux;
    int a;
std::cout<<"ingrese el DNI: ";
std::cin>>DNI;
a=guardarDNI(DNI);
while(a==-1){
std::cout<<"ingrese nuevamente el DNI: ";
std::cin>>DNI;
a=guardarDNI(DNI);}
std::cout<<"Ingrese el Nombre: ";
std::cin>>Nombre;
std::cout<<"ingrese Apellido: ";
std::cin>>Apellido;
std::cout<<"ingrese Email: ";
std::cin>>Email;
std::cout<<"ingrese telefono: ";
std::cin>>Telefono;
std::cout<<"ingrese Claustro: ";
std::cin>>aux;
setClaustro(aux);
musicos::CompararID();
///std::cout<<"ingrese el tipo de musica: ";
musicos::ExisteGen();
std::cout<<"fecha de inscripcion ";
inscripcion.Cargar();
compararFechas(inscripcion);
std::cout<<"ingrese la matricula: ";
std::cin>>Matricula;
setMatricula(Matricula);
estado=true;
}

void musicos::mostrarmusicos(){
std::cout<<"DNI: ";
std::cout<<DNI<<std::endl;
std::cout<<"Nombre: ";
std::cout<<Nombre<<std::endl;
std::cout<<"Apellido: ";
std::cout<<Apellido<<std::endl;
std::cout<<"Email: ";
std::cout<<Email<<std::endl;
std::cout<<"telefono: ";
std::cout<<Telefono<<std::endl;
std::cout<<"Claustro: ";
std::cout<<Claustro<<std::endl;
std::cout<<"instrumento principal: ";
std::cout<<Instrumentoprincipal<<std::endl;
std::cout<<"el tipo de musica: ";
std::cout<<Tipodemusica<<std::endl;
std::cout<<"fecha de inscripcion: ";
inscripcion.Mostrar();
std::cout<<"matricula: ";
std::cout<<getMatricula()<<std::endl;
}

int musicos::guardarDNI(int DNIactual){
musicos obj;
  FILE * pCli;
  pCli = fopen("musicos.dat", "rb");
  while (fread(&obj, sizeof obj, 1, pCli) == 1) {
      if(obj.getESTADO()==true){
     if (DNIactual==obj.getDNI()){std::cout<<"este dni ya existe"<<std::endl;
    fclose(pCli); return -1; }
  }
  }
  fclose(pCli);
  return 0;
}


void musicos::CompararID() {
    bool instrumentoValido = false;

    while (!instrumentoValido) {
        std::cout << "Ingrese el ID del instrumento principal: ";
        std::cin >> Instrumentoprincipal;

        FILE* pInstr;
        pInstr = fopen("instrumentos.dat", "rb");
        if (pInstr == NULL) {
            std::cout << "NO SE PUDO ABRIR EL ARCHIVO DE INSTRUMENTOS" << std::endl;
            return;
        }

        bool instrumentoEncontrado = false;
        Instrumentos instrumento;

        while (fread(&instrumento, sizeof(Instrumentos), 1, pInstr) == 1) {
            if (instrumento.getID() == Instrumentoprincipal) {
                instrumentoEncontrado = true;
            }
        }

        fclose(pInstr);

        if (instrumentoEncontrado) {
            instrumentoValido = true;
        } else {
            std::cout << "El ID de instrumento no existe en nuestros registros. Ingrese otro ID." << std::endl;
        }
    }
}

Fecha musicos::compararFechas(Fecha inscripcion){
    std::time_t now = std::time(nullptr);
    std::tm *current_time = std::localtime(&now);
     int diaH = current_time->tm_mday;
     int mesH = current_time->tm_mon + 1; // Los meses se almacenan de 0 a 11
     int anioH = current_time->tm_year + 1900; // El año se almacena como el número de años desde 1900
if (inscripcion.getAnio()<=anioH){
    if((inscripcion.getMes()<=mesH||inscripcion.getMes()>mesH) &&(inscripcion.getAnio()<anioH)){
        if ((inscripcion.getDia()<=diaH ||inscripcion.getDia()>=diaH) &&(inscripcion.getMes()<=mesH ||inscripcion.getDia()>=diaH) && (inscripcion.getMes()>=mesH) && (inscripcion.getAnio()<=anioH)){
            return inscripcion;
        }
    }
}
else{std::cout<<"introduzca una fecha correcta, la misma no debe de superar el dia actual"<<std::endl;
inscripcion.Cargar();
 }

return inscripcion;
}
#endif // OBJ_MUSICOS_H_INCLUDED
