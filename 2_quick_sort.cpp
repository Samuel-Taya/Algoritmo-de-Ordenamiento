#include <iostream>

using namespace std;

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
int Partition(T* array,T first,T last, bool (*p)(T , T))
{
    int index_pivot=last;
    int pivot_value=array[index_pivot];
    int index=first;
    int temp;
    int temp2;
    for(int i=first;i<last;i++){
        if(p(array[i],pivot_value)){
            temp=array[i];
            array[i]=array[index];
            array[index]=temp;
            index++;
        }
    }
    temp2=array[index];
    array[index]=array[last];
    array[last]=temp2;
    return index;
}

template <typename T>
int Quicksort(T* array,T beginning,T end)
{
    int p;
    if(beginning<end){
        p=Partition(array,beginning,end,compare1);
        Quicksort(array,beginning,p-1);
        Quicksort(array,p+1,end);
    }
}

int main(){
    
    int arreglo[10] = {5,2,2,7,1,3,5,2,10,1};
    mostrarArray(arreglo,10);
    Quicksort(arreglo,0,9); // elementos en la posicion 0 y 9 del arreglo
    mostrarArray(arreglo,10);

    return 0;
}