#include <assert.h>
#include <stdio.h>
#define LONGITUD 5

/*Estructura tipo pila*/
struct pila
 {
  int lista[LONGITUD];
  int tope;
 };

/*Inicializa o restablece la pila por defecto: (pila vacia)*/
void inicializar(struct pila *x)
 {
  int z;

  for(z=0; z<LONGITUD; z++)
   x[0].lista[z]=0;

  x[0].tope=0;
 }

/*Verifica si se pueden agregar mas elementos a la pila*/
int apilable(struct pila *x)
 {
  return x[0].tope!=LONGITUD;
 }

/*Verifica si hay elementos para extraer en la pila*/
int desapilable(struct pila *x)
 {
  return x[0].tope!=0;
 }

/*Agrega un elemento a la pila*/
void apilar(struct pila *x, int elemento)
 {
  assert(apilable(x));

  x[0].lista[x[0].tope++]=elemento;
 }

/*Extrae un elemento de la pila y lo retorna*/
int desapilar(struct pila *x)
 {
  int elemento;

  assert(desapilable(x));

  elemento=x[0].lista[--x[0].tope];
  x[0].lista[x[0].tope]=0;

  return elemento;
 }

/*Restablece la pila por defecto: (pila vacia)*/
void vaciar(struct pila *x)
 {
  while(desapilable(x))
   desapilar(x);
 }

/*Muestra en pantalla n numero de pilas una a continuacion de otra*/
void mostrar(struct pila *x, int pilas)
 {
  int y,z;
  /*para los discos*/
   char disc0[15], disc1[15], disc2[15], disc3[15], disc4[15], disc5[15];
   strcpy(disc0,"+           + ");
   strcpy(disc1,"+     \333     + ");
   strcpy(disc2,"+    \262\262\262    + ");
   strcpy(disc3,"+   \333\333\333\333\333   + ");
   strcpy(disc4,"+  \262\262\262\262\262\262\262  + ");
   strcpy(disc5,"+ \333\333\333\333\333\333\333\333\333 + ");
   /* fin de variables para discos*/

  if (pilas <= 5)
  {
    for(z=LONGITUD-1; z>=0; z--)
    for(y=0; y<pilas; y++)
    {
        if (y==pilas-1)
        {
            if (x[y].lista[z]==0) printf("%s",disc0);
            else if (x[y].lista[z]==1) printf("%s",disc1);
            else if (x[y].lista[z]==2) printf("%s",disc2);
            else if (x[y].lista[z]==3) printf("%s",disc3);
            else if (x[y].lista[z]==4) printf("%s",disc4);
            else if (x[y].lista[z]==5) printf("%s",disc5);
            printf("\n");
        }
        else
        {
            if (x[y].lista[z]==0) printf("%s",disc0);
            else if (x[y].lista[z]==1) printf("%s",disc1);
            else if (x[y].lista[z]==2) printf("%s",disc2);
            else if (x[y].lista[z]==3) printf("%s",disc3);
            else if (x[y].lista[z]==4) printf("%s",disc4);
            else if (x[y].lista[z]==5) printf("%s",disc5);
            printf(" ");
        }
    }
    /*printf((y==pilas-1)?("%2d\n"):("%2d "),x[y].lista[z]);*/
  }

  else
  {
    for(z=LONGITUD-1; z>=0; z--)
    for(y=0; y<pilas; y++)
    printf((y==pilas-1)?("%2d\n"):("%2d "),x[y].lista[z]);
  }

 }

