//////////////////  LABORATORIO 2  /////////////////////////////
/*
 // RUSHELL VANESSA ZAVALAGA OROZCO
*/
/////////////////  EJERCICIO 5  //////////////////////////////

#include <iostream>

using namespace std;

// FUNCIONES COMPLEMENTARIAS

// Devuelve el tamaño de la cadena
long long int tam(char *cadena){
    long long int i=0;
    while(cadena[i]!='\0'){
        i++;
    }return i++;
}

//     5                                    ///////////////////////
/* Implemente una función que reciba dos cadenas a y b; dicha función 
    debe concatenar la cadena a a la cadena b.(asuma que la cadena b tiene el
    tamaño suficiente para contener los elementos de a).*/

//Función Principal
void concatenar(char *a, char *b){
    int tam_b = tam(b);
    int tam_a = tam(a);

    int ind_a=0;
    for(int i=tam_b; i<tam_a+tam_b; i++){
        b[i] = a[ind_a];
        ind_a++;
    }b[tam_a+tam_b] = '\0';
}

int main(){
    cout<<" PROBLEMA 5 > > > "<<endl;
    char *a = new char[20];
    char *b = new char[40];

    cout<<" Ingresar cadena a: ";cin>>a;
    cout<<" Ingresar cadena b: ";cin>>b;

    concatenar(a, b);

    cout<<endl<<" Cadena 'b' concatenada a 'a' > > "<<b;

    delete [] a;
    delete [] b;
    return 0;
}