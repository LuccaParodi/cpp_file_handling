# include <iostream>
# include <cstdlib>
# include <cstring>
# include <cstdio>
# include <ctime>

# include "fecha.h"
# include "obj musicos.h"
# include "generos.h"
# include "instrumentos.h"
# include "Paises.h"
# include "funciones globales.h"
# include "menus.h"
# include "reportes.h"

///Integrantes: Folgueral Joaquin, Parodi Lucca.
int main()
{
    system("cls");
    int opc;
    while(true){
   std::cout<<"MENU PRINCIPAL"<<std::endl;
   std::cout<<"...................................................."<<std::endl;
   std::cout<<"1) MENU DE MUSICOS"<<std::endl;
   std::cout<<"2) MENU DE GENEROS"<<std::endl;
   std::cout<<"3) MENU INSTRUMENTOS"<<std::endl;
   std::cout<<"4) MENU PAISES"<<std::endl;
   std::cout<<"5) REPORTES"<<std::endl;
   std::cout<<"6) CONFIGURACION"<<std::endl;
   std::cout<<"...................................................."<<std::endl;
   std::cout<<"0) FIN DEL PROGRAMA"<<std::endl;
   std::cout<<" SELECCIONE UNA OPCION"<<std::endl;
    std::cin>>opc;
switch(opc){
case 1:
    menumusicos();
    break;
case 2:
    menugeneros();
    break;
case 3:
    menuinstrumentos();
    break;
case 4:
    menuPaises();
    break;
case 5:
    menuConsignas();
    break;
case 6:
    menubackup();
    break;
case 0:
    return 0;
    break;
default:
    system("cls");
    break;
}


}
system("cls");
}
