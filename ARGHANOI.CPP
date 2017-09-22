#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define DISCOS 5

struct reg
{
  int torre[DISCOS];
};


int arreglo()
{
   struct reg hanoi[DISCOS];
   int victoria=0, i=1,a=0, b=0;
   int lugartope1=0,lugartope2=0,lugartope3=0,tope1=0,tope2=0,tope3=0;
   int y, w;
   /* i = intentos */
   int npasos = 2;

    /*para los discos*/
   char disc0[15], disc1[15], disc2[15], disc3[15], disc4[15], disc5[15];
   strcpy(disc0,"+           + ");
   strcpy(disc1,"+     \333     + ");
   strcpy(disc2,"+    \262\262\262    + ");
   strcpy(disc3,"+   \333\333\333\333\333   + ");
   strcpy(disc4,"+  \262\262\262\262\262\262\262  + ");
   strcpy(disc5,"+ \333\333\333\333\333\333\333\333\333 + ");
   /* fin de variables para discos*/

  for(w = 1; w < DISCOS; w++)
   {
     npasos = npasos * 2;
   }
     npasos = npasos - 1;


/*los # son tamaños. 0 = vacio */
  for(y=(DISCOS-1); y>=0; y--)
  {
    hanoi[0].torre[y] = y+1;
  }

  for(y=0; y< DISCOS; y++)
  {
    hanoi[1].torre[y] = 0;
    hanoi[2].torre[y] = 0;

  } /* END FOR Y*/


  while(victoria == 0)
  {
    lugartope1=0;lugartope2=0,lugartope3=0;
    tope1 = 0; tope2 = 0;

    system("cls");
    printf("Estado de las torres:\n\n");

  for(int q = 0; q<DISCOS;q++)
  {
      if (hanoi[0].torre[q]==0) printf("%s",disc0);
        else if (hanoi[0].torre[q]==1) printf("%s",disc1);
        else if (hanoi[0].torre[q]==2) printf("%s",disc2);
        else if (hanoi[0].torre[q]==3) printf("%s",disc3);
        else if (hanoi[0].torre[q]==4) printf("%s",disc4);
        else if (hanoi[0].torre[q]==5) printf("%s",disc5);
        printf(" ");

        if (hanoi[1].torre[q]==0) printf("%s",disc0);
        else if (hanoi[1].torre[q]==1) printf("%s",disc1);
        else if (hanoi[1].torre[q]==2) printf("%s",disc2);
        else if (hanoi[1].torre[q]==3) printf("%s",disc3);
        else if (hanoi[1].torre[q]==4) printf("%s",disc4);
        else if (hanoi[1].torre[q]==5) printf("%s",disc5);
        printf(" ");

        if (hanoi[2].torre[q]==0) printf("%s",disc0);
        else if (hanoi[2].torre[q]==1) printf("%s",disc1);
        else if (hanoi[2].torre[q]==2) printf("%s",disc2);
        else if (hanoi[2].torre[q]==3) printf("%s",disc3);
        else if (hanoi[2].torre[q]==4) printf("%s",disc4);
        else if (hanoi[2].torre[q]==5) printf("%s",disc5);
        printf("\n");
  }

    printf("\nPrograma que resuelve la torre entre pasos. (Paso # %d / %d )\n",i-1,npasos);
    printf("\nPresione cualquier tecla para proseguir.\n");



  for(int t = 0; t < DISCOS; t++)
  {

    if(hanoi[0].torre[t] != 0)
	{
      tope1 = hanoi[0].torre[t];
      lugartope1 = t;
/*  printf("%d %d",tope1,lugartope1);
    getch(); */

      t = DISCOS;
    }

 } /* end for t */



   for(int l = 0; l < DISCOS; l++)
   {

     if(hanoi[1].torre[l] != 0)
     {
       tope2 = hanoi[1].torre[l];
       lugartope2 = l;
       l= DISCOS;
     }

   } /* end for l*/



   for(int g = 0; g < DISCOS; g++)
   {

     if(hanoi[2].torre[g] != 0)
	 {
        tope3 = hanoi[2].torre[g];
        lugartope3 = g;
        g = DISCOS;
     }

   } /* end for g*/


   if(hanoi[2].torre[DISCOS-1] == 0)
     tope3 = 0;

   if(tope1 == 0)
     lugartope1 = (DISCOS-1);

   if(tope2 == 0)
     lugartope2 = (DISCOS-1);

   if(tope3 == 0)
    lugartope3 = (DISCOS-1);


  printf("\nTopes: %d %d %d",tope1,tope2,tope3);
  printf("\nLTopes: %d %d %d",lugartope1,lugartope2,lugartope3);





   if(i == 1)
   {
     hanoi[2].torre[(DISCOS-1)] = tope1;
     hanoi[0].torre[lugartope1] = 0;
   }


   if(i > 1)
   { /*PASOS IMPARES. SE MUEVE EL DISCO MAS PEQUEÑO EN FORMA 3 -> 2 -> 1 -> 3 -> 2 -> 1... */
    if( (i % 2) != 0)
	{
      if(tope3 == 1)
      {
	    if(tope2 != 0)
		{
          hanoi[1].torre[lugartope2-1] = 1;
          hanoi[2].torre[lugartope3] = 0;

        } else
		  {
            hanoi[1].torre[lugartope2] = 1;
            hanoi[2].torre[lugartope3] = 0;

          }
     }

/* ______________________________________________ */

    else if(tope2 == 1)
    {
      if(tope1 != 0)
	  {
        hanoi[0].torre[lugartope1-1] = 1;
        hanoi[1].torre[lugartope2] = 0;
      }
	  else
      {
        hanoi[0].torre[lugartope1] = 1;
        hanoi[1].torre[lugartope2] = 0;
      }
    }
/* ______________________________________________ */


    else if(tope1 == 1)
    {
      if(tope3 != 0){
      hanoi[2].torre[lugartope3-1] = 1;
      hanoi[0].torre[lugartope1] = 0;
    }
	else
    {
      hanoi[2].torre[lugartope3] = 1;
      hanoi[0].torre[lugartope1] = 0;
    }
    }

/*fin pasos impares*/

} /* end if i % 2 != 0 */
/*PASOS PARES, SE HACE LA UNICA OPCION POSIBLE */

    if( (i % 2) == 0)
     {
       if(tope3 == 1)
       {
        if(tope2 > tope1)
        {
         if(tope1 == 0)
         {
           hanoi[0].torre[DISCOS-1] = tope2;
           hanoi[1].torre[lugartope2] = 0;
         }
    else
     {
       hanoi[1].torre[lugartope2-1] = tope1;
       hanoi[0].torre[lugartope1] = 0;
     } /* fin if tope 1 = 0 */

       } /*fin if tope 2 > */

    else if(tope1 > tope2)
       {
        if(tope2 == 0)
       {
         hanoi[1].torre[DISCOS-1] = tope1;
         hanoi[0].torre[lugartope1] = 0;

       }
    else
       {
         hanoi[0].torre[lugartope1-1] = tope2;
         hanoi[1].torre[lugartope2] = 0;
       }

       } /* fin if tope 1 > */
       }

/* fin tope 3 = 1 ______________________________________________ */

    else if(tope2 == 1)
     { if(tope3 > tope1)
       { if(tope1 == 0)
         {  hanoi[0].torre[DISCOS-1] = tope3;
            hanoi[2].torre[lugartope3] = 0;
         }
		 else
          {
            hanoi[2].torre[lugartope2-1] = tope1;
            hanoi[0].torre[lugartope1] = 0;
          } /* fin if tope 1 = 0 */

       } /*fin if tope 2 > */
    else if(tope1 > tope3)
      {
        if(tope3 == 0)
      {
        hanoi[2].torre[DISCOS-1] = tope1;
        hanoi[0].torre[lugartope1] = 0;
      }
     else
       {
        hanoi[0].torre[lugartope1-1] = tope3;
        hanoi[2].torre[lugartope3] = 0;
       }
      }
     }
/* ______________________________________________ */
   else if(tope1 == 1)
     {
       if(tope2 > tope3)
         {
		   if(tope3 == 0)
            {  hanoi[2].torre[DISCOS-1] = tope2;
               hanoi[1].torre[lugartope2] = 0;
            }
           else
            {
              hanoi[1].torre[lugartope2-1] = tope3;
              hanoi[2].torre[lugartope3] = 0;
            } /* fin if tope 1 = 0 */

        } /*fin if tope 2 > */

   else if(tope3 > tope2)
     {
	   if(tope2 == 0)
        {
		  hanoi[1].torre[DISCOS-1] = tope3;
          hanoi[2].torre[lugartope3] = 0;
        }
       else
        {
          hanoi[2].torre[lugartope3-1] = tope2;
          hanoi[1].torre[lugartope2] = 0;
        }
     }
    }
  } /* fin pasos pares */

} /* end if i > 1 */

getch();

   if(hanoi[2].torre[2] != 0 && hanoi[2].torre[0] != 0 && hanoi[2].torre[1] != 0)
   {
     victoria = 12;
   }

   if(hanoi[1].torre[2] != 0 && hanoi[1].torre[0] != 0 && hanoi[1].torre[1] != 0)
   {
     victoria = 12;
   }
   if(a==7 && b==7)
   {
     victoria = 12;
   }
    i++;
 } /* end while */

    if(a == 7 && b == 7)
	{
	}
    else
	{
      system("cls");
      printf("Estado de las torres:\n\n");

    for(int q = 0; q<DISCOS;q++)
    {
        if (hanoi[0].torre[q]==0) printf("%s",disc0);
        else if (hanoi[0].torre[q]==1) printf("%s",disc1);
        else if (hanoi[0].torre[q]==2) printf("%s",disc2);
        else if (hanoi[0].torre[q]==3) printf("%s",disc3);
        else if (hanoi[0].torre[q]==4) printf("%s",disc4);
        else if (hanoi[0].torre[q]==5) printf("%s",disc5);
        printf(" ");

        if (hanoi[1].torre[q]==0) printf("%s",disc0);
        else if (hanoi[1].torre[q]==1) printf("%s",disc1);
        else if (hanoi[1].torre[q]==2) printf("%s",disc2);
        else if (hanoi[1].torre[q]==3) printf("%s",disc3);
        else if (hanoi[1].torre[q]==4) printf("%s",disc4);
        else if (hanoi[1].torre[q]==5) printf("%s",disc5);
        printf(" ");

        if (hanoi[2].torre[q]==0) printf("%s",disc0);
        else if (hanoi[2].torre[q]==1) printf("%s",disc1);
        else if (hanoi[2].torre[q]==2) printf("%s",disc2);
        else if (hanoi[2].torre[q]==3) printf("%s",disc3);
        else if (hanoi[2].torre[q]==4) printf("%s",disc4);
        else if (hanoi[2].torre[q]==5) printf("%s",disc5);
        printf("\n");
    }

       printf("\nVictoria! Tomo %d movimientos.\n\n", i-1);
       getch();
    } /* end else */
    return 0;
} /* end main */

