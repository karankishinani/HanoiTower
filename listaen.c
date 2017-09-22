#include "HANOI.H"

int lista()
 {
  ptr_hanoi Torres, Find;
  int NumDiscos, index;

  system("color 1B");
  do
   {
   	printf("Resolucion de la Torre de Hanoi con Listas Enlazadas\nIntroduzca la cantidad de discos: ");scanf("%d",&NumDiscos);
   }while(NumDiscos<=0);

  setlimite(NumDiscos);

  inicializar_torre(&Torres);

  agregar_torre(&Torres,3);
  agregar_torre(&Torres,2);
  agregar_torre(&Torres,1);

  Find=buscar_torre(Torres,1);

  for(index=NumDiscos; index>=1; index--)
   agregar_valor(Find,index);

  actualizar(Torres);

  resolver(Torres,NumDiscos,1,3,2);

  return 0;
 }
