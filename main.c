#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
//CONSTANTES:
const int C=3;
const int DIST=5;
const int CANDIDATOS=4;

///PROTOTIPADOS:
//1
void CargarMatriz(int Uno[3][C],int Filas);
//2
void MostrarMatriz(int Uno[3][C]);
//3
void CargaAleatoria(int Uno[3][C]);
//4
int SumaMatriz(int Uno[3][C]);
//5
float Promedio(int Uno[3][C],int suma);
//6
void EncontrarNumero (int Uno[3][C],int dato);
//7
int CargarStrings(char Dos[10][10]);
//8
void MostrarString(char palabras[10][10],int validos);
//9
int BuscarString(char matriz[10][10],int validos,char palabra[10]);
//10
///no es necesaria utilizar la 7,8,11 y la 9
//11
void OrdenarString(char Desordenada[10][10],int validos);
//12
int DeterminanteFuncion(int Det[2][2]);
//13
int TendraInversa(int det[2][2],int valor);
//14
void CargarTabla(int[DIST][CANDIDATOS]);



//15


///////////////////////////////////////////////
int main()
{
    /*INDICE DE LA CONSOLA*/
    printf("(1)Cargar Matriz de Enteros.\n");
    printf("(2)Mostrar Matriz de Enteros.\n");
    printf("(3)Cargar una Matriz de Enteros Aleatorios.\n");
    printf("(4)Sumar Matriz de Enteros.\n");
    printf("(5)Promedio de una Matriz de Enteros.\n");
    printf("(6)Encontrar Numero en Matriz de Enteros.\n");
    printf("(7)Cargar Arreglo STRING y Retornar Cuantas Palabras.\n");
    printf("(8)Mostrar Matriz de String.\n");
    printf("(9)Determinar si un String se encuentra en una Matriz de Strings.\n");
    printf("(10)Determinar si un String se encuentra en una Matriz de Strings ordenados alfabeticamente.\n");
    printf("(11)Ordenar Alfabeticamente una Matriz.\n");
    printf("(12)Obtener el determinante de una matriz de 2x2.\n");
    printf("(13)Verificar si una Matriz de 2x2 tiene Inversa.\n");
    printf("candidatos.\n");



    ////////////////VARIABLES//////////////////
    int op,filas,resultado,dato,validos,indice,valor;
    float Prom;
    srand(time(NULL));
    int Uno[3][C];
    char Dos[10][10];
    int Det[2][2];
    char control='s';
    char palabra[10];
    int Cuadro[DIST][CANDIDATOS];

    ////////////////MENU//////////////////
    do
    {
        printf("\n");
        printf("INGRESE EL NUMERO DE LA OPERACION:\n");
        scanf("%i",&op);
        fflush(stdin);
        switch(op)
        {
        case 1:
            CargarMatriz(Uno,filas);
            break;
        case 2:
            MostrarMatriz(Uno);
            break;
        case 3:
              CargaAleatoria(Uno);
            break;
        case 4:
            resultado=SumaMatriz(Uno);
            printf("la suma de su matriz es:%i\n",resultado);
            break;
        case 5:
            /*funcion 3 numeros aleatorios
            funcion 2 la muestro
            funcion 4 la sumo*/
            Prom=Promedio(Uno,resultado);
            printf("EL PROMEDIOS ES DE:%.2f\n",Prom);
            break;
        case 6:
            /*funcion 3 numeros aleatorios
            funcion 2 la muestro*/
            printf("que numero desea buscar:\n");
            scanf("%i",&dato);
            EncontrarNumero(Uno,dato);
            break;
        case 7:
            validos=CargarStrings(Dos);
            printf("SE CARGARON %i PALABRAS\n",validos);
            break;
        case 8:
            MostrarString(Dos,validos);
            break;
        case 9:
            /*llamar funcion 7
              llamar funcion 8
            */
            printf("que string desea buscar:\n");
            scanf("%s",&palabra);
            indice=BuscarString(Dos,validos,palabra);
            if(indice==-1)
            {
                printf("-1");
            }
            break;
        case 10:
            printf("UTILIZAR LAS FUNCIONES EN ESTE ORDEN:7,8,11,9\n");
            break;
        case 11:
            OrdenarString(Dos,validos);
            break;
        case 12:
            valor=DeterminanteFuncion(Det);
            printf("El valor del determinante es de:%i\n",valor);
            break;
        case 13:
            TendraInversa(Det,valor);
            break;
        case 14:

            break;
        default:
            printf("OPCION NO VALIDA:\n");
            printf("INGRESE UN NUMERO DEL 1 AL 13:\n");
            scanf("%i",&op);
        }
        printf("\n");
        printf("DESEA VER OTROS CASOS PRESIONE s/n:\n");
        fflush(stdin);
        scanf("%c",&control);
    }
    while(control=='s');

    return 0;
}
/*FUNCION 1:
Hacer una función que reciba como parámetro una matriz de números enteros y permita que el usuario ingrese valores al mismo por teclado. La función debe cargar la matriz por completo.*/
void CargarMatriz(int Uno[3][C],int Filas)
{
    for(Filas=0;Filas<3;Filas++)
    {
        for(int J=0; J<C ;J++)
        {
           printf("Ingrese el elemento para la fila %i y la columna %i: ", Filas + 1, J+ 1);
            scanf("%i", &Uno[Filas][J]);
        }
    }
}
/*FUNCION 2:
2-Hacer una función que reciba como parámetro una matriz de números enteros y la muestre por pantalla (en formato matricial).*/
void MostrarMatriz(int Uno[3][C])
{

for(int Filas=0;Filas<3;Filas++)
    {
         for (int j= 0; j< C; j++)
        {
            printf("|%i|", Uno[Filas][j]);
        }
        printf("\n");
    }

}
/*FUNCION 3:
Hacer una función que reciba como parámetro una matriz de números enteros y que cargue la misma con números aleatorios (sin intervención del usuario). La función debe cargar la matriz por completo.*/
void CargaAleatoria(int Uno[3][C])
{
  for(int Filas=0;Filas<3;Filas++)
    {
        for(int J=0; J<C ;J++)
        {

            Uno[Filas][J]=rand()%20+1;
        }
    }
}
/*FUNCION 4:
Hacer una función tipo int que sume el contenido total de una matriz de números enteros.*/
int SumaMatriz(int Uno[3][C])
{
    int suma=0;
    for(int Filas=0;Filas<3;Filas++)
    {
         for (int j= 0; j< C; j++)
        {
           suma=suma+Uno[Filas][j];
        }
    }
   return suma;
}
/*FUNCION 5:
Hacer una función tipo float que calcule el promedio de una matriz de números enteros.*/
float Promedio(int Uno[3][C],int suma)
{
    float prom=(float)suma/(3 * C);
    return prom;
}
/*FUNCION 6:
Hacer una función que determine si un elemento se encuentra dentro de una matriz de números enteros. La función recibe la matriz y el dato a buscar.*/
void EncontrarNumero (int Uno[3][C],int dato)
{
    int flag=0;
    for(int fila=0;fila<3;fila++)
    {
        for(int columna=0;columna<C;columna++)
        {
            if(Uno[fila][columna]==dato)
            {
                flag=1;
            }
        }
    }
    if(flag==1)
    {
        printf("el numero se encuentra en la matriz:\n");
    }
    else
    {
        printf("el numero no se encuentra en la matriz:\n");
    }


}
/*FUNCION 7:
Hacer una función que cargue un arreglo de palabras (strings). La función debe retornar cuantas palabras se cargaron.  (puede ser a través del parámetro como puntero)*/
int CargarStrings(char Dos[10][10])
{
    int contador=0;
    char control='s';
    do
    {
        printf("ingrese una palabra:\n");
        scanf("%s",Dos[contador]);
        contador++;
        printf("continuar s/n:\n");
        fflush(stdin);
        scanf(" %c",&control);
    } while(control=='s');
    return contador;
}
/*FUNCION 8:
Hacer una función que muestre un arreglo de palabras.*/
void MostrarString(char palabras[10][10],int validos)
{
    printf("palabras cargadas:\n");
    for(int i= 0;i< validos;i++)
    {
        printf("%s\n", palabras[i]);
    }
}
/*FUNCION 9:
Hacer una función que determine si un string se encuentra dentro de un arreglo de strings. La función recibe el arreglo, la cantidad de palabras que contiene y la palabra a buscar. ///devuelve el índice de la fila en que se encuentra,
de lo contrario retorna -1*/
int BuscarString(char matriz[10][10],int validos,char palabra[10])
{

    int i;
    for(i=0;i<validos;i++)
    {
        if(strcmp(matriz[i],palabra)==0)
        {
            printf("El string se encuentra en la matriz\n");
            printf("La fila es: %i\n", i);
            return i;
        }
    }
    printf("el string no se encuentra\n");
    return -1;
}
/*FUNCION 10:
Hacer una función que determine si un string se encuentra dentro de un arreglo de strings ordenado alfabéticamente. La función recibe el arreglo, la cantidad de palabras que contiene y el string a buscar.
///devuelve el índice de la fila en que se encuentra, de lo contrario retorna -1*/
void FuncionNoNecesaria()
{

}
/*FUNCION 11:
Hacer una función (o varias) que ordene un arreglo de palabras por orden alfabético. (Por selección o inserción, el que más te guste).*/
void OrdenarString(char Desordenada[10][10],int validos)
{
 char aux[10];
 //arreglo aux
 for(int f=0;f<validos-1;f++)
//ultimo elemento ya va estar ubicado bien
 {
     for(int c=0;c<validos-f-1;c++)
        //ultimo elemento ya va estar ubicado bien
     {
         if(strcmp(Desordenada[c],Desordenada[c+1])>0)
            //si la primera fila es mayor a la segunda(evaluo la columna en la posicion 0)
         {
             strcpy(aux,Desordenada[c]);
             //palabra 1 pasa a aux
             strcpy(Desordenada[c],Desordenada[c+1]);
             //copio palabra 2 en la posicion de la palabra 1
             strcpy(Desordenada[c+1],aux);
             //paso la palabra guardada en aux a la posicion de la palabra 2
         }
     }
 }
}
/*FUNCION 12:
Hacer una función que retorne el determinante de una matriz de 2x2.*/
int DeterminanteFuncion(int Det[2][2])
{

    for(int f=0;f<2;f++)
    {
        for(int c=0;c<2;c++)
        {
            printf("Ingrese el elemento para la fila %i y la columna %i: ", f + 1, c+ 1);
            scanf("%i", &Det[f][c]);
        }
    }//cargo matriz de 2x2
    //////////////////////////////////////////////////////////////////////////////////////
    //muestro
    printf("\n");
    for(int f=0;f<2;f++)
    {
         for (int c= 0; c< 2; c++)
        {
            printf("|%i|", Det[f][c]);
        }
        printf("\n");
    }
    //Sacar el determinante
    int num1=Det[0][0]*Det[1][1];
    printf("%i\n",num1);
    int num2=Det[0][1]*Det[1][0];
    printf("%i\n",num2);
    int valor=num1-num2;

    return valor;

}
/*FUNCION 13:
Función que verifique si una matriz de 2x2 tiene inversa.*/
int TendraInversa(int matriz[2][2],int valor)
{

    ///Si el det es mayor a 0 tendra inversa
    if(valor<0)
    {
        printf("SU MATRIZ NO TIENE INVERSA\n");
    }
    else
    {
        printf("SU MATRIZ TIENE INVERSA\n");
    }
}
/*FUNCION 14:*/
void consigna()
{
/*Escribir un programa que haga las siguientes tareas:
a. Imprimir la tabla anterior con cabeceras incluidas.
b. Calcular e imprimir el número total de votos recibidos por cada candidato y el porcentaje total de votos emitidos. Así mismo, visualizar el candidato más votado.
c. Si algún candidato recibe más del 50% de los votos, el programa imprimirá un mensaje declarándolo ganador.
d. Si algún candidato recibe menos del 50% de los votos, el programa debe imprimir el nombre de los dos candidatos más votados que serán los que pasen a la segunda ronda de las elecciones.
*/
}


