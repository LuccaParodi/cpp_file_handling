#ifndef FUNCIONES_GLOBALES_H_INCLUDED
#define FUNCIONES_GLOBALES_H_INCLUDED

void cargarMusico() {
    musicos obj;
    FILE* pCli;
    pCli = fopen("musicos.dat", "ab");
    if (pCli == NULL) {
        std::cout << "NO SE PUDO CREAR EL ARCHIVO" << std::endl;
        return;
    }

    obj.cargarmusicos();

    fwrite(&obj, sizeof(musicos), 1, pCli);
    fclose(pCli);

    std::cout << "Músico agregado correctamente." << std::endl;
}

void mostrarMusicos(){
musicos obj;
  FILE * pCli;
  pCli = fopen("musicos.dat", "rb");
  if (pCli == NULL) {
    std::cout << "NO SE PUDO LEER EL ARCHIVO" << std::endl;
    return;
  }

  while (fread( & obj, sizeof obj, 1, pCli) == 1) {
    obj.mostrarmusicos();
    std::cout << std::endl;
  }
  fclose(pCli);
  system("pause");
  system("cls");
}

int buscarmusico (int d){
musicos obj;
int pos=0;
FILE *pCli;
pCli=fopen("musicos.dat","rb");
if (pCli==NULL){std::cout<<"no se puede leer el archivo";return -2;}
while(fread(&obj,sizeof obj,1,pCli)==1){
    if(obj.getDNI()==d){
        fclose(pCli);
        return pos;
    }
    pos++;
}
/*se lee musicos.dat(pasa lo mismo en las demas clases y con sus respectivos archivos), si no se puede abrir musicos.dat, se devuelve -2.
si se puede leer, se lee el archivo hasta el eof o hasta que se encuentre la coincidencia del if, si se encuentra esta coincidencia, se devuelve
la posicion del musico en el archivo, si no se encuentra el musico se devuelve -1. esta funcion se usa en modificar fecha y en baja logica. */
fclose(pCli);
return -1;
}

musicos leermusicos(int p){
musicos obj;
obj.setDNI(-2);
if(p<0){obj.setDNI(-3);return obj;}
FILE *ar;
ar=fopen("musicos.dat","rb");
if (ar==NULL){return obj;}
fseek(ar,sizeof obj *p, 0);
int aux=fread(&obj, sizeof obj,1,ar);
fclose(ar);
if(aux==0){obj.setDNI(-1);}
return obj;
/*
Esta función lee un objeto músico del fichero "musicos.dat" basándose en la posición p dada. Primero comprueba si la posición es válida.
Si la posición es negativa, establece el DNI del objeto músico en -3 y lo devuelve. Si el fichero no puede abrirse, devuelve un objeto con el DNI a -2.
En caso contrario, utiliza fseek para mover el puntero del fichero a la posición especificada, lee el objeto músico y lo devuelve.
Si la operación de lectura falla, establece el DNI del objeto músico a -1 y lo devuelve, esta fucion tambien aparece en la baja y la modificacion.*/
}

void buscarPorDNI() {
  musicos obj;
  bool encontro = false;
  FILE * pCli;
  pCli = fopen("musicos.dat", "rb");
  if (pCli == NULL) {
    std::cout << "NO SE PUDO ABRIR EL ARCHIVO" << std::endl;
    return;
  }
  int DNI;
  std::cout << "INGRESE EL DNI A BUSCAR: ";
  std::cin >> DNI;
if(DNI==0){std::cout<<"0 NO ES UN DNI VALIDO, VOLVIENDO AL MENU ANTERIOR"<<std::endl; system("pause"); system("cls"); return; }
  while (fread( & obj, sizeof obj, 1, pCli) == 1) {
        if (obj.getESTADO()==true){
    if (DNI == obj.getDNI()){
      obj.mostrarmusicos();
      std::cout << std::endl;
      encontro = true;
    }
  }
  }
  if (encontro == false) {
    std::cout << "NO SE ENCONTRO MUSICO CON ESE DNI" << std::endl;
  }
  fclose(pCli);
    system("pause");
  system("cls");
}

