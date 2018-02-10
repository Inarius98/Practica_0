

/* 
 * File:   main.cpp
 * Author: Andrés
 * Created on 6 de febrero de 2018, 2:02
 */

#include <iostream>
#include <string>

using namespace std;

struct vehiculo{
    string Marca;
    string Modelo;
    string Matricula;
    int Anio;
    float Precio;
};
/**
 * @brief Lectura de vehiculos por pantalla(por referencia).
 * @param[in,out] coche de tipo vehiculo a rellenar.
 * @post Introduce los datos necesarios en cada uno de los campos de la variable coche.
 */
void leePorTeclado(vehiculo& coche){
    do{
        cout<<"Introduce la marca del vehiculo(entre 3 y 20 caracteres): "<<endl;
        cin>>coche.Marca;
    }while(coche.Marca.length()<3||coche.Marca.length()>20);
    do{
        cout<<"Introduce el modelo del vehiculo(entre 1 y 30 caracteres): "<<endl;
        cin>>coche.Modelo;
    }while(coche.Modelo.length()<1||coche.Marca.length()>30);
    do{
        cout<<"Introduce la matricula del vehiculo(6 caracteres): "<<endl;
        cin>>coche.Matricula;
    }while(coche.Matricula.length()!=6);
    do{
        cout<<"Introduce el año de fabricación del vehiculo: "<<endl;
        cin>>coche.Anio;
    }while(coche.Anio<1900||coche.Anio>2018);
    do{
        cout<<"Introduce el precio del vehiculo: "<<endl;
        cin>>coche.Precio;
    }while(coche.Precio<0);
}
/**
 * @brief Lectura de vehiculos por pantalla(por punteros).
 * @param[in,out] coche de tipo vehiculo a rellenar.
 * @post Coloca los datos introducidos en cada uno de los campos de la variable coche.
 */
void leePorTeclado(vehiculo* coche){
    do{
        cout<<"Introduce la marca del vehiculo(entre 3 y 20 caracteres): "<<endl;
        cin>>coche->Marca;
    }while(coche->Marca.length()<3||coche->Marca.length()>20);
    do{
        cout<<"Introduce el modelo del vehiculo(entre 1 y 30 caracteres): "<<endl;
        cin>>coche->Modelo;
    }while(coche->Modelo.length()<1||coche->Marca.length()>30);
    do{
        cout<<"Introduce la matricula del vehiculo(6 caracteres): "<<endl;
        cin>>coche->Matricula;
    }while(coche->Matricula.length()!=6);
    do{
        cout<<"Introduce el año de fabricación del vehiculo: "<<endl;
        cin>>coche->Anio;
    }while(coche->Anio<1900||coche->Anio>2018);
    do{
        cout<<"Introduce el precio del vehiculo: "<<endl;
        cin>>coche->Precio;
    }while(coche->Precio<0);
}
/**
 * @brief Muestra los datos de coche en pantalla.(por referencia).
 * @param[in] coche de tipo vehiculo a leer.
 * @pre Debe haber introducido anteriormente datos en la variable coche.
 * @post Muestra por pantalla los datos introducidos en la variable coche.
 */
void muestraEnPantalla(const vehiculo& coche){
    cout<<"----------------------------------------------------------------------"<<endl;
    cout<<"La información del coche es: "<<endl;
    cout<<"La marca es: "<<coche.Marca<<endl;
    cout<<"El modelo es: "<<coche.Modelo<<endl;
    cout<<"La matricula es: "<<coche.Matricula<<endl;
    cout<<"El año de fabricación es: "<<coche.Anio<<endl;
    cout<<"El precio es: "<<coche.Precio<<endl;
    cout<<"----------------------------------------------------------------------"<<endl;
}
/**
 * @brief Muestra los datos de coche en pantalla.(por punteros).
 * @param[in] coche de tipo vehiculo a leer.
 * @pre Debe haber introducido anteriormente datos en la variable coche.
 * @post Muestra por pantalla los datos introducidos en la variable coche.
 */
void muestraEnPantalla(const vehiculo* coche){
    cout<<"La marca es: "<<coche->Marca<<endl;
    cout<<"El modelo es: "<<coche->Modelo<<endl;
    cout<<"La matricula es: "<<coche->Matricula<<endl;
    cout<<"El año de fabricación es: "<<coche->Anio<<endl;
    cout<<"El precio es: "<<coche->Precio<<endl;
}

/**
 * @brief Muestra los datos de un vector por pantalla.
 * @param v vector de tipo vehiculo a mostrar.
 * @param tam tamaño del vector.
 * @pre Debe haber introducido anteriormente datos en el vector.
 * @post Muestra los datos de la variable vector.
 */
void visualiza(vehiculo v[],int tam){
    for(int i=0;i<tam;i++){
        muestraEnPantalla(v[i]);
    }
}

/**
 * @brief Calcula el máximo precio entre los datos introducidos.
 * @param[in] coche de tipo vehiculo
 * @param[in,out] max para conocer el maximo
 * @param[in,out] cont para conocer la posicion en la que se encuentra el precio máximo.
 * @param[in,out] i para conocer la posicion en la que se encuentra el precio máximo a través del ciclo for realizado en el main.
 * @pre Debe haber introducido anteriormente datos en la variable coche.
 * @post Calcula el precio máximo de un coche entre los precios introducidos por el usuario.
 */
void maxPrecio(vehiculo coche,int& max,int& cont,int& i){
    if(coche.Precio>max){
        max=coche.Precio;
        cont=i;
    }
}
/**
 * @brief incrementa el precio a través de un porcentaje.
 * @param v vector de vehiculos
 * @param tam tamaño del vector
 * @param porcentaje para aumentar el precio
 * @pre debe haber introducido un porcentaje anteriormente
 * @post Calcula el incremento de precio de los coches del vector v a través de un porcentaje
 */
void incrementaPrecios(vehiculo v[],int tam,float porcentaje){
    if(porcentaje<0||porcentaje>5){
        throw string("ERROR:[incrementaPrecios]No se ha introducido un valor válido en la variable porcentajes.");//Lanza una excepcion cuando porcentaje es menor que 0 o mayor que 5.
    }
    for(int i=0;i<tam;i++){
    v[i].Precio=v[i].Precio+(v[i].Precio*porcentaje);
    }
}



int main(int argc, char** argv) {
    int const MAX_VEHICULOS=1000;
    vehiculo v[MAX_VEHICULOS];
    int tam;
    string marca;
    float porcentaje=0;
    do{
        cout<<"¿Cuántos coches va a introducir?"<<endl;//Introducción del tamaño.
        cin>>tam;
    }while(tam>100||tam<1);
    int max=-9999;
    int cont=0;


    
    for(int i=0;i<tam;i++){//Uso de las funciones.
        leePorTeclado(v[i]);
        muestraEnPantalla(v[i]);
        maxPrecio(v[i],max,cont,i);
    }
    cout<<"El vehículo de mayor precio es el: "<<endl;//Muestra el vehículo de mayor precio
    muestraEnPantalla(v[cont]);
    
    cout<<"Introduce un valor entre 0 y 5 para incrementar el precio de un vehiculo(se pueden introducir decimales): "<<endl;//introduccion del porcentaje
    cin>>porcentaje;
    try{                                    //coge la excepción si el porcentaje es menor que 0 o mayor que 5
        incrementaPrecios(v,tam,porcentaje);//uso de la funcion de incremento.
    }catch(string& error){
        cerr<<error<<endl;
    }
    
    visualiza(v,tam);//Muestra la función tras el incremento.
    return 0;
}

