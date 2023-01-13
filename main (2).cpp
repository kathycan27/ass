#include <iostream>
#include <stdlib.h>
using namespace std;

class persona //Declaramos la superclase persona
{
    protected:  //Le ponemos tipo protegido a los datos para que se pasen a la variante
        float peso; //Variable tipo decimal que guardara el peso
        float estatura; //Variable tipo decimal que guardara la estatura

    public:  //Le ponemos tipo publico a los constructores para poder utilizarlos en todo el programa
        void iniciar(float p,float e) //Este constructor se dedica a enlazar las variables del
            { //main principal con las de las clases por eso se pasan por parametros
                peso = p;  //La variable peso sera igual a la variable p
                estatura = e;  //La variable estatura sera igual a la variable e
            }; //Fin del constructor iniciar

        float ob_peso(void) //Constructor de tipo decimal que muestra el peso
            { return peso; }; //Devuelve el peso con return

        float ob_estatura(void) //Constructor de tipo decimal que muestra la estatura
            { return estatura; }; //Devuelve la estatura con return

};  //Fin de la declaracion de la superclase persona



class paciente:public persona//Declaramos la clase variante llamada paciente
    { //Hacemos que se pase todo lo protegido y publico a esta variante con :public persona
        private: //Aunque por defecto si no se pone el tipo es private, pero lo ponemos
            string nombre;  //Variable de tipo string que guardara el nombre del paciente
            int edad; //Variable de tipo entero que guardara la edad
            float indice; //Variable de tipo decimal que guardara el indice
            char tipo; //Variable tipo caracter que guara tipo


        public:  //Le ponemos tipo publico a los constructores para poder utilizarlos en todo el programa
            char iniciardatos(string nom,int ed, float in)
            { //método que enlaza variables del main
                nombre = nom;  //La variable nombre sera igual a nom
                edad = ed;  //La variable edad sera igual a ed
                indice = in; //La variable indice sera igual a in

            };  //Fin del método iniciar

            string ob_nombre(void) //Constructor de tipo string que muestra el nombre
            { return nombre; }; //Devuelve el nombre con return

            int ob_edad(void) //Constructor de tipo entero que muestra la edad
            { return edad; }; //Devuelve la edad con return

            float ob_indice(void) //Constructor de tipo entero que muestra el indice
            { return indice; }; //Devuelve el indice con return


            int ob_paciente(void) //Metodo
            {
            cout << "Ingrese el tipo de paciente que es: " << endl;  //Mostrar en pantalla el mensaje
            cout << "Si es Adulto inserte A\nSi es nino inserte N \n "  << endl;  //Mostrar en pantalla el mensaje
            cin >> tipo;  //Dato de entrada hacia la variable tipo char llamada tipo

            int tipopaciente=1;
            if((tipo == 'n') || (tipo == 'N')) //Condicion para permitir ingresar n o N
            {
               tipopaciente=1;

            }
            if((tipo == 'A') || (tipo == 'a')) //Condicion para permitir ingresar n o N
            {
                tipopaciente=0;
            }
            return tipopaciente;  //Devuelve con return el valor de la variable tipopaciente
            };  //Fin del método ob_pacientes


            string ob_pacientecalculoindicemasa(int tipo) //Método tipo string para obtener el calculo del indice
            {
                nombre="";
                edad=0;
                indice=0;
                peso=0;
                estatura=0;
                float masacorporal=0; //Inicializacion de las variables que se van a implementar
                string resultado;

                cout << endl << "Ingrese el nombre del paciente: ";  //Mostrar en pantalla el mensaje
                cin>>nombre;

                cout << endl << "Ingrese la edad del paciente: ";  //Mostrar en pantalla el mensaje
                cin>>edad;

                cout << endl << "Ingrese el peso del paciente: ";  //Mostrar en pantalla el mensaje
                cin>>peso;

                cout << endl << "Ingrese la estatura del paciente: ";  //Mostrar en pantalla el mensaje
                cin>>estatura;


                 iniciar(peso,estatura); //Llamar a la funcion iniciar
                 ob_peso();  //Funcion que devuelva el valor de peso
                 ob_estatura();  //Funcion que devuelva el valor de estatura

                 masacorporal=((peso)/(estatura*100)*(estatura*100));  //Calculo de la masa co

                 iniciardatos(nombre,edad,masacorporal);  //LLanar a la funcion inicializar datos

                 if (tipo==0){
                 if (masacorporal<=18.4)
                    resultado="Delgadez";
                 if (masacorporal>=18.5 && masacorporal<=24.9)
                    resultado="Peso normal";
                 if (masacorporal>=25)
                    resultado="Obesidad";
                }

                if (tipo==1){
                 if (masacorporal<=13)
                    resultado="Bajo Peso";
                 if (masacorporal>=18 && masacorporal<=20)
                    resultado="Peso Saludable";
                 if (masacorporal>=21)
                    resultado="Sobre Peso";
                }
            return resultado;  //Devuelve con return el valor de resultado
            };  //Fin del método ob_pacientecalculoindicemas




}; //Fin de la declaracion de la clase variante paciente


int main() //Funcion principal
{
    char n;
    int ed=0,tipopaciente=0; //Declaramos variables enteras
    float p=0,e=0;  //Declaramos variables decimales

    paciente paciente;  //Declaramos una variable tipo sub-clase paciente llamada paciente
    tipopaciente=paciente.ob_paciente(); //Asignamos el valor del constructor

    if (tipopaciente==1)
    cout <<"El paciente es un nino "<<endl;   //Mostrar mensaje
    else if(tipopaciente==0)
    cout << "El paciente es un Adulto "<<endl ;
    string v=paciente.ob_pacientecalculoindicemasa(tipopaciente);
    system("cls"); //Funcion que permite limpiar pantalla

    cout << "*************************   Caracteristicas del Paciente  ********************************"<< endl;  //Mostrar mensaje
    cout << "Nombre: " << paciente.ob_nombre() << endl  ;
    cout << "Peso: " << paciente.ob_edad() << "años" << endl ;
    cout << "Peso: " << paciente.ob_peso() << "kg" << endl ;  //Datos de salida, llamamos a ob_peso
    cout << "Estatura: " << paciente.ob_estatura() << "cm" << endl ;      //Datos de salida, llamamos a ob_estatura
    cout << "El paciente presenta un estado de : " << v << endl ;
    cout << "*****************************************************************************************"<< endl;

    cin.get();  //Limpia el buffer
    cin.get();  //Espera a que pulses una tecla
} //Fin de la funcion principal
