//////////////////  LABORATORIO 2  /////////////////////////////
/*
 // RUSHELL VANESSA ZAVALAGA OROZCO
*/
/////////////////  EJERCICIO 3  //////////////////////////////

#include <iostream>
#include <ctime>

using namespace std;

// FUNCIONES COMPLEMENTARIAS

// Llena aleatoriamente el arreglo
void aleatorio(int *&arreglo, int tam){
    srand(time(NULL));
    for(int i=0; i<tam; i++){
        arreglo[i]=rand()%100;
    }
}

// Muestra el arreglo
void print_array(int *arreglo, int tam){
    for(int i=0; i<tam; i++){
        cout<<arreglo[i]<<" ";
    }cout<<endl;
}

// Comprueba si el arreglo esta ordenado 
bool comprobar(int *arreglo, int tam){
    for(int i=0; i+1<tam ; i++){
        if(!(arreglo[i]<=arreglo[i+1])){
            return false;
        }
    }return true;
}

//     3                                    ///////////////////////
/* Implementar una función que ordene los elementos de un arreglo: 
    ascendente. Tamaño del arreglo 1000000 */

// Devuelve el mayor numero de un arreglo
int mayor(int *arr, int tam){
    int mayor = arr[0];
    for (int i = 1; i < tam; i++){
        if (arr[i] > mayor){
            mayor = arr[i];
        }
    }
    return mayor;
}

// Función de ordenamiento por Counting Sort (Complementaria)
void count_sort(int *arr, int tam, int ind){
    int *arreglo_temp = new int[tam];
    int i, count[10] = { 0 };

    for (i = 0; i < tam; i++){
        count[(arr[i] / ind) % 10]++;
    }

    for (i = 1; i < 10; i++){
        count[i] += count[i - 1];
    }

    for (i = tam - 1; i >= 0; i--) {
        arreglo_temp[count[(arr[i] / ind) % 10] - 1] = arr[i];
        count[(arr[i] / ind) % 10]--;
    }

    for (i = 0; i < tam; i++){
        arr[i] = arreglo_temp[i];
    }
    delete [] arreglo_temp;
}

// Función de ordenamiento por Radix Sort (General)
void radix_sort(int *arr, int tam){
    for (int i=1; mayor(arr, tam)/i>0; i*=10){
        count_sort(arr, tam, i);
    }
}

int main(){
    cout<<" PROBLEMA 3 > > > "<<endl;
    int tam;
    cout<<" INGRESE TAMAÑO VECTOR . . . "; cin>>tam;
    int *arreglo = new int [tam];

    aleatorio(arreglo, tam);
    //print_array(arreglo, tam);

    radix_sort(arreglo, tam);

    if(comprobar(arreglo, tam)){
        cout<<" > > > Ordenado "<<endl;
    }else{
        cout<<" > > > Error "<<endl;
    }

    delete [] arreglo;

    return 0;
}