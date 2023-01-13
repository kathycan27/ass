#include <iostream>
#include <stdlib.h>
using namespace std;

struct nodo{  //Declaracion de estructura nodo
       string utiles;   //Declaracion de dato string de la estructura
       struct nodo *sgte;  //Asignacion del puntero a la estructura
};

typedef struct nodo *LISTA;  //Asignacion del tipo de definicion de la estructura nodo

void insertarInicio(LISTA &lista, string valor) //Función insertar al inicio de la lista
{
    LISTA q; //Definimos q como una estructura de LISTA
    q = new(struct nodo); //Asignacion de un nuevo nodo
    q->utiles = valor;  //Asignamos el valor ingresado
    q->sgte = lista; //Asignamos a nuestra lista un nuevo nodo
    lista  = q;  //Asignamos el valor del nuevo nodo a lista
}

void insertarFinal(LISTA &lista, string valor) //Funcion insertar al final de la lista
{
    LISTA t, q = new(struct nodo); //Definimos t y asignamos q como nuevo nodo

    q->utiles  = valor;  //Asi
    q->sgte = NULL;

    if(lista==NULL)
    {
        lista = q;
    }
    else
    {
        t = lista;
        while(t->sgte!=NULL)
        {
            t = t->sgte;
        }
        t->sgte = q;
    }

}

void buscarMaterial(LISTA lista, string valor)
{
    LISTA q = lista;
    int i = 1, band = 0;

    while(q!=NULL)
    {
        if(q->utiles==valor)
        {
            cout<<endl<<" Encontrada en posicion "<< i <<endl;
            band = 1;
        }
        q = q->sgte;
        i++;
    }

    if(band==0)
        cout<<"\n\n utiles no encontrado..!"<< endl;
}

void mostrarLista(LISTA lista)
{
     int i = 0;

     while(lista != NULL)
     {
          cout <<' '<< i+1 <<") " << lista->utiles << endl;
          lista = lista->sgte;
          i++;
     }
}


void eliminarMaterial(LISTA &lista, string valor)
{
    LISTA p, ant;
    p = lista;

    if(lista!=NULL)
    {
        while(p!=NULL)
        {
            if(p->utiles==valor)
            {
                if(p==lista)
                    lista = lista->sgte;
                else
                    ant->sgte = p->sgte;

                delete(p);
                return;
            }
            ant = p;
            p = p->sgte;
        }
    }
    else
        cout<<" Lista vacia..!";
}

void eliminaRepetidos(LISTA &lista, string valor)
{
    LISTA q, ant;
    q = lista;
    ant = lista;

    while(q!=NULL)
    {
        if(q->utiles==valor)
        {
            if(q==lista) // primero elemento
            {
                lista = lista->sgte;
                delete(q);
                q = lista;
            }
            else
            {
                ant->sgte = q->sgte;
                delete(q);
                q = ant->sgte;
            }
        }
        else
        {
            ant = q;
            q = q->sgte;
        }

    }// fin del while

    cout<<"\n\n Valores eliminados..!"<<endl;
}

void menu1()
{
    cout<<"\n\tLISTADO DE UTILES ESCOLARES            "<<endl;
    cout<<" 1. INSERTAR UTILES AL INICIO DE LA LISTA              "<<endl;
    cout<<" 2. INSERTAR UTILES AL FINAL DE LA LISTA              "<<endl;
    cout<<" 3. MOSTRAR LISTA DE UTILESES                  "<<endl;
    cout<<" 4. BUSCAR UTILES EN LA LISTA                 "<<endl;
    cout<<" 5. ELIMINAR UTILES DE LA LISTA            "<<endl;
    cout<<" 6. ELIMINAR UTILES DUPLICADOS DE LA LISTA' "<<endl;
    cout<<" 7. SALIR                            "<<endl;

    cout<<"\n INGRESE OPCION: ";
}


/*                        Funcion Principal
---------------------------------------------------------------------*/

int main()
{
    LISTA lista = NULL;
    int op;     // opcion del menu
    string _dato;  // elemenento a ingresar


    system("color 1b");

    do
    {
        menu1();
        cin>> op;

        switch(op)
        {
            case 1:

                 cout<< "\n Insertar utiles escolares: ";
                 cin>> _dato;
                 insertarInicio(lista, _dato);
            break;


            case 2:

                 cout<< "\n Insertar utiles escolares: ";
                 cin>> _dato;
                 insertarFinal(lista, _dato );
            break;


            case 3:

                 cout << "\n\n MOSTRANDO LISTA\n\n";
                 mostrarLista(lista);
            break;


            case 4:

                 cout<<"\n Material a buscar: ";
                 cin>> _dato;
                 buscarMaterial(lista, _dato);
            break;

            case 5:

                cout<<"\n Material a eliminar: ";
                cin>> _dato;

                eliminarMaterial(lista, _dato);
            break;

            case 6:

                cout<<"\n Material repetido a eliminar: ";
                cin>> _dato;

                eliminaRepetidos(lista, _dato);
            break;

                    }

        cout<<endl<<endl;
        system("pause");  system("cls");

    }while(op!=7);


   system("pause");
   return 0;
}
