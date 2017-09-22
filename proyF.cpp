
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include "Torres_main.cpp"
#include "ARGHANOI.cpp"
#include "listaen.c"
#include "recursividad.c"

using namespace std;

int main()
{
	int opc, inicio=0;

	system("COLOR 79");
	cout<<"\n\n\t\t\t UNIVERSIDAD TECNOLOGICA DE PANAMA \n\t\t\tLIC. ING. EN SISTEMAS Y COMPUTACION \n\n\t\t\t\tEstructura de Datos I \n\n\t\t\t\t   Proyecto Final \n\t\t\t\t\tHanoi";
	cout<<"\n\n\t\tIntegrantes:\tCollazos Cristian     8-889-816 \n\t\t\t\tFeng Eimy\t      3-733-1709 \n\t\t\t\tGracia Jose\t      8-893-1290 \n\t\t\t\tKishinani Karan\t      3-735-1345 \n\t\t\t\tLovato Gillianne      8-896-2057 \n\t\t\t\tOchoa Sting\t      8-891-629 ";
	cout<<"\n\n\t\t\tProfesor: Nicholas Beliz Osorio \n\n\t\t\t\t   Grupo: 1IL121 \n\n\t\t\t            I Semestre \n\t\t\t\t        2014";
	getch();

	system("COLOR 70");
	do{
		system("cls");system("COLOR 70");
		cout<<"\n\n\tMENU: \n\n\t\t1) Jugar \n\n\t\t2) Resolucion con arreglos \n\n\t\t3) Resolucion con Listas Enlazadas \n\n\t\t4) Resolucion con Recursividad \n\n\t\t5) Puntajes \n\n\t\t6) Salir \n\n\n\t\tIngrese una opcion --> ";
		cin>>opc;
		switch(opc)
		{
			case 1: system("cls");system("color 1B");
                    inicio=juego(inicio);
				    break;

			case 2: system("cls");system("color 1B");
                    arreglo();
				    break;

			case 3: system("cls");
                    lista();
				    break;

			case 4: system("cls");
                    recursivo();
				    break;

			case 5: system("cls");system("color 1B");
                    ver_puntaje();
					break;

            case 6: system("cls");
                    cout <<"\n\n\n\t\t*  *  *  A  D  I  O  S  !  !  !  *  *  *\n\n\n\t\t";
					break;

			default: cout<<"\t\t\t\t       Opcion incorrecta\n\n\t";
				     break;
		}
		system("pause");
	}while(opc!=6);
	return 0;
}
