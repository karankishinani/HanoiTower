#include <iostream>
#include "puntaje.c"

using namespace std;

int juego(int inicio)
{
    char fin='0';
    int puntaje;
    char nombre[30];
    short indice, indice2, numero, destino, torre[3][5]={0}, errores, invalidos=0, movimientos=0;

    /*para los discos*/
   char disc0[15], disc1[15], disc2[15], disc3[15], disc4[15], disc5[15];
   strcpy(disc0,"+           + ");
   strcpy(disc1,"+     \333     + ");
   strcpy(disc2,"+    \262\262\262    + ");
   strcpy(disc3,"+   \333\333\333\333\333   + ");
   strcpy(disc4,"+  \262\262\262\262\262\262\262  + ");
   strcpy(disc5,"+ \333\333\333\333\333\333\333\333\333 + ");
   /* fin de variables para discos*/

    /*Se le asignan los valores iniciales a las torres.*/
    for(indice=0; indice<5; indice++)
        torre[0][indice]=indice+1;
    /*Se limpia la pantalla y se imprimen las reglas y objetivos del juego.*/
    system("cls");
    cout << "\t\tTorres de Hanoi" << endl << endl;
    cout << "Objetivo: Mover la pila desde la torre 1 hasta la torre 3." << endl << endl;
    cout << "Reglas:\n1) Solo se puede mover un numero a la vez.\n2) No se puede colocar un numero sobre otro de menor valor." << endl;
    cout << "3) Solo se puede desplazar el numero en la parte superior." << endl << endl;
    system("pause");system("cls");
    cout << "\t\tIntroduzca su nombre: " << endl << endl;
    gets(nombre);
    do
    {
        /*Se imprimen los valores de las torres y las instrucciónes para jugar.*/
        system("cls");
        cout << "\tTorres:" << endl << endl;
        for(indice=0; indice<5; indice++)
        {
            //cout << "\t";
            for(indice2=0; indice2<3; indice2++)
            {
                if (torre[indice2][indice]==0) printf("%s",disc0);
                else if (torre[indice2][indice]==1) printf("%s",disc1);
                else if (torre[indice2][indice]==2) printf("%s",disc2);
                else if (torre[indice2][indice]==3) printf("%s",disc3);
                else if (torre[indice2][indice]==4) printf("%s",disc4);
                else if (torre[indice2][indice]==5) printf("%s",disc5);
                printf(" ");
            }
                //cout << torre[indice2][indice] << "   ";
            cout << endl;
        }
        cout << endl << "Escoja desde que torre se movera el siguiente valor (torre 1, 2 o 3): ";
        cin >> numero;
        /*Se revisa que se halla introducido un valor válido.*/
        if(numero>=1 && numero<=3)
        {
            cout << endl << "Escoja a que torre se movera el siguiente valor (torre 1, 2 o 3): ";
            cin >> destino;
            /*Se revisa que se halla introducido un valor válido.*/
            if(destino>=1 && destino<=3)
            {
                /*Se revisa si la torre que contiene el valor a moverse y la torre a donde se quiere mover sean diferentes.*/
                if(numero==destino)
                {
                    cout << endl << "Debe escoger torres diferentes.";
                    invalidos++;
                }
                else
                {
                    /*Se revisa cual valor va a ser movido. Si no se encuentra alguno, imprime un mensaje de advertencia.*/
                    errores=0;
                    for(indice=0; indice<5; indice++)
                    {
                        if(torre[numero-1][indice]>0)
                            break;
                        else
                            ++errores;
                    }
                    if(errores==5)
                    {
                        cout << endl << "La torre " << numero << " esta vacia. Escoja una torre con un valor para mover.";
                        invalidos++;
                    }
                    else
                    {
                        /*Se revisa si la torre a donde el valor será movido está vacía o si tiene algún valor.*/
                        /*Si el valor en la torre es menor que el que se está moviendo, imprime un mensaje de advertencia.*/
                        /*Si el valor se puede mover, se le asigna al destino el valor a mover, y la casilla donde estaba el valor es reemplazada con un 0.*/
                        for(indice2=1; indice2<5; indice2++)
                        {
                            if(torre[destino-1][indice2]>0)
                                break;
                        }
                        if((torre[destino-1][indice2]==0)||(torre[destino-1][indice2]>torre[numero-1][indice]))
                        {
                            torre[destino-1][indice2-1]=torre[numero-1][indice];
                            torre[numero-1][indice]=0;
                            cout << endl << "Intercambio exitoso.";
                        }
                        else
                        {
                            cout << endl << "El valor en la torre " << destino << " es mayor que el de la torre " << numero << ". No se puede mover aqui.";
                            invalidos++;
                        }
                    }
                }
            }
            else
            {
                cout << endl << "Debe escoger un valor valido (1, 2, 3).";
                invalidos++;
            }
        }
        else
        {
            cout << endl << "Debe escoger un valor valido (1, 2, 3).";
            invalidos++;
        }
        movimientos++;
        cout << endl << endl;
        /*Revisa si la tercera torre tiene los valores necesarios para ganar el juego.*/
        /*Si los tiene, cambia la variable "fin" para salir del "Do While".*/
        if(torre[2][0]==1 && torre[2][1]==2 && torre[2][2]==3 && torre[2][3]==4 && torre[2][4]==5)
            fin='1';
        system("pause");
    }
    while(fin=='0');
    /*Imprime los valores finales de las torres y un mensaje de felicitaciones, luego sale del programa.*/
    system("cls");
    cout << endl << endl;
    for(indice=0; indice<5; indice++)
    {
        cout << "\t";
        for(indice2=0; indice2<3; indice2++)
            cout << torre[indice2][indice] << "   ";
        cout << endl;
    }

    puntaje = calcular_puntaje(movimientos);
    if (inicio==0)
    {
        formato();
        inicio++;
    }
    agregar_puntaje(nombre,puntaje);
    cout << endl << "Ha ganado en " << movimientos << " movimientos. Cometio " << invalidos << " errores. Su puntaje es "<< puntaje <<"\n\nFelicitaciones " << nombre << "!" << endl << endl;
    return inicio;
}
