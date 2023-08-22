#ifndef GUARDARDNI_H_INCLUDED
#define GUARDARDNI_H_INCLUDED

void guardarDNI(int DNIactual){

musicos obj;
  bool encontro = false;
  FILE * pCli;
  pCli = fopen("musicos.dat", "rb");
  while (fread( & obj, sizeof obj, 1, pCli) == 1) {
     if (DNIactual==obj.getDNI()){std::cout<<"este dni ya existe"<<std::endl;}
  }
  fclose(pCli);
}

#endif // GUARDARDNI_H_INCLUDED
