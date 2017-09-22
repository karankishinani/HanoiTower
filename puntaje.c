#include <stdio.h>

int formato()
{
    FILE *fp;

    fp=fopen("puntaje.txt","w");

    fprintf(fp,"+------------------------------------------------+\n");
    fprintf(fp,"|                    PUNTAJES                    |\n");
    fprintf(fp,"+------------------------------------------------+\n");
    fprintf(fp,"|                                                |\n");
    fprintf(fp,"|   Nombre:                         Puntaje:     |\n");
    fprintf(fp,"|                                                |\n");

    fclose(fp);
}

int calcular_puntaje(int movimientos)
{
    int tot_mov=31, mov_extra, puntaje;

    mov_extra=movimientos-tot_mov;

    puntaje=100-mov_extra;

    if (puntaje <= 0)
        puntaje=1;

    return puntaje;
}

int agregar_puntaje(char* nombre, int puntaje)
{
    FILE *fp;

    fp=fopen("puntaje.txt","a");

    fprintf(fp,"|   %-32s%-13d|\n",nombre,puntaje);
    fprintf(fp,"|                                                |\n");

    fclose(fp);
}

int ver_puntaje()
{
    FILE *fp;
    int c;

    fp=fopen("puntaje.txt","a+");

    c=getc(fp);

    if (c== EOF)
    {
        printf("\n\n\t\tNo hay puntajes.\n\n\t\t");
    }
    else
    {
        while (c!= EOF)
        {
            putchar(c);
            c = getc(fp);
        }
    }

    fclose(fp);
}
