#include <iostream>
#include <stdlib.h>
using namespace std;

//Se quiere realizar un programa que lea por teclado las 5 notas obtenidas por un alumno
//(comprendidas entre 0 y 10). A continuación debe mostrar todas las notas, la nota media,
//la nota más alta que ha sacado y la menor.

int main()
{
    float nota, media, mayor, menor, numeroactual; //Declaración de variables
    char estudiante[50];
    float notas[5]; //Declaración del arreglo
    int i; //Declaracion de contador

    cout<<"Ingresar el nombre del estudiante:"<<endl; //Mostrar en pantalla un mensaje
    cin>>estudiante; //Pedir un dato por teclado

    cout<<"Ingrese las 5 notas de "<<estudiante<<endl;
    for(i=0;i<5;i++) //Utilizamos bucle for para recorrer el arreglo
    {
        cout<<"Ingrese nota No: "<< i+1 << ">> ";
        cin>>nota;

        if(nota>=0 && nota<=10){ //Condicion para ingresar notas de 0-10
            notas[i]=nota; //Asignar la nota ingresada a una posicion del arreglo
        }
        else{
            cout<<"Debe ingresar notas entre 0-10.\nIngrese nuevamente la nota:"<<endl;
            i--; //vuelve a la posicion del arreglo para volver a ingresar la nota
    }
    }
system("cls"); //Funcion para limpiar pantalla

    cout<<"Las notas del "<<estudiante<< "  son: "<<endl;
    for(i=0;i<5;i++){ //Bucle for para mostrar en pantalla el arreglo

        cout<<notas[i]<<"\n"; //Muestra en pantalla cada posicion del arreglo

    }
    for(i=0;i<5;i++) //Bucle for para recorrer el arreglo
    {
       //promedio de notas
       numeroactual = notas[i]; //Asignar a una variable el dato de la posicion actual del arreglo
       media = media + numeroactual; //Sumatoria de la media


       //número mayor
       if(notas[i]>mayor) //Condicion para buscar el numero mayor
       mayor=notas[i]; //Asignacion a una variable el numero mayor


        //numero menor
       if (menor==0){ //Condicion para saber si el dato de la variable es cero
       menor=notas[i];}  //Asignamos a una variable el dato de la posicion
       else if (notas[i] < menor){ //condicion para conocer el numero menor en el arreglo
       menor=notas[i];} //Asigamos a una variable el dato de la posicion

    }

    media=media/5; //Operacion aritmetica
    cout<<"\n\nLa nota media es: "<<media<<endl;
    cout<<"La nota mayor es: "<<mayor<<endl;
    cout<<"La nota menor es: "<<menor<<endl;

    return 0;
}
