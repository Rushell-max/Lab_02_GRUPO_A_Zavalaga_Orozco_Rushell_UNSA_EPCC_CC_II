//////////////////  LABORATORIO 2  /////////////////////////////
/*
 // RUSHELL VANESSA ZAVALAGA OROZCO
*/
/////////////////  EJERCICIO 4  //////////////////////////////

#include <iostream>

using namespace std;

//     4                                    ///////////////////////
/* Implemente una función que reciba una cadena y retorne su tamaño. 
    (Iterativa y recursiva) */

// Función que halla el tamaño de una cadena por iteración
long long int iterativa4(char *cadena){
    long long int i=0;
    while(cadena[i]!='\0'){
        i++;
    }return i++;
}

// Función que halla el tamaño de una cadena por recursividad
long long int recursiva4(char *cadena, int i){
    if(cadena[i]=='\0'){
        return i++;
    }i++;
    return recursiva4(cadena, i);
}

int main(){
    cout<<" PROBLEMA 4 > > > "<<endl;
    char *cadena = new char[100];
    
    cout<<" Ingresar cadena: ";cin>>cadena;
    //char cadena []= "Si un niño naciera sin contacto humano durante aproximadamente 18 años, ¿qué idioma hablaria?";

    cout<<"La longitud de la cadena segun iteración es "<<iterativa4(cadena)<<endl;
    cout<<"La longitud de la cadena segun recursividad es "<<recursiva4(cadena, 0)<<endl;

    return 0;
}