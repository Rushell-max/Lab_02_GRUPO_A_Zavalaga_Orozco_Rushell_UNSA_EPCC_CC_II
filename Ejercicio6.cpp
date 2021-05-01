//////////////////  LABORATORIO 2  /////////////////////////////
/*
 // RUSHELL VANESSA ZAVALAGA OROZCO
*/
/////////////////  EJERCICIO 6  //////////////////////////////

#include <iostream>

using namespace std;

// FUNCIONES COMPLEMENTARIAS

// Imprimer el arreglo
void print(char *arr, int tam){
    for (int i = 0; i < tam; i++)
        cout << arr[i] << " ";
}

// Crea letras aleatorias y las inserta en un arreglo
void aleatorio_char(char *cadena, int tam){
    for(int i=0; i<tam; i++){
        cadena[i] = 97+rand()%(123-97);
    }
}

// Comprueba que el arreglo efectivamente este ordenado
bool comprobar(char *arr, int tam){
    for(int i=0; i+1<tam ; i++){
        if(!(arr[i]<=arr[i+1])){
            return false;
        }
    }return true;
}

//     6                                    ///////////////////////
/* Implemente una función que reciba un arreglo de cadenas y su 
    tamaño y ordene lexicográficamente dicho arreglo.
    Tamaño del arreglo 1000000. */

// Devuelve el mayor del arreglo
int mayor(char *arr, int tam){
    int mayor = arr[0];
    for (int i = 1; i < tam; i++){
        if (arr[i] > mayor){
            mayor = arr[i];
        }
    }return mayor;
}

// Ordenamiento por Counting Sort (Especifica)
void count_sort(char *arr, int tam, int ind){
    int *arreglo_temp = new int[tam];
    int i, count[10] = { 0 };

    for (i = 0; i < tam; i++){
        count[(arr[i] / ind) % 10]++;
    }

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = tam - 1; i >= 0; i--) {
        arreglo_temp[count[(arr[i] / ind) % 10] - 1] = arr[i];
        count[(arr[i] / ind) % 10]--;
    }

    for (i = 0; i < tam; i++){
        arr[i] = arreglo_temp[i];
    }
    delete [] arreglo_temp;
}

// Ordenamiento por Radix Sort (General)
void radix_sort(char *arr, int tam){
    for (int i=1; mayor(arr, tam)/i>0; i*=10){
        count_sort(arr, tam, i);
    }
}

int main(){
    cout<<" PROBLEMA 6 > > > "<<endl;
    int tam;
    cout<<" INGRESE TAMAÑO DEL ARREGLO . . . "; cin>>tam;
    char *cadena = new char [tam];

    aleatorio_char(cadena, tam);

    //print(arreglo, tam);
    radix_sort(cadena, tam);
    //print(cadena, tam);
    
    if(comprobar(cadena, tam)){
        cout<<" > > > Ordenado "<<endl;
    }else{
        cout<<" > > > Error "<<endl;
    }

    delete [] cadena;
    return 0;
}