bool bajalogica(){
 musicos obj;
  int DNI;
  std::cout<<"ingrese el DNI que quiere dar de baja: ";
  std::cin>>DNI;
  if(DNI==0){std::cout<<"0 NO ES UN ID VALIDO, VOLVIENDO AL MENU ANTERIOR"<<std::endl; system("pause"); system("cls"); return false; }
 int pos=buscarmusico(DNI);
 obj=leermusicos(pos);
 obj.setESTADO(false);
 FILE *archivo;
 archivo=fopen("musicos.dat","rb+");
 fseek(archivo,sizeof obj *pos, 0);
 bool aux= fwrite(&obj,sizeof obj, 1, archivo);
 fclose(archivo);
 return aux;
   system("pause");
  system("cls");

    /*como dice el nombre, en esta funcion se modifica el estado del musico a falso,a esto se le llama baja logica.
    se pide al usuario que ingrese un DNI y si el dni es 0 se   cierra el programa, ya que es imposible que exista un DNI '0'.
  si la entrada es valida se llama a buscarmusico usando el dni como parametro para  encontrar la posicion del musico en el archivo y
  luego llama a leermusicos el cual me devuelve la informacion completa del objeto en esa posicion, se setea el estado a "falso" y luego se abre el
  archivo de musicos, se busca mueve el puntero hacia donde esta el musico que buscamos y se modifica el archivo guardandola en una variable auxiliar.
  se cierra el archivo y luego devolvemos la variable auxiliar, que posee la modificacion realizada en el archivo.
  */
}

void listarMusicos(){
musicos obj;
  FILE * pCli;
  pCli = fopen("musicos.dat", "rb");
  if (pCli == NULL) {
    std::cout << "NO SE PUDO LEER EL ARCHIVO" << std::endl;
    return;
  }

  while (fread( & obj, sizeof obj, 1, pCli) == 1) {
        if(obj.getESTADO()!=false){
    obj.mostrarmusicos();
    std::cout << std::endl;
  }
  }
  fclose(pCli);
system("pause");
  system("cls");
}

