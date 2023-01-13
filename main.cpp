#include <iostream>
#include <stdlib.h>
using namespace std;
/*Suponga que debe construir un programa para registrar los tiempos de 3 lineas de buses diferentes
que tienen el mismo destino Quito-Valle. Cada linea va por calles diferentes, se deben
realizar 3 chequeos por cada ruta de buses. Usted debe registrar el nombre de la linea, por cada
ruta, registrar el tiempo de cada ruta y su tiempo promedio. Tome en cuenta que el nombre de tiene
una longitud de máximo 50 caracteres.*/
int main()
{
    char nombrelinea[3][50]; //Declaracion de arreglo multidimensional
    float rutas[3][3]; //Declaracion de arreglo multidimensional
    float promlinea[3]; //Declaracion de arreglo unidimensional
    float acu=0; //Declaracion de acumulador
    int i,j,k; //Declaracion de contadores

    cout<<"Informacion del tiempo de cada linea de bus"<<endl; //Mostrar en pantalla el mensaje
    for (i=0;i<3;i++) //Bucle for para recepcion de datos
    {
        cout<<"\nIngresar nombre de la linea de bus No. "<<i+1<<endl; //Mostrar en pantalla el mensaje
        cin>>nombrelinea[i]; //Ingreso de informacion por teclado en la posicion del arreglo
    }
    system("cls"); //Funcion para limpiar pantalla
    for (j=0;j<3;j++) //Bucle for para recorrer el arreglo
    {
        acu=0; //Declaracion de acumulador
        cout<<"\nIngrese el tiempo de la ruta "<<nombrelinea[j]<<endl; //Mostrar en pantalla el mensaje

        for (k=0;k<3;k++) //Bucle for para recorrer el arreglo y recepcion de datos
        {
            if(k==0){ //Condicion para establecer el tiempo en la mañana
            cout<<"\nEl tiempo en la mañana de la ruta"<<endl; //Mostrar en pantalla el mensaje
            cin>>rutas[j][k]; //Ingreso de informacion por teclado al arreglo
            acu=acu+rutas[j][k];} //Ingreso de datos alacumulador

            if(k==1){ //Condicion para establecer el tiempo en la tarde
            cout<<"El tiempo en la tarde de la ruta"<<endl;
            cin>>rutas[j][k];
            acu=acu+rutas[j][k];}

            if(k==2){ //Condicion para establecer el tiempo en la noche
            cout<<"El tiempo en la noche de la ruta"<<endl;
            cin>>rutas[j][k];
            acu=acu+rutas[j][k];}

        promlinea[j]=acu/3; //Calculo del promedio de los tiempos
    }
    }
    system("cls"); //Funcion para limpiar pantalla

    for (i=0;i<3;i++) //Bucle for recorrer el arreglo
    {
        cout<<"\nEl tiempo de la linea "<<nombrelinea[i]<<endl;
        cout<<"\tMañana\tTarde\tNoche"<<endl;
        for (j=0;j<3;j++) //Bucle for para recorrer el arreglo
        {
            cout<<"\t"<<rutas[i][j]; //Muestra los tiempos ingresados para cada linea
        }
        cout<<"\nEl tiempo promedio de la linea es: "<<promlinea[i]<<" minutos\n"<<endl; //Muestra en pantalla el promedio de los tiempos
    }

    return 0;
}
