#include <iostream>

using namespace std;

// Declaramos un template para cada funcion
template <typename T>
void mostrarArray(T* array, T n){ // recibe un puntero como argumento, o sea una direccion de memoria
  for (int i=0; i<n; i++){
    cout<<*(array+i)<<" ";
  }
  cout<<endl;
}

template <typename T>
bool compare1(T x, T y) {
    return x <= y;
}

template <typename T>
bool compare2(T x, T y) {
    return x > y;
}

template <typename T>
void insertionsort(T* arreglo,T size, bool (*p)(T , T))
{
    for(int k=1; k<size; k++) 
    { 
        int temp = arreglo[k]; 
        int j = k-1;
        while(j>=0 && p(temp,arreglo[j]) ) 
        { 
            arreglo[j+1] = arreglo[j]; 
            j--;
        } 
        arreglo[j+1] = temp; 
    } 
}

int main(){
    int arreglo[10] = {5,2,2,7,1,3,5,2,10,1};
    mostrarArray(arreglo,10);
    insertionsort(arreglo,10, compare1);
    mostrarArray(arreglo,10);

    return 0;
}