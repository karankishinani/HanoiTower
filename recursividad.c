#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include "pilar.h"

struct pila hanoi[3];

void estado()
 {
  system("cls");
  printf("Hecho con Recursividad\n\nLa secuencia de movimientos para resolver la Torre de Hanoi son:\n\n");
  mostrar(&hanoi[0],3);
  getch();
 }

void resolver(int discos,int origen,int destino,int auxiliar)
 {
  if(discos==1)
   {
   	apilar(&hanoi[destino],desapilar(&hanoi[origen]));
    estado();
    return;
   }

  resolver(discos-1,origen,auxiliar,destino);
  apilar(&hanoi[destino],desapilar(&hanoi[origen]));
  estado();
  resolver(discos-1,auxiliar,destino,origen);
 }

int recursivo()
 {
  int x;

  inicializar(&hanoi[0]);
  inicializar(&hanoi[1]);
  inicializar(&hanoi[2]);

  for(x=0; x<LONGITUD; x++)
   apilar(&hanoi[0],LONGITUD-x);

  system("color 1B");
  estado();

  /*Cantidad de Discos, Torre Origen, Torre Destino, Torre Auxiliar*/
  resolver(LONGITUD,0,2,1);

  return 0;
 }