void modificarFecha(){
musicos obj;
  int DNI;
  std::cout<<"ingrese el DNI que quiere modificar la fecha: ";
  std::cin>>DNI;
  if(DNI==0){std::cout<<"0 NO ES UN DNI VALIDO, VOLVIENDO AL MENU ANTERIOR"<<std::endl; system("pause"); return; }
 int pos=buscarmusico(DNI);
 obj=leermusicos(pos);
std::cout<<"ingrese la nueva fecha: "<<std::endl;
Fecha nueva;
nueva.Cargar();
obj.setInscripcion(nueva);
 FILE *archivo;
 archivo=fopen("musicos.dat","rb+");
 fseek(archivo,sizeof obj *pos, 0);
 fwrite(&obj,sizeof obj, 1, archivo);
 fclose(archivo);
  system("pause");
  system("cls");
    /*
  como dice el nombre, en esta funcion se modifica la fecha de la inscripcion de un musico, se pide al usuario que ingrese un DNI y si el dni es 0 se
  cierra el programa, ya que es imposible que exista un DNI '0', si la entrada es valida se llama a buscarmusico usando el dni como parametro para
  encontrar la posicion del musico en el archivo y luego llama a leermusicos el cual me devuelve la informacion completa del objeto en esa posicion
  luego se le pide al usuario que introduzca la nueva fecha, el usuario ingresa dicha fecha y luego de eso se abre el archivo, comenzando desde la primer
  posicion del archivo,buscando a la posicion del archivo que se quiere modificar,finalemente, se escribe en la direccion del objeto las modificaciones
  pertinentes.
  */

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////

generos leergeneros(int p){
generos obj;
obj.setID(-2);
if(p<0){obj.setID(-3);return obj;}
FILE *ar;
ar=fopen("generos.dat","rb");
if (ar==NULL){return obj;}
fseek(ar,sizeof obj *p, 0);
int aux=fread(&obj, sizeof obj,1,ar);
fclose(ar);
if(aux==0){obj.setID(-1);}
return obj;
}

int buscargeneros (int d){
generos obj;
int pos=0;
FILE *pCli;
pCli=fopen("generos.dat","rb");
if (pCli==NULL){std::cout<<"no se puede leer el archivo";return -2;}
while(fread(&obj,sizeof obj,1,pCli)==1){
    if(obj.getID()==d){
        fclose(pCli);
        return pos;
    }
    pos++;
}
fclose(pCli);
return -1;
}

void cargarGenero() {
  generos obj;
  FILE * pCli;
  pCli = fopen("generos.dat", "ab");
  if (pCli == NULL) {
    std::cout << "NO SE PUDO CREAR EL ARCHIVO" << std::endl;
  }
  obj.agregarGenero();
  fwrite( & obj, sizeof(generos), 1, pCli);
  fclose(pCli);
  system("pause");
  system("cls");
}

void listarGeneros(){
generos obj;
  FILE * pCli;
  pCli = fopen("generos.dat", "rb");
  if (pCli == NULL) {
    std::cout << "NO SE PUDO LEER EL ARCHIVO" << std::endl;
    return;
  }

  while (fread( & obj, sizeof obj, 1, pCli) == 1) {
        if(obj.getESTADO()!=false){
    obj.mostrarGeneros();
    std::cout << std::endl;
  }
  }
  fclose(pCli);
  system("pause");
  system("cls");
}

void buscarGeneroPorID() {
  generos obj;
  bool encontro = false;
  FILE * pCli;
  pCli = fopen("generos.dat", "rb");
  if (pCli == NULL) {
    std::cout << "NO SE PUDO ABRIR EL ARCHIVO" << std::endl;
    return;
  }
  int ID;
  std::cout << "INGRESE EL ID A BUSCAR: ";
  std::cin >> ID;
    if(ID==0){std::cout<<"0 NO ES UN ID VALIDO, VOLVIENDO AL MENU ANTERIOR"<<std::endl; system("pause"); system("cls"); return; }
  while (fread( & obj, sizeof obj, 1, pCli) == 1) {
        if (obj.getESTADO()==true){
    if (ID == obj.getID()){
      obj.mostrarGeneros();
      std::cout << std::endl;
      encontro = true;
    }
  }
  }
  if (encontro == false) {
    std::cout << "NO SE ENCONTRO UN GENERO CON ESA ID" << std::endl;
  }
  fclose(pCli);
  system("pause");
  system("cls");
}

void modificarAnio(){
generos obj;
  int ID;
  std::cout<<"ingrese la ID de la que quiere modificar su anio: ";
  std::cin>>ID;
 if(ID==0){std::cout<<"0 NO ES UN ID VALIDO, VOLVIENDO AL MENU ANTERIOR"<<std::endl; system("pause"); return; }
 int pos=buscargeneros(ID);
 obj=leergeneros(pos);
 int anio;
 std::cout<<"ingrese el nuevo anio"<<std::endl;
 std::cin>>anio;
obj.setAnio(anio);
 FILE *archivo;
 archivo=fopen("generos.dat","rb+");
 fseek(archivo,sizeof obj *pos, 0);
 fwrite(&obj,sizeof obj, 1, archivo);
 fclose(archivo);
system("pause");
system("cls");
return;
}

bool bajageneros(){
 generos obj;
  int ID;
  std::cout<<"ingrese la ID del genero que quiere dar de baja: ";
  std::cin>>ID;
  if(ID==0){std::cout<<"0 NO ES UN ID VALIDO, VOLVIENDO AL MENU ANTERIOR"<<std::endl; system("pause"); system("cls"); return false; }
 int pos=buscargeneros(ID);
 obj=leergeneros(pos);
 obj.setESTADO(false);
 FILE *archivo;
 archivo=fopen("generos.dat","rb+");
 fseek(archivo,sizeof obj *pos, 0);
 bool aux= fwrite(&obj,sizeof obj, 1, archivo);
 fclose(archivo);
 return aux;
 system("pause");
 system("cls");
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////

void AgregarInstrumento(){
  Instrumentos obj;
  FILE * pCli;
  pCli = fopen("instrumentos.dat", "ab");
  if (pCli == NULL) {
    std::cout << "NO SE PUDO CREAR EL ARCHIVO" << std::endl;
  }
  obj.AgregarInstrumento();
  fwrite( & obj, sizeof(Instrumentos), 1, pCli);
  fclose(pCli);
  system("pause");
  system("cls");
}

void ListarInstrumentosPorId(){
 Instrumentos obj;
  bool encontro = false;
  FILE * pCli;
  pCli = fopen("instrumentos.dat", "rb");
  if (pCli == NULL) {
    std::cout << "NO SE PUDO ABRIR EL ARCHIVO" << std::endl;
    return;
  }
  int ID;
  std::cout << "INGRESE EL ID A BUSCAR: ";
  std::cin >> ID;
  if(ID==0){std::cout<<"0 NO ES UN ID VALIDO, VOLVIENDO AL MENU ANTERIOR"<<std::endl; system("pause"); system("cls"); return; }
  while (fread( & obj, sizeof obj, 1, pCli) == 1) {
        if (obj.getESTADO()==true){
    if (ID == obj.getID()){
      obj.MostrarInstrumentos();
      std::cout << std::endl;
      encontro = true;
    }
  }
  }
  if (encontro == false) {
    std::cout << "NO SE ENCONTRO ESE INSTRUMENTO" << std::endl;
  }
  fclose(pCli);
    system("pause");
  system("cls");
}

void ListarTodosLosInstrumentos(){
Instrumentos obj;
  FILE * pCli;
  pCli = fopen("instrumentos.dat", "rb");
  if (pCli == NULL) {
    std::cout << "NO SE PUDO LEER EL ARCHIVO" << std::endl;
    return;
  }

  while (fread( & obj, sizeof obj, 1, pCli) == 1) {
        if(obj.getESTADO()!=false){
    obj.MostrarInstrumentos();
    std::cout << std::endl;
  }
  }
  fclose(pCli);
system("pause");
  system("cls");
}

int buscarInstrumento (int d){
Instrumentos obj;
int pos=0;
FILE *pCli;
pCli=fopen("instrumentos.dat","rb");
if (pCli==NULL){std::cout<<"no se puede leer el archivo";return -2;}
while(fread(&obj,sizeof obj,1,pCli)==1){
    if(obj.getID()==d){
        fclose(pCli);
        return pos;
    }
    pos++;
}
fclose(pCli);
return -1;
}

Instrumentos leerInstrumentos (int p){
Instrumentos obj;
obj.setID(-2);
if(p<0){obj.setID(-3);return obj;}
FILE *ar;
ar=fopen("instrumentos.dat","rb");
if (ar==NULL){return obj;}
fseek(ar,sizeof obj *p, 0);
int aux=fread(&obj, sizeof obj,1,ar);
fclose(ar);
if(aux==0){obj.setID(-1);}
return obj;
}

void ModificarNombre(){
    Instrumentos obj;
  int ID;
  std::cout<<"ingrese la ID del instrumento cuyo nombre desea modificar: ";
  std::cin>>ID;
 if(ID==0){std::cout<<"0 NO ES UN ID VALIDO, VOLVIENDO AL MENU ANTERIOR"<<std::endl; system("pause"); system("cls"); return; }
 int pos=buscarInstrumento(ID);
 obj=leerInstrumentos(pos);
 char nombre[30];
 std::cout<<"ingrese el nuevo nombre"<<std::endl;
 std::cin>>nombre;
obj.setNombre(nombre);
 FILE *archivo;
 archivo=fopen("instrumentos.dat","rb+");
 fseek(archivo,sizeof obj *pos, 0);
 fwrite(&obj,sizeof obj, 1, archivo);
 fclose(archivo);
system("pause");
system("cls");
return;
}

bool BajaInstrumentos(){
 Instrumentos obj;
  int ID;
  std::cout<<"ingrese la ID del instumento que quiere dar de baja: ";
  std::cin>>ID;
  if(ID==0){std::cout<<"0 NO ES UN ID VALIDO, VOLVIENDO AL MENU ANTERIOR"<<std::endl; system("pause"); system("cls"); return false; }
 int pos=buscarInstrumento(ID);
 obj=leerInstrumentos(pos);
 obj.setESTADO(false);
 FILE *archivo;
 archivo=fopen("instrumentos.dat","rb+");
 fseek(archivo,sizeof obj *pos, 0);
 bool aux= fwrite(&obj,sizeof obj, 1, archivo);
 fclose(archivo);
 return aux;
 system("pause");
 system("cls");
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////

void AgregarPais() {
    Paises obj;
    FILE* pCli;
    pCli = fopen("pais.dat", "ab");
    if (pCli == NULL) {
        std::cout << "NO SE PUDO CREAR EL ARCHIVO" << std::endl;
        return;
    }
    obj.AgregarPaises();
    fwrite(&obj, sizeof(Paises), 1, pCli);
    fclose(pCli);
    std::cout << "Pais agregado correctamente" << std::endl;
    system("pause");
    system("cls");
}

void ListarPaisPorID(){
 Paises obj;
  bool encontro = false;
  FILE * pCli;
  pCli = fopen("pais.dat", "rb");
  if (pCli == NULL) {
    std::cout << "NO SE PUDO ABRIR EL ARCHIVO" << std::endl;
    return;
  }
  int ID;
  std::cout << "INGRESE EL ID A BUSCAR: ";
  std::cin >> ID;
    if(ID==0){std::cout<<"0 NO ES UN ID VALIDO, VOLVIENDO AL MENU ANTERIOR"<<std::endl; system("pause"); system("cls"); return; }
  while (fread( & obj, sizeof obj, 1, pCli) == 1) {
        if (obj.getESTADO()==true){
    if (ID == obj.getID()){
      obj.MostrarPaises();
      std::cout << std::endl;
      encontro = true;
    }
  }
  }
  if (encontro == false) {
    std::cout << "NO SE ENCONTRO ESE PAIS" << std::endl;
  }
  fclose(pCli);
system("pause");
  system("cls");
}

void ListarPaises() {
    Paises obj;
    FILE* pCli;
    pCli = fopen("pais.dat", "rb");
    if (pCli == NULL) {
        std::cout << "NO SE PUDO LEER EL ARCHIVO" << std::endl;
        return;
    }
    while (fread( & obj, sizeof obj, 1, pCli) == 1) {
        if (obj.getESTADO() != false) {
            obj.MostrarPaises();
            std::cout << std::endl;
        }
            }
    fclose(pCli);
    system("pause");
    system("cls");
}

int buscarPais (int d){
Paises obj;
int pos=0;
FILE *pCli;
pCli=fopen("pais.dat","rb");
if (pCli==NULL){std::cout<<"no se puede leer el archivo";return -2;}
while(fread(&obj,sizeof obj,1,pCli)==1){
    if(obj.getID()==d){
        fclose(pCli);
        return pos;
    }
    pos++;
}
fclose(pCli);
return -1;
}

Paises leerPaises (int p){
Paises obj;
obj.setID(-2);
if(p<0){obj.setID(-3);return obj;}
FILE *ar;
ar=fopen("pais.dat","rb");
if (ar==NULL){return obj;}
fseek(ar,sizeof obj *p, 0);
int aux=fread(&obj, sizeof obj,1,ar);
fclose(ar);
if(aux==0){obj.setID(-1);}
return obj;
}

void ModificarNombreDelPais(){
  Paises obj;
  int ID;
  std::cout<<"ingrese la ID del pais cuyo nombre desea modificar: ";
  std::cin>>ID;
  if(ID==0){std::cout<<"0 NO ES UN ID VALIDO, VOLVIENDO AL MENU ANTERIOR"<<std::endl; system("pause"); system("cls"); return; }
 int pos=buscarPais(ID);
 obj=leerPaises(pos);
 char nombre[30];
 std::cout<<"ingrese el nuevo nombre"<<std::endl;
 std::cin>>nombre;
obj.setNombre(nombre);
 FILE *archivo;
 archivo=fopen("pais.dat","rb+");
 fseek(archivo,sizeof obj *pos, 0);
 fwrite(&obj,sizeof obj, 1, archivo);
 fclose(archivo);
system("pause");
system("cls");
return;
}

bool bajaPais() {
    Paises obj;
    int ID;
    std::cout << "Ingrese la ID del pais que desea dar de baja: ";
    std::cin >> ID;
    if(ID==0){std::cout<<"0 NO ES UN ID VALIDO, VOLVIENDO AL MENU ANTERIOR"<<std::endl; system("pause"); system("cls"); return false; }
    int pos = buscarPais(ID);
    obj = leerPaises(pos);
    obj.setESTADO(false);
    FILE* archivo;
    archivo = fopen("pais.dat", "rb+");
    fseek(archivo, sizeof(obj) * pos, 0);
    bool aux = fwrite(&obj, sizeof(obj), 1, archivo);
    fclose(archivo);
    system("pause");
    system("cls");
    return aux;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////

bool copiamusicos() {
  musicos obj;
  FILE* pCli, * pBak;
  pCli = fopen("musicos.dat", "rb");
  if (pCli == NULL) {
    std::cout << "NO SE PUDO ABRIR EL ARCHIVO DE ORIGEN" << std::endl;
    return false;
  }
  pBak = fopen("musicos.bkp", "wb");
  if (pBak == NULL) {
    std::cout << "NO SE PUDO CREAR EL ARCHIVO DE RESPALDO" << std::endl;
    fclose(pCli);
    return false;
  }

  while (fread(&obj, sizeof(obj), 1, pCli) == 1) {
    fwrite(&obj, sizeof(obj), 1, pBak);
  }
  fclose(pBak);
  std::cout << "Back-up realizado con éxito" << std::endl;
  fclose(pCli);
  system("pause");
  return true;
///se abren dos archivos, uno de lectura, otro de escritura y se copia registro por registro
///lo que se lee en el primer archivo, lo mismo sucede con las demas clases.
            /// fin de copia de seguridad

}

bool copiageneros(){
///Copiar el archivo original en el backup
            generos obj;
            FILE *pCli, *pBak;
            pCli=fopen("generos.dat", "rb");
            if(pCli==NULL){
                std::cout<<"NO SE PUDO CREAR EL ARCHIVO"<<std::endl;
                return false;
            }
            pBak=fopen("generos.bkp", "wb");
            if(pBak==NULL){
               std::cout<<"NO SE PUDO CREAR EL ARCHIVO"<<std::endl;
                fclose(pCli);
                return false;
            }

            while(fread(&obj, sizeof obj, 1, pCli)==1){
                fwrite(&obj, sizeof obj, 1, pBak);
            }
            fclose(pBak);
            std::cout<<"Back-up realizado con exito"<<std::endl;
            fclose(pCli);
            system("pause");
            return true;
            /// fin de copia de seguridad
}

bool copiainstrumentos(){
            Instrumentos obj;
            FILE *pCli, *pBak;
            pCli=fopen("instrumentos.dat", "rb");
            if(pCli==NULL){
                std::cout<<"NO SE PUDO CREAR EL ARCHIVO"<<std::endl;
                return false;
            }
            pBak=fopen("instrumentos.bkp", "wb");
            if(pBak==NULL){
               std::cout<<"NO SE PUDO CREAR EL ARCHIVO"<<std::endl;
                fclose(pCli);
                return false;
            }

            while(fread(&obj, sizeof obj, 1, pCli)==1){
                fwrite(&obj, sizeof obj, 1, pBak);
            }
            fclose(pBak);
            std::cout<<"Back-up realizado con exito"<<std::endl;
            fclose(pCli);
            system("pause");
            return true;
            /// fin de copia de seguridad
}

bool copiapaises(){
            Paises obj;
            FILE *pCli, *pBak;
            pCli=fopen("pais.dat", "rb");
            if(pCli==NULL){
                std::cout<<"NO SE PUDO CREAR EL ARCHIVO"<<std::endl;
                return false;
            }
            pBak=fopen("pais.bkp", "wb");
            if(pBak==NULL){
               std::cout<<"NO SE PUDO CREAR EL ARCHIVO"<<std::endl;
                fclose(pCli);
                return false;
            }

            while(fread(&obj, sizeof obj, 1, pCli)==1){
                fwrite(&obj, sizeof obj, 1, pBak);
            }
            fclose(pBak);
            std::cout<<"Back-up realizado con exito"<<std::endl;
            fclose(pCli);
            system("pause");
            return true;
            /// fin de copia de seguridad
}

void restauraMusicos(){
            system("cls");
  musicos obj;
            FILE *pCli, *pBak;
            pCli=fopen("musicos.bkp", "rb");
            if(pCli==NULL){
                std::cout<<"NO SE PUDO CREAR EL ARCHIVO"<<std::endl;
                return;
            }
            pBak=fopen("musicos.dat", "wb");
            if(pBak==NULL){
               std::cout<<"NO SE PUDO CREAR EL ARCHIVO"<<std::endl;
                fclose(pCli);
                return;
            }

            while(fread(&obj, sizeof obj, 1, pCli)==1){
                fwrite(&obj, sizeof obj, 1, pBak);
            }
            fclose(pBak);
            std::cout<<"Se han restaurado exitosamente los registros"<<std::endl;
            fclose(pCli);
             system("pause");

}

void restauraGeneros(){
            system("cls");
            generos obj;
            FILE *pCli, *pBak;
            pCli=fopen("generos.bkp", "rb");
            if(pCli==NULL){
                std::cout<<"NO SE PUDO CREAR EL ARCHIVO"<<std::endl;
                return;
            }
            pBak=fopen("generos.dat", "wb");
            if(pBak==NULL){
               std::cout<<"NO SE PUDO CREAR EL ARCHIVO"<<std::endl;
                fclose(pCli);
                return;
            }

            while(fread(&obj, sizeof obj, 1, pCli)==1){
                fwrite(&obj, sizeof obj, 1, pBak);
            }
            fclose(pBak);
            std::cout<<"Se han restaurado exitosamente los registros"<<std::endl;
            fclose(pCli);
            system("pause");
}

void restauraInstrumentos(){
            system("cls");
            Instrumentos obj;
            FILE *pCli, *pBak;
            pCli=fopen("instrumentos.bkp", "rb");
            if(pCli==NULL){
                std::cout<<"NO SE PUDO CREAR EL ARCHIVO"<<std::endl;
                return;
            }
            pBak=fopen("instrumentos.dat", "wb");
            if(pBak==NULL){
               std::cout<<"NO SE PUDO CREAR EL ARCHIVO"<<std::endl;
                fclose(pCli);
                return;
            }

            while(fread(&obj, sizeof obj, 1, pCli)==1){
                fwrite(&obj, sizeof obj, 1, pBak);
            }
            fclose(pBak);
            std::cout<<"Se han restaurado exitosamente los registros"<<std::endl;
            fclose(pCli);
            system("pause");
}

void restauraPaises(){
            system("cls");
            generos obj;
            FILE *pCli, *pBak;
            pCli=fopen("pais.bkp", "rb");
            if(pCli==NULL){
                std::cout<<"NO SE PUDO CREAR EL ARCHIVO"<<std::endl;
                return;
            }
            pBak=fopen("pais.dat", "wb");
            if(pBak==NULL){
               std::cout<<"NO SE PUDO CREAR EL ARCHIVO"<<std::endl;
                fclose(pCli);
                return;
            }

            while(fread(&obj, sizeof obj, 1, pCli)==1){
                fwrite(&obj, sizeof obj, 1, pBak);
            }
            fclose(pBak);
            std::cout<<"Se han restaurado exitosamente los registros"<<std::endl;
            fclose(pCli);
            system("pause");
}

void entradadefaultMusicos(){

  musicos obj;
  FILE * pCli;
  pCli = fopen("musdefault.dat", "ab");
  if (pCli == NULL) {
    std::cout << "NO SE PUDO CREAR EL ARCHIVO" << std::endl;
  }
  obj.cargarmusicos();
  fwrite( & obj, sizeof(musicos), 1, pCli);
  fclose(pCli);
  system("pause");
  system("cls");
}

void entradaDefaultGeneros(){
  generos obj;
  FILE * pCli;
  pCli = fopen("gendefault.dat", "ab");
  if (pCli == NULL) {
    std::cout << "NO SE PUDO CREAR EL ARCHIVO" << std::endl;
  }
  obj.agregarGenero();
  fwrite( & obj, sizeof(generos), 1, pCli);
  fclose(pCli);
  system("pause");
  system("cls");
}

void entradaDefaultInstrumentos(){
  Instrumentos obj;
  FILE * pCli;
  pCli = fopen("insdefault.dat", "ab");
  if (pCli == NULL) {
    std::cout << "NO SE PUDO CREAR EL ARCHIVO" << std::endl;
  }
  obj.AgregarInstrumento();
  fwrite( & obj, sizeof(Instrumentos), 1, pCli);
  fclose(pCli);
  system("pause");
  system("cls");
}

void entradaDefaultPaises(){
  Paises obj;
  FILE * pCli;
  pCli = fopen("paisdefault.dat", "ab");
  if (pCli == NULL) {
    std::cout << "NO SE PUDO CREAR EL ARCHIVO" << std::endl;
  }
  obj.AgregarPaises();
  fwrite( & obj, sizeof(Paises), 1, pCli);
  fclose(pCli);
  system("pause");
  system("cls");
}

void mostrarDefaultMus(){
musicos obj;
  FILE * pCli;
  pCli = fopen("musdefault.dat", "rb");
  if (pCli == NULL) {
    std::cout << "NO SE PUDO LEER EL ARCHIVO" << std::endl;
    return;
  }

  while (fread( & obj, sizeof obj, 1, pCli) == 1) {
    obj.mostrarmusicos();
    std::cout << std::endl;
  }
  fclose(pCli);
  system("pause");
  system("cls");
}

void mostrarDefaultGen(){
generos obj;
  FILE * pCli;
  pCli = fopen("gendefault.dat", "rb");
  if (pCli == NULL) {
    std::cout << "NO SE PUDO LEER EL ARCHIVO" << std::endl;
    return;
  }

  while (fread( & obj, sizeof obj, 1, pCli) == 1) {
        if(obj.getESTADO()!=false){
    obj.mostrarGeneros();
    std::cout << std::endl;
  }
  }
  fclose(pCli);
}

void mostrarDefaultIns(){
Instrumentos obj;
  FILE * pCli;
  pCli = fopen("insdefault.dat", "rb");
  if (pCli == NULL) {
    std::cout << "NO SE PUDO LEER EL ARCHIVO" << std::endl;
    return;
  }

  while (fread( & obj, sizeof obj, 1, pCli) == 1) {
        if(obj.getESTADO()!=false){
    obj.MostrarInstrumentos();
    std::cout << std::endl;
  }
  }
  fclose(pCli);
}

void mostrarDefaultPais(){
Paises obj;
  FILE * pCli;
  pCli = fopen("paisdefault.dat", "rb");
  if (pCli == NULL) {
    std::cout << "NO SE PUDO LEER EL ARCHIVO" << std::endl;
    return;
  }

  while (fread( & obj, sizeof obj, 1, pCli) == 1) {
        if(obj.getESTADO()!=false){
    obj.MostrarPaises();
    std::cout << std::endl;
  }
  }
  fclose(pCli);
}

void datosDefault(){
            ///MUSICOS
            musicos obj;
            FILE *pCli, *pBak;
            pCli=fopen("musdefault.dat", "rb");
            if(pCli==NULL){
                std::cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<std::endl;
                return;
            }
            pBak=fopen("musicos.dat", "wb");
            if(pBak==NULL){
               std::cout<<"NO SE PUDO CREAR EL ARCHIVO"<<std::endl;
                fclose(pCli);
                return;
            }

            while(fread(&obj, sizeof obj, 1, pCli)==1){
                fwrite(&obj, sizeof obj, 1, pBak);      ///se abren dos archivos, uno de lectura, otro de escritura y se copia registro por registro
            }                                           ///lo que se lee en el primer archivo, lo mismo sucede con las demas clases.
            fclose(pBak);
            std::cout<<"Se han establecido los datos por defecto de los musicos con exito"<<std::endl;
            fclose(pCli);



            ///GENEROS
            generos objg;
            FILE *pGen, *pBakG;
            pGen=fopen("gendefault.dat", "rb");
            if(pGen==NULL){
                std::cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<std::endl;
                return;
            }
            pBakG=fopen("generos.dat", "wb");
            if(pBakG==NULL){
               std::cout<<"NO SE PUDO CREAR EL ARCHIVO"<<std::endl;
                fclose(pGen);
                return;
            }

            while(fread(&objg, sizeof objg, 1, pGen)==1){
                fwrite(&objg, sizeof objg, 1, pBakG);
            }
            fclose(pBakG);
            std::cout<<"Se han establecido los datos por defecto de los generos con exito"<<std::endl;
            fclose(pGen);


            ///INSTRUMENTOS

            Instrumentos reg;
            FILE *pIns, *pBakI;
            pIns=fopen("insdefault.dat", "rb");
            if(pIns==NULL){
                std::cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<std::endl;
                return;
            }
            pBakI=fopen("instrumentos.dat", "wb");
            if(pBakI==NULL){
               std::cout<<"NO SE PUDO CREAR EL ARCHIVO"<<std::endl;
                fclose(pIns);
                return;
            }

            while(fread(&reg, sizeof reg, 1, pIns)==1){
                fwrite(&reg, sizeof reg, 1, pBakI);
            }
            fclose(pBakI);
            std::cout<<"Se han establecido los datos por defecto de los instrumentos con exito"<<std::endl;
            fclose(pIns);



            ///PAISES
            Paises regx;
            FILE *pPai, *pBakP;
            pPai=fopen("paisdefault.dat", "rb");
            if(pPai==NULL){
                std::cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<std::endl;
                return;
            }
            pBakP=fopen("pais.dat", "wb");
            if(pBakP==NULL){
               std::cout<<"NO SE PUDO CREAR EL ARCHIVO"<<std::endl;
                fclose(pPai);
                return;
            }

            while(fread(&regx, sizeof regx, 1, pPai)==1){
                fwrite(&regx, sizeof regx, 1, pBakP);
            }
            fclose(pBakP);
            std::cout<<"Se han establecido los datos por defecto de los paises con exito"<<std::endl;
            fclose(pPai);
            system("pause");
            /// fin de copia de seguridad
}





#endif // FUNCIONES_GLOBALES_H_INCLUDED
