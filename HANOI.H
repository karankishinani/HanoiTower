#include <conio.h>
#include "PILA.H"

#define HNULL ((struct _hanoi*)0)

struct _hanoi
 {
  int torre;
  ptr_pila lista;
  struct _hanoi *sgte;
 };

typedef struct _hanoi  var_hanoi;
typedef struct _hanoi* ptr_hanoi;

int discos=5;

void setlimite(int limite)
 {
  if(limite<=0)
   return;
   
  discos=limite;
 }

void inicializar_torre(ptr_hanoi* hanoi)
 {
  *hanoi=HNULL;
 }

void agregar_torre(ptr_hanoi* hanoi, int torre)
 {
  ptr_hanoi nuevo;
  nuevo=(ptr_hanoi)malloc(sizeof(var_hanoi));
  assert(nuevo);
  
  nuevo->torre=torre;
  inicializar_pila(&nuevo->lista,discos);
  nuevo->sgte=*hanoi;
  *hanoi=nuevo;
 }

ptr_hanoi buscar_torre(ptr_hanoi hanoi, int torre)
 {
  ptr_hanoi aux;
  aux=hanoi;
  
  while(aux)
   {
    if(aux->torre==torre)
     break;
    aux=aux->sgte;
   }
  
  return aux;
 }

void agregar_valor(ptr_hanoi hanoi, int valor)
 {
  assert(hanoi);   
  agregar(hanoi->lista,valor);  
 }

int extraer_valor(ptr_hanoi hanoi)
 {
  assert(hanoi);
  return extraer(hanoi->lista);
 }

void mostrar_torres(ptr_hanoi hanoi)
 {
  ptr_pila pilas[3];
  int x, y;
  
  for(x=0; x<3; x++)
   {
   	pilas[x]=hanoi->lista;
   	hanoi=hanoi->sgte;
   }
  
  for(x=1; x<=discos; x++)
   {
   	for(y=0; y<3; y++)
   	 if(y==2)
   	  {
   	   printf("%3d\n",pilas[y]->valor);
   	   pilas[y]=pilas[y]->sgte;
   	  }
   	 else
   	  {
   	   printf("%3d ",pilas[y]->valor);
   	   pilas[y]=pilas[y]->sgte;
   	  }     
   }
   
 }

void actualizar(ptr_hanoi hanoi)
 {
  system("cls");
  mostrar_torres(hanoi);
  getch();
 }

void resolver(ptr_hanoi torres, int discs, int origen, int destino, int auxiliar)
 {
  if(discs==1)
   {
   	agregar_valor(buscar_torre(torres,destino),extraer_valor(buscar_torre(torres,origen)));
   	actualizar(torres);
   	return;
   }
  
  resolver(torres,discs-1,origen,auxiliar,destino);
  agregar_valor(buscar_torre(torres,destino),extraer_valor(buscar_torre(torres,origen)));
  actualizar(torres);
  resolver(torres,discs-1,auxiliar,destino,origen);
 }


