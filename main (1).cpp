#include <iostream> //Incluimos librerias
#include <stdlib.h>
#include <stdio.h>
#define MAX 10  //Definimos constante

using namespace std;

/*Almacenar en una estructura los datos de uno o varios estudiantes
de la Politecnica Nacional, que contenga la información personal como:
cedula, nombre completo y carrera a la que pertenece; en otro arreglo
se almacenara 3 calificaciones finales de una materia y se indicara
si el estudiante aprueba o no la materia*/

typedef struct{ //Declaracion de estructura
    char cedula[10];
    char nombre_completo[50];
    char carrera[20];
} Datos_Estudiante;

typedef struct{ //Declaracion de estructura anidada
    Datos_Estudiante estudiante;
    float calificacion[3];
    char nombre_materia[20];
    float promedio;
}Notas_Estudiante;

int main()
{
    int i,j,n; //Declaracion de variables
    float sumatoria_notas=0;
    Notas_Estudiante notas[MAX];

    //Inicializacion de estructuras
    for(i=0;i<MAX;i++){
       notas[i].estudiante.cedula[0]='N/D';
       notas[i].estudiante.nombre_completo[0]='N/D';
       notas[i].estudiante.carrera[0]='N/D';
    for(j=0;j<3;j++){
        notas[i].calificacion[j]=0;
    }
        notas[i].nombre_materia[0]='N/D';
        notas[i].promedio=0;
    }
    i=0;

    cout<<"\nCuantos estudiantes se ingresaran: "<<endl; //Mostrar mensaje en pantalla
    cin>>n; //Ingreso de dato por teclado
    while(i<n){ //Bucle para ingreso de informacion en las estructuras
        cout<<"Ingresar la cedula del estudiante "<<i+1<<" :"<<endl;
        cin>>notas[i].estudiante.cedula;
        cout<<"Ingresar el nombre del estudiante "<<i+1<<" :"<<endl;
        cin>>notas[i].estudiante.nombre_completo;
        cout<<"Ingresar la carrera del estudiante "<<i+1<<" :"<<endl;
        cin>>notas[i].estudiante.carrera;
        cout<<"Ingresar la materia a la que pertenecen las notas "<<i+1<<" :"<<endl;
        cin>>notas[i].nombre_materia;

        for(j=0;j<3;j++){ //Bucle para ingreso de informacion de notas
            cout<<"Ingresar la calificacion "<<j+1<<" :"<<endl;
            cin>>notas[i].calificacion[j];
            if (notas[i].calificacion[j]>=0 && notas[i].calificacion[j]<=10){ //Validacion de ingreso de informacion
                sumatoria_notas = sumatoria_notas + notas[i].calificacion[j]; //Sumatoria de notas
            }
            else{ //Seguimiento del if
                cout<<"Ingrese valores entre 0 - 10; vuelva a ingresar"<<endl;
                j--;
            }
        }
            notas[i].promedio=sumatoria_notas/3; //Calculo del promedio de cada uno de los estudiantes de la estructura
        i++;
    }
    system("cls"); //Funcion que borra pantalla

    cout<<"************************************************************************************************"<<endl;

    for (i=0;i<n;i++){ //Bucle para impresion de datos de las estructuras
        cout<<"Estudiante: "<<notas[i].estudiante.nombre_completo;
        cout<<" \tCarrera: "<<notas[i].estudiante.carrera;
        cout<<" \tMateria: "<<notas[i].nombre_materia;
        cout<<" \tPromedio: "<<notas[i].promedio;
        if(notas[i].promedio>=7){ //Verificacion de aprobacion segun el promedio
            cout<<"\tAPROBADO"<<endl;
        }
        else{
            cout<<"\tREPROBADO"<<endl;
        }

    }
     cout<<"***********************************************************************************************"<<endl;

    return 0;
}










