#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED
#include "reportes.h"

int menumusicos(){
int opc;
while(true){
system("cls");
std::cout<<"MENU MUSICOS"<<std::endl;
std::cout<<"------------------"<<std::endl;

std::cout<<"1) AGREGAR MUSICOS"<<std::endl;
std::cout<<"2) LISTAR MUSICO POR DNI"<<std::endl;
std::cout<<"3) LISTAR TODOS LOS MUSICOS"<<std::endl;
std::cout<<"4) MODIFICAR FECHA DE INSCRIPCION"<<std::endl;
std::cout<<"5) ELIMINAR REGISTRO DE MUSICO"<<std::endl;
std::cout<<"--------------------------------"<<std::endl;
std::cout<<"0) SALIR"<<std::endl;
std::cin>>opc;
system("cls");

switch(opc){
case 1:
    cargarMusico();
    break;
case 2:
    buscarPorDNI();
    break;
case 3:
    listarMusicos();
    break;
case 4:
    modificarFecha();
    break;
case 5:
    bajalogica();
    break;
case 0:
    system("cls");
    return 0;
    break;
    default:
    system("cls");
    break;
}
}
system("cls");
}

int menugeneros(){

int opc;
while(true){
        system("cls");
std::cout<<"MENU GENEROS"<<std::endl;
std::cout<<"------------------"<<std::endl;

std::cout<<"1) AGREGAR GENERO"<<std::endl;
std::cout<<"2) LISTAR GENERO POR ID"<<std::endl;
std::cout<<"3) LISTAR TODO"<<std::endl;
std::cout<<"4) MODIFICAR ANIO DE ORIGEN"<<std::endl;
std::cout<<"5) ELIMINAR REGISTRO"<<std::endl;
std::cout<<"--------------------------------"<<std::endl;
std::cout<<"0) VOLVER AL MENU PRINCIPAL"<<std::endl;
std::cin>>opc;
system("cls");
switch(opc){
case 1:
    cargarGenero();
    break;
case 2:
    buscarGeneroPorID();
    break;
case 3:
    listarGeneros();
    break;
case 4:
    modificarAnio();
break;
case 5:
    bajageneros();
    break;
case 0:
    system("cls");
    return 0;
break;
default:
    system("cls");
    break;
}
}
}

int menubackup(){
    int opc;
    while(true){
    system("cls");

std::cout<<"MENU CONFIGURACION"<<std::endl;
std::cout<<"------------------"<<std::endl;

std::cout<<"1) COPIA DE SEGURIDAD DEL ARCHIVO DE MUSICOS"<<std::endl;
std::cout<<"2) COPIA DE SEGURIDAD DEL ARCHIVO DE GENEROS"<<std::endl;
std::cout<<"3) COPIA DE SEGURIDAD DEL ARCHIVO DE INSTRUMENTOS"<<std::endl;
std::cout<<"4) COPIA DE SEGURIDAD DEL ARCHIVO DE PAISES"<<std::endl;
std::cout<<"5) RESTAURAR EL ARCHIVO DE MUSICOS"<<std::endl;
std::cout<<"6) RESTAURAR EL ARCHIVO DE GENEROS"<<std::endl;
std::cout<<"7) RESTAURAR EL ARCHIVO DE INSTRUMENTOS"<<std::endl;
std::cout<<"8) RESTAURAR EL ARCHIVO DE PAISES"<<std::endl;
std::cout<<"9) ESTABLECER DATOS DE INICIO"<<std::endl;
std::cout<<"--------------------------------"<<std::endl;
std::cout<<"0) VOLVER AL MENU PRINCIPAL"<<std::endl;
    std::cin>>opc;
system("cls");
    switch(opc){
    case 1: copiamusicos();
    break;
    case 2: copiageneros();
    break;
    case 3: copiainstrumentos();
    break;
    case 4: copiapaises();
    break;
    case 5: restauraMusicos();
    break;
    case 6: restauraGeneros();
    break;
    case 7: restauraInstrumentos();
    break;
    case 8: restauraPaises();
    break;
    case 9: datosDefault();
    break;
    case 0:
        system("cls");
        return 0;
        break;
    default:
    system("cls");
    break;
    }

    }

}

int menuPaises(){
  int opc;
system("cls");
while(true){

std::cout<<"MENU PAISES"<<std::endl;
std::cout<<"------------------"<<std::endl;

std::cout<<"1) AGREGAR PAIS"<<std::endl;
std::cout<<"2) LISTAR PAIS POR ID"<<std::endl;
std::cout<<"3) LISTAR TODO"<<std::endl;
std::cout<<"4) MODIFICAR NOMBRE"<<std::endl;
std::cout<<"5) ELIMINAR REGISTRO"<<std::endl;
std::cout<<"--------------------------------"<<std::endl;
std::cout<<"0) VOLVER AL MENU PRINCIPAL"<<std::endl;
std::cin>>opc;

system("cls");
   switch(opc){
   case 1:
       AgregarPais();
        break;
   case 2:
        ListarPaisPorID();
        break;
   case 3:
      ListarPaises();
        break;
   case 4:
        ModificarNombreDelPais();
      break;

   case 5:
       bajaPais();
       break;

   case 0:
       system("cls");
    return 0;
    default:
    system("cls");
    break;
   }


}
system("cls");
}

int menuinstrumentos(){
    int opc;
system("cls");
while(true){

std::cout<<"MENU INSTRUMENTOS"<<std::endl;
std::cout<<"------------------"<<std::endl;

std::cout<<"1) AGREGAR INSTRUMENTO"<<std::endl;
std::cout<<"2) LISTAR INSTRUMENTO POR ID"<<std::endl;
std::cout<<"3) LISTAR TODO"<<std::endl;
std::cout<<"4) MODIFICAR NOMBRE"<<std::endl;
std::cout<<"5) ELIMINAR REGISTRO"<<std::endl;
std::cout<<"--------------------------------"<<std::endl;
std::cout<<"0) VOLVER AL MENU PRINCIPAL"<<std::endl;
std::cin>>opc;

system("cls");
   switch(opc){
   case 1:
       AgregarInstrumento();
        break;
   case 2:
        ListarInstrumentosPorId();
        break;
   case 3:
       ListarTodosLosInstrumentos();
        break;
   case 4:
        ModificarNombre();
      break;

   case 5:
        BajaInstrumentos();
       break;

   case 0:

       system("cls");
    return 0;
    default:
    system("cls");
    break;
   }


}
system("cls");
}

int menuConsignas(){
int opc;
system("cls");
while(true){

std::cout<<"MENU PARCIAL"<<std::endl;
std::cout<<"------------------"<<std::endl;

std::cout<<"1) CONSIGNA 1"<<std::endl;
std::cout<<"2) CONSIGNA 2"<<std::endl;
std::cout<<"3) CONSIGNA 3"<<std::endl;
std::cout<<"--------------------------------"<<std::endl;
std::cout<<"0) VOLVER AL MENU PRINCIPAL"<<std::endl;

   std::cin>>opc;
system("cls");
   switch(opc){
   case 1:
        consigna1();
        break;
   case 2:
        consigna2();
        break;
   case 3:
        consigna3();
        break;
   case 0:
       system("cls");
    return 0;
    default:
    system("cls");
    break;
   }
///NOTA FINAL LAB2 7
}
system("cls");
}



#endif // MENUS_H_INCLUDED
