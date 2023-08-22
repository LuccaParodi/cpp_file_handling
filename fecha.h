#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

class Fecha{
    private:
        int dia, mes, anio;
    public:
        Fecha(int d=0, int m=0, int a=0){
            dia=d;
            mes=m;
            anio=a;
        }
        void Cargar();
        void Mostrar();
        ///sets
        void setDia(int x){if(x>0 && x<32) dia=x;}
        void setMes(int x){if(x>0 && x<13)mes=x;}
        void setAnio(int x){if (x>1500 && x<2023)anio=x;}
        ///gets
        int getDia(){return dia;}
        int getMes(){return mes;}
        int getAnio(){return anio;}
};

 void Fecha::Cargar(){
    std::cout<<"DIA: ";
    std::cin>>dia;
    std::cout<<"MES: ";
    std::cin>>mes;
    std::cout<<"ANIO: ";
    std::cin>>anio;
}

void Fecha::Mostrar(){
    std::cout<<dia<<"/"<<mes<<"/"<<anio<<std::endl;
}



#endif // FECHA_H_INCLUDED
