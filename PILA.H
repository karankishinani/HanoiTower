#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define PNULL ((struct _pila*)0)

struct _pila
 {
  int valor;
  struct _pila *sgte;
 };

typedef struct _pila  var_pila;
typedef struct _pila* ptr_pila;

void inicializar_pila(ptr_pila* pila, int limite)
 {
  ptr_pila nuevo;
  int index;
  
  *pila=PNULL;
  
  for(index=1; index<=limite; index++)
   {
   	nuevo=(ptr_pila)malloc(sizeof(var_pila));
    assert(nuevo);
  
    nuevo->valor=0;
    nuevo->sgte=*pila;
    *pila=nuevo;
   }
 }

void agregar(ptr_pila pila, int valor)
 {    
  ptr_pila aux;  
  aux=pila;
  
  if(aux->valor!=0)
   assert(0);
  
  while(aux->sgte)
   {
   	if(aux->sgte->valor!=0)
     {
      aux->valor=valor;
      return;
     }
    aux=aux->sgte;
   }
   
  aux->valor=valor;  
 }

int  extraer(ptr_pila pila)
 {
  ptr_pila aux;
  int valor;
  
  aux=pila;
  
  while(aux)
   {
    if(aux->valor!=0)
     {
      valor=aux->valor;
      aux->valor=0;
      return valor;
     }
    aux=aux->sgte;
   }
  assert(0);
 }
