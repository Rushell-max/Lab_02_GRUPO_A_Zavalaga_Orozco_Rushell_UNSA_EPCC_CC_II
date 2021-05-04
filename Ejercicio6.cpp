//////////////////  LABORATORIO 2  /////////////////////////////
/*
 // RUSHELL VANESSA ZAVALAGA OROZCO
*/
/////////////////  EJERCICIO 6  //////////////////////////////

#include <iostream>
#include <ctime>
#include <fstream>

using namespace std;

// FUNCIONES COMPLEMENTARIAS

// Imprimer el arreglo
void print(char **cadenas, int tam, int lon){
    for(int i=0; i<tam; i++){
        for(int j=0; j<lon; j++){
            cout<<cadenas[i][j];
        }
        cout<<" ";
    }
}

// Crea cadenas aleatorias y las inserta en un arreglo
void aleatorio_cadenas(char **cadenas, int tam, int lon){
    srand(time(NULL));
    for(int i=0; i<tam; i++){
        for(int j=0; j<lon; j++){
            cadenas[i][j] = 97+rand()%(123-97);
        }
    }
}

// Pasa el arreglo a un fichero
void display_in_file1(char **cadenas, int tam, int lon, ofstream &archivo){
    for(int i=0; i<tam; i++){
        for(int j=0; j<lon; j++){
            archivo<<cadenas[i][j];
        }
        archivo<<endl;
    }
}

//     6                                    ///////////////////////
/* Implemente una función que reciba un arreglo de cadenas y su 
    tamaño y ordene lexicográficamente dicho arreglo.
    Tamaño del arreglo 1000000. */

// Devuelve el mayor del arreglo
int mayor(char **cadenas, int tam, int j){
    int mayor = cadenas[0][j];
    for (int i = 1; i < tam; i++){
        if (cadenas[i][j] > mayor){
            mayor = cadenas[i][j];
        }
    }
    return mayor;
}

// Ordenamiento por Counting Sort (Especifica)
void counting_sort(char **cadenas, int tam, int lon, int ind, int j){
    char **arreglo_temp = new char *[tam];
    for(int i=0; i<tam; i++){
        arreglo_temp[i] = new char [lon];
    }for (int i=0; i < tam; i++){
        for(int j=0; j<lon; j++){
            arreglo_temp[i][j] = cadenas[i][j];
        }
    }
    int i, count[10] = { 0 };

    for (i = 0; i < tam; i++){
        count[(cadenas[i][j] / ind) % 10]++;
    }

    for (i = 1; i < 10; i++){
        count[i] += count[i - 1];
    }

    for(int i=tam - 1; i >= 0; i--) {
        arreglo_temp[count[(cadenas[i][j] / ind) % 10] - 1][j] = cadenas[i][j];
        if(!count[(cadenas[i][j] / ind) % 10] - 1 != i){
            for(int k=0; k<lon; k++){
                arreglo_temp[count[(cadenas[i][j] / ind) % 10] - 1][k] = cadenas[i][k];
            }
        }
        count[(cadenas[i][j] / ind) % 10]--;
    }

    for (int i=0; i < tam; i++){
        for(int j=0; j<lon; j++){
            cadenas[i][j] = arreglo_temp[i][j];
        }
    }
    delete [] arreglo_temp;
}

// Ordenamiento por Radix Sort (General)
void radix_sort(char **arr, int tam, int lon){
    for (int j=lon-1 ; j>=0 ; j--){
        for (int i=1; mayor(arr, tam, j)/i>0; i*=10){
            counting_sort(arr, tam, lon, i, j);
        }
    }
}

int main(){
    cout<<endl<<" PROBLEMA 6 > > > "<<endl<<endl;
    int tam, lon;
    cout<<" INGRESE TAMAÑO DEL ARREGLO . . . "; cin>>tam;
    cout<<" INGRESE LONGITUD DE LAS CADENAS . . . "; cin>>lon;
    char **cadenas = new char *[tam];  
    for(int i=0; i<tam; i++){
        cadenas[i] = new char[lon];
    }

    ofstream archivo, archivo1;
    archivo.open("D:\\projects\\S3\\Laboratorio_CC_II\\T4_CadenasRandom.txt");
    archivo1.open("D:\\projects\\S3\\Laboratorio_CC_II\\T4_CadenasRandomOrdenadas.txt");

    aleatorio_cadenas(cadenas, tam, lon);
    //print6(cadenas, tam, lon);
    display_in_file1(cadenas, tam, lon, archivo);

    radix_sort(cadenas, tam, lon);
    //print6(cadenas, tam, lon);
    display_in_file1(cadenas, tam, lon, archivo1);

    archivo.close();archivo1.close();
    for(int i=0; i<tam; i++){
        delete [] cadenas[i];
    }
    delete [] cadenas;
    return 0;
}